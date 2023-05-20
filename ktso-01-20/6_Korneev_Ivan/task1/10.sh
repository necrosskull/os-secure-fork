#!/bin/bash
echo Enter any of seasons name 
read s
if [ $s = "winter" ] || [ $s = "summer" ] || [ $s = "autumn" ]
then
echo Correct!
elif [ $s = "spring" ]
then 
echo Correct \& my favourite one!
else 
echo Incorrect!
fi
