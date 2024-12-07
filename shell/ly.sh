echo "enter yr"
read y
i=$(($y%4))
if [ $i -eq 0 ]
then
    echo "ly"
else 
    echo "non ly"
fi