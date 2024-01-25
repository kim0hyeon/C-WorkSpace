//
// Created by 김영현 on 1/14/24.
//

#ifndef CHAPTER4_1_RECTANGLE_H
#define CHAPTER4_1_RECTANGLE_H

#include "Point.h"

class Rectangle{
private:
    Point upLeft;
    Point lowRight;
public:
    bool InitMembers(const Point &ul, const Point &lr);
    void ShowRecInfo() const; // const?
};

#endif //CHAPTER4_1_RECTANGLE_H
