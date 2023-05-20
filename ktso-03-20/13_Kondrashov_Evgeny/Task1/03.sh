#!/bin/bash
#comment
((var=1+2))
echo $var
: '
multi
line
comment
'
((res=4+5))
echo $res
