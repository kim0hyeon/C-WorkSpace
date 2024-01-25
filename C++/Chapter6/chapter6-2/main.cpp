#include <iostream>
using namespace std;

class Point;

class PointOP{
private:
    int opcnt;
public:
    PointOP() : opcnt(0) { }
    Point PointAdd(const Point&, const Point&);
    Point PointSub(const Point&, const Point&);
    ~PointOP(){
        cout << "Operation times: " << opcnt << endl;
    }
};

class Point{
private:
    int x, y;
public:
    Point(const int& xpos, const int& ypos) : x(xpos), y(ypos) { }
    friend Point PointOP::PointAdd(const Point &, const Point &); // friend 선언을 함으로써 PointOP에 존재하는 private 영역에 접근이 가능하다!
    friend Point PointOP::PointSub(const Point &, const Point &); // friend 선언을 함으로써 PointOP에 존재하는 private 영역에 접근이 가능하다!
    friend void ShowPointPos(const Point&); // friend 선언을 함으로써 PointOP에 존재하는 private 영역에 접근이 가능하다!
};