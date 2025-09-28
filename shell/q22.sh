#!/bin/bash

read -p "Enter the directory path: " dir

if [[ -d "$dir" ]]; then

file_count=$(find "$dir" -type f|wc -l)
echo "Number of files in directory '$dir': $file_count"
else
  echo "Invalid directory!"
fi
