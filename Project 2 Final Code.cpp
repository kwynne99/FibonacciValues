//Name: Kyle Wynne
//ID: 6564
//MAC 281, Section 2996
//Project 2
//Program to discover exact Fibonacci Numbers iteratively and recursively with time elapsed. Also find prime numbers.
//Iterative Function for Fibonacci Number
#include <iostream>
#include <chrono>
#include <iomanip>
#include <boost/multiprecision/cpp_int.hpp> // Downloaded a big_int library from boost.org to find exact values for f100/f500/f1000
using big_int = boost::multiprecision::cpp_int;
using namespace std;
using ns = chrono::nanoseconds;
using get_time = chrono::steady_clock;

big_int iterativeF(int);
long long recursiveF(int);
bool isPrime(big_int);

int main()
{	
	big_int k;
	int count = 1;
	auto start = get_time::now();
	k = recursiveF(40); // Find the exact value for Fibonacci100
	auto end = get_time::now();
	auto diff = end - start;
	cout << "f40: " << k << endl;
	cout << "Time taken for recursive function: " << chrono::duration_cast<ns>(diff).count() << " ns " << endl;
	auto start = get_time::now();
	k = iterativeF(40); // Find the exact value for Fibonacci40 to compare with recursive method
	auto end = get_time::now();
	auto diff = end - start;
	cout << "f40: " << k << endl;
	cout << "Time taken for iterative function: " << chrono::duration_cast<ns>(diff).count() << " ns " << endl;
	auto start = get_time::now();
	k = iterativeF(100); // Find the exact value for Fibonacci100
	auto end = get_time::now();
	auto diff = end - start;
	cout << "f100: " << k << endl;
	cout << "Time taken: " << chrono::duration_cast<ns>(diff).count() << " ns " << endl;
	start = get_time::now();
	k = iterativeF(500); // Find the exact value for Fibonacci500
	end = get_time::now();
	diff = end - start;
	cout << "f500: " << k << endl;
	cout << "Time taken: " << chrono::duration_cast<ns>(diff).count() << " ns " << endl;
	start = get_time::now();
	k = iterativeF(1000); // Find the exact value for Fibonacci1000
	end = get_time::now();
	diff = end - start;
	cout << "f1000: " << k << endl;
	cout << "Time taken: " << chrono::duration_cast<ns>(diff).count() << " ns " << endl;

	// This loop is used to find the smallest Fibonacci number great than 1 million.
	for (int i = 3; i <= 1000000; i++) {
		if (iterativeF(i) >= 1000000) {
			cout << "Smallest Fibonacci number great than 1,000,000: " << iterativeF(i) << endl;
			break;
		}
	}

	// This loop is used to find the smallest Fibonacci number greater than 1 billion.
	for (int i = 3; i <= 1000000000; i++) {
		if (iterativeF(i) >= 1000000000) {
			cout << "Smallest Fibonacci number greater than 1,000,000,000: " << iterativeF(i) << endl;
			break;
		}
	}

	cout << "Prime Fibonacci numbers: " << endl;
	// This loop is used to find the prime fibonacci numbers
	for (int i = 1; count <= 20; i++) { // This loop can be adjusted to run until a certain number of prime numbers are found.
		if (isPrime(iterativeF(i))) {
			cout << count << ": " << iterativeF(i) << endl;
			count++;
		}
	}
	system("PAUSE");
}

big_int iterativeF(int n) {
	big_int f1 = 0, f2 = 1;
	long long i;
	for (i = 2; i < n; i++) {
		big_int temp = f2;
		f2 = f1 + f2;
		f1 = temp;
	}
	if (n == 0)
		return 0;
	else
		return (f1 + f2);
}

long long recursiveF(int n) {
	if (n == 0 || n == 1)
		return n;
	else {
		return recursiveF(n - 1) + recursiveF(n - 2);
	}
}

bool isPrime(big_int n) {
	for (big_int i = 2; i <= n / 2; ++i) {
		if (n % i == 0) {
			return false;
			break;
		}
	}
	return true;
}
