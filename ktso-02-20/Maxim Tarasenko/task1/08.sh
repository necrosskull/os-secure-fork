#!/bin/bash

echo "Enter login:"
read login
echo "Enter pass"
read pass
log="admin"
pswd="123"
if [[ "$login" == "$log" ]]&&[[ "$pass" == "$pswd" ]]
then
echo "success"
else
echo "failed"
fi
