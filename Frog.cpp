/*
   Question: TestDome - Frog

   A frog only moves forward, but it can move in steps 1 inch long or in
   jumps 2 inches long. A frog can cover the same distance using
   different combinations of steps and jumps.

   Write a function that calculates the number of different combinations
   a frog can use to cover a given distance.

   For example, a distance of 3 inches can be covered in three ways:
   step-step-step, step-jump, and jump-step.
*/

#include <iostream>
#include <stdexcept>
#include <unordered_map>

class Frog
{
public:

   static int numberOfWays(int n)
   {
        int f0=1, f1=1;
        if(n==1) return f1;
        for(auto i=1; i<n;i++){
            auto f2=f1+f0;
            f0=f1;
            f1=f2;
        }
        return f1;
   }

private:
};

#ifndef RunTests
int main(int argc, const char* argv[])
{
   std::cout << Frog::numberOfWays(3)<< std::endl;

    if(Frog::numberOfWays(6)==13) std::cout << "test_passed" << std::endl;
    else std::cout << "test_failed" << std::endl;
   return 0;
}
#endif