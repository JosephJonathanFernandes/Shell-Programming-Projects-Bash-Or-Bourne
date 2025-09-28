 read -p "Enter a number: " num
    digits=($(echo "$num" | grep -o . | sort -n | uniq))
    if (( ${#digits[@]} >= 2 )); then
        second_smallest=${digits[1]}
        second_largest=${digits[-2]}
        sum=$((second_smallest + second_largest))
        echo "2nd smallest digit: $second_smallest"
        echo "2nd largest digit: $second_largest"
        echo "Sum of 2nd smallest and 2nd largest: $sum"
    else
        echo "Number has less than 2 unique digits."
    fi
