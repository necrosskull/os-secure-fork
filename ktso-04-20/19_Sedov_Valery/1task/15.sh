echo -n "Enter number: "
read n

if [[ $(( n % 2)) -eq 0 ]]
then 
    echo "It is a Even number"
else 
    echo "It is a Odd number"
fi
