#!/bin/bash

echo -n "Enter season: "
read season

if [ $season = "autumn" ] || [ $season = "spring" ] || [ $season = "summer" ] || [ $season = "winter" ]
then
	echo "Season is correct!"
else
	echo "Incorrect season!"
fi
