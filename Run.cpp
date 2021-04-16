/*
   Question: TestDome - Run

   Write a function that finds the zero-based index of the longest run in
   a string. A run is a consecutive sequence of the same character. If
   there is more than one run with the same length, return the index of
   the first one.

   For example, indexOfLongestRun("abbcccddddcccbba") should return 6 as
   the longest run is dddd and it first appears on index 6.
*/

#include <iostream>
#include <string>
#include <stdexcept>

class Run
{
public:

   static int indexOfLongestRun(std::string str)
   {
       int run_length=1;
       int longest_run_length=1;
       char c=str[0];
       int index=0;
       int index_longest_run;
        for(auto i=1; i< str.size();i++){
            if(str[i]==c){
                run_length++;
            }
            else {
                c=str[i];
                run_length=1;
                index=i;
            }
            if(run_length>longest_run_length) {
                longest_run_length=run_length;
                index_longest_run = index;
            }
        }
        return index_longest_run;
   }
};


#ifndef RunTests
int main(int argc, const char* argv[])
{
   std::cout << Run::indexOfLongestRun("abbcccddddcccbbaeeeeeee");

   return 0;
}
#endif