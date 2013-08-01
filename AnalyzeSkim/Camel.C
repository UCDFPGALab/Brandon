#define myClass_cxx
#include "Camel.h"
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

//Used for Loop and Print
Long64_t nEntries;
Long64_t nTightPho;
Long64_t nMediumPho;
Long64_t nLoosePho;
Long64_t nNoCutPho;
Long64_t nLooseEvents;
Long64_t nLoosePerEvent;
Long64_t nMediumPerEvent;
Long64_t nTightPerEvent;
Long64_t nEventsTwoL;
Long64_t nEventsOneL;
Long64_t nEventsGTTwoL;
float lowestTightPt = 1000;
float lowestLoosePt = 1000;

//Create histograms
TH1F *hNoCutPt = new TH1F("PtNoCut", "Pt Distribution: No Cut", 100, 0, 500);
TH1F *hTightPt = new TH1F("PtTight", "Pt Distribution: Tight", 100, 0, 500);
TH1F *hMediumPt = new TH1F("PtMedium", "Pt Distribution: Medium", 100, 0, 500);
TH1F *hLoosePt = new TH1F("PtLoose", "Pt Distribution: Loose", 100, 0, 500);
TH1F *hNoCutEta = new TH1F("EtaNoCut", "Eta Distribution: No Cut", 100, -3.5, 3.5);
TH1F *hTightEta = new TH1F("EtaTight", "Eta Distribution: Tight", 100, -3.5, 3.5);
TH1F *hMediumEta = new TH1F("EtaMedium", "Eta Distribution: Medium", 100, -3.5, 3.5);
TH1F *hLooseEta = new TH1F("EtaLoose", "Eta Distribution: Loose", 100, -3.5, 3.5);
TH1F *hNoCutPhi = new TH1F("PhiNoCut", "Phi Distribution: No Cut", 100, 0, 7);
TH1F *hTightPhi = new TH1F("PhiTight", "Phi Distribution: Tight", 100, 0, 7);
TH1F *hMediumPhi = new TH1F("PhiMedium", "Phi Distribution: Medium", 100, 0, 7);
TH1F *hLoosePhi = new TH1F("PhiLoose", "Phi Distribution: Loose", 100, 0, 7);
TH1F *hPFJetPt = new TH1F("PFJetPt", "Pt Distribution: Jet", 100, 0, 500);
TH1F *hPFJetEta = new TH1F("PFJetEta", "Eta Distribution: Jet", 100, -3.5, 3.5);
TH1F *hPFJetPhi = new TH1F("PFJetPhi", "Phi Distribution: Jet", 100, 0, 7);
TH1F *hFakeRateTight = new TH1F("", "", 100, 0, 500);
TH1F *hFakeRateMedium = new TH1F("", "", 100, 0, 500);
TH1F *hFakeRateLoose = new TH1F("", "", 100, 0, 500);
TH1F *hNoCutDeltaR = new TH1F("NoCutDeltaR", "DeltaR Distribution: No Cut", 100, 0, 7);
TH1F *hLooseDeltaR = new TH1F("LooseDeltaR", "DeltaR Distribution: Loose", 100, 0, 7);
TH1F *hTightDeltaR = new TH1F("TightDeltaR", "DeltaR Distribution: Tight", 100, 0, 7);
TH1F *hNoCutProbePt = new TH1F("NoCutProbePt", "Pt Distribution: No Cut Probe Jets", 100, 0, 500);
TH1F *hTightProbePt = new TH1F("TightProbePt", "Pt Distribution: Tight Probe Jets", 100, 0, 500);
TH1F *hMediumProbePt = new TH1F("MediumProbePt", "Pt Distribution: Medium Probe Jets", 100, 0, 500);
TH1F *hLooseProbePt = new TH1F("LooseProbePt", "Pt Distribution: Loose Probe Jets", 100, 0, 500);
TH1F *hNTightTheor = new TH1F("nTightTheor", "Theoretical Number of Faked Tight Jets Per Event", 10, 0, 10);
TH1F *hNMediumTheor = new TH1F("nMediumTheor", "Theoretical Number of Faked Medium Jets Per Event", 10, 0, 10);
TH1F *hNLooseTheor = new TH1F("nLooseTheor", "Theoretical Number of Faked Loose Jets Per Event", 10, 0, 10);
TH1F *hNTightReal = new TH1F("nTightReal", "Actual Number of Faked Tight Jets Per Event", 10, 0, 10);
TH1F *hNMediumReal = new TH1F("nMediumReal", "Actual Number of Faked Medium Jets Per Event", 10, 0, 10);
TH1F *hNLooseReal = new TH1F("nLooseReal", "Actual Number of Faked Loose Jets Per Event", 10, 0, 10);

//Declaration of functions
int Usage();
void PrintResults(void);
void SaveHistograms(void);
void makeFakeRates(void);

int main(int argc, char *argv[])
{ 
  if(argc == 1 || (strstr(argv[1], "help")!=NULL))
  {
    Usage();
    return 0;
  }
  else
  {
    for(int i = 1; i < argc; i++)
    {
      if(strstr(argv[i], ".root") != NULL)
      {
        _rootfile.push_back(argv[i]);
      }
    }
  }

  myClass *m_1 = new myClass;
  m_1->histoLoop();
  m_1->histoDeltaR();
  m_1->probeLoop1();
//  m_1->probeLoop2();
  makeFakeRates();
//  m_1->nLoop();
  delete m_1;

  SaveHistograms();
  PrintResults();

  return 0;
}

int Usage(void)
{
  cout << endl;
  cout << "USAGE: ./analyze [FILES]" << endl;
  cout << "--> FILES is any amount of .root files you wish to analyze" << endl;
  cout << "--> Program generates histo.root files containing histograms" << endl;
  cout << "     of various photon data" << endl;
  cout << endl;

  return 0;
}

void makeFakeRates(void)
{ 
  //Method 1 uses probe pt's to find the fakerate

  TFile *f1 = new TFile("histograms.root", "RECREATE");
  //Get the jet fake rate histogram
  hFakeRateLoose = (TH1F*)hLooseProbePt->Clone();
  hFakeRateLoose->SetName("FakeRateLoose");
  hFakeRateLoose->SetTitle("Loose Photon Jet Fake Rate"); 
  hFakeRateLoose->Divide(hNoCutProbePt);
  hFakeRateMedium = (TH1F*)hMediumProbePt->Clone();
  hFakeRateMedium->SetName("FakeRateMedium");
  hFakeRateMedium->SetTitle("Medium Photon Jet Fake Rate");
  hFakeRateMedium->Divide(hNoCutProbePt);
  hFakeRateTight = (TH1F*)hTightProbePt->Clone();
  hFakeRateTight->SetName("FakeRateTight");
  hFakeRateTight->SetTitle("Tight Photon Jet Fake Rate");
  hFakeRateTight->Divide(hNoCutProbePt);
}

void myClass::nLoop()
{
  TRandom3 r;
  float rndmNum;
  float k;
  bool alrInc;

  if(fChain == 0) return;

  Long64_t nentrs = fChain->GetEntriesFast();
  Long64_t nbytes = 0, nb = 0;
  for(Long64_t jentry=0; jentry < nentrs; jentry++)
  {
    nTightPerEvent = 0;
    nMediumPerEvent = 0;
    nLoosePerEvent = 0;
    Long64_t ientry = LoadTree(jentry);
    if(ientry < 0) break;
    nb = fChain->GetEntry(jentry); nbytes += nb;
    for(Long64_t jPhoton = 0; jPhoton < Photon_n; jPhoton++)
    {
      if(passPFTightPhoID(jPhoton))
      {
        nTightPerEvent++;
      }
      if(passMediumPFPhoID(jPhoton) || passPFTightPhoID(jPhoton))
      {
        nMediumPerEvent++;
      }
      if(passLoosePFPhoID(jPhoton) || passMediumPFPhoID(jPhoton) || passPFTightPhoID(jPhoton))
      {
        nLoosePerEvent++;
      }
    }
    hNTightReal->Fill(nTightPerEvent);
    hNMediumReal->Fill(nMediumPerEvent);
    hNLooseReal->Fill(nLoosePerEvent);
    for(Long64_t jpfJet = 0; jpfJet < pfJet_n; jpfJet++)
    { 
      alrInc = false;
      rndmNum = r.Rndm();
      k = hFakeRateTight->GetXaxis()->FindBin(pfJet_pt[jpfJet]);
      if(rndmNum < hFakeRateTight->GetBinContent(k) && alrInc == false)
      {
        nTightPerEvent++;
	nMediumPerEvent++;
	nLoosePerEvent++;
	alrInc = true;
      }
      k = hFakeRateMedium->GetXaxis()->FindBin(pfJet_pt[jpfJet]);
      if(rndmNum < hFakeRateMedium->GetBinContent(k) && alrInc == false)
      {
        nMediumPerEvent++;
	nLoosePerEvent++;
	alrInc = true;
      }
      k = hFakeRateLoose->GetXaxis()->FindBin(pfJet_pt[jpfJet]);
      if(rndmNum < hFakeRateLoose->GetBinContent(k) && alrInc == false)
      {
        nLoosePerEvent++;
	alrInc = true;
      }
    }
    hNTightTheor->Fill(nTightPerEvent);
    hNMediumTheor->Fill(nMediumPerEvent);
    hNLooseTheor->Fill(nLoosePerEvent);
    if (Cut(ientry) < 0) continue;
  }
}

void myClass::probeLoop1()
{
  float deltaR = 0;
  
  if(fChain == 0) return;

  Long64_t nentrs = fChain->GetEntriesFast();
  Long64_t nbytes = 0, nb = 0;
  for(Long64_t jentry=0; jentry < nentrs; jentry++)
  {
    Long64_t ientry = LoadTree(jentry);
    if(ientry < 0) break;
    nb = fChain->GetEntry(jentry); nbytes += nb;
    //Compare deltaR for every jet with TAG photon (Photon[0])
    for(Long64_t jPFJet = 0; jPFJet < pfJet_n; jPFJet++)
    {
      deltaR = calculateDeltaR(0, jPFJet);
      //If deltaR is within 0.5 skip the jet
      //Otherwise it is a probe jet
      if(deltaR >= 0.3)
      {
        for(Long64_t i = 1; i < Photon_n; i++)
	{
	  deltaR = calculateDeltaR(i, jPFJet);
	  if(deltaR < 0.3)
	  {
	    if(passPFTightPhoID(i))
	    {
	      hTightProbePt->Fill(pfJet_pt[jPFJet]);
	      hMediumProbePt->Fill(pfJet_pt[jPFJet]);
	      hLooseProbePt->Fill(pfJet_pt[jPFJet]);
	    }
	    if(passMediumPFPhoID(i))
	    {
	      hMediumProbePt->Fill(pfJet_pt[jPFJet]);
	      hLooseProbePt->Fill(pfJet_pt[jPFJet]);
	    }
	    if(passLoosePFPhoID(i))
	    {
	      hLooseProbePt->Fill(pfJet_pt[jPFJet]); 
	    }
	  }
	}
	hNoCutProbePt->Fill(pfJet_pt[jPFJet]);
      }
    }
    if (Cut(ientry) < 0) continue;
  }
}

void myClass::probeLoop2()
{
  float deltaR;
  Long64_t n3PerEvent;
  Long64_t n2PerEvent;
  Long64_t n2;
  Long64_t n3;
  Long64_t nPerPhoton;

  if(fChain == 0) return;

  Long64_t nentrs = fChain->GetEntriesFast();
  Long64_t nbytes = 0, nb = 0;
  for(Long64_t jentry=0; jentry < nentrs; jentry++)
  {
    n2PerEvent = 0;
    n3PerEvent = 0;
    Long64_t ientry = LoadTree(jentry);
    if(ientry < 0) break;
    nb = fChain->GetEntry(jentry); nbytes += nb;
    for(Long64_t i = 0; i < Photon_n; i++)
    {
      nPerPhoton = 0;
      for(Long64_t jPFJet = 0; jPFJet < pfJet_n; jPFJet++)
      {
        deltaR = calculateDeltaR(i, jPFJet);
        if(deltaR < 0.3)
        { 
	  nPerPhoton++;
          if(passPFTightPhoID(i))
          {
            hTightProbePt->Fill(pfJet_pt[jPFJet]);
            hMediumProbePt->Fill(pfJet_pt[jPFJet]);
            hLooseProbePt->Fill(pfJet_pt[jPFJet]);
          }
          if(passMediumPFPhoID(i))
          {
            hMediumProbePt->Fill(pfJet_pt[jPFJet]);
            hLooseProbePt->Fill(pfJet_pt[jPFJet]);
          }
          if(passLoosePFPhoID(i))
          {
            hLooseProbePt->Fill(pfJet_pt[jPFJet]); 
          }
        }
        hNoCutProbePt->Fill(pfJet_pt[jPFJet]);
      }
      if(nPerPhoton == 2)
      {
        n2PerEvent++;
      }
      if(nPerPhoton ==3 )
      {
        n3PerEvent++;
      }
    }
    if(n2PerEvent >= 1)
    {
      n2++;
    }
    if(n3PerEvent >= 1)
    {
      n3++;
    }
  if (Cut(ientry) < 0) continue;
  }

  cout << "There are " << n2 << " events that double match a jet" << endl;
  cout << "There are " << n3 << " events that triple match a jet" << endl;
}

void myClass::histoDeltaR()
{
  float deltaR = 0;
  bool alrFilled = false;

  if(fChain == 0) return;

  Long64_t nentrs = fChain->GetEntriesFast();
  Long64_t nbytes = 0, nb = 0;
  for(Long64_t jentry=0; jentry < nentrs; jentry++)
  {
    Long64_t ientry = LoadTree(jentry);
    if(ientry < 0) break;
    nb = fChain->GetEntry(jentry); nbytes += nb;
    //Loop through each photon and jet and calc DeltaR
    for(Long64_t jPhoton = 0; jPhoton < Photon_n; jPhoton++)
    {
      for(Long64_t jJet = 0; jJet < pfJet_n; jJet++)
      {
        deltaR = calculateDeltaR(jPhoton, jJet);
        //Find DeltaR for every photon/jet combination
	hNoCutDeltaR->Fill(deltaR);
	//Find DeltaR for every loose photon/jet combination
        if(passLoosePFPhoID(jPhoton) || passPFTightPhoID(jPhoton) || passMediumPFPhoID(jPhoton))
        { 
          hLooseDeltaR->Fill(deltaR);
        }
	//Find DeltaR for every tight photon/jet combination
	if(passPFTightPhoID(jPhoton))
	{
	  hTightDeltaR->Fill(deltaR);
	}
      }
    }
    if (Cut(ientry) < 0) continue;
  }
}

void myClass::histoLoop()
{
   bool alrInc = false;   
   
   if(fChain == 0) return;

   Long64_t nentrs = fChain->GetEntriesFast();
   nEntries = nEntries + nentrs;
   Long64_t nbytes = 0, nb = 0;
   for(Long64_t jentry=0; jentry < nentrs; jentry++) 
   {
      Long64_t ientry = LoadTree(jentry);
      if(ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      //These two variable are used to determine if it is a loose event
      alrInc = false;
      nLoosePerEvent = 0;
      //Loop through all of the photons in the event
      for(Long64_t photonNum=0; photonNum<Photon_n; photonNum++)
      {
        //Check to see if tight photon
        if(passPFTightPhoID(photonNum))
        {
	  nTightPho++;
	  if(Photon_pt[photonNum] < lowestTightPt)
	  {
	    lowestTightPt = Photon_pt[photonNum];
	  }
          //Fill tight histograms
          hTightPt->Fill(Photon_pt[photonNum]);
          hTightEta->Fill(Photon_eta[photonNum]);
          hTightPhi->Fill(Photon_phi[photonNum]);
        }
	//Check if tight or medium photon
	if(passMediumPFPhoID(photonNum) || passPFTightPhoID(photonNum))
	{
	  nMediumPho++;
	  //Fill medium histograms
	  hMediumPt->Fill(Photon_pt[photonNum]);
	  hMediumEta->Fill(Photon_eta[photonNum]);
	  hMediumPhi->Fill(Photon_phi[photonNum]);
	}
        //Check if tight or loose and increment number of loose
        if(passLoosePFPhoID(photonNum) || passPFTightPhoID(photonNum) || passMediumPFPhoID(photonNum))
        {
	  nLoosePho++;
          nLoosePerEvent++;
	  if(Photon_pt[photonNum] < lowestLoosePt)
	  {
	    lowestLoosePt = Photon_pt[photonNum];
	  }
          if(!alrInc) //checks to see if already incremented number of loose events
            {nLooseEvents++; alrInc = true;}
          //Fill loose histograms
          hLoosePt->Fill(Photon_pt[photonNum]);
          hLooseEta->Fill(Photon_eta[photonNum]);
          hLoosePhi->Fill(Photon_phi[photonNum]);
        }
        //Fill no cut histograms
        hNoCutPt->Fill(Photon_pt[photonNum]); 
        hNoCutEta->Fill(Photon_eta[photonNum]); 
        hNoCutPhi->Fill(Photon_phi[photonNum]);
        //Increment number of no cut photons
        nNoCutPho++;
      }
      if(nLoosePerEvent == 1) {nEventsOneL++;}
      if(nLoosePerEvent == 2) {nEventsTwoL++;}
      if(nLoosePerEvent >  2) {nEventsGTTwoL++;}
      //Loop through all the jets
      for(Long64_t jetNum=0; jetNum<pfJet_n; jetNum++)
      {
        hPFJetPt->Fill(pfJet_pt[jetNum]);
	hPFJetEta->Fill(pfJet_eta[jetNum]);
	hPFJetPhi->Fill(pfJet_phi[jetNum]);
      }
//   if (Cut(ientry) < 0) continue;
   }
}

void PrintResults(void)
{
   cout << endl;
   hNoCutPt->Print();
   hTightPt->Print();
   hMediumPt->Print();
   hLoosePt->Print();
   hNoCutEta->Print();
   hTightEta->Print();
   hMediumEta->Print();
   hLooseEta->Print();
   hNoCutPhi->Print();
   hTightPhi->Print();
   hMediumPhi->Print();
   hLoosePhi->Print();
   hFakeRateTight->Print();
   hFakeRateMedium->Print();
   hFakeRateLoose->Print();
   hPFJetPt->Print();
   hPFJetEta->Print();
   hPFJetPhi->Print();
   hNoCutDeltaR->Print();
   hLooseDeltaR->Print();
   hTightDeltaR->Print();
   hNoCutProbePt->Print();
   hTightProbePt->Print();
   hMediumProbePt->Print();
   hLooseProbePt->Print();
//   hNTightTheor->Print();
//   hNMediumTheor->Print();
//   hNLooseTheor->Print();
//   hNTightReal->Print();
//   hNMediumReal->Print();
//   hNLooseReal->Print();

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
   cout << "Number of events with one loose photon: " << nEventsOneL << endl;
   cout << "Number of events with two loose photons: " << nEventsTwoL << endl;
   cout << "Number of events with greater than two loose photons: " << nEventsGTTwoL << endl;
   cout << endl;
   cout << "Lowest Pt for Loose Photons: " << lowestLoosePt << endl;
   cout << "Lowest Pt for Tight Photon: " << lowestTightPt << endl;
   cout << endl;

/*   int fargc = 0;
   char* fargv[1];
   fargv[0] = NULL;
   TApplication *theApp = new TRint("App", &fargc, fargv);

   TCanvas *c1 = new TCanvas("NoCutPlots", "No Cut Plot", 10, 10, 1200, 750);
   c1->Divide(2,1);
   c1->cd(1);
   hLooseDeltaR->Draw();
   c1->cd(2);
   hTightDeltaR->Draw();
   c1->Update();

   theApp->Run();
*/
}

void SaveHistograms(void)
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
//   hNTightTheor->Write();
//   hNMediumTheor->Write();
//   hNLooseTheor->Write();
//   hNTightReal->Write();
//   hNMediumReal->Write();
//   hNLooseReal->Write();
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
