#!/bin/bash

read input
size=${#input}
if [[ $size -gt 0 ]]
then
	echo "input: $input"
else
	echo "Empty input"
fi
