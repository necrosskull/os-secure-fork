#!/bin/bash
# 1 line comment
var=$((5+2))
echo $var
: '
variable line
comment
'
var=$((3*2))
echo $var
