
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
	{ "Exit", nullptr },
	{ "Add test data", CreateTestingData, Empty },
	{ "Add lyrics from console", AddFromConsole, AlwaysDisplay },
	{ "Add lyrics from file", LoadFromText, AlwaysDisplay, true },
	{ "Show text", ShowText, MinOneValue, true },
	{ "Edit text", EditText, MinOneValue },
	{ "Details about the song", OutObjectDetails, MinOneValue, true },
	{ "Details about all songs", OutAllInfo, MinTwoValues, true },
	{ "Save text in file", SaveAsText, MinOneValue },
	{ "Display all songs by the same author", FilterByAuthor, MinTwoValues, true },
	{ "Display the song for the specified word", FilterByWord, MinTwoValues, true },
	{ "Clear all", Clear, MinTwoValues },
	{ "Delete song", Delete, MinOneValue },
};

const size_t COMMANDS_COUNT = sizeof commandsInfo / sizeof(CommandInfo);

void ShowMenu()
{
	cout << "\nCommands: \n\n";
	for (size_t i = 0; i < COMMANDS_COUNT; i++)
	{
		if (commandsInfo[i].display())
			cout << "\t" << i << " - " << commandsInfo[i].name << endl;
	}
}


CommandInfo EnterCommand()
{
	int index = EnterNumber("ID", 0, COMMANDS_COUNT - 1);
	return commandsInfo[index];
}


void DelayDisplaying()
{
	cout << "\n\tPress any key to continue...";
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