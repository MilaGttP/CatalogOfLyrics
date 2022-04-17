
#include "Includes.h";
#include "Run.h"
#include "Entering.h";
#include "Func.h";
#include "Commands.h"
#include "FileIO.h";

using namespace std;

bool AlwaysDisplay() { return true; }
bool MinOneValue() { return Getlenght() >= 1; }
bool MinTwoValues() { return Getlenght() >= 2; }

typedef void (*Command) ();
typedef bool (*Display) ();

const size_t COMMAND_NAME_SIZE = 64;

struct CommandInfo
{
	char name[COMMAND_NAME_SIZE];
	Command command;
	Display display = AlwaysDisplay;
	bool delayResultDisplaying = false;
};

CommandInfo commandsInfo[] =
{
	{ "�����", nullptr },
	{ "�������� �������� ������", CreateTestingData, Empty },
	{ "�������� ����� ����� � �������", AddFromConsole, AlwaysDisplay },
	{ "�������� ����� ����� � �����", LoadFromText, AlwaysDisplay, true },
	{ "���������� ����� �� �����", ShowText, MinOneValue, true },
	{ "�������� �����", EditText, MinOneValue },
	{ "�������� � ������", OutObjectDetails, MinOneValue, true },
	{ "�������� � ������", OutAllInfo, MinTwoValues, true },
	{ "��������� ����� � ����", SaveAsText, MinOneValue },
	{ "���������� ��� ����� ������ ������", FilterByAuthor, MinTwoValues, true },
	{ "���������� ����� �� ���������� �����", FilterByWord, MinTwoValues, true },
	{ "�������� ��� ������", Clear, MinTwoValues },
	{ "������� �����", Delete, MinOneValue },
};

const size_t COMMANDS_COUNT = sizeof commandsInfo / sizeof(CommandInfo);

void ShowMenu()
{
	cout << "\n��������: \n\n";
	for (size_t i = 0; i < COMMANDS_COUNT; i++)
	{
		if (commandsInfo[i].display())
			cout << "\t" << i << " - " << commandsInfo[i].name << endl;
	}
}


CommandInfo EnterCommand()
{
	int index = EnterNumber("����� ��������", 0, COMMANDS_COUNT - 1);
	return commandsInfo[index];
}


void DelayDisplaying()
{
	cout << "\n\t��� ����������� ������� ����� �������...";
	_getch();
}


void Run()
{
	Load();

	while (true)
	{
		system("cls");
		Out();
		ShowMenu();
		CommandInfo commandInfo = EnterCommand();

		if (commandInfo.command == nullptr)
			return;

		commandInfo.command();

		if (commandInfo.delayResultDisplaying)
			DelayDisplaying();
	}
}