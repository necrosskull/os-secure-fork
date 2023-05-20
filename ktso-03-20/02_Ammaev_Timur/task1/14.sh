summ()
{
	res=$(($1 + $2))
	echo $res
}

echo -n "Enter first number: "
read var1
echo -n "Enter second number: "
read var2

summ var1 var2
