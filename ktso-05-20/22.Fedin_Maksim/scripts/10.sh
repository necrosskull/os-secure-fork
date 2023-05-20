#!/bin/bash
echo "Enter seasons name"
read input
	if [ $input = "winter" ] || [ $input = "summer" ] || [ $input = "spring" ]|| [ $input = "autumn" ]
then
	if [ $input = "summer" ]
then
	echo "Correct & my favorite one!"
else
	echo "Correct!"
    fi
else
	echo "Incorrect!"
fi
