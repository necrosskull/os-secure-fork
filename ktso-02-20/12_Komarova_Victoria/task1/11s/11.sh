#!/bin/bash
echo "enter any season"
read s
case "$s" in
"spring") echo "correct";;
"summer") echo "correct and my favourite";;
"autumn") echo "correct";;
"winter") echo "correct";;
*) echo "incorrect";;
esac
