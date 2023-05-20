#!/bin/bash
echo "Enter seasons name"
read input
case "$input" in 
"winter") echo "Correct!" ;;
"summer") echo "Correct & my favorite one!" ;;
"spring") echo "Correct!" ;;
"autumn") echo "Correct!" ;;
*) echo "Incorrect!" ;;
esac
