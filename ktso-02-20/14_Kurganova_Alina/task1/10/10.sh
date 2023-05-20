#!/bin/bash

echo -n "Enter season: "
read season

if [ $season = "autumn" ] || [ $season = "winter" ] || [ $season = "spring" ]
then
	echo "Season is correct!"
elif [ $season = "summer" ]
then
	echo "Correct & my favourite one!"
else
	echo "Incorrect season!"
fi
