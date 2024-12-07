echo "enter input no"
read n
i=0
max=0
while [ $i -lt $n ]
do
    echo "enter no"
    read num
    if [ $num -gt $max ]
    then
        max=$num
    fi
    i=$(($i+1))
done
echo $max