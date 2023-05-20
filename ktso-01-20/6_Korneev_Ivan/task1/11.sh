#!/bin/bash
echo "Enter any of seasons name:"
read s
case "$s" in
	"winter") echo "Correct!";;
	"spring") echo "Correct & my favourite!";;
	"summer") echo "Correct!";;
	"autumn") echo "Correct!";;
	*) echo "Incorrect!";;
esac
