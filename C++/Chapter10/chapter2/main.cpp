#include <iostream>
using namespace std;

class Point{
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y){ }
    void ShowPosition() const{
        cout << "[" << xpos << ", " << ypos << "]" << endl;
    }
    Point& operator++(){ // 전위증가
        xpos += 1;
        ypos += 1;
        return *this;
    }
    const Point operator++(int) { // 후위증가
        const Point retobj(xpos, ypos); // 실제로는 값을 증가시키는데 이 때에만 새로운 Point객체를 생성해 원래 값을 지닌 객체를 리턴한다.
        xpos += 1;
        ypos += 1;
        return retobj;
    }
    Point& operator--() { // 전위감소
        xpos -= 1;
        ypos -= 1;
        return *this;
    }
    const Point operator--(int){ // 후위감소
        const Point retobj(xpos, ypos);
        xpos -= 1;
        ypos -= 1;
        return retobj;
    }
};

int main(){
    Point pos(3, 5);
    Point cpy;
    cpy = pos--; // cpy 에는 pos 그대로 [3, 5]가 저장될 것, pos 는 [2, 4]가 될 것
    cpy.ShowPosition();
    pos.ShowPosition();

    cpy = pos++; // cpy 에는 [2, 4]가 저장될 것, pos 는 [3, 5]가 될 것
    cpy.ShowPosition();
    pos.ShowPosition();

    return 0;
}