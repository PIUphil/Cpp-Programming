/*
  std::array
  - 메모리를 자동으로 할당하고 해제하며,
    원소의 타입과 배열크기를 매개변수로 사용하는 클래스 템플릿
*/

#include <iostream>
#include <array>
using namespace std;

int main() {
    array<int, 3> arr1;         //  <type, size>
    arr1[0] = 1;

    cout << "arr1 배열의 첫번째 원소 : " << arr1[0] << endl;

    // 크기가 5인 float타입의 배열을 생성하고 초기화
    array<double, 5> arr2 = { 1.1, 2.2, 3.3, 4.4, 5.5 };

    cout << "arr2 배열의 원소들" << endl;
    for (int i = 0; i < arr2.size(); i++) {
        cout << arr2[i] << " ";
    }
    return 0;
}