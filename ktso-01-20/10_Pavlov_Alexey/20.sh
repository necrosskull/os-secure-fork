#!/bin/bash

echo -n "Enter directory name: "
read dir

if [ -e $dir ]; then
	echo "Directory alredy exists"
else
    mkdir $dir
	echo "Directory created"
fi
