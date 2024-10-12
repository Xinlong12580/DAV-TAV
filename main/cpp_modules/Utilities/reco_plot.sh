jobname=$1
mkdir -p $jobname
python3 reco_plot.py $jobname
mv *root *png $jobname
