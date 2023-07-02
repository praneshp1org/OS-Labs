# sh 35.sh

echo "SIMULATING KILL COMMAND!"
ps
echo "Enter the pid: "
read pid
kill -9 $pid
echo "KILLED!"

