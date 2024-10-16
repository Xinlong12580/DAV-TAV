from DAVTAV_ana_modules.Dimuon_particleGunSim_ana import Dimuon_particleGunSim_ana
from DAVTAV_logistics import DAVTAV_sample_types, DAVTAV_data_types, DAVTAV_Dimuon_particleGunSim_ana_types, DAVTAV_AprimeSignal_Sim_ana_types, DAVTAV_SpinQuest_commissioning_ana_types, DAVTAV_SeaQuest_run6_ana_types
import subprocess
class DAVTAV_ana:
    def __init__(self,top_dir,reco_tag,sample_type,data_type,ana_type="All"):
        self.top_dir=top_dir
        self.sample_type=sample_type
        self.data_type=data_type
        self.reco_tag=reco_tag
        self.ana_type=ana_type
        self.input_dir=f"{self.top_dir}/reco_output/{self.reco_tag}/{self.sample_type}/{self.data_type}"
        self.output_dir=f"{self.top_dir}/ana_output/{self.reco_tag}/{self.sample_type}/{self.data_type}"
        subprocess.run(["mkdir","-p",f"{self.output_dir}"])

    def Run(self):
        if self.data_type=="Dimuon-particleGunSim":
            Dimuon_ana=Dimuon_particleGunSim_ana(self.input_dir,self.output_dir)
            Dimuon_ana.Run(self.ana_type)

