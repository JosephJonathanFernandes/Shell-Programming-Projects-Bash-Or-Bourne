#!/bin/bash

# Prompt the user to enter numbers
echo "Enter numbers separated by space:"
read -a numbers

odd_count=0
even_count=0

for num in "${numbers[@]}";do
if ((num%2==0));then
((even_count++))
else
((odd_count++))
fi
done
echo "Even:$even_count and Odd:$odd_count"
