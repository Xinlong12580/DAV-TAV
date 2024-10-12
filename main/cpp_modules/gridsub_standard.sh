#!/bin/bash

run_number=$1
file_path=/data2/e1039/dst/run_00$run_number/
./generaterunfile.sh $file_path

njobs=$(grep -c '^' "./file_list.txt")

dir_macros=$(dirname $(readlink -f $BASH_SOURCE))

jobbase=fac$3_reducer$4_geomdummy_coarse$5_SpinQuest_Standard
jobname=fac$3_reducer$4_geomdummy_coarse$5_SpinQuest_Standard_reco_$run_number
do_sub=1
nevents=$2

echo "njobs=$njobs"
echo "nevents=$nevents"

if [ $do_sub == 1 ]; then
	echo "Grid mode."
	dir_data=/pnfs/e1039/scratch/users/$USER/DataHits
	work=$dir_data/$jobname
	ln -nfs $dir_data data
else
	echo "Local mode."
	work=$dir_macros/scratch/$jobname
fi
rm -rf         $work
mkdir -p       $work 
chmod -R 01755 $work
cd $dir_macros
tar -czvf public.tar.gz file_list.txt RecoE1039Data.C work support AnaModule setup.sh
rm $work/input*
for (( id=1; id<=$njobs; id++ )) ; do
	#if [ $id == 2 ] ; then
	#	exit
	#fi
	file_name=$(sed "${id}q;d" "file_list.txt")
	file_base=$(basename "$file_name" .root)
	echo "/seaquest/users/xinlongl/data3/*$jobbase/*$jobbase_$run_number/ana_$file_base.root"
	if [ -e /seaquest/users/xinlongl/data3/*$jobbase/*$jobbase_$run_number/ana_$file_base.root ] ; then
		echo "$3_$run_number already exist"
	
		continue
	fi
	echo $file_name
	tar -czvf $work/input_$id.tar.gz public.tar.gz file_list.txt $file_name
	mkdir -p $work/$id/out
	chmod -R 01755 $work/$id
	cp -a $dir_macros/gridrun_standard.sh $work/$id
	#cp -a input.tar.gz $work/$id
	if [ $do_sub == 1 ]; then
		CMD="/exp/seaquest/app/software/script/jobsub_submit_spinquest.sh"
		CMD+=" --expected-lifetime='long'"
		CMD+=" --memory=2000"
		CMD+=" -L $work/$id/log_gridrun.txt"
		CMD+=" -f $work/input_$id.tar.gz"
		CMD+=" -d OUTPUT $work/$id/out"
		CMD+=" file://$work/$id/gridrun_standard.sh $nevents $id $run_number $3 $4 $5"
		echo "$CMD"
		unbuffer $CMD |& tee $work/$id/log_jobsub_submit.txt
		RET_SUB=${PIPESTATUS[0]}
		test $RET_SUB -ne 0 && exit $RET_SUB
	else
		mkdir -p $work/$id/input
		cp -p $work/input_$id.tar.gz $work/$id/input
		cd $work/$id
		$work/$id/gridrun_standard.sh $nevents $id |& tee $work/$id/log_gridrun.txt
	fi
done	
