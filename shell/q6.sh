#!/bin/bash

# Prompt the user for source and destination file names
echo "Enter the source file name:"
read source_file
echo "Enter the destination file name:"
read destination_file

# Check if the source file exists
if [[ -f $source_file ]]; then
    # Copy the source file to the destination
    cp "$source_file" "$destination_file"
    echo "File copied from $source_file to $destination_file."
else
    # Display an error if the source file does not exist
    echo "Source file doesn't exist."
fi

