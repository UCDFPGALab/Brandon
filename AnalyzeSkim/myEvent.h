//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Jul 17 11:51:40 2013 by ROOT version 5.34/00
// from TTree myEvent/a tree with histograms
// found on file: skim.root
//////////////////////////////////////////////////////////

#ifndef myClass_h
#define myClass_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <iostream>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>
#include <vector>
#include <vector>
using namespace std;

// Fixed size dimensions of array or collections stored in the TTree if any.

class myClass {
public :
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
   Float_t         Vertex_x[37];   //[Vertex_n]
   Float_t         Vertex_y[37];   //[Vertex_n]
   Float_t         Vertex_z[37];   //[Vertex_n]
   Int_t           Vertex_tracksize[37];   //[Vertex_n]
   Int_t           Vertex_ndof[37];   //[Vertex_n]
   Float_t         Vertex_chi2[37];   //[Vertex_n]
   Float_t         Vertex_d0[37];   //[Vertex_n]
   Bool_t          Vertex_isFake[37];   //[Vertex_n]
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
   Int_t           pfJet_n;
   Float_t         pfJet_px[50];   //[pfJet_n]
   Float_t         pfJet_py[50];   //[pfJet_n]
   Float_t         pfJet_E[50];   //[pfJet_n]
   Float_t         pfJet_pz[50];   //[pfJet_n]
   Float_t         pfJet_vx[50];   //[pfJet_n]
   Float_t         pfJet_vy[50];   //[pfJet_n]
   Float_t         pfJet_vz[50];   //[pfJet_n]
   Float_t         pfJet_pt[50];   //[pfJet_n]
   Float_t         pfJet_eta[50];   //[pfJet_n]
   Float_t         pfJet_phi[50];   //[pfJet_n]
   Float_t         pfjet_CEF[50];   //[pfJet_n]
   Float_t         pfjet_CHF[50];   //[pfJet_n]
   Float_t         pfjet_NEF[50];   //[pfJet_n]
   Float_t         pfjet_NHF[50];   //[pfJet_n]
   Int_t           pfjet_NCH[50];   //[pfJet_n]
   Float_t         pfjet_HFHAE[50];   //[pfJet_n]
   Float_t         pfjet_HFEME[50];   //[pfJet_n]
   Int_t           pfjet_NConstituents[50];   //[pfJet_n]
   Int_t           pfJet_partonFlavor[50];   //[pfJet_n]
   Int_t           pfJet_partonStatus[50];   //[pfJet_n]
   Float_t         pujetIdFull_mva[50];   //[pfJet_n]
   Float_t         pujetIdSimple_mva[50];   //[pfJet_n]
   Float_t         pujetIdCutBased_mva[50];   //[pfJet_n]
   Int_t           pujetIdFull_loose[50];   //[pfJet_n]
   Int_t           pujetIdFull_medium[50];   //[pfJet_n]
   Int_t           pujetIdFull_tight[50];   //[pfJet_n]
   Int_t           pujetIdSimple_loose[50];   //[pfJet_n]
   Int_t           pujetIdSimple_medium[50];   //[pfJet_n]
   Int_t           pujetIdSimple_tight[50];   //[pfJet_n]
   Int_t           pujetIdCutBased_loose[50];   //[pfJet_n]
   Int_t           pujetIdCutBased_medium[50];   //[pfJet_n]
   Int_t           pujetIdCutBased_tight[50];   //[pfJet_n]
   Float_t         pfjet_TrackCountHiEffBJetTags[50];   //[pfJet_n]
   Float_t         pfjet_TrackCountHiPurBJetTags[50];   //[pfJet_n]
   Float_t         pfjet_SimpleSVHiEffBJetTags[50];   //[pfJet_n]
   Float_t         pfjet_SimpleSVHiPurBJetTags[50];   //[pfJet_n]
   Float_t         pfJet_jecUncer[50];   //[pfJet_n]
   Float_t         pfJet_jecCorr[50];   //[pfJet_n]
   Float_t         ucpfJet_px[50];   //[pfJet_n]
   Float_t         ucpfJet_py[50];   //[pfJet_n]
   Float_t         ucpfJet_E[50];   //[pfJet_n]
   Float_t         ucpfJet_pz[50];   //[pfJet_n]
   Float_t         ucpfJet_pt[50];   //[pfJet_n]
   Float_t         ucpfJet_eta[50];   //[pfJet_n]
   Float_t         ucpfJet_phi[50];   //[pfJet_n]
   Int_t           Electron_n;
   Float_t         Electron_px[8];   //[Electron_n]
   Float_t         Electron_py[8];   //[Electron_n]
   Float_t         Electron_pz[8];   //[Electron_n]
   Float_t         Electron_vx[8];   //[Electron_n]
   Float_t         Electron_vy[8];   //[Electron_n]
   Float_t         Electron_vz[8];   //[Electron_n]
   Float_t         Electron_pt[8];   //[Electron_n]
   Float_t         Electron_eta[8];   //[Electron_n]
   Float_t         Electron_phi[8];   //[Electron_n]
   Float_t         Electron_energy[8];   //[Electron_n]
   Float_t         Electron_charge[8];   //[Electron_n]
   Float_t         Electron_trkIso[8];   //[Electron_n]
   Float_t         Electron_ecalIso[8];   //[Electron_n]
   Float_t         Electron_hcalIso[8];   //[Electron_n]
   Float_t         Electron_SigmaIetaIeta[8];   //[Electron_n]
   Float_t         Electron_dEtaIn[8];   //[Electron_n]
   Float_t         Electron_dPhiIn[8];   //[Electron_n]
   Float_t         Electron_HoE[8];   //[Electron_n]
   Float_t         Electron_sc_energy[8];   //[Electron_n]
   Float_t         Electron_sc_eta[8];   //[Electron_n]
   Float_t         Electron_sc_phi[8];   //[Electron_n]
   Int_t           Muon_n;
   Float_t         Muon_px[46];   //[Muon_n]
   Float_t         Muon_py[46];   //[Muon_n]
   Float_t         Muon_pz[46];   //[Muon_n]
   Float_t         Muon_vx[46];   //[Muon_n]
   Float_t         Muon_vy[46];   //[Muon_n]
   Float_t         Muon_vz[46];   //[Muon_n]
   Float_t         Muon_pt[46];   //[Muon_n]
   Float_t         Muon_eta[46];   //[Muon_n]
   Float_t         Muon_phi[46];   //[Muon_n]
   Float_t         Muon_energy[46];   //[Muon_n]
   Float_t         Muon_charge[46];   //[Muon_n]
   Bool_t          Muon_isGlobalMuon[46];   //[Muon_n]
   Bool_t          Muon_isTrackerMuon[46];   //[Muon_n]
   Bool_t          Muon_isStandAloneMuon[46];   //[Muon_n]
   Bool_t          Muon_InnerTrack_isNonnull[46];   //[Muon_n]
   Bool_t          Muon_OuterTrack_isNonnull[46];   //[Muon_n]
   Float_t         Muon_OuterTrack_InnerPoint_x[46];   //[Muon_n]
   Float_t         Muon_OuterTrack_InnerPoint_y[46];   //[Muon_n]
   Float_t         Muon_OuterTrack_InnerPoint_z[46];   //[Muon_n]
   Float_t         Muon_OuterTrack_InnerPoint_px[46];   //[Muon_n]
   Float_t         Muon_OuterTrack_InnerPoint_py[46];   //[Muon_n]
   Float_t         Muon_OuterTrack_InnerPoint_pz[46];   //[Muon_n]
   Float_t         Muon_OuterTrack_OuterPoint_x[46];   //[Muon_n]
   Float_t         Muon_OuterTrack_OuterPoint_y[46];   //[Muon_n]
   Float_t         Muon_OuterTrack_OuterPoint_z[46];   //[Muon_n]
   Float_t         Muon_OuterTrack_OuterPoint_px[46];   //[Muon_n]
   Float_t         Muon_OuterTrack_OuterPoint_py[46];   //[Muon_n]
   Float_t         Muon_OuterTrack_OuterPoint_pz[46];   //[Muon_n]
   Float_t         Muon_InnerTrack_InnerPoint_x[46];   //[Muon_n]
   Float_t         Muon_InnerTrack_InnerPoint_y[46];   //[Muon_n]
   Float_t         Muon_InnerTrack_InnerPoint_z[46];   //[Muon_n]
   Float_t         Muon_InnerTrack_InnerPoint_px[46];   //[Muon_n]
   Float_t         Muon_InnerTrack_InnerPoint_py[46];   //[Muon_n]
   Float_t         Muon_InnerTrack_InnerPoint_pz[46];   //[Muon_n]
   Float_t         Muon_InnerTrack_OuterPoint_x[46];   //[Muon_n]
   Float_t         Muon_InnerTrack_OuterPoint_y[46];   //[Muon_n]
   Float_t         Muon_InnerTrack_OuterPoint_z[46];   //[Muon_n]
   Float_t         Muon_InnerTrack_OuterPoint_px[46];   //[Muon_n]
   Float_t         Muon_InnerTrack_OuterPoint_py[46];   //[Muon_n]
   Float_t         Muon_InnerTrack_OuterPoint_pz[46];   //[Muon_n]
   Float_t         Muon_trackIso[46];   //[Muon_n]
   Float_t         Muon_ecalIso[46];   //[Muon_n]
   Float_t         Muon_hcalIso[46];   //[Muon_n]
   Float_t         Muon_relIso[46];   //[Muon_n]
   Int_t           Muon_normChi2[46];   //[Muon_n]
   Int_t           Muon_validHits[46];   //[Muon_n]
   Int_t           Muon_tkHits[46];   //[Muon_n]
   Int_t           Muon_pixHits[46];   //[Muon_n]
   Int_t           Muon_numberOfMatches[46];   //[Muon_n]
   Float_t         Muon_OuterPoint_x[46];   //[Muon_n]
   Float_t         Muon_OuterPoint_y[46];   //[Muon_n]
   Float_t         Muon_OuterPoint_z[46];   //[Muon_n]
   Float_t         Muon_InnerPoint_x[46];   //[Muon_n]
   Float_t         Muon_InnerPoint_y[46];   //[Muon_n]
   Float_t         Muon_InnerPoint_z[46];   //[Muon_n]
   Int_t           CosmicMuon_n;
   Float_t         CosmicMuon_px[28];   //[CosmicMuon_n]
   Float_t         CosmicMuon_py[28];   //[CosmicMuon_n]
   Float_t         CosmicMuon_pz[28];   //[CosmicMuon_n]
   Float_t         CosmicMuon_pt[28];   //[CosmicMuon_n]
   Float_t         CosmicMuon_eta[28];   //[CosmicMuon_n]
   Float_t         CosmicMuon_phi[28];   //[CosmicMuon_n]
   Float_t         CosmicMuon_energy[28];   //[CosmicMuon_n]
   Float_t         CosmicMuon_charge[28];   //[CosmicMuon_n]
   Bool_t          CosmicMuon_isGlobalMuon[28];   //[CosmicMuon_n]
   Bool_t          CosmicMuon_isTrackerMuon[28];   //[CosmicMuon_n]
   Bool_t          CosmicMuon_isStandAloneMuon[28];   //[CosmicMuon_n]
   Bool_t          CosmicMuon_InnerTrack_isNonnull[28];   //[CosmicMuon_n]
   Bool_t          CosmicMuon_OuterTrack_isNonnull[28];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_InnerPoint_x[28];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_InnerPoint_y[28];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_InnerPoint_z[28];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_InnerPoint_px[28];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_InnerPoint_py[28];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_InnerPoint_pz[28];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_OuterPoint_x[28];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_OuterPoint_y[28];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_OuterPoint_z[28];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_OuterPoint_px[28];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_OuterPoint_py[28];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_OuterPoint_pz[28];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_InnerPoint_x[28];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_InnerPoint_y[28];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_InnerPoint_z[28];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_InnerPoint_px[28];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_InnerPoint_py[28];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_InnerPoint_pz[28];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_OuterPoint_x[28];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_OuterPoint_y[28];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_OuterPoint_z[28];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_OuterPoint_px[28];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_OuterPoint_py[28];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_OuterPoint_pz[28];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterPoint_x[28];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterPoint_y[28];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterPoint_z[28];   //[CosmicMuon_n]
   Int_t           Tau_n;
   Float_t         Tau_px[100];   //[Tau_n]
   Float_t         Tau_py[100];   //[Tau_n]
   Float_t         Tau_pz[100];   //[Tau_n]
   Float_t         Tau_vx[100];   //[Tau_n]
   Float_t         Tau_vy[100];   //[Tau_n]
   Float_t         Tau_vz[100];   //[Tau_n]
   Float_t         Tau_pt[100];   //[Tau_n]
   Float_t         Tau_eta[100];   //[Tau_n]
   Float_t         Tau_phi[100];   //[Tau_n]
   Float_t         Tau_energy[100];   //[Tau_n]
   Float_t         Tau_charge[100];   //[Tau_n]
   Int_t           Photon_n;
   Float_t         Photon_E[20];   //[Photon_n]
   Float_t         Photon_pt[20];   //[Photon_n]
   Float_t         Photon_eta[20];   //[Photon_n]
   Float_t         Photon_phi[20];   //[Photon_n]
   Float_t         Photon_theta[20];   //[Photon_n]
   Float_t         Photon_et[20];   //[Photon_n]
   Float_t         Photon_swissCross[20];   //[Photon_n]
   Float_t         Photon_e6e2[20];   //[Photon_n]
   Float_t         Photon_e4e1[20];   //[Photon_n]
   Float_t         Photonr9[20];   //[Photon_n]
   Float_t         Photon_e1x5[20];   //[Photon_n]
   Float_t         Photon_e2x5[20];   //[Photon_n]
   Float_t         Photon_e3x3[20];   //[Photon_n]
   Float_t         Photon_e5x5[20];   //[Photon_n]
   Float_t         Photon_r1x5[20];   //[Photon_n]
   Float_t         Photon_r2x5[20];   //[Photon_n]
   Float_t         Photon_maxEnergyXtal[20];   //[Photon_n]
   Float_t         Photon_SigmaEtaEta[20];   //[Photon_n]
   Float_t         Photon_SigmaIetaIeta[20];   //[Photon_n]
   Float_t         Photon_SigmaEtaPhi[20];   //[Photon_n]
   Float_t         Photon_SigmaIetaIphi[20];   //[Photon_n]
   Float_t         Photon_SigmaPhiPhi[20];   //[Photon_n]
   Float_t         Photon_SigmaIphiIphi[20];   //[Photon_n]
   Float_t         Photon_Roundness[20];   //[Photon_n]
   Float_t         Photon_Angle[20];   //[Photon_n]
   Float_t         Photon_ecalRecHitSumEtConeDR03[20];   //[Photon_n]
   Float_t         Photon_hcalTowerSumEtConeDR03[20];   //[Photon_n]
   Float_t         Photon_trkSumPtSolidConeDR03[20];   //[Photon_n]
   Float_t         Photon_trkSumPtHollowConeDR03[20];   //[Photon_n]
   Int_t           Photon_nTrkSolidConeDR03[20];   //[Photon_n]
   Int_t           Photon_nTrkHollowConeDR03[20];   //[Photon_n]
   Float_t         Photon_hcalDepth1TowerSumEtConeDR03[20];   //[Photon_n]
   Float_t         Photon_hcalDepth2TowerSumEtConeDR03[20];   //[Photon_n]
   Float_t         Photon_ecalRecHitSumEtConeDR04[20];   //[Photon_n]
   Float_t         Photon_hcalTowerSumEtConeDR04[20];   //[Photon_n]
   Float_t         Photon_trkSumPtSolidConeDR04[20];   //[Photon_n]
   Float_t         Photon_trkSumPtHollowConeDR04[20];   //[Photon_n]
   Int_t           Photon_nTrkSolidConeDR04[20];   //[Photon_n]
   Int_t           Photon_nTrkHollowConeDR04[20];   //[Photon_n]
   Float_t         Photon_hcalDepth1TowerSumEtConeDR04[20];   //[Photon_n]
   Float_t         Photon_hcalDepth2TowerSumEtConeDR04[20];   //[Photon_n]
   Bool_t          Photon_hasPixelSeed[20];   //[Photon_n]
   Bool_t          Photon_isEB[20];   //[Photon_n]
   Bool_t          Photon_isEE[20];   //[Photon_n]
   Bool_t          Photon_isEBGap[20];   //[Photon_n]
   Bool_t          Photon_isEEGap[20];   //[Photon_n]
   Bool_t          Photon_isEBEEGap[20];   //[Photon_n]
   Float_t         Photon_e2e9[20];   //[Photon_n]
   Float_t         Photon_HoE[20];   //[Photon_n]
   Float_t         Photon_HoEnew[20];   //[Photon_n]
   Float_t         Photon_px[20];   //[Photon_n]
   Float_t         Photon_py[20];   //[Photon_n]
   Float_t         Photon_pz[20];   //[Photon_n]
   Float_t         Photon_vx[20];   //[Photon_n]
   Float_t         Photon_vy[20];   //[Photon_n]
   Float_t         Photon_vz[20];   //[Photon_n]
   Int_t           Photon_no_of_basic_clusters[20];   //[Photon_n]
   Float_t         Photon_sc_energy[20];   //[Photon_n]
   Float_t         Photon_sc_eta[20];   //[Photon_n]
   Float_t         Photon_sc_phi[20];   //[Photon_n]
   Float_t         Photon_sc_x[20];   //[Photon_n]
   Float_t         Photon_sc_y[20];   //[Photon_n]
   Float_t         Photon_sc_z[20];   //[Photon_n]
   Float_t         Photon_etaWidth[20];   //[Photon_n]
   Float_t         Photon_phiWidth[20];   //[Photon_n]
   Float_t         Photon_sc_et[20];   //[Photon_n]
   Float_t         matchphotonE[20];   //[Photon_n]
   Float_t         matchphotonpt[20];   //[Photon_n]
   Float_t         matchphotoneta[20];   //[Photon_n]
   Float_t         matchphotonphi[20];   //[Photon_n]
   Float_t         matchphotonpx[20];   //[Photon_n]
   Float_t         matchphotonpy[20];   //[Photon_n]
   Float_t         matchphotonpz[20];   //[Photon_n]
   Bool_t          ismatchedphoton[20];   //[Photon_n]
   Bool_t          Photon_hasConvTrk[20];   //[Photon_n]
   Int_t           Photon_ntracks[20];   //[Photon_n]
   Bool_t          Photon_isconverted[20];   //[Photon_n]
   Float_t         Photon_pairInvmass[20];   //[Photon_n]
   Float_t         Photon_pairCotThetaSeperation[20];   //[Photon_n]
   Float_t         Photon_pairmomentumX[20];   //[Photon_n]
   Float_t         Photon_pairmomentumY[20];   //[Photon_n]
   Float_t         Photon_pairmomentumZ[20];   //[Photon_n]
   Float_t         Photon_EoverP[20];   //[Photon_n]
   Float_t         Photon_ConvVx[20];   //[Photon_n]
   Float_t         Photon_ConvVy[20];   //[Photon_n]
   Float_t         Photon_ConvVz[20];   //[Photon_n]
   Float_t         Photon_ZOfPrimaryVertex[20];   //[Photon_n]
   Float_t         Photon_distOfMinimumApproach[20];   //[Photon_n]
   Float_t         Photon_dPhiTracksAtVtx[20];   //[Photon_n]
   Float_t         Photon_dPhiTracksAtEcal[20];   //[Photon_n]
   Float_t         Photon_dEtaTracksAtEcal[20];   //[Photon_n]
   Int_t           npho;
   Bool_t          Photon_Electronveto[20];   //[npho]
   Float_t         PFiso_Charged03[20];   //[npho]
   Float_t         PFiso_Photon03[20];   //[npho]
   Float_t         PFiso_Neutral03[20];   //[npho]
   Float_t         PFiso_Sum03[20];   //[npho]
   Float_t         PFWorstiso_Charged03[20];   //[npho]
   Int_t           Photon_ncrys[20];   //[Photon_n]
   Float_t         Photon_timing_xtal[20][100];   //[Photon_n]
   Float_t         Photon_timingavg_xtal[20];   //[Photon_n]
   Float_t         Photon_energy_xtal[20][100];   //[Photon_n]
   Int_t           Photon_ieta_xtalEB[20][100];   //[Photon_n]
   Int_t           Photon_iphi_xtalEB[20][100];   //[Photon_n]
   Int_t           Photon_recoFlag_xtalEB[20][100];   //[Photon_n]
   Float_t         Photon_timeError_xtal[20][100];   //[Photon_n]
   Float_t         Photon_s9[20];   //[Photon_n]
   Float_t         Photon_mipChi2[20];   //[Photon_n]
   Float_t         Photon_mipTotEnergy[20];   //[Photon_n]
   Float_t         Photon_mipSlope[20];   //[Photon_n]
   Float_t         Photon_mipIntercept[20];   //[Photon_n]
   Int_t           Photon_mipNhitCone[20];   //[Photon_n]
   Bool_t          Photon_mipIsHalo[20];   //[Photon_n]
   Int_t           EBRecHit_size;
   Float_t         EBRecHit_eta[2526];   //[EBRecHit_size]
   Float_t         EBRecHit_phi[2526];   //[EBRecHit_size]
   Int_t           EBRecHit_ieta[2526];   //[EBRecHit_size]
   Int_t           EBRecHit_iphi[2526];   //[EBRecHit_size]
   Float_t         EBRecHit_e[2526];   //[EBRecHit_size]
   Float_t         EBRecHit_et[2526];   //[EBRecHit_size]
   Int_t           EBRecHit_flag[2526];   //[EBRecHit_size]
   Float_t         EBRecHit_time[2526];   //[EBRecHit_size]
   Int_t           EERecHit_size;
   Float_t         EERecHit_eta[1623];   //[EERecHit_size]
   Float_t         EERecHit_phi[1623];   //[EERecHit_size]
   Int_t           EERecHit_ieta[1623];   //[EERecHit_size]
   Int_t           EERecHit_iphi[1623];   //[EERecHit_size]
   Float_t         EERecHit_e[1623];   //[EERecHit_size]
   Float_t         EERecHit_et[1623];   //[EERecHit_size]
   Int_t           EERecHit_flag[1623];   //[EERecHit_size]
   Float_t         EERecHit_time[1623];   //[EERecHit_size]
   Float_t         PFMetPt[6];
   Float_t         PFMetPx[6];
   Float_t         PFMetPy[6];
   Float_t         PFMetPhi[6];
   Float_t         PFMetSumEt[6];
   Float_t         Delta_phiPF;
   Int_t           CaloTower_n;
   Float_t         CaloTower_eta[2064];   //[CaloTower_n]
   Float_t         CaloTower_phi[2064];   //[CaloTower_n]
   Float_t         CaloTower_E[2064];   //[CaloTower_n]
   Float_t         CaloTower_Et[2064];   //[CaloTower_n]
   Float_t         CaloTower_emEnergy[2064];   //[CaloTower_n]
   Float_t         CaloTower_hadEnergy[2064];   //[CaloTower_n]
   Float_t         CaloTower_p[2064];   //[CaloTower_n]
   Float_t         CaloTower_EMEt[2064];   //[CaloTower_n]
   Float_t         CaloTower_HadEt[2064];   //[CaloTower_n]
   Float_t         CaloTower_HadPhi[2064];   //[CaloTower_n]
   Float_t         CaloTower_HadEta[2064];   //[CaloTower_n]
   Float_t         CaloTower_EMPhi[2064];   //[CaloTower_n]
   Float_t         CaloTower_EMEta[2064];   //[CaloTower_n]
   Float_t         CaloTower_HadX[2064];   //[CaloTower_n]
   Float_t         CaloTower_HadY[2064];   //[CaloTower_n]
   Float_t         CaloTower_HadZ[2064];   //[CaloTower_n]
   Float_t         CaloTower_HE_E[2064];   //[CaloTower_n]
   Float_t         CaloTower_HB_E[2064];   //[CaloTower_n]
   Float_t         CaloTower_EMTime[2064];   //[CaloTower_n]
   Float_t         CaloTower_HadTime[2064];   //[CaloTower_n]
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
   TBranch        *b_pfJet_partonFlavor;   //!
   TBranch        *b_pfJet_partonStatus;   //!
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
   TBranch        *b_npho;   //!
   TBranch        *b_Photon_Electronveto;   //!
   TBranch        *b_PFiso_Charged03;   //!
   TBranch        *b_PFiso_Photon03;   //!
   TBranch        *b_PFiso_Neutral03;   //!
   TBranch        *b_PFiso_Sum03;   //!
   TBranch        *b_PFWorstiso_Charged03;   //!
   TBranch        *b_Photon_ncrys;   //!
   TBranch        *b_Photon_timing_xtal;   //!
   TBranch        *b_Photon_timingavg_xtal;   //!
   TBranch        *b_Photon_energy_xtal;   //!
   TBranch        *b_Photon_ieta_xtalEB;   //!
   TBranch        *b_Photon_iphi_xtalEB;   //!
   TBranch        *b_Photon_recoFlag_xtalEB;   //!
   TBranch        *b_Photon_timeError_xtal;   //!
   TBranch        *b_Photon_s9;   //!
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
   TBranch        *b_PFMetPt;   //!
   TBranch        *b_PFMetPx;   //!
   TBranch        *b_PFMetPy;   //!
   TBranch        *b_PFMetPhi;   //!
   TBranch        *b_PFMetSumEt;   //!
   TBranch        *b_Delta_phiPF;   //!
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

   myClass(TTree *tree=0);
   virtual ~myClass();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);

   //Declare Functions I use
   virtual void histoLoop(Long64_t *nEntries, 
     Long64_t *nTightPho, Long64_t *nMediumPho, 
     Long64_t *nLoosePho, Long64_t *nNoCutPho, 
     Long64_t *nLooseEvents, Long64_t *nEventsOneL, 
     Long64_t *nEventsTwoL, Long64_t *nEventsGTTwoL, 
     float *lowestLoosePt, float *lowestTightPt);
   float calculateDeltaR(int i, int j);
   void histoDeltaR(void);
   void probeLoop(void);
   void nLoop(void);
   void fillPFJetHisto(int i);
   void fillNoCutHisto(int i);
   void fillLooseHisto(int i, float *lowestLoosePt);
   void fillMediumHisto(int i);
   void fillTightHisto(int i, float *lowestTightPt);
   bool passPFTightPhoID(int i);
   bool passLoosePFPhoID(int i);
   bool passMediumPFPhoID(int i);
   double EAElectroncharged(double eta, string dataType);
   double EAElectronneutral(double eta, string dataType);
   double EAElectronphoton(double eta, string dataType);
};

#endif

//Used to get root file from command line
vector<string> _rootfile;

const char* GetRootFile()
{
  string temp = _rootfile[_rootfile.size()-1];
  _rootfile.pop_back();
  return temp.c_str();
}

#ifdef myClass_cxx
myClass::myClass(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("a.root");
      if (!f || !f->IsOpen()) {
         f = new TFile(GetRootFile());
      }
      f->GetObject("myEvent",tree);

   }
   Init(tree);
}

myClass::~myClass()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t myClass::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t myClass::LoadTree(Long64_t entry)
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

void myClass::Init(TTree *tree)
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
   fChain->SetBranchAddress("pfJet_partonFlavor", pfJet_partonFlavor, &b_pfJet_partonFlavor);
   fChain->SetBranchAddress("pfJet_partonStatus", pfJet_partonStatus, &b_pfJet_partonStatus);
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
   fChain->SetBranchAddress("npho", &npho, &b_npho);
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
   fChain->SetBranchAddress("PFMetPt", PFMetPt, &b_PFMetPt);
   fChain->SetBranchAddress("PFMetPx", PFMetPx, &b_PFMetPx);
   fChain->SetBranchAddress("PFMetPy", PFMetPy, &b_PFMetPy);
   fChain->SetBranchAddress("PFMetPhi", PFMetPhi, &b_PFMetPhi);
   fChain->SetBranchAddress("PFMetSumEt", PFMetSumEt, &b_PFMetSumEt);
   fChain->SetBranchAddress("Delta_phiPF", &Delta_phiPF, &b_Delta_phiPF);
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

Bool_t myClass::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void myClass::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t myClass::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef myClass_cxx
