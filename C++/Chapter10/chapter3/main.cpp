#include <iostream>
using namespace std;

class Point{
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) { }
    void ShowPosition() const{
        cout << "[" << xpos << ", " << ypos << ']' << endl;
    }
    Point operator*(int times){
        Point pos(xpos*times, ypos*times);
        return pos;
    }
    friend Point operator*(int times, Point& ref);
};

Point operator*(int times, Point& ref){
    return ref*times;
}

int main() {
    Point pos(1, 2);
    Point cpy;

    cpy = pos*3;
    cpy.ShowPosition(); // [3, 6]

    cpy = pos*3*2;
    cpy.ShowPosition(); // [6, 12], 앞 부터 차례대로 곱한다. 3을 곱하고 그 뒤에 2를 곱한다. return값은 어차피 Point이므로.

    return 0;
}
