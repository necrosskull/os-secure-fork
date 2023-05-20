#!/bin/bash

# Comment 
((res=2+3))
echo $res

: '
BLOCK
COMMENT
'

((res=5+4))
echo $res