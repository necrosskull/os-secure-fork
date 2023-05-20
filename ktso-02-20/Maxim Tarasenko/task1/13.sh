#!/bin/bash
for (( i = 1; i <= 10; i++ ))
do 
res=$(( 2 * $i ))
echo "2 x $i = $res"
res=0
done
