mkdir -p output

file_path=/data2/e1039/dst/run_00$1/
./generaterunfile.sh $file_path

file="./file_list.txt"

# Read the file line by line
while IFS= read -r line
do
  file_base=$(basename "$line" .root)
  # Process each line
  echo "$file_base"
  root -b -q RecoE1039Data.C\(0,\"$line\",\"output\/ana_$file_base\.root\",true,$1\);
done < "$file"
