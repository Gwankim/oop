#include <iostream>
#include<fstream>
#include<cmath>
using namespace std;
const float pi = 3.141592 ;
int main() {
	double t, T, dt;
	//진동수 = 110hz로 설정
	T = 20.0 / 110.0;
	dt = 1 / 110.0 / 20.0;
	ofstream func("star.txt");
	if (!func) {
		cout << "can't make text file star." << endl;
		return 1;
	}

	for (t = 0; t < T;  t += dt) {
		func << 5 * cos(2 * 2 * pi * 110 * t) + 2 * cos(3 * 2 * pi * 110 * t) << " " << 2 * sin(3 * 2 * pi * 110 * t) - 5 * sin(2 * 2 * pi * 110 * t) << endl;
	}
	func.close();
	return 2;
}