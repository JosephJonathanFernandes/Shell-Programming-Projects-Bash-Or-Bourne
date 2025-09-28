#!/bin/bash

# Prompt the user to enter a number
echo "Enter a number:"
read num

# Extract digits, sort them, and remove duplicates
sorted_digits=$(echo "$num" | grep -o . | sort -n | uniq)

# Convert the sorted digits into an array
sorted_array=($(echo "$sorted_digits"))

# Get the second smallest and second largest digits
second_min=${sorted_array[1]}
second_max=${sorted_array[-2]}

# Display the results
echo "Second smallest digit: $second_min"
echo "Second largest digit: $second_max"
