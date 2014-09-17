#include <math.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include "TCanvas.h"
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include <iomanip>
#include <TApplication.h> 
#include <TRint.h>
#include <TROOT.h>
#include <TStyle.h>
#include "koptions.h"

using namespace std;
using namespace kutil;

int Photon_n;
float Photon_sc_eta[15];
float PFiso_Charged03[15];
float rho;
float Photon_HoEnew[15];
float Photon_SigmaIetaIeta[15];
bool Photon_hasPixelSeed[15];
float PFiso_Photon03[15];
float PFiso_Neutral03[15];
float Photon_pt[15];

void usage(void);
void skim_tree(vector<string> _flist, string userPhotonID, Long64_t userPhoton_n, Long64_t nLoose);
bool passLoosePFPhoID(int i);
bool passMediumPFPhoID(int i);
bool passPFTightPhoID(int i);
double EAElectroncharged(double eta, string dataType);
double EAElectronneutral(double eta, string dataType);
double EAElectronphoton(double eta, string dataType);

int main(int argc, char * argv[]){
  //Declare needed variables
  string arg;
  char *photonID;
  Long64_t photon_n;
  Long64_t nloose;

  kutil::koptions options(argc, argv);

  if (options.find("--help")) { usage(); }
  int verbose       = options.find("--verbose");

  //Get the arguments from the command line
  //for customizing the skim
  photonID = argv[1];

  //Ensure proper arguments are inputted
  if(argc < 5) {usage();}
  if(strstr(photonID, "loose") == NULL) {
    if(strstr(photonID, "nocut") == NULL){usage();} 
  }

  photon_n = atoi(argv[2]);
  nloose = atoi(argv[3]);

  //Store all the file names from command line
  //into a string vector
  vector<string> _filelist;
  for(int i=4; i<argc; i++) { 
    if(strstr(argv[i],".root") != NULL) {
      _filelist.push_back(string(argv[i]));
    }
  }

  while(options.unrecognized_option(arg)) {
    printf("ERROR: unrecognized option %s\n", arg.c_str());
    usage();
  }

  string infilename;
  if (! options.shift_argument(infilename)){ usage(); }

  skim_tree(_filelist, photonID, photon_n, nloose);

  return 0;
}

//Print out usage for program
void usage() {
  cout << endl;
  cout << "USAGE: ./skim [PHOTONID] [PHOTON_N] [NLOOSE] [FILES]\n";
  cout << "--> PHOTONID can be either ""nocut"" or ""loose""\n";
  cout << "--> PHOTON_N can be an integer from 1->9\n";
  cout << "--> NLOOSE is the number of loose photons per event\n";
  cout << "--> FILES can be any amount of .root files you wish to skim\n";
  cout << endl;
  exit(0);
}

//Begin skimming the inputted .root file
void skim_tree(vector<string> _flist, string userPhotonID, Long64_t userPhoton_n, Long64_t nLoose) {
  
  //Get TChain
  TChain ch("myEvent");
  
  //Create TChain for all inputted files
  int fnum = _flist.size();
  for(int i=0; i<fnum; i++)
  {
    ch.Add(_flist[i].c_str());
  }
 
//   ch.Print();

  //Set chain branch addresses
  ch.SetBranchAddress("Photon_n", &Photon_n);
  ch.SetBranchAddress("Photon_sc_eta", &Photon_sc_eta);
  ch.SetBranchAddress("PFiso_Charged03", &PFiso_Charged03);
  ch.SetBranchAddress("rho", &rho);
  ch.SetBranchAddress("Photon_HoEnew", &Photon_HoEnew);
  ch.SetBranchAddress("Photon_SigmaIetaIeta", &Photon_SigmaIetaIeta);
  ch.SetBranchAddress("Photon_hasPixelSeed", &Photon_hasPixelSeed);
  ch.SetBranchAddress("PFiso_Photon03", &PFiso_Photon03);
  ch.SetBranchAddress("Photon_pt", &Photon_pt);
  ch.SetBranchAddress("PFiso_Neutral03", &PFiso_Neutral03);

  //Make new root file to store skimmed trees
  TFile file("skim.root", "RECREATE");
  //Clone the current chained tree
  TTree * sktree = ch.CloneTree(0);

  Long64_t jPhoton;
  Long64_t nLoosePerEvent;

  //Loop over chain
  for (int i=0; i<ch.GetEntries(); i++) {
    ch.GetEntry(i);
    
    //Skim according to user inputed photon number
    if (userPhoton_n <= Photon_n) {

      //Check for cut requirements
      if(strstr(userPhotonID.c_str(), "nocut") != NULL) {sktree->Fill();}
      if(strstr(userPhotonID.c_str(), "loose") != NULL) {
	nLoosePerEvent = 0;

        for(jPhoton = 0; jPhoton < Photon_n; jPhoton++) {
          //See if we found a loose photon
	  if(passLoosePFPhoID(jPhoton)) {
	    nLoosePerEvent++;
	  }
	}
	if(nLoosePerEvent >= nLoose)
	{
	  sktree->Fill();
	}
      }
    }
  }

 sktree->Write();
 file.Close();
}

//--------------------------------------------
//Determine if photon meets tight requirements
//--------------------------------------------
bool passPFTightPhoID(int i)
{
  string dataType = "mc";
  bool tightID=false;

  if(fabs(Photon_sc_eta[i]) < 1.4442 )
  {
    tightID = ((TMath::Max(((PFiso_Charged03[i])-rho*EAElectroncharged(Photon_sc_eta[i],dataType)),0.0) < 0.7)   &&
         (Photon_HoEnew[i] < 0.5)   &&
         (Photon_SigmaIetaIeta[i] < 0.011)   &&
         //(Photon_Electronveto[i] == 1)   &&
         (!Photon_hasPixelSeed[i])   &&  
         (TMath::Max(((PFiso_Photon03[i])-rho*EAElectronphoton(Photon_sc_eta[i],dataType)), 0.0) <0.5+0.005*Photon_pt[i])  &&
         (TMath::Max(((PFiso_Neutral03[i])-rho*EAElectronneutral(Photon_sc_eta[i],dataType)), 0.0) <0.4+0.04*Photon_pt[i])
         );
  }
  
  if(fabs(Photon_sc_eta[i]) > 1.4442 )
  {     
    tightID = ((TMath::Max(((PFiso_Charged03[i])-rho*EAElectroncharged(Photon_sc_eta[i],dataType)),0.0) < 0.5)   &&
         (Photon_HoEnew[i] < 0.05)   &&
         (Photon_SigmaIetaIeta[i] < 0.031)   &&
         //(Photon_Electronveto[i] == 1)   &&
         (!Photon_hasPixelSeed[i])   &&  
         (TMath::Max(((PFiso_Photon03[i])-rho*EAElectronphoton(Photon_sc_eta[i],dataType)), 0.0) <1.0+0.005*Photon_pt[i])  &&
         (TMath::Max(((PFiso_Neutral03[i])-rho*EAElectronneutral(Photon_sc_eta[i],dataType)), 0.0) <1.5+0.04*Photon_pt[i])
         );
  }

  return tightID;
}

//---------------------------------------------
//Determine if photon meets medium requirements
//---------------------------------------------
bool passMediumPFPhoID(int i)
{           
  bool mediumID=false;
  string dataType = "mc";
                     
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

//--------------------------------------------
//Determine if photon meets loose requirements
//--------------------------------------------
bool passLoosePFPhoID(int i)
{
  bool looseID=false;
  string dataType = "mc";
  
  if(fabs(Photon_sc_eta[i]) < 1.4442 )
  {
    looseID = ((TMath::Max(((PFiso_Charged03[i])-rho*EAElectroncharged(Photon_sc_eta[i],dataType)),0.0) < 2.6)   &&
         (Photon_HoEnew[i] < 0.05)   &&
         (Photon_SigmaIetaIeta[i] < 0.012)   &&
         //(Photon_Electronveto[i] == 1)   &&
         (!Photon_hasPixelSeed[i])   &&  
         (TMath::Max(((PFiso_Photon03[i])-rho*EAElectronphoton(Photon_sc_eta[i],dataType)), 0.0) <1.3+0.005*Photon_pt[i])  &&
         (TMath::Max(((PFiso_Neutral03[i])-rho*EAElectronneutral(Photon_sc_eta[i],dataType)), 0.0) <3.5+0.04*Photon_pt[i])
         );
  }
  
  if(fabs(Photon_sc_eta[i]) > 1.4442 )
  {     
    looseID = ((TMath::Max(((PFiso_Charged03[i])-rho*EAElectroncharged(Photon_sc_eta[i],dataType)),0.0) < 2.3)   &&
         (Photon_HoEnew[i] < 0.05)   &&
         (Photon_SigmaIetaIeta[i] < 0.034)   &&
         //(Photon_Electronveto[i] == 1)   &&
         (!Photon_hasPixelSeed[i])   &&  
         (TMath::Max(((PFiso_Neutral03[i])-rho*EAElectronneutral(Photon_sc_eta[i],dataType)), 0.0) <2.9+0.04*Photon_pt[i])
         );
  }

  return looseID;
}

//---------------------------------------------------
//Effective area for electron and photon based on eta
//---------------------------------------------------
double EAElectroncharged(double eta, string dataType)
{
   float EffectiveArea = 0;

  if(dataType =="data")
  {
    if(fabs(eta) >= 0.0 && fabs(eta) < 1.0) EffectiveArea = 0.002;
    if(fabs(eta) >= 1.0 && fabs(eta) < 1.442) EffectiveArea = 0.003;
  }

  if(dataType == "mc")
  {
    if(fabs(eta) < 1.0) EffectiveArea = 0.012;
    if(fabs(eta) >= 1.0 && fabs(eta) < 1.479) EffectiveArea = 0.010;
    if(fabs(eta) >= 1.479 && fabs(eta) < 2.0) EffectiveArea = 0.0142;
    if(fabs(eta) >= 2.0 && fabs(eta) < 2.2) EffectiveArea = 0.012;
    if(fabs(eta) >= 2.2 && fabs(eta) < 2.3) EffectiveArea = 0.016;
    if(fabs(eta) >= 2.3 && fabs(eta) < 2.4) EffectiveArea = 0.020;
    if(fabs(eta) >= 2.4) EffectiveArea = 0.012;
  }

  return EffectiveArea;
}

double EAElectronneutral(double eta, string dataType)
{
  float EffectiveArea=0;

  if(dataType =="data")
  {
    if(fabs(eta) >= 0.0 && fabs(eta) < 1.0) EffectiveArea = 0.024;
    if(fabs(eta) >= 1.0 && fabs(eta) < 1.479) EffectiveArea = 0.037;
  }

  if(dataType == "mc")
  {
    if(fabs(eta) < 1.0) EffectiveArea = 0.030;
    if(fabs(eta) >= 1.0 && fabs(eta) < 1.479) EffectiveArea = 0.057;
    if(fabs(eta) >= 1.479 && fabs(eta) < 2.0) EffectiveArea = 0.039;
    if(fabs(eta) >= 2.0 && fabs(eta) < 2.2) EffectiveArea = 0.015;
    if(fabs(eta) >= 2.2 && fabs(eta) < 2.3) EffectiveArea = 0.024;
    if(fabs(eta) >= 2.3 && fabs(eta) < 2.4) EffectiveArea = 0.039;
    if(fabs(eta) >= 2.4) EffectiveArea = 0.072;
  }
 
  return EffectiveArea;
}

double EAElectronphoton(double eta, string dataType)
{
  float EffectiveArea=0;
  
  if(dataType =="data")
  {
    if(fabs(eta) >= 0.0 && fabs(eta) < 1.0) EffectiveArea = 0.081;
    if(fabs(eta) >= 1.0 && fabs(eta) < 1.442) EffectiveArea = 0.084;
  }

  if(dataType == "mc")
  {
    if(fabs(eta) < 1.0) EffectiveArea = 0.148;
    if(fabs(eta) >= 1.0 && fabs(eta) < 1.479) EffectiveArea = 0.130;
    if(fabs(eta) >= 1.479 && fabs(eta) < 2.0) EffectiveArea = 0.112;
    if(fabs(eta) >= 2.0 && fabs(eta) < 2.2) EffectiveArea = 0.216;
    if(fabs(eta) >= 2.2 && fabs(eta) < 2.3) EffectiveArea = 0.262;
    if(fabs(eta) >= 2.3 && fabs(eta) < 2.4) EffectiveArea = 0.260;
    if(fabs(eta) >= 2.4) EffectiveArea = 0.266;
  }

  return EffectiveArea;
}
