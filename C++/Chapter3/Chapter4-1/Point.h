//
// Created by 김영현 on 1/14/24.
//

#ifndef CHAPTER4_1_POINT_H
#define CHAPTER4_1_POINT_H

class Point{
private:
    int x;
    int y;

public:
    bool InitMembers(int xpos, int ypos);
    int GetX() const;
    int GetY() const;
    bool SetX(int xpos);
    bool SetY(int ypos);
};

#endif //CHAPTER4_1_POINT_H
