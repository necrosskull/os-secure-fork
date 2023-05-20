#!/bin/bash

number=$RANDOM
let "number %= $1"
echo "Случайное число меньше $1:  $number"
