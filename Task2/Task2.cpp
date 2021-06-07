#include<iostream>
#include<fstream>
#include<clocale>

using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	const int n = 16;
	char a[16] = { "Íåèí ÷¸áë, ðòáëèí" };

	fstream fbin;

	fbin.open("in.bin", ios::binary | ios::out);
	char d = 0;

	if (!fbin)
	{
		cout << "Íå îòêðûòü" << endl;
	}
	fbin.write(a, sizeof(a));
	fbin.close();

	fbin.open("in.bin", ios::binary | ios::in | ios::out);
	while (!fbin.eof())
	{
		fbin.read((char*)&d, sizeof(char));
		cout << "read ";
		cout << d << endl;
		if (d == '¸' || d == 'û' || d == 'ý' || d == 'ó' || d == 'è' || d == 'î' || d == 'ÿ' || d == 'þ' || d == 'à' || d == 'å')
		{
			fbin.seekg(-(int)sizeof(char), ios::cur);
			d = '#';
			fbin.write((char*)&d, sizeof(char));
			fbin.seekg(fbin.tellg(), ios::beg);
		}
		cout << endl;
	}
	fbin.close();

	fbin.open("in.bin", ios::in);
	while (!fbin.eof())
	{
		fbin.read((char*)&d, sizeof(char));
		cout << d;
	}

	cout << endl;
	fbin.close();

	return 0;
}