#!/bin/bash

echo -n "Enter any of seasons name: "
read season


if [[ $season = "winter" ]] || [[ $season = "spring" ]] || [[ $season = "summer" ]] || [[ $season = "autumn" ]]
then
	echo "Correct!"
else 
	echo "Incorrect!"
fi