#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;
const float pi = 3.141592;
int main() {
	float t, dt, T;
	t = 0.0;
	dt = 1.0 / 110.0 / 30.0;
	T = 6 / 110.0;
	ofstream func("function.txt");
	if (!func) {
		cout << "can't make the text file." << endl;
		return 1;
	}
	for (t; t < T; t += dt) {
		func << t << " " << exp(-110 * t) * cos(220 * pi * t) << " " << exp(-110 * t) * sin(220 * pi * t) << endl;
	}
	func.close();
	return 2;
}