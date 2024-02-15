//
// Created by 김영현 on 1/28/24.
//

#include "AccountHandler.h"
#include "BankingCommonDec1.h"
#include <iostream>
using namespace std;

int main() {
    AccountHandler manager;
    int choice;

    while(true){
        manager.ShowMenu();
        cout << "선택: "; cin >> choice;
        cout << endl;

        switch(choice){
            case MAKE:
                manager.MakeAccount();
                break;
            case DEPOSIT:
                manager.DepositMoney();
                break;
            case WITHDRAW:
                manager.WithDrawMoney();
                break;
            case INQUIRE:
                manager.ShowAllAccInfo();
                break;
            case EXIT:
                return 0;
            default:
                cout << "Illegal selection.." << endl;
        }
    }
    return 0;
}