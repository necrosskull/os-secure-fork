#!/bin/bash

echo -n "Enter any of seasons name: "
read season


if [[ $season = "winter" ]] || [[ $season = "spring" ]] || [[ $season = "summer" ]] || [[ $season = "autumn" ]]
then
	if [[ $season = "winter" ]]
	then
		echo "Correct & my favourite one!"
		else 
		echo "Correct!"
	fi
else 
	echo "Incorrect!"
fi