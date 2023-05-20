#!/bin/bash

echo -n "Enter season name: "
read season

if [[ $season = "winter" ]] || [[ $season = "spring" ]] || [[ $season = "summer" ]] || [[ $season = "autumn" ]]
then
	echo "Correct!"
else 
	echo "Incorrect!"
fi