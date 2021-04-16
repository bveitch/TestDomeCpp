#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

//Numer of Cuts. Find minimum number of cuts (ahem partitions) between two random sets of ints so that all subsets are the same:
//Eg (1,2,3,4) and (1,3,4,2) = 3 cuts
// Cut 1:(1)(2,3,4) and (1)(3,4,2) 
// Cut  2: (1)(2)(3,4) and (1)(3,4)(2) 


using std::vector;

namespace CuttingTape {

    template <class InputIterator1, class InputIterator2>  
    int count_cuts(InputIterator1 found1, InputIterator1 first1, std::pair<InputIterator1, InputIterator2> mispair,
                   InputIterator1 last1, InputIterator2 last2){
                    auto mincuts=0;
                    if(found1!=first1){
                        mincuts+=1;
                        if(mispair.first!=last1) mincuts+=1;
                        if(mispair.second!=last2) mincuts+=1; 
                    }
                    else mincuts=1; 
                    return mincuts;
    };

    int min_cuts(vector<int> given, vector<int> desired){
        if(std::equal(given.begin(),given.end(),desired.begin())) return 0;
        auto des_it = std::find (desired.begin(), desired.end(), *given.begin());
        auto mispair=mismatch(des_it,desired.end(),given.begin());
        auto ncuts=count_cuts(des_it,desired.begin(),mispair, desired.end(),given.end());
        desired.erase(des_it,mispair.first);
        given.erase(given.begin(),mispair.second); 
        return ncuts+min_cuts(desired,given);
    }

}

#ifndef RunTests
int main(int argc, const char* argv[])
{
    vector<int> desired={1,2,3,4};
    vector<int> given={1,3,4,2};
    std::cerr << CuttingTape::min_cuts(given,desired) << std::endl;
    vector<int> desired2={1,2,3,4,5,6,7};
    vector<int> given2={5,6,7,1,3,4,2};
    std::cerr << CuttingTape::min_cuts(given2,desired2) << std::endl;;
}
#endif