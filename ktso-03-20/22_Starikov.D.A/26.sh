sleep 10 &
PID=$!
sleep 1 &
PID1=$!

wait $PID
echo "1 done"
wait $PID1
echo "2 done"
