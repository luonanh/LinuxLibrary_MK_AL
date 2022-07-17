#!/bin/bash
sudo rm /usr/local/lib/libprimes.a
rm -rf libprimes.a
rm -rf primes.o
gcc -c primes.c
ar -cvq libprimes.a primes.o
sudo cp libprimes.a /usr/local/lib
rm -rf static.out
gcc -o static.out tester.c -lprimes -lm
