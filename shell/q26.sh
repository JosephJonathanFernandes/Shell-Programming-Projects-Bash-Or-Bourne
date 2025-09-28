#!/bin/bash

read -p "Enter a number: " num
original_num=$num
reverse_num=0

while (( num > 0 )); do
  remainder=$((num % 10))
  reverse_num=$((reverse_num*10 + remainder))
  num=$((num / 10))
done

if ((original_num == reverse_num)); then
  echo "$original_num is a palindrome."
else
  echo "$original_num is not a palindrome."
fi
