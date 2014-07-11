#include <iostream>
#include <windows.h>

enum Color { DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE};
void SetColor(int c){
	HANDLE hCon = NULL;

		if (hCon == NULL){
			hCon = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hCon, c);
	}
}
void AdvSetColor(Color back,Color fore){
	int c;
	c = back * 16 + fore;
	SetColor(c);
}
enum TILENAME{
	WALLTL = 1, // Wall
	FLOORT = 2, // Floor
	STAIRS = 3, // Stairs
	AIRSPC = 4, // Air (or space)
	LINBRK = 5, // Line Break ( a manual /n )
	LVLEND = 7, // End Of Level
	DYNAMC = 8, // Dynamic tiles (barrels, switches & triggered walls)
	HORBRD = 9, // Horizontal bridge
	BHORBD = 10,// and when you're below it
	UPBRDG = 11,// vertical bridge
	BUPBRD = 12,// also when you're below it
	ENDGAM = 13 // doesn't work
};
int debugrender(int arr[60][70], int& xdcheck, int& ydcheck){
	bool spark = true;
	while (spark){
		if (arr[ydcheck][xdcheck] == LVLEND){
			std::cout << LVLEND << std::endl;
			xdcheck = 0;
			ydcheck = 0;
			spark = false;
		}
		else if (arr[ydcheck][xdcheck] == LINBRK){
			std::cout << LINBRK << std::endl;
			xdcheck = 0;
			ydcheck = ydcheck + 1;
		}
		else{
			std::cout << arr[ydcheck][xdcheck];
			xdcheck = xdcheck + 1;
		}
	}
	return 0;
}
/* flooring is just tiles
   [y|x]check is for printing
   [y|x]coord is player coordinates
   sparky is to break the rendering loop
   loop is to make sure the level isn't breaking the limits of the array
   (therefore, saying something isn't right)
   looper is for debugging
   [x|y]ins is for inspecting*/
int render(int flooring[60][70], int& xcheck, int& ycheck, int xcoord, int ycoord,
	bool& sparky, int& loop, bool looper, int& loopy, int xins, int yins
	){
	bool spark = true;
	while (spark){
		if (looper){
			loopy++;
		} if (xcoord == xins && ycoord == yins && xins >= 0 && yins >= 0){
			if (flooring[ycheck][xcheck] == AIRSPC){
				AdvSetColor(DARKBLUE, DARKGRAY);
				std::cout << "_";
				xcheck = xcheck + 1;
			}
			else if (ycheck == ycoord && xcheck == xcoord){
				if (flooring[ycheck][xcheck] == BUPBRD){
					AdvSetColor(DARKBLUE,BLUE);
					std::cout << "I";
					xcheck = xcheck + 1;
				}
				else{
					AdvSetColor(DARKBLUE,BLUE);
					std::cout << "@";
					xcheck = xcheck + 1;
				}
			}
			else if (flooring[ycheck][xcheck] == FLOORT){
				AdvSetColor(DARKBLUE,DARKGRAY);
				std::cout << ",";
				xcheck = xcheck + 1;
			}
			else if (flooring[ycheck][xcheck] == STAIRS){
				AdvSetColor(DARKBLUE,YELLOW);
				std::cout << "L";
				xcheck = xcheck + 1;
			}
			else if (flooring[ycheck][xcheck] == WALLTL){
				AdvSetColor(DARKBLUE,WHITE);
				std::cout << "E";
				xcheck = xcheck + 1;
			}
			else if (flooring[ycheck][xcheck] == UPBRDG){
				AdvSetColor(DARKBLUE,TEAL);
				std::cout << "I";
				xcheck = xcheck + 1;
			}
			else{
				spark = false;
			}
		}
		else{
			if (flooring[ycheck][xcheck] == AIRSPC){
				SetColor(DARKGRAY);
				std::cout << "_";
				xcheck = xcheck + 1;
			}
			else if (ycheck == ycoord && xcheck == xcoord){
				if (flooring[ycheck][xcheck] == BUPBRD){
					SetColor(BLUE);
					std::cout << "I";
					xcheck = xcheck + 1;
				}
				else{
					SetColor(BLUE);
					std::cout << "@";
					xcheck = xcheck + 1;
				}
			}
			else if (flooring[ycheck][xcheck] == FLOORT){
				SetColor(DARKGRAY);
				std::cout << ",";
				xcheck = xcheck + 1;
			}
			else if (flooring[ycheck][xcheck] == STAIRS){
				SetColor(YELLOW);
				std::cout << "L";
				xcheck = xcheck + 1;
			}
			else if (flooring[ycheck][xcheck] == LINBRK){
				std::cout << std::endl;
				xcheck = 0;
				ycheck = ycheck + 1;
			}
			else if (flooring[ycheck][xcheck] == WALLTL){
				SetColor(WHITE);
				std::cout << "E";
				xcheck = xcheck + 1;
			}
			else if (flooring[ycheck][xcheck] == UPBRDG){
				SetColor(TEAL);
				std::cout << "I";
				xcheck = xcheck + 1;
			}
			else if (flooring[ycheck][xcheck] == LVLEND){
				std::cout << std::endl;
				xcheck = 0;
				ycheck = 0;
				sparky = false;
				spark = false;
				loop = 0;
				if (looper){
					std::cout << loopy << std::endl;
				}
			}
			else{
				spark = false;
			}
		}
	}
	}
	return 0;
}