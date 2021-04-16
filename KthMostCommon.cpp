/*
   Question: TestDome - Common

   Write a method that finds k-th most common element in a list.

   For example, kthMostCommon({ 5, 4, 3, 2, 1, 5, 4, 3, 2, 5, 4, 3, 5,
   4, 5 }, 2) should return 4. In the array, element 1 occurs once, 2
   twice, 3 three times, 4 four times, and 5 five times, making
   element 5 the most common element in the list and 4 the second most
   common element.
*/

#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>

class Common
{
public:

   static int kthMostCommon(const std::vector<int>& a, int k)
   {
        std::unordered_map<int,int> occurs;
        for(auto& i: a){
            occurs[i]++;
        }
        std::vector<std::pair<int,int>> vec(occurs.size());
        std::copy(occurs.begin(),occurs.end(),vec.begin()); 

        std::sort(vec.begin(), vec.end(),[](auto p,auto q){ return p.second > q.second;});

        return vec[k-1].first;
   }
};


#ifndef RunTests
int main(int argc, const char* argv[])
{
   std::vector<int> input;
   input.push_back(1);
   input.push_back(2);
   input.push_back(2);
   input.push_back(3);
   input.push_back(3);
   input.push_back(3);
   input.push_back(4);
   input.push_back(4);
   input.push_back(4);
   input.push_back(4);
   input.push_back(5);
   input.push_back(5);
   input.push_back(5);
   input.push_back(5);
   input.push_back(5);
   input.push_back(2);
   input.push_back(2);
   input.push_back(2);
   input.push_back(2);
   int x = Common::kthMostCommon(input, 2);
   std::cout << x;

   return 0;
}
#endif