echo "Enter login"
read login
echo "Enter password"
read password
if [ $login = "Chro" ] && [ $password = "miest" ]
then
echo "success auth!"
else
echo "auth failed!"
fi