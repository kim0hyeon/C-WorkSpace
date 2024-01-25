#include <iostream>
using namespace std;

typedef struct Point{
    int xpos;
    int ypos;
} Point;

Point& PntAdder(const Point &p1, const Point &p2);

int main() {
    Point *p1 = new Point;
    p1->xpos = 10;
    p1->ypos = 10;

    Point *p2 = new Point;
    p2->xpos = 20;
    p2->ypos = 20;

    Point &p3 = PntAdder(*p1, *p2); // *p1, *p2가 들어가야 하는 이유는 참조자를 선언할 땐 주소가 아니라 객체 자체를 가리켜야 하기 때문이다.

    cout << p3.xpos << endl;
    cout << p3.ypos << endl;

    delete p1;
    delete p2;
    delete &p3; // 위의 p1과 p2는 메모리 공간을 나타낸다. 그냥 p3도 별명이기 때문에 &p3로 메모리를 지정해 주어야 메모리 헤제가 가능하다.
    return 0;
}

Point& PntAdder(const Point &p1, const Point &p2){
    Point *p3 = new Point;
    p3->xpos = p1.xpos + p2.xpos;
    p3->ypos = p1.ypos + p2.ypos;

    return *p3; // *p3를 리턴해야 하는 이유는 p3만 리턴하게 되면 메모리 주소만 리턴하는 것이 된다. *p3로 객체를 리턴해야 받는 쪽에서 제대로 참조할 수 있다.
}
