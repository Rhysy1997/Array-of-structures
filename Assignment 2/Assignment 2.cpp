// Assignment 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"	
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <ctype.h>
#include <fstream>
#include <Windows.h>

using namespace std;

//Struct ie Record of Painting Details
struct Painting
{
	int paintingNo;
	string title;
	string artist;
	char genre;
	int cost;
	int commission;
};

//Prototypes - common functions
void message(char mess[], int col, int row);
char again(int col, int row);
void clearLine(int col, int row);
int  getOption(int c, int r, int min, int max);
void gotoXY(short x, short y);
void pressKey(int col, int row);
void PaintingHeadings(int row);
void printRecord(Painting aPainting, int row);

//Prototypes - menus
void mainMenu();
void displayOptions();
void searchMenu();
void displayMenu(Painting paintings[], int size);
void updateMenu();

//Prototypes - menu process functions
int createArray(struct Painting paintings[]);
void addPainting(struct Painting paintings[], int size);
void displayPainting(Painting paintings[], int size);
void displayPaintingByGenre(Painting paintings[], int size);
void searchPaintingByNo(Painting paintings[], int size);
void searchPaintingByTitle(Painting paintings[], int size);
void searchPaintingByArtist(Painting paintings[], int size);
void searchPaintingByGenre(Painting paintings[], int size);
void searchPaintingByCost(Painting paintings[], int size);
void displayPaintingByComm(Painting paintings[], int size);
void updatePainting(Painting paintings[], int size);

//Prototypes - validation 
int validInt(int min,int max);
string validString(int min, int max);
char validChar();

char pound = 156;
char percentage = 37;

int _tmain(int argc, _TCHAR* argv[])
{
	char tlc = 201; // Top left corner.
	char blc = 200; // Bottom left corner.
	char sl = 205; // Straightlines.
	char trc = 187; // Top right corner.
	char brc = 188; // Bottom right corner.
	char down = 186; // Down
	char topt = 203; // Top T piece.
	char bmt = 202; // Bottom T piece. 
	char lsg = 204; // Left T piece.
	char mid = 206; // Middle piece. 
	char ssl = 196; // single staight T piece.
	char rsd = 185; // Right T piece. 

	system("Color 9C");

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	gotoXY(5, 4);
	cout << "\n             **************************";
	cout << "\n          .*##*:*####***:::**###*:######*.";
	cout << "\n         *##: .###*           *######:, ##*";
	cout << "\n       *##:  :####:             *####*.  :##:";
	cout << "\n        *##,:########**********:,       :##:";
	cout << "\n         .#########################*,  *#*";
	SetConsoleTextAttribute(hConsole, 0x9E);
	cout << "\n           *#########################*##:";
	cout << "\n             *##,        ..,,::**#####:";
	cout << "\n              ,##*,*****,        *##*";
	cout << "\n                *#########*########:";
	cout << "\n                  *##*:*******###*";
	cout << "\n                   .##*.    ,##*";
	cout << "\n                     :##*  *##,";
	cout << "\n                       *####:\t\tBy Rhys Donaghey";
	cout << "\n                         :,\t\tPress any key to continue...";

	gotoXY(49, 5);
	cout << "Assignment 2 Q1\n";
	gotoXY(49, 6);
	cout << "This Program will\n";
	gotoXY(49, 7);
	cout << "demonstrate the\n";
	gotoXY(49, 8);
	cout << "uses of arrays of\n";
	gotoXY(49, 9);
	cout << "structures.\n";
	


	SetConsoleTextAttribute(hConsole, 0x9F);
	gotoXY(2, 2);
	cout << tlc;
	cout << sl << sl << sl << sl << sl << sl << sl << sl << sl << sl;
	cout << sl << sl << sl << sl << sl << sl << sl << sl << sl << sl;
	cout << sl << sl << sl << sl << sl << sl << sl << sl << sl << sl;
	cout << sl << sl << sl << sl << sl << sl << sl << sl << sl << sl;
	cout << sl << sl << sl << sl << sl << sl << sl << sl << sl << sl;
	cout << sl << sl << sl << sl << sl << sl << sl << sl << sl << sl;
	cout << sl << sl << sl << sl << sl << sl << sl << sl << sl << sl;
	cout << sl << sl << sl << sl;
	cout << trc;

	gotoXY(77, 3);
	cout << down;
	gotoXY(77, 4);
	cout << down;
	gotoXY(77, 5);
	cout << down;
	gotoXY(77, 6);
	cout << down;
	gotoXY(77, 7);
	cout << down;
	gotoXY(77, 8);
	cout << down;
	gotoXY(77, 9);
	cout << down;
	gotoXY(77, 10);
	cout << down;
	gotoXY(77, 11);
	cout << down;
	gotoXY(77, 12);
	cout << down;
	gotoXY(77, 13);
	cout << down;
	gotoXY(77, 14);
	cout << down;
	gotoXY(77, 15);
	cout << down;
	gotoXY(77, 16);
	cout << down;
	gotoXY(77, 17);
	cout << down;
	gotoXY(77, 18);
	cout << down;
	gotoXY(77, 19);
	cout << down;
	gotoXY(77, 20);
	cout << down;
	gotoXY(77, 21);
	cout << down;
	gotoXY(77, 22);
	cout << brc;

	gotoXY(2, 3);
	cout << down;
	gotoXY(2, 4);
	cout << down;
	gotoXY(2, 5);
	cout << down;
	gotoXY(2, 6);
	cout << down;
	gotoXY(2, 7);
	cout << down;
	gotoXY(2, 8);
	cout << down;
	gotoXY(2, 9);
	cout << down;
	gotoXY(2, 10);
	cout << down;
	gotoXY(2, 11);
	cout << down;
	gotoXY(2, 12);
	cout << down;
	gotoXY(2, 13);
	cout << down;
	gotoXY(2, 14);
	cout << down;
	gotoXY(2, 15);
	cout << down;
	gotoXY(2, 16);
	cout << down;
	gotoXY(2, 17);
	cout << down;
	gotoXY(2, 18);
	cout << down;
	gotoXY(2, 19);
	cout << down;
	gotoXY(2, 20);
	cout << down;
	gotoXY(2, 21);
	cout << down;
	gotoXY(2, 22);
	cout << blc;

	cout << sl << sl << sl << sl << sl << sl << sl << sl << sl << sl;
	cout << sl << sl << sl << sl << sl << sl << sl << sl << sl << sl;
	cout << sl << sl << sl << sl << sl << sl << sl << sl << sl << sl;
	cout << sl << sl << sl << sl << sl << sl << sl << sl << sl << sl;
	cout << sl << sl << sl << sl << sl << sl << sl << sl << sl << sl;
	cout << sl << sl << sl << sl << sl << sl << sl << sl << sl << sl;
	cout << sl << sl << sl << sl << sl << sl << sl << sl << sl << sl;
	cout << sl << sl << sl << sl;

	_getch();
	system("cls");

	int mOpt = 0, dOpt = 0, sOpt = 0, rOpt = 0, size = 0;
	Painting paintings[50];


	size = createArray(paintings);

	do
	{
		mainMenu();

		mOpt = getOption(45, 18, 1, 5);

		switch (mOpt)
		{
		case 1:
			addPainting(paintings, size);
			size++;
			break;
		case 2:
			displayMenu(paintings, size);
			break;
		case 3:
			do
			{
				searchMenu();
				sOpt = getOption(45, 19, 1, 6);

				switch (sOpt)
				{
				case 1:
					searchPaintingByNo(paintings, size);
					break;
				case 2:
					searchPaintingByTitle(paintings, size);
					break;
				case 3:
					searchPaintingByArtist(paintings, size);
					break;
				case 4:
					searchPaintingByGenre(paintings, size);
					break;
				case 5:
					searchPaintingByCost(paintings, size);
					break;
				}
			} while (sOpt != 6);
			break;
		case 4:
			updatePainting(paintings, size);
			break;
		}
	} while (mOpt != 5);

	return 0;
}

int createArray(struct Painting paintings[])
{
	//Existing Painting Details
	paintings[0].paintingNo = 10000; paintings[0].title = "Italian Landscape"; paintings[0].artist = "John Armleder";
	paintings[0].cost = 1250; paintings[0].genre = 'A'; paintings[0].commission = 15;

	paintings[1].paintingNo = 10001; paintings[1].title = "A Basket of Roses"; paintings[1].artist = "Andy Morris";
	paintings[1].cost = 750; paintings[1].genre = 'F'; paintings[1].commission = 25;

	paintings[2].paintingNo = 10002; paintings[2].title = "Frozen River"; paintings[2].artist = "Anna McCarthy";
	paintings[2].cost = 1500; paintings[2].genre = 'A'; paintings[2].commission = 18;

	paintings[3].paintingNo = 10003; paintings[3].title = "Spinning Wheel"; paintings[3].artist = "Elizabeth Murray";
	paintings[3].cost = 650; paintings[3].genre = 'W'; paintings[3].commission = 15;

	paintings[4].paintingNo = 10004; paintings[4].title = "Evening Sunset"; paintings[4].artist = "Edward Allington";
	paintings[4].cost = 2795; paintings[4].genre = 'O'; paintings[4].commission = 10;

	paintings[5].paintingNo = 10005; paintings[5].title = "Wolfgang"; paintings[5].artist = "Bruce Nichols";
	paintings[5].cost = 3500; paintings[5].genre = 'A'; paintings[5].commission = 20;

	paintings[6].paintingNo = 10006; paintings[6].title = "Ace of Clubs"; paintings[6].artist = "Bansky";
	paintings[6].cost = 10500; paintings[6].genre = 'F'; paintings[6].commission = 15;

	paintings[7].paintingNo = 10007; paintings[7].title = "The Hague"; paintings[7].artist = "Adrian Piper";
	paintings[7].cost = 8650; paintings[7].genre = 'A'; paintings[7].commission = 30;

	paintings[8].paintingNo = 10008; paintings[8].title = "Woody Landscape"; paintings[8].artist = "Mark Lewis";
	paintings[8].cost = 2495; paintings[8].genre = 'O'; paintings[8].commission = 25;

	paintings[9].paintingNo = 10009; paintings[9].title = "Portrait of a Man"; paintings[9].artist = "Bansky";
	paintings[9].cost = 15000; paintings[9].genre = 'O'; paintings[9].commission = 10;

	paintings[10].paintingNo = 10010; paintings[10].title = "A View of Spain"; paintings[10].artist = "Anna McCarthy";
	paintings[10].cost = 1995; paintings[10].genre = 'A'; paintings[10].commission = 12;

	paintings[11].paintingNo = 10011; paintings[11].title = "Black & White Cow"; paintings[11].artist = "Suzanne Lacy";
	paintings[11].cost = 3600; paintings[11].genre = 'W'; paintings[11].commission = 18;

	paintings[12].paintingNo = 10012; paintings[12].title = "The Walls of Rome"; paintings[12].artist = "Steven Pippin";
	paintings[12].cost = 5000; paintings[12].genre = 'F'; paintings[12].commission = 20;

	paintings[13].paintingNo = 10013; paintings[13].title = "Flowers in a Vase"; paintings[13].artist = "Zoe Leonard";
	paintings[13].cost = 9500; paintings[13].genre = 'A'; paintings[13].commission = 15;

	paintings[14].paintingNo = 10014; paintings[14].title = "Mousetrap"; paintings[14].artist = "Bansky";
	paintings[14].cost = 14000; paintings[14].genre = 'A'; paintings[14].commission = 10;

	paintings[15].paintingNo = 10015; paintings[15].title = "Summer Skies"; paintings[15].artist = "Elizabeth White";
	paintings[15].cost = 12500; paintings[15].genre = 'W'; paintings[15].commission = 25;

	paintings[16].paintingNo = 10016; paintings[16].title = "Robin's Flight"; paintings[16].artist = "Mark Lewis";
	paintings[16].cost = 7500; paintings[16].genre = 'O'; paintings[16].commission = 30;

	paintings[17].paintingNo = 10017; paintings[17].title = "Sunset by the Water"; paintings[17].artist = "Larry Bell";
	paintings[17].cost = 900; paintings[17].genre = 'F'; paintings[17].commission = 35;

	paintings[18].paintingNo = 10018; paintings[18].title = "The Shared Moon"; paintings[18].artist = "Zoe Leonard";
	paintings[18].cost = 3595; paintings[18].genre = 'G'; paintings[18].commission = 15;

	paintings[19].paintingNo = 10019; paintings[19].title = "Red Socks"; paintings[19].artist = "Sarah Lucas";
	paintings[19].cost = 6000; paintings[19].genre = 'A'; paintings[19].commission = 25;

	paintings[20].paintingNo = 10020; paintings[20].title = "Fairies in the Garden"; paintings[20].artist = "Suzanne Lacy";
	paintings[20].cost = 800; paintings[20].genre = 'W'; paintings[20].commission = 20;

	paintings[21].paintingNo = 10021; paintings[21].title = "Fruit Bowl"; paintings[21].artist = "Larry Bell";
	paintings[21].cost = 400; paintings[21].genre = 'W'; paintings[21].commission = 30;

	paintings[22].paintingNo = 10022; paintings[22].title = "Broken Window"; paintings[22].artist = "Mark Lewis";
	paintings[22].cost = 1650; paintings[22].genre = 'O'; paintings[22].commission = 35;

	paintings[23].paintingNo = 10023; paintings[23].title = "Brothers"; paintings[23].artist = "David Hall";
	paintings[23].cost = 4320; paintings[23].genre = 'O'; paintings[23].commission = 12;

	paintings[24].paintingNo = 10024; paintings[24].title = "Self Portrait"; paintings[24].artist = "Gary Hill";
	paintings[24].cost = 2100; paintings[24].genre = 'F'; paintings[24].commission = 15;

	paintings[25].paintingNo = 10025; paintings[25].title = "Mini Sunflowers"; paintings[25].artist = "John Collishaw";
	paintings[25].cost = 8500; paintings[25].genre = 'G'; paintings[25].commission = 30;

	paintings[26].paintingNo = 10026; paintings[26].title = "Supper in the Winter"; paintings[26].artist = "Christine Borland";
	paintings[26].cost = 3600;  paintings[26].genre = 'W'; paintings[26].commission = 25;

	paintings[27].paintingNo = 10027; paintings[27].title = "Music"; paintings[27].artist = "Andy Gray";
	paintings[27].cost = 995; paintings[27].genre = 'A'; paintings[27].commission = 35;

	paintings[28].paintingNo = 10028; paintings[28].title = "Venus"; paintings[28].artist = "Anthony Gormley";
	paintings[28].cost = 1875; paintings[28].genre = 'A'; paintings[28].commission = 30;

	paintings[29].paintingNo = 10029; paintings[29].title = "The Black Hole"; paintings[29].artist = "John Chamberlain";
	paintings[29].cost = 3750; paintings[29].genre = 'G'; paintings[29].commission = 15;

	paintings[30].paintingNo = 10030; paintings[30].title = "Science"; paintings[30].artist = "Christine Borland";
	paintings[30].cost = 6475; paintings[30].genre = 'O'; paintings[30].commission = 25;

	return 31;
}

void addPainting(struct Painting paintings[], int size)
{
	system("cls");
	cout << "\n\n\tAdd Painting";
	paintings[size].paintingNo = paintings[size - 1].paintingNo + 1;

	cout << "\n\n\tPainting Number " << paintings[size].paintingNo;
	cout << "\n\n\tEnter a title for stock ";
	paintings[size].title = validString(2, 40);
	system("cls");
	cout << "\n\n\tEnter an artist ";
	paintings[size].artist = validString(2, 40);
	system("cls");
	cout << "\n\n\tEnter a cost (between 50 & 20,000)";
	paintings[size].cost = validInt(50, 20000);
	system("cls");
	cout << "\n\n\tEnter a Genre ";
	paintings[size].genre = validChar();
	system("cls");
	cout << "\n\n\tEnter a commission (between 10 & 35)";
	paintings[size].commission = validInt(10, 35);

	pressKey(8, 22);
}

void displayPainting(Painting paintings[], int size)
{
	int row = 0, rowTotal = 0;

	system("cls");
	PaintingHeadings(2);

	cout << fixed << setprecision(2);

	do
	{
		printRecord(paintings[rowTotal], row + 6);
		row++;
		rowTotal++;
		if (row % 14 == 0)
		{
			row = 0;
			pressKey(1, 22);
			system("cls");
			PaintingHeadings(2);
		}
	} while (rowTotal < size);

	pressKey(1, 22);
}

void searchPaintingByNo(Painting paintings[], int size)
{
	int row = 0, rowTotal = 0;
	int paintingNum = 0;
	system("cls");
	cout << "\n\n\tSearch Painting by Number";
	cout << "\n\n\tEnter Painting Number: ";
	cin >> paintingNum;

	cout << fixed << setprecision(2);

	do
	{
		if (paintings[rowTotal].paintingNo == paintingNum)
		{
			printRecord(paintings[rowTotal], row + 6);
			row++;
			rowTotal++;
			if (row % 14 == 0)
			{
				row = 0;
				pressKey(1, 22);
				system("cls");
				PaintingHeadings(3);
			}
		}
		else
		{
			rowTotal++;
		}
	} while (rowTotal < size);
	
	pressKey(1, 22);
}

void searchPaintingByTitle(Painting paintings[], int size)
{
	int row = 0, rowTotal = 0;
	string title, tempTitle;
	bool found = false;
	
	system("cls");
	cout << "\n\n\tSearch Painting by Title";

	title = validString(2, 40);


	for (string::size_type i = 0; i < title.length(); i++)
	{
		title[i] = toupper(title[i]);
	}

	system("cls");

	cout << fixed << setprecision(2);

	PaintingHeadings(3);
	do
	{
		tempTitle = paintings[rowTotal].title;

		for (string::size_type i = 0; i < tempTitle.length(); i++)
		{
			tempTitle[i] = toupper(tempTitle[i]);
		}

		if (tempTitle.compare(title) == 0)
		{
			printRecord(paintings[rowTotal], 6 + row);
			row++;
			rowTotal++;
			found = true;
			if (row % 14 == 0)
			{
				row = 0;
				pressKey(1, 22);
				system("cls");
				PaintingHeadings(3);
			}
		}
		else
			rowTotal++;

	} while (rowTotal < size);

	if (!found)
		cout << "\n\n\t Painting title does not exist!";
	pressKey(1, 22);
}

void searchPaintingByArtist(Painting paintings[], int size)
{
	int row = 0, rowTotal = 0;
	string artist, tempArtist;
	bool found = false;


	system("cls");
	cout << "\n\n\tSearch Painting by artist";
	
	artist = validString(2, 40);

	for (string::size_type i = 0; i < artist.length(); i++)
	{
		artist[i] = toupper(artist[i]);
	}

	system("cls");

	cout << fixed << setprecision(2);

	PaintingHeadings(3);

	do
	{
		tempArtist = paintings[rowTotal].artist;

		for (string::size_type i = 0; i < tempArtist.length(); i++)
		{
			tempArtist[i] = toupper(tempArtist[i]);
		}

		if (tempArtist.find(artist) != string::npos)
		{
			printRecord(paintings[rowTotal], 6 + row);
			row++;
			rowTotal++;
			found = true;
			if (row % 14 == 0)
			{
				row = 0;
				pressKey(1, 22);
				system("cls");
				PaintingHeadings(3);
			}
		}
		else
			rowTotal++;

	} while (rowTotal < size);

	if (!found)
		cout << "\n\n\t Painting artist does not exist!";
	pressKey(8, 22);
}
void searchPaintingByCost(Painting paintings[], int size)
{
	int row = 0, rowTotal = 0;
	int costPricePainting = 0;
	bool found = false;

	system("cls");
	cout << "\n\n\tSearch Painting by Cost (between 50 & 20,000)";
	
	costPricePainting = validInt(50,20000);

	cout << fixed << setprecision(2);
	system("cls");
	PaintingHeadings(3);
	do
	{
		if (paintings[rowTotal].cost == costPricePainting)
		{
			printRecord(paintings[rowTotal], row + 6);
			row++;
			rowTotal++;
			found = true;
			if (row % 14 == 0)
			{
				row = 0;
				pressKey(1, 22);
				system("cls");
				PaintingHeadings(3);
			}
		}
		else
		{
			rowTotal++;
		}
	} while (rowTotal < size);

	if (!found)
	{
		cout << "\n\n\n\tNo painting found";
	}

	
	pressKey(8, 22);
}

void searchPaintingByGenre(Painting paintings[], int size)
{
	int row = 0, rowTotal = 0;
	char genrePainting;

	system("cls");
	cout << "\n\n\tSearch Painting by genre";

	genrePainting = validChar();

	cout << fixed << setprecision(2);

	do
	{
		if (paintings[rowTotal].genre == toupper(genrePainting))
		{
			printRecord(paintings[rowTotal], row + 6);
			row++;
			rowTotal++;
			if (row % 14 == 0)
			{
				row = 0;
				pressKey(1, 22);
				system("cls");
				PaintingHeadings(3);
			}
		}
		else
		{
			rowTotal++;
		}
	} while (rowTotal < size);

	pressKey(8, 22);
}


void displayPaintingByComm(Painting paintings[], int size)
{
	int row = 0, rowTotal = 0;
	int commissionPainting = 0;
	bool found=false;
	system("cls");
	cout << "\n\n\tDisplay Painting by commission (between 10 & 35)";
	
	commissionPainting = validInt(10,35);

	cout << fixed << setprecision(2);

	system("cls");
	PaintingHeadings(3);
	do
	{
		if (paintings[rowTotal].commission == commissionPainting)
		{
			printRecord(paintings[rowTotal], row + 6);
			row++;
			rowTotal++;
			found = true;
			if (row % 14 == 0)
			{
				row = 0;
				pressKey(1, 22);
				system("cls");
				PaintingHeadings(3);
			}
		}
		else
		{
			rowTotal++;
		}
	} while (rowTotal < size);

	if (!found)
	{
		cout << "\n\n\n\n\tPainting not found";
	}
	
	pressKey(8, 22);
}


void updatePainting(Painting paintings[], int size)
{
	int row = 0, rowTotal = 0, uOpt, position;
	double paintingNumInput = 0.0;
	bool found = false;
	char opt;

	system("cls");
	cout << "\n\n\tEnter a painting number: ";
	cin >> paintingNumInput;
	
	system("cls");

	cout << fixed << setprecision(2);

	do
	{
		if (paintings[rowTotal].paintingNo == paintingNumInput)
		{
			PaintingHeadings(3);
			printRecord(paintings[rowTotal], 6);
			position = rowTotal;
			found = true;
		}
		else
		{
			rowTotal++;
		}
	} while (rowTotal < size && !found);

	if (!found)
	{
		cout << "\n\n\t Painting item does not exist!";
		pressKey(1, 22);
	}
	else
	{
		gotoXY(1, 20);
		cout << "\n\n\tCorrect painting item (Y\N): ";
		cin >> opt;

		if (toupper(opt) == 'Y')
		{
			do
			{
				updateMenu();
				uOpt = getOption(45, 20, 1, 6);

				system("cls");
				gotoXY(5, 3);

				switch (uOpt)
				{
				case 1:
					cout << "\n\n\tPlease enter a painting title: ";
					paintings[position].title = validString(2, 40);
					break;
				case 2:
					cout << "\n\n\tPlease enter a painting artist: ";
					paintings[position].artist = validString(2, 40);
					break;
				case 3:
					cout << "\n\n\tPlease enter a painting cost: ";
					paintings[position].cost = validInt(50, 20000);
					break;
				case 4:
					cout << "\n\n\tPlease enter a painting genre: ";
					paintings[position].genre = validChar();
					break;
				case 5:
					cout << "\n\n\tPlease enter a painting commission: ";
					paintings[position].commission = validInt(10, 35);
					break;
				}
			} while (uOpt != 6);
		}
	}

	
}

void mainMenu()
{
	system("cls");
	gotoXY(25, 4); cout << "N E W  V I S I O N  A R T S";
	gotoXY(20, 7); cout << "1. Add Painting Details";
	gotoXY(20, 9); cout << "2. Display Painting Details";
	gotoXY(20, 11); cout << "3. Search Painting Details";
	gotoXY(20, 13); cout << "4. Update Painting Details";
	gotoXY(20, 15); cout << "5. Exit";
	gotoXY(20, 18); cout << "Enter Option (1 - 5)    [_]";
}

void displayOptions()
{
	system("cls");
	gotoXY(25, 4); cout << "D I S P L A Y   M E N U";
	gotoXY(20, 7); cout << "1. Display All Paintings";
	gotoXY(20, 9); cout << "2. Display Paintings by commission";
	gotoXY(20, 11); cout << "3. Exit";
	gotoXY(20, 14); cout << "Enter Option (1 - 3)    [_]";

}

void displayMenu(Painting paintings[], int size)
{
	int dOpt;

	do
	{
		displayOptions();

		dOpt = getOption(45, 14, 1, 3);

		switch (dOpt)
		{
		case 1:
			displayPainting(paintings, size);
			break;
		case 2:
			displayPaintingByComm(paintings, size);
			break;
		}
	} while (dOpt != 3);
}

void searchMenu()
{
	system("cls");
	gotoXY(25, 3); cout << "S E A R C H   P A I N T I N G   B Y";
	gotoXY(20, 6); cout << "1. Painting No";
	gotoXY(20, 8); cout << "2. Title";
	gotoXY(20, 10); cout << "3. Artist";
	gotoXY(20, 12); cout << "4. Genre";
	gotoXY(20, 14); cout << "5. Cost";
	gotoXY(20, 16); cout << "6. Exit";
	gotoXY(20, 19); cout << "Enter Option (1 - 6)    [_]";
}

void updateMenu()
{
	system("cls");
	gotoXY(20, 4); cout << "Do you wish to update:";
	gotoXY(20, 7); cout << "1. Title";
	gotoXY(20, 9); cout << "2. Artist";
	gotoXY(20, 11); cout << "3. Genre";
	gotoXY(20, 13); cout << "4. Cost";
	gotoXY(20, 15); cout << "5. Comm";
	gotoXY(20, 17); cout << "6. Exit";
	gotoXY(20, 20); cout << "Enter Option (1 - 6)    [_]";
}

int getOption(int c, int r, int min, int max)
{
	int x;

	gotoXY(c, r);
	cin >> x;
	cin.ignore(10, '\n');
	while ((x < min) || (x > max))
	{
		message("Invalid Option", 20, 21);
		gotoXY(c - 1, r);
		cout << "[_]          ";
		gotoXY(c, r);
		cin >> x;
		cin.ignore(10, '\n');
	}
	return x;
}

void message(char mess[], int col, int row)
{
	gotoXY(col, row);
	cout << mess;
	pressKey(col, row + 2);
	clearLine(col, row);
	clearLine(col, row + 2);
}//end of message

void clearLine(int col, int row)
{
	//Used to clear prompts and user input
	gotoXY(col, row);

	for (int i = col; i <= 80; i++)
	{
		cout << " ";
	}
}

void pressKey(int col, int row)
{
	gotoXY(col, row);
	cout << "Press any key to continue...";
	_getch();
}

void gotoXY(short x, short y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

char again(int col, int row)
{
	char reply;

	do
	{
		gotoXY(col, row);
		cin >> noskipws >> reply;
		reply = toupper(reply);

		if ((reply != 'Y' && reply != 'N'))
		{
			message("Must Enter Y or N ", 5, row + 3);
			clearLine(col, row);

			cin.ignore(150, '\n');
		}

		cin.setf(ios::skipws);

	} while (reply != 'Y' && reply != 'N');

	return reply;
}

void PaintingHeadings(int row)  //output headings
{
	gotoXY(1, row); cout << "Painting";
	gotoXY(9, row); cout << "Title";
	gotoXY(38, row); cout << "Artist";
	gotoXY(58, row); cout << "Genre";
	gotoXY(66, row); cout << "Cost";
	gotoXY(74, row); cout << "Comm";
}

void printRecord(Painting paintings, int row)
{
	gotoXY(2, row); cout << paintings.paintingNo;
	gotoXY(9, row); cout << paintings.title;
	gotoXY(38, row); cout << paintings.artist;
	gotoXY(58, row); cout << right << setw(3) << paintings.genre;
	gotoXY(66, row); cout << pound << setw(5) << paintings.cost;
	gotoXY(74, row); cout << right << setw(3) << paintings.commission << percentage;

}

int validInt(int min ,int max)
{
	bool valid = false;
	int a = 0;
	int col = 8, row = 7;
	
	do
	{
		gotoXY(col, row);
		cout << "Please enter a number:";
		cin >> noskipws >> a;
		if (cin.fail())
		{
			gotoXY(col, row + 2);
			cout << "Invalid input! Please re-enter. ";
			gotoXY(col, row + 4);
			cout << "Press any key to continue...";
			_getch();
			cin.clear();
			clearLine(col, row + 2);
			clearLine(col, row + 4);
			gotoXY(col + 20, row);
			cout << "         ";
		}
		else if (a < min || a > max)
		{
			
			gotoXY(col, row + 2);
			cout << "Invalid input! Please re-enter a value between " << min << " and " << max;
			gotoXY(col, row + 4);
			cout << "Press any key to continue...";
			_getch();
			cin.clear();
			clearLine(col, row + 2);
			clearLine(col, row + 4);
			gotoXY(col + 20, row);
			cout << "         ";
			
		}
		else
		{
			valid = true;
		}
		cin.ignore(80, '\n');
	} while (!valid);
	return a;
}

string validString(int min, int max)
{
	bool valid = false;
	string s;
	int col = 8, row = 7;

	do
	{
		gotoXY(col, row);
		cout << "Please enter between " << min << " and " << max << " characters: ";
		getline(cin, s);
		
		if (s.length() < min || s.length() > max)
		{
			system("cls");
			gotoXY(col, row + 2);
			cout << "Invalid input! Please re-enter between " << min << " and " << max << " characters.";
			pressKey(col, row + 6);
			gotoXY(col + 20, row);
			cout << "                 ";
			gotoXY(col, row + 2);
			for (int i = col; i <= 80; i++)
			{
				cout << " ";
			}
			gotoXY(col, row + 6);
			for (int i = col; i <= 80; i++)
			{
				cout << " ";
			}
		}
		else
		{
			valid = true;
		}
	} while (!valid);
	return s;
}

char validChar()
{
	bool valid = false;
	char letter;
	int col = 8, row = 7;

	do
	{
		gotoXY(col, row);
		cout << "Acrylic(A)";
		cout << "\n\tOil(O)";
		cout << "\n\tWatercolour(W)";
		cout << "\n\tGouache(G)";
		cout << "\n\tFresco(F)";
		cout << "\n\tEnter a genre: ";
		cin >> letter;
		letter = toupper(letter);
		system("cls");
		PaintingHeadings(3);

		if (!(letter == 'A' || letter == 'O' || letter == 'W' || letter == 'F' || letter == 'G'))
		{
			system("cls");
			gotoXY(col, row + 2);
			cout << "Invalid input! Please re-enter a letter";
			pressKey(col, row + 6);
			gotoXY(col + 20, row);
			cout << "                 ";
			gotoXY(col, row + 2);
			for (int i = col; i <= 80; i++)
			{
				cout << " ";
			}
			gotoXY(col, row + 6);
			for (int i = col; i <= 80; i++)
			{
				cout << " ";
			}
		}
		else
		{
			valid = true;
		}
	} while (!valid);
	return letter;
}