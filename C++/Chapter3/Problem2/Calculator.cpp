//
// Created by 김영현 on 1/14/24.
//
#include <iostream>
using namespace std;

class Calculator{
private:
    int plus_cnt;
    int minus_cnt;
    int multi_cnt;
    int div_cnt;
public:
    void Init();
    double Add(const double &num1, const double &num2);
    double Min(const double &num1, const double &num2);
    double Mul(const double &num1, const double &num2);
    double Div(const double &num1, const double &num2);
    void ShowOpCount();
};

void Calculator::Init() {
    plus_cnt = 0;
    minus_cnt = 0;
    multi_cnt = 0;
    div_cnt = 0;
}

double Calculator::Add(const double &num1, const double &num2) {
    plus_cnt++;
    return num1 + num2;
}

double Calculator::Min(const double &num1, const double &num2) {
    minus_cnt++;
    return num1 - num2;
}

double Calculator::Mul(const double &num1, const double &num2) {
    multi_cnt++;
    return num1 * num2;
}

double Calculator::Div(const double &num1, const double &num2) {
    div_cnt++;
    return num1 / num2;
}

void Calculator::ShowOpCount() {
    cout << "덧셈: " << plus_cnt << " 뺄셈: " << minus_cnt << " 곱셈: " << multi_cnt << " 나눗셈: " << div_cnt << endl;
}

int main(){
    Calculator cal;
    cal.Init();
    cout << "3.2 + 2.4 = " << cal.Add(3.2, 3.4) << endl;
    cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
    cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
    cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
    cal.ShowOpCount();
    return 0;
}