#!/bin/bash

echo "Enter season name:"
read name
if [[ "$name" == "winter" ]]||[[ "$name" == "spring" ]]||[[ "$name" == "summer" ]]
then
if [[ "$name" == "winter" ]]
then
echo "correct & my favourite one"
else
echo "correct"
fi
else
echo "not correct"
fi

