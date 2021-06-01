/*
  �迭(Array)
  - ������ �ڷ����� �ϳ��� �̸����� ��� �����ϴ� �ڷᱸ��
  - �������� ���� ���̰�, ó���ӵ��� ������ �ϱ� ����.
  - 1���� �迭�� ������ �迭(2���� �迭...)
  - �迭�� ����
	int a;
	int arr[�迭�� ����];   // ['÷��'] 
  - �迭�� �ε����� 0���� �����Ѵ�

  - ����(variable)
  - �迭(Array)
  - ����ü(structure) : ���� �ٸ� �ڷ����� �ϳ��� �̸����� ���� �ڷᱸ��
  - Ŭ����(class)
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	// int a, b, c;
	int arr[3];			// �迭 - 4����Ʈx3 // ���ӵ� ������ ��ġ
	/*a = 10;
	b = 20;
	c = 30;*/
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;		// �迭�� ����θ� �����Ⱚ�� ��;;


	/*cout << sizeof(int) << "bytes" << endl;	
	cout << a << " : " << &a << endl;
	cout << b << " : " << &b << endl;
	cout << c << " : " << &c << endl;*/

	cout << sizeof(arr) << "bytes" << endl;
	/*cout << arr[0] << " : " << &arr[0] << endl;
	cout << arr[1] << " : " << &arr[1] << endl;
	cout << arr[2] << " : " << &arr[2] << endl;*/
	for (int i = 0; i < 3; i++) {
		cout << arr[i] << " : " << &arr[i] << endl;
	}

	return 0;
}