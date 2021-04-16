/*
   Question: TestDome - ArrayMath

   The method must throw std::invalid_argument("Argument exception") for
   every illegal argument value or combination. The expected arguments
   are two arrays with the same length.

   For example, weightedMean called with values {3, 6} and weights {4, 2}
   should return the weighted mean (3 * 4 + 6 * 2) / (4 + 2) = 4. Fix the
   bugs.
*/

#include <stdexcept>
#include <iostream>
#include <vector>
#include <numeric> 

class ArrayMath
{
public:

   static double weightedMean(const std::vector<int>& values, const std::vector<int>& weights)
   {
       if(values.size()!=weights.size()) throw std::invalid_argument("Argument exception");
       auto weight=std::accumulate(weights.begin(),weights.end(),0);
       auto mean=std::inner_product(values.begin(),values.end(),weights.begin(),0);
       return static_cast<double>(mean)/weight;
   }
};


#ifndef RunTests
int main(int argc, const char* argv[])
{
   std::vector<int> a, b;
   a.push_back(3);
   a.push_back(6);
   b.push_back(4);
   b.push_back(2);
   std::cout << ArrayMath::weightedMean(a, b);
   return 0;
}
#endif