!#/bin/bash
echo -n "Enter season of year: "
read s
if( [[ $s == winter ]] || [[ $s == spring ]] || [[ $s == autumn ]] || [[ $s == Summer ]]) then
echo "Correct season!"
else echo "Incorrect season:("
fi