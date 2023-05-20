#!/bin/bash
i=0
if [[ -n $1 ]]
then
((i++))
fi
if [[ -n $2 ]]
then 
((i++))
fi
echo "$1 $2"
echo "total arguments: $i"
