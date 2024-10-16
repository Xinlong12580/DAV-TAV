import glob
import ROOT
ROOT.gROOT.SetBatch(True)
class Dimuon_particleGunSim_ana:
    def __init__(self,input_dir,output_dir):
        self.input_dir=input_dir
        self.output_dir=output_dir

    def Run(self, ana_type):
        if ana_type=="Reconstruction_Efficiency_z":
            files=glob.glob(f"{self.input_dir}/reco_*root")
            valid_files=[f for f in files if "DST" not in f]
            graph=ROOT.TGraph()
            for file in valid_files:
                pos_z=float(file[-20:-14])
                #print(pos_z)
                rdf=ROOT.RDataFrame('Events',file)
                ntot=rdf.Count().GetValue()
                nrecoed=rdf.Filter("n_dimuons==1").Count().GetValue()
                eff=float(nrecoed)/float(ntot)*100.0
                graph.AddPoint(pos_z,eff)
            c=ROOT.TCanvas("c","c")
            graph.Sort()
            graph.Draw("AL*")
            c.Print(f"{self.output_dir}/Reconstruction_Efficiency_z.png")
            ana_file=ROOT.TFile.Open(f"{self.output_dir}/ana_Dimuon-particleGunSim.root","RECREATE")
            ana_file.WriteObject(graph,"Reconstruction_Efficiency_z")

                



