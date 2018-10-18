TClonesArray *fLutNew;


void lutaddbar(TString inFile = "/lustre/nyx/panda/aali/phs/build/1m*.root", TString outFile = "lut_all.root") {

    TFile *fFileNew = TFile::Open(outFile, "RECREATE");
    TTree *fTreeNew = new TTree("prtlut","Look-up table for DIRC. Averaged");
    fLutNew = new TClonesArray("PrtLutNode");
    fTreeNew->Branch("LUT",&fLutNew,256000,2);


    Int_t Nnodes = 5000;
    TClonesArray &fLutaNew = *fLutNew;
    for (Long64_t n=0; n<Nnodes; n++) {
        new((fLutaNew)[n]) PrtLutNode(-1);
    }


    if(inFile.Contains("*")) {
        TString tname = inFile;
        TString tname1 = inFile;
        TString tname2 = inFile;
        TString end = tname1.Remove(0,inFile.Last('*')+1);
        TString start = tname2.Remove(inFile.Last('*'));

        TString dirname= tname.Remove(inFile.Last('/')) + "/";

        const char *ext=".root";
        TSystemDirectory dir(dirname, dirname);
        TList *files = dir.GetListOfFiles();
        if (files) {
            TSystemFile *file;
            TString fname;
            TIter next(files);
            while ((file=(TSystemFile*)next())) {
                fname = file->GetName();
                if (!file->IsDirectory() && fname.EndsWith(ext)) {
                    TString path = dirname+fname;
                    TString substr = path.SubString(start);
                    if( substr.Length()>0 && path.EndsWith(end)) {
                        adddirs(path);
                    }
                }
            }
        }
    } else {
        adddirs(inFile);
    }

    TFile *fFileNew = TFile::Open(outFile,"RECREATE");
    fTreeNew->Fill();
    fTreeNew->Write();
    fFileNew->Write();
    std::cout<<"File  "<<outFile<<" was created." <<std::endl;

}


void adddirs(TString filename) {
    TFile* f = new TFile(filename);
    TTree *t=(TTree *) f->Get("prtlut") ;
    TClonesArray* fLut;
    t->SetBranchAddress("LUT",&fLut);
    t->GetEntry(0);

    for (Int_t inode=0; inode<fLut->GetEntriesFast(); inode++) {
        if(inode%1000==0) cout<<"Node # "<<inode<<endl;
        node= (PrtLutNode*) fLut->At(inode);
        Int_t size = node->Entries();
        if (size==0) continue;
        
        cout <<filename<<  "  id =" << node->GetDetectorId()<< endl;
       // ((PrtLutNode*)(fLutNew->At(inode)))->AddEntry(node->GetDetectorId(), sum,pArray[j],node->GetNRefl(0),sumt, node->GetDigiPos(),node->GetDigiPos(),vArray[j].size()/(Double_t)size);
    }
    f->Close();
}




