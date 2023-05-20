#!/bin/bash

echo "введите любой сезон года"
read season
if [ $season == "summer" ] || [ $season == "autumn" ] || [ $season == "spring" ]; then
    echo "Correct!" 
elif [ $season == "winter" ]; then
    echo "Это мое любимое время года"
else 
    echo "Incorrect!"
fi
