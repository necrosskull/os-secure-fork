BASE_DIR=$(dirname "$0")
BASE_DIR="$PWD/$BASE_DIR"
echo Enter directory name
read var1
if [ -e $BASE_DIR/$var1 ]
then
    echo "path exitsts"
else
    mkdir "$var1"
    echo "directory created"
fi