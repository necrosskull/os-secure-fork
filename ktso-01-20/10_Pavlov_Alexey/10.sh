#!/bin/bash

echo -n "Enter season name: "
read season

if [[ $season = "spring" ]] || [[ $season = "summer" ]] || [[ $season = "autumn" ]]; then
    echo "Correct"
elif [[ $season = "winter" ]]; then
    echo "Correct & my favourite one!"
else 
    echo "Incorrect!"
fi