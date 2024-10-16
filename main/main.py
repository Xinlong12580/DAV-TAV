from DAVTAV_manager import DAVTAV_manager

DManager=DAVTAV_manager(["/seaquest/users/xinlongl/projects/debug"],"mini_scale","Dimuon-particleGunSim","9995","Reconstruction_Efficiency_z")
#DManager=DAVTAV_manager(["/seaquest/users/xinlongl/projects/debug"],"mini_scale","SpinQuest-commissioning","1234","Reconstruction_Efficiency_z")

DManager.Reco()
DManager.Ana()
#DManager.Comp()
