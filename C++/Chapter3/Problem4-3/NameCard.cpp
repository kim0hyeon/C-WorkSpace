//
// Created by 김영현 on 1/15/24.
//

#include "NameCard.h"
#include <iostream>
#include <cstring>
using namespace std;

NameCard::NameCard(char *myname, char *myCompany, char *myPhone, int myrank)
{
    name = new char[strlen(myname)+1];
    strcpy(name, myname);
    company = new char[strlen(myCompany)+1];
    strcpy(company, myCompany);
    phone = new char[strlen(myPhone)+1];
    strcpy(phone, myPhone);
    rank = myrank;
}

NameCard::NameCard(NameCard & copy) : rank(copy.rank){
    name = new char[strlen(copy.name)+1];
    strcpy(name, copy.name);
    company = new char[strlen(copy.company)+1];
    strcpy(company, copy.company);
    phone = new char[strlen(copy.phone)+1];
    strcpy(phone, copy.phone);
}

void NameCard::ShowNameCard() {
    string ranks[] = {"사원", "주임", "대리", "과장"};
    cout << "이름: " << name << endl;
    cout << "회사: " << company << endl;
    cout << "전화번호: " << phone << endl;
    cout << "직급: " << ranks[rank] << endl << endl;
}

NameCard::~NameCard(){
    delete []name;
    delete []company;
    delete []phone;
}