#include <stdexcept>
#include <iostream>
#include <deque>

class TrainComposition
{
    std::deque<int> train;
public:
    void attachWagonFromLeft(int wagonId)
    {
        train.push_front(wagonId);
    }

    void attachWagonFromRight(int wagonId)
    {
        train.push_back(wagonId);
    }

    int detachWagonFromLeft()
    {
        auto v=train.front();
        train.pop_front();
        return v;
    }

    int detachWagonFromRight()
    { 
        auto v=train.back();
        train.pop_back();
        return v;
    }
};

#ifndef RunTests
int main()
{
    TrainComposition train;
    train.attachWagonFromLeft(7);
    train.attachWagonFromLeft(13);
    std::cout << train.detachWagonFromRight() << "\n"; // 7 
    std::cout << train.detachWagonFromLeft(); // 13
}
#endif