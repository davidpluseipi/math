#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n = 0;
	int i = 2;
	bool is_prime = true;

	cout << "Enter a number and press ENTER: ";
	cin >> n;
	double sqrtn = sqrt(n);

	while (i <= sqrtn) {
		if (n%i == 0) {
			is_prime = false;
			break;
		}
		++i;
	}

	if (is_prime) {
		cout << n << " is prime." << endl;
	}
	else {
		cout << n << " is not prime." << endl;
	}
	return 0;
}