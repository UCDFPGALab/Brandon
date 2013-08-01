#define myPlot_cxx 
#include "myPlot.h"
#include "TROOT.h"

double correct_phi(double phi){
        return (phi >= 0 ? phi : (2*TMath::Pi() + phi));
}

double correct_0_2pi(double phi)
{
      double z=(double)(fmod(2*TMath::Pi()+phi, 2*TMath::Pi()));

         return z;
}




int main(){
 
  gROOT->ProcessLine("#include <vector>");
  gROOT->ProcessLine("#include <map>");
  gSystem->Load("libDCache.so");
  myPlot m_1;
  m_1.Loop();
 
  return 0;
}


void myPlot::Loop()
{

  dataType="mc";  //Only for EA and use "mc"  always
  isoType ="medium";
  string outFile ="Skims_DataQCD_pt120_MET120_CommonSkim";

  //Output Files
  Long64_t maxsize = 500000000;                 
  maxsize *= 100;                                
  TTree::SetMaxTreeSize(maxsize);

  TFile *rfile = new TFile((outFile+"_1.root").c_str(),"RECREATE");


 fChain->LoadTree(0); //force 1st tree to be loaded
 TTree *newtree = fChain->GetTree()->CloneTree(0);
 rfile->cd();




//---these will have final candidate/qcd
std::vector<UInt_t> dEvt, dRun, dLumi;

dEvt.clear();
dRun.clear();
dLumi.clear();

std::vector<int> dFile;
dFile.clear();
 
 
std::vector<int> qEvt, qRun, qLumi;                                                                                                                                                
qEvt.clear();     
qRun.clear();     
qLumi.clear();

//dubplicate check 
map<Int_t, set<Int_t> > DoubleChecker;
int doubleCount=0;

map<Int_t, std::vector<Double_t> > nVtxIso;
map<Int_t, std::vector<Double_t> > nVtxIsoWithRho;


  //get all triggers to check 
  HLTPhotonTrigger.clear();
  HLTPhotonTrigger.push_back("HLT_Photon135_v1");
  HLTPhotonTrigger.push_back("HLT_Photon135_v2");
  HLTPhotonTrigger.push_back("HLT_Photon135_v3");
  HLTPhotonTrigger.push_back("HLT_Photon135_v4");
  HLTPhotonTrigger.push_back("HLT_Photon135_v5");
  HLTPhotonTrigger.push_back("HLT_Photon135_v6");
  HLTPhotonTrigger.push_back("HLT_Photon135_v7");
  HLTPhotonTrigger.push_back("HLT_Photon135_v8");
  HLTPhotonTrigger.push_back("HLT_Photon135_v9");

  HLTPhotonTrigger.push_back("HLT_Photon150_v1");
  HLTPhotonTrigger.push_back("HLT_Photon150_v2");
  HLTPhotonTrigger.push_back("HLT_Photon150_v3");
  HLTPhotonTrigger.push_back("HLT_Photon150_v4");
  HLTPhotonTrigger.push_back("HLT_Photon150_v5");
  HLTPhotonTrigger.push_back("HLT_Photon150_v6");
  HLTPhotonTrigger.push_back("HLT_Photon150_v7");
  HLTPhotonTrigger.push_back("HLT_Photon150_v8");
  HLTPhotonTrigger.push_back("HLT_Photon150_v9");

  HLTPhotonTrigger.push_back("HLT_Photon160_v1");
  HLTPhotonTrigger.push_back("HLT_Photon160_v2");
  HLTPhotonTrigger.push_back("HLT_Photon160_v3");
  HLTPhotonTrigger.push_back("HLT_Photon160_v4");
  HLTPhotonTrigger.push_back("HLT_Photon160_v5");
  HLTPhotonTrigger.push_back("HLT_Photon160_v6");
  HLTPhotonTrigger.push_back("HLT_Photon160_v7");
  HLTPhotonTrigger.push_back("HLT_Photon160_v8");
  HLTPhotonTrigger.push_back("HLT_Photon160_v9");

  HLTPhotonTrigger.push_back("HLT_Photon70_CaloIdXL_PFMET100_v1");
  HLTPhotonTrigger.push_back("HLT_Photon70_CaloIdXL_PFMET100_v2");
  HLTPhotonTrigger.push_back("HLT_Photon70_CaloIdXL_PFMET100_v3");
  HLTPhotonTrigger.push_back("HLT_Photon70_CaloIdXL_PFMET100_v4");
  HLTPhotonTrigger.push_back("HLT_Photon70_CaloIdXL_PFMET100_v5");
  HLTPhotonTrigger.push_back("HLT_Photon70_CaloIdXL_PFMET100_v6");
  HLTPhotonTrigger.push_back("HLT_Photon70_CaloIdXL_PFMET100_v7");
  HLTPhotonTrigger.push_back("HLT_Photon70_CaloIdXL_PFMET100_v8");
  HLTPhotonTrigger.push_back("HLT_Photon70_CaloIdXL_PFMET100_v9");


   
  double MaxMetCut =120.0;
                     

  std::vector<int> foundQCDCandidate;
  std::vector<int> foundSignalCandidate;
//-----------------Event Loop sstart here---------------------------------
 if (fChain == 0) return;
  
    int bugnum=0;  //for tracking deno<num entries

      Long64_t nentries = fChain->GetEntriesFast();
      Long64_t nbytes = 0, nb = 0;


    Int_t cachesize = 200000000; //10 MBytes       
    fChain->SetCacheSize(cachesize); //<<<
    fChain->AddBranchToCache("*");

   bool found_QCDevent=false;  //for control region
   bool found_DATAevent=false;  //for control region

//-----------------------Loop Over events-------------------------------------------------
   for (Long64_t jentry=0; jentry<nentries;jentry++)
  {
	Long64_t ientry = LoadTree(jentry);
	if (ientry < 0) break;
	nb = fChain->GetEntry(jentry);   nbytes += nb;
        

  //----------------------------------------
  //  Event Selection
  //----------------------------------------
  int triggerIndex=-1;
  string triggername;
  int foundGoodVtx=0;

   if( ( passHlt(triggername,triggerIndex) )      &&  
       (!Scraping_isScrapingEvent)  && 
       (passVtx(foundGoodVtx))       
     ) 
      
  {



 
    //------------------------------
     // check if double counting //Remove for MC
     //------------------------------   
        Bool_t DuplicateEvent = kFALSE;
        map<Int_t, set<Int_t> >::iterator runner = DoubleChecker.find(run);
        if (runner == DoubleChecker.end()){
          set<Int_t> evtTemp;
          evtTemp.insert(event);
          DoubleChecker.insert( make_pair(run, evtTemp));
        }
        else{
             set<Int_t>::iterator evter = (*runner).second.find(event);
            if (evter == (*runner).second.end()){
             (*runner).second.insert(event);
             }
             else { DuplicateEvent = kTRUE;
                    }
              }
        if(DuplicateEvent)doubleCount++;
        if(DuplicateEvent)continue;
 



        foundQCDCandidate.clear();
        foundSignalCandidate.clear();
      //--------------------------------
      // Get Photon/QCD candidate
      //--------------------------------
      for(int ipho=0; ipho<Photon_n && ipho< 200; ipho++)
 	{
          if(Photon_pt[ipho]> 120.0 )
             {
                bool mypatphoisEB = ( fabs(Photon_sc_eta[ipho]) < 1.4442 ); 
                bool mypatphoisEE = ( fabs(Photon_sc_eta[ipho]) > 1.4442 );
 
                                        //Get QCD candidate 
					 if( 
                                             (denoPFPhoID(ipho)) &&
                                             (notSpike(ipho))    &&
                                             (mypatphoisEB)      
                                            )foundQCDCandidate.push_back(ipho);   

                                         //Get data candidate 
                                         if(
                                             (passMediumPFPhoID(ipho)) &&
                                             (notSpike(ipho))    &&
                                             (mypatphoisEB)      
                                            )foundSignalCandidate.push_back(ipho); 
             }//pt cut


          
         }//for(int ipho=0; ipho<Photon_n; ipho++)
                      			    

//-------Fill histo here
    bool   myVtxIso  =false;
    double junkvalue =0.0;
    double newEtaJunk=-99.0;
    int    newVtx    =-1;


       //FILL DATA Candiate
         if(foundSignalCandidate.size() > 0 )
          {
             int pc=foundSignalCandidate[0];

              if(TMath::Max((PFWorstiso_Charged03[pc]-rho*EAPFWorstElectroncharged(Photon_sc_eta[pc])),0.0)  < 1.5)myVtxIso=true;

             if( PFMetPt[0] > MaxMetCut &&
                 (jetVeto(pc)) &&
                 (trkVeto(pc)) &&
                 (myVtxIso)    &&
                 (noCosmic(pc))   
               )
                {

                   //Save candidate information for scan
                    dEvt.push_back(event);
                    dRun.push_back(run);
                    dLumi.push_back(luminosityBlock);
                    dFile.push_back(fCurrent);
                }

          //control plots for data 
          if( PFMetPt[0] > MaxMetCut )
              { 
                 found_DATAevent=true;

              }    

        }//found signal candidate



    //FILL QCD Candiates
         if(foundQCDCandidate.size()> 0)
          { 
             int qc=foundQCDCandidate[0];
             double fakeRate_scale= FakeRatePt(Photon_pt[qc]); 

            if( PFMetPt[0] > MaxMetCut &&
                (jetVeto(qc)) &&
                (trkVeto(qc)) &&
                (noCosmic(qc))   
               ) 
               {

                      //save qcd candidate list info 
                      qEvt.push_back(event);
                      qRun.push_back(run);
                      qLumi.push_back(luminosityBlock); 

              }
          //control plots for Qcd 
          if(PFMetPt[0] > MaxMetCut )   
             { 
                   found_QCDevent=true; 
                  
             }


           }

    }//HLT,scraping && good vertex

   if((jentry%100000)==0) cout<<"Event Analyzerd Till Now  =  "<<(jentry+1)<<endl;


    if( (found_QCDevent) || (found_DATAevent))newtree->Fill(); 
    found_QCDevent=false;
    found_DATAevent=false;

   }//for (Long64_t jentry=0; jentry<nentries;jentry++)

  

   newtree->Write();
   rfile->Write();
   rfile->Close();

  std::cout<<"done ! with double counts removed ="<<doubleCount<<std::endl;

  cout<<" QCD events are  = "<<qEvt.size()<<endl;
  for(int i=0; i<qEvt.size(); i++){
  cout<<"Run:  "<<qRun[i]<<"    Lumi: "<<qLumi[i]<<"    Event:  "<<qEvt[i]<<endl;
  }
 
 
  cout<<" Data events are  = "<<dEvt.size()<<endl;
  for(int i=0; i<dEvt.size(); i++){
  cout<<"Run:  "<<dRun[i]<<"    Lumi: "<<dLumi[i]<<"    Event:  "<<dEvt[i]<<"     Data File #: "<<dFile[i]<<endl;
  }
 



}//void loop

//--------------
//  offline Hlt 
//-------------
bool myPlot::passHlt(std::string &TriggerName, int &TriggerIndex){

     bool hltpass=false;
     vector<std::string> hltMyTrigger;
     hltMyTrigger.clear();
     vector<int> hltIndex;
     hltIndex.clear();

   //loop over my desired triggers     
     for(int k=0; k < HLTPhotonTrigger.size(); k++){
       //loop over all triggers
        for(int p=0; p < (*triggernames).size();p++){
             
           string string_search (HLTPhotonTrigger[k]);
           size_t found = (*triggernames)[p].find(string_search);     
                                                                                           
           if(found != string::npos)
              {
                     double  HLTPreScale =  (*triggerprescales)[p];
                     bool    HLTPassed   =  (*ifTriggerpassed)[p];
                  if(HLTPreScale==1 && (HLTPassed) ){hltMyTrigger.push_back(HLTPhotonTrigger[k]);      
                                                     hltIndex.push_back(p); 
                                                    }
               }
       }
    }

   if(hltIndex.size()>0 && hltMyTrigger.size()>0)hltpass=true;

   for(int m=0; m<hltIndex.size(); m++)
       {   //cout<<hltMyTrigger[m]<<endl;
           TriggerIndex= hltIndex[m]; //the last pass trigger index from HLTTrigger array
           TriggerName = hltMyTrigger[m]; //Name of the trigger
          }

   return hltpass;
}


//--------------
// Trigger matching
//-------------

bool myPlot::triggerMatch(std::string triggerName,  // name of the trigger  say "HLT_Photon150_v3"
				 int triggerIndex,       //index of the trigger
				  vector<std::string> filterName,  //name if the filter  say "hltPhoton150HEFilter"
				    int phoIndex,            //offline photon index
				    float maxDeltaRCut)        //delta R =0.2
{
  bool Matched = false;
  float dr     = 999999999.;

  int f_1= (*FilterStartPosition)[triggerIndex];
  int f_2= (*FilterEndPosition)[triggerIndex];
  
  if(f_1 != -1 && f_2 != -1)
    {  
      for(int i=f_1;i<=f_2;i++)  
	{   

         for(int f=0; f<filterName.size(); f++)
          {
	  if( (filterName[f].find( (*FilterNames)[i]) ) !=  std::string::npos )
              {           

                 //cout<<"found Filter = "<<filterName[f]<<endl;

                int obj_1 = (*ObjectStartPosition)[i];	
	        int obj_2 = (*ObjectEndPosition)[i];
		
               if(obj_1 != -1 && obj_2 != -1)
                 {
                    for(int k=obj_1;k<=obj_2;k++)      
                       {  // u could do many things here for other purpose :)
			  float thisDR= DeltaR(Photon_eta[phoIndex],
					       (*ObjectEta)[k],
                                                 Photon_phi[phoIndex],
					          (*ObjectPhi)[k]
                                               ); 
                         if(thisDR < dr)dr= thisDR;
                            //cout<<" dr = "<<dr<<"  for photon: "<<phoIndex<<endl;
                            //cout<<"objectPt ="<<(*ObjectPt)[k]<<", PhotonPT = "<<Photon_pt[phoIndex]<<endl;
                        }//loop over object of desired filter
                  }//check if object is present

                f=100; //if found then no need to loop over desired filtere
              }//check if desired filter is present 

           }//loop over desired filters
         }//loop over filters name
     }//check if filter is present

   if(dr <= maxDeltaRCut )Matched=true;

   return Matched;

}



//--------------------------
//     Vertex Selection
//---------------------------

bool myPlot::passVtx(int &goodVertex){

     bool passvtx=false;
     goodVertex=0;
     int nonFakeVertices=0;
 
       for(int v=0;v< Vertex_n && v< 200; v++)
         {
              if(  fabs(Vertex_z[v]) <= 24.0  && 
                   Vertex_ndof[v] > 4         &&
                   (!Vertex_isFake[v])        && 
                   fabs(Vertex_d0[v]) < 2.0 
                )goodVertex++;
              
         }//loop over v
 
  if(goodVertex>0)passvtx=true;

  return passvtx;
}



//-------------
//  No Splike
//------------
bool myPlot::notSpike(int ipho){

   bool passspike=false;

    if( fabs(Photon_timing_xtal[ipho][0]) < 3.0 && 
        Photon_SigmaIetaIeta[ipho]>0.001        && 
        Photon_SigmaIphiIphi[ipho]>0.001        &&
        Photonr9[ipho]          < 1.0          &&
        fabs(computeLICTD(ipho))        < 5.0   &&
        Photon_mipTotEnergy[ipho]       <  6.3      //removed mip  
        )passspike=true;

   return passspike;

}


//-----------
//Tight ID
//-----------
bool myPlot::passPFTightPhoID(int i) {

      bool ID=false;
    
     if(fabs(Photon_sc_eta[i]) <1.4442 )
      {
           ID =( (TMath::Max(((PFiso_Charged03[i]) - rho*EAElectroncharged(Photon_sc_eta[i],dataType)) ,0.0)  < 0.7  )      &&
                   (Photon_HoEnew[i]     < 0.05)      &&
                   (Photon_SigmaIetaIeta[i]  < 0.011) &&
                   //(Photon_Electronveto[i]      == 1) && 
                   (!Photon_hasPixelSeed[i])   && 
                   (TMath::Max(((PFiso_Photon03[i]) - rho*EAElectronphoton(Photon_sc_eta[i],dataType)) ,0.0) < 0.5+0.005*Photon_pt[i] ) &&
                   (TMath::Max(((PFiso_Neutral03[i])- rho*EAElectronneutral(Photon_sc_eta[i],dataType)) ,0.0) < 0.4+0.04*Photon_pt[i] ) 
                  ) ;
       }

  if(fabs(Photon_sc_eta[i])> 1.4442 )
      { 
         ID =(    (TMath::Max(((PFiso_Charged03[i]) - rho*EAElectroncharged(Photon_sc_eta[i],dataType)) ,0.0)  < 0.5  )      &&
                   (Photon_HoEnew[i]     < 0.05)      &&
                   (Photon_SigmaIetaIeta[i]  < 0.031) &&
                   //(Photon_Electronveto[i]      == 1) &&  
                   (!Photon_hasPixelSeed[i])   &&   
                   (TMath::Max(((PFiso_Photon03[i]) - rho*EAElectronphoton(Photon_sc_eta[i],dataType)) ,0.0) < 1.0+0.005*Photon_pt[i] ) &&
                   (TMath::Max(((PFiso_Neutral03[i])- rho*EAElectronneutral(Photon_sc_eta[i],dataType)) ,0.0) < 1.5+0.04*Photon_pt[i] ) 
                  ) ;
       }

       
        

  return ID; 
    
}
           
//------------- 
//Loose ID
//-------------
bool myPlot::passLoosePFPhoID(int i) {

      bool looseID=false;
    
                 
  if(fabs(Photon_sc_eta[i]) <1.4442 )          
    { 
          looseID =((TMath::Max(((PFiso_Charged03[i]) - rho*EAElectroncharged(Photon_sc_eta[i],dataType)) ,0.0)  < 2.6  )      &&
                 (Photon_HoEnew[i]     < 0.05)      &&
                 (Photon_SigmaIetaIeta[i]  < 0.012) &&
                 //(Photon_Electronveto[i]      == 1) &&
                 (!Photon_hasPixelSeed[i])   &&     
                 (TMath::Max(((PFiso_Photon03[i]) - rho*EAElectronphoton(Photon_sc_eta[i],dataType)) ,0.0) < 1.3+0.005*Photon_pt[i] ) &&
                 (TMath::Max(((PFiso_Neutral03[i])- rho*EAElectronneutral(Photon_sc_eta[i],dataType)) ,0.0) < 3.5+0.04*Photon_pt[i] ) 
                ); 
    }

 if(fabs(Photon_sc_eta[i])> 1.4442 )             
      { 
         looseID =((TMath::Max(((PFiso_Charged03[i]) - rho*EAElectroncharged(Photon_sc_eta[i],dataType)) ,0.0)  < 2.3  )      &&
                   (Photon_HoEnew[i]     < 0.05)      && 
                   (Photon_SigmaIetaIeta[i]  < 0.034) &&
                   //(Photon_Electronveto[i]      == 1) &&
                   (!Photon_hasPixelSeed[i])   &&     
                   (TMath::Max(((PFiso_Neutral03[i])- rho*EAElectronneutral(Photon_sc_eta[i],dataType)) ,0.0) < 2.9+0.04*Photon_pt[i] ) 
                  );         
       }
     
    

  return looseID; 
    
}
           

//--------------
//Medium ID 
//------------- 
bool myPlot::passMediumPFPhoID(int i) {                                                                                        
           
      bool mediumID=false;
           
                 
  if(fabs(Photon_sc_eta[i]) <1.4442 )          
    {      
         mediumID =((TMath::Max(((PFiso_Charged03[i]) - rho*EAElectroncharged(Photon_sc_eta[i],dataType)) ,0.0)  < 1.5  )      &&
                 (Photon_HoEnew[i]     < 0.05)      &&
                 (Photon_SigmaIetaIeta[i]  < 0.011) &&
                 //(Photon_Electronveto[i]      == 1) &&  
                 //(!Photon_hasPixelSeed[i])   &&   
                 (TMath::Max(((PFiso_Photon03[i]) - rho*EAElectronphoton(Photon_sc_eta[i],dataType)) ,0.0) < 0.7+0.005*Photon_pt[i] ) &&
                 (TMath::Max(((PFiso_Neutral03[i])- rho*EAElectronneutral(Photon_sc_eta[i],dataType)) ,0.0) < 1.0+0.04*Photon_pt[i] ) 
                ); 
    }      
           

 if(fabs(Photon_sc_eta[i]) > 1.4442 )             
      {    
         mediumID =((TMath::Max(((PFiso_Charged03[i]) - rho*EAElectroncharged(Photon_sc_eta[i],dataType)) ,0.0) < 1.2  )      &&
                   (Photon_HoEnew[i]         < 0.05)      && 
                   (Photon_SigmaIetaIeta[i]  < 0.033) &&
                   //(Photon_Electronveto[i]      == 1) && 
                   (!Photon_hasPixelSeed[i])   &&   
                   (TMath::Max(((PFiso_Photon03[i]) - rho*EAElectronphoton(Photon_sc_eta[i],dataType)) ,0.0) < 1.0+0.005*Photon_pt[i] ) &&
                   (TMath::Max(((PFiso_Neutral03[i])- rho*EAElectronneutral(Photon_sc_eta[i],dataType)) ,0.0)< 1.5+0.04*Photon_pt[i] ) 
                  );         
       }   
           
           
           
  return mediumID; 
           
}       

 

//-------------------------------
// ID For Denominator
//-------------------------------
bool myPlot::denoPFPhoID(int i) {

      bool denoID=false;
    
     bool upperBound=false;
     bool lowerBound =false;


     double  maxPFCharged= TMath::Min(5.0*(2.6) , 0.20*Photon_pt[i]);
     double  maxPFPhoton = TMath::Min(5.0*(1.3+0.005*Photon_pt[i]) , 0.20*Photon_pt[i]);
     double  maxPFNeutral= TMath::Min(5.0*(3.5+0.04*Photon_pt[i]) , 0.20*Photon_pt[i]);


     upperBound=( (TMath::Max(((PFiso_Charged03[i]) - rho*EAElectroncharged(Photon_sc_eta[i],dataType)) ,0.0)     < maxPFCharged  )    &&
                 (Photon_HoEnew[i]         < 0.05          )    &&
                 (Photon_SigmaIetaIeta[i]  < 0.013        )    &&//<----for beam halo
                //(Photon_Electronveto[i]   == 1            )    && 
                //(!Photon_hasPixelSeed[i])   &&    
                 (TMath::Max(((PFiso_Photon03[i]) - rho*EAElectronphoton(Photon_sc_eta[i],dataType)) ,0.0) < maxPFPhoton ) &&
                 (TMath::Max(((PFiso_Neutral03[i])- rho*EAElectronneutral(Photon_sc_eta[i],dataType)) ,0.0) < maxPFNeutral ) 
                ); 
        
   //invertex lose ids
    lowerBound=((TMath::Max(((PFiso_Photon03[i]) - rho*EAElectronphoton(Photon_sc_eta[i],dataType)) ,0.0) > 1.3+0.005*Photon_pt[i] ) ||
                 (TMath::Max(((PFiso_Neutral03[i])- rho*EAElectronneutral(Photon_sc_eta[i],dataType)) ,0.0) > 3.5+0.04*Photon_pt[i] ) ||
                 (TMath::Max(((PFiso_Charged03[i]) - rho*EAElectroncharged(Photon_sc_eta[i],dataType)) ,0.0) > 2.6  )
                );
        
         if( (upperBound) && (lowerBound) )denoID = true;

  return denoID; 
    
}



//--------------------
// Template Signal ID
//--------------------
bool myPlot::templateSignalID(int i, std::string idType){                                                                                        
                      
      bool mediumID=false;
                      
       double phoThr;                                                                                                                                                          
       double neuThr;                                   
       double chThr;                                  
                                                        
                                                        
     if(idType== "medium")                              
    {                                                   
         if(fabs(Photon_sc_eta[i]) < 1.4442)            
          {  phoThr=0.7;                               
             neuThr=1.0;                                
             chThr=1.5;                              
          }                                             
         if(fabs(Photon_sc_eta[i]) > 1.4442)            
          {  phoThr=1.0;                               
             neuThr=1.5;                                
             chThr=1.2;                              
          }                                             
      }                                                 
                                                        
     if(idType=="tight")                                
      {                                                 
        if(fabs(Photon_sc_eta[i]) < 1.4442)             
          {  phoThr=0.5;                                
             neuThr=0.4;                                
             chThr=0.7;                              
           }                                            
                                                        
      if(fabs(Photon_sc_eta[i]) > 1.4442)               
          {   phoThr=1.0;                               
             neuThr=1.5;                                
             chThr=0.5;                              
          }                        
      
      }
                       
  if(fabs(Photon_sc_eta[i]) <1.4442 )          
    {                 
         mediumID =( (TMath::Max(((PFiso_Charged03[i]) - rho*EAElectroncharged(Photon_sc_eta[i],dataType)) ,0.0)  < chThr )      &&
                     (Photon_HoEnew[i]     < 0.05)      &&
                     //(Photon_Electronveto[i]      == 1) &&
                     (!Photon_hasPixelSeed[i])   &&     
                     (TMath::Max(((PFiso_Photon03[i]) - rho*EAElectronphoton(Photon_sc_eta[i],dataType)) ,0.0) < phoThr+0.005*Photon_pt[i] ) &&
                     (TMath::Max(((PFiso_Neutral03[i])- rho*EAElectronneutral(Photon_sc_eta[i],dataType)) ,0.0) < neuThr+0.04*Photon_pt[i] ) 
                );    
    }                 
                      
                      
 if(fabs(Photon_sc_eta[i]) > 1.4442 )             
      {               
         mediumID =( (TMath::Max(((PFiso_Charged03[i]) - rho*EAElectroncharged(Photon_sc_eta[i],dataType)) ,0.0)  < chThr )      &&
                     (Photon_HoEnew[i]         < 0.05)      && 
                     //(Photon_Electronveto[i]      == 1) && 
                     (!Photon_hasPixelSeed[i])   &&   
                     (TMath::Max(((PFiso_Photon03[i]) - rho*EAElectronphoton(Photon_sc_eta[i],dataType)) ,0.0) < phoThr+0.005*Photon_pt[i] ) &&
                     (TMath::Max(((PFiso_Neutral03[i])- rho*EAElectronneutral(Photon_sc_eta[i],dataType)) ,0.0)< neuThr+0.04*Photon_pt[i] ) 
                  );         
       }              
                      
                      
                      
  return mediumID;    
                      
}          





//--------------------
// Template qcd ID:tight+track flip
//--------------------
bool myPlot::templateQCDID(int i, std::string idType){                                                                                        
                      
      bool templateID=false;

       double phoThr;                                                                                                                                                          
       double neuThr;                   
       double chlowThr;                 
       double chhiThr;


     if(idType== "medium")
    {                     
         if(fabs(Photon_sc_eta[i]) < 1.4442)
          {  phoThr=0.7;
             neuThr=1.0;
             chlowThr=1.5;
             chhiThr=6.0;
          }
         if(fabs(Photon_sc_eta[i]) > 1.4442)
          {   phoThr=1.0;                   
             neuThr=1.5;                    
             chlowThr=1.2;                  
             chhiThr=6.0;                 
          }
      }

     if(idType=="tight")
      {
        if(fabs(Photon_sc_eta[i]) < 1.4442)
          {  phoThr=0.5;
             neuThr=0.4;
             chlowThr=0.7;
             chhiThr=6.0;      
           }

      if(fabs(Photon_sc_eta[i]) > 1.4442)
          {   phoThr=1.0;                   
             neuThr=1.5;                    
             chlowThr=0.5;                  
             chhiThr=6.0;                 
          }

      } 
                      
  if(fabs(Photon_sc_eta[i]) <1.4442 )          
    {                 
         templateID =( 
                     (Photon_HoEnew[i]           < 0.05) &&
                    // (Photon_Electronveto[i]      == 1)  && 
                     (!Photon_hasPixelSeed[i])   &&    
                     (TMath::Max(((PFiso_Photon03[i]) - rho*EAElectronphoton(Photon_sc_eta[i],dataType)) ,0.0) < phoThr+0.005*Photon_pt[i] ) &&
                     (TMath::Max(((PFiso_Neutral03[i])- rho*EAElectronneutral(Photon_sc_eta[i],dataType)) ,0.0) < neuThr+0.04*Photon_pt[i] ) &&
                     (TMath::Max(((PFiso_Charged03[i]) - rho*EAElectroncharged(Photon_sc_eta[i],dataType)) ,0.0)  > chlowThr && TMath::Max(((PFiso_Charged03[i]) - rho*EAElectroncharged(Photon_sc_eta[i],dataType)) ,0.0)  < chhiThr ) //trk side band 
                );    
    }                 
                      
                      
 if(fabs(Photon_sc_eta[i]) > 1.4442 )             
      {               
         templateID =( 
                     (Photon_HoEnew[i]          < 0.05) && 
                    // (Photon_Electronveto[i]      == 1) && 
                     (!Photon_hasPixelSeed[i])   &&   
                     (TMath::Max(((PFiso_Photon03[i]) - rho*EAElectronphoton(Photon_sc_eta[i],dataType)) ,0.0) < phoThr+0.005*Photon_pt[i] ) &&
                     (TMath::Max(((PFiso_Neutral03[i])- rho*EAElectronneutral(Photon_sc_eta[i],dataType)) ,0.0)< neuThr+0.04*Photon_pt[i] ) &&
                     (TMath::Max(((PFiso_Charged03[i]) - rho*EAElectroncharged(Photon_sc_eta[i],dataType)) ,0.0)  > chlowThr  && TMath::Max(((PFiso_Charged03[i]) - rho*EAElectroncharged(Photon_sc_eta[i],dataType)) ,0.0)  < chhiThr ) //trk side band 
                  );         
       }              
                      
  return templateID;    
                      
}          


            
//--------------
// LICTD/
//--------------
double myPlot::computeLICTD(int i){
            
      Float_t SeedTime = -999;
      Float_t SeedE    = -999;
      Int_t crysIdx = -1;
            
        for (int k=0;k<Photon_ncrys[i]&&k<100;++k)
       {    
          Float_t crysE = Photon_energy_xtal[i][k];
            
         if (crysE > SeedE){
            SeedE = crysE;
            SeedTime = Photon_timing_xtal[i][k];
            crysIdx = k;
          } 
        }   
            
            
    Float_t LICTD   = 99.;
            
          if (fabs(SeedTime)< 3.)
           {    
              LICTD   = 0;
              Int_t crysCrys  =-1;
              Int_t crysThresh= 0;
            
             for (int k=0;k<Photon_ncrys[i]&&k<100;++k)
               {   
                   if (crysIdx==k) continue;
                    Float_t crysE = Photon_energy_xtal[i][k];
                                                                                                                                                      
                  if (crysE > 1.)
                    { 
                         crysThresh++;
                         Float_t tdiff = Photon_timing_xtal[i][crysIdx] -
                         Photon_timing_xtal[i][k];
                       if (fabs(tdiff) > fabs(LICTD))
                           {
                               LICTD = tdiff;
                               crysCrys=k;
                           }
                     } 
                }   
           }     
            
            
   return LICTD;
}


//-------------------
//Vertex Isolation
//------------------

bool myPlot::GetRightVtxIso(int PC, 
                              double &vtxIsovalue, 
                               double &NEWETA,
                                int  &newVtx)
   {                   
         Float_t sumIsoMax1=0;
         Int_t VtxMax      =-1;
         Float_t newtheta  =0.;
         Float_t neweta    =-99.; 
         Float_t NEWTHETA  =-999.;
                NEWETA     =-999.;
        //take all vertices.
        //Loop over all tracks (except electrons) within dz of some 
        //find max iso sum
 
       for (int iii=0;iii<Vertex_n;++iii)
        {              
            Float_t tempSSPT=0;
            //We have now selected vertex iii.  Calculate
            //the photon eta with respect to this vertex
            Float_t RCal = sqrt(Photon_sc_x[PC]*Photon_sc_x[PC]
                             +Photon_sc_y[PC]*Photon_sc_y[PC]);
 
            Float_t NewZ = Vertex_z[iii];
            newtheta = atan2(RCal, Photon_sc_z[PC]-NewZ);
             neweta = -1. * log(tan(newtheta/2.));

             if(iii==0){  NEWETA= neweta;
                          NEWTHETA =newtheta;
                        }   
 
         for(int iiii=0;iiii<Track_n;++iiii)
            {          
               Float_t dz = fabs(Track_vz[iiii] - Vertex_z[iii]);
               Float_t dR = DeltaR(neweta,Track_eta[iiii], Photon_phi[PC],Track_phi[iiii]);
               if (dz<0.1 && dR < 0.3 && dR > 0.04)tempSSPT+=Track_pt[iiii];
             //  if (dz<0.1 && dR < 0.4 && dR > 0.04)tempSSPT+=Track_pt[iiii];   //EXO
            }          
 
          if (tempSSPT > sumIsoMax1)
              {        
                    sumIsoMax1 = tempSSPT;
                    VtxMax = iii;
                    NEWETA= neweta;
                    NEWTHETA =newtheta; 
              }

        
          }              

             vtxIsovalue  = sumIsoMax1; 
      double Photon_newPt = ( Photon_E[PC]*fabs(sin(NEWTHETA)) );
      newVtx= VtxMax;
            //for EB                       
      double threshold;              
       if(isoType == "tight")threshold=0.7;
       if(isoType == "medium")threshold=1.5; 
                                     
      bool  PassFailed = (TMath::Max((sumIsoMax1 - rho*EAElectroncharged(NEWETA,dataType)) ,0.0) < threshold );  

     // bool PassFailed = (sumIsoMax1< 2.0 + 0.001*Photon_newPt );  //EXO
 

      return PassFailed;
 
 }



//---------------------------------------------------
//Effective area for electron and photon based on eta
//---------------------------------------------------
double myPlot::EAElectroncharged(double eta, string dataType){
  float EffectiveArea=0.;            
/*                                   
 if(dataType == "data")              
{                                    
  if (fabs(eta) >= 0.0   && fabs(eta) < 1.0 )   EffectiveArea = 0.002;
  if (fabs(eta) >= 1.0   && fabs(eta) < 1.4442 ) EffectiveArea = 0.003;
 }                                   
                                     
*/                                   
               
                                     
if( dataType == "mc")
{                      
  if (fabs(eta) < 1.0 )   EffectiveArea = 0.012;
  if (fabs(eta) >= 1.0   && fabs(eta) < 1.479 ) EffectiveArea = 0.010;
  if (fabs(eta) >= 1.479   && fabs(eta) < 2.0 ) EffectiveArea = 0.014;
  if (fabs(eta) >= 2.0   && fabs(eta) < 2.2 ) EffectiveArea = 0.012;
  if (fabs(eta) >= 2.2   && fabs(eta) < 2.3 ) EffectiveArea = 0.016;                                                                                                               
  if (fabs(eta) >= 2.3   && fabs(eta) < 2.4 ) EffectiveArea = 0.020;                                                                                                               
  if (fabs(eta) >= 2.4  ) EffectiveArea = 0.012; 
 }                                   
                                     
                                     
  return EffectiveArea;              
}                                    
                                     

double myPlot::EAElectronneutral(double eta, string dataType){
  float EffectiveArea=0.;           
/*                                  
if(dataType == "data")              
 {                                  
  if (fabs(eta) < 1.0 )   EffectiveArea = 0.024;
  if (fabs(eta) >= 1.0   && fabs(eta) < 1.479 ) EffectiveArea = 0.037;
 }                                  
*/                                  
 
if( dataType == "mc")                           
 {                                  
  if (fabs(eta) < 1.0 )   EffectiveArea = 0.030;
  if (fabs(eta) >= 1.0   && fabs(eta) < 1.479 ) EffectiveArea = 0.057;
  if (fabs(eta) >= 1.479   && fabs(eta) < 2.0 ) EffectiveArea = 0.039;
  if (fabs(eta) >= 2.0   && fabs(eta) < 2.2 ) EffectiveArea = 0.015;
  if (fabs(eta) >= 2.2   && fabs(eta) < 2.3 ) EffectiveArea = 0.024;
  if (fabs(eta) >= 2.3   && fabs(eta) < 2.4 ) EffectiveArea = 0.039;                                                                                                               
  if (fabs(eta) >= 2.4  ) EffectiveArea = 0.072; 
 }                                  
 
                                    
  return EffectiveArea;             
 
}                                   


double myPlot::EAElectronphoton(double eta, string dataType){                                                                                                                                      
  float EffectiveArea=0.;       
/*                              
 if( dataType == "data")        
{                               
  if (fabs(eta) < 1.0 )   EffectiveArea = 0.081;
  if (fabs(eta) >= 1.0   && fabs(eta) < 1.479 ) EffectiveArea = 0.084;
 }                              
*/                              
if( dataType == "mc")           
 {                              
  if (fabs(eta) < 1.0 )   EffectiveArea = 0.148;
  if (fabs(eta) >= 1.0   && fabs(eta) < 1.479 ) EffectiveArea = 0.130;
  if (fabs(eta) >= 1.479   && fabs(eta) < 2.0 ) EffectiveArea = 0.112;
  if (fabs(eta) >= 2.0   && fabs(eta) < 2.2 ) EffectiveArea = 0.216;
  if (fabs(eta) >= 2.2   && fabs(eta) < 2.3 ) EffectiveArea = 0.262;
  if (fabs(eta) >= 2.3   && fabs(eta) < 2.4 ) EffectiveArea = 0.260;
  if (fabs(eta) >= 2.4  ) EffectiveArea = 0.266; 
 }                              
                                
                                
  return EffectiveArea;         
}                               


double myPlot::EAPFWorstElectroncharged(double eta){
 float EffectiveArea=0.;
 if (fabs(eta) < 1.0 )   EffectiveArea = 0.075;
 if (fabs(eta) >= 1.0   && fabs(eta) < 1.4442 ) EffectiveArea = 0.062;

 return EffectiveArea;
}


double myPlot::DeltaR(double eta1, double eta2, double phi1,double phi2)                                                                                                   
{                       
                        
         double pfdPhi = fabs(phi1-phi2);
                        
          Double_t pi =3.141592654;
          Double_t twopi =2.0*pi;
                        
          if(pfdPhi<0) pfdPhi=-pfdPhi;
          if(pfdPhi>=(2*pi-pfdPhi))pfdPhi= 2.0*pi-pfdPhi;
                        
                        
         //if (pfdPhi > TMath::Pi()) pfdPhi = TMath::Pi()*2. - pfdPhi;                                                                                  
         double pfdEta = fabs(eta1-eta2);
                        
         double pfDR =1.0;
                        
         pfDR= pow((pfdPhi*pfdPhi + pfdEta*pfdEta),0.5);
                        
                        
       return pfDR;     
}



double myPlot::getDPhi(double phi1,double phi2)                                                                                                   
{                       
                        
         double pfdPhi = -999.;
           
          pfdPhi=fabs(phi1-phi2);
                        
          Double_t pi =3.141592654;
          Double_t twopi =2.0*pi;
                        
          if(pfdPhi<0) pfdPhi=-pfdPhi;
          if(pfdPhi>=(2*pi-pfdPhi))pfdPhi= 2.0*pi-pfdPhi;
                        
                        
       return pfdPhi;     
}



///------------------------------------Below are the OLD EXO IDs


//-----------------
//  Exo2011 tightID
//------------------        
bool myPlot::passEXOTightPhoID(int i) {

      bool ID=false;
    
     if(fabs(Photon_sc_eta[i]) <1.4442 )
      {
           ID =(Photon_HoE[i] < 0.05              && 
                Photon_ecalRecHitSumEtConeDR04[i] < 4.2+0.006*Photon_pt[i] &&
                Photon_hcalTowerSumEtConeDR04[i]  < 2.2+0.0025*Photon_pt[i]&& 
                Photon_trkSumPtHollowConeDR04[i]  < 2.0+0.001*Photon_pt[i] &&
                Photon_SigmaIetaIeta[i]           < 0.013                  &&
                (!Photon_hasPixelSeed[i])                          
               );

       }

  if(fabs(Photon_sc_eta[i])> 1.4442 )
      { 
         ID =( Photon_HoE[i]< 0.05                &&
               Photon_ecalRecHitSumEtConeDR04[i] < 4.2+0.006*Photon_pt[i]  &&
               Photon_hcalTowerSumEtConeDR04[i]  < 2.2+0.0025*Photon_pt[i]  && 
               Photon_trkSumPtHollowConeDR04[i]  < 2.0+0.001*Photon_pt[i]  &&
               Photon_SigmaIetaIeta[i]           < 0.030  && 
               (!Photon_hasPixelSeed[i])                                  
              ); 
       }

        
        

  return ID; 
}


//-----------------
//  Exo2011 LooseID
//------------------        
bool myPlot::passEXOLoosePhoID(int i) {
 
      bool ID=false;
            
     if(fabs(Photon_sc_eta[i]) <1.4442 )
      {     
           ID =(Photon_HoE[i] < 0.05              && 
                Photon_ecalRecHitSumEtConeDR04[i] < 4.2+0.006*Photon_pt[i] &&
                Photon_hcalTowerSumEtConeDR04[i]  < 2.2+0.0025*Photon_pt[i]&& 
                Photon_trkSumPtHollowConeDR04[i]  < 3.5+0.001*Photon_pt[i] &&
                Photon_SigmaIetaIeta[i]           < 0.013                  &&
                (!Photon_hasPixelSeed[i])                          
               );
 
       }    
  if(fabs(Photon_sc_eta[i])> 1.4442 )
      {     
         ID =( Photon_HoE[i]< 0.05                &&
               Photon_ecalRecHitSumEtConeDR04[i] < 4.2+0.006*Photon_pt[i]  &&
               Photon_hcalTowerSumEtConeDR04[i]  < 2.2+0.0025*Photon_pt[i]  && 
               Photon_trkSumPtHollowConeDR04[i]  < 3.5+0.001*Photon_pt[i]  &&
               Photon_SigmaIetaIeta[i]           < 0.030  && 
               (!Photon_hasPixelSeed[i])                                  
              ); 
       }    
 
            
            
 
  return ID; 
}

  
//-----------------                    
//  Exo2011 Deno ID                    
//------------------                   
bool myPlot::denoEXOPhoID(int i){
                                       
      bool denoID=false;          
      bool upperBound=false;
      bool lowerBound=false;           

     double lecalcut = 4.2+0.006*Photon_pt[i];
     double lhcalcut = 2.2+0.0025*Photon_pt[i];
     double ltrkcut  = 3.5+0.001*Photon_pt[i];

                                      
     double lminecalcut = TMath::Min( 5.0*lecalcut,0.2*Photon_pt[i] );
     double lminhcalcut = TMath::Min( 5.0*lhcalcut,0.2*Photon_pt[i] );
     double lmintrkcut  = TMath::Min( 5.0*ltrkcut,0.2*Photon_pt[i] ) ;


 
     if(fabs(Photon_sc_eta[i]) <1.4442 )
      {                                                                                                                                               
           upperBound =( Photon_HoE[i] < 0.05              && 
                         Photon_ecalRecHitSumEtConeDR04[i] < lminecalcut &&
                         Photon_hcalTowerSumEtConeDR04[i]  < lminhcalcut && 
                         Photon_trkSumPtHollowConeDR04[i]  < lmintrkcut &&
                         Photon_SigmaIetaIeta[i]           < 0.013 &&  //<-----for beam halo
                        (!Photon_hasPixelSeed[i])                          
                       );                      

          lowerBound =( Photon_ecalRecHitSumEtConeDR04[i]  > lecalcut ||
                         Photon_hcalTowerSumEtConeDR04[i]  > lhcalcut || 
                         Photon_trkSumPtHollowConeDR04[i]  > ltrkcut 
                       );
                                       
       }                               

                                       
  if(fabs(Photon_sc_eta[i])> 1.4442 )  
      {
           upperBound =( Photon_HoE[i] < 0.05              &&    
                         Photon_ecalRecHitSumEtConeDR04[i] < lminecalcut &&
                         Photon_hcalTowerSumEtConeDR04[i]  < lminhcalcut && 
                         Photon_trkSumPtHollowConeDR04[i]  < lmintrkcut &&
                         Photon_SigmaIetaIeta[i]           < 0.03 &&
                        (!Photon_hasPixelSeed[i])                          
                       );                      
           
          lowerBound =( Photon_ecalRecHitSumEtConeDR04[i]  > lecalcut ||
                         Photon_hcalTowerSumEtConeDR04[i]  > lhcalcut || 
                         Photon_trkSumPtHollowConeDR04[i]  > ltrkcut 
                       );
                                
       }                               
                                       
    
   if((upperBound) && (lowerBound))denoID=true;      
                                
                                       
                                       
  return denoID;                           
}           


 
//--------------------
// EXO Template Signal ID
//--------------------
bool myPlot::templateEXOSignalID(int i){                                                                                        
                      
      bool templateID=false;
                                                        
 
  if(fabs(Photon_sc_eta[i]) <1.4442 )          
      { templateID=( Photon_HoE[i] < 0.05              &&
                     Photon_ecalRecHitSumEtConeDR04[i] < 4.2+0.006*Photon_pt[i] &&
                     Photon_hcalTowerSumEtConeDR04[i]  < 2.2+0.0025*Photon_pt[i]&& 
                     Photon_trkSumPtHollowConeDR04[i]  < 2.0+0.001*Photon_pt[i] &&
                    (!Photon_hasPixelSeed[i])
                  );                    
       }                 
                      
                      
 if(fabs(Photon_sc_eta[i]) > 1.4442 )             
     { templateID=(  Photon_HoE[i] < 0.05              &&
                   Photon_ecalRecHitSumEtConeDR04[i] < 4.2+0.006*Photon_pt[i] &&
                   Photon_hcalTowerSumEtConeDR04[i]  < 2.2+0.0025*Photon_pt[i]&& 
                   Photon_trkSumPtHollowConeDR04[i]  < 2.0+0.001*Photon_pt[i] &&
                   (!Photon_hasPixelSeed[i])
                 );                    
       }  
                      
                      
  return templateID;    
                      
}          


//--------------------
// EXO Template qcd ID:tight+track flip
//--------------------
bool myPlot::templateEXOQCDID(int i) {                                                                                        
                      
      bool templateID=false;
      double upperBound=false;  
      double lowerBound=false;                     
 
  if(fabs(Photon_sc_eta[i]) <1.4442 )          
    {                 
        templateID =( Photon_HoE[i] < 0.05               &&
                       Photon_ecalRecHitSumEtConeDR04[i] < 4.2+0.006*Photon_pt[i] &&
                       Photon_hcalTowerSumEtConeDR04[i]  < 2.2+0.0025*Photon_pt[i] && 
                       (!Photon_hasPixelSeed[i])                                   &&
                       Photon_trkSumPtHollowConeDR04[i]  > 2.0+0.001*Photon_pt[i] &&
                       Photon_trkSumPtHollowConeDR04[i]  < 4.0+0.001*Photon_pt[i] 
                       );   
     }                 
                      
                      
 if(fabs(Photon_sc_eta[i]) > 1.4442 )             
      { templateID =( Photon_HoE[i] < 0.05               &&
                       Photon_ecalRecHitSumEtConeDR04[i] < 4.2+0.006*Photon_pt[i] &&
                       Photon_hcalTowerSumEtConeDR04[i]  < 2.2+0.0025*Photon_pt[i] && 
                       (!Photon_hasPixelSeed[i]) &&   
                       Photon_trkSumPtHollowConeDR04[i]  > 2.0+0.001*Photon_pt[i] &&
                       Photon_trkSumPtHollowConeDR04[i]  < 4.0+0.001*Photon_pt[i] 
                       );
       }              


                      
  return templateID;    
                      
}



//-----------------
// Jet Veto
//---------------


bool myPlot::jetVeto(int PC){

    bool accept=true;

    //Check Jet Veto     
    for(int j=0;j<pfJet_n;j++)
      {           
           float drp=1.0;

           if(PC >= 0 )drp=DeltaR(pfJet_eta[j],Photon_eta[PC],pfJet_phi[j],Photon_phi[PC]);
                     
           if(drp > 0.5)
             { if(pfJet_pt[j]> 40.0 && fabs(pfJet_eta[j])< 3.0)accept =false;

              }      
                     
       }           
                     
   return accept;

}


//-------------
// Track Veto
//------------

bool myPlot::trkVeto(int PC){
                 
    bool accept=true;

   //check Track Veto 
    for(int t=0;t<Track_n;t++)
     {            
           float dtrp=1.0;
 
           if(PC >= 0 )dtrp=DeltaR(Track_eta[t],Photon_eta[PC],Track_phi[t],Photon_phi[PC]);
                      
           if( dtrp > 0.04)
            {         
             if(Track_pt[t]> 20.0 )accept =false;
             }        
                      
       }      

    return accept;
    
}      

//-----------
// Cosmic veto
//-----------

bool myPlot::noCosmic(int PC){    

    bool noCosmicMuon=true;
     bool hasCosMuon=false;

     for (int kk=0;kk<CosmicMuon_n;++kk)
     {
       if (CosmicMuon_OuterTrack_isNonnull[kk]==1 && CosmicMuon_isStandAloneMuon[kk]==1)
           hasCosMuon=true;
     }
         
    if(hasCosMuon)noCosmicMuon=false;             

   return noCosmicMuon;
    
}



double myPlot::getFakeRate(int qc){
 
     double fr=1.0;

     return fr;


}



//Fake Rate Fit Funciton

double myPlot::FakeRatePt(double x)
{
   double scale=1.0;

 //For 2012PFMedium Full dataset
      
   double p0=0.056;                                                                                                                                  
   double p1=0.0002466;
      
   scale =  p0 + x*p1;   

  return scale;
}

