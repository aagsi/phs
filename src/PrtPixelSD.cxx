#include "PrtPixelSD.h"
#include "G4HCofThisEvent.hh"
#include "G4Step.hh"
#include "G4ThreeVector.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"
#include "G4RunManager.hh"
#include <TVector3.h>

#include "PrtEvent.h"
#include "PrtPrizmHit.h"

#include "PrtRunAction.h"
#include "PrtManager.h"

#include "G4TransportationManager.hh"
#include "G4Navigator.hh"

#include "PrtPrimaryGeneratorAction.h"

#include "globals.hh"

#include "TROOT.h"
#include "TMath.h"
#include "TRotation.h"
#include "G4PhysicalVolumeStore.hh"
#include "G4ThreeVector.hh"
#include "G4INCLThreeVector.hh"
#include "G4ThreeVector.hh"

PrtPixelSD::PrtPixelSD( const G4String& name, 
                       const G4String& hitsCollectionName,
                       G4int nofCells)
: G4VSensitiveDetector(name){
    collectionName.insert(hitsCollectionName);
}

PrtPixelSD::~PrtPixelSD(){ 
}

void PrtPixelSD::Initialize(G4HCofThisEvent* hce){
    
    memset(fMultHit, 0, sizeof(fMultHit[0][0])*960);

}

G4bool PrtPixelSD::ProcessHits(G4Step* step, G4TouchableHistory* hist){  
    // // energy deposit
    // G4double edep = step->GetTotalEnergyDeposit();
    
    // // step length
    // G4double stepLength = 0.;
    // if ( step->GetTrack()->GetDefinition()->GetPDGCharge() != 0. ) {
    //   stepLength = step->GetStepLength();
    // }
    
    // if ( edep==0. && stepLength == 0. ) return false;
    
    if(step == 0) return false;
    
    //G4ThreeVector translation = hist->GetTranslation();
    //G4ThreeVector localpos = step->GetPreStepPoint()->GetPhysicalVolume()->GetObjectTranslation();
    G4TouchableHistory* touchable = (G4TouchableHistory*)(step->GetPostStepPoint()->GetTouchable());
    
    // Get cell id
    G4int layerNumber = touchable->GetReplicaNumber(0);
    //G4cout<< " PixelId = "<<layerNumber << G4endl;
    G4Track* track = step->GetTrack();
    const G4DynamicParticle* dynParticle = track->GetDynamicParticle();
    G4ParticleDefinition* particle = dynParticle->GetDefinition();
    G4String ParticleName = particle->GetParticleName();
    
    G4ThreeVector globalpos = step->GetPostStepPoint()->GetPosition();
    G4ThreeVector localpos = touchable->GetHistory()->GetTopTransform().TransformPoint(globalpos);
    G4ThreeVector translation = touchable->GetHistory()->GetTopTransform().Inverse().TransformPoint(G4ThreeVector(0,0,0));
    G4ThreeVector inPrismpos = touchable->GetHistory()->GetTransform(1).TransformPoint(globalpos);
    
    G4ThreeVector globalvec = track->GetVertexMomentumDirection();
    G4ThreeVector localvec = touchable->GetHistory()->GetTopTransform().TransformAxis(globalvec);
    
    // G4ThreeVector g4mom = track->GetVertexMomentumDirection(); // track->GetMomentum();
    
    G4ThreeVector g4mom =  track->GetMomentum(); // track->GetVertexMomentumDirection();
    G4ThreeVector g4pos = track->GetVertexPosition();
    
    TVector3 globalPos(inPrismpos.x(),inPrismpos.y(),inPrismpos.z());
    TVector3 localPos(localpos.x(),localpos.y(),localpos.z());
    
    if(PrtManager::Instance()->GetRunType() == 6){ //focal plane scan
        globalPos = TVector3(globalpos.x(),globalpos.y(),globalpos.z());
        localPos = TVector3(g4pos.x(),g4pos.y(),g4pos.z());
    }
    
    translation=touchable->GetHistory()->GetTransform(1).TransformPoint(translation);
    TVector3 digiPos(translation.x(),translation.y(),translation.z());
    TVector3 momentum(g4mom.x(),g4mom.y(),g4mom.z());
    G4ThreeVector lp = touchable->GetHistory()->GetTransform(1).TransformPoint(g4pos); //pos in wDirc
    TVector3 position(lp.x(),lp.y(),lp.z());
    
    // information from prizm
    G4SDManager* fSDM = G4SDManager::GetSDMpointer();
    G4RunManager* fRM = G4RunManager::GetRunManager();
    G4int collectionID = fSDM->GetCollectionID("PrizmHitsCollection");
    const G4Event* currentEvent = fRM->GetCurrentEvent();
    G4HCofThisEvent* HCofEvent = currentEvent->GetHCofThisEvent();
    PrtPrizmHitsCollection* prizmCol = (PrtPrizmHitsCollection*)(HCofEvent->GetHC(collectionID));
    
    Double_t pathId = 0;
    Int_t refl=0;
    for (G4int i=0;i<prizmCol->entries();i++){
        PrtPrizmHit* phit = (*prizmCol)[i];
        if(phit->GetTrackID()==track->GetTrackID()) {
            refl++;
            pathId += phit->GetNormalId()*1000*refl;
        }
    }
    
    //std::cout<<"Number of reflections: "<<refl <<std::endl;
    
    
    G4ThreeVector pp =G4ThreeVector(0,0,0.6).rotateY(PrtManager::Instance()->GetAngle()*CLHEP::deg-180*CLHEP::deg);
    G4ThreeVector mm =G4ThreeVector(0,0,0.3).rotateY(PrtManager::Instance()->GetAngle()*CLHEP::deg-180*CLHEP::deg);
    
    
    G4ThreeVector myPoint = G4ThreeVector (g4pos.x(), g4pos.y(), g4pos.z() ) + pp ;
    G4Navigator* theNavigator = G4TransportationManager::GetTransportationManager()->GetNavigatorForTracking();
    G4VPhysicalVolume* myVolume = theNavigator->LocateGlobalPointAndSetup(myPoint);
    
    
    G4ThreeVector myPoint2 = G4ThreeVector (g4pos.x(), g4pos.y(), g4pos.z()) + mm;
    G4Navigator* theNavigator2= G4TransportationManager::GetTransportationManager()->GetNavigatorForTracking();
    G4VPhysicalVolume* myVolume2 = theNavigator->LocateGlobalPointAndSetup(myPoint2);
    
    
    
    //std::cout<<"#########  #################  ############  myVolume name is : "<<myVolume->GetName()<< "  num " << myVolume->GetCopyNo()<<std::endl;
    //std::cout<<"#########  #################  ############  myVolume name is : "<<myVolume2->GetName()<< "  num " << myVolume2->GetCopyNo()<<std::endl;
    G4ThreeVector globalpos2 = step->GetPostStepPoint()->GetPosition();
    //std::cout<<"#########  #################  ############  globalPos is : " << globalpos2 << std::endl;
    
    PrtHit hit;
    //Int_t mcpid=touchable->GetReplicaNumber(1);
    //Int_t pixid = touchable->GetReplicaNumber(0);
    
    Int_t mcpid=myVolume2->GetCopyNo();
    Int_t pixid =myVolume->GetCopyNo();
    
    
    hit.SetMcpId(mcpid);
    hit.SetPixelId(pixid);
    hit.SetGlobalPos(globalPos);
    hit.SetLocalPos(localPos);
    hit.SetDigiPos(digiPos);
    hit.SetPosition(position);
    //hit.SetMomentum(momentum);
    
    G4ThreeVector mominend = step->GetPostStepPoint()->GetMomentum();
    TVector3 mominendv(mominend.x(),mominend.y(),mominend.z());
    hit.SetMomentum(mominendv);
    
    hit.SetParticleId(track->GetTrackID());
    hit.SetParentParticleId(track->GetParentID());
    hit.SetNreflectionsInPrizm(refl-1);
    hit.SetPathInPrizm(pathId);
    hit.SetCherenkovMC(PrtManager::Instance()->GetCurrentCherenkov());
    // time since track created
    
    G4double time = step->GetPreStepPoint()->GetLocalTime();
    if(PrtManager::Instance()->GetRunType()==0) time = G4RandGauss::shoot(time,PrtManager::Instance()->GetTimeRes()); //resolution [ns]
    hit.SetLeadTime(time);
    Double_t wavelength = 1.2398/(track->GetMomentum().mag()*1E6)*1000;
    hit.SetTotTime(wavelength); //set photon wavelength
    // time since event created
    // step->GetPreStepPoint()->GetGlobalTime()*1000
    
    
    
    
    
    
//    if(fQe_space[mcpid][pixid]>G4UniformRand) {
//        
//        
//        std::cout << " #### #### #### #### fQe_space= "<< fQe_space[mcpid][pixid]<< "      G4UniformRand= "<<G4UniformRand()<< std::endl;
//        PrtManager::Instance()->AddHit(hit);
//        fMultHit[mcpid][pixid]++;
//    }
    
     PrtManager::Instance()->AddHit(hit);
    
    
    
    
    // number of event = 500 User=9.63s Real=10.7s Sys=0.4s
    return true;
}

void PrtPixelSD::EndOfEvent(G4HCofThisEvent*){
    memset(fMultHit, 0, sizeof(fMultHit[0][0])*960);
    G4int eventNumber = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
    if(eventNumber%1==0 && PrtManager::Instance()->GetRunType()==0) std::cout<<"Event # "<<eventNumber <<std::endl;
    if(eventNumber%1000==0 && PrtManager::Instance()->GetRunType()!=0) std::cout<<"Event # "<<eventNumber <<std::endl;
    PrtManager::Instance()->Fill();
}

