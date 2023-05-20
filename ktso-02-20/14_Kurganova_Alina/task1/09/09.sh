#!/bin/bash

echo -n "Enter season: "
read season

if [ $season = "summer" ] || [ $season = "autumn" ] || [ $season = "winter" ] || [ $season = "spring" ]
then
	echo "Season is correct!"
else
	echo "Incorrect season!"
fi


