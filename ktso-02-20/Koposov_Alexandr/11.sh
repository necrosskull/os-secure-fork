#!/bin/bash

echo "Enter season name:"
read name
case $name in
winter)
echo "correct & my favourite"
;;
spring)
echo "correct"
;;
summer)
echo "correct"
;;
autumn)
echo "correct"
;;
*)
echo "not correct"
;;
esac
