#!/bin/bash

for ((i = 50; i <= 100; i++)); do
  if ((i % 3 == 0 && i % 5 != 0)); then
    echo "$i"
  fi
done

echo "-----------------------------------"

for ((i = 50; i <= 100; i++)); do
  if [ $((i % 3)) -eq 0 ] && [ $((i % 5)) -ne 0 ]; then
    echo "$i"
  fi
done
