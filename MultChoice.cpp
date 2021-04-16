#include <iostream>
#include <string>
#include <vector>

class MultipleChoiceTest
{
   
public:
    MultipleChoiceTest(int questionsCount)
    {
        this->questionsCount = questionsCount;
        auto ptr = std::make_unique<int[]>(questionsCount);

        for (int i = 0; i < questionsCount; ++i)
        {
            ptr[i] = -1;
        }
        answers.swap(ptr);
    }

    void setAnswer(int questionIndex, int answer)
    {
        answers[questionIndex] = answer;
    }

    int getAnswer(int questionIndex) const
    {
        return answers[questionIndex];
    }

protected:
    int questionsCount;

private:
    std::unique_ptr<int[]> answers;
};

class TimedMultipleChoiceTest : public MultipleChoiceTest
{
public:
    TimedMultipleChoiceTest(int questionsCount)
        : MultipleChoiceTest(questionsCount)
    {
        auto ptr = std::make_unique<int[]>(questionsCount);

        for (int i = 0; i < questionsCount; ++i)
        {
            ptr[i] = 0;
        }
        times.swap(ptr);
    }

    void setTime(int questionIndex, int time)
    {
        times[questionIndex] = time;
    }

    int getTime(int questionIndex) const
    {
        return times[questionIndex];
    }

private:
    std::unique_ptr<int[]> times;
};

#ifndef RunTests
void executeTest()
{
    MultipleChoiceTest test(5);
    for (int i = 0; i < 5; i++)
    {
        test.setAnswer(i, i);
    }

    for (int i = 0; i < 5; i++)
    {
        std::cout << "Question " << i + 1 << ", correct answer: " << test.getAnswer(i) << "\n";
    }
}

int main()
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Test: " << i + 1 << "\n";
        executeTest();
    }
}
#endif

//this =67%