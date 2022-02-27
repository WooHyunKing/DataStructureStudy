#include <stdio.h>

int factorial(int n) {

	printf("factorial(%d)\n", n);
	if (n <= 1)return 1;
	else return n * factorial(n - 1);
}

int factorial_iter(int n) {

	int k,v=1;

	for (int k = n; k > 0; k--) {
		v = v * k;
	}

	return v;
}

int sub(int n) {

	if (n < 0)return 0;
	else return n + sub(n - 3);

	return 0;
}

int sub_iter(int n) {

	int sum = 0,i=n;

	while (i>0) {

		sum += i;
		i -= 3;

	}

	return sum;
	
}

double power(double x, int n) {

	if (n == 0)return 1;

	else if (n % 2 == 0) return power(x * x, n/2);

	else return x * power(x * x, (n - 1) / 2);
}

double power_iter(double x, int n) {
	
	double result = 1.0;

	for (int i = 0; i < n; i++) {
		result *= x;
	}
	
	return result;
}

int fib(int n) {

	if (n == 0) return 0;
	else if (n == 1) return 1;
	else return fib(n - 1) + fib(n - 2);

}

int fib_iter(int n) {

	if (n < 2) return n;

	else {

		int result, p1=1,p2=0;

		for (int i = 2; i <= n; i++) {

			result = p1 + p2;
			p2 = p1;
			p1 = result;
	
		}
		
		return result;

	}

}

void hanoi_tower(int n, char from, char tmp, char to) {

	if (n == 1) printf("원판 1을 %c에서 %c으로 옮긴다.\n", from, to);

	else {

		hanoi_tower(n - 1, from, to, tmp);
		printf("원판 %d을 %c에서 %c으로 옮긴다.\n", n, from, to);
		hanoi_tower(n - 1, tmp, from, to);
	}
	
}

int main() {
	/*
	int num = 10;

	int result = factorial(num);

	printf("%d\n", result);

	printf("\n");

	int result2 = sub_iter(num);

	printf("%d\n", result2);

	
	
	for (int i = 0; i < 10; i++) {

		printf("%d ", fib_iter(i));
	}

	*/

	hanoi_tower(5, 'A', 'B', 'C','D');

	return 0;
}