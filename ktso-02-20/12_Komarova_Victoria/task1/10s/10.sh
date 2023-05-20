#!/bin/bash
echo "enter any season"
read s
s1="spring"
s2="summer"
s3="autumn"
s4="winter"
if [[ $s = $s1 ]] || [[ $s = $s3 ]] || [[ $s = $s4 ]]
then
echo "correct"
elif [[ $s = $s2 ]] 
then
echo "correct and my favourite"
else
echo "incorrect"
fi 
