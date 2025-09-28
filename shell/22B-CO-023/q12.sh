#!/bin/bash

# Read inputs
read -p "Enter Principal (P): " P
read -p "Enter Rate of Interest (R): " R
read -p "Enter Time (T): " T

# Calculate simple interest
SI=$((P * R * T / 100))

# Display the result
echo "Simple Interest: $SI"
