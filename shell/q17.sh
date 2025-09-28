#!/bin/bash

read -p "Enter a number: " num

# Check if the number is prime
is_prime=1
if ((num < 2)); then
  is_prime=0
else
  for ((i = 2; i * i <= num; i++)); do
    if ((num % i == 0)); then
      is_prime=0
      break
    fi
  done
fi

if ((is_prime == 1)); then
  echo "$num is a prime number."
else
  echo "$num is not a prime number."
fi

# Generate its square
square=$((num * num))
echo "The square of $num is $square."
