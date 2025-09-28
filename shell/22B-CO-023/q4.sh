#!/bin/bash

# Input number of rows and columns
echo -n "Enter number of rows: "
read m
echo -n "Enter number of columns: "
read n

# Initialize matrices A and B
declare -A arr1
declare -A arr2
declare -A arr3

# Input elements of matrix A
echo "Enter elements of matrix A:"
for ((i=1; i<=m; i++)); do
  for ((j=1; j<=n; j++)); do
    echo -n "Enter element ($i,$j): "
    read arr1[$i,$j]
  done
done

# Display matrix A
echo "Elements of matrix A:"
for ((i=1; i<=m; i++)); do
  for ((j=1; j<=n; j++)); do
    echo -n "${arr1[$i,$j]} "
  done
  echo
done

# Input elements of matrix B
echo "Enter elements of matrix B:"
for ((i=1; i<=m; i++)); do
  for ((j=1; j<=n; j++)); do
    echo -n "Enter element ($i,$j): "
    read arr2[$i,$j]
  done
done

# Display matrix B
echo "Elements of matrix B:"
for ((i=1; i<=m; i++)); do
  for ((j=1; j<=n; j++)); do
    echo -n "${arr2[$i,$j]} "
  done
  echo
done

# Add matrices A and B
for ((i=1; i<=m; i++)); do
  for ((j=1; j<=n; j++)); do
    arr3[$i,$j]=$(( arr1[$i,$j] + arr2[$i,$j] ))
  done
done

# Display result after addition
echo "After addition, the matrix is:"
for ((i=1; i<=m; i++)); do
  for ((j=1; j<=n; j++)); do
    echo -n "${arr3[$i,$j]} "
  done
  echo
done
