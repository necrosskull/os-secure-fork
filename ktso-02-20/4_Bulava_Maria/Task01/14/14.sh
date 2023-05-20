#!/bin/bash

sum ()
{
    echo $(($1+$2))
}
echo -n 'enter first number ' 
read number1
echo -n 'enter second number '
read number2
sum number1 number2
