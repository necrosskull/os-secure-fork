function mod()
{
    ((res = $1 % 2 ))
    if [ $res == 1 ]
    then
    echo "it's odd number"
    else 
    echo "it's even number"
    fi
}

echo Entere The Number:
read var1
mod var1