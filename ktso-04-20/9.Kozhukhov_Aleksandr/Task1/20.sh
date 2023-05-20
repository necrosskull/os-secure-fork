echo -n "Enter directory name: " 
read dir

if [ -e $dir ]
then
	echo "Directory alredy exists"
else
	echo "Directory created"
fi