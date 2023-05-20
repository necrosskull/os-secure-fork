#!/bin/bash
# echo 5
echo 4
((res=5+4))
echo $res


: '
echo 5
echo 9
.. 
'

