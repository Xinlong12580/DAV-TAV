no_file=1
for id in {1..100}
#for id in {7..10}
do
	echo $id
	ls /pnfs/e1039/scratch/users/$USER/DataHits/$1_reco_$2/$id/out/
	if [ -e /pnfs/e1039/scratch/users/$USER/DataHits/$1_reco_$2/$id/out/ana*root ] ; then
		file_name=$(basename "/pnfs/e1039/scratch/users/$USER/DataHits/$1_reco_$2/$id/out/"ana*root)
		echo $file_name
		if [ ! -e ./$file_name ] ; then  
			cp /pnfs/e1039/scratch/users/$USER/DataHits/$1_reco_$2/$id/out/ana*root .
			echo $id >> goodruns.txt
			no_file=0
		fi
	fi
done
if [ $no_file == 1 ] ; then
	exit 0
else
	exit 1
fi
