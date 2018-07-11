
On the Constructor:

if(fRunType==1 ){
    fLut = new TClonesArray("PrtLutNode");
    fTree = new TTree("prtlut","Look-up table for the geometrical reconstruction.");
    fTree->Branch("LUT",&fLut,256000,2);
    Int_t Nnodes = 5000;
    
    TClonesArray &fLuta = *fLut;
    for (Long64_t n=0; n<Nnodes; n++) {
        new((fLuta)[n]) PrtLutNode(n);
    }
}


void PrtManager::AddHit(PrtHit hit){
    if(fRunType==1){
        if(fMomentum.Angle(fnX1) > fCriticalAngle && fMomentum.Angle(fnY1) > fCriticalAngle){
            Int_t id = 100*hit.GetMcpId() + hit.GetPixelId();
            Double_t time = hit.GetLeadTime();
            ((PrtLutNode*)(fLut->At(id)))->AddEntry(id, fMomentum, hit.GetPathInPrizm(),hit.GetNreflectionsInPrizm(),time,hit.GetLocalPos(),hit.GetDigiPos());
        }
    }
}
