#!/bin/bash
echo "Enter seasons name"
read input
case "$input" in 
"winter") echo "Correct!" ;;
"summer") echo "Correct!" ;;
"fall") echo "Correct!" ;;
"spring") echo "Correct & my favorite one!" ;;
*) echo echo "Incorrect!" ;;
esac
