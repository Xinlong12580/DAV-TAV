import os
import secrets
import subprocess
import string
import helper
from DAVTAV_reco import DAVTAV_reco
from DAVTAV_ana import DAVTAV_ana
from DAVTAV_comp import DAVTAV_comp
from DAVTAV_logistics import DAVTAV_sample_types, DAVTAV_data_types
class DAVTAV_manager:
    def __init__(self, branches,sample_type,data_type,random_tag=None,ana_type="All"):
        if sample_type not in DAVTAV_sample_types._value2member_map_:
            raise ValueError("Invalid sample type!")
        if data_type not in DAVTAV_data_types._value2member_map_ and data_type != "All":
            raise ValueError("Invalid data type!")
        self.top_dir=os.path.dirname(os.path.abspath(__file__))+"/.."
        
        self.branches=branches
        self.sample_type=sample_type
        self.data_type=data_type
        self.sample_top_dir=self.top_dir+"/samples/"+sample_type
        self.grid_on=False
        self.mute=False
        self.random_tag="1234"
        if random_tag==None:
            self.random_tag=''.join(secrets.choice(string.digits) for _ in range(4))
        else:
            self.random_tag=random_tag
        self.branch_tag=[]
        for branch in self.branches:
            branch_name=subprocess.check_output(["git","-C",branch+"/e1039-core","rev-parse","--abbrev-ref","HEAD"],universal_newlines=True).strip()
            commit_time=subprocess.check_output(["git","-C",branch+"/e1039-core","log","-1","--format=%cd"],universal_newlines=True).strip().replace(" ","")
            commit_hash=subprocess.check_output(["git","-C",branch+"/e1039-core","log","-1","--format=%H"],universal_newlines=True).strip()
            tag=branch_name+"@@"+commit_time+"@@"+commit_hash+"@@"+self.random_tag
            self.branch_tag.append(tag)
        self.reco_tag=self.branch_tag
        self.ana_tag=self.reco_tag
        self.comp_tag=None
        self.ana_type=ana_type
        if len(self.ana_tag)==2:
            self.comp_tag=self.ana_tag[0]+"%$"+self.ana_tag[1]
        
        self.reco_top_dir=[self.top_dir+"/reco_output/"+r_tag+"/"+sample_type for r_tag in self.reco_tag]
        self.ana_top_dir=None
        self.comp_top_dir=None

    def Reco(self): 
        for i in range(len(self.branches)):
            branch=self.branches[i]
            reco_tag=self.reco_tag[i]
            branch_env=branch+"/core-inst/this-e1039.sh"
            helper.SourceScript(branch_env)
            sample_files=[]
            output_dirs=[]
            sample_files=[]
            if self.data_type != "All":
                sample_file=self.sample_top_dir+"/"+self.data_type+"/DAVTAV_raw_list.txt"
                sample_files.append(sample_file)
                output_dir=self.reco_top_dir[i]+"/"+self.data_type
                output_dirs.append(output_dir)
                subprocess.run(["mkdir","-p",output_dir])
            else:
                for d_type in DAVTAV_data_types._value2member_map_:
                    sample_file=self.sample_top_dir+"/"+self.data_type+"/DAVTAV_raw_list.txt"
                    sample_files.append(sample_file)
                    output_dir=self.reco_top_dir[i]+"/"+d_type
                    output_dirs.append(output_dir)
                    subprogress.run(["mkdir","-p",output_dir])
            
            if self.data_type !="All":
                DReco=DAVTAV_reco(sample_files[0],self.data_type,output_dirs[0],self.grid_on,branch,self.top_dir)
                print("chekcpoint1")
                DReco.Run()
                DReco.Report()
            else:
                for j in len(DAVTAV_data_types._value2member_map_):
                    d_type=DAVTAV_data_types._value2member_map_[j]
                    DReco=DAVTAV_reco(sample_files[j],d_type,output_dirs[j],self.grid_on,branch,self.top_dir)
                    DReco.Run()
                    DReco.Report()
    
    def Ana(self):
        for a_tag in self.ana_tag:
            DAna=DAVTAV_ana(self.top_dir,a_tag,self.sample_type,self.data_type,self.ana_type)
            DAna.Run()
        

    def Comp(self):
        #if len(ana_files !=2):
            #raise ValueError("For comparision you need two sets of analysis level data")
        DComp=DAVTAV_comp()
        DComp.Run()

