#include <iostream>
#include<cmath>

int main() {
  int n, count = 0;
  printf("Enter the value: ");
  std::cin>>n;
  for(int i=1; i<=sqrt(n); i++){
      if(sqrt(n) == i){
        count ++;
        printf("one\n");
      }
      else if(n%i == 0){
        count +=2;
        printf("two\n");
      }
  }
  printf("The number of divisors for %d is %d", n, count);
  return 0;
}