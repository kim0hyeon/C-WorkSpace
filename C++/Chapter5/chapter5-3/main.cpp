#include <iostream>
using namespace std;

class SoSimple{
private:
    int num;
public:
    SoSimple(int n): num(n){ }
    SoSimple(const SoSimple & copy) : num(copy.num){
        cout << "Called SoSimple(const SoSimple & copy)" << endl;
    }
    SoSimple & AddNum(int n){
        num += n;
        return *this;
    }
    void ShowData(){
        cout << "num: " << num << endl;
    }
};

SoSimple SimpleFuncObj(SoSimple ob){ // ob = obj로 복사생성자 호출
    cout << "return 이전" << endl;
    return ob; // return ob이므로 SoSimple ob를 리턴하는 것과 마찬가지다. 리턴할 때 새로 생성자를 생성한다고 했으니 복사 생성자가 호출되는거 맞나
}

int main() {
    SoSimple obj(7);
    SimpleFuncObj(obj).AddNum(30).ShowData();
    obj.ShowData();
    return 0;
}
