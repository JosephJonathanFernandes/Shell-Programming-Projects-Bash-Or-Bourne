#!/bin/bash

# Prompt user for input
read -p "Enter a number: " num

if [ $num -gt 0 ]; then
echo "positive no"
elif [ $num -lt 0 ]; then
echo "negative"
else
echo "0"
fi

for((i=50;i<=100;i++));do
if ((i%3==0&&i%5!=0)); then
echo "$i"
fi
done


for((i=0;i<=50;i=i+2));do
echo "$((i*i*i))"
done
