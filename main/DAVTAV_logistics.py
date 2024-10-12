from enum import Enum
class DAVTAV_sample_types(Enum):
    A="mini_scale"
    B="small_scale"
    C="medium_scale"
    D="large_scale"

class DAVTAV_data_types(Enum):
    A="AprimeSignal-Sim"
    B="Background-pythiaGenSim"
    C="SpinQuest-commissioning"
    D="SeaQuest-run6"
