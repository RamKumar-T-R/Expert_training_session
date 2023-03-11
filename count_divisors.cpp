#include <iostream>
#include<cmath>
#include<vector>

std::vector<int> countDivisors(std::vector<int> nums){
  std::vector<int> res(nums.size(), 0);
  for(int i=0; i<nums.size(); i++){
    int count = 0;
    for(int i=1; i<=sqrt(nums[i]); i++){
      if(sqrt(nums[i]) == i){
        count ++;
        printf("one\n");
      }
      else if(nums[i]%i == 0){
        count +=2;
        printf("two\n");
      }
    }
    res[i] = count;
  }
  return res;
}