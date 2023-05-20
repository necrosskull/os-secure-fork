#!/bin/bash
read val1
size=${#val1}
if [[ $size -gt 0 ]]
then
echo "input is: $val1"
else
echo "empty :("
fi
