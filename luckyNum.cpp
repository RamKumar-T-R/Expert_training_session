#include <cmath>
#include <iostream>
#include <vector>

int main() {
  long long n, count = 0;
  printf("Enter the number: ");
  std::cin >> n;
  for (long long i = 2; i <= n; i++) { // from 2 to n   //i
    // Sieve of Erothness
    std::vector<long long> isPrimeFact(i + 1, 1);
    isPrimeFact[0] = 0;
    isPrimeFact[1] = 0;
    for (long long j = 2; j <= sqrt(i); j++) { // from 2 to sqrt(i)   //j
      if (isPrimeFact[j] == 1) {
        for (long long k = j; k <= i; k += j) {
          isPrimeFact[k] = 0;
        }
      }
      if (i % j == 0) {
        isPrimeFact[j] = 1;
      }
    }
    long long pfCount = 0;
    for (long long j = 0; j <= i; j++) {
      if (isPrimeFact[j] && i % j == 0) {
        pfCount++;
      }
    }
    if (pfCount == 2) {
      count++;
    }
  }
  printf("The number of lucky numbers between 1 and %d is %d", n, count);
}