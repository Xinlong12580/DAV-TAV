// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME sim_ana_Dict
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "ROOT/RConfig.hxx"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Header files passed as explicit arguments
#include "/seaquest/users/xinlongl/projects/DAV-TAV/main/cpp_modules/MC_module_src/DoEmbedding.h"
#include "/seaquest/users/xinlongl/projects/DAV-TAV/main/cpp_modules/MC_module_src/SimAna.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static TClass *DoEmbedding_Dictionary();
   static void DoEmbedding_TClassManip(TClass*);
   static void *new_DoEmbedding(void *p = nullptr);
   static void *newArray_DoEmbedding(Long_t size, void *p);
   static void delete_DoEmbedding(void *p);
   static void deleteArray_DoEmbedding(void *p);
   static void destruct_DoEmbedding(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DoEmbedding*)
   {
      ::DoEmbedding *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DoEmbedding));
      static ::ROOT::TGenericClassInfo 
         instance("DoEmbedding", "", 15,
                  typeid(::DoEmbedding), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &DoEmbedding_Dictionary, isa_proxy, 3,
                  sizeof(::DoEmbedding) );
      instance.SetNew(&new_DoEmbedding);
      instance.SetNewArray(&newArray_DoEmbedding);
      instance.SetDelete(&delete_DoEmbedding);
      instance.SetDeleteArray(&deleteArray_DoEmbedding);
      instance.SetDestructor(&destruct_DoEmbedding);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DoEmbedding*)
   {
      return GenerateInitInstanceLocal(static_cast<::DoEmbedding*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::DoEmbedding*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DoEmbedding_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::DoEmbedding*>(nullptr))->GetClass();
      DoEmbedding_TClassManip(theClass);
   return theClass;
   }

   static void DoEmbedding_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SimAna_Dictionary();
   static void SimAna_TClassManip(TClass*);
   static void *new_SimAna(void *p = nullptr);
   static void *newArray_SimAna(Long_t size, void *p);
   static void delete_SimAna(void *p);
   static void deleteArray_SimAna(void *p);
   static void destruct_SimAna(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SimAna*)
   {
      ::SimAna *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SimAna));
      static ::ROOT::TGenericClassInfo 
         instance("SimAna", "", 103,
                  typeid(::SimAna), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &SimAna_Dictionary, isa_proxy, 3,
                  sizeof(::SimAna) );
      instance.SetNew(&new_SimAna);
      instance.SetNewArray(&newArray_SimAna);
      instance.SetDelete(&delete_SimAna);
      instance.SetDeleteArray(&deleteArray_SimAna);
      instance.SetDestructor(&destruct_SimAna);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SimAna*)
   {
      return GenerateInitInstanceLocal(static_cast<::SimAna*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::SimAna*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SimAna_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::SimAna*>(nullptr))->GetClass();
      SimAna_TClassManip(theClass);
   return theClass;
   }

   static void SimAna_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_DoEmbedding(void *p) {
      return  p ? new(p) ::DoEmbedding : new ::DoEmbedding;
   }
   static void *newArray_DoEmbedding(Long_t nElements, void *p) {
      return p ? new(p) ::DoEmbedding[nElements] : new ::DoEmbedding[nElements];
   }
   // Wrapper around operator delete
   static void delete_DoEmbedding(void *p) {
      delete (static_cast<::DoEmbedding*>(p));
   }
   static void deleteArray_DoEmbedding(void *p) {
      delete [] (static_cast<::DoEmbedding*>(p));
   }
   static void destruct_DoEmbedding(void *p) {
      typedef ::DoEmbedding current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::DoEmbedding

namespace ROOT {
   // Wrappers around operator new
   static void *new_SimAna(void *p) {
      return  p ? new(p) ::SimAna : new ::SimAna;
   }
   static void *newArray_SimAna(Long_t nElements, void *p) {
      return p ? new(p) ::SimAna[nElements] : new ::SimAna[nElements];
   }
   // Wrapper around operator delete
   static void delete_SimAna(void *p) {
      delete (static_cast<::SimAna*>(p));
   }
   static void deleteArray_SimAna(void *p) {
      delete [] (static_cast<::SimAna*>(p));
   }
   static void destruct_SimAna(void *p) {
      typedef ::SimAna current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::SimAna

namespace {
  void TriggerDictionaryInitialization_sim_ana_Dict_Impl() {
    static const char* headers[] = {
"0",
nullptr
    };
    static const char* includePaths[] = {
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "sim_ana_Dict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class DoEmbedding;
class SimAna;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "sim_ana_Dict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#ifndef _DO_EMBEDDING__H_
#define _DO_EMBEDDING__H_
#include <fun4all/SubsysReco.h>
class TFile;
class TTree;
class SQEvent;
class SQMCEvent;
class SQHitVector;
class SQTrackVector;
class SQDimuonVector;

/// An example class to analyze the simulated uDST file.
class DoEmbedding: public SubsysReco {
  bool m_overwrite_rf_info;
  int m_hit_id_shift;
  int m_trk_id_shift;
  int m_dim_id_shift;

  /// DST nodes
  SQEvent       * mi_evt;
  SQHitVector   * mi_vec_hit;
  SQMCEvent     * mi_sim_evt;
  SQTrackVector * mi_sim_vec_trk;
  SQDimuonVector* mi_sim_vec_dim;
  SQEvent       * mi_evt_emb; ///< Node to hold SQEvent of embedded event as is
  SQMCEvent     * mi_sim_evt_emb; ///< Node to hold SQMCEvent of embedded event as is

  /// Embedding data
  std::vector<std::string> m_list_emb_file;
  int m_idx_emb_file;
  int m_idx_emb_evt;
  bool m_emb_data_has_sim_evt;
  bool m_emb_data_has_sim_trk;
  bool m_emb_data_has_sim_dim;

  TFile* m_file_emb;
  TTree* m_tree_emb;
  SQEvent*        m_emb_sqevt;
  SQMCEvent*      m_emb_sqmcevt;
  SQHitVector*    m_emb_sqvec_hit;
  SQTrackVector*  m_emb_sqvec_trk;
  SQDimuonVector* m_emb_sqvec_dim;

 public:
  DoEmbedding(const std::string name="DoEmbedding");
  virtual ~DoEmbedding();
  int Init(PHCompositeNode *topNode);
  int InitRun(PHCompositeNode *topNode);
  int process_event(PHCompositeNode *topNode);
  int End(PHCompositeNode *topNode);

  void DoOverwriteRfInfo(const bool overwrite) { m_overwrite_rf_info = overwrite; }
  bool DoOverwriteRfInfo() const        { return m_overwrite_rf_info; }
  void SetHitIdShift(const int id_shift) { m_hit_id_shift = id_shift; }
  int  GetHitIdShift() const      { return m_hit_id_shift; }
  void SetTrackIdShift(const int id_shift) { m_trk_id_shift = id_shift; }
  int  GetTrackIdShift() const      { return m_trk_id_shift; }
  void SetDimuonIdShift(const int id_shift) { m_dim_id_shift = id_shift; }
  int  GetDimuonIdShift() const      { return m_dim_id_shift; }

  void AddEmbDataFile(const char* fn_root);
  void AddEmbDataFiles(const char* fn_list);
  int  GetNumEmbEvents();

 protected:
  void OpenEmbDataFile(const char* fn_root);
  void CloseEmbDataFile();
  bool GetNextEmbEvent();
};

#endif // _DO_EMBEDDING__H_
#ifndef _Sim_Ana__H_
#define _Sim_Ana__H_

#include <TString.h>
#include <TVector3.h>
#include <fun4all/SubsysReco.h>
#include <map>

#include <chrono>
#include <ctime>

class TFile;
class TTree;
class SQHitVector;
class SQTrackVector;
class SQDimuonVector;

class PHG4TruthInfoContainer;
class PHG4HitContainer;
class SRecEvent;
class SRecTrack;
class PHG4Hit;
class PHG4Shower;
class PHG4Particle;

class SQEvent_v1;
class SQMCEvent;

class SimAna : public SubsysReco {
public:
    SimAna(const std::string& name = "SimAna");
    virtual ~SimAna();

    int Init(PHCompositeNode* topNode);
    int InitRun(PHCompositeNode* topNode);
    int process_event(PHCompositeNode* topNode);
    int End(PHCompositeNode* topNode);
    int ResetEvalVars();

    PHG4Hit* FindG4HitAtStation(const int trk_id, const PHG4HitContainer* g4hc);
    std::vector<PHG4Hit*> FindG4HitsAtStation(const int trk_id, const PHG4HitContainer* g4hc);
    PHG4Shower* get_primary_shower(PHG4Particle* particle);
    int FindCommonHitIDs(std::vector<int>& hitidvec1, std::vector<int>& hitidvec2);
    SRecTrack* FindBestMomRecTrack(SRecEvent* recEvent, const float true_P);

    void set_out_name(std::string out_file) { saveName = out_file.c_str(); }
    void set_legacy_rec_container(bool b);
    void save_secondaries(bool b);
    void save_primaries(bool b);
    void save_tracks(bool b);
    void save_vertex(bool b);

private:
    int GetNodes(PHCompositeNode* topNode);
    bool _legacyContainer;
    bool _saveSecondaries;
    bool _savePrimaries;
    bool _saveTracks;
    bool _saveVertex;

    void MakeTree();

    SQHitVector* _hitVector;
    SQTrackVector* _trackVector;
    SQDimuonVector* _dimuonVector;

    SRecEvent* _recEvent;
    SQTrackVector* _recTrackVector;
    SQTrackVector* _recSt3TrackletVector;
    SQDimuonVector* _recDimuonVector;

    SQEvent_v1* _sqEvent;
    SQMCEvent* _sqMCEvent;

    PHG4TruthInfoContainer* _truth;

    PHG4HitContainer* g4hc_d1x;
    PHG4HitContainer* g4hc_d2xp;
    PHG4HitContainer* g4hc_d3px;
    PHG4HitContainer* g4hc_d3mx;

    PHG4HitContainer* g4hc_h1t;
    PHG4HitContainer* g4hc_h1b;
    PHG4HitContainer* g4hc_h1l;
    PHG4HitContainer* g4hc_h1r;
    PHG4HitContainer* g4hc_h2t;
    PHG4HitContainer* g4hc_h2b;
    PHG4HitContainer* g4hc_h2l;
    PHG4HitContainer* g4hc_h2r;
    PHG4HitContainer* g4hc_h3t;
    PHG4HitContainer* g4hc_h3b;
    PHG4HitContainer* g4hc_h4t;
    PHG4HitContainer* g4hc_h4b;
    PHG4HitContainer* g4hc_h4y2l;
    PHG4HitContainer* g4hc_h4y2r;

    PHG4HitContainer* g4hc_p1y1;
    PHG4HitContainer* g4hc_p1y2;
    PHG4HitContainer* g4hc_p1x1;
    PHG4HitContainer* g4hc_p1x2;
    PHG4HitContainer* g4hc_p2x1;
    PHG4HitContainer* g4hc_p2x2;
    PHG4HitContainer* g4hc_p2y1;
    PHG4HitContainer* g4hc_p2y2;

    PHG4HitContainer* g4hc_ecal;

    // Output
    std::string saveName;

    TFile* saveFile;
    int event_number;
    int eventID;
    TTree* saveTree;

  float totalTime;

  int passHitCuts;
  int nTrueDM;
  int nFakeDM;
  float TrueDMFrac;
  int nFakeTracks;
  int nFakeTracksTop2;
  int nRealTracks;
  int mainDMRecoed;
  
    int n_hits;
    int n_hits_h1x;
    int n_hits_h2x;
    int n_hits_h3x;
    int n_hits_h4x;
    int n_hits_d0x;
    int n_hits_d2x;
    int n_hits_d3px;
    int n_hits_d3mx;
    int n_hits_d0;
    int n_hits_d1;
    int n_hits_d2;
    int n_hits_d3p;
    int n_hits_d3m;
    int n_hits_dp1;
    int n_hits_dp2;
    int hit_detid[1000];
    int hit_elmid[1000];
    int hit_trkid[1000];
    float hit_driftdis[1000];
    float hit_pos[1000];
    float hit_edep[1000];
    float hit_truthx[1000];
    float hit_truthy[1000];
    float hit_truthz[1000];
    float hit_truthpx[1000];
    float hit_truthpy[1000];
    float hit_truthpz[1000];

    int n_truthtracks;
    int truthtrack_charge[1000];
    float truthtrack_x_st1[1000];
    float truthtrack_y_st1[1000];
    float truthtrack_z_st1[1000];
    float truthtrack_px_st1[1000];
    float truthtrack_py_st1[1000];
    float truthtrack_pz_st1[1000];
    float truthtrack_x_st3[1000];
    float truthtrack_y_st3[1000];
    float truthtrack_z_st3[1000];
    float truthtrack_px_st3[1000];
    float truthtrack_py_st3[1000];
    float truthtrack_pz_st3[1000];
    float truthtrack_x_vtx[1000];
    float truthtrack_y_vtx[1000];
    float truthtrack_z_vtx[1000];
    float truthtrack_px_vtx[1000];
    float truthtrack_py_vtx[1000];
    float truthtrack_pz_vtx[1000];
    int truthtrack_rectrack_id[1000];

    int rec_status;
    int n_tracks;
    int track_charge[100];
    int track_particleID[100];
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
    float track_x_st3[100];
    float track_y_st3[100];
    float track_z_st3[100];
    float track_px_st3[100];
    float track_py_st3[100];
    float track_pz_st3[100];
    float track_x_vtx[100];
    float track_y_vtx[100];
    float track_z_vtx[100];
    float track_px_vtx[100];
    float track_py_vtx[100];
    float track_pz_vtx[100];
    float track_m[100];
    float track_x_CAL[100];
    float track_y_CAL[100];
    float track_chisq[100];
    float track_prob[100];
    float track_quality[100];
    int track_matched[100];
    int track_isValid[100];
    int track_nhits_st1[100];
    int track_nhits_st2[100];
    int track_nhits_st3[100];

    int n_st3tracklets;
    float st3tracklet_x_CAL[100];
    float st3tracklet_y_CAL[100];
    float st3tracklet_chisq[100];
    float st3tracklet_prob[100];
    float st3tracklet_quality[100];
    int st3tracklet_isValid[100];
    int st3tracklet_nhits_st1[100];
    int st3tracklet_nhits_st2[100];
    int st3tracklet_nhits_st3[100];
    int st3tracklet_nhits[100];
    float st3tracklet_x_target[100];
    float st3tracklet_y_target[100];
    float st3tracklet_z_target[100];
    float st3tracklet_px_target[100];
    float st3tracklet_py_target[100];
    float st3tracklet_pz_target[100];
    float st3tracklet_x_st1[100];
    float st3tracklet_y_st1[100];
    float st3tracklet_z_st1[100];
    float st3tracklet_px_st1[100];
    float st3tracklet_py_st1[100];
    float st3tracklet_pz_st1[100];
    float st3tracklet_x_st3[100];
    float st3tracklet_y_st3[100];
    float st3tracklet_z_st3[100];
    float st3tracklet_px_st3[100];
    float st3tracklet_py_st3[100];
    float st3tracklet_pz_st3[100];
    float st3tracklet_x_vtx[100];
    float st3tracklet_y_vtx[100];
    float st3tracklet_z_vtx[100];
    float st3tracklet_px_vtx[100];
    float st3tracklet_py_vtx[100];
    float st3tracklet_pz_vtx[100];
    float st3tracklet_m[100];
    int st3tracklet_charge[100];

    int n_truthdimuons;
    float truthdimuon_mass[100];
    float truthdimuon_x_vtx[100];
    float truthdimuon_y_vtx[100];
    float truthdimuon_z_vtx[100];
    float truthdimuon_px[100];
    float truthdimuon_py[100];
    float truthdimuon_pz[100];
    float truthdimuon_pmom_x[100];
    float truthdimuon_pmom_y[100];
    float truthdimuon_pmom_z[100];
    float truthdimuon_nmom_x[100];
    float truthdimuon_nmom_y[100];
    float truthdimuon_nmom_z[100];
    int truthdimuon_recoed[100];

    int n_dimuons;
    float dimuon_mass[100];
    float dimuon_chisq[100];
    float dimuon_chisq_vx[100];
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
    int dimuon_matched[100];
  
    int n_showers;
    float sx_ecal[1000];
    float sy_ecal[1000];
    float sz_ecal[1000];
    float sedep_ecal[1000];

    int n_primaries;
    int gtrkid[1000];
    int gpid[1000];
    float gvx[1000];
    float gvy[1000];
    float gvz[1000];
    float gpx[1000];
    float gpy[1000];
    float gpz[1000];
    float gpt[1000];
    float geta[1000];
    float gphi[1000];
    float ge[1000];

    int nhits_ecal[1000];
    float gx_ecal[1000][100];
    float gy_ecal[1000][100];
    float gz_ecal[1000][100];
    float gpx_ecal[1000][100];
    float gpy_ecal[1000][100];
    float gpz_ecal[1000][100];
    float gedep_ecal[1000][100];

    float gx_st1[1000];
    float gy_st1[1000];
    float gz_st1[1000];
    float gpx_st1[1000];
    float gpy_st1[1000];
    float gpz_st1[1000];
    float gx_st2[1000];
    float gy_st2[1000];
    float gz_st2[1000];
    float gpx_st2[1000];
    float gpy_st2[1000];
    float gpz_st2[1000];
    float gx_st3[1000];
    float gy_st3[1000];
    float gz_st3[1000];
    float gpx_st3[1000];
    float gpy_st3[1000];
    float gpz_st3[1000];

    float gx_h1[1000];
    float gy_h1[1000];
    float gz_h1[1000];
    float gpx_h1[1000];
    float gpy_h1[1000];
    float gpz_h1[1000];
    float gx_h2[1000];
    float gy_h2[1000];
    float gz_h2[1000];
    float gpx_h2[1000];
    float gpy_h2[1000];
    float gpz_h2[1000];
    float gx_h3[1000];
    float gy_h3[1000];
    float gz_h3[1000];
    float gpx_h3[1000];
    float gpy_h3[1000];
    float gpz_h3[1000];
    float gx_h4[1000];
    float gy_h4[1000];
    float gz_h4[1000];
    float gpx_h4[1000];
    float gpy_h4[1000];
    float gpz_h4[1000];

    float gx_p1[1000];
    float gy_p1[1000];
    float gz_p1[1000];
    float gpx_p1[1000];
    float gpy_p1[1000];
    float gpz_p1[1000];

    float gx_h4y2l[1000];
    float gy_h4y2l[1000];
    float gz_h4y2l[1000];
    float gpx_h4y2l[1000];
    float gpy_h4y2l[1000];
    float gpz_h4y2l[1000];
    float gx_h4y2r[1000];
    float gy_h4y2r[1000];
    float gz_h4y2r[1000];
    float gpx_h4y2r[1000];
    float gpy_h4y2r[1000];
    float gpz_h4y2r[1000];

    int n_secondaries;
    int gtrkid_sec[1000];
    int gpid_sec[1000];
    float gvx_sec[1000];
    float gvy_sec[1000];
    float gvz_sec[1000];
    float gpx_sec[1000];
    float gpy_sec[1000];
    float gpz_sec[1000];
    float ge_sec[1000];
    //int nhits_ecal_sec[1000];

    bool fpga_trigger[5];
    bool nim_trigger[5];

    float weight;
  
  std::chrono::time_point<std::chrono::system_clock> startTime;

  int allRecoed;
  int allCouldBeRecoed;
  int numNonMatched;
};

#endif

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"DoEmbedding", payloadCode, "@",
"SimAna", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("sim_ana_Dict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_sim_ana_Dict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_sim_ana_Dict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_sim_ana_Dict() {
  TriggerDictionaryInitialization_sim_ana_Dict_Impl();
}
