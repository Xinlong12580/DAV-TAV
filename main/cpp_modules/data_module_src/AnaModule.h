#ifndef _ANA_Module__H_
#define _ANA_Module__H_

#include <map>
#include <fun4all/SubsysReco.h>
#include <TString.h>
#include <TVector3.h>
#include <ktracker/SRawEvent.h>

class TFile;
class TTree;
class SQHitVector;
class SRecTrack;
class SRecEvent;
class SQTrackVector;
class SQDimuonVector;
class SQEvent;

class AnaModule : public SubsysReco
{
public:
  AnaModule() { ; }
  virtual ~AnaModule() { ; }

  int Init(PHCompositeNode *topNode);
  int InitRun(PHCompositeNode *topNode);
  int process_event(PHCompositeNode *topNode);
  int End(PHCompositeNode *topNode);

  void set_output_filename(const TString &n) { saveName = n; }
  void set_reco(bool b) { saveReco = b; }
  void set_additional_information(const TString &n) { additional_information = n; }
  void reset_event_number() { event_number = 0; }

private:
  int GetNodes(PHCompositeNode *topNode);
  int ResetEvalVars();
  void MakeTree();

  // Input
  // SRawEvent* rawEvent;
  SQEvent *Event;
  SQHitVector *hitVector;
  SQHitVector *triggerHitVector;
  SRecEvent *recEvent;

  // Output
  TString saveName;
  TFile *saveFile;
  TTree *saveTree;
  TString additional_information;

  Int_t runID, spillID, eventID;
  
  Int_t trigger;
  bool NIM_1;
  bool NIM_2;
  bool NIM_3;
  bool NIM_4;
  bool NIM_5;
  bool MATRIX_1;
  bool MATRIX_2;
  bool MATRIX_3;
  bool MATRIX_4;
  bool MATRIX_5;
  Int_t nHits;
  Int_t detectorID[15000], elementID[15000];
  Double_t tdcTime[15000], driftDistance[15000], pos[15000];

  Int_t nTriggerHits;
  Int_t trigger_hit_detectorID[15000], trigger_hit_elementID[15000];
  Double_t trigger_hit_tdcTime[15000], trigger_hit_driftDistance[15000], trigger_hit_pos[15000];
  
  int n_tracks;
  int track_charge[100];
  int track_nhits[100];
  float track_x_target[100];
  float track_y_target[100];
  float track_z_target[100];
  float track_px_target[100];
  float track_py_target[100];
  float track_pz_target[100];
  float track_x_st1[100];
  float track_y_st1[100];
  float track_z_st1[100];
  float track_px_st1[100];
  float track_py_st1[100];
  float track_pz_st1[100];
  float track_x_vtx[100];
  float track_y_vtx[100];
  float track_z_vtx[100];
  float track_px_vtx[100];
  float track_py_vtx[100];
  float track_pz_vtx[100];
  float track_m[100];
  float track_chisq[100];
  float track_prob[100];
  float track_quality[100];
  int track_nhits_st1[100];
  int track_nhits_st2[100];
  int track_nhits_st3[100];

  int n_dimuons;
  float dimuon_mass[100];
  float dimuon_chisq[100];
  float dimuon_x_vtx[100];
  float dimuon_y_vtx[100];
  float dimuon_z_vtx[100];
  float dimuon_px[100];
  float dimuon_py[100];
  float dimuon_pz[100];
  float dimuon_pmom_x[100];
  float dimuon_pmom_y[100];
  float dimuon_pmom_z[100];
  float dimuon_nmom_x[100];
  float dimuon_nmom_y[100];
  float dimuon_nmom_z[100];
  float dimuon_ppos_x[100];
  float dimuon_ppos_y[100];
  float dimuon_ppos_z[100];
  float dimuon_npos_x[100];
  float dimuon_npos_y[100];
  float dimuon_npos_z[100];
  int event_number;
  bool saveReco = false;
};

#endif
