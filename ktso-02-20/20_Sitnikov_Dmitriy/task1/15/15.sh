#!/bin/bash
echo "enter a number"
read ch
res=$(($ch % 2))
if [[ $res -eq 1 ]]
then
echo "odd number"
else
echo "even number"
fi
