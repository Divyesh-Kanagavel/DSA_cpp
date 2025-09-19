/* sort an array consisting of three elements using dutch national flag algorithm*/

#include <vector>
#include <iostream>

using namespace std;

enum class Color
{
    Red = 0,
    Blue = 1,
    White = 2
};

void swap(vector<Color>& a, int i, int j)
{
    auto temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void dutch_parition(vector<Color>& a)
{
    int red_ptr = 0;
    int blue_ptr = 0;
    int white_ptr = a.size() - 1;

    while(blue_ptr <= white_ptr)
    {
        if (a[blue_ptr] == Color::Red)
        {
            swap(a, red_ptr, blue_ptr);
            red_ptr++;
            blue_ptr++;
        }
        else if (a[blue_ptr] == Color::Blue)
        {
            blue_ptr++;
        }
        else
        {
            swap(a, blue_ptr, white_ptr);
            white_ptr--;
        }
    }

}

std::string printable(Color color)
{
    switch(color)
    {
        case Color::Blue : return "Blue";  
        case Color::Red : return "Red";
        case Color::White : return "White";
        default : return "";
    }
}

int main()
{
    vector<Color> a = {Color::Blue, Color::Red,Color::Blue, Color::White, Color::Blue, Color::White, Color::Red, Color::Blue};
    dutch_parition(a);
    for(auto i:a)
        std::cout << printable(i) << " ";
    std::cout << "\n";
}