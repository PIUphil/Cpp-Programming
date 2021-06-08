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

/*
  클래스 이름 : BookHandler
  클래스 유형 : Control 클래스
  처리기능
  1. 책을 등록하는 작업
  2. 등록된 책에 대한 정보를 출력
  3. 등록된 책에 모든 금액을 누적해 출력
  4. 등록된 책의 저자명을 통해 책의 정보를 출력
  5. 책 제목을 통해 해당 책의 내용을 수정하도록 구현
  6. 한 권 이상의 책을 담아서 처리할 수 있도록 자료구조를 활용
*/

class BookHandler {
    vector<Book> book;

public:
    // 책을 등록하는 작업
    void addBook();
    // 현재 등록된 책의 수를 리턴
    void getBook();
    // 등록된 모든 책의 정보 출력
    void showAllBook();
    // 등록된 책의 가격 누적
    void showAllPrice();
    // 저자명에 따른 책정보 출력
    void getBookInfo();
    // 제목에 따른 책 수정
    void editBook();
};

void BookHandler::addBook() {
    string title;
    string writer;
    int price;

    cout << "책제목 = ";
    //cin >> title;
    getline(cin, title);
    cout << "저자명 = ";
    //cin >> writer;
    getline(cin, writer);
    cout << "책가격 = ";
    cin >> price;
    

    /*Book b(title, writer, price);
    book.push_back(b);*/
    book.push_back(Book(title, writer, price));
    cout << "책 등록을 완료했습니다." << endl << endl;
}

void BookHandler::getBook() {
    cout << "등록된 책의 개수 : " << book.size() << endl;
}

void BookHandler::showAllBook() {
    for (auto it = book.begin(); it != book.end(); it++) {
        /*Book imsi = *it;
        imsi.bookInfo();*/
        it->bookInfo();
    }
}

void BookHandler::showAllPrice() {
    int sum = 0;
    for (auto it = book.begin(); it != book.end(); it++) {
        sum += it->getPrice();
    }
    cout << "총 도서가격 : " << sum << endl;
}

void BookHandler::getBookInfo() {
    cout << "저자명 = ";
    string w;
    getline(cin, w);

    for (auto it = book.begin(); it != book.end(); it++) {
        if (it->getWriter() == w) {
            it->bookInfo();
            return;
        }   
    }
    cout << "입력한 저자에 대한 도서는 발견되지 않았습니다." << endl << endl;
}

void BookHandler::editBook() {
    cout << "책제목 = ";
    string t;
    cin >> t;

    for (auto it = book.begin(); it != book.end(); it++) {
        if (it->getTitle() == t) {
            
            cout << "저자명 = ";
            string w;
            getline(cin, w);
            
            cout << "책가격 = ";
            int p;
            cin >> p;

            it->setWriter(w);
            it->setPrice(p);
        }
    }
}

int main() {
    BookHandler manager;

    while (true) {
        // 메뉴출력
        cout << "== Book Manager ==\n";
        cout << "1. 도서 등록\n";
        cout << "2. 도서 검색\n";
        cout << "3. 도서 출력\n";
        cout << "4. 작업 종료\n";
        cout << "===================\n";
        int ch;
        cout << "선택 = ";
        cin >> ch;

        // 입력버퍼를 지우는 작업
        cin.ignore();

        // 선택에서 숫자를 입력하고 엔터를 누르면
        // '엔터' (= \n)가 다음으로 넘어가서 문자로 입력되어버림 -> 입력버퍼에 남아있음
        // '엔터'를 지우기위해 ignore()를 해줌 -> // 입력버퍼 초기화(cin.clear())

        /*
         문자열을 입출력하는 함수 : gets(), puts()
         gets(변수); // 문자열 입력     // 변수로 입력 // get - 입력을 받아옴
         puts(변수); // 문자열 출력    //변수에 있는것을 출력
        */
        // fflush(stdin);      // stdio.h
        
        //gets();     // getstring();     하나의 문자열을 얻어와라
        // puts();

        switch (ch) {
        case 1: manager.addBook(); break;
        case 2: {
            cout << "== 검색방법 ==\n";
            cout << "[1]저자명 [2]도서명\n";
            int c;
            cin >> c;
            cin.ignore();
            if (c == 1) manager.getBookInfo();
            else if (c == 2) manager.editBook();    // 아님..
            else cout << "올바르지 않은 선택입니다.\n";
            break;
        }
        case 3:
            manager.showAllBook(); break;
        case 4:
            cout << "프로그램을 종료합니다.\n";
            return 0;
        }
    }
    return 0;
}