#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
const float PI = 3.141592;
int main() {
	char header[12];
	int* n;
	n = (int*)header;
	*n = 500;
	float* f;
	f = (float*)(header + 4);
	*f = 1000;
	short* a;
	a = (short*)(header + 8);
	*a = 500;
	short* p;
	p = (short*)(header + 10);
	*p = 12;
	float dt = 1. / f[0] / 20.0;
	short* data;
	data = new short[*n];

	ofstream xx("a.dat", ios::binary | ios::out);
	if (!xx) return 666;
	xx.write(header, 12 * sizeof(char));

	for (int i = 0; i < n[0]; i++) {
		data[i] = (short)(a[0] * sin(2.0 * PI * f[0] * i * dt));
	}
	xx.write((char*)data, n[0] * sizeof(short));


	xx.close();

	ifstream xxx("a.dat", ios::binary | ios::in);
	if (!xxx) {
		cout << "can't open the file." << endl;
		return 666;
	}
	xxx.read(header, 12 * sizeof(char));
	*f = 700.0;
	for (int i = 0; i < n[0]; i++) {
		data[i] = (short)(a[0] * sin(2.0 * PI * f[0] * i * dt));
	}
	xxx.close();

	ofstream a1("b.dat", ios::binary | ios::out);
	if (!a1) {
		cout << "can't open the file." << endl;
		return 666;
	}
	a1.write(header, 12 * sizeof(char));
	a1.write((char*)data, n[0] * sizeof(short));
	a1.close();

	ifstream a2("a.dat", ios::binary | ios::in);
	a2.read(header, 12 * sizeof(char));
	short* data1; 
	data1 = new short[*n];
	a2.read((char*)data1, n[0] * sizeof(short));
	a2.close();

	ifstream a3("b.dat", ios::binary | ios::in);
	a3.read(header, 12 * sizeof(char));
	short* data2;
	data2 = new short[*n];
	a3.read((char*)data2, n[0] * sizeof(short));
	a3.close();

	ofstream a4("c.txt");
	if (!a4) {
		cout << "can't open the file." << endl;
		return 666;
	}
	for (int i = 0; i < n[0]; i++) {
		a4 << i * dt << " " << data1[i] << " " << data2[i] << endl;
	}
	a4.close();
}