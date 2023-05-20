#!/bin/bash

read val
size=${#val}
if [ $size -gt 0 ]
then 
	echo "Input is: $val"
else
	echo "Empty input!"
fi

