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
#include "G4LogicalVolumeStore.hh"
#include "G4Box.hh"

//#include "../../prttools/prttools.C"
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
    

    
    G4ThreeVector vectPos(0,0,0);
    int counter = 0;
    int counter2 = 0;
    auto store = G4PhysicalVolumeStore::GetInstance();
    for (size_t i=0;i<store->size();i++){
        //std::cout<<"name "<<(*store)[i]->GetName()<<std::endl;
        if((*store)[i]->GetName()=="wDirc") { //  Dirc Physical volum
            //            if (counter == 1) break;
            //            if (counter2 == 20) break;
            auto d = (*store)[i]->GetTranslation(); // GetObjectTranslation  GetTranslation   GetFrameTranslation
            G4LogicalVolume * temp_0 = (*store)[i]->GetLogicalVolume(); //opttions  GetLogicalVolume , GetMotherLogical
            for (G4int jj=0; jj<temp_0->GetNoDaughters(); jj++){
                
                (*store)[jj] = temp_0->GetDaughter(jj);
                if((*store)[jj]->GetName()=="wMcp") { //  MCP Physical volum
                    //                    if (counter == 1) break;
                    //                    if (counter2 == 20) break;
                    std::cout<<"############### MCP["<<counter<<"]"<<(*store)[jj]->GetName()<<std::endl;
                    auto t = (*store)[jj]->GetTranslation(); // options GetObjectTranslation  GetTranslation   GetFrameTranslation
                    //std::cout<<"############### MCP translation "<<"x "<<t.x()<<" y "<<t.y()<<" z "<<t.z()<<std::endl;
                    G4LogicalVolume * temp = (*store)[jj]->GetLogicalVolume();
                    //std::cout<<"###### name "<<temp->GetName()<<std::endl;
                    for (G4int jjj=0; jjj<temp->GetNoDaughters(); jjj++){ // Loop over pixels
                        //                        if (counter2 == 20) break;
                        (*store)[jjj] = temp->GetDaughter(jjj);
                        
                        auto k = (*store)[jjj]->GetTranslation();
                        //std::cout<<"###### Pixel translation "<<"x "<<k.x()<<" y "<<k.y()<<" z "<<k.z()<<std::endl;
                        vectPos = t+k+d;
                        std::cout<<"###### Pixel["<<jjj<<"]"<<(*store)[jjj]->GetName()<<"translations= "<< vectPos<<std::endl;
                        vectPos_vector[counter2].setX(vectPos.x());
                        vectPos_vector[counter2].setY(vectPos.y());
                        vectPos_vector[counter2].setZ(vectPos.z());
                        ++counter2;
                    } // loop over MCP Doughters "pixels"
                    ++counter;
                } // if MCP
            } // loop over DIRC Doughter
        } // if DIRC
        
    } // loop over all Geometry
    
}
PrtPrimaryGeneratorAction::~PrtPrimaryGeneratorAction(){
    delete fParticleGun;
    delete fGunMessenger;
    
}
void PrtPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent){
    G4double x,y,z;
    G4double radiatorL = PrtManager::Instance()->GetRadiatorL();
    G4double radiatorW = PrtManager::Instance()->GetRadiatorW();
    G4double radiatorH = PrtManager::Instance()->GetRadiatorH();
    for ( auto n=0 ; n<768 ; ++n ){
        if(PrtManager::Instance()->GetRunType() == 0){ // LUT generation
            
            std::cout<<"###### Pixel number=  "<<n<<" vectPos_vector[n] "<<vectPos_vector[n]<<std::endl;
            fParticleGun->SetParticlePosition(G4ThreeVector(vectPos_vector[n].x(),vectPos_vector[n].y(), vectPos_vector[n].z()  ));
            G4double angle = -G4UniformRand()*M_PI;
            G4ThreeVector vec(0,0,1);
            vec.setTheta(acos(G4UniformRand()));
            vec.setPhi(2*M_PI*G4UniformRand());
            //vec.rotateY(-M_PI/2.);
            fParticleGun->SetParticleMomentumDirection(-vec);
        }

        
        fParticleGun->GeneratePrimaryVertex(anEvent);
        
        G4ThreeVector dir = fParticleGun->GetParticleMomentumDirection();
        dir *= fParticleGun->GetParticleMomentum();
        PrtManager::Instance()->SetMomentum(TVector3(dir.x(),dir.y(),dir.z()));
        
    } // array vector loop
    
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


