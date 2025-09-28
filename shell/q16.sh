#!/bin/bash

year=2000
count=0

echo "20 Leap Years from 2000:"
while ((count<=20)); do
if(( year%4==0 && year%100!=0 || year%400==0 )); then
echo "$year"
((count++))

fi
((year++))


done
