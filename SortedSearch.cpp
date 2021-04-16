#include <vector>
#include <stdexcept>
#include <iostream>

int countNumbers(const std::vector<int>& sortedVector, int lessThan)
{
    auto it = std::lower_bound(sortedVector.begin(), sortedVector.end(), lessThan);
    return std::distance(sortedVector.begin(),it);
    /**
    if(sortedVector.size()==1) return int(sortedVector[0]<lessThan);
    int mid=(sortedVector.size()/2);
    int v=sortedVector[mid];
    std::cout << "mid = " << mid << " v = " << v << std::endl;
    std::vector<int> leftvector(sortedVector.begin(),sortedVector.begin()+mid);
    if(v==lessThan) return mid;
    else if(v>lessThan) return countNumbers(leftvector,lessThan);
    std::vector<int> rightvector(sortedVector.begin()+mid,sortedVector.end());
    return mid + countNumbers(rightvector,lessThan);
    */
}

#ifndef RunTests
int main()
{
    std::vector<int> v { 1, 2, 3, 5, 6, 7 };
    std::cout << countNumbers(v, 4);
}
#endif
//100%