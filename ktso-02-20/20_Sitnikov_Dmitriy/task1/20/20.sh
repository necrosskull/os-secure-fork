#!/bin/bash
echo "enter directory name"
read v1
if [[ -d $v1 ]]
then
echo "this directory exists"
else 
mkdir $v1
echo "this directory is created"
fi
