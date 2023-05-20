#!/bin/bash
echo "Enter seasons name"
read input
case "$input" in 
"winter") echo "Correct!" ;;
"summer") echo "Correct!" ;;
"autum") echo "Correct!" ;;
"spring") echo "Correct & my favorite one!" ;;
*) echo echo "Incorrect!" ;;
esac
