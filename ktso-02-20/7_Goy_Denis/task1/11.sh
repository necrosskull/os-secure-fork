#!/bin/bash
echo -n "Enter season:"
read s
case $s in
summer ) echo "Correct!";;
autumn ) echo "Correct! My fav season!";;
spring ) echo "Correct!";;
winter ) echo "Correct!";;
* ) echo "Incorrect";;
esac