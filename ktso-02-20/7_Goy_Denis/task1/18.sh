#!/bin/bash

if [[ -f $1 ]]
then 
	echo "File exists!"
else
	echo "No such file!"
fi