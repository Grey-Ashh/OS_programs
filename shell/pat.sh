echo "enter num"
read n
for((i=0;i<n;i++))
do
    for((j=0;j<n-i-1;j++))
    {
        echo -n "$j "
    }
    echo ""
done