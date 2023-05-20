#!/bin/bash
echo "Please Enter seasons name"
read season
if [ $season = "winter" ] || [ $season = "autumn" ] || [ $season = "spring" ]
then
echo "Correct season!"
elif [ $season = "summer" ]
then
echo  "Correct season! It is my favourite!!"
else 
echo "It is not the season"
fi
