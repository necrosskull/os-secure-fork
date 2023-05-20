#!/bin/bash

e=0

while [ $e -le 9 ]

do
	echo $(($e + 1))
	e=$(($e+1))
done