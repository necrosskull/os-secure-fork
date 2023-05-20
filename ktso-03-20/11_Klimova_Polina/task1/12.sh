#!/bin/bash

cntr=0

if [[ -n $1 ]]
then
    ((cntr++))
fi

if [[ -n $2 ]]
then
    ((cntr++))
fi

echo "$1 $2"
echo "Total arguments : $cntr"
