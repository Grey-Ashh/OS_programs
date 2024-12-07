echo "enter number"
read num
a=0
b=1
c=0
i=2
echo -n "$a $b"
while [ $i -lt $num ]
do
    c=$(($a+$b))
    echo -n " $c"
    a=$b
    b=$c
    i=$(($i+1))
done