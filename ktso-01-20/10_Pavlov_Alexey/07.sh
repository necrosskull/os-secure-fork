#!/bin/bash

read input

size=${#input}
if [ $size -gt 0 ]
then
	echo "Input is: $input"
else
	echo "Empty input!"
fi
