#!/bin/bash

echo "Enter login:"
read login
echo "Enter pass"
read pass
if [[ "$login" == "admin" ]]&&[[ "$pass" == "111" ]]
then
echo "success auth"
else
echo "failed auth"
fi
