// https://opensource.com/article/21/2/linux-software-libraries
// https://unix.stackexchange.com/questions/67781/use-shared-libraries-in-usr-local-lib

#include <stdio.h>
#include <primes.h>

int main() {
	/* is_prime */
	printf("\nis_prime\n");
	unsigned i, count = 0, n = 1000;
	for (i = 1; i <= n; i++) {
		if (is_prime(i)) {
			count++;
			if (1 == (i % 100)) printf("Sample prime ending in 1: %i\n", i);
		}
	}
	printf("%i primes in range of 1 to a thousand.\n", count);

	/* prime_factors
	 * */
	printf("\nprime_factors\n");
	printf("prime factors of 12: ");
	prime_factors(12);
	printf("\n");

	printf("prime factors of 13: ");
	prime_factors(13);
	printf("\n");

	printf("prime factors of 876,512,779: ");
	prime_factors(876512779);
	printf("\n");

	/* are_coprimes
	 * */
	printf("\nare_coprime\n");
	printf("Are %i and %i coprime? %s\n",
			21, 22, are_coprimes(21, 22) ? "yes" : "no");
	printf("Are %i and %i coprime? %s\n",
			21, 24, are_coprimes(21, 24) ? "yes" : "no");

	/* goldbach
	 * */
	printf("\ngoldbach\n");
	goldbach(11);    /* error */
	goldbach(4);     /* small one */
	goldbach(6);     /* another */
	for (i = 100; i <= 150; i += 2) goldbach(i);

	return 0;
}
