#!/bin/bash

echo -n "Enter season: "
read season
case $season in
"autumn") echo "autumn exists";;
"spring") echo "spring exists";;
"summer") echo "summer exists";;
"winter") echo "winter exists";;
"4") echo "Incorrect season";;
esac