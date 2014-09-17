/*
  This utility looks at root files generated from the decay of Higgs -> gamma, gamma interactions.
  We generate various histograms to be used for data analysis as well as used to confirm
  theoretical estimates for the expected photon count.
  Tight  - strict quotas the jet needs to meet to be considered a photon
  Medium - less strict quotas
  Loose  - even lesser strict quotas

  Author: Brandon Buonacorsi <bbuonacorsi@ucdavis.edu>
*/

#define myClass_cxx
#include "myEvent.h"
#include <TH2.h>
#include <TH1F.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <cmath>
#include <TF1.h>
#include <TApplication.h>
#include <TRint.h>
#include <TRandom.h>
#include <TRandom3.h>
using namespace std;

//Create histograms
TH1F *hNoCutPt = new TH1F("PtNoCut", "Pt Distribution: Photon No Cut", 100, 0, 500);
TH1F *hTightPt = new TH1F("PtTight", "Pt Distribution: Photon Tight", 100, 0, 500);
TH1F *hMediumPt = new TH1F("PtMedium", "Pt Distribution: Photon Medium", 100, 0, 500);
TH1F *hLoosePt = new TH1F("PtLoose", "Pt Distribution: Photon Loose", 100, 0, 500);
TH1F *hNoCutEta = new TH1F("EtaNoCut", "Eta Distribution: Photon No Cut", 100, -3.5, 3.5);
TH1F *hTightEta = new TH1F("EtaTight", "Eta Distribution: Photon Tight", 100, -3.5, 3.5);
TH1F *hMediumEta = new TH1F("EtaMedium", "Eta Distribution: Photon Medium", 100, -3.5, 3.5);
TH1F *hLooseEta = new TH1F("EtaLoose", "Eta Distribution: Photon Loose", 100, -3.5, 3.5);
TH1F *hNoCutPhi = new TH1F("PhiNoCut", "Phi Distribution: Photon No Cut", 100, 0, 7);
TH1F *hTightPhi = new TH1F("PhiTight", "Phi Distribution: Photon Tight", 100, 0, 7);
TH1F *hMediumPhi = new TH1F("PhiMedium", "Phi Distribution: Photon Medium", 100, 0, 7);
TH1F *hLoosePhi = new TH1F("PhiLoose", "Phi Distribution: Photon Loose", 100, 0, 7);
TH1F *hPFJetPt = new TH1F("PFJetPt", "Pt Distribution: Jet No Cut", 100, 0, 500);
TH1F *hPFJetEta = new TH1F("PFJetEta", "Eta Distribution: Jet No Cut", 100, -3.5, 3.5);
TH1F *hPFJetPhi = new TH1F("PFJetPhi", "Phi Distribution: Jet No Cut", 100, 0, 7);
TH1F *hFakeRateTight = new TH1F("", "", 100, 0, 500);
TH1F *hFakeRateMedium = new TH1F("", "", 100, 0, 500);
TH1F *hFakeRateLoose = new TH1F("", "", 100, 0, 500);
TH1F *hNoCutDeltaR = new TH1F("NoCutDeltaR", "DeltaR Distribution: No Cut", 100, 0, 7);
TH1F *hLooseDeltaR = new TH1F("LooseDeltaR", "DeltaR Distribution: Loose", 100, 0, 7);
TH1F *hTightDeltaR = new TH1F("TightDeltaR", "DeltaR Distribution: Tight", 100, 0, 7);
TH1F *hNoCutProbePt = new TH1F("NoCutProbePt", "Pt Distribution: Jets Faking No Cut", 100, 0, 500);
TH1F *hTightProbePt = new TH1F("TightProbePt", "Pt Distribution: Jets Faking Tight", 100, 0, 500);
TH1F *hMediumProbePt = new TH1F("MediumProbePt", "Pt Distribution: Jets Faking Medium", 100, 0, 500);
TH1F *hLooseProbePt = new TH1F("LooseProbePt", "Pt Distribution: Jets Faking Loose", 100, 0, 500);
TH1F *hNTightReal = new TH1F("NumTightReal", "Actual Observed Number of Tight Photons", 10, 0, 10);
TH1F *hNMediumReal = new TH1F("NumMediumReal", "Actual Observed Number of Medium Photons", 10, 0, 10);
TH1F *hNLooseReal = new TH1F("NumLooseReal", "Actual Observed Number of Loose Photons", 10, 0, 10);
TH1F *hNTightTheor = new TH1F("NumTightTheor", "Theoretical Number of Tight Photons", 10, 0, 10);
TH1F *hNMediumTheor = new TH1F("NumMediumTheor", "Theoretical Number of Medium Photons", 10, 0, 10);
TH1F *hNLooseTheor = new TH1F("NumLooseTheor", "Theoretical Number of Loose Photons", 10, 0, 10);

//Declaration of functions
int usage();
void printResults(Long64_t nEntries, Long64_t nTightPho, 
  Long64_t nMediumPho, Long64_t nLoosePho, Long64_t nNoCutPho, 
  Long64_t nLooseEvents, Long64_t nEventsOneL, Long64_t nEventsTwoL, 
  Long64_t nEventsGTTwoL, float lowestLoosePt, float lowestTightPt);
void saveHistograms(void);
void makeFakeRates(void);

int main(int argc, char *argv[]) { 
  Long64_t nEntries=0;
  Long64_t nTightPho=0;
  Long64_t nMediumPho=0;
  Long64_t nLoosePho=0;
  Long64_t nNoCutPho=0;
  Long64_t nLooseEvents=0;
  Long64_t nEventsOneL=0;
  Long64_t nEventsTwoL=0;
  Long64_t nEventsGTTwoL=0;
  float lowestTightPt = 1000;
  float lowestLoosePt = 1000;
  
  if(argc == 1 || (strstr(argv[1], "help")!=NULL)) {
    usage();
    return 0;
  }
  else {
    for(int i = 1; i < argc; i++) {
      //Add inputted files from argument line to be processed
      if(strstr(argv[i], ".root") != NULL) {
        _rootfile.push_back(argv[i]);
      }
    }
  }

  //Construct a new class from file list
  myClass *m_1 = new myClass;

  //Generate needed histrograms of newly constructed class
  m_1->histoLoop(&nEntries, &nTightPho, &nMediumPho, &nLoosePho,
    &nNoCutPho, &nLooseEvents, &nEventsOneL, &nEventsTwoL, 
    &nEventsGTTwoL, &lowestLoosePt, &lowestTightPt);
  m_1->histoDeltaR();
 
  //Generate probe jet histograms
  m_1->probeLoop();
  
  //Generates fake rates of different cut photons
  makeFakeRates();

  //Makes theoretical and actual counts of expected numbers of photons
  m_1->nLoop();
  delete m_1;

  saveHistograms();
  printResults(nEntries, nTightPho, nMediumPho, nLoosePho, 
    nNoCutPho, nLooseEvents, nEventsOneL, nEventsTwoL, 
    nEventsGTTwoL, lowestLoosePt, lowestTightPt);

  return 0;
}

//---------------------------------
//Displays the usage of the program
//---------------------------------
int usage(void) {
  cout << endl;
  cout << "USAGE: ./analyze [FILES]" << endl;
  cout << "--> FILES is any amount of .root files you wish to analyze" << endl;
  cout << "--> Program generates histo.root files containing histograms" << endl;
  cout << "     of various photon data" << endl;
  cout << endl;

  return 0;
}

//------------------------------------------
//Generates the fake rates used for analysis
//------------------------------------------
void makeFakeRates(void) { 
  TFile *f1 = new TFile("histograms.root", "RECREATE");
  //Get the jet fake rate histogram
  hFakeRateLoose = (TH1F*)hLooseProbePt->Clone();
  hFakeRateLoose->SetName("FakeRateLoose");
  hFakeRateLoose->SetTitle("Loose Photon Jet Fake Rate"); 
  hFakeRateLoose->Divide(hPFJetPt);
  hFakeRateMedium = (TH1F*)hMediumProbePt->Clone();
  hFakeRateMedium->SetName("FakeRateMedium");
  hFakeRateMedium->SetTitle("Medium Photon Jet Fake Rate");
  hFakeRateMedium->Divide(hPFJetPt);
  hFakeRateTight = (TH1F*)hTightProbePt->Clone();
  hFakeRateTight->SetName("FakeRateTight");
  hFakeRateTight->SetTitle("Tight Photon Jet Fake Rate");
  hFakeRateTight->Divide(hPFJetPt);
}

//----------------------------------------------------
//Generates theoretical and actual n counts of photons
//----------------------------------------------------
void myClass::nLoop() {
  TRandom3 r;
  float rndmNum;
  float k;
  bool alrInc;
  int nTightPerEvent, nMediumPerEvent, nLoosePerEvent;

  if(fChain == 0) return;

  //Simply loop through the TTree
  Long64_t nentrs = fChain->GetEntriesFast();
  Long64_t nbytes = 0, nb = 0;
  for(Long64_t jentry=0; jentry < nentrs; jentry++) {
    nTightPerEvent = 0;
    nMediumPerEvent = 0;
    nLoosePerEvent = 0;
    Long64_t ientry = LoadTree(jentry);
    if(ientry < 0) break;
    nb = fChain->GetEntry(jentry); nbytes += nb;
    //Loop through number of photons in event
    for(Long64_t jPhoton = 0; jPhoton < Photon_n; jPhoton++) { 
      //This variable is used to not double count
      alrInc = false;
      //Check for tight photon requirements
      if(passPFTightPhoID(jPhoton) && alrInc == false) {
        nTightPerEvent++;
	nMediumPerEvent++;
	nLoosePerEvent++;
	alrInc = true;
      }
      //Check for medium photon requirements
      if(passMediumPFPhoID(jPhoton) && alrInc == false) {
        nMediumPerEvent++;
	nLoosePerEvent++;
	alrInc = true;
      }
      //Check for loose photon requirements
      if(passLoosePFPhoID(jPhoton) && alrInc == false) {
        nLoosePerEvent++;
	alrInc = true;
      }
    }
    //Fill histograms with the number of found photons per event
    hNTightReal->Fill(nTightPerEvent);
    hNMediumReal->Fill(nMediumPerEvent);
    hNLooseReal->Fill(nLoosePerEvent);
    nTightPerEvent = 0;
    nMediumPerEvent = 0;
    //During our skim, we only picked events that have at least 1 loose photon
    //Therefore, we must force our theoretical to always include at least one 
    //loose photon
    nLoosePerEvent = 1;
    //Loop through jets
    for(Long64_t jpfJet = 0; jpfJet < pfJet_n; jpfJet++) { 
      alrInc = false;
      //Use random number generator to find theoretical expected number
      //i.e. Monte Carlo simulation
      rndmNum = r.Rndm();
      //Find the fake rate (i.e. how many photons do we see that are 
      //actually just jets faking as a photon)
      //Simulate if a fake tight photon
      k = hFakeRateTight->GetXaxis()->FindBin(pfJet_pt[jpfJet]);
      if(rndmNum <= hFakeRateTight->GetBinContent(k) && alrInc == false) {
        nTightPerEvent++;
	nMediumPerEvent++;
	nLoosePerEvent++;
	alrInc = true;
      }
      //Simulate if a fake medium photon
      k = hFakeRateMedium->GetXaxis()->FindBin(pfJet_pt[jpfJet]);
      if(rndmNum <= hFakeRateMedium->GetBinContent(k) && alrInc == false) {
        nMediumPerEvent++;
	nLoosePerEvent++;
	alrInc = true;
      }
      //Simulate if a fake loose photon
      k = hFakeRateLoose->GetXaxis()->FindBin(pfJet_pt[jpfJet]);
      if(rndmNum <= hFakeRateLoose->GetBinContent(k) && alrInc == false) {
        nLoosePerEvent++;
	alrInc = true;
      }
    }
    //Fill corresponding hists
    hNTightTheor->Fill(nTightPerEvent);
    hNMediumTheor->Fill(nMediumPerEvent);
    hNLooseTheor->Fill(nLoosePerEvent);
    if (Cut(ientry) < 0) continue;
  }
}

//---------------------------
//Generate probe jet pt plots
//---------------------------
void myClass::probeLoop() { 
  bool alrInc = false;
  float deltaR;
  TRandom3 r;
  int rndm;

  if(fChain == 0) return;

  Long64_t nentrs = fChain->GetEntriesFast();
  Long64_t nbytes = 0, nb = 0;
  //Loop through events
  for(Long64_t jentry=0; jentry < nentrs; jentry++)
  {
    Long64_t ientry = LoadTree(jentry);
    if(ientry < 0) break;
    nb = fChain->GetEntry(jentry); nbytes += nb;
    //Get random tag photon
    rndm = int(r.Rndm()*Photon_n);

    //Compare deltaR for every jet with TAG photon (Photon[rndm])
    for(Long64_t jPFJet = 0; jPFJet < pfJet_n; jPFJet++) {
      deltaR = calculateDeltaR(rndm, jPFJet);
      //If deltaR is within 0.5 skip the jet
      //Otherwise it is a probe jet
      if(deltaR >= 0.5) {
        for(Long64_t i = 0; i < Photon_n; i++) {  
	  //Skip over tag photon
	  if(i == rndm) {continue;}
	  //Otherwise, carry on
	  alrInc = false;
	  deltaR = calculateDeltaR(i, jPFJet);
	  if(deltaR < 0.5) {
	    //Check photon requirements were met
	    if(passPFTightPhoID(i) && alrInc == false) { 
	      hTightProbePt->Fill(pfJet_pt[jPFJet]);
	      hMediumProbePt->Fill(pfJet_pt[jPFJet]);
	      hLooseProbePt->Fill(pfJet_pt[jPFJet]);
	      alrInc = true;
	    }
	    if(passMediumPFPhoID(i) && alrInc == false) {
	      hMediumProbePt->Fill(pfJet_pt[jPFJet]);
	      hLooseProbePt->Fill(pfJet_pt[jPFJet]);
	      alrInc = true;
	    }
	    if(passLoosePFPhoID(i) && alrInc == false) {
	      hLooseProbePt->Fill(pfJet_pt[jPFJet]); 
	      alrInc = true;
	    }
	    hNoCutProbePt->Fill(pfJet_pt[jPFJet]);
	  }
	}
      }
    }
    if (Cut(ientry) < 0) continue;
  }
}

//-------------------------------------
//Generate a histogram of DeltaR values
//-------------------------------------
void myClass::histoDeltaR() {
  float deltaR = 0;
  bool alrFilled = false;

  if(fChain == 0) return;

  Long64_t nentrs = fChain->GetEntriesFast();
  Long64_t nbytes = 0, nb = 0;
  //Loop through events
  for(Long64_t jentry=0; jentry < nentrs; jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if(ientry < 0) break;
    nb = fChain->GetEntry(jentry); nbytes += nb;
    //Loop through each photon and jet and calc DeltaR
    for(Long64_t jPhoton = 0; jPhoton < Photon_n; jPhoton++) {
      for(Long64_t jJet = 0; jJet < pfJet_n; jJet++) {
        deltaR = calculateDeltaR(jPhoton, jJet);
        //Find DeltaR for every photon/jet combination
	hNoCutDeltaR->Fill(deltaR);
	//Find DeltaR for every loose photon/jet combination
        if(passLoosePFPhoID(jPhoton)) { 
          hLooseDeltaR->Fill(deltaR);
        }
	//Find DeltaR for every tight photon/jet combination
	if(passPFTightPhoID(jPhoton)) {
	  hTightDeltaR->Fill(deltaR);
	}
      }
    }
    if (Cut(ientry) < 0) continue;
  }
}

//---------------------------------------
//Generates a bunch of various histograms
//---------------------------------------
void myClass::histoLoop(Long64_t *nEntries, 
     Long64_t *nTightPho, Long64_t *nMediumPho, 
     Long64_t *nLoosePho, Long64_t *nNoCutPho, 
     Long64_t *nLooseEvents, Long64_t *nEventsOneL, 
     Long64_t *nEventsTwoL, Long64_t *nEventsGTTwoL, 
     float *lowestLoosePt, float *lowestTightPt) 
{
   bool alrInc = false;
   bool alrIncLoose = false;
   int nLoosePerEvent;
   
   if(fChain == 0) return;

   Long64_t nentrs = fChain->GetEntriesFast();
   *nEntries = *nEntries + nentrs;
   Long64_t nbytes = 0, nb = 0;
   //Loop through events
   for(Long64_t jentry=0; jentry < nentrs; jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if(ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      nLoosePerEvent = 0;
      //Loop through all of the photons in the event
      for(Long64_t photonNum=0; photonNum<Photon_n; photonNum++) { 
        alrInc = false;
        //Check to see if tight photon
        if(passPFTightPhoID(photonNum) && alrInc == false) {
	  //Increment photon counts
	  (*nTightPho)++;
	  (*nMediumPho)++;
	  (*nLoosePho)++;
	  //Fill histograms
	  fillTightHisto(photonNum, lowestTightPt);
	  fillMediumHisto(photonNum);
	  fillLooseHisto(photonNum, lowestLoosePt);
          nLoosePerEvent++;
	  alrInc = true;
	}
	//Check if medium
	if(passMediumPFPhoID(photonNum) && alrInc == false) {
	  (*nMediumPho)++;
	  (*nLoosePho)++;
	  //Fill histograms
	  fillMediumHisto(photonNum);
	  fillLooseHisto(photonNum, lowestLoosePt);
          nLoosePerEvent++;
	  alrInc = true;
	}
        //Check if loose
        if(passLoosePFPhoID(photonNum) && alrInc == false) {
	  (*nLoosePho)++;
          nLoosePerEvent++;
	  //Fill histograms
	  fillLooseHisto(photonNum, lowestLoosePt);
	  alrInc = true;
        }
	//Fill histograms
	fillNoCutHisto(photonNum);
        (*nNoCutPho)++;
      }
      if(nLoosePerEvent >  0) {(*nLooseEvents)++;}
      if(nLoosePerEvent == 1) {(*nEventsOneL)++;}
      if(nLoosePerEvent == 2) {(*nEventsTwoL)++;}
      if(nLoosePerEvent >  2) {(*nEventsGTTwoL)++;}
      //Loop through all the jets
      for(Long64_t jetNum=0; jetNum<pfJet_n; jetNum++) {
        fillPFJetHisto(jetNum);
      }
   }
}

//-------------------------------------------
//Print out various data points after looping
//-------------------------------------------
void printResults(Long64_t nEntries, Long64_t nTightPho, 
  Long64_t nMediumPho, Long64_t nLoosePho, Long64_t nNoCutPho, 
  Long64_t nLooseEvents, Long64_t nEventsOneL, Long64_t nEventsTwoL,  Long64_t nEventsGTTwoL, float lowestLoosePt, float lowestTightPt)
{
   cout << endl;
   cout << "Number of photons (No Cut): " << nNoCutPho << endl;
   cout << "-> Tight photons: " << nTightPho << endl;
   cout << "-> Medium photons: " << nMediumPho << endl;
   cout << "-> Loose photons: " << nLoosePho << endl;
   cout << endl;
   cout << "Tight efficiency: " << double(nTightPho)/double(nNoCutPho)*100 << "%" << endl;
   cout << "Medium efficiency: " << double(nMediumPho)/double(nNoCutPho)*100 << "%" << endl;
   cout << "Loose efficiency: " << double(nLoosePho)/double(nNoCutPho)*100 << "%" << endl;
   cout << "-> Tight to loose efficiency: " << double(nTightPho)/double(nLoosePho)*100 << "%" << endl;
   cout << "-> Medium to loose efficiency: " << double(nMediumPho)/double(nLoosePho)*100 << "%" << endl;
   cout << "-> Tight to Medium efficiency: " << double(nTightPho)/double(nMediumPho)*100 << "%" << endl;
   cout << endl;
   cout << "Number of events: " << nEntries << endl;
   cout << "Number of events with loose photons: " << nLooseEvents << endl;
   cout << "Ratio of loose events to events: " << double(nLooseEvents)/double(nEntries) << endl;
   cout << endl;
   cout << "Lowest Pt for Loose Photons: " << lowestLoosePt << endl;
   cout << "Lowest Pt for Tight Photon: " << lowestTightPt << endl;
   cout << endl;

   //Draw some histograms too..
   int fargc = 0;
   char* fargv[1];
   fargv[0] = NULL;
   TApplication *theApp = new TRint("App", &fargc, fargv);

   TCanvas *c1 = new TCanvas("FakeRates", "Fake Rate Plots", 10, 10, 1200, 750);
   c1->Divide(2,1);
   c1->cd(1);
   hFakeRateLoose->Draw();
   c1->cd(2);
   hFakeRateTight->Draw();
   c1->Update();

   theApp->Run();

}

//-------------------
//Save all histograms
//-------------------
void saveHistograms(void)
{
   //Make the file to save the histograms
   TFile *f = new TFile("histograms.root", "RECREATE");

   //Save all of the histograms to the histo.root file
   hNoCutPt->Write();
   hTightPt->Write();
   hMediumPt->Write();
   hLoosePt->Write();
   hNoCutEta->Write();
   hTightEta->Write();
   hMediumEta->Write();
   hLooseEta->Write();
   hNoCutPhi->Write();
   hTightPhi->Write();
   hMediumPhi->Write();
   hLoosePhi->Write();
   hFakeRateTight->Write();
   hFakeRateMedium->Write();
   hFakeRateLoose->Write();
   hPFJetPt->Write();
   hPFJetEta->Write();
   hPFJetPhi->Write();
   hNoCutDeltaR->Write();
   hLooseDeltaR->Write();
   hTightDeltaR->Write();
   hNoCutProbePt->Write();
   hTightProbePt->Write();
   hMediumProbePt->Write();
   hLooseProbePt->Write();
   hNTightTheor->Write();
   hNMediumTheor->Write();
   hNLooseTheor->Write();
   hNTightReal->Write();
   hNMediumReal->Write();
   hNLooseReal->Write();
}

//-----------------------------------
//Fill No Cut Pt, Eta, Phi Histograms
//-----------------------------------
void myClass::fillPFJetHisto(int i)
{
  hPFJetPt->Fill(pfJet_pt[i]); 
  hPFJetEta->Fill(pfJet_eta[i]); 
  hPFJetPhi->Fill(pfJet_phi[i]);
}

//-----------------------------------
//Fill No Cut Pt, Eta, Phi Histograms
//-----------------------------------
void myClass::fillNoCutHisto(int i)
{
  hNoCutPt->Fill(Photon_pt[i]); 
  hNoCutEta->Fill(Photon_eta[i]); 
  hNoCutPhi->Fill(Photon_phi[i]);
}

//----------------------------------
//Fill Loose Pt, Eta, Phi Histograms
//----------------------------------
void myClass::fillLooseHisto(int i, float *lowestLoosePt)
{
  hLoosePt->Fill(Photon_pt[i]);  
  hLooseEta->Fill(Photon_eta[i]);  
  hLoosePhi->Fill(Photon_phi[i]);  
  
  if(Photon_pt[i] < (*lowestLoosePt))
  {
    *lowestLoosePt = Photon_pt[i];
  }
}

//-----------------------------------
//Fill Medium Pt, Eta, Phi Histograms
//-----------------------------------
void myClass::fillMediumHisto(int i)
{
  hMediumPt->Fill(Photon_pt[i]);  
  hMediumEta->Fill(Photon_eta[i]);  
  hMediumPhi->Fill(Photon_phi[i]);  
}

//----------------------------------
//Fill Tight Pt, Eta, Phi Histograms
//----------------------------------
void myClass::fillTightHisto(int i, float *lowestTightPt)
{
  hTightPt->Fill(Photon_pt[i]);  
  hTightEta->Fill(Photon_eta[i]);  
  hTightPhi->Fill(Photon_phi[i]);  
  
  if(Photon_pt[i] < (*lowestTightPt))
  {
    *lowestTightPt = Photon_pt[i];
  }
}

//----------------
//Calculate deltaR
//----------------
float myClass::calculateDeltaR(int i, int j)
{
  float deltaR, deltaEtaSqr, deltaPhiSqr;

  deltaEtaSqr = (Photon_eta[i]-pfJet_eta[j])*(Photon_eta[i]-pfJet_eta[j]);
  deltaPhiSqr = (Photon_phi[i]-pfJet_phi[j])*(Photon_phi[i]-pfJet_phi[j]);
  deltaR = sqrt(deltaEtaSqr + deltaPhiSqr);

  return deltaR;
}

//----------------------------
//Determine if photon is tight
//----------------------------
bool myClass::passPFTightPhoID(int i)
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

//----------------------------
//Determine if photon is loose
//----------------------------
bool myClass::passLoosePFPhoID(int i)
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

//-----------------------------
//Determine if photon is medium
//-----------------------------
bool myClass::passMediumPFPhoID(int i)                                                                                        
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


//---------------------------------------------------
//Effective area for electron and photon based on eta
//---------------------------------------------------
double myClass::EAElectroncharged(double eta, string dataType)
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

double myClass::EAElectronneutral(double eta, string dataType)
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

double myClass::EAElectronphoton(double eta, string dataType)
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
