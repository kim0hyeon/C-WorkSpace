#include <iostream>
using namespace std;

class Point{
private:
    int xpos, ypos;
public:
    void Init(int x, int y){
        xpos = x;
        ypos = y;
    }
    void ShowPointInfo() const{
        cout << "[" << xpos << ", " << ypos << "]" << endl;
    }
};

class Circle{
private:
    Point center;
    int radius;
public:
    void Init(int x, int y, int r){
        center.Init(x, y);
        radius = r;
    }
    void ShowCircleInfo() const {
        cout << "radius: " << radius << endl;
        center.ShowPointInfo();

    };
};

class Ring{
private:
    Circle innerCircle;
    Circle outerCircle;
public:
    void Init(int innerX, int innerY, int innerR, int outerX, int outerY, int outerR){
        innerCircle.Init(innerX, innerY, innerR);
        outerCircle.Init(outerX, outerY, outerR);
    }
    void ShowRingInfo() const{
        cout << "Inner Circle Info..." << endl;
        innerCircle.ShowCircleInfo();
        cout << "Outer Circle Info..." << endl;
        outerCircle.ShowCircleInfo();
    }
};

int main() {
    Ring ring;
    ring.Init(1,1,4,2,2,9);
    ring.ShowRingInfo();

    return 0;
}
