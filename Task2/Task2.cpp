#include<iostream>
#include<fstream>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	int n = 16;
	char a[16] = { "Íåèí ÷¸áë, ðòáëèí" };
	fstream fbin;
	fbin.open("in.bin", ios::binary | ios::out);
	char d = '0';

	if (!fbin)
	{
		cout << "не найден файл! " << endl;
	}
	fbin.write(a, sizeof(a));
	fbin.close();

	while (!fbin.eof())
	{
		fbin.read((char*)&d, sizeof(char));
		cout << d;
	}
	fbin.close();
	fbin.open("in.bin", ios::binary | ios::in | ios::out);
	while (!fbin.eof())
	{
		fbin.read((char*)&d, sizeof(char));
		cout << "считывай ";
		cout << d << endl;
		if (d == 'A' || d == 'E' || d == 'I' || d == 'O' || d == 'Y' || d == 'U' || d == 'a' || d == 'e' || d == 'i' || d == 'o' || d == 'u' || d == 'y')
		{
			fbin.seekg(-(int)sizeof(char), ios::cur);
			d = '#';
			fbin.write((char*)&d, sizeof(char));
			fbin.seekg(fbin.tellg(), ios::beg);
		}
	}
	cout << endl;
	fbin.close();

	fbin.open("in.bin", ios::in);
	while (fbin.read((char*)&d, sizeof(char)))
	{
		cout << d;
	}
	fbin.close();

	return 0;
}