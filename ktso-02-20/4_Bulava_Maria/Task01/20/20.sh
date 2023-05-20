#!/bin/bash

if [[ -d $1 ]]
then 
	echo "File exists!"
else
    echo "Файл $1 создан"
	mkdir $1
fi