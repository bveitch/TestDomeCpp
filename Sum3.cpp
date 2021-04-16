/*
   Question: TestDome - Sum3

   Design a data structure that can EFFICIENTLY handle two types of
   requests: add a list of elements at the end of the internal list, and
   answer whether there is a sum of any three consecutive elements in the
   internal list equal to the given sum.

   For example, a Sum3() creates an empty internal list with no existing
   sum3s. addLast({1, 2, 3}) appends elements {1, 2, 3} resulting with
   internal list {1, 2, 3} and only one existing sum3 (1+2+3=6).
   addLast({4}) appends element 4 resulting with internal list {1, 2, 3,
   4} and two existing sum3s (1+2+3=6 and 2+3+4=9).
*/

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_set>

class Sum3
{
public:

   /**
   *   \brief Adds/appends list of integers at the end of internal list.
   *
   **/
   void addLast(const std::vector<int>& list)
   {
      std::copy (list.begin(),list.end(),back_inserter(v_));
   }

   /**
   *   \brief Returns boolean representing if any three consecutive integers in the internal list have given susum_map.
   *
   **/
   bool containsSum3(int sum)
   {
      std::sort(v_.begin(),v_.end());
      for(auto i=1;i<v_.size()-1;i++){
          if(v_[i-1]+v_[i]+v_[i+1]==sum) return true;
      }
      return false;
   }

private:

   std::vector<int> v_;
   //std::unordered_set<int> sum_map_;
};


#ifndef RunTests
int main(int argc, const char* argv[])
{
   Sum3 s;

   std::vector<int> first;
   first.push_back(1);
   first.push_back(2);
   first.push_back(3);

   s.addLast(first);

   std::cout << s.containsSum3(6) << '\n';
   std::cout << s.containsSum3(9) << '\n';

   std::vector<int> second;
   second.push_back(4);
   s.addLast(second);

   std::cout << s.containsSum3(9) << '\n';
}
#endif