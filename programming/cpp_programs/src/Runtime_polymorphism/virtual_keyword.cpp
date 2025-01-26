#include <cstdio>

struct BaseClass
{
    virtual const char* final_message() const
    {
        return "BaseClass\n";
    }
};

struct Derivedclass : BaseClass
{
    // virtual function overridden in the derived class
    const char* final_message() const override
    {
        return "Derived class!\n";
    }

};

int main()
{
    BaseClass bc;
    Derivedclass dc;
    BaseClass& ref = dc;

    printf("%s",bc.final_message());
    printf("%s",dc.final_message());
    printf("%s",ref.final_message());
    return 0;
}