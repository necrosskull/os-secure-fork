#!/bin/bash

echo -n "Enter season: "
read season

if [ $season = "summer" ] || [ $season = "winter" ] || [ $season = "autumn" ]
then
echo "Season is correct!"
elif [ $season = "spring" ]
then
echo "Season is correct too!"
else
echo "Incorrect season!"
fi
