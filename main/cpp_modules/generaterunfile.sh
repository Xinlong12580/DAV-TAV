DIRECTORY_PATH=$1
OUTPUT_FILE="file_list.txt"

# Use the find command to list all files and redirect the output to the output file
find "$DIRECTORY_PATH" -type f > "$OUTPUT_FILE"
