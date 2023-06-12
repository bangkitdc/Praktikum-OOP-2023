#include <iostream>
#include "exception.h"
#include "memo.h"
#include "sekretaris.h"

using namespace std;

int main() {

	Sekretaris s(50, 50);

	s.buatMemo("hai", "joli");
	s.buatMemo("apa kabar", "joli");

	s.printStatus();

	return 0;
}