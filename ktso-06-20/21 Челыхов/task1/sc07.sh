#!/bin/bash
read answer
if [ -z  "$answer" ]
then
echo "Empty input!"
else
echo "Input: $answer"
fi
