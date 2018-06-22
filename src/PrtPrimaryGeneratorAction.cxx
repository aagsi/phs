#include "PrtPrimaryGeneratorAction.h"
#include "PrtPrimaryGeneratorMessenger.h"

#include "Randomize.hh"
#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"
#include "globals.hh"
#include "PrtManager.h"
#include "PrtLutNode.h"
#include "TROOT.h"
#include "TMath.h"
#include "TRotation.h"
#include "G4PhysicalVolumeStore.hh"
#include "G4ThreeVector.hh"

PrtPrimaryGeneratorAction::PrtPrimaryGeneratorAction():G4VUserPrimaryGeneratorAction(),fParticleGun(0){
    G4int n_particle = 1;
    fParticleGun = new G4ParticleGun(n_particle);
    
    //create a messenger for this class
    fGunMessenger = new PrtPrimaryGeneratorMessenger(this);
    
    //default kinematic
    G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
    fParticleP = particleTable->FindParticle("proton");
    fParticlePi = particleTable->FindParticle("pi+");
    
    fParticleGun->SetParticleDefinition(fParticleP);
    fParticleGun->SetParticleTime(0.0*ns);
    fParticleGun->SetParticlePosition(G4ThreeVector(0.0*cm,0.0*cm,0.0*cm));
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(1.,0.,0.));
    fParticleGun->SetParticleEnergy(7*MeV);
    
    int mid=-1, pid=-1;
    G4ThreeVector vdirc,vmcp[12],vpix[64];
    auto store = G4PhysicalVolumeStore::GetInstance();
    for (size_t i=0;i<store->size();i++){
        if((*store)[i]->GetName()=="wDirc")  vdirc =(*store)[i]->GetTranslation();
        if((*store)[i]->GetName()=="wMcp")   vmcp[++mid] =(*store)[i]->GetTranslation();
        if((*store)[i]->GetName()=="wPixel") vpix[++pid] =(*store)[i]->GetTranslation();
    }
    //std::cout<<"############ m["<<mid<<"]" <<" pid = "<< pid<<std::endl; // here
    G4ThreeVector vpixminus[64];
    for(auto m=0; m<=mid; m++){
        for(auto p=0; p<=pid; p++){
            vpixminus[p]= G4ThreeVector(vpix[p].x(),vpix[p].y(), vpix[p].z()- 0.6);
            //std::cout<<"###### m["<<m<<"]" <<" p = "<< p<<std::endl; // here
            gpix[m][p] =vdirc+(vmcp[m]+vpixminus[p]).rotateY(PrtManager::Instance()->GetAngle()*deg-180*deg);
        }
    }
}
PrtPrimaryGeneratorAction::~PrtPrimaryGeneratorAction(){
    delete fParticleGun;
    delete fGunMessenger;
}
void PrtPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent){
    int counter3= 0 ;
    for ( auto m=0 ; m<12 ; ++m ){
        for ( auto p=0 ; p<64 ; ++p ){
            //if (counter3 == 63) break;
            PrtManager::Instance()->AddEvent(PrtEvent());
            if(PrtManager::Instance()->GetRunType() == 0){ // Phs generation
                ///////////////
                // pos dir ////
                ///////////////
                fParticleGun->SetParticlePosition(gpix[m][p]);
                ///////////////
                // mom dir ////
                ///////////////
                G4double angle = -G4UniformRand()*M_PI;
                G4ThreeVector vec(0,0,1);
                vec.setTheta(acos(G4UniformRand()));
                vec.setPhi(2*M_PI*G4UniformRand());
                vec.rotateY(PrtManager::Instance()->GetAngle()*deg-180*deg);
                fParticleGun->SetParticleMomentumDirection(-vec);
            }
            fParticleGun->GeneratePrimaryVertex(anEvent);
            ++counter3;
        } // pix loop
    } // pmt loop
    
} // promary particle generator loop
void PrtPrimaryGeneratorAction::SetOptPhotonPolar(){
    G4double angle = G4UniformRand() * 360.0*deg;
    SetOptPhotonPolar(angle);
}

void PrtPrimaryGeneratorAction::SetOptPhotonPolar(G4double angle){
    if (fParticleGun->GetParticleDefinition()->GetParticleName()!="opticalphoton"){
        G4cout << "--> warning from PrimaryGeneratorAction::SetOptPhotonPolar() :"
        "the particleGun is not an opticalphoton " <<
        fParticleGun->GetParticleDefinition()->GetParticleName()<< G4endl;
        return;
    }
    G4ThreeVector normal (1., 0., 0.);
    G4ThreeVector kphoton = fParticleGun->GetParticleMomentumDirection();
    G4ThreeVector product = normal.cross(kphoton);
    G4double modul2       = product*product;
    
    G4ThreeVector e_perpend (0., 0., 1.);
    if (modul2 > 0.) e_perpend = (1./std::sqrt(modul2))*product;
    G4ThreeVector e_paralle    = e_perpend.cross(kphoton);
    
    G4ThreeVector polar = std::cos(angle)*e_paralle + std::sin(angle)*e_perpend;
    fParticleGun->SetParticlePolarization(polar);
}


