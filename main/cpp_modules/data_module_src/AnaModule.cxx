#include <iomanip>
#include <TFile.h>
#include <TTree.h>

#include <fun4all/Fun4AllReturnCodes.h>
#include <phool/getClass.h>
#include <ktracker/SRecEvent.h>
#include <interface_main/SQHitVector.h>
#include <interface_main/SQHit.h>
#include <interface_main/SQEvent.h>
#include "AnaModule.h"

int AnaModule::Init(PHCompositeNode *topNode)
{
  return Fun4AllReturnCodes::EVENT_OK;
}

int AnaModule::InitRun(PHCompositeNode *topNode)
{
  event_number = 0;
  int ret = GetNodes(topNode);
  if (ret != Fun4AllReturnCodes::EVENT_OK)
    return ret;

  eventID = 0;
  MakeTree();
  return Fun4AllReturnCodes::EVENT_OK;
}

int AnaModule::process_event(PHCompositeNode *topNode)
{
  ResetEvalVars();

  nHits = hitVector->size();
  nTriggerHits = triggerHitVector->size();
  std::cout << additional_information << std::endl;
  std::cout << "nhits " << nHits << std::endl;
  std::cout << "EVENT_NUMBER " << event_number << std::endl;
  event_number++;
  // The NIM1 and NIM3 bits are random triggers.

  runID=Event->get_run_id();
  spillID=Event->get_spill_id();
  eventID=Event->get_event_id();
  trigger=Event->get_trigger();
  NIM_1=Event->get_trigger(static_cast<SQEvent::TriggerMask>(SQEvent::NIM1));
  NIM_2=Event->get_trigger(static_cast<SQEvent::TriggerMask>(SQEvent::NIM2));
  NIM_3=Event->get_trigger(static_cast<SQEvent::TriggerMask>(SQEvent::NIM3));
  NIM_4=Event->get_trigger(static_cast<SQEvent::TriggerMask>(SQEvent::NIM4));
  NIM_5=Event->get_trigger(static_cast<SQEvent::TriggerMask>(SQEvent::NIM5));
  MATRIX_1=Event->get_trigger(static_cast<SQEvent::TriggerMask>(SQEvent::MATRIX1));
  MATRIX_2=Event->get_trigger(static_cast<SQEvent::TriggerMask>(SQEvent::MATRIX2));
  MATRIX_3=Event->get_trigger(static_cast<SQEvent::TriggerMask>(SQEvent::MATRIX3));
  MATRIX_4=Event->get_trigger(static_cast<SQEvent::TriggerMask>(SQEvent::MATRIX4));
  MATRIX_5=Event->get_trigger(static_cast<SQEvent::TriggerMask>(SQEvent::MATRIX5));
  for (Int_t k = 0; k < nHits; ++k)
  {
    SQHit *h = hitVector->at(k);
    detectorID[k] = h->get_detector_id();
    elementID[k] = h->get_element_id();
    pos[k] = h->get_pos();

    // detector ID refers to the detector number as seen here:
    // st1-drift chambers| D0: 1-6, D1: 7-12
    // st2-drift chambers| D2: 13-18
    // st3-drift chambers| D3p: 19-24, D3m: 25-30
    // h1-hodoscope: H1B/T: 31/22 H1L/R: 33/34
    // h2-hodoscope: H2L/R: 35/36 H2B/T: 37/38
    // h3-hodoscope: H3B/T: 39/40
    // h4-hodoscope: H4Y1L/R: 41/42 H4Y2L/R: 43/44 H4B/T: 45/46
    // proto-tubes: 47-54
    // dp-stations: DP1:55-58, DP2:59-6

    // elementID refers to the hodoscope bar or drift chamber channel hit, this is detector dependent but can give us an idea of position

    tdcTime[k] = h->get_tdc_time();
    driftDistance[k] = h->get_drift_distance();
  }
  for (Int_t k = 0; k < nTriggerHits; ++k)
  {
	 
    SQHit *h = triggerHitVector->at(k);
    trigger_hit_detectorID[k] = h->get_detector_id();
    trigger_hit_elementID[k] = h->get_element_id();
    trigger_hit_pos[k] = h->get_pos();

    trigger_hit_tdcTime[k] = h->get_tdc_time();
    trigger_hit_driftDistance[k] = h->get_drift_distance();
  }

  // track related variables
  if (recEvent)
  {
    n_tracks = recEvent->getNTracks();
    for (int i = 0; i < n_tracks; ++i)
    {
      SRecTrack *recTrack = &recEvent->getTrack(i);
      track_charge[i] = recTrack->getCharge();
      track_nhits[i] = recTrack->getNHits();
      track_x_target[i] = (recTrack->getTargetPos()).X();
      track_y_target[i] = (recTrack->getTargetPos()).Y();
      track_z_target[i] = (recTrack->getTargetPos()).Z();
      track_px_target[i] = (recTrack->getTargetMom()).Px();
      track_py_target[i] = (recTrack->getTargetMom()).Py();
      track_pz_target[i] = (recTrack->getTargetMom()).Pz();
      track_x_st1[i] = (recTrack->getPositionVecSt1()).X();
      track_y_st1[i] = (recTrack->getPositionVecSt1()).Y();
      track_z_st1[i] = (recTrack->getPositionVecSt1()).Z();
      track_px_st1[i] = (recTrack->getMomentumVecSt1()).Px();
      track_py_st1[i] = (recTrack->getMomentumVecSt1()).Py();
      track_pz_st1[i] = (recTrack->getMomentumVecSt1()).Pz();
      track_x_vtx[i] = (recTrack->getVertexPos()).X();
      track_y_vtx[i] = (recTrack->getVertexPos()).Y();
      track_z_vtx[i] = (recTrack->getVertexPos()).Z();
      track_px_vtx[i] = (recTrack->getVertexMom()).X();
      track_py_vtx[i] = (recTrack->getVertexMom()).Y();
      track_pz_vtx[i] = (recTrack->getVertexMom()).Z();
      track_chisq[i] = recTrack->getChisq();
      track_prob[i] = recTrack->getProb();
      track_quality[i] = recTrack->getQuality();
      track_nhits_st1[i] = recTrack->getNHitsInStation(1);
      track_nhits_st2[i] = recTrack->getNHitsInStation(2);
      track_nhits_st3[i] = recTrack->getNHitsInStation(3);
      if (i >= 100)
        break;
    }

    // dimuon information
    n_dimuons = recEvent->getNDimuons();
    for (int i = 0; i < n_dimuons; ++i)
    {
      SRecDimuon *recDimuon = &recEvent->getDimuon(i);
      dimuon_mass[i] = recDimuon->mass;
      dimuon_chisq[i] = recDimuon->get_chisq();
      dimuon_x_vtx[i] = (recDimuon->vtx).X();
      dimuon_y_vtx[i] = (recDimuon->vtx).Y();
      dimuon_z_vtx[i] = (recDimuon->vtx).Z();
      dimuon_px[i] = (recDimuon->get_mom()).X();
      dimuon_py[i] = (recDimuon->get_mom()).Y();
      dimuon_pz[i] = (recDimuon->get_mom()).Z();
      dimuon_pmom_x[i] = (recDimuon->p_pos).Px(); // 4-momentum of the muon tracks after vertex fit
      dimuon_pmom_y[i] = (recDimuon->p_pos).Py();
      dimuon_pmom_z[i] = (recDimuon->p_pos).Pz();
      dimuon_nmom_x[i] = (recDimuon->p_neg).Px();
      dimuon_nmom_y[i] = (recDimuon->p_neg).Py();
      dimuon_nmom_z[i] = (recDimuon->p_neg).Pz();
      dimuon_ppos_x[i] = (recDimuon->vtx_pos).X(); // vertex position
      dimuon_ppos_y[i] = (recDimuon->vtx_pos).Y();
      dimuon_ppos_z[i] = (recDimuon->vtx_pos).Z();
      dimuon_npos_x[i] = (recDimuon->vtx_neg).X();
      dimuon_npos_y[i] = (recDimuon->vtx_neg).Y();
      dimuon_npos_z[i] = (recDimuon->vtx_neg).Z();
    }
  }

  saveTree->Fill();
  //}

  return Fun4AllReturnCodes::EVENT_OK;
}

int AnaModule::End(PHCompositeNode *topNode)
{
  saveFile->cd();
  saveTree->Write();
  saveFile->Close();

  return Fun4AllReturnCodes::EVENT_OK;
}

int AnaModule::GetNodes(PHCompositeNode *topNode)
{

  Event=findNode::getClass<SQEvent>(topNode, "SQEvent");
  if (!Event)
  {
    std::cout << "failed to find SQEvent, return " << std::endl;
    Event = nullptr;
    return Fun4AllReturnCodes::ABORTEVENT;
  }
  hitVector = findNode::getClass<SQHitVector>(topNode, "SQHitVector");
  if (!hitVector)
  {
    std::cout << "failed to find SQHitVector, return " << std::endl;
    hitVector = nullptr;
    return Fun4AllReturnCodes::ABORTEVENT;
  }
  triggerHitVector = findNode::getClass<SQHitVector>(topNode, "SQTriggerHitVector");
  if (!triggerHitVector)
  {
    std::cout << "failed to find SQTriggerHitVector, return " << std::endl;
    triggerHitVector = nullptr;
    return Fun4AllReturnCodes::ABORTEVENT;
  }
  recEvent = findNode::getClass<SRecEvent>(topNode, "SRecEvent");
  if (!recEvent || !saveReco)
  {
    std::cout << "failed to find SRecEvent " << std::endl;
    // recEvent = nullptr;
    //  return Fun4AllReturnCodes::ABORTEVENT;
  }
  return Fun4AllReturnCodes::EVENT_OK;
}

int AnaModule::ResetEvalVars()
{
  nHits = 0;
  for (int i = 0; i < 15000; ++i)
  {
    
    detectorID[i] = std::numeric_limits<int>::max();
    elementID[i] = std::numeric_limits<int>::max();
    tdcTime[i] = std::numeric_limits<double>::max();
    driftDistance[i] = std::numeric_limits<double>::max();
    pos[i] = std::numeric_limits<double>::max();
  }
  nTriggerHits = 0;
  for (int i = 0; i < 15000; ++i)
  {
    
    trigger_hit_detectorID[i] = std::numeric_limits<int>::max();
    trigger_hit_elementID[i] = std::numeric_limits<int>::max();
    trigger_hit_tdcTime[i] = std::numeric_limits<double>::max();
    trigger_hit_driftDistance[i] = std::numeric_limits<double>::max();
    trigger_hit_pos[i] = std::numeric_limits<double>::max();
  }

    runID = std::numeric_limits<int>::max();
    spillID = std::numeric_limits<int>::max();
    eventID = std::numeric_limits<int>::max();
    trigger = std::numeric_limits<int>::max();
  n_tracks = 0;
   NIM_1=0;
   NIM_2=0;
   NIM_3=0;
   NIM_4=0;
   NIM_5=0;
   MATRIX_1=0;
   MATRIX_2=0;
   MATRIX_3=0;
   MATRIX_4=0;
   MATRIX_5=0;
  for (int i = 0; i < 100; ++i)
  {
    track_charge[i] = std::numeric_limits<int>::max();
    track_nhits[i] = std::numeric_limits<int>::max();
    track_x_target[i] = std::numeric_limits<float>::max();
    track_y_target[i] = std::numeric_limits<float>::max();
    track_z_target[i] = std::numeric_limits<float>::max();
    track_px_target[i] = std::numeric_limits<float>::max();
    track_py_target[i] = std::numeric_limits<float>::max();
    track_pz_target[i] = std::numeric_limits<float>::max();
    track_x_st1[i] = std::numeric_limits<float>::max();
    track_y_st1[i] = std::numeric_limits<float>::max();
    track_z_st1[i] = std::numeric_limits<float>::max();
    track_px_st1[i] = std::numeric_limits<float>::max();
    track_py_st1[i] = std::numeric_limits<float>::max();
    track_pz_st1[i] = std::numeric_limits<float>::max();
    track_x_vtx[i] = std::numeric_limits<float>::max();
    track_y_vtx[i] = std::numeric_limits<float>::max();
    track_z_vtx[i] = std::numeric_limits<float>::max();
    track_px_vtx[i] = std::numeric_limits<float>::max();
    track_py_vtx[i] = std::numeric_limits<float>::max();
    track_pz_vtx[i] = std::numeric_limits<float>::max();
    track_m[i] = std::numeric_limits<float>::max();
    track_chisq[i] = std::numeric_limits<float>::max();
    track_prob[i] = std::numeric_limits<float>::max();
    track_quality[i] = std::numeric_limits<float>::max();
    track_nhits_st1[i] = std::numeric_limits<float>::max();
    track_nhits_st2[i] = std::numeric_limits<float>::max();
    track_nhits_st3[i] = std::numeric_limits<float>::max();
  }

  n_dimuons = 0;
  for (int i = 0; i < 100; ++i)
  {
    dimuon_mass[i] = std::numeric_limits<float>::max();
    dimuon_chisq[i] = std::numeric_limits<float>::max();
    dimuon_x_vtx[i] = std::numeric_limits<float>::max();
    dimuon_y_vtx[i] = std::numeric_limits<float>::max();
    dimuon_z_vtx[i] = std::numeric_limits<float>::max();
    dimuon_px[i] = std::numeric_limits<float>::max();
    dimuon_py[i] = std::numeric_limits<float>::max();
    dimuon_pz[i] = std::numeric_limits<float>::max();
    dimuon_pmom_x[i] = std::numeric_limits<float>::max();
    dimuon_pmom_y[i] = std::numeric_limits<float>::max();
    dimuon_pmom_z[i] = std::numeric_limits<float>::max();
    dimuon_nmom_x[i] = std::numeric_limits<float>::max();
    dimuon_nmom_y[i] = std::numeric_limits<float>::max();
    dimuon_nmom_z[i] = std::numeric_limits<float>::max();
    dimuon_ppos_x[i] = std::numeric_limits<float>::max();
    dimuon_ppos_y[i] = std::numeric_limits<float>::max();
    dimuon_ppos_z[i] = std::numeric_limits<float>::max();
    dimuon_npos_x[i] = std::numeric_limits<float>::max();
    dimuon_npos_y[i] = std::numeric_limits<float>::max();
    dimuon_npos_z[i] = std::numeric_limits<float>::max();
  }

  return 1;
}

void AnaModule::MakeTree()
{
  saveFile = new TFile(saveName, "RECREATE");

  saveTree = new TTree("Events", "Tree Created by AnaModule");
  saveTree->Branch("nHits", &nHits);
  saveTree->Branch("nTriggerHits", &nTriggerHits);
  saveTree->Branch("eventID", &eventID);
  saveTree->Branch("runID", &runID);
  saveTree->Branch("spillID", &spillID);
  saveTree->Branch("trigger", &trigger);
  saveTree->Branch("NIM_1", &NIM_1);
  saveTree->Branch("NIM_2", &NIM_2);
  saveTree->Branch("NIM_3", &NIM_3);
  saveTree->Branch("NIM_4", &NIM_4);
  saveTree->Branch("NIM_5", &NIM_5);
  saveTree->Branch("MATRIX_1",&MATRIX_1);
  saveTree->Branch("MATRIX_2",&MATRIX_2);
  saveTree->Branch("MATRIX_3",&MATRIX_3);
  saveTree->Branch("MATRIX_4",&MATRIX_4);
  saveTree->Branch("MATRIX_5",&MATRIX_5);
  saveTree->Branch("detectorID", detectorID, "detectorID[nHits]/I");
  saveTree->Branch("elementID", elementID, "elementID[nHits]/I");
  saveTree->Branch("tdcTime", tdcTime, "tdcTime[nHits]/D");
  saveTree->Branch("driftDistance", driftDistance, "driftDistance[nHits]/D");
  saveTree->Branch("pos", pos, "pos[nHits]/D");
  
  saveTree->Branch("trigger_hit_detectorID", trigger_hit_detectorID, "trigger_hit_detectorID[nTriggerHits]/I");
  saveTree->Branch("trigger_hit_elementID", trigger_hit_elementID, "trigger_hit_elementID[nTriggerHits]/I");
  saveTree->Branch("trigger_hit_tdcTime", trigger_hit_tdcTime, "trigger_hit_tdcTime[nTriggerHits]/D");
  saveTree->Branch("trigger_hit_driftDistance", trigger_hit_driftDistance, "trigger_hit_driftDistance[nTriggerHits]/D");
  saveTree->Branch("trigger_hit_pos", trigger_hit_pos, "trigger_hit_pos[nTriggerHits]/D");

  if (saveReco)
  {
    saveTree->Branch("n_tracks", &n_tracks, "n_tracks/I");
    saveTree->Branch("track_charge", track_charge, "track_charge[n_tracks]/I");
    saveTree->Branch("track_nhits", track_nhits, "track_nhits[n_tracks]/I");
    saveTree->Branch("track_x_target", track_x_target, "track_x_target[n_tracks]/F");
    saveTree->Branch("track_y_target", track_y_target, "track_y_target[n_tracks]/F");
    saveTree->Branch("track_z_target", track_z_target, "track_z_target[n_tracks]/F");
    saveTree->Branch("track_px_target", track_px_target, "track_px_target[n_tracks]/F");
    saveTree->Branch("track_py_target", track_py_target, "track_py_target[n_tracks]/F");
    saveTree->Branch("track_pz_target", track_pz_target, "track_pz_target[n_tracks]/F");
    saveTree->Branch("track_x_st1", track_x_st1, "track_x_st1[n_tracks]/F");
    saveTree->Branch("track_y_st1", track_y_st1, "track_y_st1[n_tracks]/F");
    saveTree->Branch("track_z_st1", track_z_st1, "track_z_st1[n_tracks]/F");
    saveTree->Branch("track_px_st1", track_px_st1, "track_px_st1[n_tracks]/F");
    saveTree->Branch("track_py_st1", track_py_st1, "track_py_st1[n_tracks]/F");
    saveTree->Branch("track_pz_st1", track_pz_st1, "track_pz_st1[n_tracks]/F");
    saveTree->Branch("track_x_vtx", track_x_vtx, "track_x_vtx[n_tracks]/F");
    saveTree->Branch("track_y_vtx", track_y_vtx, "track_y_vtx[n_tracks]/F");
    saveTree->Branch("track_z_vtx", track_z_vtx, "track_z_vtx[n_tracks]/F");
    saveTree->Branch("track_px_vtx", track_px_vtx, "track_px_vtx[n_tracks]/F");
    saveTree->Branch("track_py_vtx", track_py_vtx, "track_py_vtx[n_tracks]/F");
    saveTree->Branch("track_pz_vtx", track_pz_vtx, "track_pz_vtx[n_tracks]/F");
    saveTree->Branch("track_m", track_m, "track_m[n_tracks]/F");
    saveTree->Branch("track_chisq", track_chisq, "track_chisq[n_tracks]/F");
    saveTree->Branch("track_prob", track_prob, "track_prob[n_tracks]/F");
    saveTree->Branch("track_quality", track_quality, "track_quality[n_tracks]/F");
    saveTree->Branch("track_nhits_st1", track_nhits_st1, "track_nhits_st1[n_tracks]/I");
    saveTree->Branch("track_nhits_st2", track_nhits_st2, "track_nhits_st2[n_tracks]/I");
    saveTree->Branch("track_nhits_st3", track_nhits_st3, "track_nhits_st3[n_tracks]/I");

    saveTree->Branch("n_dimuons", &n_dimuons, "n_dimuons/I");
    saveTree->Branch("dimuon_mass", dimuon_mass, "dimuon_mass[n_dimuons]/F");
    saveTree->Branch("dimuon_chisq", dimuon_chisq, "dimuon_chisq[n_dimuons]/F");
    saveTree->Branch("dimuon_x_vtx", dimuon_x_vtx, "dimuon_x_vtx[n_dimuons]/F");
    saveTree->Branch("dimuon_y_vtx", dimuon_y_vtx, "dimuon_y_vtx[n_dimuons]/F");
    saveTree->Branch("dimuon_z_vtx", dimuon_z_vtx, "dimuon_z_vtx[n_dimuons]/F");
    saveTree->Branch("dimuon_px", dimuon_px, "dimuon_px[n_dimuons]/F");
    saveTree->Branch("dimuon_py", dimuon_py, "dimuon_py[n_dimuons]/F");
    saveTree->Branch("dimuon_pz", dimuon_pz, "dimuon_pz[n_dimuons]/F");
    saveTree->Branch("dimuon_pmom_x", dimuon_pmom_x, "dimuon_pmom_x[n_dimuons]/F");
    saveTree->Branch("dimuon_pmom_y", dimuon_pmom_y, "dimuon_pmom_y[n_dimuons]/F");
    saveTree->Branch("dimuon_pmom_z", dimuon_pmom_z, "dimuon_pmom_z[n_dimuons]/F");
    saveTree->Branch("dimuon_nmom_x", dimuon_nmom_x, "dimuon_nmom_x[n_dimuons]/F");
    saveTree->Branch("dimuon_nmom_y", dimuon_nmom_y, "dimuon_nmom_y[n_dimuons]/F");
    saveTree->Branch("dimuon_nmom_z", dimuon_nmom_z, "dimuon_nmom_z[n_dimuons]/F");
    saveTree->Branch("dimuon_ppos_x", dimuon_ppos_x, "dimuon_ppos_x[n_dimuons]/F");
    saveTree->Branch("dimuon_ppos_y", dimuon_ppos_y, "dimuon_ppos_y[n_dimuons]/F");
    saveTree->Branch("dimuon_ppos_z", dimuon_ppos_z, "dimuon_ppos_z[n_dimuons]/F");
    saveTree->Branch("dimuon_npos_x", dimuon_npos_x, "dimuon_npos_x[n_dimuons]/F");
    saveTree->Branch("dimuon_npos_y", dimuon_npos_y, "dimuon_npos_y[n_dimuons]/F");
    saveTree->Branch("dimuon_npos_z", dimuon_npos_z, "dimuon_npos_z[n_dimuons]/F");
  }
}
