#!/bin/bash
  
winter="winter"
spring="spring"
summer="summer"
autumn="autumn"

echo "Enter any of seasons name"
read season

if [ $season = $winter ] || [ $season = $spring ] || [ $season = $summer ]
then
        echo "Correct!"
elif [ $season = $autumn ]
then
	echo "Correct & my favourite one!"
else
        echo "Incorrect!"
fi

