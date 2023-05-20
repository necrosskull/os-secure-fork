#!/bin/bash

echo -n "Enter season: "
read season

case $season in
"autumn") echo "autumn exists";;
"spring") echo "spring exists";;
"summer") echo "summer exists";;
"winter") echo "winter exists";;
*) echo "Incorrect season!";;
esac
