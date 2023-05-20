#!/bin/bash
f=2
for((i = 1; i<11; i++))
do
    (( res=$f \* $i  ))
    echo $f \* $i = $res 
          
done
