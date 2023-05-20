#!/bin/bash

echo -n "Enter a number: "
read ch

res=$(($ch % 2))

if [[ $res -eq 1 ]]; then
    echo "$ch is an Odd number"
else
    echo "$ch is an Even number"
fi
