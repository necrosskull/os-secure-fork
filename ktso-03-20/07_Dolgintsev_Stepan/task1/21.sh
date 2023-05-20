while read line;
do
echo "$line"
n=$((n+1))
done < "$1"