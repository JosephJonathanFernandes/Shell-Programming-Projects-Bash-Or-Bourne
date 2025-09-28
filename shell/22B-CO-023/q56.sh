#!/bin/bash

# Read the array elements from user input
echo "Enter array elements separated by space:"
read -a arr

# Initialize max with the first element of the array
max=${arr[0]}

# Iterate through the array to find the maximum value
for ((i = 0; i < ${#arr[@]}; i++)); do
  if ((arr[i] > max)); then
    max=${arr[i]}
  fi
done

# Print the maximum value
echo "The maximum value is: $max"
