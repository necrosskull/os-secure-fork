#!/bin/bash
echo "Enter season:"
read input

case "$input" in
	"winter") echo "Correct!";;
	"spring") echo "Correct!";;
	"summer") echo "Correct and my favourite!";;
	"autumn") echo "Correct!";;
	*) echo "Incorrect!";;
esac
