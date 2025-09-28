#!/bin/bash

# Rectangle
read -p "Enter the length of the rectangle: " length
read -p "Enter the breadth of the rectangle: " breadth
rect_area=$((length * breadth))
echo "Area of the rectangle: $rect_area"

# Square
read -p "Enter the side of the square: " side
square_area=$((side * side))
echo "Area of the square: $square_area"

# Circle
read -p "Enter the radius of the circle: " radius
circle_area=$(echo "scale=2;3.14*$radius*$radius"|bc -l)
echo "Area of the circle: $circle_area"
