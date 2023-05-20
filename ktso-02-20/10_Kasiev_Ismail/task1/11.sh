#!/bin/bash

echo "Enter any of seasons name"
read season

case $season in
	"autumn") echo "Correct & my favourite one!";;
	"spring") echo "Correct!";;
	"summer") echo "Correct!";;
	"winter") echo "Correct!";;
	*) echo "Incorrect!";;
esac
