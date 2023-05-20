#!/bin/bash

((res1=2+3))
echo $res1
: '
mnogostrochniy
komment
..
'
((res2=4+5))
echo $res2
