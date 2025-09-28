#!/bin/bash

read -p "Enter a number: " num
smallest_digit=9
temp=$num

while (( num > 0 )); do
  digit=$((num % 10))
  if ((digit < smallest_digit)); then
    smallest_digit=$digit
  fi
  num=$((num / 10))
done

echo "The smallest digit is: $smallest_digit"


sorted_dig=($(echo "$temp"|grep -o .|tr ' ' '\n'|sort -n |tr '\n' ' '))
echo "The smallest digit is: ${sorted_dig[0]}"

