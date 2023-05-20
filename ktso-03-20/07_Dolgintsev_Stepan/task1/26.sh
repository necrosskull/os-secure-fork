sleep 2 &
PID=$!
sleep 3 &

wait $PID
echo "First RIP"
wait $!
echo "Second RIP"