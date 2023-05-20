#!/bin/bash
echo "Enter seasons name"
read input
if [ $input = "winter" ] || [ $input = "summer" ] || [ $input = "spring" ]|| [ $input = "fall" ]
then
    if [ $input = "winter" ]
    then
    echo "Correct but i hate winter"
    else
    echo "Correct!"
    fi
else
echo "Incorrect!"
fi
