#!/bin/bash

read inp

size=${#inp}

if [ $size -gt 0 ]

then
	echo "Your input is: $inp"
else
	echo "Empty input!"
fi
