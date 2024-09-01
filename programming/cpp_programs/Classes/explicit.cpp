#include <iostream>

class Date
{
    int d,m,y;
    public:
         explicit Date(int dd = 0, int mm = 0, int yy = 0)
        {
            d = dd;
            m = mm;
            y = yy;
        }
};

int main()
{
    Date d1 {15,4,2}; // explicit, OK
    Date d2 = Date(15); // explicit, OK
  //  Date d3 = {15}; // initialization does not do conversion
  //  Date d4 = 15; // initialization does not do conversion.
}