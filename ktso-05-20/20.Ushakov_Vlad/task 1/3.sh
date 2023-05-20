#!/bin/bash
# 1 line comment
var=$((2+8))
echo $var
: '
variable line
comment
'
var=$((9*3))
echo $var
