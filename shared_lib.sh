#!/bin/bash
sudo rm /usr/local/lib/libshprimes.so.1
sudo rm /usr/local/lib/libshprimes.so
rm -rf libshprimes.so.1
rm -rf primes.o
gcc primes.c -c -fpic
gcc -shared -Wl,-soname,libshprimes.so -o libshprimes.so.1 primes.o
sudo cp libshprimes.so.1 /usr/local/lib
working_dir=$(pwd)
cd /usr/local/lib/
sudo ln --symbolic libshprimes.so.1 libshprimes.so
cd $working_dir
sudo ldconfig
gcc -o shared.out tester.c -lshprimes -lm
