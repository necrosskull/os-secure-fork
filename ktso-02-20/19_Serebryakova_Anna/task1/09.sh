#!/bin/bash

echo -n "Enter season: "
read season


if [[ $season = "winter" ]] || [[ $season = "spring" ]] || [[ $season = "summer" ]] || [[ $season = "autumn" ]]
then
	echo "Correct!"
else
	echo "Incorrect!"
fi

