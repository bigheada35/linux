vim a-server.c
gcc -o a-server a-server.c
./a-server &

vim b-client.c
gcc -o b-client b-client.c
./b-client
