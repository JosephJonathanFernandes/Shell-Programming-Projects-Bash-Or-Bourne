#!/bin/bash
print_address() {
    read -p "Enter your address: " address
    read -p "How many times do you want to print your address? " n
    for ((i=0; i<n; i++)); do
        echo "$address"
    done
}
check_number() {
    read -p "Enter a number: " number
    if (( number > 0 )); then
        echo "The number is positive."
    elif (( number < 0 )); then
        echo "The number is negative."
    else
        echo "The number is zero."
    fi
}
copy_files() {
read -p "Enter the directory to copy files to: " directory
    read -p "Enter the files to copy (space-separated): " -a files
    mkdir -p "$directory"  # Create the directory if it does not exist
    for file in "${files[@]}"; do
        if [ -e "$file" ]; then
            cp "$file" "$directory"
            echo "Copied $file to $directory."
        else
            echo "File $file does not exist."
        fi
    done
}
while true; do
    echo "Menu:"
    echo "1. Print your address n times"
    echo "2. Check if a number is positive, negative, or zero"
    echo "3. Copy multiple files to a directory"
    echo "4. Exit"
    read -p "Choose an option: " choice

    case $choice in
        1) print_address ;;
        2) check_number ;;
        3) copy_files ;;
        4) exit 0 ;;
        *) echo "Invalid option. Please try again." ;;
    esac
done
