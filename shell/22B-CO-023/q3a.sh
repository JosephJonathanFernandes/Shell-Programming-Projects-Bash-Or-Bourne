#!/bin/bash

read -p "Enter number: " num

# Initialize the array for digits
digits=()

# Extract each digit of the number
while [ -n "$num" ]; do
  digits+=("${num:0:1}")
  num="${num:1}"
done

# Initialize variables for smallest and largest digits
smallest=9
largest=0
second_smallest=9
second_largest=0

# Loop through each digit in the digits array
for digit in ${digits[@]}; do
  # Finding the smallest and second smallest
  if [ $digit -lt $smallest ]; then
    second_smallest=$smallest
    smallest=$digit
  elif [ $digit -lt $second_smallest ] && [ $digit -ne $smallest ]; then
    second_smallest=$digit
  fi

  # Finding the largest and second largest
  if [ $digit -gt $largest ]; then
    second_largest=$largest
    largest=$digit
  elif [ $digit -gt $second_largest ] && [ $digit -ne $largest ]; then
    second_largest=$digit
  fi
done

# Output the results
echo "Second smallest digit: $second_smallest"
echo "Second largest digit: $second_largest"
