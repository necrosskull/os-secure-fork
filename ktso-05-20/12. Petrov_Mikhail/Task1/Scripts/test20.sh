#!/bin/bash
echo -n "Enter directory name: "
read dir
if [[ -d $dir ]]
then
echo "Directory already exists!"
ls -l
else
mkdir $dir
echo "Directory created!"
fi