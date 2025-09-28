#!/bin/bash

LOG_FILE="log.txt"

# Function to check if directory exists
check_directory() {
    if [ ! -d "$1" ]; then
        echo "Error: Directory $1 does not exist."
        exit 1
    fi
}

# Function to log deleted files
log_deletion() {
    echo "$(date) - Deleted: $1" >> "$LOG_FILE"
}

# Get user input
read -p "Enter directory path: " dir
read -p "Enter the number of largest files to display: " count

# Validate directory
check_directory "$dir"

# List top N largest files
echo -e "\nTop $count largest files in $dir:"
largest_files=$(du -ah "$dir" 2>/dev/null | sort -rh | head -n "$count")

# Display the files
echo "$largest_files"

# Ask for deletion
echo -e "\nDo you want to delete any file? (yes/no)"
read choice

if [[ "$choice" == "yes" ]]; then
    echo "Enter the file name (full path) to delete: "
    read file_to_delete
    if [ -f "$file_to_delete" ]; then
        rm -i "$file_to_delete"
        if [ ! -f "$file_to_delete" ]; then
            log_deletion "$file_to_delete"
            echo "File deleted successfully. Logged in log.txt."
        else
            echo "Error: File could not be deleted."
        fi
    else
        echo "Error: File not found!"
    fi
else
    echo "No files were deleted."
fi
