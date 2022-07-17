#include <stdio.h>
#include <math.h>

extern unsigned is_prime(unsigned n) {
	if (n <= 3) return n > 1;                   /* 2 and 3 are prime */
	if (0 == (n % 2) || 0 == (n % 3)) return 0; /* multiples of 2 or 3 aren't */

	/* check that n is not a multiple of other
	 * values < n */
	unsigned i;
	for (i = 5; (i * i) <= n; i += 6)
		if (0 == (n % i) || 0 == (n % (i + 2))) return 0; /* not prime */

	return 1; /* a prime other than 2 or 3 */
}

extern void prime_factors(unsigned n) {
	/* list 2s in n's prime factorization */
	while (0 == (n % 2)) {  
		printf("%i ", 2);
		n /= 2;
	}

	/* 2s are done, the divisor is now odd */
	unsigned i;
	for (i = 3; i <= sqrt(n); i += 2) {
		while (0 == (n % i)) {
			printf("%i ", i);
			n /= i;
		}
	}

	/* one
	 * more
	 * prime
	 * factor?
	 * */
	if (n > 2) printf("%i", n);
}

/* utility function: greatest common divisor */
static unsigned gcd(unsigned n1, unsigned n2) {
	while (n1 != 0) {
		unsigned n3 = n1;
		n1 = n2 % n1;
		n2 = n3;
	}
	return n2;
}

extern unsigned are_coprimes(unsigned n1, unsigned n2) {
	return 1 == gcd(n1, n2);
}

extern void goldbach(unsigned n) {
	/* input errors */
	if ((n <= 2) || ((n & 0x01) > 0)) {
		printf("Number must be > 2 and even: %i is not.\n", n);
		return;
	}

	/* two simple cases: 4 and 6 */
	if ((4 == n) || (6 == n)) {
		printf("%i = %i + %i\n", n, n / 2, n / 2);
		return;
	}

	/* for n >= 8:
	 * multiple
	 * possibilities for
	 * many */
	unsigned i;
	for (i = 3; i < (n / 2); i++) {
		if (is_prime(i) && is_prime(n - i)) {
			printf("%i = %i + %i\n", n, i, n - i);
			/* if
			 * one
			 * pair
			 * is
			 * enough,
			 * replace
			 * this
			 * with
			 * break
			 * */
		}
	}
}
