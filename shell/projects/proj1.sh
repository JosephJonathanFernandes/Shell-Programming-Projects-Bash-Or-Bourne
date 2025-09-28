#!/bin/bash

LOG_FILE="log.txt"

# Colors for better UI
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m' # No Color

# Function to check if directory exists
check_directory() {
    if [ ! -d "$1" ]; then
        echo -e "${RED}Error: Directory $1 does not exist.${NC}"
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
echo -e "\n${YELLOW}Top $count largest files in $dir:${NC}"
largest_files=$(du -ah "$dir" 2>/dev/null | sort -rh | head -n "$count")

# Display the files
echo "$largest_files"

# Ask for deletion
echo -e "\n${YELLOW}Do you want to delete any file? (yes/no)${NC}"
read choice

if [[ "$choice" == "yes" ]]; then
    echo "Enter the file name (full path) to delete: "
    read file_to_delete
    if [ -f "$file_to_delete" ]; then
        rm -i "$file_to_delete"
        log_deletion "$file_to_delete"
        echo -e "${GREEN}File deleted successfully. Logged in $LOG_FILE.${NC}"
    else
        echo -e "${RED}Error: File not found!${NC}"
    fi
else
    echo -e "${GREEN}No files were deleted.${NC}"
fi

