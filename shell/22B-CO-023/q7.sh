#!/bin/bash

# Read the array elements from user input
echo "Enter array elements separated by space:"
read -a arr

# Sort in ascending order
sorted_asc=$(echo "${arr[@]}" | tr ' ' '\n' | sort -n | tr '\n' ' ')

# Sort in descending order
sorted_desc=$(echo "${arr[@]}" | tr ' ' '\n' | sort -nr | tr '\n' ' ')

# Print sorted arrays
echo "Sorted in ascending order: $sorted_asc"
echo "Sorted in descending order: $sorted_desc"
