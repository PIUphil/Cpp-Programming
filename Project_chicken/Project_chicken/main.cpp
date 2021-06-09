#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
using namespace std;


int chicken = 20, radish= 20;
int coke = 20, beer = 20;
float oil = 20;

// 치킨----------------------------------------------------------------
class Chicken {				// 후라이드치킨 - 최상위클래스
public:
	Chicken();
	void fry();
	virtual int getSeasoning() { return 0; }
	virtual void setSeasoning(int ss) {}
	virtual int getSoysource() { return 0; }
	virtual void setSoysource(int soy) {}
	virtual int getGarlic() { return 0; }
	virtual void setGarlic(int gl) {}
};

Chicken::Chicken() {}

void Chicken::fry() { chicken--; radish--; oil -= 0.1; }


class SeasoningChicken : public Chicken {	// 양념 치킨
	static int seasoning;

public:
	SeasoningChicken();
	void fry();
	int getSeasoning();
	void setSeasoning(int ss);
};

SeasoningChicken::SeasoningChicken() { seasoning = 20; }

void SeasoningChicken::fry() {chicken--; radish--; seasoning--; oil -= 0.1;}

int SeasoningChicken::getSeasoning() { return seasoning; }

void SeasoningChicken::setSeasoning(int ss) { seasoning += ss; }

int SeasoningChicken::seasoning = 20;


class SoyChicken : public Chicken {			// 간장 치킨
	static int soysource;

public:
	SoyChicken();
	void fry();
	int getSoysource();
	void setSoysource(int soy);
};

SoyChicken::SoyChicken() { soysource = 20; }

void SoyChicken::fry() { chicken--; radish--; soysource--; oil -= 0.1; }

int SoyChicken::getSoysource() { return soysource; }

void SoyChicken::setSoysource(int soy) { soysource += soy; }

int SoyChicken::soysource = 20;


class GarlicChicken : public Chicken {		// 갈릭 치킨
	static int garlic;

public:
	GarlicChicken();
	void fry();
	int getGarlic();
	void setGarlic(int gl);
};

GarlicChicken::GarlicChicken() { garlic = 20; }

void GarlicChicken::fry() { chicken--; radish--; garlic--; oil -= 0.1; }

int GarlicChicken::getGarlic() { return garlic; }

void GarlicChicken::setGarlic(int gl) { garlic += gl; }

int GarlicChicken::garlic = 20;


void Coke() { coke--; }
void Beer() { beer--; }

// ----------------------------------------------------------------

// ChickenHandler();

// ----------------------------------------------------------------

int run() {
	int ch;

	cout << "========== 치킨 주문 프로그램 ==========" << endl
		<< "1. 메뉴 선택		5. 재고 확인" << endl
		<< "2. 배달 완료		6. 재고 조정" << endl
		<< "3. 주문 취소		7. 판매실적 확인" << endl
		<< "4. 주문 확인		8. 프로그램 종료" << endl
		<< "========================================" << endl
		<< "선택 = ";
	cin >> ch;

	return ch;
}

void showMenu() {
	cout<< "\n ==== 메뉴선택 ====" << endl
		<< "1. 후라이드 (15,000)" << endl
		<< "2. 양념치킨 (16,000)" << endl
		<< "3. 간장치킨 (17,000)" << endl
		<< "4. 갈릭치킨 (17,000)" << endl
		<< "5. 콜라      (1,000)" << endl
		<< "6. 맥주      (3,000)" << endl
		<< "7. 선택 종료" << endl
		<< "====================" << endl;
}

string totalChoice(vector<int> choice) {			// 총 메뉴 (Map; key-메뉴, value-수량)

	vector<string> list = { "", "후라이드", "양념치킨", "간장치킨", "갈릭치킨", "콜라", "맥주" };
	map<string, int> mapList;

	for (int i = 0; i < choice.size(); i++)
		if (mapList.find(list[choice[i]]) == mapList.end())
			mapList[list[choice[i]]] = 1;
		else mapList[list[choice[i]]]++;

	string choiceStr = "[";

	map<string, int>::iterator iter;
	for (iter = mapList.begin(); iter != mapList.end(); iter++) {
		choiceStr += iter->first + "(" + to_string(iter->second) + "), ";
	}
	choiceStr = choiceStr.substr(0, choiceStr.length() - 2) + "]";

	return choiceStr;
}


int totalPrice(vector<int> choice) {			// 총 주문금액
	int tot = 0;

	vector<int> price = {0, 15000, 16000, 17000, 17000, 1000, 3000 };

	for (int i = 0; i < choice.size(); i++)
		tot += price[choice[i]];

	return tot;
}

void cook(vector<int> choice);
void orderList(string ttc, string ttp, string addr, string callNum);


void menu() {										// 메뉴 선택
	int ch_menu;
	vector<int> choice;

	while (true) {
		showMenu();
		cout << "선택 = ";
		cin >> ch_menu;
		
		if (ch_menu ==7) break;
		choice.push_back(ch_menu);
	}

	cout << "\n<주문 확인>" << endl;

	string ttc = totalChoice(choice);
	int ttp = totalPrice(choice);
	cout << ttc << "\t = " << ttp << "원" << endl;

	char chk;
	cout << "주문내용이 맞습니까? (y/n) = ";
	cin >> chk;
	if (chk == 'n'|| chk=='N') {
		cout << "주문이 취소되었습니다." << endl << endl;
		return;
	}

	int deliv;
	string addr, callNum;
	cout << "배달장소(1.홀 2.근방 3.먼거리) = ";
	cin >> deliv;

	if (deliv == 1) { addr = "홀"; callNum = ""; }
	else if (deliv != 1) {
		cout << "상세주소 = ";
		cin >> addr;
		/*getline(cin, addr);
		cin.ignore();*/
		cout << "연락처 = ";
		cin >> callNum;
		/*getline(cin, callNum);
		cin.ignore();*/
	}
	
	cout << "\n<주문 확인>" << endl;
	cout << ttc << " = " << ttp << "원" << endl;

	if (deliv == 1) {}
	else if (deliv == 2) {
		ttp += 1000;
		cout << "+ 배달비 1,000원\t = " << ttp << "원" << endl;
	}
	else if (deliv == 3) {
		ttp += 2000;
		cout << "+ 배달비 2,000원\t = " << ttp << "원" << endl;
	}
	else cout << "잘못된 선택입니다"<<endl;

	cout << "\t\t\t 감사합니다" << endl << endl;

	cook(choice);
	orderList(ttc, to_string(ttp), addr, callNum);
}

void cook(vector<int> choice) {							// 요리
	Chicken chik;
	SeasoningChicken ssc;
	SoyChicken syc;
	GarlicChicken glc;

	for (int i = 0; i < choice.size(); i++) {
		switch (choice[i]) {
		case 1: chik.fry(); break;
		case 2: ssc.fry(); break;
		case 3: syc.fry(); break;
		case 4: glc.fry(); break;
		case 5: Coke(); break;
		case 6: Beer(); break;
		default: cout << "요리 실패" << endl;
		}
	}
}

vector<vector<string>> orderV = {};
void orderList(string ttc, string ttp, string addr, string callNum) {		// 주문 내역
	orderV.push_back({ttc, ttp, addr, callNum});		// 2차원벡터
}

vector<vector<string>> completeV = {};
void completeList(string ttc, string ttp, string addr, string callNum) {		// 완료 내역
	completeV.push_back({ ttc, ttp, addr, callNum });		// 2차원벡터
}

void complete() {											// 배달 완료
	int del;

	cout << "\n============== 배달 완료 ==============" << endl;
	for (int i = 0; i < orderV.size(); i++)
		cout << i + 1 << ". " << orderV[i][0] << " " << orderV[i][3] << endl;
	cout << "0. 취소"<< endl;
	cout << "=======================================" << endl;
	cout << "선택 = ";
	cin >> del;
	
	if (del == 0) return;
	completeList(orderV[del-1][0], orderV[del - 1][1], orderV[del - 1][2], orderV[del - 1][3]);
	orderV.erase(orderV.begin() + del - 1);
}

void cancel() {													// 주문 취소
	int del;

	cout << "\n============== 주문 취소 ==============" << endl;
	for (int i = 0; i < orderV.size(); i++)
		cout << i + 1 << ". " << orderV[i][0] << " " << orderV[i][3] << endl;
	cout << "0. 취소" << endl;
	cout << "=======================================" << endl;
	cout << "선택 = ";
	cin >> del;

	if (del == 0) return;
	orderV.erase(orderV.begin() + del - 1);
}


void confirm() {												// 주문확인
	cout << "\n============== 주문 확인 ==============" << endl;
	for (int i = 0; i < orderV.size(); i++) {
		cout << i + 1 << ". " << orderV[i][0] << " " << orderV[i][3] << endl;
		cout << "   " << orderV[i][2] << endl;
	}
	cout << "=======================================" << endl << endl;
}

void amount() {											// 재고 확인
	Chicken chik;
	/*SeasoningChicken ssc;
	SoyChicken syc;
	GarlicChicken glc;*/

	cout << "\n================= 남은 재료 =================" << endl
		<< "치킨 = " << chicken << "  치킨무= " << radish << "   콜라 = " << coke << "   맥주 = " << beer << endl
		<< "양념 = " << chik.getSeasoning() << "   간장 = " << chik.getSoysource() << "   마늘 = "
		<< chik.getGarlic() << "   기름 = " << oil << endl
		<< "=============================================" << endl << endl;
}


void fix() {											// 재고조정
	SeasoningChicken ssc;
	GarlicChicken glc;
	SoyChicken syc;

	while (true) {
		cout << "\n================= 재고 조정 =================" << endl
			<< "1. 치킨 = " << chicken << "\t5. 양념 = " << ssc.getSeasoning() << "\t9. 종료" << endl
			<< "2. 치킨무 = " << radish << "\t6. 간장 = " << syc.getSoysource() << endl
			<< "3. 콜라 = " << coke << "\t7. 마늘 = " << glc.getGarlic() << endl
			<< "4. 맥주 = " << beer << "\t8. 기름 = " << oil << endl
			<< "=============================================" << endl
			<< "선택 = ";

		int ch, a;
		cin >> ch;
		if (ch == 9) break;

		cout << "수량 = ";
		cin >> a;

		switch (ch) {
		case 1: chicken += a; break;
		case 2: radish += a; break;
		case 3: coke += a; break;
		case 4: beer += a; break;
		case 5: ssc.setSeasoning(a); break;
		case 6: syc.setSoysource(a); break;
		case 7: glc.setGarlic(a); break;
		case 8: oil += a; break;
		default: cout << "잘못된 선택입니다" << endl;
		}
	}
}

void income() {													// 판매 실적
	int totalEarn = 0;
	cout << "\n============= 판매 실적 =============" << endl
		<< "   판매			  금액" << endl;
	for (int i = 0; i < completeV.size(); i++) {
		cout << i + 1 << ". " << completeV[i][0] << "  " << completeV[i][1] << "원" << endl;
		totalEarn += stoi(completeV[i][1]);
	}
	cout << "-------------------------------------" << endl;
	cout << "\t\t\t총 " << totalEarn << "원" << endl << endl;
}


int main() {
	// 1. 메뉴 선택  2. 배달 완료  3. 주문 취소  4. 주문 확인
	// 5. 재고 확인  6. 재고 조정  7. 판매실적 확인  8. 프로그램 종료
	enum { MENU = 1, COMPLETE, CANCEL, CONFIRM, AMOUNT, FIX, INCOME, BYE };

	while (true) {
		switch (run()) {
		case MENU: menu(); break;
		case COMPLETE: complete(); break;
		case CANCEL: cancel(); break;
		case CONFIRM: confirm(); break;
		case AMOUNT: amount(); break;
		case FIX: fix(); break;
		case INCOME: income(); break;
		case BYE:
			cout << "오늘도 수고하셨습니다 (_ _)" << endl;
			return 0; break;
		default:
			cout << "잘못된 선택입니다." << endl << endl;
		}
	}
	return 0;
}