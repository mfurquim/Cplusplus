#include <cstdio>
#include <cmath>
#include <map>

using namespace std;

void unique_prime_factorization(const int &, map<int,int> &);
void display(const int &, const map<int,int> &);
int sum_of_factors(const map<int,int> &);

int main()
{
	printf("What number factorial do you want to calculate?\nn = ");

	int n = 0;
	scanf("%d", &n);

	// Key is a prime number; Value is the exponent
	map<int,int> factors;

	// Calculating unique prime factorization of 2 up to n
	// This is the same as calculating unique prime factorization of n!
	for (int i = 2; i <= n; i++) {
		unique_prime_factorization(i, factors);
	}

	// n! = 2^a + 3^b + ... + p^k
	display(n, factors);

	// Sum of factors is calculate as giving on the issue #9
	// SUM = product of all (pow(ak,pk+1)-1)/(ak-1);
	int sum = 0;
	sum = sum_of_factors(factors);

	printf("Sum of factors of %d! = %d", n, sum);

	return 0;
}

void unique_prime_factorization(const int &i, map<int,int> &factors)
{
	int number = i;
	for (int j = 2; j <= number; j++) {

		double division = 0;
		double intpart = 0;
		double fractpart = 0;

		do {
			division = ((double) number) / ((double) j);
			fractpart = modf(division, &intpart);

			if (fractpart == 0) {
				factors[j]++;
				number /= j;
			}
		} while (fractpart == 0);
	}

	return;
}

void display(const int &n, const map<int,int> &m)
{
	printf("%d! = ", n);

	for (map<int,int>::const_iterator map_iterator = m.begin(); map_iterator != m.end(); ++map_iterator) {
		if (map_iterator == m.begin()) {
			printf("%d^%d", map_iterator->first, map_iterator->second);
		}
		else {
			printf(" + %d^%d", map_iterator->first, map_iterator->second);
		}
	}

	printf("\n");

	return;
}

int sum_of_factors(const map<int,int> &m)
{
	int sum = 1;

	for (map<int,int>::const_iterator map_iterator = m.begin(); map_iterator != m.end(); ++map_iterator) {
		int tmp_sum = 0;

		for (int j = 0; j <= map_iterator->second; j++) {
			tmp_sum += pow(map_iterator->first,j);
		}

		sum *= tmp_sum;
	}

	return sum;
}

