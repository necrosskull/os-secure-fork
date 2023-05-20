#!/bin/bash
echo "Enter seasons name"
read input
if [ $input = "winter" ] || [ $input = "fall" ] || [ $input = "summer" ] || [ $input = "summer" ]
then
echo "Correct!"
else
echo "Incorrect!"
fi
