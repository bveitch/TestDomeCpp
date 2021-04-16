#include <stdexcept>
#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>

std::pair<int, int> findTwoSum(const std::vector<int>& list, int sum)
{
    std::unordered_map<int,int> m;
    
    for(auto i=0; i< list.size(); i++){
        auto got = m.find (sum-list[i]);
        if(got!=m.end() && got->second!=i) return {std::move(i),std::move(got->second)}; 
        m[list[i]]=i;
    }
    return {-1,-1};
}

#ifndef RunTests
int main()
{
    std::vector<int> list = {3, 1, 5, 7, 5, 9};
    std::pair<int, int> indices = findTwoSum(list, 10);
    std::cout << indices.first << '\n' << indices.second;
}
#endif
//this =100%