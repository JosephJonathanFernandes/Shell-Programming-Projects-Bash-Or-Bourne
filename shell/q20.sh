#!/bin/bash

read -p "Enter a string: " str
read -p "Enter a character to count: " char
count=$(echo "$str"|grep -o "$char"|wc -l)
echo "The character '$char' occurs $count times in the string '$str'."
