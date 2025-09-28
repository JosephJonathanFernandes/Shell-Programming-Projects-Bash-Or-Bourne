#!/bin/bash 
echo "Multiplication table of 23:"
    for ((i=1; i<=10; i++)); do
        echo "23 * $i = $((23 * i))"
    done


echo "Cubes of odd numbers from 1 to 50:"
    for ((i=1; i<=50; i+=2)); do
        echo "$i^3 = $((i * i * i))"
    done
