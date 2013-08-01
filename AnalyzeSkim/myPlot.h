 
//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Sep 21 05:00:52 2012 by ROOT version 5.32/00
// from TTree myEvent/a tree with histograms
// found on file: outputfile_singlePhoton_run2012B_promptReco_v1_212.root
//////////////////////////////////////////////////////////

#ifndef myPlot_h
#define myPlot_h
 
#include <TROOT.h>
#include <TFile.h>
#include <TChain.h>
#include <TTree.h>
#include <TBranch.h>
#include "TH1.h"
#include "TH2.h"
#include <TMinuit.h>
#include <TRandom.h>
#include <string>
#include <iostream>
#include <fstream>
#include <TMath.h>
#include <stdio.h>
#include <TString.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TH1I.h>
#include <TSystemFile.h>
#include <TSystemDirectory.h>
//#include <TDCacheFile.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TList.h>
#include <Riostream.h> 
#include <TGraphAsymmErrors.h>
#include <map>
//#include "TRFIOFile.h"
#include <TSystem.h>
#include "TMath.h"
#include <vector>
#include <TList.h>
#include <Riostream.h> 
#include <set>


#ifdef __MAKECINT__ 
#pragma link C++ class vector<bool>+;
#pragma link C++ class map<TString,TH1D*>+;
#endif
 
using namespace std;        
using namespace ROOT;


// Fixed size dimensions of array or collections stored in the TTree if any.
const Int_t kMaxnpho = 200;

class myPlot {
public :

   TH1I*  choosenVtx;
   string        isoType;
  string         dataType;

   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           nevents;
   UInt_t          run;
   UInt_t          event;
   UInt_t          luminosityBlock;
   UInt_t          beamCrossing;
   UInt_t          totalIntensityBeam1;
   UInt_t          totalIntensityBeam2;
   Float_t         avgInsDelLumi;
   Float_t         avgInsDelLumiErr;
   Float_t         avgInsRecLumi;
   Float_t         avgInsRecLumiErr;
   Int_t           ntriggers;
   vector<string>  *triggernames;
   vector<int>     *triggerprescales;
   vector<bool>    *ifTriggerpassed;
   vector<float>   *ObjectPt;
   vector<float>   *ObjectEta;
   vector<float>   *ObjectPhi;
   vector<string>  *FilterNames;
   vector<int>     *FilterStartPosition;
   vector<int>     *FilterEndPosition;
   vector<int>     *ObjectStartPosition;
   vector<int>     *ObjectEndPosition;
   Int_t           Vertex_n;
   Float_t         Vertex_x[200];   //[Vertex_n]
   Float_t         Vertex_y[200];   //[Vertex_n]
   Float_t         Vertex_z[200];   //[Vertex_n]
   Int_t           Vertex_tracksize[200];   //[Vertex_n]
   Int_t           Vertex_ndof[200];   //[Vertex_n]
   Float_t         Vertex_chi2[200];   //[Vertex_n]
   Float_t         Vertex_d0[200];   //[Vertex_n]
   Bool_t          Vertex_isFake[200];   //[Vertex_n]
   Bool_t          Scraping_isScrapingEvent;
   Int_t           Scraping_numOfTracks;
   Float_t         Scraping_fractionOfGoodTracks;
   Int_t           Track_n;
   Float_t         Track_px[1000];   //[Track_n]
   Float_t         Track_py[1000];   //[Track_n]
   Float_t         Track_pz[1000];   //[Track_n]
   Float_t         Track_vx[1000];   //[Track_n]
   Float_t         Track_vy[1000];   //[Track_n]
   Float_t         Track_vz[1000];   //[Track_n]
   Float_t         Track_pt[1000];   //[Track_n]
   Float_t         Track_eta[1000];   //[Track_n]
   Float_t         Track_phi[1000];   //[Track_n]
   Int_t           Jet_n;
   Float_t         Jet_px[200];   //[Jet_n]
   Float_t         Jet_py[200];   //[Jet_n]
   Float_t         Jet_E[200];   //[Jet_n]
   Float_t         Jet_pz[200];   //[Jet_n]
   Float_t         Jet_vx[200];   //[Jet_n]
   Float_t         Jet_vy[200];   //[Jet_n]
   Float_t         Jet_vz[200];   //[Jet_n]
   Float_t         Jet_pt[200];   //[Jet_n]
   Float_t         Jet_eta[200];   //[Jet_n]
   Float_t         Jet_phi[200];   //[Jet_n]
   Float_t         Jet_emEnergyFraction[200];   //[Jet_n]
   Float_t         Jet_energyFractionHadronic[200];   //[Jet_n]
   Int_t           Jet_hitsInN90[200];   //[Jet_n]
   Int_t           Jet_n90Hits[200];   //[Jet_n]
   Int_t           Jet_nTowers[200];   //[Jet_n]
   Float_t         Jet_fHPD[200];   //[Jet_n]
   Float_t         Jet_fRBX[200];   //[Jet_n]
   Float_t         Jet_RHF[200];   //[Jet_n]
   Float_t         Jet_jecUncer[200];   //[Jet_n]
   Float_t         Jet_jecCorr[200];   //[Jet_n]
   Float_t         ucJet_px[200];   //[Jet_n]
   Float_t         ucJet_py[200];   //[Jet_n]
   Float_t         ucJet_E[200];   //[Jet_n]
   Float_t         ucJet_pz[200];   //[Jet_n]
   Float_t         ucJet_pt[200];   //[Jet_n]
   Float_t         ucJet_eta[200];   //[Jet_n]
   Float_t         ucJet_phi[200];   //[Jet_n]
   Int_t           pfJet_n;
   Float_t         pfJet_px[200];   //[pfJet_n]
   Float_t         pfJet_py[200];   //[pfJet_n]
   Float_t         pfJet_E[200];   //[pfJet_n]
   Float_t         pfJet_pz[200];   //[pfJet_n]
   Float_t         pfJet_vx[200];   //[pfJet_n]
   Float_t         pfJet_vy[200];   //[pfJet_n]
   Float_t         pfJet_vz[200];   //[pfJet_n]
   Float_t         pfJet_pt[200];   //[pfJet_n]
   Float_t         pfJet_eta[200];   //[pfJet_n]
   Float_t         pfJet_phi[200];   //[pfJet_n]
   Float_t         pfjet_CEF[200];   //[pfJet_n]
   Float_t         pfjet_CHF[200];   //[pfJet_n]
   Float_t         pfjet_NEF[200];   //[pfJet_n]
   Float_t         pfjet_NHF[200];   //[pfJet_n]
   Int_t           pfjet_NCH[200];   //[pfJet_n]
   Float_t         pfjet_HFHAE[200];   //[pfJet_n]
   Float_t         pfjet_HFEME[200];   //[pfJet_n]
   Int_t           pfjet_NConstituents[200];   //[pfJet_n]
   Float_t         pujetIdFull_mva[200];   //[pfJet_n]
   Float_t         pujetIdSimple_mva[200];   //[pfJet_n]
   Float_t         pujetIdCutBased_mva[200];   //[pfJet_n]
   Int_t           pujetIdFull_loose[200];   //[pfJet_n]
   Int_t           pujetIdFull_medium[200];   //[pfJet_n]
   Int_t           pujetIdFull_tight[200];   //[pfJet_n]
   Int_t           pujetIdSimple_loose[200];   //[pfJet_n]
   Int_t           pujetIdSimple_medium[200];   //[pfJet_n]
   Int_t           pujetIdSimple_tight[200];   //[pfJet_n]
   Int_t           pujetIdCutBased_loose[200];   //[pfJet_n]
   Int_t           pujetIdCutBased_medium[200];   //[pfJet_n]
   Int_t           pujetIdCutBased_tight[200];   //[pfJet_n]
   Float_t         pfjet_TrackCountHiEffBJetTags[200];   //[pfJet_n]
   Float_t         pfjet_TrackCountHiPurBJetTags[200];   //[pfJet_n]
   Float_t         pfjet_SimpleSVHiEffBJetTags[200];   //[pfJet_n]
   Float_t         pfjet_SimpleSVHiPurBJetTags[200];   //[pfJet_n]
   Float_t         pfJet_jecUncer[200];   //[pfJet_n]
   Float_t         pfJet_jecCorr[200];   //[pfJet_n]
   Float_t         ucpfJet_px[200];   //[pfJet_n]
   Float_t         ucpfJet_py[200];   //[pfJet_n]
   Float_t         ucpfJet_E[200];   //[pfJet_n]
   Float_t         ucpfJet_pz[200];   //[pfJet_n]
   Float_t         ucpfJet_pt[200];   //[pfJet_n]
   Float_t         ucpfJet_eta[200];   //[pfJet_n]
   Float_t         ucpfJet_phi[200];   //[pfJet_n]
   Int_t           Electron_n;
   Float_t         Electron_px[200];   //[Electron_n]
   Float_t         Electron_py[200];   //[Electron_n]
   Float_t         Electron_pz[200];   //[Electron_n]
   Float_t         Electron_vx[200];   //[Electron_n]
   Float_t         Electron_vy[200];   //[Electron_n]
   Float_t         Electron_vz[200];   //[Electron_n]
   Float_t         Electron_pt[200];   //[Electron_n]
   Float_t         Electron_eta[200];   //[Electron_n]
   Float_t         Electron_phi[200];   //[Electron_n]
   Float_t         Electron_energy[200];   //[Electron_n]
   Float_t         Electron_charge[200];   //[Electron_n]
   Float_t         Electron_trkIso[200];   //[Electron_n]
   Float_t         Electron_ecalIso[200];   //[Electron_n]
   Float_t         Electron_hcalIso[200];   //[Electron_n]
   Float_t         Electron_SigmaIetaIeta[200];   //[Electron_n]
   Float_t         Electron_dEtaIn[200];   //[Electron_n]
   Float_t         Electron_dPhiIn[200];   //[Electron_n]
   Float_t         Electron_HoE[200];   //[Electron_n]
   Float_t         Electron_sc_energy[200];   //[Electron_n]
   Float_t         Electron_sc_eta[200];   //[Electron_n]
   Float_t         Electron_sc_phi[200];   //[Electron_n]
   Int_t           Muon_n;
   Float_t         Muon_px[200];   //[Muon_n]
   Float_t         Muon_py[200];   //[Muon_n]
   Float_t         Muon_pz[200];   //[Muon_n]
   Float_t         Muon_vx[200];   //[Muon_n]
   Float_t         Muon_vy[200];   //[Muon_n]
   Float_t         Muon_vz[200];   //[Muon_n]
   Float_t         Muon_pt[200];   //[Muon_n]
   Float_t         Muon_eta[200];   //[Muon_n]
   Float_t         Muon_phi[200];   //[Muon_n]
   Float_t         Muon_energy[200];   //[Muon_n]
   Float_t         Muon_charge[200];   //[Muon_n]
   Bool_t          Muon_isGlobalMuon[200];   //[Muon_n]
   Bool_t          Muon_isTrackerMuon[200];   //[Muon_n]
   Bool_t          Muon_isStandAloneMuon[200];   //[Muon_n]
   Bool_t          Muon_InnerTrack_isNonnull[200];   //[Muon_n]
   Bool_t          Muon_OuterTrack_isNonnull[200];   //[Muon_n]
   Float_t         Muon_OuterTrack_InnerPoint_x[200];   //[Muon_n]
   Float_t         Muon_OuterTrack_InnerPoint_y[200];   //[Muon_n]
   Float_t         Muon_OuterTrack_InnerPoint_z[200];   //[Muon_n]
   Float_t         Muon_OuterTrack_InnerPoint_px[200];   //[Muon_n]
   Float_t         Muon_OuterTrack_InnerPoint_py[200];   //[Muon_n]
   Float_t         Muon_OuterTrack_InnerPoint_pz[200];   //[Muon_n]
   Float_t         Muon_OuterTrack_OuterPoint_x[200];   //[Muon_n]
   Float_t         Muon_OuterTrack_OuterPoint_y[200];   //[Muon_n]
   Float_t         Muon_OuterTrack_OuterPoint_z[200];   //[Muon_n]
   Float_t         Muon_OuterTrack_OuterPoint_px[200];   //[Muon_n]
   Float_t         Muon_OuterTrack_OuterPoint_py[200];   //[Muon_n]
   Float_t         Muon_OuterTrack_OuterPoint_pz[200];   //[Muon_n]
   Float_t         Muon_InnerTrack_InnerPoint_x[200];   //[Muon_n]
   Float_t         Muon_InnerTrack_InnerPoint_y[200];   //[Muon_n]
   Float_t         Muon_InnerTrack_InnerPoint_z[200];   //[Muon_n]
   Float_t         Muon_InnerTrack_InnerPoint_px[200];   //[Muon_n]
   Float_t         Muon_InnerTrack_InnerPoint_py[200];   //[Muon_n]
   Float_t         Muon_InnerTrack_InnerPoint_pz[200];   //[Muon_n]
   Float_t         Muon_InnerTrack_OuterPoint_x[200];   //[Muon_n]
   Float_t         Muon_InnerTrack_OuterPoint_y[200];   //[Muon_n]
   Float_t         Muon_InnerTrack_OuterPoint_z[200];   //[Muon_n]
   Float_t         Muon_InnerTrack_OuterPoint_px[200];   //[Muon_n]
   Float_t         Muon_InnerTrack_OuterPoint_py[200];   //[Muon_n]
   Float_t         Muon_InnerTrack_OuterPoint_pz[200];   //[Muon_n]
   Float_t         Muon_trackIso[200];   //[Muon_n]
   Float_t         Muon_ecalIso[200];   //[Muon_n]
   Float_t         Muon_hcalIso[200];   //[Muon_n]
   Float_t         Muon_relIso[200];   //[Muon_n]
   Int_t           Muon_normChi2[200];   //[Muon_n]
   Int_t           Muon_validHits[200];   //[Muon_n]
   Int_t           Muon_tkHits[200];   //[Muon_n]
   Int_t           Muon_pixHits[200];   //[Muon_n]
   Int_t           Muon_numberOfMatches[200];   //[Muon_n]
   Float_t         Muon_OuterPoint_x[200];   //[Muon_n]
   Float_t         Muon_OuterPoint_y[200];   //[Muon_n]
   Float_t         Muon_OuterPoint_z[200];   //[Muon_n]
   Float_t         Muon_InnerPoint_x[200];   //[Muon_n]
   Float_t         Muon_InnerPoint_y[200];   //[Muon_n]
   Float_t         Muon_InnerPoint_z[200];   //[Muon_n]
   Int_t           CosmicMuon_n;
   Float_t         CosmicMuon_px[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_py[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_pz[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_pt[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_eta[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_phi[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_energy[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_charge[200];   //[CosmicMuon_n]
   Bool_t          CosmicMuon_isGlobalMuon[200];   //[CosmicMuon_n]
   Bool_t          CosmicMuon_isTrackerMuon[200];   //[CosmicMuon_n]
   Bool_t          CosmicMuon_isStandAloneMuon[200];   //[CosmicMuon_n]
   Bool_t          CosmicMuon_InnerTrack_isNonnull[200];   //[CosmicMuon_n]
   Bool_t          CosmicMuon_OuterTrack_isNonnull[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_InnerPoint_x[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_InnerPoint_y[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_InnerPoint_z[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_InnerPoint_px[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_InnerPoint_py[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_InnerPoint_pz[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_OuterPoint_x[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_OuterPoint_y[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_OuterPoint_z[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_OuterPoint_px[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_OuterPoint_py[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_OuterPoint_pz[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_InnerPoint_x[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_InnerPoint_y[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_InnerPoint_z[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_InnerPoint_px[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_InnerPoint_py[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_InnerPoint_pz[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_OuterPoint_x[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_OuterPoint_y[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_OuterPoint_z[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_OuterPoint_px[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_OuterPoint_py[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_OuterPoint_pz[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterPoint_x[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterPoint_y[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterPoint_z[200];   //[CosmicMuon_n]
   Int_t           Tau_n;
   Float_t         Tau_px[200];   //[Tau_n]
   Float_t         Tau_py[200];   //[Tau_n]
   Float_t         Tau_pz[200];   //[Tau_n]
   Float_t         Tau_vx[200];   //[Tau_n]
   Float_t         Tau_vy[200];   //[Tau_n]
   Float_t         Tau_vz[200];   //[Tau_n]
   Float_t         Tau_pt[200];   //[Tau_n]
   Float_t         Tau_eta[200];   //[Tau_n]
   Float_t         Tau_phi[200];   //[Tau_n]
   Float_t         Tau_energy[200];   //[Tau_n]
   Float_t         Tau_charge[200];   //[Tau_n]
   vector<string>  *genTauDecayMode1;
   Int_t           oneProng0Pi0[200];   //[Tau_n]
   Int_t           oneProng1Pi0[200];   //[Tau_n]
   Int_t           oneProng2Pi0[200];   //[Tau_n]
   Int_t           threeProng0Pi0[200];   //[Tau_n]
   Int_t           threeProng1Pi0[200];   //[Tau_n]
   Int_t           tauelectron[200];   //[Tau_n]
   Int_t           taumuon[200];   //[Tau_n]
   Int_t           nthreeProng1Pi0;
   Int_t           ntauelectron;
   Int_t           ntaumuon;
   Double_t        genHadTauPt[200];   //[Tau_n]
   Double_t        genHadTauEta[200];   //[Tau_n]
   Double_t        genHadTauPhi[200];   //[Tau_n]
   Int_t           nPions[200];   //[Tau_n]
   Int_t           PionPdgId[200][5];   //[Tau_n]
   Double_t        PionPt[200][5];   //[Tau_n]
   Double_t        PionEta[200][5];   //[Tau_n]
   Double_t        PionPhi[200][5];   //[Tau_n]
   Int_t           nPi0[200];   //[Tau_n]
   Int_t           Pi0PdgId[200][5];   //[Tau_n]
   Double_t        Pi0Pt[200][5];   //[Tau_n]
   Double_t        Pi0Eta[200][5];   //[Tau_n]
   Double_t        Pi0Phi[200][5];   //[Tau_n]
   Int_t           nPhotons[200];   //[Tau_n]
   Double_t        PhotonPt[200][5];   //[Tau_n]
   Double_t        PhotonEta[200][5];   //[Tau_n]
   Double_t        PhotonPhi[200][5];   //[Tau_n]
   Int_t           PhotonPdgId[200][5];   //[Tau_n]
   Int_t           Photon_n;
   Float_t         Photon_E[200];   //[Photon_n]
   Float_t         Photon_pt[200];   //[Photon_n]
   Float_t         Photon_eta[200];   //[Photon_n]
   Float_t         Photon_phi[200];   //[Photon_n]
   Float_t         Photon_theta[200];   //[Photon_n]
   Float_t         Photon_et[200];   //[Photon_n]
   Float_t         Photon_swissCross[200];   //[Photon_n]
   Float_t         Photon_e6e2[200];   //[Photon_n]
   Float_t         Photon_e4e1[200];   //[Photon_n]
   Float_t         Photonr9[200];   //[Photon_n]
   Float_t         Photon_e1x5[200];   //[Photon_n]
   Float_t         Photon_e2x5[200];   //[Photon_n]
   Float_t         Photon_e3x3[200];   //[Photon_n]
   Float_t         Photon_e5x5[200];   //[Photon_n]
   Float_t         Photon_r1x5[200];   //[Photon_n]
   Float_t         Photon_r2x5[200];   //[Photon_n]
   Float_t         Photon_maxEnergyXtal[200];   //[Photon_n]
   Float_t         Photon_SigmaEtaEta[200];   //[Photon_n]
   Float_t         Photon_SigmaIetaIeta[200];   //[Photon_n]
   Float_t         Photon_SigmaEtaPhi[200];   //[Photon_n]
   Float_t         Photon_SigmaIetaIphi[200];   //[Photon_n]
   Float_t         Photon_SigmaPhiPhi[200];   //[Photon_n]
   Float_t         Photon_SigmaIphiIphi[200];   //[Photon_n]
   Float_t         Photon_Roundness[200];   //[Photon_n]
   Float_t         Photon_Angle[200];   //[Photon_n]
   Float_t         Photon_ecalRecHitSumEtConeDR03[200];   //[Photon_n]
   Float_t         Photon_hcalTowerSumEtConeDR03[200];   //[Photon_n]
   Float_t         Photon_trkSumPtSolidConeDR03[200];   //[Photon_n]
   Float_t         Photon_trkSumPtHollowConeDR03[200];   //[Photon_n]
   Int_t           Photon_nTrkSolidConeDR03[200];   //[Photon_n]
   Int_t           Photon_nTrkHollowConeDR03[200];   //[Photon_n]
   Float_t         Photon_hcalDepth1TowerSumEtConeDR03[200];   //[Photon_n]
   Float_t         Photon_hcalDepth2TowerSumEtConeDR03[200];   //[Photon_n]
   Float_t         Photon_ecalRecHitSumEtConeDR04[200];   //[Photon_n]
   Float_t         Photon_hcalTowerSumEtConeDR04[200];   //[Photon_n]
   Float_t         Photon_trkSumPtSolidConeDR04[200];   //[Photon_n]
   Float_t         Photon_trkSumPtHollowConeDR04[200];   //[Photon_n]
   Int_t           Photon_nTrkSolidConeDR04[200];   //[Photon_n]
   Int_t           Photon_nTrkHollowConeDR04[200];   //[Photon_n]
   Float_t         Photon_hcalDepth1TowerSumEtConeDR04[200];   //[Photon_n]
   Float_t         Photon_hcalDepth2TowerSumEtConeDR04[200];   //[Photon_n]
   Bool_t          Photon_hasPixelSeed[200];   //[Photon_n]
   Bool_t          Photon_isEB[200];   //[Photon_n]
   Bool_t          Photon_isEE[200];   //[Photon_n]
   Bool_t          Photon_isEBGap[200];   //[Photon_n]
   Bool_t          Photon_isEEGap[200];   //[Photon_n]
   Bool_t          Photon_isEBEEGap[200];   //[Photon_n]
   Float_t         Photon_e2e9[200];   //[Photon_n]
   Float_t         Photon_HoE[200];   //[Photon_n]
   Float_t         Photon_HoEnew[200];   //[Photon_n]
   Float_t         Photon_px[200];   //[Photon_n]
   Float_t         Photon_py[200];   //[Photon_n]
   Float_t         Photon_pz[200];   //[Photon_n]
   Float_t         Photon_vx[200];   //[Photon_n]
   Float_t         Photon_vy[200];   //[Photon_n]
   Float_t         Photon_vz[200];   //[Photon_n]
   Int_t           Photon_no_of_basic_clusters[200];   //[Photon_n]
   Float_t         Photon_sc_energy[200];   //[Photon_n]
   Float_t         Photon_sc_eta[200];   //[Photon_n]
   Float_t         Photon_sc_phi[200];   //[Photon_n]
   Float_t         Photon_sc_x[200];   //[Photon_n]
   Float_t         Photon_sc_y[200];   //[Photon_n]
   Float_t         Photon_sc_z[200];   //[Photon_n]
   Float_t         Photon_etaWidth[200];   //[Photon_n]
   Float_t         Photon_phiWidth[200];   //[Photon_n]
   Float_t         Photon_sc_et[200];   //[Photon_n]
   Float_t         matchphotonE[200];   //[Photon_n]
   Float_t         matchphotonpt[200];   //[Photon_n]
   Float_t         matchphotoneta[200];   //[Photon_n]
   Float_t         matchphotonphi[200];   //[Photon_n]
   Float_t         matchphotonpx[200];   //[Photon_n]
   Float_t         matchphotonpy[200];   //[Photon_n]
   Float_t         matchphotonpz[200];   //[Photon_n]
   Bool_t          ismatchedphoton[200];   //[Photon_n]
   Bool_t          Photon_hasConvTrk[200];   //[Photon_n]
   Int_t           Photon_ntracks[200];   //[Photon_n]
   Bool_t          Photon_isconverted[200];   //[Photon_n]
   Float_t         Photon_pairInvmass[200];   //[Photon_n]
   Float_t         Photon_pairCotThetaSeperation[200];   //[Photon_n]
   Float_t         Photon_pairmomentumX[200];   //[Photon_n]
   Float_t         Photon_pairmomentumY[200];   //[Photon_n]
   Float_t         Photon_pairmomentumZ[200];   //[Photon_n]
   Float_t         Photon_EoverP[200];   //[Photon_n]
   Float_t         Photon_ConvVx[200];   //[Photon_n]
   Float_t         Photon_ConvVy[200];   //[Photon_n]
   Float_t         Photon_ConvVz[200];   //[Photon_n]
   Float_t         Photon_ZOfPrimaryVertex[200];   //[Photon_n]
   Float_t         Photon_distOfMinimumApproach[200];   //[Photon_n]
   Float_t         Photon_dPhiTracksAtVtx[200];   //[Photon_n]
   Float_t         Photon_dPhiTracksAtEcal[200];   //[Photon_n]
   Float_t         Photon_dEtaTracksAtEcal[200];   //[Photon_n]
   Int_t           npho_;
   Bool_t          Photon_Electronveto[kMaxnpho];   //[npho_]
   Float_t         PFiso_Charged03[kMaxnpho];   //[npho_]
    Float_t        PFWorstiso_Charged03[kMaxnpho];   //[npho]  
   Float_t         PFiso_Photon03[kMaxnpho];   //[npho_]
   Float_t         PFiso_Neutral03[kMaxnpho];   //[npho_]
   Float_t         PFiso_Sum03[kMaxnpho];   //[npho_]
   Int_t           Photon_ncrys[200];   //[Photon_n]
   Float_t         Photon_timing_xtal[200][100];   //[Photon_n]
   Float_t         Photon_timingavg_xtal[200];   //[Photon_n]
   Float_t         Photon_energy_xtal[200][100];   //[Photon_n]
   Int_t           Photon_ieta_xtalEB[200][100];   //[Photon_n]
   Int_t           Photon_iphi_xtalEB[200][100];   //[Photon_n]
   Int_t           Photon_recoFlag_xtalEB[200][100];   //[Photon_n]
   Float_t         Photon_timeError_xtal[200][100];   //[Photon_n]
   Float_t         Photon_s9[200];   //[Photon_n]
   Int_t           HERecHit_subset_n;
   UInt_t          HERecHit_subset_detid[10000];   //[HERecHit_subset_n]
   Float_t         HERecHit_subset_energy[10000];   //[HERecHit_subset_n]
   Float_t         HERecHit_subset_time[10000];   //[HERecHit_subset_n]
   Int_t           HERecHit_subset_depth[10000];   //[HERecHit_subset_n]
   Float_t         HERecHit_subset_phi[10000];   //[HERecHit_subset_n]
   Float_t         HERecHit_subset_eta[10000];   //[HERecHit_subset_n]
   Float_t         HERecHit_subset_x[10000];   //[HERecHit_subset_n]
   Float_t         HERecHit_subset_y[10000];   //[HERecHit_subset_n]
   Float_t         HERecHit_subset_z[10000];   //[HERecHit_subset_n]
   Float_t         Photon_mipChi2[200];   //[Photon_n]
   Float_t         Photon_mipTotEnergy[200];   //[Photon_n]
   Float_t         Photon_mipSlope[200];   //[Photon_n]
   Float_t         Photon_mipIntercept[200];   //[Photon_n]
   Int_t           Photon_mipNhitCone[200];   //[Photon_n]
   Bool_t          Photon_mipIsHalo[200];   //[Photon_n]
   Int_t           EBRecHit_size;
   Float_t         EBRecHit_eta[10000];   //[EBRecHit_size]
   Float_t         EBRecHit_phi[10000];   //[EBRecHit_size]
   Int_t           EBRecHit_ieta[10000];   //[EBRecHit_size]
   Int_t           EBRecHit_iphi[10000];   //[EBRecHit_size]
   Float_t         EBRecHit_e[10000];   //[EBRecHit_size]
   Float_t         EBRecHit_et[10000];   //[EBRecHit_size]
   Int_t           EBRecHit_flag[10000];   //[EBRecHit_size]
   Float_t         EBRecHit_time[10000];   //[EBRecHit_size]
   Int_t           EERecHit_size;
   Float_t         EERecHit_eta[10000];   //[EERecHit_size]
   Float_t         EERecHit_phi[10000];   //[EERecHit_size]
   Int_t           EERecHit_ieta[10000];   //[EERecHit_size]
   Int_t           EERecHit_iphi[10000];   //[EERecHit_size]
   Float_t         EERecHit_e[10000];   //[EERecHit_size]
   Float_t         EERecHit_et[10000];   //[EERecHit_size]
   Int_t           EERecHit_flag[10000];   //[EERecHit_size]
   Float_t         EERecHit_time[10000];   //[EERecHit_size]
   Bool_t          isBeamHaloGlobalLoosePass;
   Bool_t          isBeamHaloGlobalTightPass;
   Bool_t          isBeamHaloHcalLoosePass;
   Bool_t          isBeamHaloHcalTightPass;
   Bool_t          isBeamHaloCSCLoosePass;
   Bool_t          isBeamHaloCSCTightPass;
   Bool_t          isBeamHaloEcalLoosePass;
   Bool_t          isBeamHaloEcalTightPass;
   Bool_t          isBeamHaloIDTightPass;
   Bool_t          isBeamHaloIDLoosePass;
   Bool_t          isSmellsLikeHalo_Tag;
   Bool_t          isLooseHalo_Tag;
   Bool_t          isTightHalo_Tag;
   Bool_t          isExtremeTightHalo_Tag;
   Float_t         CaloMetSigma;
   Float_t         CaloMetEz;
   Float_t         CaloEtFractionHadronic;
   Float_t         CaloEmEtFraction;
   Float_t         CaloHadEtInHB;
   Float_t         CaloHadEtInHE;
   Float_t         CaloHadEtInHO;
   Float_t         CaloHadEtInHF;
   Float_t         CaloEmEtInEB;
   Float_t         CaloEmEtInEE;
   Float_t         CaloEmEtInHF;
   Float_t         CaloMaxEtInEmTowers;
   Float_t         CaloMaxEtInHadTowers;
   Float_t         CaloMetPt[6];
   Float_t         CaloMetPx[6];
   Float_t         CaloMetPy[6];
   Float_t         CaloMetPhi[6];
   Float_t         CaloMetSumEt[6];
   Float_t         Delta_phi;
   Float_t         PFMetPt[6];
   Float_t         PFMetPx[6];
   Float_t         PFMetPy[6];
   Float_t         PFMetPhi[6];
   Float_t         PFMetSumEt[6];
   Float_t         Delta_phiPF;
   Float_t         TCMetPt[6];
   Float_t         TCMetPx[6];
   Float_t         TCMetPy[6];
   Float_t         TCMetPhi[6];
   Float_t         TCMetSumEt[6];
   Float_t         Delta_phiTC;
   Int_t           ucPhoton_n;
   Float_t         ucPhoton_E[200];   //[ucPhoton_n]
   Float_t         ucPhoton_pt[200];   //[ucPhoton_n]
   Float_t         ucPhoton_eta[200];   //[ucPhoton_n]
   Float_t         ucPhoton_phi[200];   //[ucPhoton_n]
   Float_t         ucPhoton_theta[200];   //[ucPhoton_n]
   Float_t         ucPhoton_et[200];   //[ucPhoton_n]
   Float_t         ucPhoton_swissCross[200];   //[ucPhoton_n]
   Float_t         ucPhoton_e6e2[200];   //[ucPhoton_n]
   Float_t         ucPhoton_e4e1[200];   //[ucPhoton_n]
   Float_t         ucPhotonr9[200];   //[ucPhoton_n]
   Float_t         ucPhoton_e1x5[200];   //[ucPhoton_n]
   Float_t         ucPhoton_e2x5[200];   //[ucPhoton_n]
   Float_t         ucPhoton_e3x3[200];   //[ucPhoton_n]
   Float_t         ucPhoton_e5x5[200];   //[ucPhoton_n]
   Float_t         ucPhoton_r1x5[200];   //[ucPhoton_n]
   Float_t         ucPhoton_r2x5[200];   //[ucPhoton_n]
   Float_t         ucPhoton_maxEnergyXtal[200];   //[ucPhoton_n]
   Float_t         ucPhoton_SigmaEtaEta[200];   //[ucPhoton_n]
   Float_t         ucPhoton_SigmaIetaIeta[200];   //[ucPhoton_n]
   Float_t         ucPhoton_SigmaEtaPhi[200];   //[ucPhoton_n]
   Float_t         ucPhoton_SigmaIetaIphi[200];   //[ucPhoton_n]
   Float_t         ucPhoton_SigmaPhiPhi[200];   //[ucPhoton_n]
   Float_t         ucPhoton_SigmaIphiIphi[200];   //[ucPhoton_n]
   Float_t         ucPhoton_Roundness[200];   //[ucPhoton_n]
   Float_t         ucPhoton_Angle[200];   //[ucPhoton_n]
   Float_t         ucPhoton_ecalRecHitSumEtConeDR03[200];   //[ucPhoton_n]
   Float_t         ucPhoton_hcalTowerSumEtConeDR03[200];   //[ucPhoton_n]
   Float_t         ucPhoton_trkSumPtSolidConeDR03[200];   //[ucPhoton_n]
   Float_t         ucPhoton_trkSumPtHollowConeDR03[200];   //[ucPhoton_n]
   Int_t           ucPhoton_nTrkSolidConeDR03[200];   //[ucPhoton_n]
   Int_t           ucPhoton_nTrkHollowConeDR03[200];   //[ucPhoton_n]
   Float_t         ucPhoton_hcalDepth1TowerSumEtConeDR03[200];   //[ucPhoton_n]
   Float_t         ucPhoton_hcalDepth2TowerSumEtConeDR03[200];   //[ucPhoton_n]
   Float_t         ucPhoton_ecalRecHitSumEtConeDR04[200];   //[ucPhoton_n]
   Float_t         ucPhoton_hcalTowerSumEtConeDR04[200];   //[ucPhoton_n]
   Float_t         ucPhoton_trkSumPtSolidConeDR04[200];   //[ucPhoton_n]
   Float_t         ucPhoton_trkSumPtHollowConeDR04[200];   //[ucPhoton_n]
   Int_t           ucPhoton_nTrkSolidConeDR04[200];   //[ucPhoton_n]
   Int_t           ucPhoton_nTrkHollowConeDR04[200];   //[ucPhoton_n]
   Float_t         ucPhoton_hcalDepth1TowerSumEtConeDR04[200];   //[ucPhoton_n]
   Float_t         ucPhoton_hcalDepth2TowerSumEtConeDR04[200];   //[ucPhoton_n]
   Bool_t          ucPhoton_hasPixelSeed[200];   //[ucPhoton_n]
   Bool_t          ucPhoton_isEB[200];   //[ucPhoton_n]
   Bool_t          ucPhoton_isEE[200];   //[ucPhoton_n]
   Bool_t          ucPhoton_isEBGap[200];   //[ucPhoton_n]
   Bool_t          ucPhoton_isEEGap[200];   //[ucPhoton_n]
   Bool_t          ucPhoton_isEBEEGap[200];   //[ucPhoton_n]
   Float_t         ucPhoton_e2e9[200];   //[ucPhoton_n]
   Float_t         ucPhoton_HoE[200];   //[ucPhoton_n]
   Float_t         ucPhoton_HoEnew[200];   //[ucPhoton_n]
   Float_t         ucPhoton_px[200];   //[ucPhoton_n]
   Float_t         ucPhoton_py[200];   //[ucPhoton_n]
   Float_t         ucPhoton_pz[200];   //[ucPhoton_n]
   Float_t         ucPhoton_vx[200];   //[ucPhoton_n]
   Float_t         ucPhoton_vy[200];   //[ucPhoton_n]
   Float_t         ucPhoton_vz[200];   //[ucPhoton_n]
   Int_t           ucPhoton_no_of_basic_clusters[200];   //[ucPhoton_n]
   Float_t         ucPhoton_sc_energy[200];   //[ucPhoton_n]
   Float_t         ucPhoton_sc_eta[200];   //[ucPhoton_n]
   Float_t         ucPhoton_sc_phi[200];   //[ucPhoton_n]
   Float_t         ucPhoton_sc_x[200];   //[ucPhoton_n]
   Float_t         ucPhoton_sc_y[200];   //[ucPhoton_n]
   Float_t         ucPhoton_sc_z[200];   //[ucPhoton_n]
   Float_t         ucPhoton_etaWidth[200];   //[ucPhoton_n]
   Float_t         ucPhoton_phiWidth[200];   //[ucPhoton_n]
   Float_t         ucPhoton_sc_et[200];   //[ucPhoton_n]
   Float_t         matchucphotonE[200];   //[ucPhoton_n]
   Float_t         matchucphotonpt[200];   //[ucPhoton_n]
   Float_t         matchucphotoneta[200];   //[ucPhoton_n]
   Float_t         matchucphotonphi[200];   //[ucPhoton_n]
   Float_t         matchucphotonpx[200];   //[ucPhoton_n]
   Float_t         matchucphotonpy[200];   //[ucPhoton_n]
   Float_t         matchucphotonpz[200];   //[ucPhoton_n]
   Bool_t          ismatcheducphoton[200];   //[ucPhoton_n]
   Bool_t          ucPhoton_hasConvTrk[200];   //[ucPhoton_n]
   Int_t           ucPhoton_ntracks[200];   //[ucPhoton_n]
   Bool_t          ucPhoton_isconverted[200];   //[ucPhoton_n]
   Float_t         ucPhoton_pairInvmass[200];   //[ucPhoton_n]
   Float_t         ucPhoton_pairCotThetaSeperation[200];   //[ucPhoton_n]
   Float_t         ucPhoton_pairmomentumX[200];   //[ucPhoton_n]
   Float_t         ucPhoton_pairmomentumY[200];   //[ucPhoton_n]
   Float_t         ucPhoton_pairmomentumZ[200];   //[ucPhoton_n]
   Float_t         ucPhoton_EoverP[200];   //[ucPhoton_n]
   Float_t         ucPhoton_ConvVx[200];   //[ucPhoton_n]
   Float_t         ucPhoton_ConvVy[200];   //[ucPhoton_n]
   Float_t         ucPhoton_ConvVz[200];   //[ucPhoton_n]
   Float_t         ucPhoton_ZOfPrimaryVertex[200];   //[ucPhoton_n]
   Float_t         ucPhoton_distOfMinimumApproach[200];   //[ucPhoton_n]
   Float_t         ucPhoton_dPhiTracksAtVtx[200];   //[ucPhoton_n]
   Float_t         ucPhoton_dPhiTracksAtEcal[200];   //[ucPhoton_n]
   Float_t         ucPhoton_dEtaTracksAtEcal[200];   //[ucPhoton_n]
   Int_t           ucPhoton_ncrys[200];   //[ucPhoton_n]
   Float_t         ucPhoton_timing_xtal[200][100];   //[ucPhoton_n]
   Float_t         ucPhoton_timingavg_xtal[100];   //[ucPhoton_n]
   Float_t         ucPhoton_energy_xtal[200][100];   //[ucPhoton_n]
   Int_t           ucPhoton_ieta_xtalEB[200][100];   //[ucPhoton_n]
   Int_t           ucPhoton_iphi_xtalEB[200][100];   //[ucPhoton_n]
   Int_t           ucPhoton_recoFlag_xtalEB[200][100];   //[ucPhoton_n]
   Float_t         ucPhoton_timeError_xtal[200][100];   //[ucPhoton_n]
   Float_t         ucPhoton_s9[200];   //[ucPhoton_n]
   Int_t           ucHERecHit_subset_n;
   UInt_t          ucHERecHit_subset_detid[10000];   //[ucHERecHit_subset_n]
   Float_t         ucHERecHit_subset_energy[10000];   //[ucHERecHit_subset_n]
   Float_t         ucHERecHit_subset_time[10000];   //[ucHERecHit_subset_n]
   Int_t           ucHERecHit_subset_depth[10000];   //[ucHERecHit_subset_n]
   Float_t         ucHERecHit_subset_phi[10000];   //[ucHERecHit_subset_n]
   Float_t         ucHERecHit_subset_eta[10000];   //[ucHERecHit_subset_n]
   Float_t         ucHERecHit_subset_x[10000];   //[ucHERecHit_subset_n]
   Float_t         ucHERecHit_subset_y[10000];   //[ucHERecHit_subset_n]
   Float_t         ucHERecHit_subset_z[10000];   //[ucHERecHit_subset_n]
   Float_t         ucPhoton_mipChi2[200];   //[ucPhoton_n]
   Float_t         ucPhoton_mipTotEnergy[200];   //[ucPhoton_n]
   Float_t         ucPhoton_mipSlope[200];   //[ucPhoton_n]
   Float_t         ucPhoton_mipIntercept[200];   //[ucPhoton_n]
   Int_t           ucPhoton_mipNhitCone[200];   //[ucPhoton_n]
   Bool_t          ucPhoton_mipIsHalo[200];   //[ucPhoton_n]
   Int_t           CaloTower_n;
   Float_t         CaloTower_eta[5000];   //[CaloTower_n]
   Float_t         CaloTower_phi[5000];   //[CaloTower_n]
   Float_t         CaloTower_E[5000];   //[CaloTower_n]
   Float_t         CaloTower_Et[5000];   //[CaloTower_n]
   Float_t         CaloTower_emEnergy[5000];   //[CaloTower_n]
   Float_t         CaloTower_hadEnergy[5000];   //[CaloTower_n]
   Float_t         CaloTower_p[5000];   //[CaloTower_n]
   Float_t         CaloTower_EMEt[5000];   //[CaloTower_n]
   Float_t         CaloTower_HadEt[5000];   //[CaloTower_n]
   Float_t         CaloTower_HadPhi[5000];   //[CaloTower_n]
   Float_t         CaloTower_HadEta[5000];   //[CaloTower_n]
   Float_t         CaloTower_EMPhi[5000];   //[CaloTower_n]
   Float_t         CaloTower_EMEta[5000];   //[CaloTower_n]
   Float_t         CaloTower_HadX[5000];   //[CaloTower_n]
   Float_t         CaloTower_HadY[5000];   //[CaloTower_n]
   Float_t         CaloTower_HadZ[5000];   //[CaloTower_n]
   Float_t         CaloTower_HE_E[5000];   //[CaloTower_n]
   Float_t         CaloTower_HB_E[5000];   //[CaloTower_n]
   Float_t         CaloTower_EMTime[5000];   //[CaloTower_n]
   Float_t         CaloTower_HadTime[5000];   //[CaloTower_n]
   Float_t         rho;
   Float_t         sigma;
   Float_t         rho25;
   Float_t         sigma25;

   // List of branches
   TBranch        *b_nevents;   //!
   TBranch        *b_RunNumber;   //!
   TBranch        *b_EventNumber;   //!
   TBranch        *b_LumiNumber;   //!
   TBranch        *b_BXNumber;   //!
   TBranch        *b_totalIntensityBeam1;   //!
   TBranch        *b_totalIntensityBeam2;   //!
   TBranch        *b_avgInsDelLumi;   //!
   TBranch        *b_avgInsDelLumiErr;   //!
   TBranch        *b_avgInsRecLumi;   //!
   TBranch        *b_avgInsRecLumiErr;   //!
   TBranch        *b_ntriggers;   //!
   TBranch        *b_triggernames;   //!
   TBranch        *b_triggerprescales;   //!
   TBranch        *b_ifTriggerpassed;   //!
   TBranch        *b_ObjectPt;   //!
   TBranch        *b_ObjectEta;   //!
   TBranch        *b_ObjectPhi;   //!
   TBranch        *b_FilterNames;   //!
   TBranch        *b_FilterStartPosition;   //!
   TBranch        *b_FilterEndPosition;   //!
   TBranch        *b_ObjectStartPosition;   //!
   TBranch        *b_ObjectEndPosition;   //!
   TBranch        *b_Vertex_n;   //!
   TBranch        *b_Vertex_x;   //!
   TBranch        *b_Vertex_y;   //!
   TBranch        *b_Vertex_z;   //!
   TBranch        *b_Vertex_tracksize;   //!
   TBranch        *b_Vertex_ndof;   //!
   TBranch        *b_Vertex_chi2;   //!
   TBranch        *b_Vertex_d0;   //!
   TBranch        *b_Vertex_isFake;   //!
   TBranch        *b_Scraping_isScrapingEvent;   //!
   TBranch        *b_Scraping_numOfTracks;   //!
   TBranch        *b_Scraping_fractionOfGoodTracks;   //!
   TBranch        *b_Track_n;   //!
   TBranch        *b_Track_px;   //!
   TBranch        *b_Track_py;   //!
   TBranch        *b_Track_pz;   //!
   TBranch        *b_Track_vx;   //!
   TBranch        *b_Track_vy;   //!
   TBranch        *b_Track_vz;   //!
   TBranch        *b_Track_pt;   //!
   TBranch        *b_Track_eta;   //!
   TBranch        *b_Track_phi;   //!
   TBranch        *b_Jet_n;   //!
   TBranch        *b_Jet_px;   //!
   TBranch        *b_Jet_py;   //!
   TBranch        *b_Jet_E;   //!
   TBranch        *b_Jet_pz;   //!
   TBranch        *b_Jet_vx;   //!
   TBranch        *b_Jet_vy;   //!
   TBranch        *b_Jet_vz;   //!
   TBranch        *b_Jet_pt;   //!
   TBranch        *b_Jet_eta;   //!
   TBranch        *b_Jet_phi;   //!
   TBranch        *b_Jet_emEnergyFraction;   //!
   TBranch        *b_Jet_energyFractionHadronic;   //!
   TBranch        *b_Jet_hitsInN90;   //!
   TBranch        *b_Jet_n90Hits;   //!
   TBranch        *b_Jet_nTowers;   //!
   TBranch        *b_Jet_fHPD;   //!
   TBranch        *b_Jet_fRBX;   //!
   TBranch        *b_Jet_RHF;   //!
   TBranch        *b_Jet_jecUncer;   //!
   TBranch        *b_Jet_jecCorr;   //!
   TBranch        *b_ucJet_px;   //!
   TBranch        *b_ucJet_py;   //!
   TBranch        *b_ucJet_E;   //!
   TBranch        *b_ucJet_pz;   //!
   TBranch        *b_ucJet_pt;   //!
   TBranch        *b_ucJet_eta;   //!
   TBranch        *b_ucJet_phi;   //!
   TBranch        *b_pfJet_n;   //!
   TBranch        *b_pfJet_px;   //!
   TBranch        *b_pfJet_py;   //!
   TBranch        *b_pfJet_E;   //!
   TBranch        *b_pfJet_pz;   //!
   TBranch        *b_pfJet_vx;   //!
   TBranch        *b_pfJet_vy;   //!
   TBranch        *b_pfJet_vz;   //!
   TBranch        *b_pfJet_pt;   //!
   TBranch        *b_pfJet_eta;   //!
   TBranch        *b_pfJet_phi;   //!
   TBranch        *b_pfjet_CEF;   //!
   TBranch        *b_pfjet_CHF;   //!
   TBranch        *b_pfjet_NEF;   //!
   TBranch        *b_pfjet_NHF;   //!
   TBranch        *b_pfjet_NCH;   //!
   TBranch        *b_pfjet_HFHAE;   //!
   TBranch        *b_pfjet_HFEME;   //!
   TBranch        *b_pfjet_NConstituents;   //!
   TBranch        *b_pujetIdFull_mva;   //!
   TBranch        *b_pujetIdSimple_mva;   //!
   TBranch        *b_pujetIdCutBased_mva;   //!
   TBranch        *b_pujetIdFull_loose;   //!
   TBranch        *b_pujetIdFull_medium;   //!
   TBranch        *b_pujetIdFull_tight;   //!
   TBranch        *b_pujetIdSimple_loose;   //!
   TBranch        *b_pujetIdSimple_medium;   //!
   TBranch        *b_pujetIdSimple_tight;   //!
   TBranch        *b_pujetIdCutBased_loose;   //!
   TBranch        *b_pujetIdCutBased_medium;   //!
   TBranch        *b_pujetIdCutBased_tight;   //!
   TBranch        *b_pfjet_TrackCountHiEffBJetTags;   //!
   TBranch        *b_pfjet_TrackCountHiPurBJetTags;   //!
   TBranch        *b_pfjet_SimpleSVHiEffBJetTags;   //!
   TBranch        *b_pfjet_SimpleSVHiPurBJetTags;   //!
   TBranch        *b_pfJet_jecUncer;   //!
   TBranch        *b_pfJet_jecCorr;   //!
   TBranch        *b_ucpfJet_px;   //!
   TBranch        *b_ucpfJet_py;   //!
   TBranch        *b_ucpfJet_E;   //!
   TBranch        *b_ucpfJet_pz;   //!
   TBranch        *b_ucpfJet_pt;   //!
   TBranch        *b_ucpfJet_eta;   //!
   TBranch        *b_ucpfJet_phi;   //!
   TBranch        *b_Electron_n;   //!
   TBranch        *b_Electron_px;   //!
   TBranch        *b_Electron_py;   //!
   TBranch        *b_Electron_pz;   //!
   TBranch        *b_Electron_vx;   //!
   TBranch        *b_Electron_vy;   //!
   TBranch        *b_Electron_vz;   //!
   TBranch        *b_Electron_pt;   //!
   TBranch        *b_Electron_eta;   //!
   TBranch        *b_Electron_phi;   //!
   TBranch        *b_Electron_energy;   //!
   TBranch        *b_Electron_charge;   //!
   TBranch        *b_Electron_trkIso;   //!
   TBranch        *b_Electron_ecalIso;   //!
   TBranch        *b_Electron_hcalIso;   //!
   TBranch        *b_Electron_SigmaIetaIeta;   //!
   TBranch        *b_Electron_dEtaIn;   //!
   TBranch        *b_Electron_dPhiIn;   //!
   TBranch        *b_Electron_HoE;   //!
   TBranch        *b_Electron_sc_energy;   //!
   TBranch        *b_Electron_sc_eta;   //!
   TBranch        *b_Electron_sc_phi;   //!
   TBranch        *b_Muon_n;   //!
   TBranch        *b_Muon_px;   //!
   TBranch        *b_Muon_py;   //!
   TBranch        *b_Muon_pz;   //!
   TBranch        *b_Muon_vx;   //!
   TBranch        *b_Muon_vy;   //!
   TBranch        *b_Muon_vz;   //!
   TBranch        *b_Muon_pt;   //!
   TBranch        *b_Muon_eta;   //!
   TBranch        *b_Muon_phi;   //!
   TBranch        *b_Muon_energy;   //!
   TBranch        *b_Muon_charge;   //!
   TBranch        *b_Muon_isGlobalMuon;   //!
   TBranch        *b_Muon_isTrackerMuon;   //!
   TBranch        *b_Muon_isStandAloneMuon;   //!
   TBranch        *b_Muon_InnerTrack_isNonnull;   //!
   TBranch        *b_Muon_OuterTrack_isNonnull;   //!
   TBranch        *b_Muon_OuterTrack_InnerPoint_x;   //!
   TBranch        *b_Muon_OuterTrack_InnerPoint_y;   //!
   TBranch        *b_Muon_OuterTrack_InnerPoint_z;   //!
   TBranch        *b_Muon_OuterTrack_InnerPoint_px;   //!
   TBranch        *b_Muon_OuterTrack_InnerPoint_py;   //!
   TBranch        *b_Muon_OuterTrack_InnerPoint_pz;   //!
   TBranch        *b_Muon_OuterTrack_OuterPoint_x;   //!
   TBranch        *b_Muon_OuterTrack_OuterPoint_y;   //!
   TBranch        *b_Muon_OuterTrack_OuterPoint_z;   //!
   TBranch        *b_Muon_OuterTrack_OuterPoint_px;   //!
   TBranch        *b_Muon_OuterTrack_OuterPoint_py;   //!
   TBranch        *b_Muon_OuterTrack_OuterPoint_pz;   //!
   TBranch        *b_Muon_InnerTrack_InnerPoint_x;   //!
   TBranch        *b_Muon_InnerTrack_InnerPoint_y;   //!
   TBranch        *b_Muon_InnerTrack_InnerPoint_z;   //!
   TBranch        *b_Muon_InnerTrack_InnerPoint_px;   //!
   TBranch        *b_Muon_InnerTrack_InnerPoint_py;   //!
   TBranch        *b_Muon_InnerTrack_InnerPoint_pz;   //!
   TBranch        *b_Muon_InnerTrack_OuterPoint_x;   //!
   TBranch        *b_Muon_InnerTrack_OuterPoint_y;   //!
   TBranch        *b_Muon_InnerTrack_OuterPoint_z;   //!
   TBranch        *b_Muon_InnerTrack_OuterPoint_px;   //!
   TBranch        *b_Muon_InnerTrack_OuterPoint_py;   //!
   TBranch        *b_Muon_InnerTrack_OuterPoint_pz;   //!
   TBranch        *b_Muon_trackIso;   //!
   TBranch        *b_Muon_ecalIso;   //!
   TBranch        *b_Muon_hcalIso;   //!
   TBranch        *b_Muon_relIso;   //!
   TBranch        *b_Muon_normChi2;   //!
   TBranch        *b_Muon_validHits;   //!
   TBranch        *b_Muon_tkHits;   //!
   TBranch        *b_Muon_pixHits;   //!
   TBranch        *b_Muon_numberOfMatches;   //!
   TBranch        *b_Muon_OuterPoint_x;   //!
   TBranch        *b_Muon_OuterPoint_y;   //!
   TBranch        *b_Muon_OuterPoint_z;   //!
   TBranch        *b_Muon_InnerPoint_x;   //!
   TBranch        *b_Muon_InnerPoint_y;   //!
   TBranch        *b_Muon_InnerPoint_z;   //!
   TBranch        *b_CosmicMuon_n;   //!
   TBranch        *b_CosmicMuon_px;   //!
   TBranch        *b_CosmicMuon_py;   //!
   TBranch        *b_CosmicMuon_pz;   //!
   TBranch        *b_CosmicMuon_pt;   //!
   TBranch        *b_CosmicMuon_eta;   //!
   TBranch        *b_CosmicMuon_phi;   //!
   TBranch        *b_CosmicMuon_energy;   //!
   TBranch        *b_CosmicMuon_charge;   //!
   TBranch        *b_CosmicMuon_isGlobalMuon;   //!
   TBranch        *b_CosmicMuon_isTrackerMuon;   //!
   TBranch        *b_CosmicMuon_isStandAloneMuon;   //!
   TBranch        *b_CosmicMuon_InnerTrack_isNonnull;   //!
   TBranch        *b_CosmicMuon_OuterTrack_isNonnull;   //!
   TBranch        *b_CosmicMuon_OuterTrack_InnerPoint_x;   //!
   TBranch        *b_CosmicMuon_OuterTrack_InnerPoint_y;   //!
   TBranch        *b_CosmicMuon_OuterTrack_InnerPoint_z;   //!
   TBranch        *b_CosmicMuon_OuterTrack_InnerPoint_px;   //!
   TBranch        *b_CosmicMuon_OuterTrack_InnerPoint_py;   //!
   TBranch        *b_CosmicMuon_OuterTrack_InnerPoint_pz;   //!
   TBranch        *b_CosmicMuon_OuterTrack_OuterPoint_x;   //!
   TBranch        *b_CosmicMuon_OuterTrack_OuterPoint_y;   //!
   TBranch        *b_CosmicMuon_OuterTrack_OuterPoint_z;   //!
   TBranch        *b_CosmicMuon_OuterTrack_OuterPoint_px;   //!
   TBranch        *b_CosmicMuon_OuterTrack_OuterPoint_py;   //!
   TBranch        *b_CosmicMuon_OuterTrack_OuterPoint_pz;   //!
   TBranch        *b_CosmicMuon_InnerTrack_InnerPoint_x;   //!
   TBranch        *b_CosmicMuon_InnerTrack_InnerPoint_y;   //!
   TBranch        *b_CosmicMuon_InnerTrack_InnerPoint_z;   //!
   TBranch        *b_CosmicMuon_InnerTrack_InnerPoint_px;   //!
   TBranch        *b_CosmicMuon_InnerTrack_InnerPoint_py;   //!
   TBranch        *b_CosmicMuon_InnerTrack_InnerPoint_pz;   //!
   TBranch        *b_CosmicMuon_InnerTrack_OuterPoint_x;   //!
   TBranch        *b_CosmicMuon_InnerTrack_OuterPoint_y;   //!
   TBranch        *b_CosmicMuon_InnerTrack_OuterPoint_z;   //!
   TBranch        *b_CosmicMuon_InnerTrack_OuterPoint_px;   //!
   TBranch        *b_CosmicMuon_InnerTrack_OuterPoint_py;   //!
   TBranch        *b_CosmicMuon_InnerTrack_OuterPoint_pz;   //!
   TBranch        *b_CosmicMuon_OuterPoint_x;   //!
   TBranch        *b_CosmicMuon_OuterPoint_y;   //!
   TBranch        *b_CosmicMuon_OuterPoint_z;   //!
   TBranch        *b_Tau_n;   //!
   TBranch        *b_Tau_px;   //!
   TBranch        *b_Tau_py;   //!
   TBranch        *b_Tau_pz;   //!
   TBranch        *b_Tau_vx;   //!
   TBranch        *b_Tau_vy;   //!
   TBranch        *b_Tau_vz;   //!
   TBranch        *b_Tau_pt;   //!
   TBranch        *b_Tau_eta;   //!
   TBranch        *b_Tau_phi;   //!
   TBranch        *b_Tau_energy;   //!
   TBranch        *b_Tau_charge;   //!
   TBranch        *b_genTauDecayMode1;   //!
   TBranch        *b_oneProng0Pi0;   //!
   TBranch        *b_oneProng1Pi0;   //!
   TBranch        *b_oneProng2Pi0;   //!
   TBranch        *b_threeProng0Pi0;   //!
   TBranch        *b_threeProng1Pi0;   //!
   TBranch        *b_tauelectron;   //!
   TBranch        *b_taumuon;   //!
   TBranch        *b_nthreeProng1Pi0;   //!
   TBranch        *b_ntauelectron;   //!
   TBranch        *b_ntaumuon;   //!
   TBranch        *b_genHadTauPt;   //!
   TBranch        *b_genHadTauEta;   //!
   TBranch        *b_genHadTauPhi;   //!
   TBranch        *b_nPions;   //!
   TBranch        *b_PionPdgId;   //!
   TBranch        *b_PionPt;   //!
   TBranch        *b_PionEta;   //!
   TBranch        *b_PionPhi;   //!
   TBranch        *b_nPi0;   //!
   TBranch        *b_Pi0PdgId;   //!
   TBranch        *b_Pi0Pt;   //!
   TBranch        *b_Pi0Eta;   //!
   TBranch        *b_Pi0Phi;   //!
   TBranch        *b_nPhotons;   //!
   TBranch        *b_PhotonPt;   //!
   TBranch        *b_PhotonEta;   //!
   TBranch        *b_PhotonPhi;   //!
   TBranch        *b_PhotonPdgId;   //!
   TBranch        *b_Photon_n;   //!
   TBranch        *b_Photon_E;   //!
   TBranch        *b_Photon_pt;   //!
   TBranch        *b_Photon_eta;   //!
   TBranch        *b_Photon_phi;   //!
   TBranch        *b_Photon_theta;   //!
   TBranch        *b_Photon_et;   //!
   TBranch        *b_Photon_swissCross;   //!
   TBranch        *b_Photon_e6e2;   //!
   TBranch        *b_Photon_e4e1;   //!
   TBranch        *b_Photonr9;   //!
   TBranch        *b_Photon_e1x5;   //!
   TBranch        *b_Photon_e2x5;   //!
   TBranch        *b_Photon_e3x3;   //!
   TBranch        *b_Photon_e5x5;   //!
   TBranch        *b_Photon_r1x5;   //!
   TBranch        *b_Photon_r2x5;   //!
   TBranch        *b_Photon_maxEnergyXtal;   //!
   TBranch        *b_Photon_SigmaEtaEta;   //!
   TBranch        *b_Photon_SigmaIetaIeta;   //!
   TBranch        *b_Photon_SigmaEtaPhi;   //!
   TBranch        *b_Photon_SigmaIetaIphi;   //!
   TBranch        *b_Photon_SigmaPhiPhi;   //!
   TBranch        *b_Photon_SigmaIphiIphi;   //!
   TBranch        *b_Photon_Roundness;   //!
   TBranch        *b_Photon_Angle;   //!
   TBranch        *b_Photon_ecalRecHitSumEtConeDR03;   //!
   TBranch        *b_Photon_hcalTowerSumEtConeDR03;   //!
   TBranch        *b_Photon_trkSumPtSolidConeDR03;   //!
   TBranch        *b_Photon_trkSumPtHollowConeDR03;   //!
   TBranch        *b_Photon_nTrkSolidConeDR03;   //!
   TBranch        *b_Photon_nTrkHollowConeDR03;   //!
   TBranch        *b_Photon_hcalDepth1TowerSumEtConeDR03;   //!
   TBranch        *b_Photon_hcalDepth2TowerSumEtConeDR03;   //!
   TBranch        *b_Photon_ecalRecHitSumEtConeDR04;   //!
   TBranch        *b_Photon_hcalTowerSumEtConeDR04;   //!
   TBranch        *b_Photon_trkSumPtSolidConeDR04;   //!
   TBranch        *b_Photon_trkSumPtHollowConeDR04;   //!
   TBranch        *b_Photon_nTrkSolidConeDR04;   //!
   TBranch        *b_Photon_nTrkHollowConeDR04;   //!
   TBranch        *b_Photon_hcalDepth1TowerSumEtConeDR04;   //!
   TBranch        *b_Photon_hcalDepth2TowerSumEtConeDR04;   //!
   TBranch        *b_Photon_hasPixelSeed;   //!
   TBranch        *b_Photon_isEB;   //!
   TBranch        *b_Photon_isEE;   //!
   TBranch        *b_Photon_isEBGap;   //!
   TBranch        *b_Photon_isEEGap;   //!
   TBranch        *b_Photon_isEBEEGap;   //!
   TBranch        *b_Photon_e2e9;   //!
   TBranch        *b_Photon_HoE;   //!
   TBranch        *b_Photon_HoEnew;   //!
   TBranch        *b_Photon_px;   //!
   TBranch        *b_Photon_py;   //!
   TBranch        *b_Photon_pz;   //!
   TBranch        *b_Photon_vx;   //!
   TBranch        *b_Photon_vy;   //!
   TBranch        *b_Photon_vz;   //!
   TBranch        *b_Photon_no_of_basic_clusters;   //!
   TBranch        *b_Photon_sc_energy;   //!
   TBranch        *b_Photon_sc_eta;   //!
   TBranch        *b_Photon_sc_phi;   //!
   TBranch        *b_Photon_sc_x;   //!
   TBranch        *b_Photon_sc_y;   //!
   TBranch        *b_Photon_sc_z;   //!
   TBranch        *b_Photon_etaWidth;   //!
   TBranch        *b_Photon_phiWidth;   //!
   TBranch        *b_Photon_sc_et;   //!
   TBranch        *b_matchphotonE;   //!
   TBranch        *b_matchphotonpt;   //!
   TBranch        *b_matchphotoneta;   //!
   TBranch        *b_matchphotonphi;   //!
   TBranch        *b_matchphotonpx;   //!
   TBranch        *b_matchphotonpy;   //!
   TBranch        *b_matchphotonpz;   //!
   TBranch        *b_ismatchedphoton;   //!
   TBranch        *b_Photon_hasConvTrk;   //!
   TBranch        *b_Photon_ntracks;   //!
   TBranch        *b_Photon_isconverted;   //!
   TBranch        *b_Photon_pairInvmass;   //!
   TBranch        *b_Photon_pairCotThetaSeperation;   //!
   TBranch        *b_Photon_pairmomentumX;   //!
   TBranch        *b_Photon_pairmomentumY;   //!
   TBranch        *b_Photon_pairmomentumZ;   //!
   TBranch        *b_Photon_EoverP;   //!
   TBranch        *b_Photon_ConvVx;   //!
   TBranch        *b_Photon_ConvVy;   //!
   TBranch        *b_Photon_ConvVz;   //!
   TBranch        *b_Photon_ZOfPrimaryVertex;   //!
   TBranch        *b_Photon_distOfMinimumApproach;   //!
   TBranch        *b_Photon_dPhiTracksAtVtx;   //!
   TBranch        *b_Photon_dPhiTracksAtEcal;   //!
   TBranch        *b_Photon_dEtaTracksAtEcal;   //!
   TBranch        *b_npho_;   //!
   TBranch        *b_Photon_Electronveto;   //!
   TBranch        *b_PFiso_Charged03;   //!
   TBranch        *b_PFiso_Photon03;   //!
   TBranch        *b_PFiso_Neutral03;   //!
   TBranch        *b_PFiso_Sum03;   //!
   TBranch        *b_PFWorstiso_Charged03;  
   TBranch        *b_Photon_ncrys;   //!
   TBranch        *b_Photon_timing_xtal;   //!
   TBranch        *b_Photon_timingavg_xtal;   //!
   TBranch        *b_Photon_energy_xtal;   //!
   TBranch        *b_Photon_ieta_xtalEB;   //!
   TBranch        *b_Photon_iphi_xtalEB;   //!
   TBranch        *b_Photon_recoFlag_xtalEB;   //!
   TBranch        *b_Photon_timeError_xtal;   //!
   TBranch        *b_Photon_s9;   //!
   TBranch        *b_HERecHit_subset_n;   //!
   TBranch        *b_HERecHit_subset_detid;   //!
   TBranch        *b_HERecHit_subset_energy;   //!
   TBranch        *b_HERecHit_subset_time;   //!
   TBranch        *b_HERecHit_subset_depth;   //!
   TBranch        *b_HERecHit_subset_phi;   //!
   TBranch        *b_HERecHit_subset_eta;   //!
   TBranch        *b_HERecHit_subset_x;   //!
   TBranch        *b_HERecHit_subset_y;   //!
   TBranch        *b_HERecHit_subset_z;   //!
   TBranch        *b_Photon_mipChi2;   //!
   TBranch        *b_Photon_mipTotEnergy;   //!
   TBranch        *b_Photon_mipSlope;   //!
   TBranch        *b_Photon_mipIntercept;   //!
   TBranch        *b_Photon_mipNhitCone;   //!
   TBranch        *b_Photon_mipIsHalo;   //!
   TBranch        *b_EBRecHit_size;   //!
   TBranch        *b_EBRecHit_eta;   //!
   TBranch        *b_EBRecHit_phi;   //!
   TBranch        *b_EBRecHit_ieta;   //!
   TBranch        *b_EBRecHit_iphi;   //!
   TBranch        *b_EBRecHit_e;   //!
   TBranch        *b_EBRecHit_et;   //!
   TBranch        *b_EBRecHit_flag;   //!
   TBranch        *b_EBRecHit_time;   //!
   TBranch        *b_EERecHit_size;   //!
   TBranch        *b_EERecHit_eta;   //!
   TBranch        *b_EERecHit_phi;   //!
   TBranch        *b_EERecHit_ieta;   //!
   TBranch        *b_EERecHit_iphi;   //!
   TBranch        *b_EERecHit_e;   //!
   TBranch        *b_EERecHit_et;   //!
   TBranch        *b_EERecHit_flag;   //!
   TBranch        *b_EERecHit_time;   //!
   TBranch        *b_isBeamHaloGlobalLoosePass;   //!
   TBranch        *b_isBeamHaloGloablTightPass;   //!
   TBranch        *b_isBeamHaloHcalLoosePass;   //!
   TBranch        *b_isBeamHaloHcalTightPass;   //!
   TBranch        *b_isBeamHaloCSCLoosePass;   //!
   TBranch        *b_isBeamHaloCSCTightPass;   //!
   TBranch        *b_isBeamHaloEcalLoosePass;   //!
   TBranch        *b_isBeamHaloEcalTightPass;   //!
   TBranch        *b_isBeamHaloIDTightPass;   //!
   TBranch        *b_isBeamHaloIDLoosePass;   //!
   TBranch        *b_isSmellsLikeHalo_Tag;   //!
   TBranch        *b_isLooseHalo_Tag;   //!
   TBranch        *b_isTightHalo_Tag;   //!
   TBranch        *b_isExtremeTightHalo_Tag;   //!
   TBranch        *b_CaloMetSig;   //!
   TBranch        *b_CaloMetEz;   //!
   TBranch        *b_CaloEtFractionHadronic;   //!
   TBranch        *b_CaloEmEtFraction;   //!
   TBranch        *b_CaloHadEtInHB;   //!
   TBranch        *b_CaloHadEtInHE;   //!
   TBranch        *b_CaloHadEtInHO;   //!
   TBranch        *b_CaloHadEtInHF;   //!
   TBranch        *b_CaloEmEtInEB;   //!
   TBranch        *b_CaloEmEtInEE;   //!
   TBranch        *b_CaloEmEtInHF;   //!
   TBranch        *b_CaloMaxEtInEmTowers;   //!
   TBranch        *b_CaloMaxEtInHadTowers;   //!
   TBranch        *b_CaloMetPt;   //!
   TBranch        *b_CaloMetPx;   //!
   TBranch        *b_CaloMetPy;   //!
   TBranch        *b_CaloMetPhi;   //!
   TBranch        *b_CaloMetSumEt;   //!
   TBranch        *b_Delta_phi;   //!
   TBranch        *b_PFMetPt;   //!
   TBranch        *b_PFMetPx;   //!
   TBranch        *b_PFMetPy;   //!
   TBranch        *b_PFMetPhi;   //!
   TBranch        *b_PFMetSumEt;   //!
   TBranch        *b_Delta_phiPF;   //!
   TBranch        *b_TCMetPt;   //!
   TBranch        *b_TCMetPx;   //!
   TBranch        *b_TCMetPy;   //!
   TBranch        *b_TCMetPhi;   //!
   TBranch        *b_TCMetSumEt;   //!
   TBranch        *b_Delta_phiTC;   //!
   TBranch        *b_ucPhoton_n;   //!
   TBranch        *b_ucPhoton_E;   //!
   TBranch        *b_ucPhoton_pt;   //!
   TBranch        *b_ucPhoton_eta;   //!
   TBranch        *b_ucPhoton_phi;   //!
   TBranch        *b_ucPhoton_theta;   //!
   TBranch        *b_ucPhoton_et;   //!
   TBranch        *b_ucPhoton_swissCross;   //!
   TBranch        *b_ucPhoton_e6e2;   //!
   TBranch        *b_ucPhoton_e4e1;   //!
   TBranch        *b_ucPhotonr9;   //!
   TBranch        *b_ucPhoton_e1x5;   //!
   TBranch        *b_ucPhoton_e2x5;   //!
   TBranch        *b_ucPhoton_e3x3;   //!
   TBranch        *b_ucPhoton_e5x5;   //!
   TBranch        *b_ucPhoton_r1x5;   //!
   TBranch        *b_ucPhoton_r2x5;   //!
   TBranch        *b_ucPhoton_maxEnergyXtal;   //!
   TBranch        *b_ucPhoton_SigmaEtaEta;   //!
   TBranch        *b_ucPhoton_SigmaIetaIeta;   //!
   TBranch        *b_ucPhoton_SigmaEtaPhi;   //!
   TBranch        *b_ucPhoton_SigmaIetaIphi;   //!
   TBranch        *b_ucPhoton_SigmaPhiPhi;   //!
   TBranch        *b_ucPhoton_SigmaIphiIphi;   //!
   TBranch        *b_ucPhoton_Roundness;   //!
   TBranch        *b_ucPhoton_Angle;   //!
   TBranch        *b_ucPhoton_ecalRecHitSumEtConeDR03;   //!
   TBranch        *b_ucPhoton_hcalTowerSumEtConeDR03;   //!
   TBranch        *b_ucPhoton_trkSumPtSolidConeDR03;   //!
   TBranch        *b_ucPhoton_trkSumPtHollowConeDR03;   //!
   TBranch        *b_ucPhoton_nTrkSolidConeDR03;   //!
   TBranch        *b_ucPhoton_nTrkHollowConeDR03;   //!
   TBranch        *b_ucPhoton_hcalDepth1TowerSumEtConeDR03;   //!
   TBranch        *b_ucPhoton_hcalDepth2TowerSumEtConeDR03;   //!
   TBranch        *b_ucPhoton_ecalRecHitSumEtConeDR04;   //!
   TBranch        *b_ucPhoton_hcalTowerSumEtConeDR04;   //!
   TBranch        *b_ucPhoton_trkSumPtSolidConeDR04;   //!
   TBranch        *b_ucPhoton_trkSumPtHollowConeDR04;   //!
   TBranch        *b_ucPhoton_nTrkSolidConeDR04;   //!
   TBranch        *b_ucPhoton_nTrkHollowConeDR04;   //!
   TBranch        *b_ucPhoton_hcalDepth1TowerSumEtConeDR04;   //!
   TBranch        *b_ucPhoton_hcalDepth2TowerSumEtConeDR04;   //!
   TBranch        *b_ucPhoton_hasPixelSeed;   //!
   TBranch        *b_ucPhoton_isEB;   //!
   TBranch        *b_ucPhoton_isEE;   //!
   TBranch        *b_ucPhoton_isEBGap;   //!
   TBranch        *b_ucPhoton_isEEGap;   //!
   TBranch        *b_ucPhoton_isEBEEGap;   //!
   TBranch        *b_ucPhoton_e2e9;   //!
   TBranch        *b_ucPhoton_HoE;   //!
   TBranch        *b_ucPhoton_HoEnew;   //!
   TBranch        *b_ucPhoton_px;   //!
   TBranch        *b_ucPhoton_py;   //!
   TBranch        *b_ucPhoton_pz;   //!
   TBranch        *b_ucPhoton_vx;   //!
   TBranch        *b_ucPhoton_vy;   //!
   TBranch        *b_ucPhoton_vz;   //!
   TBranch        *b_ucPhoton_no_of_basic_clusters;   //!
   TBranch        *b_ucPhoton_sc_energy;   //!
   TBranch        *b_ucPhoton_sc_eta;   //!
   TBranch        *b_ucPhoton_sc_phi;   //!
   TBranch        *b_ucPhoton_sc_x;   //!
   TBranch        *b_ucPhoton_sc_y;   //!
   TBranch        *b_ucPhoton_sc_z;   //!
   TBranch        *b_ucPhoton_etaWidth;   //!
   TBranch        *b_ucPhoton_phiWidth;   //!
   TBranch        *b_ucPhoton_sc_et;   //!
   TBranch        *b_matchucphotonE;   //!
   TBranch        *b_matchucphotonpt;   //!
   TBranch        *b_matchucphotoneta;   //!
   TBranch        *b_matchucphotonphi;   //!
   TBranch        *b_matchucphotonpx;   //!
   TBranch        *b_matchucphotonpy;   //!
   TBranch        *b_matchucphotonpz;   //!
   TBranch        *b_ismatcheducphoton;   //!
   TBranch        *b_ucPhoton_hasConvTrk;   //!
   TBranch        *b_ucPhoton_ntracks;   //!
   TBranch        *b_ucPhoton_isconverted;   //!
   TBranch        *b_ucPhoton_pairInvmass;   //!
   TBranch        *b_ucPhoton_pairCotThetaSeperation;   //!
   TBranch        *b_ucPhoton_pairmomentumX;   //!
   TBranch        *b_ucPhoton_pairmomentumY;   //!
   TBranch        *b_ucPhoton_pairmomentumZ;   //!
   TBranch        *b_ucPhoton_EoverP;   //!
   TBranch        *b_ucPhoton_ConvVx;   //!
   TBranch        *b_ucPhoton_ConvVy;   //!
   TBranch        *b_ucPhoton_ConvVz;   //!
   TBranch        *b_ucPhoton_ZOfPrimaryVertex;   //!
   TBranch        *b_ucPhoton_distOfMinimumApproach;   //!
   TBranch        *b_ucPhoton_dPhiTracksAtVtx;   //!
   TBranch        *b_ucPhoton_dPhiTracksAtEcal;   //!
   TBranch        *b_ucPhoton_dEtaTracksAtEcal;   //!
   TBranch        *b_ucPhoton_ncrys;   //!
   TBranch        *b_ucPhoton_timing_xtal;   //!
   TBranch        *b_ucPhoton_timingavg_xtal;   //!
   TBranch        *b_ucPhoton_energy_xtal;   //!
   TBranch        *b_ucPhoton_ieta_xtalEB;   //!
   TBranch        *b_ucPhoton_iphi_xtalEB;   //!
   TBranch        *b_ucPhoton_recoFlag_xtalEB;   //!
   TBranch        *b_ucPhoton_timeError_xtal;   //!
   TBranch        *b_ucPhoton_s9;   //!
   TBranch        *b_ucHERecHit_subset_n;   //!
   TBranch        *b_ucHERecHit_subset_detid;   //!
   TBranch        *b_ucHERecHit_subset_energy;   //!
   TBranch        *b_ucHERecHit_subset_time;   //!
   TBranch        *b_ucHERecHit_subset_depth;   //!
   TBranch        *b_ucHERecHit_subset_phi;   //!
   TBranch        *b_ucHERecHit_subset_eta;   //!
   TBranch        *b_ucHERecHit_subset_x;   //!
   TBranch        *b_ucHERecHit_subset_y;   //!
   TBranch        *b_ucHERecHit_subset_z;   //!
   TBranch        *b_ucPhoton_mipChi2;   //!
   TBranch        *b_ucPhoton_mipTotEnergy;   //!
   TBranch        *b_ucPhoton_mipSlope;   //!
   TBranch        *b_ucPhoton_mipIntercept;   //!
   TBranch        *b_ucPhoton_mipNhitCone;   //!
   TBranch        *b_ucPhoton_mipIsHalo;   //!
   TBranch        *b_CaloTower_n;   //!
   TBranch        *b_CaloTower_eta;   //!
   TBranch        *b_CaloTower_phi;   //!
   TBranch        *b_CaloTower_E;   //!
   TBranch        *b_CaloTower_Et;   //!
   TBranch        *b_CaloTower_emEnergy;   //!
   TBranch        *b_CaloTower_hadEnergy;   //!
   TBranch        *b_CaloTower_p;   //!
   TBranch        *b_CaloTower_EMEt;   //!
   TBranch        *b_CaloTower_HadEt;   //!
   TBranch        *b_CaloTower_HadPhi;   //!
   TBranch        *b_CaloTower_HadEta;   //!
   TBranch        *b_CaloTower_EMPhi;   //!
   TBranch        *b_CaloTower_EMEta;   //!
   TBranch        *b_CaloTower_HadX;   //!
   TBranch        *b_CaloTower_HadY;   //!
   TBranch        *b_CaloTower_HadZ;   //!
   TBranch        *b_CaloTower_HE_E;   //!
   TBranch        *b_CaloTower_HB_E;   //!
   TBranch        *b_CaloTower_EMTime;   //!
   TBranch        *b_CaloTower_HadTime;   //!
   TBranch        *b_rho;   //!
   TBranch        *b_sigma;   //!
   TBranch        *b_rho25;   //!
   TBranch        *b_sigma25;   //!

   myPlot();
   virtual ~myPlot();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   //my functions

   bool passHlt(string &TriggerName, int &TriggerIndex);
   bool triggerMatch(std::string triggerName,
                                int triggerIndex,       //index of the trigger
                                  vector<std::string> filterName,  //name if the filter  say "hltPhoton150HEFilter"
                                    int phoIndex,            //offline photon index
                                    float maxDeltaRCut);
   bool passVtx(int &nvtx);
   bool notSpike(int ipho); 
   bool passPFTightPhoID(int i);
   bool passLoosePFPhoID(int i);
   bool passMediumPFPhoID(int i);
   bool denoPFPhoID(int i);
   bool templateSignalID(int i, std::string idType);
   bool templateQCDID(int i, std::string idType);
   double computeLICTD(int i);
   bool GetRightVtxIso(int PC,double &value, double &newETA, int &vtx);
   double EAElectroncharged(double eta,string dataType);
   double EAElectronneutral(double eta,string dataType);
   double EAElectronphoton(double eta,string dataType);
   double EAPFWorstElectroncharged(double eta);
   double  DeltaR(double eta1, double eta2, double phi1, double phi2);  

   vector<std::string> HLTPhotonTrigger;
   vector<std::string> hltFilterNames;

  bool passEXOTightPhoID(int i); 
  bool passEXOLoosePhoID(int i);
  bool denoEXOPhoID(int i); 
  bool templateEXOSignalID(int i);
  bool templateEXOQCDID(int i);

  bool noCosmic(int PC);
  bool jetVeto(int PC);
  bool trkVeto(int PC);
  double getFakeRate(int qc);
  double getDPhi(double phi1,double phi2); 
  double FakeRatePt(double x); 
 

};

#endif

#ifdef myPlot_cxx                 
myPlot::myPlot()                  
{                                 
                                  
TChain *chain = new TChain("myEvent");
                                  
          //add input files here  
          ifstream datafile;      
          datafile.open("2012Data_CommonSkim_dataset.txt", ifstream::in );
          char datafilename[200]; 
                                  
                                  
     for(int i=1; i<= 20 && i<= 20; i++){
            datafile >> datafilename;
            string fname(datafilename);
            string location = "dcap://cmsgridftp.fnal.gov:24125/pnfs/fnal.gov/usr/cms/WAX/11/store/user/lpcgg/weinberg/ntuples/";                                                                                                                                
            if(i >= 1 && i <= 20){

            string nameFile = fname;
            string string_search (".root");
            size_t found =nameFile.find(string_search);                                                                                                 
           
         if(found != string::npos){
                                    chain->Add((location+fname).c_str());
                                    cout<<chain->GetEntries()<<"  file= "<<((location+fname).c_str())<<endl;      
                                 }

                                                                                                                              
               }                  
          }                       
                                  
                                  
  Init(chain);                    
}                   




myPlot::~myPlot()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t myPlot::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t myPlot::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void myPlot::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   triggernames = 0;
   triggerprescales = 0;
   ifTriggerpassed = 0;
   ObjectPt = 0;
   ObjectEta = 0;
   ObjectPhi = 0;
   FilterNames = 0;
   FilterStartPosition = 0;
   FilterEndPosition = 0;
   ObjectStartPosition = 0;
   ObjectEndPosition = 0;
   genTauDecayMode1 = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("nevents", &nevents, &b_nevents);
   fChain->SetBranchAddress("run", &run, &b_RunNumber);
   fChain->SetBranchAddress("event", &event, &b_EventNumber);
   fChain->SetBranchAddress("luminosityBlock", &luminosityBlock, &b_LumiNumber);
   fChain->SetBranchAddress("beamCrossing", &beamCrossing, &b_BXNumber);
   fChain->SetBranchAddress("totalIntensityBeam1", &totalIntensityBeam1, &b_totalIntensityBeam1);
   fChain->SetBranchAddress("totalIntensityBeam2", &totalIntensityBeam2, &b_totalIntensityBeam2);
   fChain->SetBranchAddress("avgInsDelLumi", &avgInsDelLumi, &b_avgInsDelLumi);
   fChain->SetBranchAddress("avgInsDelLumiErr", &avgInsDelLumiErr, &b_avgInsDelLumiErr);
   fChain->SetBranchAddress("avgInsRecLumi", &avgInsRecLumi, &b_avgInsRecLumi);
   fChain->SetBranchAddress("avgInsRecLumiErr", &avgInsRecLumiErr, &b_avgInsRecLumiErr);
   fChain->SetBranchAddress("ntriggers", &ntriggers, &b_ntriggers);
   fChain->SetBranchAddress("triggernames", &triggernames, &b_triggernames);
   fChain->SetBranchAddress("triggerprescales", &triggerprescales, &b_triggerprescales);
   fChain->SetBranchAddress("ifTriggerpassed", &ifTriggerpassed, &b_ifTriggerpassed);
   fChain->SetBranchAddress("ObjectPt", &ObjectPt, &b_ObjectPt);
   fChain->SetBranchAddress("ObjectEta", &ObjectEta, &b_ObjectEta);
   fChain->SetBranchAddress("ObjectPhi", &ObjectPhi, &b_ObjectPhi);
   fChain->SetBranchAddress("FilterNames", &FilterNames, &b_FilterNames);
   fChain->SetBranchAddress("FilterStartPosition", &FilterStartPosition, &b_FilterStartPosition);
   fChain->SetBranchAddress("FilterEndPosition", &FilterEndPosition, &b_FilterEndPosition);
   fChain->SetBranchAddress("ObjectStartPosition", &ObjectStartPosition, &b_ObjectStartPosition);
   fChain->SetBranchAddress("ObjectEndPosition", &ObjectEndPosition, &b_ObjectEndPosition);
   fChain->SetBranchAddress("Vertex_n", &Vertex_n, &b_Vertex_n);
   fChain->SetBranchAddress("Vertex_x", Vertex_x, &b_Vertex_x);
   fChain->SetBranchAddress("Vertex_y", Vertex_y, &b_Vertex_y);
   fChain->SetBranchAddress("Vertex_z", Vertex_z, &b_Vertex_z);
   fChain->SetBranchAddress("Vertex_tracksize", Vertex_tracksize, &b_Vertex_tracksize);
   fChain->SetBranchAddress("Vertex_ndof", Vertex_ndof, &b_Vertex_ndof);
   fChain->SetBranchAddress("Vertex_chi2", Vertex_chi2, &b_Vertex_chi2);
   fChain->SetBranchAddress("Vertex_d0", Vertex_d0, &b_Vertex_d0);
   fChain->SetBranchAddress("Vertex_isFake", Vertex_isFake, &b_Vertex_isFake);
   fChain->SetBranchAddress("Scraping_isScrapingEvent", &Scraping_isScrapingEvent, &b_Scraping_isScrapingEvent);
   fChain->SetBranchAddress("Scraping_numOfTracks", &Scraping_numOfTracks, &b_Scraping_numOfTracks);
   fChain->SetBranchAddress("Scraping_fractionOfGoodTracks", &Scraping_fractionOfGoodTracks, &b_Scraping_fractionOfGoodTracks);
   fChain->SetBranchAddress("Track_n", &Track_n, &b_Track_n);
   fChain->SetBranchAddress("Track_px", Track_px, &b_Track_px);
   fChain->SetBranchAddress("Track_py", Track_py, &b_Track_py);
   fChain->SetBranchAddress("Track_pz", Track_pz, &b_Track_pz);
   fChain->SetBranchAddress("Track_vx", Track_vx, &b_Track_vx);
   fChain->SetBranchAddress("Track_vy", Track_vy, &b_Track_vy);
   fChain->SetBranchAddress("Track_vz", Track_vz, &b_Track_vz);
   fChain->SetBranchAddress("Track_pt", Track_pt, &b_Track_pt);
   fChain->SetBranchAddress("Track_eta", Track_eta, &b_Track_eta);
   fChain->SetBranchAddress("Track_phi", Track_phi, &b_Track_phi);
   fChain->SetBranchAddress("Jet_n", &Jet_n, &b_Jet_n);
   fChain->SetBranchAddress("Jet_px", Jet_px, &b_Jet_px);
   fChain->SetBranchAddress("Jet_py", Jet_py, &b_Jet_py);
   fChain->SetBranchAddress("Jet_E", Jet_E, &b_Jet_E);
   fChain->SetBranchAddress("Jet_pz", Jet_pz, &b_Jet_pz);
   fChain->SetBranchAddress("Jet_vx", Jet_vx, &b_Jet_vx);
   fChain->SetBranchAddress("Jet_vy", Jet_vy, &b_Jet_vy);
   fChain->SetBranchAddress("Jet_vz", Jet_vz, &b_Jet_vz);
   fChain->SetBranchAddress("Jet_pt", Jet_pt, &b_Jet_pt);
   fChain->SetBranchAddress("Jet_eta", Jet_eta, &b_Jet_eta);
   fChain->SetBranchAddress("Jet_phi", Jet_phi, &b_Jet_phi);
   fChain->SetBranchAddress("Jet_emEnergyFraction", Jet_emEnergyFraction, &b_Jet_emEnergyFraction);
   fChain->SetBranchAddress("Jet_energyFractionHadronic", Jet_energyFractionHadronic, &b_Jet_energyFractionHadronic);
   fChain->SetBranchAddress("Jet_hitsInN90", Jet_hitsInN90, &b_Jet_hitsInN90);
   fChain->SetBranchAddress("Jet_n90Hits", Jet_n90Hits, &b_Jet_n90Hits);
   fChain->SetBranchAddress("Jet_nTowers", Jet_nTowers, &b_Jet_nTowers);
   fChain->SetBranchAddress("Jet_fHPD", Jet_fHPD, &b_Jet_fHPD);
   fChain->SetBranchAddress("Jet_fRBX", Jet_fRBX, &b_Jet_fRBX);
   fChain->SetBranchAddress("Jet_RHF", Jet_RHF, &b_Jet_RHF);
   fChain->SetBranchAddress("Jet_jecUncer", Jet_jecUncer, &b_Jet_jecUncer);
   fChain->SetBranchAddress("Jet_jecCorr", Jet_jecCorr, &b_Jet_jecCorr);
   fChain->SetBranchAddress("ucJet_px", ucJet_px, &b_ucJet_px);
   fChain->SetBranchAddress("ucJet_py", ucJet_py, &b_ucJet_py);
   fChain->SetBranchAddress("ucJet_E", ucJet_E, &b_ucJet_E);
   fChain->SetBranchAddress("ucJet_pz", ucJet_pz, &b_ucJet_pz);
   fChain->SetBranchAddress("ucJet_pt", ucJet_pt, &b_ucJet_pt);
   fChain->SetBranchAddress("ucJet_eta", ucJet_eta, &b_ucJet_eta);
   fChain->SetBranchAddress("ucJet_phi", ucJet_phi, &b_ucJet_phi);
   fChain->SetBranchAddress("pfJet_n", &pfJet_n, &b_pfJet_n);
   fChain->SetBranchAddress("pfJet_px", pfJet_px, &b_pfJet_px);
   fChain->SetBranchAddress("pfJet_py", pfJet_py, &b_pfJet_py);
   fChain->SetBranchAddress("pfJet_E", pfJet_E, &b_pfJet_E);
   fChain->SetBranchAddress("pfJet_pz", pfJet_pz, &b_pfJet_pz);
   fChain->SetBranchAddress("pfJet_vx", pfJet_vx, &b_pfJet_vx);
   fChain->SetBranchAddress("pfJet_vy", pfJet_vy, &b_pfJet_vy);
   fChain->SetBranchAddress("pfJet_vz", pfJet_vz, &b_pfJet_vz);
   fChain->SetBranchAddress("pfJet_pt", pfJet_pt, &b_pfJet_pt);
   fChain->SetBranchAddress("pfJet_eta", pfJet_eta, &b_pfJet_eta);
   fChain->SetBranchAddress("pfJet_phi", pfJet_phi, &b_pfJet_phi);
   fChain->SetBranchAddress("pfjet_CEF", pfjet_CEF, &b_pfjet_CEF);
   fChain->SetBranchAddress("pfjet_CHF", pfjet_CHF, &b_pfjet_CHF);
   fChain->SetBranchAddress("pfjet_NEF", pfjet_NEF, &b_pfjet_NEF);
   fChain->SetBranchAddress("pfjet_NHF", pfjet_NHF, &b_pfjet_NHF);
   fChain->SetBranchAddress("pfjet_NCH", pfjet_NCH, &b_pfjet_NCH);
   fChain->SetBranchAddress("pfjet_HFHAE", pfjet_HFHAE, &b_pfjet_HFHAE);
   fChain->SetBranchAddress("pfjet_HFEME", pfjet_HFEME, &b_pfjet_HFEME);
   fChain->SetBranchAddress("pfjet_NConstituents", pfjet_NConstituents, &b_pfjet_NConstituents);
   fChain->SetBranchAddress("pujetIdFull_mva", pujetIdFull_mva, &b_pujetIdFull_mva);
   fChain->SetBranchAddress("pujetIdSimple_mva", pujetIdSimple_mva, &b_pujetIdSimple_mva);
   fChain->SetBranchAddress("pujetIdCutBased_mva", pujetIdCutBased_mva, &b_pujetIdCutBased_mva);
   fChain->SetBranchAddress("pujetIdFull_loose", pujetIdFull_loose, &b_pujetIdFull_loose);
   fChain->SetBranchAddress("pujetIdFull_medium", pujetIdFull_medium, &b_pujetIdFull_medium);
   fChain->SetBranchAddress("pujetIdFull_tight", pujetIdFull_tight, &b_pujetIdFull_tight);
   fChain->SetBranchAddress("pujetIdSimple_loose", pujetIdSimple_loose, &b_pujetIdSimple_loose);
   fChain->SetBranchAddress("pujetIdSimple_medium", pujetIdSimple_medium, &b_pujetIdSimple_medium);
   fChain->SetBranchAddress("pujetIdSimple_tight", pujetIdSimple_tight, &b_pujetIdSimple_tight);
   fChain->SetBranchAddress("pujetIdCutBased_loose", pujetIdCutBased_loose, &b_pujetIdCutBased_loose);
   fChain->SetBranchAddress("pujetIdCutBased_medium", pujetIdCutBased_medium, &b_pujetIdCutBased_medium);
   fChain->SetBranchAddress("pujetIdCutBased_tight", pujetIdCutBased_tight, &b_pujetIdCutBased_tight);
   fChain->SetBranchAddress("pfjet_TrackCountHiEffBJetTags", pfjet_TrackCountHiEffBJetTags, &b_pfjet_TrackCountHiEffBJetTags);
   fChain->SetBranchAddress("pfjet_TrackCountHiPurBJetTags", pfjet_TrackCountHiPurBJetTags, &b_pfjet_TrackCountHiPurBJetTags);
   fChain->SetBranchAddress("pfjet_SimpleSVHiEffBJetTags", pfjet_SimpleSVHiEffBJetTags, &b_pfjet_SimpleSVHiEffBJetTags);
   fChain->SetBranchAddress("pfjet_SimpleSVHiPurBJetTags", pfjet_SimpleSVHiPurBJetTags, &b_pfjet_SimpleSVHiPurBJetTags);
   fChain->SetBranchAddress("pfJet_jecUncer", pfJet_jecUncer, &b_pfJet_jecUncer);
   fChain->SetBranchAddress("pfJet_jecCorr", pfJet_jecCorr, &b_pfJet_jecCorr);
   fChain->SetBranchAddress("ucpfJet_px", ucpfJet_px, &b_ucpfJet_px);
   fChain->SetBranchAddress("ucpfJet_py", ucpfJet_py, &b_ucpfJet_py);
   fChain->SetBranchAddress("ucpfJet_E", ucpfJet_E, &b_ucpfJet_E);
   fChain->SetBranchAddress("ucpfJet_pz", ucpfJet_pz, &b_ucpfJet_pz);
   fChain->SetBranchAddress("ucpfJet_pt", ucpfJet_pt, &b_ucpfJet_pt);
   fChain->SetBranchAddress("ucpfJet_eta", ucpfJet_eta, &b_ucpfJet_eta);
   fChain->SetBranchAddress("ucpfJet_phi", ucpfJet_phi, &b_ucpfJet_phi);
   fChain->SetBranchAddress("Electron_n", &Electron_n, &b_Electron_n);
   fChain->SetBranchAddress("Electron_px", Electron_px, &b_Electron_px);
   fChain->SetBranchAddress("Electron_py", Electron_py, &b_Electron_py);
   fChain->SetBranchAddress("Electron_pz", Electron_pz, &b_Electron_pz);
   fChain->SetBranchAddress("Electron_vx", Electron_vx, &b_Electron_vx);
   fChain->SetBranchAddress("Electron_vy", Electron_vy, &b_Electron_vy);
   fChain->SetBranchAddress("Electron_vz", Electron_vz, &b_Electron_vz);
   fChain->SetBranchAddress("Electron_pt", Electron_pt, &b_Electron_pt);
   fChain->SetBranchAddress("Electron_eta", Electron_eta, &b_Electron_eta);
   fChain->SetBranchAddress("Electron_phi", Electron_phi, &b_Electron_phi);
   fChain->SetBranchAddress("Electron_energy", Electron_energy, &b_Electron_energy);
   fChain->SetBranchAddress("Electron_charge", Electron_charge, &b_Electron_charge);
   fChain->SetBranchAddress("Electron_trkIso", Electron_trkIso, &b_Electron_trkIso);
   fChain->SetBranchAddress("Electron_ecalIso", Electron_ecalIso, &b_Electron_ecalIso);
   fChain->SetBranchAddress("Electron_hcalIso", Electron_hcalIso, &b_Electron_hcalIso);
   fChain->SetBranchAddress("Electron_SigmaIetaIeta", Electron_SigmaIetaIeta, &b_Electron_SigmaIetaIeta);
   fChain->SetBranchAddress("Electron_dEtaIn", Electron_dEtaIn, &b_Electron_dEtaIn);
   fChain->SetBranchAddress("Electron_dPhiIn", Electron_dPhiIn, &b_Electron_dPhiIn);
   fChain->SetBranchAddress("Electron_HoE", Electron_HoE, &b_Electron_HoE);
   fChain->SetBranchAddress("Electron_sc_energy", Electron_sc_energy, &b_Electron_sc_energy);
   fChain->SetBranchAddress("Electron_sc_eta", Electron_sc_eta, &b_Electron_sc_eta);
   fChain->SetBranchAddress("Electron_sc_phi", Electron_sc_phi, &b_Electron_sc_phi);
   fChain->SetBranchAddress("Muon_n", &Muon_n, &b_Muon_n);
   fChain->SetBranchAddress("Muon_px", Muon_px, &b_Muon_px);
   fChain->SetBranchAddress("Muon_py", Muon_py, &b_Muon_py);
   fChain->SetBranchAddress("Muon_pz", Muon_pz, &b_Muon_pz);
   fChain->SetBranchAddress("Muon_vx", Muon_vx, &b_Muon_vx);
   fChain->SetBranchAddress("Muon_vy", Muon_vy, &b_Muon_vy);
   fChain->SetBranchAddress("Muon_vz", Muon_vz, &b_Muon_vz);
   fChain->SetBranchAddress("Muon_pt", Muon_pt, &b_Muon_pt);
   fChain->SetBranchAddress("Muon_eta", Muon_eta, &b_Muon_eta);
   fChain->SetBranchAddress("Muon_phi", Muon_phi, &b_Muon_phi);
   fChain->SetBranchAddress("Muon_energy", Muon_energy, &b_Muon_energy);
   fChain->SetBranchAddress("Muon_charge", Muon_charge, &b_Muon_charge);
   fChain->SetBranchAddress("Muon_isGlobalMuon", Muon_isGlobalMuon, &b_Muon_isGlobalMuon);
   fChain->SetBranchAddress("Muon_isTrackerMuon", Muon_isTrackerMuon, &b_Muon_isTrackerMuon);
   fChain->SetBranchAddress("Muon_isStandAloneMuon", Muon_isStandAloneMuon, &b_Muon_isStandAloneMuon);
   fChain->SetBranchAddress("Muon_InnerTrack_isNonnull", Muon_InnerTrack_isNonnull, &b_Muon_InnerTrack_isNonnull);
   fChain->SetBranchAddress("Muon_OuterTrack_isNonnull", Muon_OuterTrack_isNonnull, &b_Muon_OuterTrack_isNonnull);
   fChain->SetBranchAddress("Muon_OuterTrack_InnerPoint_x", Muon_OuterTrack_InnerPoint_x, &b_Muon_OuterTrack_InnerPoint_x);
   fChain->SetBranchAddress("Muon_OuterTrack_InnerPoint_y", Muon_OuterTrack_InnerPoint_y, &b_Muon_OuterTrack_InnerPoint_y);
   fChain->SetBranchAddress("Muon_OuterTrack_InnerPoint_z", Muon_OuterTrack_InnerPoint_z, &b_Muon_OuterTrack_InnerPoint_z);
   fChain->SetBranchAddress("Muon_OuterTrack_InnerPoint_px", Muon_OuterTrack_InnerPoint_px, &b_Muon_OuterTrack_InnerPoint_px);
   fChain->SetBranchAddress("Muon_OuterTrack_InnerPoint_py", Muon_OuterTrack_InnerPoint_py, &b_Muon_OuterTrack_InnerPoint_py);
   fChain->SetBranchAddress("Muon_OuterTrack_InnerPoint_pz", Muon_OuterTrack_InnerPoint_pz, &b_Muon_OuterTrack_InnerPoint_pz);
   fChain->SetBranchAddress("Muon_OuterTrack_OuterPoint_x", Muon_OuterTrack_OuterPoint_x, &b_Muon_OuterTrack_OuterPoint_x);
   fChain->SetBranchAddress("Muon_OuterTrack_OuterPoint_y", Muon_OuterTrack_OuterPoint_y, &b_Muon_OuterTrack_OuterPoint_y);
   fChain->SetBranchAddress("Muon_OuterTrack_OuterPoint_z", Muon_OuterTrack_OuterPoint_z, &b_Muon_OuterTrack_OuterPoint_z);
   fChain->SetBranchAddress("Muon_OuterTrack_OuterPoint_px", Muon_OuterTrack_OuterPoint_px, &b_Muon_OuterTrack_OuterPoint_px);
   fChain->SetBranchAddress("Muon_OuterTrack_OuterPoint_py", Muon_OuterTrack_OuterPoint_py, &b_Muon_OuterTrack_OuterPoint_py);
   fChain->SetBranchAddress("Muon_OuterTrack_OuterPoint_pz", Muon_OuterTrack_OuterPoint_pz, &b_Muon_OuterTrack_OuterPoint_pz);
   fChain->SetBranchAddress("Muon_InnerTrack_InnerPoint_x", Muon_InnerTrack_InnerPoint_x, &b_Muon_InnerTrack_InnerPoint_x);
   fChain->SetBranchAddress("Muon_InnerTrack_InnerPoint_y", Muon_InnerTrack_InnerPoint_y, &b_Muon_InnerTrack_InnerPoint_y);
   fChain->SetBranchAddress("Muon_InnerTrack_InnerPoint_z", Muon_InnerTrack_InnerPoint_z, &b_Muon_InnerTrack_InnerPoint_z);
   fChain->SetBranchAddress("Muon_InnerTrack_InnerPoint_px", Muon_InnerTrack_InnerPoint_px, &b_Muon_InnerTrack_InnerPoint_px);
   fChain->SetBranchAddress("Muon_InnerTrack_InnerPoint_py", Muon_InnerTrack_InnerPoint_py, &b_Muon_InnerTrack_InnerPoint_py);
   fChain->SetBranchAddress("Muon_InnerTrack_InnerPoint_pz", Muon_InnerTrack_InnerPoint_pz, &b_Muon_InnerTrack_InnerPoint_pz);
   fChain->SetBranchAddress("Muon_InnerTrack_OuterPoint_x", Muon_InnerTrack_OuterPoint_x, &b_Muon_InnerTrack_OuterPoint_x);
   fChain->SetBranchAddress("Muon_InnerTrack_OuterPoint_y", Muon_InnerTrack_OuterPoint_y, &b_Muon_InnerTrack_OuterPoint_y);
   fChain->SetBranchAddress("Muon_InnerTrack_OuterPoint_z", Muon_InnerTrack_OuterPoint_z, &b_Muon_InnerTrack_OuterPoint_z);
   fChain->SetBranchAddress("Muon_InnerTrack_OuterPoint_px", Muon_InnerTrack_OuterPoint_px, &b_Muon_InnerTrack_OuterPoint_px);
   fChain->SetBranchAddress("Muon_InnerTrack_OuterPoint_py", Muon_InnerTrack_OuterPoint_py, &b_Muon_InnerTrack_OuterPoint_py);
   fChain->SetBranchAddress("Muon_InnerTrack_OuterPoint_pz", Muon_InnerTrack_OuterPoint_pz, &b_Muon_InnerTrack_OuterPoint_pz);
   fChain->SetBranchAddress("Muon_trackIso", Muon_trackIso, &b_Muon_trackIso);
   fChain->SetBranchAddress("Muon_ecalIso", Muon_ecalIso, &b_Muon_ecalIso);
   fChain->SetBranchAddress("Muon_hcalIso", Muon_hcalIso, &b_Muon_hcalIso);
   fChain->SetBranchAddress("Muon_relIso", Muon_relIso, &b_Muon_relIso);
   fChain->SetBranchAddress("Muon_normChi2", Muon_normChi2, &b_Muon_normChi2);
   fChain->SetBranchAddress("Muon_validHits", Muon_validHits, &b_Muon_validHits);
   fChain->SetBranchAddress("Muon_tkHits", Muon_tkHits, &b_Muon_tkHits);
   fChain->SetBranchAddress("Muon_pixHits", Muon_pixHits, &b_Muon_pixHits);
   fChain->SetBranchAddress("Muon_numberOfMatches", Muon_numberOfMatches, &b_Muon_numberOfMatches);
   fChain->SetBranchAddress("Muon_OuterPoint_x", Muon_OuterPoint_x, &b_Muon_OuterPoint_x);
   fChain->SetBranchAddress("Muon_OuterPoint_y", Muon_OuterPoint_y, &b_Muon_OuterPoint_y);
   fChain->SetBranchAddress("Muon_OuterPoint_z", Muon_OuterPoint_z, &b_Muon_OuterPoint_z);
   fChain->SetBranchAddress("Muon_InnerPoint_x", Muon_InnerPoint_x, &b_Muon_InnerPoint_x);
   fChain->SetBranchAddress("Muon_InnerPoint_y", Muon_InnerPoint_y, &b_Muon_InnerPoint_y);
   fChain->SetBranchAddress("Muon_InnerPoint_z", Muon_InnerPoint_z, &b_Muon_InnerPoint_z);
   fChain->SetBranchAddress("CosmicMuon_n", &CosmicMuon_n, &b_CosmicMuon_n);
   fChain->SetBranchAddress("CosmicMuon_px", CosmicMuon_px, &b_CosmicMuon_px);
   fChain->SetBranchAddress("CosmicMuon_py", CosmicMuon_py, &b_CosmicMuon_py);
   fChain->SetBranchAddress("CosmicMuon_pz", CosmicMuon_pz, &b_CosmicMuon_pz);
   fChain->SetBranchAddress("CosmicMuon_pt", CosmicMuon_pt, &b_CosmicMuon_pt);
   fChain->SetBranchAddress("CosmicMuon_eta", CosmicMuon_eta, &b_CosmicMuon_eta);
   fChain->SetBranchAddress("CosmicMuon_phi", CosmicMuon_phi, &b_CosmicMuon_phi);
   fChain->SetBranchAddress("CosmicMuon_energy", CosmicMuon_energy, &b_CosmicMuon_energy);
   fChain->SetBranchAddress("CosmicMuon_charge", CosmicMuon_charge, &b_CosmicMuon_charge);
   fChain->SetBranchAddress("CosmicMuon_isGlobalMuon", CosmicMuon_isGlobalMuon, &b_CosmicMuon_isGlobalMuon);
   fChain->SetBranchAddress("CosmicMuon_isTrackerMuon", CosmicMuon_isTrackerMuon, &b_CosmicMuon_isTrackerMuon);
   fChain->SetBranchAddress("CosmicMuon_isStandAloneMuon", CosmicMuon_isStandAloneMuon, &b_CosmicMuon_isStandAloneMuon);
   fChain->SetBranchAddress("CosmicMuon_InnerTrack_isNonnull", CosmicMuon_InnerTrack_isNonnull, &b_CosmicMuon_InnerTrack_isNonnull);
   fChain->SetBranchAddress("CosmicMuon_OuterTrack_isNonnull", CosmicMuon_OuterTrack_isNonnull, &b_CosmicMuon_OuterTrack_isNonnull);
   fChain->SetBranchAddress("CosmicMuon_OuterTrack_InnerPoint_x", CosmicMuon_OuterTrack_InnerPoint_x, &b_CosmicMuon_OuterTrack_InnerPoint_x);
   fChain->SetBranchAddress("CosmicMuon_OuterTrack_InnerPoint_y", CosmicMuon_OuterTrack_InnerPoint_y, &b_CosmicMuon_OuterTrack_InnerPoint_y);
   fChain->SetBranchAddress("CosmicMuon_OuterTrack_InnerPoint_z", CosmicMuon_OuterTrack_InnerPoint_z, &b_CosmicMuon_OuterTrack_InnerPoint_z);
   fChain->SetBranchAddress("CosmicMuon_OuterTrack_InnerPoint_px", CosmicMuon_OuterTrack_InnerPoint_px, &b_CosmicMuon_OuterTrack_InnerPoint_px);
   fChain->SetBranchAddress("CosmicMuon_OuterTrack_InnerPoint_py", CosmicMuon_OuterTrack_InnerPoint_py, &b_CosmicMuon_OuterTrack_InnerPoint_py);
   fChain->SetBranchAddress("CosmicMuon_OuterTrack_InnerPoint_pz", CosmicMuon_OuterTrack_InnerPoint_pz, &b_CosmicMuon_OuterTrack_InnerPoint_pz);
   fChain->SetBranchAddress("CosmicMuon_OuterTrack_OuterPoint_x", CosmicMuon_OuterTrack_OuterPoint_x, &b_CosmicMuon_OuterTrack_OuterPoint_x);
   fChain->SetBranchAddress("CosmicMuon_OuterTrack_OuterPoint_y", CosmicMuon_OuterTrack_OuterPoint_y, &b_CosmicMuon_OuterTrack_OuterPoint_y);
   fChain->SetBranchAddress("CosmicMuon_OuterTrack_OuterPoint_z", CosmicMuon_OuterTrack_OuterPoint_z, &b_CosmicMuon_OuterTrack_OuterPoint_z);
   fChain->SetBranchAddress("CosmicMuon_OuterTrack_OuterPoint_px", CosmicMuon_OuterTrack_OuterPoint_px, &b_CosmicMuon_OuterTrack_OuterPoint_px);
   fChain->SetBranchAddress("CosmicMuon_OuterTrack_OuterPoint_py", CosmicMuon_OuterTrack_OuterPoint_py, &b_CosmicMuon_OuterTrack_OuterPoint_py);
   fChain->SetBranchAddress("CosmicMuon_OuterTrack_OuterPoint_pz", CosmicMuon_OuterTrack_OuterPoint_pz, &b_CosmicMuon_OuterTrack_OuterPoint_pz);
   fChain->SetBranchAddress("CosmicMuon_InnerTrack_InnerPoint_x", CosmicMuon_InnerTrack_InnerPoint_x, &b_CosmicMuon_InnerTrack_InnerPoint_x);
   fChain->SetBranchAddress("CosmicMuon_InnerTrack_InnerPoint_y", CosmicMuon_InnerTrack_InnerPoint_y, &b_CosmicMuon_InnerTrack_InnerPoint_y);
   fChain->SetBranchAddress("CosmicMuon_InnerTrack_InnerPoint_z", CosmicMuon_InnerTrack_InnerPoint_z, &b_CosmicMuon_InnerTrack_InnerPoint_z);
   fChain->SetBranchAddress("CosmicMuon_InnerTrack_InnerPoint_px", CosmicMuon_InnerTrack_InnerPoint_px, &b_CosmicMuon_InnerTrack_InnerPoint_px);
   fChain->SetBranchAddress("CosmicMuon_InnerTrack_InnerPoint_py", CosmicMuon_InnerTrack_InnerPoint_py, &b_CosmicMuon_InnerTrack_InnerPoint_py);
   fChain->SetBranchAddress("CosmicMuon_InnerTrack_InnerPoint_pz", CosmicMuon_InnerTrack_InnerPoint_pz, &b_CosmicMuon_InnerTrack_InnerPoint_pz);
   fChain->SetBranchAddress("CosmicMuon_InnerTrack_OuterPoint_x", CosmicMuon_InnerTrack_OuterPoint_x, &b_CosmicMuon_InnerTrack_OuterPoint_x);
   fChain->SetBranchAddress("CosmicMuon_InnerTrack_OuterPoint_y", CosmicMuon_InnerTrack_OuterPoint_y, &b_CosmicMuon_InnerTrack_OuterPoint_y);
   fChain->SetBranchAddress("CosmicMuon_InnerTrack_OuterPoint_z", CosmicMuon_InnerTrack_OuterPoint_z, &b_CosmicMuon_InnerTrack_OuterPoint_z);
   fChain->SetBranchAddress("CosmicMuon_InnerTrack_OuterPoint_px", CosmicMuon_InnerTrack_OuterPoint_px, &b_CosmicMuon_InnerTrack_OuterPoint_px);
   fChain->SetBranchAddress("CosmicMuon_InnerTrack_OuterPoint_py", CosmicMuon_InnerTrack_OuterPoint_py, &b_CosmicMuon_InnerTrack_OuterPoint_py);
   fChain->SetBranchAddress("CosmicMuon_InnerTrack_OuterPoint_pz", CosmicMuon_InnerTrack_OuterPoint_pz, &b_CosmicMuon_InnerTrack_OuterPoint_pz);
   fChain->SetBranchAddress("CosmicMuon_OuterPoint_x", CosmicMuon_OuterPoint_x, &b_CosmicMuon_OuterPoint_x);
   fChain->SetBranchAddress("CosmicMuon_OuterPoint_y", CosmicMuon_OuterPoint_y, &b_CosmicMuon_OuterPoint_y);
   fChain->SetBranchAddress("CosmicMuon_OuterPoint_z", CosmicMuon_OuterPoint_z, &b_CosmicMuon_OuterPoint_z);
   fChain->SetBranchAddress("Tau_n", &Tau_n, &b_Tau_n);
   fChain->SetBranchAddress("Tau_px", Tau_px, &b_Tau_px);
   fChain->SetBranchAddress("Tau_py", Tau_py, &b_Tau_py);
   fChain->SetBranchAddress("Tau_pz", Tau_pz, &b_Tau_pz);
   fChain->SetBranchAddress("Tau_vx", Tau_vx, &b_Tau_vx);
   fChain->SetBranchAddress("Tau_vy", Tau_vy, &b_Tau_vy);
   fChain->SetBranchAddress("Tau_vz", Tau_vz, &b_Tau_vz);
   fChain->SetBranchAddress("Tau_pt", Tau_pt, &b_Tau_pt);
   fChain->SetBranchAddress("Tau_eta", Tau_eta, &b_Tau_eta);
   fChain->SetBranchAddress("Tau_phi", Tau_phi, &b_Tau_phi);
   fChain->SetBranchAddress("Tau_energy", Tau_energy, &b_Tau_energy);
   fChain->SetBranchAddress("Tau_charge", Tau_charge, &b_Tau_charge);
   fChain->SetBranchAddress("genTauDecayMode1", &genTauDecayMode1, &b_genTauDecayMode1);
   fChain->SetBranchAddress("oneProng0Pi0", oneProng0Pi0, &b_oneProng0Pi0);
   fChain->SetBranchAddress("oneProng1Pi0", oneProng1Pi0, &b_oneProng1Pi0);
   fChain->SetBranchAddress("oneProng2Pi0", oneProng2Pi0, &b_oneProng2Pi0);
   fChain->SetBranchAddress("threeProng0Pi0", threeProng0Pi0, &b_threeProng0Pi0);
   fChain->SetBranchAddress("threeProng1Pi0", threeProng1Pi0, &b_threeProng1Pi0);
   fChain->SetBranchAddress("tauelectron", tauelectron, &b_tauelectron);
   fChain->SetBranchAddress("taumuon", taumuon, &b_taumuon);
   fChain->SetBranchAddress("nthreeProng1Pi0", &nthreeProng1Pi0, &b_nthreeProng1Pi0);
   fChain->SetBranchAddress("ntauelectron", &ntauelectron, &b_ntauelectron);
   fChain->SetBranchAddress("ntaumuon", &ntaumuon, &b_ntaumuon);
   fChain->SetBranchAddress("genHadTauPt", genHadTauPt, &b_genHadTauPt);
   fChain->SetBranchAddress("genHadTauEta", genHadTauEta, &b_genHadTauEta);
   fChain->SetBranchAddress("genHadTauPhi", genHadTauPhi, &b_genHadTauPhi);
   fChain->SetBranchAddress("nPions", nPions, &b_nPions);
   fChain->SetBranchAddress("PionPdgId", PionPdgId, &b_PionPdgId);
   fChain->SetBranchAddress("PionPt", PionPt, &b_PionPt);
   fChain->SetBranchAddress("PionEta", PionEta, &b_PionEta);
   fChain->SetBranchAddress("PionPhi", PionPhi, &b_PionPhi);
   fChain->SetBranchAddress("nPi0", nPi0, &b_nPi0);
   fChain->SetBranchAddress("Pi0PdgId", Pi0PdgId, &b_Pi0PdgId);
   fChain->SetBranchAddress("Pi0Pt", Pi0Pt, &b_Pi0Pt);
   fChain->SetBranchAddress("Pi0Eta", Pi0Eta, &b_Pi0Eta);
   fChain->SetBranchAddress("Pi0Phi", Pi0Phi, &b_Pi0Phi);
   fChain->SetBranchAddress("nPhotons", nPhotons, &b_nPhotons);
   fChain->SetBranchAddress("PhotonPt", PhotonPt, &b_PhotonPt);
   fChain->SetBranchAddress("PhotonEta", PhotonEta, &b_PhotonEta);
   fChain->SetBranchAddress("PhotonPhi", PhotonPhi, &b_PhotonPhi);
   fChain->SetBranchAddress("PhotonPdgId", PhotonPdgId, &b_PhotonPdgId);
   fChain->SetBranchAddress("Photon_n", &Photon_n, &b_Photon_n);
   fChain->SetBranchAddress("Photon_E", Photon_E, &b_Photon_E);
   fChain->SetBranchAddress("Photon_pt", Photon_pt, &b_Photon_pt);
   fChain->SetBranchAddress("Photon_eta", Photon_eta, &b_Photon_eta);
   fChain->SetBranchAddress("Photon_phi", Photon_phi, &b_Photon_phi);
   fChain->SetBranchAddress("Photon_theta", Photon_theta, &b_Photon_theta);
   fChain->SetBranchAddress("Photon_et", Photon_et, &b_Photon_et);
   fChain->SetBranchAddress("Photon_swissCross", Photon_swissCross, &b_Photon_swissCross);
   fChain->SetBranchAddress("Photon_e6e2", Photon_e6e2, &b_Photon_e6e2);
   fChain->SetBranchAddress("Photon_e4e1", Photon_e4e1, &b_Photon_e4e1);
   fChain->SetBranchAddress("Photonr9", Photonr9, &b_Photonr9);
   fChain->SetBranchAddress("Photon_e1x5", Photon_e1x5, &b_Photon_e1x5);
   fChain->SetBranchAddress("Photon_e2x5", Photon_e2x5, &b_Photon_e2x5);
   fChain->SetBranchAddress("Photon_e3x3", Photon_e3x3, &b_Photon_e3x3);
   fChain->SetBranchAddress("Photon_e5x5", Photon_e5x5, &b_Photon_e5x5);
   fChain->SetBranchAddress("Photon_r1x5", Photon_r1x5, &b_Photon_r1x5);
   fChain->SetBranchAddress("Photon_r2x5", Photon_r2x5, &b_Photon_r2x5);
   fChain->SetBranchAddress("Photon_maxEnergyXtal", Photon_maxEnergyXtal, &b_Photon_maxEnergyXtal);
   fChain->SetBranchAddress("Photon_SigmaEtaEta", Photon_SigmaEtaEta, &b_Photon_SigmaEtaEta);
   fChain->SetBranchAddress("Photon_SigmaIetaIeta", Photon_SigmaIetaIeta, &b_Photon_SigmaIetaIeta);
   fChain->SetBranchAddress("Photon_SigmaEtaPhi", Photon_SigmaEtaPhi, &b_Photon_SigmaEtaPhi);
   fChain->SetBranchAddress("Photon_SigmaIetaIphi", Photon_SigmaIetaIphi, &b_Photon_SigmaIetaIphi);
   fChain->SetBranchAddress("Photon_SigmaPhiPhi", Photon_SigmaPhiPhi, &b_Photon_SigmaPhiPhi);
   fChain->SetBranchAddress("Photon_SigmaIphiIphi", Photon_SigmaIphiIphi, &b_Photon_SigmaIphiIphi);
   fChain->SetBranchAddress("Photon_Roundness", Photon_Roundness, &b_Photon_Roundness);
   fChain->SetBranchAddress("Photon_Angle", Photon_Angle, &b_Photon_Angle);
   fChain->SetBranchAddress("Photon_ecalRecHitSumEtConeDR03", Photon_ecalRecHitSumEtConeDR03, &b_Photon_ecalRecHitSumEtConeDR03);
   fChain->SetBranchAddress("Photon_hcalTowerSumEtConeDR03", Photon_hcalTowerSumEtConeDR03, &b_Photon_hcalTowerSumEtConeDR03);
   fChain->SetBranchAddress("Photon_trkSumPtSolidConeDR03", Photon_trkSumPtSolidConeDR03, &b_Photon_trkSumPtSolidConeDR03);
   fChain->SetBranchAddress("Photon_trkSumPtHollowConeDR03", Photon_trkSumPtHollowConeDR03, &b_Photon_trkSumPtHollowConeDR03);
   fChain->SetBranchAddress("Photon_nTrkSolidConeDR03", Photon_nTrkSolidConeDR03, &b_Photon_nTrkSolidConeDR03);
   fChain->SetBranchAddress("Photon_nTrkHollowConeDR03", Photon_nTrkHollowConeDR03, &b_Photon_nTrkHollowConeDR03);
   fChain->SetBranchAddress("Photon_hcalDepth1TowerSumEtConeDR03", Photon_hcalDepth1TowerSumEtConeDR03, &b_Photon_hcalDepth1TowerSumEtConeDR03);
   fChain->SetBranchAddress("Photon_hcalDepth2TowerSumEtConeDR03", Photon_hcalDepth2TowerSumEtConeDR03, &b_Photon_hcalDepth2TowerSumEtConeDR03);
   fChain->SetBranchAddress("Photon_ecalRecHitSumEtConeDR04", Photon_ecalRecHitSumEtConeDR04, &b_Photon_ecalRecHitSumEtConeDR04);
   fChain->SetBranchAddress("Photon_hcalTowerSumEtConeDR04", Photon_hcalTowerSumEtConeDR04, &b_Photon_hcalTowerSumEtConeDR04);
   fChain->SetBranchAddress("Photon_trkSumPtSolidConeDR04", Photon_trkSumPtSolidConeDR04, &b_Photon_trkSumPtSolidConeDR04);
   fChain->SetBranchAddress("Photon_trkSumPtHollowConeDR04", Photon_trkSumPtHollowConeDR04, &b_Photon_trkSumPtHollowConeDR04);
   fChain->SetBranchAddress("Photon_nTrkSolidConeDR04", Photon_nTrkSolidConeDR04, &b_Photon_nTrkSolidConeDR04);
   fChain->SetBranchAddress("Photon_nTrkHollowConeDR04", Photon_nTrkHollowConeDR04, &b_Photon_nTrkHollowConeDR04);
   fChain->SetBranchAddress("Photon_hcalDepth1TowerSumEtConeDR04", Photon_hcalDepth1TowerSumEtConeDR04, &b_Photon_hcalDepth1TowerSumEtConeDR04);
   fChain->SetBranchAddress("Photon_hcalDepth2TowerSumEtConeDR04", Photon_hcalDepth2TowerSumEtConeDR04, &b_Photon_hcalDepth2TowerSumEtConeDR04);
   fChain->SetBranchAddress("Photon_hasPixelSeed", Photon_hasPixelSeed, &b_Photon_hasPixelSeed);
   fChain->SetBranchAddress("Photon_isEB", Photon_isEB, &b_Photon_isEB);
   fChain->SetBranchAddress("Photon_isEE", Photon_isEE, &b_Photon_isEE);
   fChain->SetBranchAddress("Photon_isEBGap", Photon_isEBGap, &b_Photon_isEBGap);
   fChain->SetBranchAddress("Photon_isEEGap", Photon_isEEGap, &b_Photon_isEEGap);
   fChain->SetBranchAddress("Photon_isEBEEGap", Photon_isEBEEGap, &b_Photon_isEBEEGap);
   fChain->SetBranchAddress("Photon_e2e9", Photon_e2e9, &b_Photon_e2e9);
   fChain->SetBranchAddress("Photon_HoE", Photon_HoE, &b_Photon_HoE);
   fChain->SetBranchAddress("Photon_HoEnew", Photon_HoEnew, &b_Photon_HoEnew);
   fChain->SetBranchAddress("Photon_px", Photon_px, &b_Photon_px);
   fChain->SetBranchAddress("Photon_py", Photon_py, &b_Photon_py);
   fChain->SetBranchAddress("Photon_pz", Photon_pz, &b_Photon_pz);
   fChain->SetBranchAddress("Photon_vx", Photon_vx, &b_Photon_vx);
   fChain->SetBranchAddress("Photon_vy", Photon_vy, &b_Photon_vy);
   fChain->SetBranchAddress("Photon_vz", Photon_vz, &b_Photon_vz);
   fChain->SetBranchAddress("Photon_no_of_basic_clusters", Photon_no_of_basic_clusters, &b_Photon_no_of_basic_clusters);
   fChain->SetBranchAddress("Photon_sc_energy", Photon_sc_energy, &b_Photon_sc_energy);
   fChain->SetBranchAddress("Photon_sc_eta", Photon_sc_eta, &b_Photon_sc_eta);
   fChain->SetBranchAddress("Photon_sc_phi", Photon_sc_phi, &b_Photon_sc_phi);
   fChain->SetBranchAddress("Photon_sc_x", Photon_sc_x, &b_Photon_sc_x);
   fChain->SetBranchAddress("Photon_sc_y", Photon_sc_y, &b_Photon_sc_y);
   fChain->SetBranchAddress("Photon_sc_z", Photon_sc_z, &b_Photon_sc_z);
   fChain->SetBranchAddress("Photon_etaWidth", Photon_etaWidth, &b_Photon_etaWidth);
   fChain->SetBranchAddress("Photon_phiWidth", Photon_phiWidth, &b_Photon_phiWidth);
   fChain->SetBranchAddress("Photon_sc_et", Photon_sc_et, &b_Photon_sc_et);
   fChain->SetBranchAddress("matchphotonE", matchphotonE, &b_matchphotonE);
   fChain->SetBranchAddress("matchphotonpt", matchphotonpt, &b_matchphotonpt);
   fChain->SetBranchAddress("matchphotoneta", matchphotoneta, &b_matchphotoneta);
   fChain->SetBranchAddress("matchphotonphi", matchphotonphi, &b_matchphotonphi);
   fChain->SetBranchAddress("matchphotonpx", matchphotonpx, &b_matchphotonpx);
   fChain->SetBranchAddress("matchphotonpy", matchphotonpy, &b_matchphotonpy);
   fChain->SetBranchAddress("matchphotonpz", matchphotonpz, &b_matchphotonpz);
   fChain->SetBranchAddress("ismatchedphoton", ismatchedphoton, &b_ismatchedphoton);
   fChain->SetBranchAddress("Photon_hasConvTrk", Photon_hasConvTrk, &b_Photon_hasConvTrk);
   fChain->SetBranchAddress("Photon_ntracks", Photon_ntracks, &b_Photon_ntracks);
   fChain->SetBranchAddress("Photon_isconverted", Photon_isconverted, &b_Photon_isconverted);
   fChain->SetBranchAddress("Photon_pairInvmass", Photon_pairInvmass, &b_Photon_pairInvmass);
   fChain->SetBranchAddress("Photon_pairCotThetaSeperation", Photon_pairCotThetaSeperation, &b_Photon_pairCotThetaSeperation);
   fChain->SetBranchAddress("Photon_pairmomentumX", Photon_pairmomentumX, &b_Photon_pairmomentumX);
   fChain->SetBranchAddress("Photon_pairmomentumY", Photon_pairmomentumY, &b_Photon_pairmomentumY);
   fChain->SetBranchAddress("Photon_pairmomentumZ", Photon_pairmomentumZ, &b_Photon_pairmomentumZ);
   fChain->SetBranchAddress("Photon_EoverP", Photon_EoverP, &b_Photon_EoverP);
   fChain->SetBranchAddress("Photon_ConvVx", Photon_ConvVx, &b_Photon_ConvVx);
   fChain->SetBranchAddress("Photon_ConvVy", Photon_ConvVy, &b_Photon_ConvVy);
   fChain->SetBranchAddress("Photon_ConvVz", Photon_ConvVz, &b_Photon_ConvVz);
   fChain->SetBranchAddress("Photon_ZOfPrimaryVertex", Photon_ZOfPrimaryVertex, &b_Photon_ZOfPrimaryVertex);
   fChain->SetBranchAddress("Photon_distOfMinimumApproach", Photon_distOfMinimumApproach, &b_Photon_distOfMinimumApproach);
   fChain->SetBranchAddress("Photon_dPhiTracksAtVtx", Photon_dPhiTracksAtVtx, &b_Photon_dPhiTracksAtVtx);
   fChain->SetBranchAddress("Photon_dPhiTracksAtEcal", Photon_dPhiTracksAtEcal, &b_Photon_dPhiTracksAtEcal);
   fChain->SetBranchAddress("Photon_dEtaTracksAtEcal", Photon_dEtaTracksAtEcal, &b_Photon_dEtaTracksAtEcal);
   fChain->SetBranchAddress("npho_", &npho_, &b_npho_);
   fChain->SetBranchAddress("Photon_Electronveto", Photon_Electronveto, &b_Photon_Electronveto);
   fChain->SetBranchAddress("PFiso_Charged03", PFiso_Charged03, &b_PFiso_Charged03);
   fChain->SetBranchAddress("PFiso_Photon03", PFiso_Photon03, &b_PFiso_Photon03);
   fChain->SetBranchAddress("PFiso_Neutral03", PFiso_Neutral03, &b_PFiso_Neutral03);
   fChain->SetBranchAddress("PFiso_Sum03", PFiso_Sum03, &b_PFiso_Sum03);
   fChain->SetBranchAddress("PFWorstiso_Charged03", PFWorstiso_Charged03, &b_PFWorstiso_Charged03);
   fChain->SetBranchAddress("Photon_ncrys", Photon_ncrys, &b_Photon_ncrys);
   fChain->SetBranchAddress("Photon_timing_xtal", Photon_timing_xtal, &b_Photon_timing_xtal);
   fChain->SetBranchAddress("Photon_timingavg_xtal", Photon_timingavg_xtal, &b_Photon_timingavg_xtal);
   fChain->SetBranchAddress("Photon_energy_xtal", Photon_energy_xtal, &b_Photon_energy_xtal);
   fChain->SetBranchAddress("Photon_ieta_xtalEB", Photon_ieta_xtalEB, &b_Photon_ieta_xtalEB);
   fChain->SetBranchAddress("Photon_iphi_xtalEB", Photon_iphi_xtalEB, &b_Photon_iphi_xtalEB);
   fChain->SetBranchAddress("Photon_recoFlag_xtalEB", Photon_recoFlag_xtalEB, &b_Photon_recoFlag_xtalEB);
   fChain->SetBranchAddress("Photon_timeError_xtal", Photon_timeError_xtal, &b_Photon_timeError_xtal);
   fChain->SetBranchAddress("Photon_s9", Photon_s9, &b_Photon_s9);
   fChain->SetBranchAddress("HERecHit_subset_n", &HERecHit_subset_n, &b_HERecHit_subset_n);
   fChain->SetBranchAddress("HERecHit_subset_detid", HERecHit_subset_detid, &b_HERecHit_subset_detid);
   fChain->SetBranchAddress("HERecHit_subset_energy", HERecHit_subset_energy, &b_HERecHit_subset_energy);
   fChain->SetBranchAddress("HERecHit_subset_time", HERecHit_subset_time, &b_HERecHit_subset_time);
   fChain->SetBranchAddress("HERecHit_subset_depth", HERecHit_subset_depth, &b_HERecHit_subset_depth);
   fChain->SetBranchAddress("HERecHit_subset_phi", HERecHit_subset_phi, &b_HERecHit_subset_phi);
   fChain->SetBranchAddress("HERecHit_subset_eta", HERecHit_subset_eta, &b_HERecHit_subset_eta);
   fChain->SetBranchAddress("HERecHit_subset_x", HERecHit_subset_x, &b_HERecHit_subset_x);
   fChain->SetBranchAddress("HERecHit_subset_y", HERecHit_subset_y, &b_HERecHit_subset_y);
   fChain->SetBranchAddress("HERecHit_subset_z", HERecHit_subset_z, &b_HERecHit_subset_z);
   fChain->SetBranchAddress("Photon_mipChi2", Photon_mipChi2, &b_Photon_mipChi2);
   fChain->SetBranchAddress("Photon_mipTotEnergy", Photon_mipTotEnergy, &b_Photon_mipTotEnergy);
   fChain->SetBranchAddress("Photon_mipSlope", Photon_mipSlope, &b_Photon_mipSlope);
   fChain->SetBranchAddress("Photon_mipIntercept", Photon_mipIntercept, &b_Photon_mipIntercept);
   fChain->SetBranchAddress("Photon_mipNhitCone", Photon_mipNhitCone, &b_Photon_mipNhitCone);
   fChain->SetBranchAddress("Photon_mipIsHalo", Photon_mipIsHalo, &b_Photon_mipIsHalo);
   fChain->SetBranchAddress("EBRecHit_size", &EBRecHit_size, &b_EBRecHit_size);
   fChain->SetBranchAddress("EBRecHit_eta", EBRecHit_eta, &b_EBRecHit_eta);
   fChain->SetBranchAddress("EBRecHit_phi", EBRecHit_phi, &b_EBRecHit_phi);
   fChain->SetBranchAddress("EBRecHit_ieta", EBRecHit_ieta, &b_EBRecHit_ieta);
   fChain->SetBranchAddress("EBRecHit_iphi", EBRecHit_iphi, &b_EBRecHit_iphi);
   fChain->SetBranchAddress("EBRecHit_e", EBRecHit_e, &b_EBRecHit_e);
   fChain->SetBranchAddress("EBRecHit_et", EBRecHit_et, &b_EBRecHit_et);
   fChain->SetBranchAddress("EBRecHit_flag", EBRecHit_flag, &b_EBRecHit_flag);
   fChain->SetBranchAddress("EBRecHit_time", EBRecHit_time, &b_EBRecHit_time);
   fChain->SetBranchAddress("EERecHit_size", &EERecHit_size, &b_EERecHit_size);
   fChain->SetBranchAddress("EERecHit_eta", EERecHit_eta, &b_EERecHit_eta);
   fChain->SetBranchAddress("EERecHit_phi", EERecHit_phi, &b_EERecHit_phi);
   fChain->SetBranchAddress("EERecHit_ieta", EERecHit_ieta, &b_EERecHit_ieta);
   fChain->SetBranchAddress("EERecHit_iphi", EERecHit_iphi, &b_EERecHit_iphi);
   fChain->SetBranchAddress("EERecHit_e", EERecHit_e, &b_EERecHit_e);
   fChain->SetBranchAddress("EERecHit_et", EERecHit_et, &b_EERecHit_et);
   fChain->SetBranchAddress("EERecHit_flag", EERecHit_flag, &b_EERecHit_flag);
   fChain->SetBranchAddress("EERecHit_time", EERecHit_time, &b_EERecHit_time);
   fChain->SetBranchAddress("isBeamHaloGlobalLoosePass", &isBeamHaloGlobalLoosePass, &b_isBeamHaloGlobalLoosePass);
   fChain->SetBranchAddress("isBeamHaloGlobalTightPass", &isBeamHaloGlobalTightPass, &b_isBeamHaloGloablTightPass);
   fChain->SetBranchAddress("isBeamHaloHcalLoosePass", &isBeamHaloHcalLoosePass, &b_isBeamHaloHcalLoosePass);
   fChain->SetBranchAddress("isBeamHaloHcalTightPass", &isBeamHaloHcalTightPass, &b_isBeamHaloHcalTightPass);
   fChain->SetBranchAddress("isBeamHaloCSCLoosePass", &isBeamHaloCSCLoosePass, &b_isBeamHaloCSCLoosePass);
   fChain->SetBranchAddress("isBeamHaloCSCTightPass", &isBeamHaloCSCTightPass, &b_isBeamHaloCSCTightPass);
   fChain->SetBranchAddress("isBeamHaloEcalLoosePass", &isBeamHaloEcalLoosePass, &b_isBeamHaloEcalLoosePass);
   fChain->SetBranchAddress("isBeamHaloEcalTightPass", &isBeamHaloEcalTightPass, &b_isBeamHaloEcalTightPass);
   fChain->SetBranchAddress("isBeamHaloIDTightPass", &isBeamHaloIDTightPass, &b_isBeamHaloIDTightPass);
   fChain->SetBranchAddress("isBeamHaloIDLoosePass", &isBeamHaloIDLoosePass, &b_isBeamHaloIDLoosePass);
   fChain->SetBranchAddress("isSmellsLikeHalo_Tag", &isSmellsLikeHalo_Tag, &b_isSmellsLikeHalo_Tag);
   fChain->SetBranchAddress("isLooseHalo_Tag", &isLooseHalo_Tag, &b_isLooseHalo_Tag);
   fChain->SetBranchAddress("isTightHalo_Tag", &isTightHalo_Tag, &b_isTightHalo_Tag);
   fChain->SetBranchAddress("isExtremeTightHalo_Tag", &isExtremeTightHalo_Tag, &b_isExtremeTightHalo_Tag);
   fChain->SetBranchAddress("CaloMetSigma", &CaloMetSigma, &b_CaloMetSig);
   fChain->SetBranchAddress("CaloMetEz", &CaloMetEz, &b_CaloMetEz);
   fChain->SetBranchAddress("CaloEtFractionHadronic", &CaloEtFractionHadronic, &b_CaloEtFractionHadronic);
   fChain->SetBranchAddress("CaloEmEtFraction", &CaloEmEtFraction, &b_CaloEmEtFraction);
   fChain->SetBranchAddress("CaloHadEtInHB", &CaloHadEtInHB, &b_CaloHadEtInHB);
   fChain->SetBranchAddress("CaloHadEtInHE", &CaloHadEtInHE, &b_CaloHadEtInHE);
   fChain->SetBranchAddress("CaloHadEtInHO", &CaloHadEtInHO, &b_CaloHadEtInHO);
   fChain->SetBranchAddress("CaloHadEtInHF", &CaloHadEtInHF, &b_CaloHadEtInHF);
   fChain->SetBranchAddress("CaloEmEtInEB", &CaloEmEtInEB, &b_CaloEmEtInEB);
   fChain->SetBranchAddress("CaloEmEtInEE", &CaloEmEtInEE, &b_CaloEmEtInEE);
   fChain->SetBranchAddress("CaloEmEtInHF", &CaloEmEtInHF, &b_CaloEmEtInHF);
   fChain->SetBranchAddress("CaloMaxEtInEmTowers", &CaloMaxEtInEmTowers, &b_CaloMaxEtInEmTowers);
   fChain->SetBranchAddress("CaloMaxEtInHadTowers", &CaloMaxEtInHadTowers, &b_CaloMaxEtInHadTowers);
   fChain->SetBranchAddress("CaloMetPt", CaloMetPt, &b_CaloMetPt);
   fChain->SetBranchAddress("CaloMetPx", CaloMetPx, &b_CaloMetPx);
   fChain->SetBranchAddress("CaloMetPy", CaloMetPy, &b_CaloMetPy);
   fChain->SetBranchAddress("CaloMetPhi", CaloMetPhi, &b_CaloMetPhi);
   fChain->SetBranchAddress("CaloMetSumEt", CaloMetSumEt, &b_CaloMetSumEt);
   fChain->SetBranchAddress("Delta_phi", &Delta_phi, &b_Delta_phi);
   fChain->SetBranchAddress("PFMetPt", PFMetPt, &b_PFMetPt);
   fChain->SetBranchAddress("PFMetPx", PFMetPx, &b_PFMetPx);
   fChain->SetBranchAddress("PFMetPy", PFMetPy, &b_PFMetPy);
   fChain->SetBranchAddress("PFMetPhi", PFMetPhi, &b_PFMetPhi);
   fChain->SetBranchAddress("PFMetSumEt", PFMetSumEt, &b_PFMetSumEt);
   fChain->SetBranchAddress("Delta_phiPF", &Delta_phiPF, &b_Delta_phiPF);
   fChain->SetBranchAddress("TCMetPt", TCMetPt, &b_TCMetPt);
   fChain->SetBranchAddress("TCMetPx", TCMetPx, &b_TCMetPx);
   fChain->SetBranchAddress("TCMetPy", TCMetPy, &b_TCMetPy);
   fChain->SetBranchAddress("TCMetPhi", TCMetPhi, &b_TCMetPhi);
   fChain->SetBranchAddress("TCMetSumEt", TCMetSumEt, &b_TCMetSumEt);
   fChain->SetBranchAddress("Delta_phiTC", &Delta_phiTC, &b_Delta_phiTC);
   fChain->SetBranchAddress("ucPhoton_n", &ucPhoton_n, &b_ucPhoton_n);
   fChain->SetBranchAddress("ucPhoton_E", ucPhoton_E, &b_ucPhoton_E);
   fChain->SetBranchAddress("ucPhoton_pt", ucPhoton_pt, &b_ucPhoton_pt);
   fChain->SetBranchAddress("ucPhoton_eta", ucPhoton_eta, &b_ucPhoton_eta);
   fChain->SetBranchAddress("ucPhoton_phi", ucPhoton_phi, &b_ucPhoton_phi);
   fChain->SetBranchAddress("ucPhoton_theta", ucPhoton_theta, &b_ucPhoton_theta);
   fChain->SetBranchAddress("ucPhoton_et", ucPhoton_et, &b_ucPhoton_et);
   fChain->SetBranchAddress("ucPhoton_swissCross", ucPhoton_swissCross, &b_ucPhoton_swissCross);
   fChain->SetBranchAddress("ucPhoton_e6e2", ucPhoton_e6e2, &b_ucPhoton_e6e2);
   fChain->SetBranchAddress("ucPhoton_e4e1", ucPhoton_e4e1, &b_ucPhoton_e4e1);
   fChain->SetBranchAddress("ucPhotonr9", ucPhotonr9, &b_ucPhotonr9);
   fChain->SetBranchAddress("ucPhoton_e1x5", ucPhoton_e1x5, &b_ucPhoton_e1x5);
   fChain->SetBranchAddress("ucPhoton_e2x5", ucPhoton_e2x5, &b_ucPhoton_e2x5);
   fChain->SetBranchAddress("ucPhoton_e3x3", ucPhoton_e3x3, &b_ucPhoton_e3x3);
   fChain->SetBranchAddress("ucPhoton_e5x5", ucPhoton_e5x5, &b_ucPhoton_e5x5);
   fChain->SetBranchAddress("ucPhoton_r1x5", ucPhoton_r1x5, &b_ucPhoton_r1x5);
   fChain->SetBranchAddress("ucPhoton_r2x5", ucPhoton_r2x5, &b_ucPhoton_r2x5);
   fChain->SetBranchAddress("ucPhoton_maxEnergyXtal", ucPhoton_maxEnergyXtal, &b_ucPhoton_maxEnergyXtal);
   fChain->SetBranchAddress("ucPhoton_SigmaEtaEta", ucPhoton_SigmaEtaEta, &b_ucPhoton_SigmaEtaEta);
   fChain->SetBranchAddress("ucPhoton_SigmaIetaIeta", ucPhoton_SigmaIetaIeta, &b_ucPhoton_SigmaIetaIeta);
   fChain->SetBranchAddress("ucPhoton_SigmaEtaPhi", ucPhoton_SigmaEtaPhi, &b_ucPhoton_SigmaEtaPhi);
   fChain->SetBranchAddress("ucPhoton_SigmaIetaIphi", ucPhoton_SigmaIetaIphi, &b_ucPhoton_SigmaIetaIphi);
   fChain->SetBranchAddress("ucPhoton_SigmaPhiPhi", ucPhoton_SigmaPhiPhi, &b_ucPhoton_SigmaPhiPhi);
   fChain->SetBranchAddress("ucPhoton_SigmaIphiIphi", ucPhoton_SigmaIphiIphi, &b_ucPhoton_SigmaIphiIphi);
   fChain->SetBranchAddress("ucPhoton_Roundness", ucPhoton_Roundness, &b_ucPhoton_Roundness);
   fChain->SetBranchAddress("ucPhoton_Angle", ucPhoton_Angle, &b_ucPhoton_Angle);
   fChain->SetBranchAddress("ucPhoton_ecalRecHitSumEtConeDR03", ucPhoton_ecalRecHitSumEtConeDR03, &b_ucPhoton_ecalRecHitSumEtConeDR03);
   fChain->SetBranchAddress("ucPhoton_hcalTowerSumEtConeDR03", ucPhoton_hcalTowerSumEtConeDR03, &b_ucPhoton_hcalTowerSumEtConeDR03);
   fChain->SetBranchAddress("ucPhoton_trkSumPtSolidConeDR03", ucPhoton_trkSumPtSolidConeDR03, &b_ucPhoton_trkSumPtSolidConeDR03);
   fChain->SetBranchAddress("ucPhoton_trkSumPtHollowConeDR03", ucPhoton_trkSumPtHollowConeDR03, &b_ucPhoton_trkSumPtHollowConeDR03);
   fChain->SetBranchAddress("ucPhoton_nTrkSolidConeDR03", ucPhoton_nTrkSolidConeDR03, &b_ucPhoton_nTrkSolidConeDR03);
   fChain->SetBranchAddress("ucPhoton_nTrkHollowConeDR03", ucPhoton_nTrkHollowConeDR03, &b_ucPhoton_nTrkHollowConeDR03);
   fChain->SetBranchAddress("ucPhoton_hcalDepth1TowerSumEtConeDR03", ucPhoton_hcalDepth1TowerSumEtConeDR03, &b_ucPhoton_hcalDepth1TowerSumEtConeDR03);
   fChain->SetBranchAddress("ucPhoton_hcalDepth2TowerSumEtConeDR03", ucPhoton_hcalDepth2TowerSumEtConeDR03, &b_ucPhoton_hcalDepth2TowerSumEtConeDR03);
   fChain->SetBranchAddress("ucPhoton_ecalRecHitSumEtConeDR04", ucPhoton_ecalRecHitSumEtConeDR04, &b_ucPhoton_ecalRecHitSumEtConeDR04);
   fChain->SetBranchAddress("ucPhoton_hcalTowerSumEtConeDR04", ucPhoton_hcalTowerSumEtConeDR04, &b_ucPhoton_hcalTowerSumEtConeDR04);
   fChain->SetBranchAddress("ucPhoton_trkSumPtSolidConeDR04", ucPhoton_trkSumPtSolidConeDR04, &b_ucPhoton_trkSumPtSolidConeDR04);
   fChain->SetBranchAddress("ucPhoton_trkSumPtHollowConeDR04", ucPhoton_trkSumPtHollowConeDR04, &b_ucPhoton_trkSumPtHollowConeDR04);
   fChain->SetBranchAddress("ucPhoton_nTrkSolidConeDR04", ucPhoton_nTrkSolidConeDR04, &b_ucPhoton_nTrkSolidConeDR04);
   fChain->SetBranchAddress("ucPhoton_nTrkHollowConeDR04", ucPhoton_nTrkHollowConeDR04, &b_ucPhoton_nTrkHollowConeDR04);
   fChain->SetBranchAddress("ucPhoton_hcalDepth1TowerSumEtConeDR04", ucPhoton_hcalDepth1TowerSumEtConeDR04, &b_ucPhoton_hcalDepth1TowerSumEtConeDR04);
   fChain->SetBranchAddress("ucPhoton_hcalDepth2TowerSumEtConeDR04", ucPhoton_hcalDepth2TowerSumEtConeDR04, &b_ucPhoton_hcalDepth2TowerSumEtConeDR04);
   fChain->SetBranchAddress("ucPhoton_hasPixelSeed", ucPhoton_hasPixelSeed, &b_ucPhoton_hasPixelSeed);
   fChain->SetBranchAddress("ucPhoton_isEB", ucPhoton_isEB, &b_ucPhoton_isEB);
   fChain->SetBranchAddress("ucPhoton_isEE", ucPhoton_isEE, &b_ucPhoton_isEE);
   fChain->SetBranchAddress("ucPhoton_isEBGap", ucPhoton_isEBGap, &b_ucPhoton_isEBGap);
   fChain->SetBranchAddress("ucPhoton_isEEGap", ucPhoton_isEEGap, &b_ucPhoton_isEEGap);
   fChain->SetBranchAddress("ucPhoton_isEBEEGap", ucPhoton_isEBEEGap, &b_ucPhoton_isEBEEGap);
   fChain->SetBranchAddress("ucPhoton_e2e9", ucPhoton_e2e9, &b_ucPhoton_e2e9);
   fChain->SetBranchAddress("ucPhoton_HoE", ucPhoton_HoE, &b_ucPhoton_HoE);
   fChain->SetBranchAddress("ucPhoton_HoEnew", ucPhoton_HoEnew, &b_ucPhoton_HoEnew);
   fChain->SetBranchAddress("ucPhoton_px", ucPhoton_px, &b_ucPhoton_px);
   fChain->SetBranchAddress("ucPhoton_py", ucPhoton_py, &b_ucPhoton_py);
   fChain->SetBranchAddress("ucPhoton_pz", ucPhoton_pz, &b_ucPhoton_pz);
   fChain->SetBranchAddress("ucPhoton_vx", ucPhoton_vx, &b_ucPhoton_vx);
   fChain->SetBranchAddress("ucPhoton_vy", ucPhoton_vy, &b_ucPhoton_vy);
   fChain->SetBranchAddress("ucPhoton_vz", ucPhoton_vz, &b_ucPhoton_vz);
   fChain->SetBranchAddress("ucPhoton_no_of_basic_clusters", ucPhoton_no_of_basic_clusters, &b_ucPhoton_no_of_basic_clusters);
   fChain->SetBranchAddress("ucPhoton_sc_energy", ucPhoton_sc_energy, &b_ucPhoton_sc_energy);
   fChain->SetBranchAddress("ucPhoton_sc_eta", ucPhoton_sc_eta, &b_ucPhoton_sc_eta);
   fChain->SetBranchAddress("ucPhoton_sc_phi", ucPhoton_sc_phi, &b_ucPhoton_sc_phi);
   fChain->SetBranchAddress("ucPhoton_sc_x", ucPhoton_sc_x, &b_ucPhoton_sc_x);
   fChain->SetBranchAddress("ucPhoton_sc_y", ucPhoton_sc_y, &b_ucPhoton_sc_y);
   fChain->SetBranchAddress("ucPhoton_sc_z", ucPhoton_sc_z, &b_ucPhoton_sc_z);
   fChain->SetBranchAddress("ucPhoton_etaWidth", ucPhoton_etaWidth, &b_ucPhoton_etaWidth);
   fChain->SetBranchAddress("ucPhoton_phiWidth", ucPhoton_phiWidth, &b_ucPhoton_phiWidth);
   fChain->SetBranchAddress("ucPhoton_sc_et", ucPhoton_sc_et, &b_ucPhoton_sc_et);
   fChain->SetBranchAddress("matchucphotonE", matchucphotonE, &b_matchucphotonE);
   fChain->SetBranchAddress("matchucphotonpt", matchucphotonpt, &b_matchucphotonpt);
   fChain->SetBranchAddress("matchucphotoneta", matchucphotoneta, &b_matchucphotoneta);
   fChain->SetBranchAddress("matchucphotonphi", matchucphotonphi, &b_matchucphotonphi);
   fChain->SetBranchAddress("matchucphotonpx", matchucphotonpx, &b_matchucphotonpx);
   fChain->SetBranchAddress("matchucphotonpy", matchucphotonpy, &b_matchucphotonpy);
   fChain->SetBranchAddress("matchucphotonpz", matchucphotonpz, &b_matchucphotonpz);
   fChain->SetBranchAddress("ismatcheducphoton", ismatcheducphoton, &b_ismatcheducphoton);
   fChain->SetBranchAddress("ucPhoton_hasConvTrk", ucPhoton_hasConvTrk, &b_ucPhoton_hasConvTrk);
   fChain->SetBranchAddress("ucPhoton_ntracks", ucPhoton_ntracks, &b_ucPhoton_ntracks);
   fChain->SetBranchAddress("ucPhoton_isconverted", ucPhoton_isconverted, &b_ucPhoton_isconverted);
   fChain->SetBranchAddress("ucPhoton_pairInvmass", ucPhoton_pairInvmass, &b_ucPhoton_pairInvmass);
   fChain->SetBranchAddress("ucPhoton_pairCotThetaSeperation", ucPhoton_pairCotThetaSeperation, &b_ucPhoton_pairCotThetaSeperation);
   fChain->SetBranchAddress("ucPhoton_pairmomentumX", ucPhoton_pairmomentumX, &b_ucPhoton_pairmomentumX);
   fChain->SetBranchAddress("ucPhoton_pairmomentumY", ucPhoton_pairmomentumY, &b_ucPhoton_pairmomentumY);
   fChain->SetBranchAddress("ucPhoton_pairmomentumZ", ucPhoton_pairmomentumZ, &b_ucPhoton_pairmomentumZ);
   fChain->SetBranchAddress("ucPhoton_EoverP", ucPhoton_EoverP, &b_ucPhoton_EoverP);
   fChain->SetBranchAddress("ucPhoton_ConvVx", ucPhoton_ConvVx, &b_ucPhoton_ConvVx);
   fChain->SetBranchAddress("ucPhoton_ConvVy", ucPhoton_ConvVy, &b_ucPhoton_ConvVy);
   fChain->SetBranchAddress("ucPhoton_ConvVz", ucPhoton_ConvVz, &b_ucPhoton_ConvVz);
   fChain->SetBranchAddress("ucPhoton_ZOfPrimaryVertex", ucPhoton_ZOfPrimaryVertex, &b_ucPhoton_ZOfPrimaryVertex);
   fChain->SetBranchAddress("ucPhoton_distOfMinimumApproach", ucPhoton_distOfMinimumApproach, &b_ucPhoton_distOfMinimumApproach);
   fChain->SetBranchAddress("ucPhoton_dPhiTracksAtVtx", ucPhoton_dPhiTracksAtVtx, &b_ucPhoton_dPhiTracksAtVtx);
   fChain->SetBranchAddress("ucPhoton_dPhiTracksAtEcal", ucPhoton_dPhiTracksAtEcal, &b_ucPhoton_dPhiTracksAtEcal);
   fChain->SetBranchAddress("ucPhoton_dEtaTracksAtEcal", ucPhoton_dEtaTracksAtEcal, &b_ucPhoton_dEtaTracksAtEcal);
   fChain->SetBranchAddress("ucPhoton_ncrys", ucPhoton_ncrys, &b_ucPhoton_ncrys);
   fChain->SetBranchAddress("ucPhoton_timing_xtal", ucPhoton_timing_xtal, &b_ucPhoton_timing_xtal);
   fChain->SetBranchAddress("ucPhoton_timingavg_xtal", ucPhoton_timingavg_xtal, &b_ucPhoton_timingavg_xtal);
   fChain->SetBranchAddress("ucPhoton_energy_xtal", ucPhoton_energy_xtal, &b_ucPhoton_energy_xtal);
   fChain->SetBranchAddress("ucPhoton_ieta_xtalEB", ucPhoton_ieta_xtalEB, &b_ucPhoton_ieta_xtalEB);
   fChain->SetBranchAddress("ucPhoton_iphi_xtalEB", ucPhoton_iphi_xtalEB, &b_ucPhoton_iphi_xtalEB);
   fChain->SetBranchAddress("ucPhoton_recoFlag_xtalEB", ucPhoton_recoFlag_xtalEB, &b_ucPhoton_recoFlag_xtalEB);
   fChain->SetBranchAddress("ucPhoton_timeError_xtal", ucPhoton_timeError_xtal, &b_ucPhoton_timeError_xtal);
   fChain->SetBranchAddress("ucPhoton_s9", ucPhoton_s9, &b_ucPhoton_s9);
   fChain->SetBranchAddress("ucHERecHit_subset_n", &ucHERecHit_subset_n, &b_ucHERecHit_subset_n);
   fChain->SetBranchAddress("ucHERecHit_subset_detid", ucHERecHit_subset_detid, &b_ucHERecHit_subset_detid);
   fChain->SetBranchAddress("ucHERecHit_subset_energy", ucHERecHit_subset_energy, &b_ucHERecHit_subset_energy);
   fChain->SetBranchAddress("ucHERecHit_subset_time", ucHERecHit_subset_time, &b_ucHERecHit_subset_time);
   fChain->SetBranchAddress("ucHERecHit_subset_depth", ucHERecHit_subset_depth, &b_ucHERecHit_subset_depth);
   fChain->SetBranchAddress("ucHERecHit_subset_phi", ucHERecHit_subset_phi, &b_ucHERecHit_subset_phi);
   fChain->SetBranchAddress("ucHERecHit_subset_eta", ucHERecHit_subset_eta, &b_ucHERecHit_subset_eta);
   fChain->SetBranchAddress("ucHERecHit_subset_x", ucHERecHit_subset_x, &b_ucHERecHit_subset_x);
   fChain->SetBranchAddress("ucHERecHit_subset_y", ucHERecHit_subset_y, &b_ucHERecHit_subset_y);
   fChain->SetBranchAddress("ucHERecHit_subset_z", ucHERecHit_subset_z, &b_ucHERecHit_subset_z);
   fChain->SetBranchAddress("ucPhoton_mipChi2", ucPhoton_mipChi2, &b_ucPhoton_mipChi2);
   fChain->SetBranchAddress("ucPhoton_mipTotEnergy", ucPhoton_mipTotEnergy, &b_ucPhoton_mipTotEnergy);
   fChain->SetBranchAddress("ucPhoton_mipSlope", ucPhoton_mipSlope, &b_ucPhoton_mipSlope);
   fChain->SetBranchAddress("ucPhoton_mipIntercept", ucPhoton_mipIntercept, &b_ucPhoton_mipIntercept);
   fChain->SetBranchAddress("ucPhoton_mipNhitCone", ucPhoton_mipNhitCone, &b_ucPhoton_mipNhitCone);
   fChain->SetBranchAddress("ucPhoton_mipIsHalo", ucPhoton_mipIsHalo, &b_ucPhoton_mipIsHalo);
   fChain->SetBranchAddress("CaloTower_n", &CaloTower_n, &b_CaloTower_n);
   fChain->SetBranchAddress("CaloTower_eta", CaloTower_eta, &b_CaloTower_eta);
   fChain->SetBranchAddress("CaloTower_phi", CaloTower_phi, &b_CaloTower_phi);
   fChain->SetBranchAddress("CaloTower_E", CaloTower_E, &b_CaloTower_E);
   fChain->SetBranchAddress("CaloTower_Et", CaloTower_Et, &b_CaloTower_Et);
   fChain->SetBranchAddress("CaloTower_emEnergy", CaloTower_emEnergy, &b_CaloTower_emEnergy);
   fChain->SetBranchAddress("CaloTower_hadEnergy", CaloTower_hadEnergy, &b_CaloTower_hadEnergy);
   fChain->SetBranchAddress("CaloTower_p", CaloTower_p, &b_CaloTower_p);
   fChain->SetBranchAddress("CaloTower_EMEt", CaloTower_EMEt, &b_CaloTower_EMEt);
   fChain->SetBranchAddress("CaloTower_HadEt", CaloTower_HadEt, &b_CaloTower_HadEt);
   fChain->SetBranchAddress("CaloTower_HadPhi", CaloTower_HadPhi, &b_CaloTower_HadPhi);
   fChain->SetBranchAddress("CaloTower_HadEta", CaloTower_HadEta, &b_CaloTower_HadEta);
   fChain->SetBranchAddress("CaloTower_EMPhi", CaloTower_EMPhi, &b_CaloTower_EMPhi);
   fChain->SetBranchAddress("CaloTower_EMEta", CaloTower_EMEta, &b_CaloTower_EMEta);
   fChain->SetBranchAddress("CaloTower_HadX", CaloTower_HadX, &b_CaloTower_HadX);
   fChain->SetBranchAddress("CaloTower_HadY", CaloTower_HadY, &b_CaloTower_HadY);
   fChain->SetBranchAddress("CaloTower_HadZ", CaloTower_HadZ, &b_CaloTower_HadZ);
   fChain->SetBranchAddress("CaloTower_HE_E", CaloTower_HE_E, &b_CaloTower_HE_E);
   fChain->SetBranchAddress("CaloTower_HB_E", CaloTower_HB_E, &b_CaloTower_HB_E);
   fChain->SetBranchAddress("CaloTower_EMTime", CaloTower_EMTime, &b_CaloTower_EMTime);
   fChain->SetBranchAddress("CaloTower_HadTime", CaloTower_HadTime, &b_CaloTower_HadTime);
   fChain->SetBranchAddress("rho", &rho, &b_rho);
   fChain->SetBranchAddress("sigma", &sigma, &b_sigma);
   fChain->SetBranchAddress("rho25", &rho25, &b_rho25);
   fChain->SetBranchAddress("sigma25", &sigma25, &b_sigma25);
   Notify();
}

Bool_t myPlot::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void myPlot::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t myPlot::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef myPlot_cxx


