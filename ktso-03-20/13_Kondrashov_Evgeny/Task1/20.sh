#!/bin/bash
echo "Enter the name for the new directory: "
read dir
if  [ -e $dir ]
then
    echo "Directory with this name is already exists"
else
    mkdir $dir
    echo "Done"
fi

#rm -r $dir
