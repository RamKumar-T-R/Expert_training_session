#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> sieveOfEtrothness(std::vector<int> isPrime)
{
  isPrime[0] = 0;
  if(isPrime.size()>1){
    isPrime[1] = 0;
  }
  for(int i=2; i<=sqrt(isPrime.size()-1); i++){
    if(isPrime[i] == 1){
      for(int j=i+i; j<isPrime.size(); j+=i){
        isPrime[j] = 0;
      }
    }
  }
  return isPrime;
}

int findSumPair(std::vector<int> isPrime){
  for(int i=0; i<=isPrime.size()/2; i++){
    if(isPrime[i] && isPrime[isPrime.size()-1-i]){
      printf("%d  %d", i, isPrime.size()-1-i);
      return 0;
    }
  }
}
int main(void) {
  int n;
  printf("Enter the number: ");
  std::cin>>n;
  std::vector<int> isPrime(n+1, 1);
  isPrime = sieveOfEtrothness(isPrime);
  findSumPair(isPrime);
  return 0;
}

