#!/bin/bash
	
echo -n "Enter the number: "
read first
if [ $((first%2)) -eq 0 ]
then
echo "It is a even number."
else
echo "It is a odd number."
fi
