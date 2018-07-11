#define prt__sim
#include "../src/PrtHit.h"
#include "../src/PrtEvent.h"
#include "../src/PrtLutNode.h"
#include "../../prttools/datainfo.C"
#include "../../prttools/prttools.C"

#include "TGraph2D.h"
#include "TRotation.h"
#include "TMath.h"
#include "TROOT.h"
#include "TVector3.h"


void lut_read(TString infile="test.root"){ //lut_opt_332_2018_cs_avr.root
    if(!prt_init(infile,1,"data/drawHPt")) return;
    PrtHit hit;
    if(infile=="") return;
    const int nmcp = 12, npix = 64;
    TFile* f = new TFile(infile);
    TTree* t = (TTree*)f->Get("prtlut");
    TClonesArray *fLut = new TClonesArray("PrtLutNode");
    t->SetBranchAddress("LUT",&fLut);
    t->GetEntry(0);
    Double_t evtime;
    TVector3 dird;
    Int_t mcpid, pixid;
    PrtLutNode *fLutNode[5000];
    PrtLutNode *node;
    
    for(int i=0; i<5000; i++){
        node = (PrtLutNode*) fLut->At(i);
        Int_t size = node->Entries();
        if(size > 0){
            //cout<<"node "<<fLutNode[i]->GetDetectorId()<<" has "<<size<<endl;
            mcpid = i/100;   // old
            pixid = i%100-1; // old
            
            for(int u=0; u<size; u++){
                evtime = node->GetTime(u);
                //hPTime[mcpid][pixid]->Fill(evtime);
                prt_hdigi[mcpid]->Fill(pixid%8, pixid/8);
                cout<<"mcpid "<<mcpid<<" pixid "<<pixid<<endl;
                
                cout<<"evtime "<<evtime<<endl;

           
            }
            
            
        }
    }

    
    
    
    //
    //    for(Int_t i=0; i<770; i++) {
    //        Int_t direction_lut =fLutNode[i]->Entries();
    //        hist_ambiguity->Fill(i, direction_lut);
    //    }
    //    Double_t pos_x,pos_y, pos_z;
    //    for (Int_t mcpid_int=0; mcpid_int<12; mcpid_int++){
    //        for (Int_t pixid_int=1; pixid_int<65; pixid_int++){
    //            Int_t sensorId_int = 100*mcpid_int + pixid_int ;
    //            pos_x   = fLutNode[sensorId_int]->GetDigiPos().X();
    //            pos_y   = fLutNode[sensorId_int]->GetDigiPos().Y();
    //            pos_z   = fLutNode[sensorId_int]->GetDigiPos().Z();
    //            lut_pix_pos_xy->Fill(pos_x ,pos_y);
    //        }
    //    }
    
    

        prt_drawDigi("m,p,v\n",2017,0,0);
        prt_cdigi->SetName(Form("hp_dataProtonS332_%d_%2.1f",(Int_t)prt_theta,prt_phi));
        prt_canvasAdd(prt_cdigi);
        //prt_cdigi_palette->Draw();
        //prt_canvasSave(1,0);
    
    
    
    
    
}


