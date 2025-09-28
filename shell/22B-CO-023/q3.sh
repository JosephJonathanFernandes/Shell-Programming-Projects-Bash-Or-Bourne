#!/bin/bash

read -p "enter nos" num

digits=$(echo "$num" | grep -o . | sort -n | uniq)

digits_array=($digits)
if [ ${#digits_array[@]} -lt 2 ]; then
  echo "Not enough unique digits."
else
  echo "Second smallest digit: ${digits_array[1]}"
  echo "Second largest digit: ${digits_array[-2]}"
fi


