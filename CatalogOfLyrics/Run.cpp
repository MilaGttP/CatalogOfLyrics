
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
	{ "Выйти", nullptr },
	{ "Добавить тестовые данные", CreateTestingData, Empty },
	{ "Добавить текст песни с консоли", AddFromConsole, AlwaysDisplay },
	{ "Добавить текст песни с файла", LoadFromText, AlwaysDisplay, true },
	{ "Отобразить текст на экран", ShowText, MinOneValue, true },
	{ "Изменить текст", EditText, MinOneValue },
	{ "Детально о записи", OutObjectDetails, MinOneValue, true },
	{ "Детально о песнях", OutAllInfo, MinTwoValues, true },
	{ "Сохранить текст в файл", SaveAsText, MinOneValue },
	{ "Отобразить все песни одного автора", FilterByAuthor, MinTwoValues, true },
	{ "Отобразить песню по указанному слову", FilterByWord, MinTwoValues, true },
	{ "Очистить все данные", Clear, MinTwoValues },
	{ "Удалить песню", Delete, MinOneValue },
};

const size_t COMMANDS_COUNT = sizeof commandsInfo / sizeof(CommandInfo);

void ShowMenu()
{
	cout << "\nКомманды: \n\n";
	for (size_t i = 0; i < COMMANDS_COUNT; i++)
	{
		if (commandsInfo[i].display())
			cout << "\t" << i << " - " << commandsInfo[i].name << endl;
	}
}


CommandInfo EnterCommand()
{
	int index = EnterNumber("Номер комманды", 0, COMMANDS_COUNT - 1);
	return commandsInfo[index];
}


void DelayDisplaying()
{
	cout << "\n\tДля продолжения нажмите любую клавишу...";
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