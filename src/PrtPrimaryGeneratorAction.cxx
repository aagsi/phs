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
    
    TString lutfile_gen = "/Users/ahmed/phs/lut/lut_opt_332_2018_cs_avr.root";
    TFile *fFile_gen = new TFile(lutfile_gen);
    //fFile_gen = TFile::Open(lutfile_gen,"read");
    fTree_gen=(TTree *) fFile_gen->Get("prtlut") ;
    fLut_gen = new TClonesArray("PrtLutNode");
    fTree_gen->SetBranchAddress("LUT",&fLut_gen);
    fTree_gen->GetEntry(0);
    for(Int_t i=0; i<5000; i++) {
        fLutNode_gen[i] = (PrtLutNode*) fLut_gen->At(i);
    }
    
}

PrtPrimaryGeneratorAction::~PrtPrimaryGeneratorAction(){
    delete fParticleGun;
    delete fGunMessenger;
    //delete fFile_gen;
}

void PrtPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent){
    // Double_t pos_x,pos_y, pos_z;
    // for (Int_t mcpid_int=0; mcpid_int<12; mcpid_int++){ //12
    //   for (Int_t pixid_int=1; pixid_int<65; pixid_int++){ // 65
    
    G4ThreeVector vectPos(0,0,0);
    int counter = 0;
    auto store = G4PhysicalVolumeStore::GetInstance();
    
    for (size_t i=0;i<store->size();i++){
        //std::cout<<"name "<<(*store)[i]->GetName()<<std::endl;
        if((*store)[i]->GetName()=="wMcp") { //  wPixel
            std::cout<<"############### MCP["<<counter<<"]"<<(*store)[i]->GetName()<<std::endl;
            auto t = (*store)[i]->GetTranslation(); // GetObjectTranslation  GetTranslation   GetFrameTranslation
            std::cout<<"############### MCP translation "<<"x "<<t.x()<<" y "<<t.y()<<" z "<<t.z()<<std::endl;
            G4LogicalVolume * temp = (*store)[i]->GetLogicalVolume(); // lMcp // GetMotherLogical
            //std::cout<<"###### name "<<temp->GetName()<<std::endl;
            for (G4int j=0; j<temp->GetNoDaughters(); j++){
                
                G4double x,y,z;
                G4double radiatorL = PrtManager::Instance()->GetRadiatorL();
                G4double radiatorW = PrtManager::Instance()->GetRadiatorW();
                G4double radiatorH = PrtManager::Instance()->GetRadiatorH();
//
//                if(PrtManager::Instance()->GetMixPiP()){
//                    if(PrtManager::Instance()->GetParticle()==211 || PrtManager::Instance()->GetParticle()==0){
//                        fParticleGun->SetParticleDefinition(fParticleP);
//                        PrtManager::Instance()->SetParticle(2212);
//                    }else{
//                        fParticleGun->SetParticleDefinition(fParticlePi);
//                        PrtManager::Instance()->SetParticle(211);
//                    }
//                }
//
//                PrtManager::Instance()->AddEvent(PrtEvent());
//
//                if(PrtManager::Instance()->GetBeamDinsion() == -1){ // random momentum
//                    fParticleGun->SetParticleMomentum(G4ThreeVector(0, 0, 4.0*GeV*G4UniformRand()));
//                }
//
//                if(PrtManager::Instance()->GetBeamDinsion() > 0){ // smearing and divergence
//                    G4double sigma = PrtManager::Instance()->GetBeamDinsion()*mm;
//                    z = fParticleGun->GetParticlePosition().z();
//
//                    // // gaussian smearing
//                    // x = G4RandGauss::shoot(0,sigma);
//                    // y = G4RandGauss::shoot(0,sigma);
//
//                    // box smearing
//                    x = (0.5-G4UniformRand())*sigma;
//                    y = (0.5-G4UniformRand())*sigma;
//
//                    fParticleGun->SetParticlePosition(G4ThreeVector(x,y,z));
//                    PrtManager::Instance()->Event()->SetPosition(TVector3(x,y,z));
//                    G4double angle = -G4UniformRand()*M_PI;
//                    G4ThreeVector vec(0,0,1);
//                    vec.setTheta(G4RandGauss::shoot(0,0.0025)); //beam divergence
//                    vec.setPhi(2*M_PI*G4UniformRand());
//
//                    fParticleGun->SetParticleMomentumDirection(vec);
//                }
                
                
                if(PrtManager::Instance()->GetRunType() == 0){ // LUT generation
                    
                    //                    Int_t sensorId_int = 100*mcpid_int + pixid_int ;
                    //                    pos_x   = fLutNode_gen[sensorId_int]->GetDigiPos().X()-0.0;
                    //                    pos_y   = fLutNode_gen[sensorId_int]->GetDigiPos().Y()-0.0;
                    //                    pos_z   = fLutNode_gen[sensorId_int]->GetDigiPos().Z()-0.6;
                    //                    fParticleGun->SetParticlePosition(G4ThreeVector(pos_x, pos_y, pos_z));

                    (*store)[j] = temp->GetDaughter(j);
                    std::cout<<"###### Pixel["<<j<<"]"<<(*store)[j]->GetName()<<std::endl;
                    auto k = (*store)[j]->GetTranslation(); // GetObjectTranslation GetTranslation // GetFrameTranslation
                    std::cout<<"###### Pixel translation "<<"x "<<k.x()<<" y "<<k.y()<<" z "<<k.z()<<std::endl;
                    vectPos = t+k;
                    std::cout<<"###### All translations "<<"x "<<vectPos.x()<<" y "<<vectPos.y()<<" z "<<vectPos.z()<<std::endl;
                    
                    fParticleGun->SetParticlePosition(G4ThreeVector(vectPos.x(), vectPos.y(), vectPos.z()));

                    
                    
                    
                    //fParticleGun->SetParticlePosition(G4ThreeVector(radiatorH*(0.5-G4UniformRand()),radiatorW*(0.5-G4UniformRand()),radiatorL/2.-0.1));
                    /*fParticleGun->SetParticlePosition(G4ThreeVector(PrtManager::Instance()->GetRStepY(),//+5-10*G4UniformRand(),
                     PrtManager::Instance()->GetRStepX(),//+10-20*G4UniformRand(),
                     radiatorL/2.-0.1));*/
                    G4double angle = -G4UniformRand()*M_PI;
                    G4ThreeVector vec(0,0,1);
                    vec.setTheta(acos(G4UniformRand()));
                    vec.setPhi(2*M_PI*G4UniformRand());
                    
                    //    vec.rotateY(-M_PI/2.);
                    fParticleGun->SetParticleMomentumDirection(-vec);
                }
                if(PrtManager::Instance()->GetRunType() == 5){ // calibration light
                    G4double shift = PrtManager::Instance()->GetShift();
                    
                    fParticleGun->SetParticlePosition(G4ThreeVector(-radiatorL/2.+0.1-shift,0,5+tan(45*M_PI/180.)*shift+25));
                    G4double angle = -G4UniformRand()*M_PI;
                    G4ThreeVector vec(0,0,1);
                    vec.setTheta(acos(G4UniformRand()));
                    vec.setPhi(2*M_PI*G4UniformRand());
                    
                    vec.rotateY(-M_PI/2.);
                    fParticleGun->SetParticleMomentumDirection(vec);
                }
                if(PrtManager::Instance()->GetRunType() == 6){ // for determining focal plane of the lens
                    G4double shiftx = -radiatorL/2.+0.1;
                    G4double shifty = radiatorW/2. - G4UniformRand()*radiatorW;
                    G4double shiftz = radiatorH/2. - G4UniformRand()*radiatorH;
                    
                    G4double angle = 0.7*(M_PI/2.-G4UniformRand()*M_PI);
                    G4ThreeVector vec(0,0,1);
                    vec.setTheta(angle);
                    ///vec.setTheta(acos(G4UniformRand()));
                    //vec.setPhi(2*M_PI*G4UniformRand());
                    //std::cout<<"angle "<<angle*180/M_PI <<std::endl;
                    
                    G4double lensThickness=15;
                    G4double separation=PrtManager::Instance()->GetBeamDinsion();
                    if(separation<0.001) separation=10;
                    G4double rotShiftX=0.5*separation*std::cos(angle)+(0.5*lensThickness+0.1)*std::tan(angle);
                    G4double rotShiftY=-0.5*radiatorL +0.1;
                    
                    //fParticleGun->SetParticlePosition(G4ThreeVector(shiftx,shifty,shiftz));
                    //fParticleGun->SetParticlePosition(G4ThreeVector(rotShiftY, 0,-rotShiftX));
                    fParticleGun->SetParticlePosition(G4ThreeVector(rotShiftY, 0,0.5*separation));
                    
                    
                    vec.rotateY(-M_PI/2.);
                    fParticleGun->SetParticleMomentumDirection(vec);
                    
                    fParticleGun->GeneratePrimaryVertex(anEvent);
                    rotShiftX=-0.5*separation*std::cos(angle)+(0.5*lensThickness+0.1)*std::tan(angle);
                    shiftx = -radiatorL/2.+0.1;
                    shifty = radiatorW/2. - G4UniformRand()*radiatorW;
                    shiftz = radiatorH/2. - G4UniformRand()*radiatorH;
                    //fParticleGun->SetParticlePosition(G4ThreeVector(shiftx,shifty,shiftz));
                    //fParticleGun->SetParticlePosition(G4ThreeVector(rotShiftY,0,-rotShiftX));
                    fParticleGun->SetParticlePosition(G4ThreeVector(rotShiftY, 0,-0.5*separation));
                }
                
                fParticleGun->GeneratePrimaryVertex(anEvent);
                
                G4ThreeVector dir = fParticleGun->GetParticleMomentumDirection();
                dir *= fParticleGun->GetParticleMomentum();
                PrtManager::Instance()->SetMomentum(TVector3(dir.x(),dir.y(),dir.z()));
                //  }
                //}
            }
            ++counter;
        }
        
    }
    
}
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


