#!/bin/bash

function Sum {
echo -n "Enter first number: "
read first
echo -n "Enter second number: "
read second
echo "Sum is $[ $first + $second ]"
}

Sum
