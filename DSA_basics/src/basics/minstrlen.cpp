// remove substring "AB" or "CD" from string s and return the string s after the erasure.

#include <iostream>
#include <stack>
#include <string>
int minimum_strlen(std::string s)
{
    std::stack<char> stack_;
    for(char ch : s)
    {

    if ((!stack_.empty()) &&( ((stack_.top() == 'A') && (ch=='B')) || ((stack_.top() == 'C')&&(ch=='D'))) )
    {
	    stack_.pop(); // remove the pair AB or CD

    } 
    else
    {
	    stack_.push(ch);
    }
    }

    return stack_.size();
}

int main()
{
	std::string s = "ABFCACDDOP";
	std::cout << minimum_strlen(s) << std::endl;
	return 0;
}

