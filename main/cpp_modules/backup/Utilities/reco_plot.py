import ROOT
import glob
import subprocess
import sys
ROOT.gROOT.SetBatch(True)
jobname = sys.argv[1]
dirname='/seaquest/users/xinlongl/data3/'
basedir= dirname+jobname
allsubdirs=subprocess.check_output(f'ls {basedir} | grep  _ | grep -v root',shell=True,text=True).strip().split('\n')
#print(subdirs)
# Total dataset is 11GB so split up into multiple dataframes. Add the histograms at the end
subdirs=[]
for allsubdir in allsubdirs:
    sub=allsubdir[-4:]
    run=int(sub)
    if run>61:
        subdirs.append(allsubdir)
    print(run)
print(subdirs)
hmasses = []
hchisqs=[]
chisq_le_8s=[]
hvtxs   = []
h2ds    = []
mass_near_target = []
mass_near_target_SQ = []
mass_near_magnetStart = []
mass_near_magnetEnd = []
mass_after_magnetEnd = []
mass_FPGA5=[]
xy_vtxs = []
chisq_cuts=[]
for subdir in subdirs:
    print(f'Creating RDF from {basedir}/{subdir}/*.root')
    rdf = ROOT.RDataFrame('Events', f'{basedir}/{subdir}/*.root')
    # Dimuon mass plot
    hmass = rdf.Histo1D(("dimuon_mass","dimuon_mass",80,0,10),"dimuon_mass")
    hmasses.append(hmass)
    #Dimuon chisq
    hchisq=rdf.Histo1D(("dimuon_chisq","dimuon_chisq",20,0,20),"dimuon_chisq")
    hchisqs.append(hchisq)
    # Dimuon z vertex plot
    hvtx = rdf.Histo1D(("dimuon_z_vtx","dimuon_z_vtx",160,-600,800),"dimuon_z_vtx")
    hvtxs.append(hvtx)
    # 2D plot mass vs vertex
    h2d = rdf.Histo2D(("mass_vs_vtx","dimuon mass vs z vtx",20,0,10,20,-600,800),"dimuon_mass","dimuon_z_vtx")
    h2ds.append(h2d)
    req = 'dimuon_chisq <=6 && dimuon_z_vtx >= -600 && dimuon_z_vtx <= 200'
    chisq_le_8 = rdf.Define("chisq_less_than_or_equals_8",f"dimuon_mass[{req}]").Histo1D(("dimuon_mass_with_chisq_cut",f"dimuon_mass[{req}]",50,0,10),"chisq_less_than_or_equals_8")
    chisq_le_8s.append(chisq_le_8)
    # Zoom in on the masses near the regions
    req = 'dimuon_chisq <=6'
    chisq_cut = rdf.Define("chisq_less_than_or_equals_6",f"dimuon_mass[{req}]").Histo1D(("dimuon_mass_with_chisq_cut6",f"dimuon_mass[{req}]",50,0,10),"chisq_less_than_or_equals_6")
    chisq_cuts.append(chisq_cut)
    
    req = 'dimuon_z_vtx >= -150 && dimuon_z_vtx <= -110'
    hmass_near_target = rdf.Define("mass_near_target",f"dimuon_mass[{req}]").Histo1D(("dimuon_mass_near_target",f"dimuon_mass[{req}]",50,0,10),"mass_near_target")
    mass_near_target.append(hmass_near_target)

    req = 'dimuon_z_vtx >= -20 && dimuon_z_vtx <= 20'
    hmass_near_magStart = rdf.Define("mass_near_magStart",f"dimuon_mass[{req}]").Histo1D(("dimuon_mass_near_magnetStart",f"dimuon_mass[{req}]",50,0,10),"mass_near_magStart")
    mass_near_magnetStart.append(hmass_near_magStart)

    req = 'dimuon_z_vtx >= 480 && dimuon_z_vtx <= 520'
    hmass_near_magnetEnd = rdf.Define("mass_near_magEnd",f"dimuon_mass[{req}]").Histo1D(("dimuon_mass_near_magnetEnd",f"dimuon_mass[{req}]",50,0,10),"mass_near_magEnd")
    mass_near_magnetEnd.append(hmass_near_magnetEnd)
    
    req = 'dimuon_z_vtx >= 500 && dimuon_z_vtx <= 600'
    hmass_after_magnetEnd = rdf.Define("mass_after_magEnd",f"dimuon_mass[{req}]").Histo1D(("dimuon_mass_after_magnetEnd",f"dimuon_mass[{req}]",50,0,10),"mass_after_magEnd")
    mass_after_magnetEnd.append(hmass_after_magnetEnd)

    req = 'MATRIX_5 != 0'
    hmass_FPGA5 = rdf.Define("mass_FPGA5",f"dimuon_mass[{req}]").Histo1D(("dimuon_FPGA5",f"dimuon_mass[{req}]",50,0,10),"mass_FPGA5")
    mass_FPGA5.append(hmass_FPGA5)
    
    req = 'dimuon_z_vtx >= -600 && dimuon_z_vtx <= 150'
    hmass_near_targetSQ = rdf.Define("mass_near_target_SQ",f"dimuon_mass[{req}]").Histo1D(("dimuon_mass_near_targetSQ",f"dimuon_mass[{req}]",50,0,10),"mass_near_target_SQ")
    mass_near_target_SQ.append(hmass_near_targetSQ)

    hxy = rdf.Histo2D(("x_vs_y_vtxs","dimuon X vs Y vertex",20,-10,10,20,-10,10),"dimuon_x_vtx","dimuon_y_vtx")
    xy_vtxs.append(hxy)


out = ROOT.TFile.Open('all.root','RECREATE')
out.cd()

for group in [chisq_cuts, chisq_le_8s, hmasses, hchisqs, hvtxs, h2ds, mass_near_target, mass_near_magnetStart, mass_near_magnetEnd, mass_after_magnetEnd, mass_FPGA5, xy_vtxs, mass_near_target_SQ]:
    # Clone the first hist, reset it for blank slate
    h = group[0].Clone()
    print(f'Plotting {h.GetName()}')
    h.Reset()
    c = ROOT.TCanvas('c','c')
    c.cd()
    for hist in group:
        
        h.Add(hist.GetPtr())
    h.Write()
    la=ROOT.TLatex(0.5,0.8,"Preliminary");
    la.SetNDC()
    if isinstance(h,ROOT.TH2):
        h.Draw("COLZ")
        la.DrawLatex(0.5,0.8,"Preliminary")
    else:
        h.Draw("pe0")
        la.Draw("Same")
    c.Print(f'{h.GetName()}.png')

