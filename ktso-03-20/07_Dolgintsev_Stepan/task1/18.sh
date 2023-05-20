BASE_DIR=$(dirname "$0")
BASE_DIR="$PWD/$BASE_DIR"
if [  -f $BASE_DIR/$1 ]
then
    echo exists
else
    echo nofile
fi