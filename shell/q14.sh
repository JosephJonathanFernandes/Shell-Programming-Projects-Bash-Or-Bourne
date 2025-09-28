#!/bin/bash

read -p "Enter n: " n
sum=0

# Loop through numbers from 2 to n
for ((i=2; i<=n; i++)); do
    is_prime=1  # Assume the number is prime
    
    # Check divisors from 2 to sqrt(i)
    for ((j=2; j*j<=i; j++)); do
        if ((i % j == 0)); then
            is_prime=0  # Not a prime number
            break
        fi
    done
    
    # If the number is prime, add it to the sum
    if ((is_prime == 1)); then
        sum=$((sum + i))
    fi
done

echo "The sum of all prime numbers up to $n is: $sum"
