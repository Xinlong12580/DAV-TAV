import subprocess
import os
import ROOT
import time
import secrets
import string
import helper
class DAVTAV_reco:
    def __init__(self,sample_file, data_type,output_dir,grid_on,e1039,top_dir):
        self.sample_file=sample_file
        self.data_type=data_type
        self.output_dir=output_dir
        self.grid_on=grid_on
        self.top_dir=top_dir
        self.e1039=e1039
   
    def Run(self):
        if self.grid_on==False:
            print(self.data_type)
            if self.data_type in ["AprimeSignal-Sim","Background-pythiaGenSim","Dimuon-particleGunSim"]:
                print("CP2")
                subprocess.run([self.top_dir+"/main/cpp_modules/compile_module.sh","MC_module"])
                helper.SourceScript(self.top_dir+"/main/cpp_modules/set_MC_module_env.sh")
                if self.data_type == "AprimeSignal-Sim":
                    with open(self.sample_file,'r') as file:
                        for line in file:
                            line=line.strip() 
                            file_base=os.path.basename(line)
                            out_file=f"{self.output_dir}/reco_{file_base}.root"
                            #subprocess.run(["root",self.top_dir+'/main/cpp_modules/RecoSim.C'])
                            subprocess.run(["root",f'{self.top_dir}/main/cpp_modules/RecoSim.C("{self.top_dir}","AprimeSignal-Sim",0,"{line}","{out_file}","{self.top_dir}/main/cpp_modules/RecoSim_config.ini")'])
                if self.data_type == "Dimuon-particleGunSim":
                    with open (self.sample_file,"r") as file:
                        for line in file:
                            line=line.strip()
                            pos_z_str,mom_z_str,n_event_str=line.split()
                            input_str=pos_z_str+":"+mom_z_str
                            n_event=int(n_event_str)
                            out_file=self.output_dir+f"/reco_Dimuon_particleGunSim_{pos_z_str}_{mom_z_str}_{n_event}.root"
                            subprocess.run(["root",f'{self.top_dir}/main/cpp_modules/RecoSim.C("{self.top_dir}","Dimuon-particleGunSim",{n_event},"{input_str}","{out_file}","{self.top_dir}/main/cpp_modules/RecoSim_config.ini")'])
                            #subprocess.run(["root",f'{self.top_dir}/main/cpp_modules/RecoSim.C("{self.top_dir}","Dimuon-particleGunSim",{n_event},"{pos_z_str}","~/test.root","{self.top_dir}/main/cpp_modules/RecoData_config.ini")'])#"{out_file}")'])

            if self.data_type in ["SeaQuest-run6","SpinQuest-commissioning"]:
                subprocess.run([self.top_dir+"/main/cpp_modules/compile_module.sh","data_module"])
                helper.SourceScript(self.top_dir+"/main/cpp_modules/set_data_module_env.sh")
                with open(self.sample_file,'r') as file:
                    for line in file:
                        line=line.strip()
                        print(self.top_dir+"/main/cpp_modules/RecoData.C(0,"+self.data_type+","+line+")")
                        file_base=os.path.basename(line)
                        out_file=f"{self.output_dir}/reco_{file_base}"
                        subprocess.run(["root",f'{self.top_dir}/main/cpp_modules/RecoData.C("{self.top_dir}","{self.data_type}",0,"{line}","{out_file}","{self.top_dir}/main/cpp_modules/RecoData_config.ini")'])
                        #subprocess.run(["root",self.top_dir+'/main/cpp_modules/RecoData.C("'+self.top_dir+'","'+self.data_type+'",0,"'+line+'","'+self.output_dir+'")'])
                        #reco_command=".x "+ self.top_dir+"/main/cpp_modules/RecoData.C(0,"+self.data_type+","+line+")"
                        #ROOT.gROOT.ProcessLine(reco_command)
        

        if self.grid_on==True:
            grid_dir=" "
            print("\033[31m"+"GRID mode is on. submitting jobs to GRID..."+"\033[0m")
            if self.data_type in ["AprimeSignal-Sim","Background-pythiaGenSim","Dimuon-particleGunSim"]:
                print("CP2")
                subprocess.run([self.top_dir+"/main/cpp_modules/compile_module.sh","MC_module"])
                bare_e1039=self.e1039.replace("/","",1)
                print(f"--transform='s,^{bare_e1039},,'")
                subprocess.run(["tar","-czvf",self.top_dir+"/main/cpp_modules/e1039_MC.tar.gz",self.e1039+"/core-inst",f"--transform=s,^{bare_e1039},,"])
                #print("tar"+" "+"-czvf"+" "+self.top_dir+"/main/cpp_modules/e1039_MC.tar.gz"+" "+self.e1039+"/core-inst"+" "+f"--transform='s,^{bare_e1039},,'")
                #subprocess.run(["tar","-czvf","/seaquest/users/xinlongl/projects/DAV-TAV/main/../main/cpp_modules/e1039_MC.tar.gz /seaquest/users/xinlongl/projects/Pro_DarkQuest_Sim/core-software/core-inst","--transform='s,^seaquest/users/xinlongl/projects/Pro_DarkQuest_Sim/core-software,,'"])
                subprocess.run(["tar","-czvf",self.top_dir+"/main/cpp_modules/public_MC.tar.gz",self.top_dir+"/main/cpp_modules/RecoSim.C",self.top_dir+"/main/cpp_modules/RecoSim_config.ini",self.top_dir+"/main/cpp_modules/MC_module/libsim_ana.so",self.top_dir+"/main/cpp_modules/MC_module_src",self.top_dir+"/main/cpp_modules/support",self.top_dir+"/main/cpp_modules/e1039_MC.tar.gz",f"--transform=s,^main/cpp_modules,,"])
                grid_dir="/pnfs/e1039/scratch/users/$USER/"+(''.join(secrets.choice(string.digits) for _ in range(12)))
                n_jobs=0
                #helper.SourceScript(self.top_dir+"/main/cpp_modules/set_MC_module_env.sh")
                if self.data_type == "AprimeSignal-Sim":
                    print(f"Open file: {self.sample_file}")
                    print(" ")
                    with open(self.sample_file,'r') as file:
                        lines=file.readlines()
                        n_jobs=len(lines)
                        print(str(n_jobs))
                        for ind in range(n_jobs):
                            line=(flines[ind]).strip() 
                            file_base=os.path.basename(line)
                            out_file=f"{reco_file_base}.root"
                            print(f"Total {n_jobs} jobs, submitting job {ind}...")
                            job_dir=grid_dir+"/"+str(ind)
                            subprocess.run([self.top_dir+"/main/cpp_modules/gridsub_MC.sh","AprimeSignal-Sim",0,line,out_file,"config_RecoSim.ini",job_dir])
                if self.data_type == "Dimuon-particleGunSim":
                    with open (self.sample_file,"r") as file:
                        for line in file:
                            line=line.strip()
                            pos_z_str,mom_z_str,n_event_str=line.split()
                            input_str=pos_z_str+":"+mom_z_str
                            n_event=int(n_event_str)
                            out_file=self.output_dir+f"/reco_Dimuon_particleGunSim_{pos_z_str}_{mom_z_str}_{n_event}.root"
                            subprocess.run(["root",f'{self.top_dir}/main/cpp_modules/RecoSim.C("{self.top_dir}","Dimuon-particleGunSim",{n_event},"{input_str}","{out_file}","{self.top_dir}/main/cpp_modules/RecoSim_config.ini")'])
                            #subprocess.run(["root",f'{self.top_dir}/main/cpp_modules/RecoSim.C("{self.top_dir}","Dimuon-particleGunSim",{n_event},"{pos_z_str}","~/test.root","{self.top_dir}/main/cpp_modules/RecoData_config.ini")'])#"{out_file}")'])
            print("Wait for GRID jobs to finish...")
            print(" ")
            for ind in range(10800):
                time.sleep(1)
                print(f"Expected running time: 10800 s, remaining time: {10800-ind} s",flush=True)
            for ind in range(n_jobs):
                subprocess.run(["cp",f"{grid_dir}/{str(ind)}/out/*.root", output_dir])
            if self.data_type in ["SeaQuest-run6","SpinQuest-commissioning"]:
                subprocess.run([self.top_dir+"/main/cpp_modules/compile_module.sh","data_module"])
    
    def Report(self):
        pass



