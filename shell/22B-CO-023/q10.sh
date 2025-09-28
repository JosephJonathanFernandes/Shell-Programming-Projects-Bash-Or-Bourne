#!/bin/bash

# Prompt for source and destination file names
echo "Enter the source file name:"
read source_file
echo "Enter the destination file name:"
read destination_file

# Check if the source file exists
if [[ -f "$source_file" ]]; then
  # Copy the contents of the source file to the destination file
  cp "$source_file" "$destination_file"
  echo "Contents of '$source_file' have been copied to '$destination_file'."
else
  echo "Source file '$source_file' does not exist."
fi
