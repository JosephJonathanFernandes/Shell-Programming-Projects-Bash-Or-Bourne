#!/bin/bash

# Set conversion rate (modify this as per the latest rate)
conversion_rate=83.00

read -p "Enter amount in US dollars: " dollars
rupees=$(echo "$dollars * $conversion_rate" | bc)
echo "$dollars USD = $rupees INR"
