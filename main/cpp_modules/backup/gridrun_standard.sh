#!/bin/bash
ls / 
#ls -a /home
#ls /scratch
#ls -a /usr
#ls /cvmfs
nevents=$1
job_id=$2
run_number=$3
fac=$4
reducer=$5
if [[ $6 == on ]] ; then
	coarse=true
elif [[ $6 = off ]] ; then
	coarse=false
fi
if [ -z ${CONDOR_DIR_INPUT+x} ]; then
	CONDOR_DIR_INPUT=./input;
	echo "CONDOR_DIR_INPUT is initiallized as $CONDOR_DIR_INPUT"
else
	echo "CONDOR_DIR_INPUT is set to '$CONDOR_DIR_INPUT'";
fi

if [ -z ${CONDOR_DIR_OUTPUT+x} ]; then
	CONDOR_DIR_OUTPUT=./out;
	mkdir -p $CONDOR_DIR_OUTPUT
	echo "CONDOR_DIR_OUTPUT is initiallized as $CONDOR_DIR_OUTPUT"
else
	echo "CONDOR_DIR_OUTPUT is set to '$CONDOR_DIR_OUTPUT'";
fi
ls
echo "hello, grid." | tee out.txt $CONDOR_DIR_OUTPUT/out.txt
echo "HOST = $HOSTNAME" | tee -a out.txt $CONDOR_DIR_OUTPUT/out.txt
pwd | tee -a out.txt $CONDOR_DIR_OUTPUT/out.txt
tar -xzvf $CONDOR_DIR_INPUT/input_$job_id.tar.gz
tar -xzvf public.tar.gz
ls -lh | tee -a out.txt $CONDOR_DIR_OUTPUT/out.txt
source /cvmfs/seaquest.opensciencegrid.org/seaquest/software/e1039/this-e1039.sh
source setup.sh 

file_list=file_list.txt
file_name=$(sed "${job_id}q;d" "$file_list")
file_base=$(basename "$file_name" .root)
in_file="${file_name:1}"
time root -b -q RecoE1039Data.C\($nevents,\"$in_file\",\"ana_$file_base\.root\",true,$run_number,$fac,\"$reducer\",$coarse\);
RET=$?
if [ $RET -ne 0 ] ; then
	echo "Error in RecoE1039Data.C: $RET"
	exit $RET
fi
mv ana_$file_base.root $CONDOR_DIR_OUTPUT/
echo "gridrun.sh finished!"
