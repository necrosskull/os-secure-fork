#!/bin/bash

echo "Enter directory name "

read name

if [ -d "$name" ]
then 
echo "Directory exists"
else
mkdir $name
echo "Directory created"
fi
