#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<std::string> unique_names(const std::vector<std::string>& names1, const std::vector<std::string>& names2)
{
    std::unordered_set<std::string> set;
    for(auto& s: names1){
        set.emplace(s);
    }
    for(auto& s: names2){
        set.emplace(s);
    }
    std::vector<std::string> unique={};
    for(auto it=set.begin();it!=set.end();it++){
        unique.push_back(*it);
    }
    return unique;
}

#ifndef RunTests
int main()
{
    std::vector<std::string> names1 = {"Ava", "Emma", "Olivia"};
    std::vector<std::string> names2 = {"Olivia", "Sophia", "Emma"};
    
    std::vector<std::string> result = unique_names(names1, names2);
    for(auto element : result)
    {
        std::cout << element << ' '; // should print Ava Emma Olivia Sophia
    }
}
#endif