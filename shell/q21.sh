#!/bin/bash

read -p "Enter numbers separated by space: " -a numbers
sum=0

for num in "${numbers[@]}"; do
  sum=$((sum + num))
done

count=${#numbers[@]}
average=$(echo "scale=2; $sum / $count" | bc)
echo "Sum: $sum"
echo "Average: $average"
