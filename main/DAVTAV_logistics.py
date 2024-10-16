from enum import Enum
class DAVTAV_sample_types(Enum):
    A="mini_scale"
    B="small_scale"
    C="medium_scale"
    D="large_scale"

class DAVTAV_data_types(Enum):
    A="AprimeSignal-Sim"
    E="Dimuon-particleGunSim"
    B="Background-pythiaGenSim"
    C="SpinQuest-commissioning"
    D="SeaQuest-run6"

class DAVTAV_AprimeSignal_Sim_ana_types(Enum):
    A=None

class DAVTAV_Dimuon_particleGunSim_ana_types(Enum):
    A=None

class DAVTAV_SpinQuest_commissioning_ana_types(Enum):
    A=None

class DAVTAV_SeaQuest_run6_ana_types(Enum):
    A=None
