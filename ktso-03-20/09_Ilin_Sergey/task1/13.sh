var=2
for((i = 1; i<10; i++))
do
    (( res=$var \* $i  ))
    echo $var \* $i = $res 
          
done
