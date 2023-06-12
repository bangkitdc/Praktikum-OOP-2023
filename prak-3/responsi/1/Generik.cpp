#include <iostream>
using namespace std;

template <class T>
void func(T t1, T t2) {
	cout << "Masukan Anda: " << t1 << " dan " << t2 << ", memiliki tipe yang sama" << endl;
}

template <class X, class Y>
void func(X x, Y y) {
	cout << "Masukan Anda: " << x << " dan " << y << ", mungkin memiliki tipe yang berbeda" << endl;
}

template<>
void func<char, int>(char c, int a) {
	for (int i = 0; i < a; i ++) {
		cout << c << endl;
	}
}
