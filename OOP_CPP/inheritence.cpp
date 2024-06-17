#include <iostream>
using namespace std;

class BaseClass
{
    public:
        BaseClass()
        {
            
        }
        virtual void f(char* s = "unknown")
        {
            cout << "Function f() in BaseClass called from " << s << endl;
            h();
        }

    protected:
        void g(char* s = "unknown")
        {
            cout << "Function g() in BaseClass called from " << s  << endl;
        }
    private:
        void h()
        {
            cout << "Function h() in BaseClass\n";
        }

};

class DerivedClass1 : public virtual BaseClass
{
    public:
        void f(char* s = "unknown")
        {
            cout << "Function f() in Derived1Level1 called from " << s << endl;
            g("DerivedLevel1");
            h("DerivedLevel1");
        }
        void h (char* s = "unknown")
        {
            cout << "Function h() in DerivedLevel1 called from " << s << endl;
        }

};

class DerivedClass2 : public virtual BaseClass
{
    public:
        void f(char* s = "unknown")
        {
            std::cout << "function f() in DerivedClass2 called from " << s << std::endl;
            g ("DerivedLevel2");
            //h(); // will raise error because it is a private member of base class
        }
};

class DerivedClass3 : public DerivedClass1 , public DerivedClass2{
    public:
        void f(char* s = "unknown")
        {
            cout << "function f() in DerivedClass3 called from " << s << endl;
            g("DerivedClass1");
            DerivedClass1::h("DerivedClass3");
            BaseClass::f("DerivedClass3");

        }

};

int main()
{
    /*
    BaseClass b;
    DerivedClass1 d1;
    DerivedClass2 d2;
    DerivedClass3 d3;
    b.f("main 1");
    //b.g(); protected member - cannot be called from outside 
    //b.h(); private member - cannot be called from outside
    d1.f("main 2");
    //d1.g(); protected inherited member - cannot be called from outside
    d1.h("main 3"); // the overridden h() function is called 
    d2.f("main 4");
    //d2.g(); protected member cannot be called from outside
    //d2.h(); private member cannot be called from outside
    d3.f("main 5");
    //d3.g(); // protected member cannot be called from outside
    d3.h(); // the overridden h() function is called
    */

   BaseClass* b = new BaseClass();
   b->f("main 1");

   DerivedClass1 d;
   d.f("main 2");
   BaseClass* b2 = new DerivedClass1();
   b2->f("main 3");

   delete b;
   delete b2;
   

    return 0;


}