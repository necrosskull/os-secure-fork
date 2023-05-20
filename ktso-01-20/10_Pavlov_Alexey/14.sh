#!/bin/bash

function Sum()
{
    expr $1 + $2
}
echo -n "Enter first number: "
read number_1
echo -n "Enter second number: "
read number_2
echo -n "Sum is: "
Sum $number_1 $number_2