#!/bin/bash

# Read the array elements from user input
echo "Enter array elements separated by space:"
read -a arr


for ((i = 0; i < ${#arr[@]}-1; i++)); do
for ((j=i+1 ; j < ${#arr[@]} ; j++)); do
if (( arr[i] > arr[j] )); then
temp=${arr[i]}
arr[i]=${arr[j]}
arr[j]=$temp

fi
done
done

echo "${arr[@]}"

echo " ---------------------------------"


for ((i = 0; i < ${#arr[@]}-1; i++)); do
for ((j=i+1 ; j < ${#arr[@]} ; j++)); do
if (( arr[i] < arr[j] )); then
temp=${arr[i]}
arr[i]=${arr[j]}
arr[j]=$temp

fi
done
done

echo "${arr[@]}"
