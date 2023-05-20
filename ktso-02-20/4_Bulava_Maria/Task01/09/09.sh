#!/bin/bash

echo "введите любой сезон года"
read season
if [ $season == "winter" ]  ||  [ $season == "summer" ]|| [ $season == "autumn" ]|| [ $season == "spring" ]; then
    echo "Correct!" 
else 
    echo "Incorrect!"
fi
