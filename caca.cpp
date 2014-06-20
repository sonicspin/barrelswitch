#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int mov(int& coord, int movcoord,int checktile){
	if (checktile == 1){
		cout << "you can't do that!" << endl;
	}
	else if (checktile == 3){
		coord = movcoord;
		
	}
	else if (checktile == 2){
		coord = movcoord;

	}
	else {
		;
	}
	return 0;
}
int main() {
	enum TILENAME{
		WALLTL = 1,
		FLOORT = 2,
		STAIRS = 3,
		AIRSPC = 4,
		LINBRK = 5,
		PLAYER = 6,
		LVLEND = 7,
		HORBRD = 9,
		BHORBD = 17,
		UPBRDG = 10,
		BUPBRD = 18,
		LFTLED = 11,
		RGTLED = 12,
		DWNLED = 13,
		UPLDGE = 14,
	};
	int	tiles[4][60][70] = {
				{
					{ 1, 1, 1, 1, 1, 1, 5 },
					{ 1, 2, 2, 2, 2, 1, 5 },
					{ 1, 2, 2, 3, 2, 1, 5 },
					{ 1, 2, 2, 2, 2, 1, 5 },
					{ 1, 2, 2, 2, 2, 1, 5 },
					{ 1, 2, 2, 2, 2, 1, 5 },
					{ 1, 1, 1, 1, 1, 1, 7 }
				},
				{
					{ 1, 1, 1, 1, 1, 5 },
					{ 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 5 },
					{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 5 },
					{ 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 2, 1, 4, 4, 1, 1, 1, 1, 1, 5 },
					{ 1, 1, 1, 1, 1, 4, 4, 4, 4, 1, 2, 1, 1, 1, 1, 2, 2, 2, 1, 5 },
					{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 2, 2, 2, 2, 2, 2, 3, 2, 1, 5 },
					{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 2, 2, 2, 1, 5 },
					{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 7 }
				}, {
						{ 4, 4, 4, 1, 1, 1, 5 },
						{ 4, 4, 4, 1, 2, 1, 5 },
						{ 4, 4, 4, 1, 14, 1, 5 },
						{ 4, 4, 4, 1, 2, 1, 5 },
						{ 1, 1, 1, 1, 2, 1, 1, 1, 5 },
						{ 1, 3, 2, 2, 10, 2, 2, 1, 5 },
						{ 1, 1, 1, 1, 2, 1, 2, 1, 5 },
						{ 4, 4, 4, 1, 2, 2, 2, 1, 5 },
						{ 4, 4, 4, 1, 1, 1, 1, 1, 7 },
				}
		};
	int spawnpoint[3][2] = {
			{ 2, 5 },
			{ 2, 2 },
			{ 4, 1 }
	};
	int barrelspawn[3][2] = {
			{0,0},
			{0,0},
            {0,0}
	};
	int switchspawn[3][2]{
			{0,0},
			{0,0},
			{0,0}
	};
	cout << "size of all levels right now is " << sizeof(tiles) << " bytes" << endl;
	cout << "welcome to my game" << endl;
	cout << "WASD to move!" << endl;
	int level = 0;
	int xarraychecker = 0, yarraychecker = 0;
	bool sparker, levelindicator = false, oversparker = true, levelcomplete = false;
	while (oversparker == true){
		if (levelcomplete == true){
			level = level + 1;
			levelcomplete = false;
		}
		int xcord = spawnpoint[level][0];
		int ycord = spawnpoint[level][1];
		sparker = true;
		while (sparker == true){
			if (levelindicator == false){
				cout << "you are in level " << level << endl;
				levelindicator = true;
			}
			char movementinput = 0;
			bool tilesparker = true;
			int xchecker = xcord;
			int ychecker = ycord;
			if (tiles[level][ycord][xcord] == 3){
				cout << "you're on a staircase! write \"q\" to go up a level!" << endl;
			}
			//renderer
			while (tilesparker == true){
				if (yarraychecker == ycord && xarraychecker == xcord){
					if (tiles[level][yarraychecker][xarraychecker] == BUPBRD){
						cout << "I";
						xarraychecker = xarraychecker + 1;
					}
					else{
						cout << "@";
						xarraychecker = xarraychecker + 1;
					}
				}
				else if (tiles[level][yarraychecker][xarraychecker] == FLOORT){
					cout << ",";
					xarraychecker = xarraychecker + 1;
				}
				else if (tiles[level][yarraychecker][xarraychecker] == STAIRS){
					cout << "L";
					xarraychecker = xarraychecker + 1;
				}
				else if (tiles[level][yarraychecker][xarraychecker] == AIRSPC){
					cout << "_";
					xarraychecker = xarraychecker + 1;
				}
				else if (tiles[level][yarraychecker][xarraychecker] == LINBRK){
					cout << endl;
					xarraychecker = 0;
					yarraychecker = yarraychecker + 1;
				}
				else if (tiles[level][yarraychecker][xarraychecker] == WALLTL){
					cout << "E";
					xarraychecker = xarraychecker + 1;
				}
				else if (tiles[level][yarraychecker][xarraychecker] == UPLDGE){
					cout << "v";
					xarraychecker = xarraychecker + 1;
				}
				else if (tiles[level][yarraychecker][xarraychecker] == UPBRDG){
					cout << "I";
					xarraychecker = xarraychecker + 1;
				}
				else if (tiles[level][yarraychecker][xarraychecker] == DWNLED){
					cout << "*";
					xarraychecker = xarraychecker + 1;
				}
				else if (tiles[level][yarraychecker][xarraychecker] == LVLEND){
					cout << endl;
					xarraychecker = 0;
					yarraychecker = 0;
					tilesparker = false;
				}
				else{
					cout << "there was an error rendering this, the error tile was "
						<< tiles[level][yarraychecker][xarraychecker] << endl;
					tilesparker = false;
				}
				//end renderer
			}

			//movement
			/*
			Movement:
			w         |    a    |    s    |    d
			Upbridge  |Upbridge |Upbridge |
			Upledge   |Upledge  |         |
			*/
			cin >> movementinput;
			if (tiles[level][ycord][xcord] == 3 && movementinput == 'q'){
				levelcomplete = true;
				levelindicator = false;
				sparker = false;
			}
			else if (tiles[level][ycord][xcord] == UPBRDG){
				if (movementinput == 'd'){
					cout << "you can't do that!" << endl;
				}
				if (movementinput == 'w'){
					ychecker = ychecker - 1;
					mov(ycord, ychecker, tiles[level][ychecker][xchecker]);
					if (tiles[level][ychecker][xchecker] == UPBRDG){
						ycord = ycord - 1;
						ychecker = ycord;
					}
					else if (tiles[level][ychecker][xchecker] == UPLDGE){
						cout << "you can't do that" << endl;
					}
				}
				else if (movementinput == 's'){
					ychecker = ychecker + 1;
					mov(ycord, ychecker, tiles[level][ychecker][xchecker]);
					if (tiles[level][ychecker][xchecker] == UPLDGE){
						ycord = ycord + 1;
						ychecker = ycord;
					}
					else if (tiles[level][ychecker][xchecker] == UPBRDG){
						ycord = ycord + 1;
						ychecker = ycord;
					}
				}

				else if (movementinput == 'a'){
					cout << "you can't do that!" << endl;
				}
			}
			else if (tiles[level][ycord][xcord] == BUPBRD){
				if (movementinput == 'd'){
					xchecker = xchecker + 1;
					tiles[level][ycord][xcord] = UPBRDG;
					mov(xcord, xchecker, tiles[level][ychecker][xchecker]);
					if (tiles[level][ychecker][xchecker] == UPBRDG){
						xcord = xcord + 1;
						tiles[level][ychecker][xchecker] = BUPBRD;
						xchecker = xcord;
					}
					else if (tiles[level][ychecker][xchecker] == UPLDGE){
						xcord = xcord + 1;
						xchecker = xcord;
					}

				}
				else if (movementinput == 'w'){
					cout << "you can't do that!" << endl;
					ychecker = ycord;
				}
				else if (movementinput == 's'){
					cout << "you can't do that!" << endl;
					ychecker = ycord;
				}

				else if (movementinput == 'a'){
					xchecker = xchecker - 1;
					tiles[level][ycord][xcord] = UPBRDG;
					mov(xcord, xchecker, tiles[level][ychecker][xchecker]);
					if (tiles[level][ychecker][xchecker] == UPBRDG){
						xcord = xcord - 1;
						tiles[level][ychecker][xchecker] = BUPBRD;
						xchecker = xcord;
					}
					else if (tiles[level][ychecker][xchecker] == UPLDGE){
						xcord = xcord - 1;
						xchecker = xcord;
					}
				}
			}
				else{
					if (movementinput == 'd'){
						xchecker = xchecker + 1;
						mov(xcord, xchecker, tiles[level][ychecker][xchecker]);
						if (tiles[level][ychecker][xchecker] == UPBRDG){
							xcord = xcord + 1;
							tiles[level][ychecker][xchecker] = BUPBRD;
							xchecker = xcord;
						}
						else if (tiles[level][ychecker][xchecker] == UPLDGE){
							xcord = xcord + 1;
							xchecker = xcord;
						}

					}else if (movementinput == 'w'){
						ychecker = ychecker - 1;
						mov(ycord, ychecker, tiles[level][ychecker][xchecker]);
						if (tiles[level][ychecker][xchecker] == UPBRDG){
							ycord = ycord - 1;
							ychecker = ycord;
						}
						else if (tiles[level][ychecker][xchecker] == UPLDGE){
							cout << "you can't do that" << endl;
							ychecker = ycord;
						}
					}
					else if (movementinput == 's'){
						ychecker = ychecker + 1;
						mov(ycord, ychecker, tiles[level][ychecker][xchecker]);
						if (tiles[level][ychecker][xchecker] == UPLDGE){
							ycord = ycord + 1;
							ychecker = ycord;
						}
						else if (tiles[level][ychecker][xchecker] == UPBRDG){
							ycord = ycord + 1;
							ychecker = ycord;
						}

					}
					else if (movementinput == 'a'){
						xchecker = xchecker - 1;
						mov(xcord, xchecker, tiles[level][ychecker][xchecker]);
						if (tiles[level][ychecker][xchecker] == UPBRDG){
							xcord = xcord - 1;
							tiles[level][ychecker][xchecker] = BUPBRD;
							xchecker = xcord;
						}
						else if (tiles[level][ychecker][xchecker] == UPLDGE){
							xcord = xcord - 1;
							xchecker = xcord;
							//special case layer
						}
						//a move layer
					}
					//bridge/non bridge movement layer
				}
				//general movement
			}
			//sparker layer
		}
		//oversparker layer
	} //too many layers of indentation @_@
	//main() layer