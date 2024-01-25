#include <iostream>
using namespace std;

class Rectangle{
private:
    int width;
    int high;
public:
    Rectangle(int wInput, int hInput) : width(wInput), high(hInput) { }
    void ShowAreaInfo() const {
        cout << "넓이는 " << width * high << "입니다." << endl << endl;
    }
};

class Square : public Rectangle{
public:
    Square(int sInput) : Rectangle(sInput, sInput) { }
};

int main() {
    Rectangle rec(4,3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();

    return 0;
}
