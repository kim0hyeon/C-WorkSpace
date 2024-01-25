//
// Created by 김영현 on 1/15/24.
//

#ifndef PROBLEM4_3_NAMECARD_H
#define PROBLEM4_3_NAMECARD_H

namespace RANK{
    enum{CLERK, SENIOR, ASSIST, MANAGER};
}

class NameCard{
private:
    char *name;
    char *company;
    char *phone;
    int rank;
public:
    NameCard(char *myname, char *myCompany, char *myPhone, int myrank);
    NameCard(NameCard & copy);
    void ShowNameCard();
    ~NameCard();
};

#endif //PROBLEM4_3_NAMECARD_H
