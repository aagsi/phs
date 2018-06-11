// -----------------------------------------
// PrtPrimaryGeneratorAction class
//
// Author  : R.Dzhygadlo at gsi.de
// -----------------------------------------

#ifndef PrtPrimaryGeneratorAction_h
#define PrtPrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleDefinition.hh"
#include "globals.hh"


#include "TString.h"
#include "TFile.h"
#include "TTree.h"

#include "PrtEvent.h"
#include "PrtHit.h"



class G4ParticleGun;
class G4Event;
class PrtPrimaryGeneratorMessenger;

class PrtPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
public:
  PrtPrimaryGeneratorAction();
  virtual ~PrtPrimaryGeneratorAction();

public:
  virtual void GeneratePrimaries(G4Event*);

  void SetOptPhotonPolar();
  void SetOptPhotonPolar(G4double);

private:
  G4ParticleGun* fParticleGun;
  G4ParticleDefinition* fParticleP;
  G4ParticleDefinition* fParticlePi;
  PrtPrimaryGeneratorMessenger* fGunMessenger;
    
//
    TClonesArray *fLut_gen;
    TFile *fFile_gen;
    TTree *fTree_gen;
    
};

#endif
