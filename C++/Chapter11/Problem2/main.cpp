#include <iostream>
#include <cstring>
using namespace std;

class Book{
private:
    char * title;
    char * isbn;
    int price;
public:
    Book(char * title, char * isbn, int value) : price(value){
        this->title = new char[strlen(title)+1];
        strcpy(this->title, title);
        this->isbn = new char[strlen(isbn)+1];
        strcpy(this->isbn, isbn);
    }
    Book(const Book &ref) : price(ref.price){
        title = new char[strlen(ref.title)+1];
        strcpy(title, ref.title);
        isbn = new char[strlen(ref.isbn)+1];
        strcpy(isbn, ref.isbn);
    }
    void ShowBookInfo(){
        cout << "제목: " << title << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "가격: " << price << endl;
    }
    Book& operator=(const Book &ref){
        price = ref.price;

        delete []title;
        title = new char[strlen(ref.title)+1];
        strcpy(title, ref.title);

        delete []isbn;
        isbn = new char[strlen(ref.isbn)+1];
        strcpy(isbn, ref.isbn);

        return *this;
    }
    ~Book(){
        delete []title;
        delete []isbn;
    }
};

class EBook : public Book{
private:
    char * DRMKey;
public:
    EBook(char * title, char * isbn, int value, char * key) : Book(title, isbn, value){
        DRMKey = new char[strlen(key)+1];
        strcpy(DRMKey, key);
    }
    EBook(const EBook &ref) : Book(ref){ // EBook의 복사 생성자 정의
        DRMKey = new char[strlen(ref.DRMKey)+1];
        strcpy(DRMKey, ref.DRMKey);
    }
    void ShowEBookInfo(){
        ShowBookInfo();
        cout << "인증키: " << DRMKey << endl << endl;
    }
    EBook& operator=(const EBook &ref){
        Book::operator=(ref); // Book의 대입연산자 호출하는 방법!

        delete []DRMKey;
        DRMKey = new char[strlen(ref.DRMKey)+1];
        strcpy(DRMKey, ref.DRMKey);

        return *this;
    }
    ~EBook(){
        delete []DRMKey;
    }
};

int main() {
    EBook eb1("안녕", "123-213", 10000, "1");
    EBook eb2 = eb1; // 복사 생성자 호출
    eb2.ShowEBookInfo();

    EBook eb3("헬로", "111-122", 20000, "2");
    eb3.ShowEBookInfo();
    eb3 = eb1; // 대입 연산자 호출
    eb3.ShowEBookInfo();

    return 0;
}
