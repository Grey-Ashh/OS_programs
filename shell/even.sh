echo "Number"
read n
i=0
i=$(($n%2))
if [ $i -eq 0 ]
then
    echo "even"
else
    echo "odd"
fi