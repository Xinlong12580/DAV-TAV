#include<DAVTAV_manager>

DAVTAV_manager::DAVTAV_manager()
{}

DAVTAV_manager::DAVTAV_manager(string _sample_type, string _reco_type)sample_type(_sample_type):reco_type(_reco_type){
	sample_location="../samples/"+sample_type;
	DReco=new DAVTAV_reco;
	DAna=new DAVTAV_ana;
	DComp=new DAVTAV_comp;
	DReco->SetType(reco_type);
}

DAVTAV_manager::~DAVTAV_manager()
{
	delete DReco;
	delete DAna;
	delete DComp;
}

void DAVTAV_manager::Reco(){
	if(reco_type=="SeaQuest_run6")
}
