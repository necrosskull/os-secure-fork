#!/bin/bash
function Odd()
{
    ((res = $1 % 2 ))
    if [ $res == 1 ]
    then
    echo "It's an odd number"
    else 
    echo "It's an even number"
    fi
}

echo -n "Entere The Number: "
read n1
Odd n1
