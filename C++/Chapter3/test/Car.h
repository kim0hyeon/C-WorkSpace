//
// Created by 김영현 on 1/14/24.
//

#ifndef TEST_CAR_H
#define TEST_CAR_H

namespace CAR_CONST{
    enum{
        ID_LEN = 20, MAX_SPD = 200, FUEL_STEP = 2,
        ACC_STEP = 10, BRK_STEP = 10
    };
}

class Car{
private:
    char gamerID[CAR_CONST::ID_LEN];
    int fuelGauge;
    int carSpeed;
public:
    void InitMembers(char* ID, int fuel);
    void ShowCarState();
    void Accel();
    void Break();
};

#endif //TEST_CAR_H
