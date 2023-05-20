#!/bin/bash
echo Enter any of seasons name:
read man
if [ $man = "winter" ] || [ $man = "summer" ] || [ $man = "autumn" ] || [ $man = "spring" ]
then
echo Correct!
else
echo Incorrect!
fi

