#!/bin/bash

# Using (( )) for arithmetic evaluation
for ((i = 1; i <= 50; i++)); do
  if ((i % 2 != 0)); then
    cube=$((i * i * i))
    echo "$cube"
  fi
done

echo "-----------------------------------"

# Using [ ] for arithmetic evaluation
for ((i = 1; i <= 50; i++)); do
  if [ $((i % 2)) -ne 0 ]; then
    cube=$((i * i * i))
    echo "$cube"
  fi
done
