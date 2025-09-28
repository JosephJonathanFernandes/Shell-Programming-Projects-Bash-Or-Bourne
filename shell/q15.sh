#!/bin/bash

read -p "Enter coefficient a: " a
read -p "Enter coefficient b: " b
read -p "Enter coefficient c: " c

d=$((b*b-4*a*c))

if((d>0)); then
root1=$(echo "scale=2;(-$b+sqrt($d))/(2*$a)"|bc -l)
root2=$(echo "scale=2;(-$b-sqrt($d))/(2*$a)"|bc -l)
echo "Roots are real and different: $root1, $root2"
elif ((d==0)); then
root=$(echo "scale=2;(-$b)/(2*$a)"|bc -l)
echo "Roots are real and the same: $root"
else
real=$(echo "scale=2;(-$b)/(2*$a)"|bc -l)
imag=$(echo "scale=2;(sqrt(-$d)/(2*$a)"|bc -l)
echo "Roots are complex: $real + $imag i and $real - $imag i"
fi
