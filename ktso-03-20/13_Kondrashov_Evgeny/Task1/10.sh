#!/bin/bash

echo -n "Enter season of year: "
read season

if [[ $season == "winter" ]] || [[ $season == "spring" ]] || [[ $season == "autumn" ]]
then
    echo "Correct!"
elif [[ $season == "summer" ]]
then
    echo "I like it!"
else
    echo "Incorrect!"
fi
