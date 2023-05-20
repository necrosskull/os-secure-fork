#!/bin/bash

echo -n "Enter season: "
read season

case $season in
	"autumn") echo "Correct!";;
	"winter") echo "Correct!";;
	"spring") echo "Correct!";;
	"summer") echo "Correct & my favourite one!";;
	*) echo "Incorrect!";;
esac
