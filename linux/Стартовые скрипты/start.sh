(bin/oo4-tfss > logs/console.log 2>&1)&

#command > /dev/null 2>&1
echo $!> application.pid
