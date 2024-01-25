#include <iostream>
using namespace std;

class MyFriendInfo{
private:
    char * name;
    int age;
public:
    MyFriendInfo(char * fname, int fage) : age(fage) {
        name = new char[strlen(fname)+1];
        strcpy(name, fname);
        cout << "친구정보 생성!" << endl;
    }
    void ShowMyFriendInfo(){
        cout << "이름: " << name << endl;
        cout << "나이: " << age << endl;
    }
    ~MyFriendInfo(){
        delete []name;
        cout << "친구정보 삭제!" << endl;
    }
};

class MyFriendDetailInfo : public MyFriendInfo {
private:
    char * addr;
    char * phone;
public:
    MyFriendDetailInfo(char * fname, int fage, char * faddr, char * fphone)
        : MyFriendInfo(fname, fage){
        addr = new char[strlen(faddr)+1];
        strcpy(addr, faddr);
        phone = new char[strlen(fphone)+1];
        strcpy(phone, fphone);
        cout << "디테일 생성!" << endl;
    }
    void ShowMyFriendDetailInfo(){
        ShowMyFriendInfo();
        cout << "주소: " << addr << endl;
        cout << "전화: " << phone << endl;
    }
    ~MyFriendDetailInfo(){
        delete []addr;
        delete []phone;
        cout << "디테일 삭제!" << endl;
    }
};


int main() {
    MyFriendDetailInfo fInfo("채빈", 25, "안양", "010-4290-3310");
    fInfo.ShowMyFriendDetailInfo();
    return 0;
}
