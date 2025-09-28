#!/bin/bash
read -p "enter theno of rows:" n
read -p "enter theno of columns:" m

declare -A arr1
declare -A arr2
declare -A arr3 


for ((i=0;i<n;i++)); do
for ((j=0;j<m;j++)); do
read arr1[$i,$j]
done
done


for ((i=0;i<n;i++)); do
for ((j=0;j<m;j++)); do
read arr2[$i,$j]
done
done


for ((i=0;i<n;i++)); do
for ((j=0;j<m;j++)); do
 arr3[$i,$j]=$((arr1[$i,$j] + arr2[$i,$j]))
echo "${arr3[$i,$j]}"
done
done
