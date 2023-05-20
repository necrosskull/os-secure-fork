#!/bin/bash
echo -n "Enter the number: "
read number
if [ $((number%2)) -eq 0 ]
then 
echo "It is a even number."
else
  echo "It is a odd number."
fi
