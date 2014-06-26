#include <iostream>
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
int render(int flooring[60][70], int& xcheck, int& ycheck, int xcoord, int ycoord, int lvl, bool& sparky, int& loop,bool looper,int& loopy){
	bool spark = true;
	if (looper){
		loopy++;
	}
	 if (flooring[ycheck][xcheck] == AIRSPC){
		 std::cout << "\033[0;30;40m" << "_";
		 xcheck = xcheck + 1;
	 }
	 else if (ycheck == ycoord && xcheck == xcoord){
		 if (flooring[ycheck][xcheck] == BUPBRD){
			 std::cout << "\033[0;34;40m" << "I";
			 xcheck = xcheck + 1;
		 }
		 else{
			 std::cout << "\033[0;34;40m" << "@";
			 xcheck = xcheck + 1;
		 }
	 }
	 else if (flooring[ycheck][xcheck] == FLOORT){
		 std::cout << "\033[0;37;40m" << ",";
		 xcheck = xcheck + 1;
	 }
	 else if (flooring[ycheck][xcheck] == STAIRS){
		 std::cout << "\033[0;33;40m" << "L";
		 xcheck = xcheck + 1;
	 }
	 else if (flooring[ycheck][xcheck] == LINBRK){
		 std::cout << std::endl;
		 xcheck = 0;
		 ycheck = ycheck + 1;
	 }
	 else if (flooring[ycheck][xcheck] == WALLTL){
		 std::cout << "\033[0;37;40m" << "E";
		 xcheck = xcheck + 1;
	 }
	 else if (flooring[ycheck][xcheck] == UPBRDG){
		 std::cout << "\033[0;36;40m" << "I";
		 xcheck = xcheck + 1;
	 }
	 else if (flooring[ycheck][xcheck] == LVLEND){
		 std::cout << std::endl;
		 xcheck = 0;
		 ycheck = 0;
		 sparky = false;
		 spark = false;
		 loop = 0;
		 if (looper){ std::cout << loopy<<std::endl; }
	 }
	 else{
		 spark = false;
	 }
	 return 0;
 }
	