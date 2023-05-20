#!/bin/bash

for ((i=10;i>=1;i--))
do
	if [ $i -ne 1 ]
	then
		echo -n "$i "
	else
		echo "$i"
	fi
done

