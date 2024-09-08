#include<iostream>
using namespace std;
class box{
private:
    double height;
    double length;
    double width;
public:
    box (double h, double l, double w)
{
    height =h;
    length= l;
    width= w;
}
friend void print_dimention(box& b);
friend class friend_class;
};

class friend_class
{

public:
void print_volume (box& b)
{
double volume=b.height*b.length*b.width;
cout << "volume" <<volume << endl;
}
};


void print_dimention(box& b)
{
cout << "height" <<b.height<< endl;
cout << "height" <<b.length<<endl;
cout << "height" <<b.width<<endl;

}


int main()
{

box b1(7.5, 8.5, 6.9);
friend_class fc;
print_dimention(b1);
fc.print_volume(b1);
  return 0;
}