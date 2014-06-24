#include <iostream>
#include <string>
using namespace std;
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
int is_valid(int checkedtile,bool& valid){
	switch (checkedtile)
	{
	case 1:
		valid = true;
		break;
	case 2:
		valid = true;
		break;
	case 3:
		valid = true;
		break;
	case 4:
		valid = true;
		break;
	case 5:
		valid = true;
		break;
	case 7:
		valid = true;
		break;
	case 9:
		valid = true;
		break;
	case 10:
		valid = true;
		break;
	case 11:
		valid = true;
		break;
	case 12:
		valid = true;
		break;
	default:
		valid = false;
		break;
	}
	return 0;
}
int debugrender(int arr[60][70],int& xdcheck, int& ydcheck){
	bool spark = true;
	while (spark){
		if (arr[ydcheck][xdcheck] == LVLEND){
			cout << LVLEND << endl;
			xdcheck = 0;
			ydcheck = 0;
			spark = false;
		}
		else if(arr[ydcheck][xdcheck] == LINBRK){
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
int render(int flooring[60][70],int& xcheck, int& ycheck,int xcoord, int ycoord, int lvl, bool& sparky,int& loop){
	bool spark = true;
	while (spark){
		if (flooring[ycheck][xcheck] == AIRSPC){
			cout << "_";
			xcheck = xcheck + 1;
		}
		else if (ycheck == ycoord && xcheck == xcoord){
			if (flooring[ycheck][xcheck] == BUPBRD){
				cout << "I";
				xcheck = xcheck + 1;
			}
			else{
				cout << "@";
				xcheck = xcheck + 1;
			}
		}
		else if (flooring[ycheck][xcheck] == FLOORT){
			cout << ",";
			xcheck = xcheck + 1;
		}
		else if (flooring[ycheck][xcheck] == STAIRS){
			cout << "L";
			xcheck = xcheck + 1;
		} 
		else if (flooring[ycheck][xcheck] == LINBRK){
			cout << endl;
			xcheck = 0;
			ycheck = ycheck + 1;
		}
		else if (flooring[ycheck][xcheck] == WALLTL){
			cout << "E";
			xcheck = xcheck + 1;
		}
		else if (flooring[ycheck][xcheck] == UPBRDG){
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
		else{ spark = false;
		}
	}
	return 0;
}
int mov(int& coord, int movcoord, int checktile,bool is_barrel){
	if(is_barrel){
	if (checktile == 1){
		cout << "you can't do that!" << endl;
	}
	else if (checktile == 3){
		coord = movcoord;
	}
	else if (checktile == 2){
		coord = movcoord;
	}else if (checktile == 8){
		coord = movcoord;
	}
    else{
	;
	}
	}else{if (checktile == 1){
		cout << "you can't do that!" << endl;
	}
	else if (checktile == 3){
		coord = movcoord;
	}
	else if (checktile == 2){
		coord = movcoord;
	}
    else{
	;
	}
	}
	return 0;
}
int main() {
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
					{ 1, 3, 2, 2, 11, 2, 2, 1, 5 },
					{ 1, 1, 1, 1, 2, 1, 2, 1, 5 },
					{ 4, 4, 4, 1, 2, 2, 2, 1, 5 },
					{ 4, 4, 4, 1, 1, 1, 1, 1, 7 },
			}, {
					{ 1, 1, 1, 1, 1, 1, 5 },
					{ 1, 2, 2, 2, 2, 1, 1, 1, 1, 1, 4, 4, 4, 1, 1, 1, 1, 1, 5 },
					{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 2, 2, 2, 1, 5 },
					{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 8, 2, 1, 5 },
					{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 2, 2, 2, 1, 5 },
					{ 1, 2, 2, 2, 2, 1, 1, 1, 1, 1, 4, 4, 4, 1, 2, 2, 2, 1, 5 },
					{ 1, 1, 1, 1, 1, 1, 4, 4, 4, 4, 4, 4, 4, 1, 2, 2, 2, 1, 5 },
					{ 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 1, 5 },
					{ 4, 4, 4, 4, 4, 4, 1, 8, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 5 },
					{ 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 1, 5 },
					{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 2, 2, 2, 1, 5 },
					{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 2, 1, 1, 5 },
					{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 2, 1, 5 },
					{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 8, 1, 1, 1, 1, 1, 5 },
					{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 2, 2, 2, 2, 2, 1, 5 },
					{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 2, 2, 2, 2, 2, 1, 5 },
					{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 2, 2, 2, 2, 2, 1, 5 },
					{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 2, 2, 2, 3, 2, 1, 5 },
					{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 2, 2, 2, 2, 2, 1, 5 },
					{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 7 }
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
	barrelspawn, switchspawn, playerspawn, specspawn;
	playerspawn.xcoord[0] = 2; playerspawn.xcoord[1] = 2; playerspawn.xcoord[2] = 4; playerspawn.xcoord[3] = 2; //SPAM
	playerspawn.ycoord[0] = 5; playerspawn.ycoord[1] = 2; playerspawn.ycoord[2] = 1; playerspawn.ycoord[3] = 3; //SHARE THE SPAM
	barrelspawn.xcoord[0] = 0; barrelspawn.xcoord[1] = 0; barrelspawn.xcoord[2] = 0; barrelspawn.xcoord[3] = 15; //SPAM THE WORLD
	barrelspawn.ycoord[0] = 0; barrelspawn.ycoord[1] = 0; barrelspawn.ycoord[2] = 0; barrelspawn.ycoord[3] = 3;//JUST SPAM IT
	switchspawn.xcoord[0] = 0; switchspawn.xcoord[1] = 0; switchspawn.xcoord[2] = 0; switchspawn.xcoord[3] = 7; //ALL IN SPAM
	switchspawn.ycoord[0] = 0; switchspawn.ycoord[1] = 0; switchspawn.ycoord[2] = 0; switchspawn.ycoord[3] = 8; // 100% SPAM FREE
	specspawn.xcoord[0] = 0; specspawn.xcoord[1] = 0; specspawn.xcoord[2] = 0; specspawn.xcoord[3] = 15; //THAT WAS PURE SPAMMING SATISFACTION
	specspawn.ycoord[0] = 0; specspawn.ycoord[1] = 0; specspawn.ycoord[2] = 0; specspawn.ycoord[3] = 13; //WE NEED TO GO SPAMMER
	cout << "size of all levels right now is " << sizeof(tiles) << " bytes" << endl;
	cout << "welcome to my game" << endl;
	cout << "WASD to move!" << endl;
	string debugger;
	bool debug;
	int level =0, loop = 0;
	int xarraychecker = 0, yarraychecker = 0;
	/*bcoords = barrel carriers
	  scoords = switch carriers
	  spcoords = wall carriers */
	bool sparker, levelindicator = false, oversparker = true, levelcomplete = false,tilecheck = false;
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
		bool movcheck = true;
		while (sparker == true){
			if (levelindicator == false){
				cout << "you are in level " << level + 1 << endl;
				levelindicator = true;
			}
			if (bycoord == sycoord && bxcoord == sxcoord){
				switchspawn.is_active = true;
			}
			if (tiles[level][ycord][xcord] == 3){
				cout << "you're on a staircase! write \"q\" to go up a level!" << endl;
			}
			if (switchspawn.is_active){
				specspawn.is_active = true;
			}
			char movementinput = 0;
			bool tilesparker = true;
			int xchecker = xcord;
			int ychecker = ycord;
			int bycheck = bycoord;
			int bxcheck = bxcoord;
			//renderer
			while (tilesparker == true){
				if (loop == 150){ 
					cout << "ERROR NO.1: infinite loop!";
					tilesparker = false; }
				is_valid(tiles[level][yarraychecker][xarraychecker],tilecheck);
				if (tilecheck == true){
						render(tiles[level], xarraychecker, yarraychecker, xcord, ycord, level, tilesparker,loop);
				}
				else if (tiles[level][yarraychecker][xarraychecker] == DYNAMC){
					if (xarraychecker == bxcoord && yarraychecker == bycoord){
						cout << "O";
						xarraychecker = xarraychecker + 1;
					}
					else if (xarraychecker == sxcoord && yarraychecker == sycoord && switchspawn.is_active == false){
							cout << "S";
							xarraychecker = xarraychecker + 1;
						}
						else if (xarraychecker == sxcoord && yarraychecker == sycoord){
							cout << "O";
							xarraychecker = xarraychecker + 1;
						}
						else if (xarraychecker == spxcoord && yarraychecker == spycoord && specspawn.is_active == false){
							cout << "E";
							xarraychecker = xarraychecker + 1;
						}
						else if (xarraychecker == spxcoord && yarraychecker == spycoord){
							cout << ",";
							xarraychecker = xarraychecker + 1;
						}
					}
				else if (tilecheck == false){
							cout << "ERROR NO.2:there was an error rendering this, the error tile was "
								<< tiles[level][yarraychecker][xarraychecker] << endl;
							tilesparker = false;
							loop = 0;
						}
						tilecheck = false;
						loop++;
						//end renderer
				}
				cin >> movementinput;
				if(movementinput == 'p'){
					bool annoyer = true;
				debug = true;
				while (debug == true){
					if(annoyer){
				cout << "available commands: goto, level,lvlprint" << endl;
				annoyer = false;
					}
				cin >> debugger;
				if(debugger == "help"){
				cout << "available commands: goto, level,lvlprint, exit" << endl;
				cout << "write help <command> to see more information" << endl;
				}else if(debugger == "lvlprint"){
                 debugrender(tiles[level], xarraychecker, yarraychecker);
				}else if(debugger == "level"){
					int lvlteleport;
				cout << "enter the level you want to teleport into (close the debugger to apply)" << endl;
				cin >> lvlteleport;
				level = lvlteleport;
				sparker = false;
				}else if (debugger == "exit"){
					debug = false;
				}else if(debugger == "goto"){
				int, xtele,ytele;
				cout << "enter the x coordinate you want to teleport" << endl;
				cin >> xtele;
                cout << "enter the y coordinate you want to teleport" << endl;
				cin >> ytele;
				cout << "close the debugger to apply"
				}
				}
				}
				else if (tiles[level][ycord][xcord] == 3 && movementinput == 'q'){
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
						if ((spycoord == ychecker && spxcoord == xchecker) && specspawn.is_active == false){
							cout << "you can't do that!" << endl;
							movcheck = false;
						}
						else if ((spycoord == ychecker && spxcoord == xchecker) && specspawn.is_active == true){
							ycord = ycord - 1;
							ychecker = ycord;
						}
						if (movcheck){
							mov(ycord, ychecker, tiles[level][ychecker][xchecker],false);
						}
						if (bycoord == ychecker && bxcoord == xchecker){
							bycheck = bycoord - 1;
							tiles[level][bycoord][bxcoord] = 2;
							mov(bycoord, bycheck, tiles[level][bycheck][bxcheck],true);
							tiles[level][bycheck][bxcheck] = 8;
							ycord = ycord - 1;
							ychecker = ycord;
						}
						else if (tiles[level][ychecker][xchecker] == UPBRDG){
							ycord = ycord - 1;
							ychecker = ycord;
						}
					}
					else if (movementinput == 's'){
						ychecker = ychecker + 1;
						if ((spycoord == ychecker && spxcoord == xchecker) && specspawn.is_active == false){
							cout << "you can't do that!";
							movcheck = false;
						}
						else if ((spycoord == ychecker && spxcoord == xchecker) && specspawn.is_active == true){
							ycord = ycord + 1;
							ychecker = ycord;
						}
						if (movcheck){
							mov(ycord, ychecker, tiles[level][ychecker][xchecker],false);
						}
						if (bycoord == ychecker && bxcoord == xchecker){
							bycheck = bycoord + 1;
							tiles[level][bycoord][bxcoord] = 2;
							mov(bycoord, bycheck, tiles[level][bycheck][bxcheck],true);
							tiles[level][bycheck][bxcheck] = 8;
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
						if ((spycoord == ychecker && spxcoord == xchecker) && specspawn.is_active == false){
							cout << "you can't do that!";
							movcheck = false;
						}
						else if ((spycoord == ychecker && spxcoord == xchecker) && specspawn.is_active == true){
							xcord = xcord + 1;
							xchecker = xcord;
						}
						if (movcheck){
							mov(xcord, xchecker, tiles[level][ychecker][xchecker],false);
						}
						if (bycoord == ychecker && bxcoord == xchecker){
							bxcheck = bxcoord + 1;
							tiles[level][bycoord][bxcoord] = 2;
							mov(bxcoord, bxcheck, tiles[level][bycheck][bxcheck],true);
							tiles[level][bycheck][bxcheck] = 8;
							xcord = xcord + 1;
							xchecker = xcord;
						}else if (tiles[level][ychecker][xchecker] == UPBRDG){
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
						if ((spycoord == ychecker && spxcoord == xchecker) && specspawn.is_active == false){
							cout << "you can't do that!";
							movcheck = false;
						}
						else if ((spycoord == ychecker && spxcoord == xchecker) && specspawn.is_active == true){
							xcord = xcord - 1;
							xchecker = xcord;
						}
						if (movcheck){
							mov(xcord, xchecker, tiles[level][ychecker][xchecker],false);
						}
						if (bycoord == ychecker && bxcoord == xchecker){
							bxcheck = bxcoord - 1;
							tiles[level][bycoord][bxcoord] = 2;
							mov(bxcoord, bxcheck, tiles[level][bycheck][bxcheck],true);
							tiles[level][bycheck][bxcheck] = 8;
							xcord = xcord - 1;
							xchecker = xcord;
						}
						else
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
						if ((spycoord == ychecker && spxcoord == xchecker) && specspawn.is_active == false){
							cout << "you can't do that!";
							movcheck = false;
						}
						else if ((spycoord == ychecker && spxcoord == xchecker) && specspawn.is_active == true){
							xcord = xcord + 1;
							xchecker = xcord;
						}
						if (movcheck){
							mov(xcord, xchecker, tiles[level][ychecker][xchecker],false);
						}
						if (bycoord == ychecker && bxcoord == xchecker){
							bxcheck = bxcoord + 1;
							tiles[level][bycoord][bxcoord] = 2;
							mov(bxcoord, bxcheck, tiles[level][bycheck][bxcheck],true);
							tiles[level][bycheck][bxcheck] = 8;
							xcord = xcord + 1;
							xchecker = xcord;
						}
						else if (tiles[level][ychecker][xchecker] == UPBRDG){
							xcord = xcord + 1;
							tiles[level][ychecker][xchecker] = BUPBRD;
							xchecker = xcord;
						}
					}
					else if (movementinput == 'w'){
						ychecker = ychecker - 1;
						if ((spycoord == ychecker && spxcoord == xchecker) && specspawn.is_active == false){
							cout << "you can't do that!";
							movcheck = false;
						}
						else if ((spycoord == ychecker && spxcoord == xchecker) && specspawn.is_active == true){
							ycord = ycord - 1;
							ychecker = ycord;
						}
						if (movcheck){
							mov(ycord, ychecker, tiles[level][ychecker][xchecker],false);
						}
						if (bycoord == ychecker && bxcoord == xchecker){
							bycheck = bycoord - 1;
							tiles[level][bycoord][bxcoord] = 2;
							mov(bycoord, bycheck, tiles[level][bycheck][bxcheck],true);
							tiles[level][bycheck][bxcheck] = 8;
							ycord = ycord - 1;
							ychecker = ycord;
						}else if (tiles[level][ychecker][xchecker] == UPBRDG){
							ycord = ycord - 1;
							ychecker = ycord;
						}
					}
					else if (movementinput == 's'){
						ychecker = ychecker + 1;
						if ((spycoord == ychecker && spxcoord == xchecker) && specspawn.is_active == false){
							cout << "you can't do that!";
							movcheck = false;
						}
						else if ((spycoord == ychecker && spxcoord == xchecker) && specspawn.is_active == true){
							ycord = ycord + 1;
							ychecker = ycord;
						}
						if (movcheck){
							mov(ycord, ychecker, tiles[level][ychecker][xchecker],false);
						}
						if (bycoord == ychecker && bxcoord == xchecker){
							bycheck = bycoord + 1;
							tiles[level][bycoord][bxcoord] = 2;
							mov(bycoord, bycheck, tiles[level][bycheck][bxcheck],true);
							tiles[level][bycheck][bxcheck] = 8;
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
						if ((spycoord == ychecker && spxcoord == xchecker) && specspawn.is_active == false){
							cout << "you can't do that!";
							movcheck = false;
						}
						else if ((spycoord == ychecker && spxcoord == xchecker) && specspawn.is_active == true){
							xcord = xcord - 1;
							xchecker = xcord;
						}
						if (movcheck){
							mov(xcord, xchecker, tiles[level][ychecker][xchecker],false);
						}
						if (bycoord == ychecker && bxcoord == xchecker){
							bxcheck = bxcoord - 1;
							tiles[level][bycoord][bxcoord] = 2;
							mov(bxcoord, bxcheck, tiles[level][bycheck][bxcheck],true);
							tiles[level][bycheck][bxcheck] = 8;
							xcord = xcord - 1;
							xchecker = xcord;
						}
						else if (tiles[level][ychecker][xchecker] == UPBRDG){
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