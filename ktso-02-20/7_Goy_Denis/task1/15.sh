#!/bin/bash
read number
if [ $(($number % 2)) -eq 1 ]
then 
	echo "$number is odd number"
else
	echo "$number is even number"
fi