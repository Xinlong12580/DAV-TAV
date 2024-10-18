#!/bin/bash
data_type=$1
n_events=$2
in_file=$3
out_file=$4
config_file=$5
top_dir="None"
job_dir=$6
mkdir -p $job_dir
chmod -R 01755 $job_dir
dir_macros=$(dirname $(readlink -f $BASH_SOURCE))

cd $dir_macros
tar -czvf input_MC.tar.gz public_MC.tar.gz in_file

mkdir -p $job_dir/out
cp -a $dir_macros/gridrun_RecoSim.sh $job_dir
CMD="/exp/seaquest/app/software/script/jobsub_submit_spinquest.sh"
CMD+=" --expected-lifetime='long'"
CMD+=" --memory=2000"
CMD+=" -L $job_dir/log_gridrun.txt"
CMD+=" -f $dir_macros/input_MC.tar.gz"
CMD+=" -d OUTPUT $job_dir/out"
CMD+=" file://$job_dir/gridrun_RecoSim.sh $data_type $n_events $in_file $out_file $config_file"
echo CMD
unbuffer $CMD |& tee $job_dir/log_jobsub_submit.txt
RET_SUB=${PIPESTATUS[0]}
test $RET_SUB -ne 0 && exit $RET_SUB
