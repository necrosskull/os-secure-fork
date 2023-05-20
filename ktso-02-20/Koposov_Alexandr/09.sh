#!/bin/bash

echo "Enter season name:"
read name
if [[ "$name" == "winter" ]]||[[ "$name" == "spring" ]]||[[ "$name" == "summer" ]]||[[ "$name" == "autumn" ]]
then
echo "correct"
else
echo "not correct"
fi
