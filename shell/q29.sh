read -p "Enter a number: " num
    fact=1
for((i=1;i<=num;i++)); do
fact=$((fact*i))
done
    echo "Factorial of $num is: $fact"
#iterative approach


# Function to calculate factorial using recursion
factorial() {
    local n=$1
    if (( n == 0 || n == 1 )); then
        echo 1
    else
        echo $(( n * $(factorial $((n - 1))) ))
    fi
}

# Prompt the user for input
read -p "Enter a number to calculate its factorial: " num

# Validate input
if (( num < 0 )); then
    echo "Factorial is not defined for negative numbers."
else
    result=$(factorial $num)
    echo "The factorial of $num is $result"
fi
