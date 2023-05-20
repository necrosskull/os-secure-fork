#!/bin/bash
echo -n "insert 1st number "
read first
echo -n "insert 2nd number "
read second

function sum() 
{
    echo $(($first+$second))
}

sum
