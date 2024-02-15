#include <iostream>
using namespace std;

class Point{
private:
    int xpos, ypos;
public:
    Point(const int x = 0, const int y = 0) : xpos(x), ypos(y)
    { }
    void ShowPosition() const{
        cout << "[" << xpos << ", " << ypos << "]" << endl;
    }

    Point& operator+=(Point& pos){
        xpos += pos.xpos;
        ypos += pos.ypos;
        return *this;
    }

    Point& operator-=(Point& pos){
        xpos -= pos.xpos;
        ypos -= pos.ypos;
        return *this;
    }

    friend Point operator-(Point &pos1, Point &pos2);
    friend bool operator==(Point &pos1, Point &pos2);
    friend bool operator!=(Point &pos1, Point &pos2);
};

Point operator-(Point &pos1, Point &pos2){
    Point pos = Point(pos1.xpos+pos2.xpos, pos1.ypos+pos2.ypos);
    return pos;
}

bool operator==(Point &pos1, Point &pos2){
    if (pos1.xpos != pos2.xpos)
        return false;
    if (pos1.ypos != pos2.ypos)
        return false;
    return true;
}

bool operator!=(Point &pos1, Point &pos2){
    return !(pos1==pos2);
}

int main() {

    return 0;
}
