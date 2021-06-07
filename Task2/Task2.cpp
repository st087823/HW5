#include<iostream>
#include<fstream>
#include<clocale>

using namespace std;

bool isRussianVowel(char symbol)
{
	return symbol == 'À' || symbol == 'à' ||
		symbol == 'Å' || symbol == 'å' ||
		symbol == '¨' || symbol == '¸' ||
		symbol == 'È' || symbol == 'è' ||
		symbol == 'Î' || symbol == 'î' ||
		symbol == 'Ó' || symbol == 'ó' ||
		symbol == 'Û' || symbol == 'û' ||
		symbol == 'Ý' || symbol == 'ý' ||
		symbol == 'Þ' || symbol == 'þ' ||
		symbol == 'ß' || symbol == 'ÿ';
}
bool isEnglishVowel(char symbol)
{
	return symbol == 'A' || symbol == 'a' ||
		symbol == 'E' || symbol == 'e' ||
		symbol == 'I' || symbol == 'i' ||
		symbol == 'O' || symbol == 'o' ||
		symbol == 'U' || symbol == 'u' ||
		symbol == 'Y' || symbol == 'y';
}


int main()
{
	setlocale(LC_ALL, "Russian");
	const int n = 32;
	char a[n] = { "Êàê õîðîøî áûòü ïðîãðàììèñòîì" };
	for (int i = 0; i < n; cout << a[i] << (i == n - 1 ? '\n' : ' '), ++i);

	fstream fbin;
	fbin.open("in.bin", ios::binary | ios::out);
	if (!fbin)
	{
		cout << "Íå îòêðûëñÿ" << endl;
	}
	fbin.write(a, sizeof(a));
	fbin.close();

	char b = 0;

	fbin.open("in.bin", ios::binary | ios::in | ios::out);
	while (!fbin.eof())
	{
		fbin.read((char*)&b, sizeof(char));
		cout << "read : " << b;
		if (isRussianVowel(b))
		{
			fbin.seekg(-(int)sizeof(char), ios::cur);
			b = '#';
			fbin.write((char*)&b, sizeof(char));
			cout << " changed to #";
			fbin.seekg(fbin.tellg(), ios::beg);
		}
		else if (isEnglishVowel(b))
		{
			fbin.seekg(-(int)sizeof(char), ios::cur);
			b = '#';
			fbin.write((char*)&b, sizeof(char));
			cout << " changed to #";
			fbin.seekg(fbin.tellg(), ios::beg);
		}
		cout << endl;
	}
	fbin.close();

	fbin.open("in.bin", ios::in);
	fbin.read((char*)&a, sizeof(a));
	for (int i = 0; i < n; cout << a[i] << (i == n - 1 ? '\n' : ' '), ++i);
	fbin.close();

	return 0;
}