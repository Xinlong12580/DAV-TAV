import subprocess
import os
import ROOT
import helper
class DAVTAV_reco:
    def __init__(self,sample_file, data_type,output_dir,grid_on,top_dir):
        self.sample_file=sample_file
        self.data_type=data_type
        self.grid_on=grid_on
        self.top_dir=top_dir
   
    def Run(self):
        if self.grid_on==False:
            print(self.data_type)
            if self.data_type in ["AprimeSignal-Sim","Background-pythiaGenSim","Dimuon-particleGunSim"]:
                subprocess.run([self.top_dir+"/main/cpp_modules/compile_module.sh","MC_module"])
                helper.SourceScript(self.top_dir+"/main/cpp_modules/set_data_module_env.sh")
                if self.data_type == "AprimeSignal-Sim":
                    with open(self.sample_file,'r') as file:
                        for line in file:
                            line=line.strip()
                            subprocess.run(["root",self.top_dir+'/main/cpp_modules/RecoSim.C'])
                            #subprocess.run(["root",self.top_dir+'/main/cpp_modules/RecoSim.C(0,"'+self.top_dir+'","'+line+'")'])
                if self.data_type == "Dimuon-particleGunSim":
                    with open (self.sample_file,"r") as file:
                        for line in file:
                            line=line.strip()
                            pos_z_str,n_event_str=line.split()
                            n_event=int(n_event_str)
                            subprocess.run(["root",f'{self.top_dir}/main/cpp_modules/RecoSim.C("{self.top_dir}","Dimuon-particleGunSim",{n_event},"{pos_z_str}")'])

            if self.data_type in ["SeaQuest-run6","SpinQuest-commissioning"]:
                subprocess.run([self.top_dir+"/main/cpp_modules/compile_module.sh","data_module"])
                helper.SourceScript(self.top_dir+"/main/cpp_modules/set_data_module_env.sh")
                with open(self.sample_file,'r') as file:
                    for line in file:
                        line=line.strip()
                        print(self.top_dir+"/main/cpp_modules/RecoData.C(0,"+self.data_type+","+line+")")
                        subprocess.run(["root",self.top_dir+'/main/cpp_modules/RecoData.C('+self.top_dir+'","'+self.data_type+'",0,"'+line+'")'])
                        #reco_command=".x "+ self.top_dir+"/main/cpp_modules/RecoData.C(0,"+self.data_type+","+line+")"
                        #ROOT.gROOT.ProcessLine(reco_command)
        

        if self.grid_on==True:
            if self.data_type in ['AprimeSignal-Sim','Background-phythiaGenSim']:
                pass
            if self.data_type in ["SeaQuest-run6","SpinQuest-commissioning"]:
                pass
                #subprogress.run(['source', 'grid_sub.sh', sample_file] )
    def Report(self):
        pass



