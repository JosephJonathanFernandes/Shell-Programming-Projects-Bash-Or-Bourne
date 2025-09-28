#!/bin/bash

while true; do
echo "Menu:"
  echo "a) Display present working directory"
  echo "b) Display users of the system"
  echo "c) Display calendar of the year"
  echo "d) Exit"
read -p "enter choice:" choice

case $choice in
a) echo "$(pwd)"
pwd;;
b)echo "$(who)"
who
whoami;;
c)read -p "enter year:" year
cal "$year"
cal 2024;;
d)exit 0;;
*)echo "invalid option"
esac
done
