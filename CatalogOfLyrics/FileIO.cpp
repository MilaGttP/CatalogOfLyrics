
#include "Includes.h";
#include "FileIO.h";
#include "Func.h";
#include "FuncWithEntering.h";

using namespace std;

char binFileName[_MAX_FNAME] = "Songs.bin";

void Save()
{
	fstream stream(binFileName, ios::trunc | ios::out | ios::binary);

	if (!stream.is_open())
	{
		cout << "Ошибка открытия файла " << binFileName << " для записи\n";
		return;
	}

	for (size_t i = 0; i < Getlenght(); i++)
		stream.write((char*)ElementAt(i), sizeof(Song));

	stream.close();
}


void Load()
{
	fstream stream(binFileName, ios::in | ios::out | ios::binary);

	if (!stream.is_open())
	{
		cout << "Ошибка открытия файла " << binFileName << " для чтения\n";
		return;
	}

	while (true)
	{
		Song* p = new Song;

		if (!stream.read((char*)p, sizeof(Song)))
			break;

		Add(p);
	}

	stream.close();
}


void SaveAsText(const char* fName)
{
	ofstream fout(fName);

	if (!fout.is_open())
		return;

	Print(fout);
	fout.close();
}


void LoadFromText(const char* fName)
{
	ifstream fin(fName);

	if (!fin.is_open())
		return;

	while (!fin.eof()) 
	{
		Song* p = new Song();
		Input(fin, p);

		if (fin.fail())
			break;

		Add(p);
	}

	fin.close();
}