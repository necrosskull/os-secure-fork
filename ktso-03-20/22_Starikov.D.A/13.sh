for ((i=0; i<11; i++))
do
j=i
let "j *=2" 
echo "$i x 2 = $j"
done 
echo