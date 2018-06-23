#define prt__sim
#include "../src/PrtHit.h"
#include "../src/PrtEvent.h"
#include "../../prttools/datainfo.C"
#include "../../prttools/prttools.C"

#include "TGraph2D.h"


TH1F*  hist_time = new TH1F("hist_time",";measured time [ns];entries [#]",   500,0,50);
TH2F*  hist_xy = new TH2F("hist_xy",";calculated time [ns];measured time [ns]", 400,-20,20, 200,-12,12);
TH1F*  hist_z = new TH1F("hist_z",";measured time [ns];entries [#]",   1000,-1200,1200);

TH1F*  hist_dir_x = new TH1F("hist_dir_x",";dir x component ;entries [#]", 100,-1.0,1.0);
TH1F*  hist_dir_y = new TH1F("hist_dir_y",";dir y component ;entries [#]", 100,-1.0,1.0);
TH1F*  hist_dir_z = new TH1F("hist_dir_z",";dir z component;entries [#]", 200,-1.5,1.5);

TH1F*  hist_pix = new TH1F("hist_pix",";oix num;entries [#]",100 ,0,100);
TH1F*  hist_mcp = new TH1F("hist_mcp",";oix num;entries [#]",100 ,0,100);

//TGraph2D *graph_pos = new TGraph2D();
TGraph *graph_pos = new TGraph();
TGraph *graph_dir = new TGraph();

void drawHP(TString infile="../build/test1.root"){
    
    if(!prt_init(infile,1,"data/drawHPt")) return;
    PrtHit hit;
    int counter = 0;
    Double_t pos_x, pos_y, pos_z;
    Double_t dir_x, dir_y, dir_z;
    
    for (Int_t ievent=0; ievent< prt_entries /*&& ievent< 50000*/; ievent++){
        prt_nextEvent(ievent,1000);
        for(Int_t h=0; h<prt_event->GetHitSize(); h++){
            hit = prt_event->GetHit(h);
            Int_t mcpid = hit.GetMcpId();
            Int_t pixid = hit.GetPixelId()-1;
            Double_t time = hit.GetLeadTime();
            
            //Double_t time = hit.GetPosition().X(), ;
            
            Int_t ch = map_mpc[mcpid][pixid];
            //if(prt_isBadChannel(ch)) continue;
            
            // if(mcpid%3==0 && pixid<32) continue;
            // if(mcpid%3==2 && pixid>=32) continue;
            //cout<< "phs pos= "<<hit.GetPosition().Z()<< endl;
            //cout<< "mcpid= "<<mcpid<< "      pixid= "<<pixid<<" ch= "<<ch<<endl;

            hist_time->Fill(time);
            pos_x=hit.GetGlobalPos().X();
            pos_y=hit.GetGlobalPos().Y();
            pos_z=hit.GetGlobalPos().Z();
            
            TVector3 direction = hit.GetMomentum().Unit();
            dir_x=direction.X();
            dir_y=direction.Y();
            dir_z=direction.Z();
            
            hist_xy->Fill(pos_y, pos_x);
            hist_z->Fill(pos_z);
            
            //cout<< "dir_z "<<dir_z<<endl;
            //graph_pos->SetPoint(counter, pos_x, pos_y, pos_z);
            graph_pos->SetPoint(counter, pos_y, pos_x);
            graph_dir->SetPoint(counter, dir_x, dir_y);
            
            hist_dir_x->Fill(dir_x);
            hist_dir_y->Fill(dir_y);
            hist_dir_z->Fill(dir_z);
            
            
            hist_pix->Fill(pixid);
            hist_mcp->Fill(mcpid);
            
            ++counter;
            prt_hdigi[mcpid]->Fill(pixid%8, pixid/8);
        }
    }
    
    

        
        graph_pos->SetMarkerColor(kBlue);
        graph_pos->SetMarkerStyle(7);
        graph_pos->SetLineWidth(1);
    
    
    
    prt_canvasAdd("r_time",800,400);
    hist_time->Draw();
    prt_canvasAdd("r_hist_pos_xy",800,400);
    hist_xy->Draw("colz");
    prt_canvasAdd("r_hist_pos_z",800,400);
    hist_z->Draw();
    prt_canvasAdd("r_graph_pos_xy",800,400);
    graph_pos->Draw();
    
    prt_canvasAdd("r_graph_dir_xy",800,400);
    graph_dir->Draw();
    
    prt_canvasAdd("r_dir_x",800,400);
    hist_dir_x->Draw();
    prt_canvasAdd("r_dir_y",800,400);
    hist_dir_y->Draw();
    prt_canvasAdd("r_dir_z",800,400);
    hist_dir_z->Draw();
    
    
    prt_canvasAdd("r_pix_num",800,400);
    hist_pix->Draw();
    
    
    prt_canvasAdd("r_mcp_num",800,400);
    hist_mcp->Draw();
    
    
    
    prt_canvasSave(2,0);
    prt_canvasDel("*");
    
    
    prt_drawDigi("m,p,v\n",2017,0,0);
    prt_cdigi->SetName(Form("hp_dataProtonS332_%d_%2.1f",(Int_t)prt_theta,prt_phi));
    prt_canvasAdd(prt_cdigi);
    //prt_cdigi_palette->Draw();
    //prt_canvasSave(1,0);
    
    
}
