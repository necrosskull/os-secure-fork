#!/bin/bash
echo "Enter seasons name"
read input
if [ $input = "winter" ] || [ $input = "spring" ] || [ $input = "summer" ] || [ $input = "winter" ]
then
	echo "Correct!"
else
	echo "Incorrect!"
fi
