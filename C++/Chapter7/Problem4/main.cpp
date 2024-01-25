#include <iostream>
#include <cstring>
using namespace std;

class Book{
private:
    char * title;
    char * isbn;
    int price;
public:
    Book(char * titleInput, char * isbnInput, int priceInput) : price(priceInput){
        title = new char[strlen(titleInput)+1];
        strcpy(title, titleInput);
        isbn = new char[strlen(isbnInput)+1];
        strcpy(isbn, isbnInput);
    }
    void ShowBookInfo() const{
        cout << "제목: " << title << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "가격: " << price << endl;
    }
};

class EBook : public Book{
private:
    char * DRMKey;
public:
    EBook(char * titleInput, char * isbnInput, int priceInput, char * DRMInput)
            : Book(titleInput, isbnInput, priceInput){
        DRMKey = new char[strlen(DRMInput)+1];
        strcpy(DRMKey, DRMInput);
    }
    void ShowEBookInfo() const {
        ShowBookInfo();
        cout << "인증키: " << DRMKey << endl << endl;
    }
};

int main() {
    Book book("좋은 C++", "555-12345-890-0", 20000);
    book.ShowBookInfo();
    cout << endl;
    EBook ebook("좋은 C++", "555-12345-890-1", 10000, "fxdx9w0i8kiw");
    ebook.ShowEBookInfo();

    return 0;
}
