#!/bin/bash

echo -n "Enter The Number: "
read n

if [ $(($n % 2)) -eq 0 ]
then 
	echo "It is a Even Number"
else
	echo "It is a Odd Number"
fi
