/*
  도서관리 프로그램
  <처리조건>
  1. 도서에 대한 기본값을 담고 있는 객체 Book 클래스를 구현한다.
  2. 북객체는 책제목, 저자, 책가격을 멤버로 가지고 있다.
  3. 북객체를 통해 새로운 책을 저장하고, 저장된 책에 대한 
     기본정보를 출력할 수 있도록 구현한다.
  4. 기타조건은 프로그램의 흐름에 맞게 구현한다.     
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
    string title;
    string writer;
    int price;

public:
    Book();         // 디폴트 생성자
    Book(string t, string w, int p);

    string getTitle() const;
    void setTitle(string t);
    string getWriter() const;
    void setWriter(string w);
    int getPrice() const;
    void setPrice(int p);

    void bookInfo() const;
};

Book::Book()
// default constructor(디폴트 생성자) - 매개변수가 없는 생성자
// 멤버필드를 초기화시켜주는 역할을 수행한다.
    : title(""), writer(""), price(0) {}

Book::Book(string t, string w, int p)
    : title(t), writer(w), price(p) {}

string Book::getTitle() const { return title; }
void Book::setTitle(string t) { title = t; }
string Book::getWriter() const { return writer; }
void Book::setWriter(string w) { writer = w; }
int Book::getPrice() const { return price; }
void Book::setPrice(int p) { price = p; }

void Book::bookInfo() const {
    cout << "책 제목 : " << title << endl;
    cout << "저자명  : " << writer << endl;
    cout << "책 가격 : " << price << endl << endl;
}

int main() {
    //Book book1;     // Book() 생성자 호출
    //Book book2("C++", "선생님", 3000);
    //book book3;

    //Book book1, book2, book3;

    //Book book[3];

    vector<Book> b;

    b.push_back(Book());
    b.push_back(Book("aaa", "a", 1000));
    b.push_back(Book("bbb", "b", 2000));

    //for (int i = 0; i < b.size(); i++) {
    //    //b[i].bookInfo();
    //    Book imsi = b[i];       // 객체 복사  b.at(i)
    //    imsi.bookInfo();
    //}

    vector<Book>::iterator it;     // 포인터 변수(주소)
    for (it = b.begin(); it != b.end(); it++) {
        //cout << *it << endl;
        Book imsi = *it;
        imsi.bookInfo();
        //it->bookInfo();
    }
    return 0;
}