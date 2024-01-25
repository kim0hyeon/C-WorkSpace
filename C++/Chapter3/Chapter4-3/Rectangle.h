//
// Created by 김영현 on 1/14/24.
//

#ifndef CHAPTER4_3_RECTANGLE_H
#define CHAPTER4_3_RECTANGLE_H

#include "Point.h"

class Rectangle{
private:
    Point upLeft;
    Point lowRight;
public:
    Rectangle(const int &x1, const int &y1, const int &x2, const int &y2);
    void ShowRefInfo() const;
};

#endif //CHAPTER4_3_RECTANGLE_H
