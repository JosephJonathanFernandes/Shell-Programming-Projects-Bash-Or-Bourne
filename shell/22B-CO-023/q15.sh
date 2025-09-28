#!/bin/bash

# Conversion rate (change it as per the latest rate)
conversion_rate=83.00

# Prompt the user for input
read -p "Enter amount in dollars: " dollars

# Convert to rupees
rupees=$(echo "$dollars * $conversion_rate" | bc)

# Display the result
echo "$dollars USD is $rupees INR."
