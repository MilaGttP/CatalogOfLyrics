
#include "Includes.h";
#include "Commands.h"
#include "Func.h";
#include "TestingData.h";
#include "Entering.h";
#include "FileIO.h";
#include "FuncWithEntering.h";

using namespace std;

void ShowText()
{
	size_t num = EnterNumber("\tНомер записи", 1, (int)Getlenght());
	Song* p = ElementAt(num - 1);

	system("cls");
	Out();
	OutText(p);
}


void OutObjectDetails()
{
	size_t num = EnterNumber("\tНомер записи", 1, (int)Getlenght());
	Song* p = ElementAt(num - 1);
	
	system("cls");
	cout << "\n";
	Print(cout, p);
}


void Out()
{
	if (Empty())
		cout << "Список песен пуст! \n";

	else
	{
		cout << "Список песен: \n\n";

		cout << left << setw(2) << "№"
			<< setw(35) << "Название песни"
			<< setw(25) << "Автор"
			<< setw(5) << "Год\n";

		cout << setfill('=') << setw(75) << '=' << setfill(' ') << endl;

		for (size_t i = 0; i < Getlenght(); i++)
			OutObject(ElementAt(i), i + 1);
	}
}


void CreateTestingData()
{
	AddRange(testingArr, TEST_ARR_SIZE);
}


void AddFromConsole()
{
	Add(AddSongFromConsole());
}


void OutAllInfo()
{
	system("cls");
	cout << "\n\tИнформация о песнях: \n\n";
	Print(cout);
}



void EditText()
{
	size_t num = EnterNumber("\tНомер записи", 1, (int)Getlenght());
	Song* p = ElementAt(num - 1);

	Edit(p);
}


void Delete()
{
	int num = EnterNumber("\tНомер записи", 1, (int)Getlenght());
	DeleteAt(num - 1);
}


static char startName[64];
static char startWord[64];

bool SelectByStartName(Song* pObj)
{
	return strstr(pObj->Author, startName) == pObj->Author;
}


bool SelectByStartWord(Song* pObj)
{
	return strstr(pObj->Name, startWord) == pObj->Name
		|| strstr(pObj->Text, startWord) == pObj->Text;
}


void FilterByAuthor()
{
	system("cls");
	Out();

	cout << "\n\tНачало имени автора: ";
	char buff[64];
	cin.getline(startName, sizeof startName);
	cout << "\n";
	Filter(SelectByStartName);
}


void FilterByWord()
{
	system("cls");
	Out();

	cout << "\n\tИскомое слово: ";
	char buff[64];
	cin.getline(startWord, sizeof startWord);
	cout << "\n";
	Filter(SelectByStartWord);
}


char textFileName[_MAX_FNAME] = "Songs.txt";

char* InputFileName(const char* defaultName) 
{
	static char fName[_MAX_FNAME];
	cout << "\tВведите имя файла (" << defaultName << "): ";
	cin.getline(fName, _MAX_PATH);

	if (fName[0] == '\0')
		strcpy(fName, defaultName);

	else if (strstr(fName, ".txt") == nullptr) 
		strcat(fName, ".txt");

	return fName;
}

void SaveAsText() 
{
	char* fName = InputFileName(textFileName);
	SaveAsText(fName);
}

void LoadFromText() 
{
	char* fName = InputFileName(textFileName);
	LoadFromText(fName);
}