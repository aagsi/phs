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
#include "G4VPhysicalVolume.hh"
#include "G4TransportationManager.hh"
#include "G4MultiNavigator.hh"

#include "G4ITNavigator.hh"
#include "G4ITTransportationManager.hh"
#include "G4ITSafetyHelper.hh"






PrtPixelSD::PrtPixelSD( const G4String& name, const G4String& hitsCollectionName, G4int nofCells): G4VSensitiveDetector(name){
    collectionName.insert(hitsCollectionName);
    counter =0;
    
    bool_time=false;
}

PrtPixelSD::~PrtPixelSD(){
    
}

void PrtPixelSD::Initialize(G4HCofThisEvent* hce){
    
    memset(fMultHit, 0, sizeof(fMultHit[0][0])*960);
    
}

G4bool PrtPixelSD::ProcessHits(G4Step* step, G4TouchableHistory* hist){
    
    
    G4int counter2 =0;
    // // energy deposit
    // G4double edep = step->GetTotalEnergyDeposit();
    
    // // step length
    // G4double stepLength = 0.;
    // if ( step->GetTrack()->GetDefinition()->GetPDGCharge() != 0. ) {
    //   stepLength = step->GetStepLength();
    // }
    
    // if ( edep==0. && stepLength == 0. ) return false;
    
    if(step == 0) return false;
    
    G4TouchableHistory* touchable = (G4TouchableHistory*)(step->GetPreStepPoint()->GetTouchable());
    G4Track* track = step->GetTrack();
    const G4DynamicParticle* dynParticle = track->GetDynamicParticle();
    G4ParticleDefinition* particle = dynParticle->GetDefinition();
    G4String ParticleName = particle->GetParticleName();
    
    G4ThreeVector globalpos = step->GetPreStepPoint()->GetPosition();
    G4ThreeVector localpos = touchable->GetHistory()->GetTopTransform().TransformPoint(globalpos);
    G4ThreeVector translation = touchable->GetHistory()->GetTopTransform().Inverse().TransformPoint(G4ThreeVector(0,0,0));
    G4ThreeVector inPrismpos = touchable->GetHistory()->GetTransform(1).TransformPoint(globalpos);
    
    G4ThreeVector globalvec = track->GetVertexMomentumDirection();
    G4ThreeVector localvec = touchable->GetHistory()->GetTopTransform().TransformAxis(globalvec);
    
    
    TVector3 localPos(localpos.x(),localpos.y(),localpos.z());
    
    translation=touchable->GetHistory()->GetTransform(1).TransformPoint(translation);
    TVector3 digiPos(translation.x(),translation.y(),translation.z());
    
    G4ThreeVector pos_vertex = track->GetVertexPosition();
    G4ThreeVector lp = touchable->GetHistory()->GetTransform(1).TransformPoint(pos_vertex);
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
    
    ///////////////////
    

    
    
    
    
    
    G4double globalTime    = track->GetGlobalTime();
    G4ThreeVector pp =G4ThreeVector(0,0,0.6).rotateY(PrtManager::Instance()->GetAngle()*CLHEP::deg-180*CLHEP::deg); // 0.6
    G4ThreeVector mm =G4ThreeVector(0,0,0.3).rotateY(PrtManager::Instance()->GetAngle()*CLHEP::deg-180*CLHEP::deg); // 0.3
    G4ThreeVector myPoint = G4ThreeVector (pos_vertex.x(), pos_vertex.y(), pos_vertex.z())+ pp;
    G4ThreeVector myPoint2 = G4ThreeVector (pos_vertex.x(), pos_vertex.y(), pos_vertex.z())+mm;
    

    int test_num1 = whereIsthePoint(myPoint);
    int test_num2 = whereIsthePoint(myPoint2);
    

    G4double time = step->GetPreStepPoint()->GetLocalTime();
    G4ThreeVector mom_phs = step->GetPreStepPoint()->GetMomentum();
    TVector3 mom_phs_v(mom_phs.x(),mom_phs.y(),mom_phs.z());
    
    
    //TVector3 globalPos(globalPos.x(),globalPos.y(),globalPos.z());
    TVector3 globalPos(inPrismpos.x(),inPrismpos.y(),inPrismpos.z());
    
    G4bool Reflected= true;
    if(mom_phs.x()> 0) Reflected = false;
    
    
    
    //std::cout<<"#########  ################# MCP: " << test_num1<<" pix: "<< test_num2<< " time = "<<time <<" Reflected: " <<Reflected<<std::endl;
    
    
    
    
    PrtHit hit;
    //Int_t mcpid=touchable->GetReplicaNumber(1);
    //Int_t pixid = touchable->GetReplicaNumber(0);
    
    Int_t mcpid=test_num2;
    Int_t pixid=test_num1;
    
    std::cout<<"#########  ################# MCP: " << mcpid<<" pix: "<< pixid<<std::endl;
    hit.SetMcpId(mcpid);
    hit.SetPixelId(pixid);
    hit.SetGlobalPos(globalPos);
    hit.SetLocalPos(localPos);
    hit.SetDigiPos(digiPos);
    hit.SetPosition(position);
    //hit.SetMomentum(momentum);
    hit.SetMomentum(mom_phs_v);
    hit.SetParticleId(track->GetTrackID());
    hit.SetParentParticleId(track->GetParentID());
    hit.SetNreflectionsInPrizm(refl-1);
    
    
    hit.SetPathInPrizm(pathId);
    hit.SetCherenkovMC(PrtManager::Instance()->GetCurrentCherenkov());
    // time since track created
    
    //G4double time = step->GetPreStepPoint()->GetLocalTime(); // comminted
    //if(PrtManager::Instance()->GetRunType()==0) time = G4RandGauss::shoot(time,PrtManager::Instance()->GetTimeRes()); //resolution [ns] // comminted
    hit.SetLeadTime(globalTime); //
    Double_t wavelength = 1.2398/(track->GetMomentum().mag()*1E6)*1000;
    hit.SetTotTime(wavelength); //set photon wavelength
    // time since event created
    // step->GetPreStepPoint()->GetGlobalTime()*1000

    counter++;
    //if (Reflected){
    if (counter % 2 == 0){
        counter2++;
         //std::cout<<"###### ####### ####### #########  ########### ####### ######### ######## ###### counter out : " << counter<<std::endl;
         //std::cout<<"###### ####### ####### #########  ########### ####### ######### ######## ###### counter in  : " << counter2<<std::endl;
         //std::cout<<"#########  ################# MCP: " << test_num1<<" pix: "<< test_num2<< " time = "<<time <<" Reflected: " <<Reflected<<std::endl;
        PrtManager::Instance()->AddHit(hit);
    }
    //}
    
    
    
    return true;
}


int PrtPixelSD::whereIsthePoint(G4ThreeVector& pos){
    G4ThreeVector null(0.,0.,0.);
    G4ThreeVector *ptr;
    ptr = &null;
    G4VPhysicalVolume *theVolume;
    G4Navigator *gNavigator =G4TransportationManager::GetTransportationManager()->GetNavigatorForTracking();
    theVolume=gNavigator->LocateGlobalPointAndSetup(pos,ptr,true);
    G4String theVolName = theVolume->GetName();
    int number = theVolume->GetCopyNo();
    
    theVolume=gNavigator->LocateGlobalPointAndSetup(null,ptr,true);
    return number;
}





void PrtPixelSD::EndOfEvent(G4HCofThisEvent*){
    memset(fMultHit, 0, sizeof(fMultHit[0][0])*960);
    G4int eventNumber = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
    if(eventNumber%1==0 && PrtManager::Instance()->GetRunType()==0) std::cout<<"Event # "<<eventNumber <<std::endl;
    if(eventNumber%1000==0 && PrtManager::Instance()->GetRunType()!=0) std::cout<<"Event # "<<eventNumber <<std::endl;
    PrtManager::Instance()->Fill();
}






