#!/bin/bash
echo "Enter seasons name"
read input
if [ $input = "winter" ] || [ $input = "autumn" ] || [ $inpit = "spring" ] || [ $input = "summer" ]
then
	echo "Correct!"
else
	echo "Incorrect!"
fi

