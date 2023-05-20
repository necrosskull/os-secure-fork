#!/bin/bash
read number
if [ $(($number%2)) -eq 1 ]
then
echo "Odd"
else echo "Even"
fi