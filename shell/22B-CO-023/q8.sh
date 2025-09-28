#!/bin/bash

# Prompt the user to enter numbers
echo "Enter numbers separated by space:"
read -a numbers

# Initialize counters
odd_count=0
even_count=0

# Loop through each number
for num in "${numbers[@]}"; do
  if ((num % 2 == 0)); then
    ((even_count++))
  else
    ((odd_count++))
  fi
done

# Display the counts
echo "Number of even numbers: $even_count"
echo "Number of odd numbers: $odd_count"
