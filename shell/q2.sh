#!/bin/bash

read -p "enter a number" num

sorted_digit=$(echo "$num"|grep -o .|sort -n|uniq)

second_smallest=$(echo "$sorted_digit"|head -n 2|tail -n 1)

echo "$second_smallest"

second_largest=$(echo "$sorted_digit"|tail -n 2|head -n 1)

echo "$second_largest"

sorted_digits=($sorted_digit)

echo "${sorted_digits[1]} and ${sorted_digits[-2]}"


read -p "enter a number" num

sorted_digit1=$(echo "$num"|grep -o .|sort -n|uniq)

second_smallest1=$(echo "$sorted_digit1"|cut -d' ' -f 2)

echo "$second_smallest1"

second_largest1=$(echo "$sorted_digit1"|cut -d' ' -f 2)

echo "$second_largest1"
