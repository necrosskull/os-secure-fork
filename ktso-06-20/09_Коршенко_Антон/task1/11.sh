#!/bin/bash
echo "Please Enter seasons name"
read season
case "$season" in
"winter") echo "Correct season!" ;;
"autumn") echo "Correct season!" ;;
"spring") echo "Correct season!" ;;
"summer") echo  "Correct season! It is my favourite!!";;
*) echo "It is not the season";;
esac
