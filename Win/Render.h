#include <iostream>
#include <windows.h>
using namespace std;

enum Color { DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE };
void SetColor(Color c){
	HANDLE hCon = NULL;

		if (hCon == NULL){
			hCon = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hCon, c);
	}
}
enum TILENAME{
	WALLTL = 1,
	FLOORT = 2,
	STAIRS = 3,
	AIRSPC = 4,
	LINBRK = 5,
	LVLEND = 7,
	DYNAMC = 8,
	HORBRD = 9,
	BHORBD = 10,
	UPBRDG = 11,
	BUPBRD = 12,
};
int debugrender(int arr[60][70], int& xdcheck, int& ydcheck){
	bool spark = true;
	while (spark){
		if (arr[ydcheck][xdcheck] == LVLEND){
			cout << LVLEND << endl;
			xdcheck = 0;
			ydcheck = 0;
			spark = false;
		}
		else if (arr[ydcheck][xdcheck] == LINBRK){
			cout << LINBRK << endl;
			xdcheck = 0;
			ydcheck = ydcheck + 1;
		}
		else{
			cout << arr[ydcheck][xdcheck];
			xdcheck = xdcheck + 1;
		}
	}
	return 0;
}
int render(int flooring[60][70], int& xcheck, int& ycheck, int xcoord, int ycoord, int lvl, bool& sparky, int& loop){
	bool spark = true;
	while (spark){
			if (flooring[ycheck][xcheck] == AIRSPC){
				SetColor(DARKGRAY);
				cout << "_";
				xcheck = xcheck + 1;
			}
			else if (ycheck == ycoord && xcheck == xcoord){
				if (flooring[ycheck][xcheck] == BUPBRD){
					SetColor(BLUE);
					cout << "I";
					xcheck = xcheck + 1;
				}
				else{
					SetColor(BLUE);
					cout << "@";
					xcheck = xcheck + 1;
				}
			}
			else if (flooring[ycheck][xcheck] == FLOORT){
				SetColor(DARKGRAY);
				cout << ",";
				xcheck = xcheck + 1;
			}
			else if (flooring[ycheck][xcheck] == STAIRS){
				SetColor(YELLOW);
				cout << "L";
				xcheck = xcheck + 1;
			}
			else if (flooring[ycheck][xcheck] == LINBRK){
				cout << endl;
				xcheck = 0;
				ycheck = ycheck + 1;
			}
			else if (flooring[ycheck][xcheck] == WALLTL){
				SetColor(WHITE);
				cout << "E";
				xcheck = xcheck + 1;
			}
			else if (flooring[ycheck][xcheck] == UPBRDG){
				SetColor(TEAL);
				cout << "I";
				xcheck = xcheck + 1;
			}
			else if (flooring[ycheck][xcheck] == LVLEND){
				cout << endl;
				xcheck = 0;
				ycheck = 0;
				sparky = false;
				spark = false;
				loop = 0;
			}
			else{
				spark = false;
			}
		}
	return 0;
}