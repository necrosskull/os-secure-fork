#!/bin/bash

if [[ -f $1 ]]; then
    echo "File $1 exists"
else
    echo "no file"
fi
