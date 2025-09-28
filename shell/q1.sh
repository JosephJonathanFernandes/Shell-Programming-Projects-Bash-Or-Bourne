echo "enter nos:"
read -a arr


for num in "${arr[@]}"; do
echo "$num"
done

sorted_asc=$(echo "${arr[@]}"|tr ' ' '\n'|sort -n| tr '\n' ' ')
sorted_desc=$(echo "${arr[@]}"|tr ' ' '\n'|sort -nr| tr '\n' ' ')
echo "$sorted_asc"
echo "$sorted_desc"
n=${#arr[@]}

for((i=0;i<n-1;i++)); do
for((j=0;j<n-i-1;j++)); do
if (( arr[j] > arr[j+1] )); then
temp=${arr[j]}
arr[j]=${arr[j+1]}
arr[j+1]=$temp
fi
done
done

echo "${arr[@]}"
echo "${arr[n-1]}"
max=${arr[0]}

for num in "${arr[@]}"; do
if [ $max -lt $num ]; then
max=$num
fi
done
echo "$max"
