#!/bin/bash

#comment
var=$((2+2))
echo $var
: '
comment
comment
..
'
var=$((3+3))
echo $var
