//
// Created by 김영현 on 1/14/24.
//

#include "Car.h"
#include <iostream>
#include <cstring>
using namespace std;


void Car::InitMembers(char *ID, int fuel) {
    strcpy(gamerID, ID);
    fuelGauge = fuel;
    carSpeed = 0;
}

void Car::ShowCarState(){
    cout << "소유자ID: " << gamerID << endl;
    cout << "연료량: " << fuelGauge << endl;
    cout << "현재속도: " << carSpeed << endl;
}

void Car::Accel() {
    if (fuelGauge <= 0)
        return ;
    else
        fuelGauge -= CAR_CONST::FUEL_STEP;

    if ((carSpeed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD){
        carSpeed = CAR_CONST::MAX_SPD;
        return ;
    }
    carSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break() {
    if (carSpeed < CAR_CONST::BRK_STEP){
        carSpeed = 0;
        return ;
    }
    carSpeed -= CAR_CONST::BRK_STEP;
}

