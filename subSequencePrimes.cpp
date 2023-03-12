#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> flags(100007, 1);
std::vector<std::vector<int>> subSequences;
void findSS(std::vector<int> res, std::vector<int> nums, int k){
  if(k>=nums.size()){
    subSequences.push_back(res);
  }
  else{
    res.push_back(nums[k]);
    findSS(res, nums, k+1);
    res.pop_back();
    findSS(res, nums, k+1);
  }
}
int main() {
  int n;
  std::cin>>n;
  flags[0] = 0;
  flags[1] = 0;
  for(int i=2; i<=sqrt(10007); i++){
    if(flags[i] == 1){
      for(int j=i; j<=100007; j+=i){
        flags[j] = 0;
      }
      flags[i] = 1;
    }
  }
  std::vector<int> nums(n, 0);
  std::vector<int> res;
  for(int i=0; i<n;i++){
    std::cin>>nums[i];
  }
  findSS(res, nums, 0);
  int count=0;
  for(int i=0; i<subSequences.size(); i++){
    int f = 1;
    for(int j=0; j<subSequences[i].size(); j++){
      if(flags[subSequences[i][j]] == 0){
        f = 0;
        break;
      }
    }
    if(f && subSequences[i].size() != 0){
      count++;
    }
  }
  
  printf("%d ", count);
}