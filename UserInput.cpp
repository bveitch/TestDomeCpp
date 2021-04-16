#include <iostream>
#include <string>
#include <ctype.h>
/**
User interface contains two types of user input controls: TextInput, which accepts all characters and NumericInput, which accepts only digits.

Implement the following methods:

add on class TextInput - adds the given character to the current value
getValue on class TextInput - returns the current value
add on class NumericInput - overrides the base class method so that each non-numeric character is ignored
*/
class TextInput
{
protected:
    std::string str;
public:
    virtual void add(char c) {  str+=c;}

    std::string getValue() { return str; }
};

class NumericInput : public TextInput 
{ 
public:
    void add(char c) { 
        if(isdigit(static_cast<unsigned char>(c))) {
            str+=c;
        }
    }

};

#ifndef RunTests
int main()
{
    //TextInput* input = new NumericInput();
    TextInput* input = new NumericInput();
    input->add('1');
    input->add('a');
    input->add('0');
    std::cout << input->getValue();
}
#endif
//this 100%