#include <../src/PrtLutNode.h>
#include <TTree.h>
#include <TFile.h>
#include <TVector3.h>
#include <TInterpreter.h>
#include <TClonesArray.h>


void lutmean_cs(TString baseFile = "../data/lut.root"){
  //gROOT->ProcessLine(".L ../src/PrtLutNode.cxx+");
  gInterpreter->GenerateDictionary("vector<TVector3>","TVector3.h"); 
  
  TString inFile =baseFile;
  TString outFile = baseFile.Remove(baseFile.Last('.'))+"_cs_avr.root";

  TFile* f = new TFile(inFile);
  TTree *t=(TTree *) f->Get("prtlut") ;
  TClonesArray* fLut=new TClonesArray("PrtLutNode");
  t->SetBranchAddress("LUT",&fLut); 
  t->GetEntry(0);

  TFile *fFileNew = TFile::Open(outFile, "RECREATE");
  TClonesArray *fLutNew;

  TTree *fTreeNew = new TTree("prtlut","Look-up table for DIRC. Averaged");

  fLutNew = new TClonesArray("PrtLutNode");
  fTreeNew->Branch("LUT",&fLutNew,256000,2); 

  Int_t Nnodes = 5000;
  TClonesArray &fLutaNew = *fLutNew;
  for (Long64_t n=0; n<Nnodes; n++) {
    new((fLutaNew)[n]) PrtLutNode(-1);
  }
  
  std::vector<TVector3> vArray[100];
  std::vector<TVector3> lArray[100];
  std::vector<Double_t> tArray[100];
  std::vector<Double_t> pArray;

  Double_t cut(0), weight[9];
  TVector3 dir, pos, sum[9];
  Double_t angle, minangle,pathid,time,sumt;
  PrtLutNode *node;

  for (Int_t inode=0; inode<fLut->GetEntriesFast(); inode++){
    if(inode%1000==0) cout<<"Node # "<<inode<<endl;
    node= (PrtLutNode*) fLut->At(inode);
    Int_t size = node->Entries();    
    if(size<1) continue;
    for(int i=0; i<size; i++){
      dir = node->GetEntry(i);
      pos = node->GetHitPos(i);
      time = node->GetTime(i);
      pathid = node->GetPathId(i);

      bool newid = true;
      for(int j=0; j<pArray.size(); j++){
	if(pathid == pArray[j]){
	  vArray[j].push_back(dir);
	  lArray[j].push_back(pos);
	  tArray[j].push_back(time);
	  newid= false;
	}
      }
      if(newid) {
	vArray[pArray.size()].push_back(dir);
	lArray[pArray.size()].push_back(pos);
	tArray[pArray.size()].push_back(time);
	pArray.push_back(pathid);
      }
    }
  
    for(int j=0; j<pArray.size(); j++){
      for(Int_t s=0; s<9; s++) {
	weight[s]=0;
	sum[s] = TVector3(0,0,0);	
      }
      
      sumt=0;
      for(int v=0; v<vArray[j].size(); v++) {
	sum[0] += vArray[j][v];
	weight[0]++;
	if(lArray[j][v].X()<cut) {
	  sum[1] += vArray[j][v];
	  weight[1]++;
	}
	if(lArray[j][v].X()<cut && lArray[j][v].Y()>cut) {
	  sum[2] += vArray[j][v];
	  weight[2]++;
	}
	if(lArray[j][v].Y()>cut) {
	  sum[3] += vArray[j][v];
	  weight[3]++;
	}
	if(lArray[j][v].X()>cut && lArray[j][v].Y()>cut) {
	  sum[4] += vArray[j][v];
	  weight[4]++;
	}

	if(lArray[j][v].X()>cut) {
	  sum[5] += vArray[j][v];
	  weight[5]++;
	}
	if(lArray[j][v].X()>cut && lArray[j][v].Y()<cut) {
	  sum[6] += vArray[j][v];
	  weight[6]++;
	}
	if(lArray[j][v].Y()<cut) {
	  sum[7] += vArray[j][v];
	  weight[7]++;
	}
	if(lArray[j][v].X()<cut && lArray[j][v].Y()<cut) {
	  sum[8] += vArray[j][v];
	  weight[8]++;
	}
	
	sumt += tArray[j][v]; 
      }
      
      if(weight[0]<10) continue;      
      for(Int_t s=0; s<9; s++) {
	//std::cout<<s<<" "<<weight[s] <<std::endl;
	sum[s] *= 1/weight[s];
      }
      
      sumt *= 1/weight[0];
      
      ((PrtLutNode*)(fLutNew->At(inode)))->AddEntry(node->GetDetectorId(), sum[0],pArray[j],node->GetNRefl(0),sumt, node->GetDigiPos(),node->GetDigiPos(),vArray[j].size()/(Double_t)size,
						    sum[1],sum[2],sum[3],sum[4],sum[5],sum[6],sum[7],sum[8]); 
    }
    for(int i=0; i<100; i++) {vArray[i].clear();  tArray[i].clear(); lArray[i].clear();}
    pArray.clear();
  }

  fTreeNew->Fill();
  fTreeNew->Write();

}
