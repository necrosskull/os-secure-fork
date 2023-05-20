#!/bin/bash
function Sum()
{
expr $1 + $2
}
echo "enter first number"
read v1
echo "enter second number"
read v2
echo "sum is:"
Sum $v1 $v2
