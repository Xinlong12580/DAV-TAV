mkdir -p output

file="./run_list.txt"
vfac=$1
reducer_option=$2
coarse_mode=$3
tar -czvf public.tar.gz RecoE1039Data.C work support AnaModule setup.sh 
# Read the file line by line
while IFS= read -r line
do
  ./gridsub_standard.sh $line 0 $vfac $reducer_option $coarse_mode
done < "$file"
