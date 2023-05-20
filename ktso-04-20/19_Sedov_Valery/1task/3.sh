#/bin/bash
# comment1
((res=1+1))
echo $res

: '
big comment 1
big comment 2
'

((res=2+2))
echo $res
