#!/bin/bash

read -p "Enter the coefficients a, b, and c (separated by space): " a b c

discriminant=$((b*b - 4*a*c))

if ((discriminant > 0)); then
  root1=$(echo "scale=2; (-$b + sqrt($discriminant)) / (2*$a)" | bc)
  root2=$(echo "scale=2; (-$b - sqrt($discriminant)) / (2*$a)" | bc)
  echo "Roots are real and different:"
  echo "Root 1: $root1"
  echo "Root 2: $root2"
elif ((discriminant == 0)); then
  root=$(echo "scale=2; -$b / (2*$a)" | bc)
  echo "Roots are real and the same:"
  echo "Root: $root"
else
  echo "Roots are complex."
fi
