#include <iostream>
#include <cstring>
using namespace std;

class Gun{
private:
    int bullet;
public:
    Gun(int bnum) : bullet(bnum){ }

    Gun(const Gun &ref) : bullet(ref.bullet) { }

    void Shot(){
        cout << "BBANG!" << endl;
        bullet--;
    }
};

class Police{
private:
    int handcuffs;
    Gun * pistol;
public:
    Police(int bnum, int bcuff) : handcuffs(bcuff){
        if (bnum > 0)
            pistol = new Gun(bnum);
        else
            pistol = NULL;
    }
    Police(const Police& ref) : handcuffs(ref.handcuffs) { // 깊은 복사를 하는 복사 생성자 만들기!
        if (ref.pistol != NULL)
            pistol = new Gun(*(ref.pistol)); // 복사 생성자에서 또 복사 생성자 이용!
        else
            pistol = NULL;
    }
    void PutHandCuff(){
        cout << "SNAP!" << endl;
        handcuffs--;
    }
    void Shot(){
        if (pistol == NULL)
            cout << "Hut BBANG!" << endl;
        else
            pistol->Shot();
    }
    Police& operator=(const Police& ref){ // 깊은 복사를 하는 대입 연산자 만들기! 맞나?
        if (pistol != NULL)
            delete pistol;

        if (ref.pistol != NULL)
            pistol = new Gun(*(ref.pistol));

        handcuffs = ref.handcuffs;
        return *this;
    }
    ~Police(){
        if (pistol != NULL)
            delete pistol;
    }
};

int main(void){
    Police pman1(5, 3);
    Police pman2 = pman1; // 복사 생성자의 호출
    pman2.PutHandCuff();
    pman2.Shot();

    Police pman3(2,4);
    pman3 = pman1; // 대입 연산자의 호출
    pman3.PutHandCuff();
    pman3.Shot();

    return 0;
}
