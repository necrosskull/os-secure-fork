function sum() {
    expr $1 + $2
}

echo Enter First Number:
read var1
echo Enter Second Number:
read var2

sum $var1 $var2