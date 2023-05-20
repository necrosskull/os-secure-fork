#!/bin/bash
echo Enter any of seasons name
read s
if [ $s = "winter" ] || [ $s = "spring" ] || [ $s = "summer" ] || [ $s	= "autumn" ]
then
echo Correct!
else
echo Incorrect!
fi

