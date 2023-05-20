#!/bin/bash

function Sum()
{
echo $(( $1 + $2 ))
}
echo "Enter first num:"
read var1
echo "Second num:"
read var2
Sum var1 var2
