#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
#include <algorithm>

//calculate all anagrams of a word

class AllAnagrams
{
public:
   static std::vector<std::string> getAllAnagrams(std::string str)
   {
       std::sort(str.begin(),str.end());
        //vector should be sorted at the beginning.
        std::unordered_set<std::string> set;
        do {
            set.emplace(str);
        } while (std::next_permutation(str.begin(), str.end()));

        return std::vector<std::string>(set.begin(),set.end());
   }
};

#ifndef RunTests
int main(int argc, const char* argv[])
{
    std::vector<std::string> anagrams = AllAnagrams::getAllAnagrams("abbaba");

    for (std::vector<std::string>::iterator it = anagrams.begin(); it != anagrams.end(); ++it) std::cout << *it << '\n';

    std::cout << "Number of anagrams =" << anagrams.size() << std::endl;
    return 0;
}
#endif