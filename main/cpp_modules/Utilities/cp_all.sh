

file="../utilities/run_list.txt"
datetoday=$1
jobname=$2
no_file=1
cd ..
mkdir -p "$datetoday"_"$jobname"
cd "$datetoday"_"$jobname"
# Read the file line by line
while IFS= read -r line
do
	dirname="$datetoday"_"$jobname"_$line
	echo $dirname
	mkdir -p $dirname
	cp ../utilities/cp_file.sh $dirname
	cd $dirname
	echo $2
	./cp_file.sh $jobname $line
	if [ $? == 1 ] ; then
		no_file=0
	fi
	cd ..
done < "$file"
cd utilities
if [ $no_file == 1 ] ; then
	echo "NO FILES COPIED"
else
	echo "ALL FILES COPIED"
fi
