# DAV-TAV
Darkquest Automated Validation for Tracking And Vertexing
##How to set up DAV-TAV on spinquestgpvm
To run simulation and reconstruction module of DAV-TAV you need to have `e1039-core` software installed with a proper installation position. These commands install the e1039-core under a directory `my-e1039-core`:
```bash
git clone -b testio  https://github.com/Xinlong12580/e1039-core
cd e1039-core/script
./setup-install.sh auto
source ../../core-inst/this-e1039.sh
cd ..
./build.sh
cd ../..
```
Then clone the DAV-TAV branch:
```bash
git clone https://github.com/Xinlong12580/DAV-TAV
```
go to the main directory and check out the main.py file:
```
cd DAV-TAV/main
vim main.py
```
change the first argument for the `DAVTAV_manager` class to the location of the `e1039-core` software you just installed:
```
DManager=DAVTAV_manager(["/path/to/my-e1039-core"],"mini_scale","Dimuon-particleGunSim","9998","Reconstruction_Efficiency_z")
```
quit vim, and run:
```
python main.py
```
After it is finished, check out the reconstruction level output and the analysis level output:
```
ls ../reco_output/*9998/mini_scale/Dimuon-particleGunSim/
ls ../ana_output/*9998/mini_scale/Dimuon-particleGunSim/
```

  

