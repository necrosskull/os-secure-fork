#!/bin/bash
count=0
if [[ -n $1 ]]
then
(( count++ ))
fi
if [[ -n $2 ]]
then
(( count++ ))
fi
echo "$1 $2"
echo "Total arguments : $count"
