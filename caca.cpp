#include <iostream>
#include <string>
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
						{ 4, 4, 4, 1, 2, 1, 5 },
						{ 4, 4, 4, 1, 2, 1, 5 },
						{ 1, 1, 1, 1, 2, 1, 1, 1, 5 },
						{ 1, 3, 2, 2,10, 2, 2, 1, 5 },
						{ 1, 1, 1, 1, 2, 1, 2, 1, 5 },
						{ 4, 4, 4, 1, 2, 2, 2, 1, 5 },
						{ 4, 4, 4, 1, 1, 1, 1, 1, 7 },
				}, {
						{1,1,1,1,1,1,5},
						{1,2,2,2,2,1,1,1,1,1,4,4,4,1,1,1,1,1,5},
						{1,2,2,2,2,2,2,2,2,1,1,1,1,1,2,2,2,1,5},
						{1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,5},
						{1,2,2,2,2,2,2,2,2,1,1,1,1,1,2,2,2,1,5},
						{1,2,2,2,2,1,1,1,1,1,4,4,4,1,2,2,2,1,5},
						{1,1,1,1,1,1,4,4,4,4,4,4,4,1,2,2,2,1,5},
				}
		};
	int spawnpoint[3][2] = {
			{ 2, 5 },
			{ 2, 2 },
			{ 4, 1 }
	};
	struct dynamic_stuff{
		int xcoord[4];
		int ycoord[4];
		bool is_active;
	}
	barrelspawn,switchspawn,playerspawn,specspawn;
	playerspawn.xcoord[0] = 2; playerspawn.xcoord[1] = 2; playerspawn.xcoord[2] = 4; playerspawn.xcoord[3] = 2; //SPAM
	playerspawn.ycoord[0] = 5; playerspawn.ycoord[1] = 2; playerspawn.ycoord[2] = 1; playerspawn.ycoord[2] = 3; //SHARE THE SPAM
	barrelspawn.xcoord[0] = 0; barrelspawn.xcoord[1] = 0; barrelspawn.xcoord[2] = 0; //SPAM THE WORLD
	barrelspawn.ycoord[0] = 0; barrelspawn.ycoord[1] = 0; barrelspawn.ycoord[2] = 0; //JUS SPAM IT
	switchspawn.xcoord[0] = 0; switchspawn.xcoord[1] = 0; switchspawn.xcoord[2] = 0; //ALL IN SPAM
	switchspawn.ycoord[0] = 0; switchspawn.ycoord[1] = 0; switchspawn.ycoord[2] = 0; // 100% SPAM FREE
	specspawn.xcoord[0] = 0; specspawn.xcoord[1] = 0; specspawn.xcoord[2] = 0; //THAT WAS PURE SPAMMING SATISFACTION
	specspawn.ycoord[0] = 0; specspawn.ycoord[1] = 0; specspawn.ycoord[2] = 0; //WE NEED TO GO SPAMMER
	cout << "size of all levels right now is " << sizeof(tiles) << " bytes" << endl;
	cout << "welcome to my game" << endl;
	cout << "WASD to move!" << endl;
	int level = 0;
	int xarraychecker = 0, yarraychecker = 0;
	/*bcoords = barrel carriers
	  scoords = switch carriers
	  spcoords = wall carriers */
	bool sparker, levelindicator = false, oversparker = true, levelcomplete = false;
	while (oversparker == true){
		if (levelcomplete == true){
			level = level + 1;
			levelcomplete = false;
		}
		int xcord = playerspawn.xcoord[level];
		int ycord = playerspawn.ycoord[level];
		int bxcoord = barrelspawn.xcoord[level];
		int bycoord = barrelspawn.ycoord[level];
		int sxcoord = switchspawn.xcoord[level];
		int sycoord = switchspawn.ycoord[level];
		int spxcoord = specspawn.xcoord[level];
		int spycoord = specspawn.ycoord[level];
		specspawn.is_active = false;
		switchspawn.is_active = false;
		sparker = true;
		while (sparker == true){
			if (levelindicator == false){
				cout << "you are in level " << level + 1 << endl;
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
				if (bxcoord != 0){ if (xarraychecker == bxcoord && yarraychecker == bycoord){
					cout << "O";
					xarraychecker += 1;
				}
				}
				else if (sxcoord != 0){if ((xarraychecker == sxcoord && yarraychecker == sycoord) && !switchspawn.is_active){
						cout << "S";
						xarraychecker += 1;
				}
				else if ((xarraychecker == sxcoord && yarraychecker) == sycoord && specspawn.is_active){
					cout << "O";
				}}
				else if (spxcoord != 0){ if ((xarraychecker == spxcoord && yarraychecker == spycoord) && !specspawn.is_active){
						cout << "E";
						xarraychecker += 1;
					}
				else if ((xarraychecker == spxcoord && yarraychecker == spycoord) && specspawn.is_active){
						cout << ",";
						xarraychecker += 1;
					}
				}
                  else if (yarraychecker == ycord && xarraychecker == xcord){
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
				else if (tiles[level][yarraychecker][xarraychecker] == UPBRDG){
					cout << "I";
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
				}
				else if (movementinput == 's'){
					ychecker = ychecker + 1;
					mov(ycord, ychecker, tiles[level][ychecker][xchecker]);
                    if (tiles[level][ychecker][xchecker] == UPBRDG){
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
					}else if (movementinput == 'w'){
						ychecker = ychecker - 1;
						mov(ycord, ychecker, tiles[level][ychecker][xchecker]);
						if (tiles[level][ychecker][xchecker] == UPBRDG){
							ycord = ycord - 1;
							ychecker = ycord;
						}
					}
					else if (movementinput == 's'){
						ychecker = ychecker + 1;
						mov(ycord, ychecker, tiles[level][ychecker][xchecker]);
                         if (tiles[level][ychecker][xchecker] == UPBRDG){
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