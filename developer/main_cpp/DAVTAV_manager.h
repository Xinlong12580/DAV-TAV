
class DAVTAV_manager{

public:
	DAVTAV_manager();
	DAVTAV_manager(std::string _sample_type, string _reco_type);
	~DAVTAV_manager();
	void Reco();
	void Ana();
	void Comp();
	std::string reco_types[5]={"SeaQuest_run6", "SpinQuest_commissioning", "Background_pythiaGenSim", "AprimeSignal_Sim", "All"};
	std::string sample_types[4]= {"mini", "small", "medium", "large"};
	std::string pileup_types[2]= {MC, SeaQuest};


private:
	DAVTAV_reco* DReco;
	DAVTAV_ana* DAna;
	DAVTAV_comp* DComp;
	std::string sample_type;DAVTAV_ana(std::string i_sample_name, string i_reco_type);
	std::string reco_type;
	std::string sample_location;
	std::string output_location
	std::string histo_set_type;
	std::vector<THisto1D> histo_set;
}




