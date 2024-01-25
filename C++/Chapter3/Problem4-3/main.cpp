#include <iostream>
#include "NameCard.h"
using namespace std;

int main(){
    NameCard manClerk("Lee", "ABCENG", "010-1111-2222", RANK::CLERK);
    NameCard copy1(manClerk);
    NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", RANK::SENIOR);
    NameCard copy2 = manSENIOR;
    copy1.ShowNameCard();
    copy2.ShowNameCard();
    return 0;
}
