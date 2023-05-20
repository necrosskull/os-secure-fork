#!/bin/bash
echo "Enter seasons name"
read input
if [ $input = "winter" ] || [ $input = "fall" ] || [ $input = "spring" ] || [ $input = "summer" ]
then
echo "Correct!"
else
echo "Incorrect!"
fi
