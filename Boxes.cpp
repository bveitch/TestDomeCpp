/*
   Question: TestDome - Boxes

   A large box can hold five items, while the small box can hold only one
   item. All items must be placed in boxes and used boxes have to be
   filled up completely.

   Write a function that calculates the minimum number of boxes needed to
   hold a given number of items. If it's not possible to meet the
   requirements, return -1.

   For example, if we have 12 products, 3 large and 3 small boxes, the
   function should return 4 (2 large boxes + 2 small boxes).
*/

#include <stdexcept>
#include <iostream>

class Boxes
{
public:
   static int minimalNumberOfBoxes(int products, int availableLargeBoxes, int availableSmallBoxes)
   {
       int nLarge = products/5;
       int nSmall = products - 5*nLarge;
       if(nLarge > availableLargeBoxes) return -1;
       if(nSmall > availableSmallBoxes) return -1;
       return nLarge + nSmall;
   }
};


#ifndef RunTests
int main(int argc, const char* argv[])
{
   std::cout << Boxes::minimalNumberOfBoxes(12, 3, 3) << std::endl;
   if(Boxes::minimalNumberOfBoxes(12, 3, 3) ==4) std::cout << "test_passed" << std::endl;
   else std::cout << "test_failed" << std::endl;
}
#endif