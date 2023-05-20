#!/bin/bash
echo "Enter seasons name"
read input
case "$input" in 
"winter") echo "Correct!" ;;
"summer") echo "Correct!" ;;
"spring") echo "Correct!" ;;
"fall") echo "Correct!" ;;
*) echo echo "Incorrect!" ;;
esac
