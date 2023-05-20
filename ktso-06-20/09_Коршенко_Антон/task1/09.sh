#!/bin/bash
echo "Please Enter seasons name"
read season
if [ $season = "winter" ] || [ $season = "autumn" ] || [ $season = "summer" ] || [ $season = "spring" ]
then
echo "Correct season!"
else 
echo "It is not the season"
fi

