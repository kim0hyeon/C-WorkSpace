#include <iostream>
using namespace std;

class Car{
private:
    int gasolineGauge;
public:
    Car(int gas) : gasolineGauge(gas){ }
    int GetGasGauge() const{
        return gasolineGauge;
    }
};

class HybridCar : public Car {
private:
    int eletricGauge;
public:
    HybridCar(int gas, int elec) : Car(gas), eletricGauge(elec) { }
    int GetElecGauge() const{
        return eletricGauge;
    }
};

class HybridWaterCar : public HybridCar {
private:
    int waterGauge;
public:
    HybridWaterCar(int gas, int elec, int water) : HybridCar(gas, elec), waterGauge(water) { }
    void ShowCurrentGauge(){
        cout << "잔여 가솔린: " << GetGasGauge() << endl;
        cout << "잔여 전기량: " << GetElecGauge() << endl;
        cout << "잔여 워터량: " << waterGauge << endl;
    }
};

int main(){
    HybridWaterCar hwCar(10, 20, 30);
    hwCar.ShowCurrentGauge();
    return 0;
}