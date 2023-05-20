#!/bin/bash
# echo c1
((res=5+4))
echo $res
: '
echo c21
echo c22
.. 
'
((res=5+9))
echo $res
