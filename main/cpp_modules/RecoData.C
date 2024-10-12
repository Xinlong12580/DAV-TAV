#include <iostream>
#include <ctime>
#include <TSystem.h>
#include "data_module_src/AnaModule.h"
R__LOAD_LIBRARY(libinterface_main)
R__LOAD_LIBRARY(libfun4all)
R__LOAD_LIBRARY(libg4detectors)
R__LOAD_LIBRARY(libg4eval)
R__LOAD_LIBRARY(libcalibrator)
R__LOAD_LIBRARY(libktracker)
R__LOAD_LIBRARY(libanamodule)
/*
This macro takes severl external input files to run:
1. geom.root is the standard geometry dump from running the Fun4Sim macro;
2. `DST_in` (data.root) should be the DST file generated either by decoder or by simulation.

This is an example script intended to demonstrate how to run SQReco in a minimalistic fashion, it is NOT
suitable for production use and users should develop their own reconstruction macro for their own analysis.
*/

int RecoData(const int nEvents, std::string top_dir, std::string data_type="SpinQuest-commissioning",std::string infile = "./fileset/digit_run_028694_spill_001415238.root", std::string outfile="ana.root", bool do_displaced_tracking=true,const int runID=6155, const float fac=2,const string reducer="none", const bool coarse=false)
{

    // Get the current time

    // Convert the time to a string
 
  std::string dstfile = "DST.root";
  std::string evalloc = "eval.root";
  std::string vtxevalloc = "vtx_eval.root";
  const bool cosmic = false;

  const bool legacy_rec_container = true;
  const double FMAGSTR = -1.044;
  const double KMAGSTR = -1.025;

  recoConsts* rc = recoConsts::instance();
  rc->set_IntFlag("RUNNUMBER", runID);
  rc->set_DoubleFlag("FMAGSTR", -1.044);
  rc->set_DoubleFlag("KMAGSTR", -1.025);
  
  rc->set_IntFlag("MaxHitsDC0" , int(350/fac)); // number of hits per chamber. Suggestion make it half
  rc->set_IntFlag("MaxHitsDC1" , int(350/fac));
  rc->set_IntFlag("MaxHitsDC2" , int(170/fac));
  rc->set_IntFlag("MaxHitsDC3p", int(140/fac));
  rc->set_IntFlag("MaxHitsDC3m", int(140/fac)); // This is the end line to set occupancy. Talk to Kun
 if (do_displaced_tracking)  
 {     
	 rc->set_BoolFlag("TRACK_ELECTRONS", do_displaced_tracking);  
	 rc->set_BoolFlag("TRACK_DISPLACED", do_displaced_tracking);   
 }
  //printf("final: %i",int(350/fac)); // number of hits per chamber. Suggestion make it half
  //printf("final: %i",int(170/fac));
  //printf("final: %i",int(140/fac));
  //printf("final: %i",int(140/fac)); // This is the end line to set occupancy. Talk to Kun


 

  rc->set_BoolFlag("COARSE_MODE", coarse);
  //rc->set_DoubleFlag("KMAGSTR", 0.);
  //rc->set_BoolFlag("KMAG_ON", false);

  //rc->set_CharFlag("AlignmentMille", "");
  //rc->set_CharFlag("AlignmentHodo", "");
  //rc->set_CharFlag("AlignmentProp", "");
  //rc->set_CharFlag("Calibration", "");
  if (data_type=="SpinQuest-commissioning"){
  	rc->set_CharFlag("AlignmentMille", "$E1039_RESOURCE/alignment/dummy/align_mille.txt");
  	rc->set_CharFlag("AlignmentHodo", "$E1039_RESOURCE/alignment/dummy/alignment_hodo.txt");
  	rc->set_CharFlag("AlignmentProp", "$E1039_RESOURCE/alignment/dummy/alignment_prop.txt");
  	rc->set_CharFlag("Calibration", "$E1039_RESOURCE/alignment/dummy/calibration.txt");
  }
  rc->Print();

  Fun4AllServer* se = Fun4AllServer::instance();
  se->Verbosity(0);

  // Calibrator
  CalibHitElementPos* cal_ele_pos = new CalibHitElementPos();
  cal_ele_pos->CalibTriggerHit(false);
  se->registerSubsystem(cal_ele_pos);

  //GeomSvc* geom_svc = GeomSvc::instance();
  CalibDriftDist* cal_dd = new CalibDriftDist();
  se->registerSubsystem(cal_dd);

  SQReco* reco = new SQReco();
  reco->Verbosity(0);
  reco->set_legacy_rec_container(legacy_rec_container);
  reco->set_geom_file_name(top_dir+"/main/cpp_modules/support/geom.root");
  reco->set_enable_KF(true); //Kalman filter not needed for the track finding, disabling KF saves a lot of initialization time
  reco->setInputTy(SQReco::E1039);    //options are SQReco::E906 and SQReco::E1039
  reco->setFitterTy(SQReco::KFREF);  //not relavant for the track finding
  reco->set_evt_reducer_opt(reducer.c_str()); //if not provided, event reducer will be using JobOptsSvc to intialize; to turn off, set it to "none"



  se->registerSubsystem(reco);

  VertexFit* vtx_fit = new VertexFit();
  vtx_fit->set_eval_file_name(vtxevalloc);
  se->registerSubsystem(vtx_fit);

  AnaModule *ana = new AnaModule();
  ana->set_output_filename(outfile);
  ana->set_reco(true);
  ana->set_additional_information(infile);
  se->registerSubsystem(ana);
  if (data_type=="SpinQuest-commissioning"){  
  	Fun4AllInputManager* in = new Fun4AllDstInputManager("DSTIN");
  	in->Verbosity(0);
  	in->fileopen(infile.c_str());
  	se->registerInputManager(in);
  }
  else if (data_type=="SeaQuest-run6"){
	Fun4AllSRawEventInputManager *in = new Fun4AllSRawEventInputManager("SRawEventIM");
	in->Verbosity(0);
        in->enable_E1039_translation();
	in->set_tree_name("save");
	in->set_branch_name("rawEvent");
	in->fileopen(infile.c_str());
	se->registerInputManager(in);
  }



  Fun4AllDstOutputManager* out = new Fun4AllDstOutputManager("DSTOUT", dstfile);
  se->registerOutputManager(out);

  se->run(nEvents);

  // finish job - close and save output files
  se->End();
  se->PrintTimer();

  delete se;
  // Get the current time

  // Convert the time to a string
 
  printf("\nAll Done.!");
  printf("\n0");
  gSystem->Exit(0);
  return 0;
}
