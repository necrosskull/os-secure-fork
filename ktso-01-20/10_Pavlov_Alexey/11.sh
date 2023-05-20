#!/bin/bash

echo -n "Enter season: "
read season

case $season in
	"summer" | "spring" | "autumn")
		echo "Correct!";;
	"winter")
		echo "Correct & my favourite one";;
	*)
		echo "Incorrect!";;
esac