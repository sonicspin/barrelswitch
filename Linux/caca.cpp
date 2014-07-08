#include "iostream"
#include "string"
#include"Render.h"
int is_valid(int checkedtile, bool& valid){
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
void mov(int& coord, int movcoord, int checktile, bool is_barrel, bool on_bridge, int& tile){
	if (is_barrel){
		if (on_bridge){
			if (checktile == 1){
				std::cout << "you can't do that!" << std::endl;
			}
			else if (checktile == 3){
				tile = UPBRDG;
				coord = movcoord;
			}
			else if (checktile == 2){
				tile = UPBRDG;
				coord = movcoord;
			}
			else if (checktile == 8){
				tile = UPBRDG;
				coord = movcoord;
			}
			else{
				;
			}
		}
		else{
			if (checktile == 1){
				std::cout << "you can't do that!" << std::endl;
			}
			else if (checktile == 3){
				coord = movcoord;
			}
			else if (checktile == 2){
				coord = movcoord;
			}
			else if (checktile == 8){
				coord = movcoord;
			}
			else{
				;
			}
		}
	}
	else{
		if (on_bridge){
			if (checktile == 1){
				std::cout << "you can't do that!" << std::endl;
			}
			else if (checktile == 3){
				tile = UPBRDG;
				coord = movcoord;
			}
			else if (checktile == 2){
				tile = UPBRDG;
				coord = movcoord;
			}
			else{
				;
			}
		}
		else{
			if (checktile == 1){
				std::cout << "you can't do that!" << std::endl;
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
	}
}
int main() {
	int	tiles[5][60][70] = {
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
			}, { { 13 } }
	};
	int spawnpoint[3][2] = {
			{ 2, 5 },
			{ 2, 2 },
			{ 4, 1 }
	};
	struct coord_stuff{
		int xcoord[2][5];
		int ycoord[2][5];

	};
	struct dynamic_tiles{
		bool is_active;
		int is_activated_by;
		coord_stuff coords;
	}	barrelspawn, switchspawn, playerspawn, specspawn;
	struct npc{
		coord_stuff coords;
		std::string text[2][5];
	}someNPC;
	playerspawn.coords.xcoord[0][0] = 2; playerspawn.coords.xcoord[0][1] = 2; playerspawn.coords.xcoord[0][2] = 4; playerspawn.coords.xcoord[0][3] = 2; //SPAM
	playerspawn.coords.xcoord[0][4] = 2;
	playerspawn.coords.ycoord[0][0] = 5; playerspawn.coords.ycoord[0][1] = 2; playerspawn.coords.ycoord[0][2] = 1; playerspawn.coords.ycoord[0][3] = 3; //SHARE THE SPAM
	playerspawn.coords.ycoord[0][4] = 2;
	barrelspawn.coords.xcoord[0][0] = 0; barrelspawn.coords.xcoord[0][1] = 0; barrelspawn.coords.xcoord[0][2] = 0; barrelspawn.coords.xcoord[0][3] = 15; //SPAM THE WORLD
	barrelspawn.coords.xcoord[0][4] = 10;
	barrelspawn.coords.ycoord[0][0] = 0; barrelspawn.coords.ycoord[0][1] = 0; barrelspawn.coords.ycoord[0][2] = 0; barrelspawn.coords.ycoord[0][3] = 3;//JUST SPAM IT
	barrelspawn.coords.ycoord[0][4] = 2;
	switchspawn.coords.xcoord[0][0] = 0; switchspawn.coords.xcoord[0][1] = 0; switchspawn.coords.xcoord[0][2] = 0; switchspawn.coords.xcoord[0][3] = 7; //ALL IN SPAM
	switchspawn.coords.xcoord[0][4] = 8; switchspawn.coords.xcoord[1][4] = 4;
	switchspawn.coords.ycoord[0][0] = 0; switchspawn.coords.ycoord[0][1] = 0; switchspawn.coords.ycoord[0][2] = 0; switchspawn.coords.ycoord[0][3] = 8; // 100% SPAM FREE
	switchspawn.coords.ycoord[0][4] = 8; switchspawn.coords.ycoord[1][4] = 8;
	specspawn.coords.xcoord[0][0] = 0; specspawn.coords.xcoord[0][1] = 0; specspawn.coords.xcoord[0][2] = 0; specspawn.coords.xcoord[0][3] = 15; //THAT WAS PURE SPAMMING SATISFACTION
	specspawn.coords.xcoord[0][4] = 10;
	specspawn.coords.ycoord[0][0] = 0; specspawn.coords.ycoord[0][1] = 0; specspawn.coords.ycoord[0][2] = 0; specspawn.coords.ycoord[0][3] = 13; //WE NEED TO GO SPAMMER
	std::cout << "size of all levels right now is " << sizeof(tiles) << " bytes" << std::endl;
	std::cout << "welcome to my game" << std::endl;
	std::cout << "WASD to move!" << std::endl;
	std::string debugger;
	bool debug, loopcheck = false;
	int loopcount = 0;
	int level = 0, loop = 0;
	int xarraychecker = 0, yarraychecker = 0;
	/*bcoords = barrel carriers
	  scoords = switch carriers
	  spcoords = wall carriers */
	bool sparker, levelindicator = false, oversparker = true, levelcomplete = false, tilecheck = false;
	while (oversparker == true){
		if (levelcomplete == true){
			level = level + 1;
			levelcomplete = false;
		}
		int xcord = playerspawn.coords.xcoord[0][level];
		int ycord = playerspawn.coords.ycoord[0][level];
		int bxcoord = barrelspawn.coords.xcoord[0][level];
		int bycoord = barrelspawn.coords.ycoord[0][level];
		int sxcoord = switchspawn.coords.xcoord[0][level];
		int sycoord = switchspawn.coords.ycoord[0][level];
		int spxcoord = specspawn.coords.xcoord[0][level];
		int spycoord = specspawn.coords.ycoord[0][level];
		specspawn.is_active = false;
		switchspawn.is_active = false;
		sparker = true;
		while (sparker == true){
			if (levelindicator == false){
				std::cout << "you are in level " << level + 1 << std::endl;
				levelindicator = true;
			}
			if (bycoord == sycoord && bxcoord == sxcoord){
				switchspawn.is_active = true;
			}
			else{
				switchspawn.is_active = false;
			}
			if (tiles[level][ycord][xcord] == 3){
				std::cout << "you're on a staircase! write \"q\" to go up a level!" << std::endl;
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
			loop = 0;
			while (tilesparker == true){
				if (loop == 4210){
					std::cout << "\033[0;31;40m" << "ERROR NO.1:";
					std::cout << "\033[0;36;40m" << "infinite loop!";
					tilesparker = false;
				}
				is_valid(tiles[level][yarraychecker][xarraychecker], tilecheck);
				if (tilecheck == true){
					render(tiles[level], xarraychecker, yarraychecker, xcord, ycord, level, tilesparker, loop, loopcheck, loopcount);
				}
				else if (tiles[level][yarraychecker][xarraychecker] == DYNAMC){
					if (xarraychecker == bxcoord && yarraychecker == bycoord){
						std::cout << "\033[0;31;40m" << "O";
						xarraychecker = xarraychecker + 1;
					}
					else if (xarraychecker == sxcoord && yarraychecker == sycoord && switchspawn.is_active == false){
						std::cout << "\033[0;31;40m" << "S";
						xarraychecker = xarraychecker + 1;
					}
					else if (xarraychecker == sxcoord && yarraychecker == sycoord){
						std::cout << "\033[0;31;40m" << "O";
						xarraychecker = xarraychecker + 1;
					}
					else if (xarraychecker == spxcoord && yarraychecker == spycoord && specspawn.is_active == false){
						std::cout << "\033[0;31;40m" << "E";
						xarraychecker = xarraychecker + 1;
					}
					else if (xarraychecker == spxcoord && yarraychecker == spycoord){
						std::cout << "\033[0;37;40m" << ",";
						xarraychecker = xarraychecker + 1;
					}
				}
				else if (tiles[level][yarraychecker][xarraychecker] == ENDGAM){
					std::cout << "Bye! And thank you for playing!";
					goto end;
				}
				else if (tilecheck == false){
					std::cout << "\033[0;31;40m" << "ERROR NO.2:";
					std::cout << "\033[0;37;40m" << "there was an error rendering this, the error tile was ";
					std::cout << "\033[0;31;40m" << tiles[level][yarraychecker][xarraychecker] << std::endl;
					tilesparker = false;
				}
				tilecheck = false;
				loop++;
				//end renderer
			}
			bool movcheck = false;
			std::cin >> movementinput;
			if (movementinput == 'p'){
				bool annoyer = true;
				debug = true;
				while (debug == true){
					if (annoyer){
						std::cout << "available commands: goto, level,lvlprint,exit,loopcheck" << std::endl;
						annoyer = false;
					}
					std::cin >> debugger;
					if (debugger == "help"){
						std::cout << "available commands: goto,level,lvlprint,exit,loopcheck" << std::endl;
						std::cout << "write help <command> to see more information" << std::endl;
					}
					else if (debugger == "lvlprint"){
						debugrender(tiles[level], xarraychecker, yarraychecker);
					}
					else if (debugger == "level"){
						int lvlteleport;
						std::cout << "enter the level you want to teleport into (close the debugger to apply)" << std::endl;
						std::cin >> lvlteleport;
						level = lvlteleport;
						sparker = false;
					}
					else if (debugger == "exit"){
						debug = false;
					}
					else if (debugger == "goto"){
						int xtele, ytele;
						std::cout << "enter the x coordinate you want to teleport" << std::endl;
						std::cin >> xtele;
						std::cout << "enter the y coordinate you want to teleport" << std::endl;
						std::cin >> ytele;
						xcord = xtele;
						ycord = ytele;
						std::cout << "close the debugger to apply" << std::endl;
					}
					else if (debugger == "loopcheck"){
						std::cout << "loop checking switched" << std::endl;
						loopcheck = !loopcheck;
					}
				}
			}
			else if (tiles[level][ycord][xcord] == 3 && movementinput == 'q'){
				levelcomplete = true;
				levelindicator = false;
				sparker = false;
			}
			else if (movementinput == 'd'){
				if (tiles[level][ycord][xcord] == UPBRDG){
					std::cout << "you can't do that!" << std::endl;
				}
				else{
					if (tiles[level][ycord][xcord] == BUPBRD){
						xchecker = xchecker + 1;
						if ((spycoord == ychecker && spxcoord == xchecker) && specspawn.is_active == false){
							std::cout << "you can't do that!" << std::endl;
							movcheck = false;
						}
						else if ((spycoord == ychecker && spxcoord == xchecker) && specspawn.is_active == true){
							tiles[level][ycord][xcord] = UPBRDG;
							xcord = xcord + 1;
							xchecker = xcord;
						}
						if (movcheck){
							tiles[level][ycord][xcord] = UPBRDG;
							mov(xcord, xchecker, tiles[level][ychecker][xchecker], false, true, tiles[level][ycord][xcord]);
						}
						else if (tiles[level][ychecker][xchecker] == UPBRDG){
							tiles[level][ycord][xcord] = UPBRDG;
							xcord = xcord + 1;
							tiles[level][ychecker][xchecker] = BUPBRD;
							xchecker = xcord;
						}
						if (bycoord == ychecker && bxcoord == xchecker){
							bxcheck = bxcoord + 1;
							tiles[level][bycoord][bxcoord] = 2;
							mov(bxcoord, bxcheck, tiles[level][bycheck][bxcheck], true, true, tiles[level][bycoord][bxcoord]);
							tiles[level][bycheck][bxcheck] = 8;
							tiles[level][ycord][xcord] = UPBRDG;
							xcord = xcord + 1;
							xchecker = xcord;
						}
					}
					else{
						xchecker = xchecker + 1;
						if ((spycoord == ychecker && spxcoord == xchecker) && specspawn.is_active == false){
							std::cout << "you can't do that!" << std::endl;
							movcheck = false;
						}
						else if ((spycoord == ychecker && spxcoord == xchecker) && specspawn.is_active == true){
							xcord = xcord + 1;
							xchecker = xcord;
						}
						if (movcheck){
							mov(xcord, xchecker, tiles[level][ychecker][xchecker], false, false, tiles[level][ycord][xcord]);
						}
						else if (tiles[level][ychecker][xchecker] == UPBRDG){
							xcord = xcord + 1;
							tiles[level][ychecker][xchecker] = BUPBRD;
							xchecker = xcord;
						}
						if (bycoord == ychecker && bxcoord == xchecker){
							bxcheck = bxcoord + 1;
							tiles[level][bycoord][bxcoord] = 2;
							mov(bxcoord, bxcheck, tiles[level][bycheck][bxcheck], true, false, tiles[level][bycoord][bxcoord]);
							tiles[level][bycheck][bxcheck] = 8;
							xcord = xcord + 1;
							xchecker = xcord;
						}
					}
				}
			}
			else if (movementinput == 'w'){
				if (tiles[level][ycord][xcord] == BUPBRD){
					std::cout << "you can't do that!" << std::endl;
				}
				else{
					ychecker = ychecker - 1;
					if ((spycoord == ychecker && spxcoord == xchecker) && specspawn.is_active == false){
						std::cout << "you can't do that!" << std::endl;
						movcheck = false;
					}
					else if ((spycoord == ychecker && spxcoord == xchecker) && specspawn.is_active == true){
						ycord = ycord - 1;
						ychecker = ycord;
					}
					if (movcheck){
						mov(ycord, ychecker, tiles[level][ychecker][xchecker], false, false, tiles[level][ycord][xcord]);
					}
					else if (tiles[level][ychecker][xchecker] == UPBRDG){
						ycord = ycord - 1;
						ychecker = ycord;
					}
					if (bycoord == ychecker && bxcoord == xchecker){
						bycheck = bycoord - 1;
						tiles[level][bycoord][bxcoord] = 2;
						mov(bycoord, bycheck, tiles[level][bycheck][bxcheck], true, false, tiles[level][ycord][xcord]);
						tiles[level][bycheck][bxcheck] = 8;
						ycord = ycord - 1;
						ychecker = ycord;
					}
				}
			}
			else if (movementinput == 's'){
				if (tiles[level][ycord][xcord] == BUPBRD){
					std::cout << "you can't do that!" << std::endl;
				}
				else{
					ychecker = ychecker + 1;
					if ((spycoord == ychecker && spxcoord == xchecker) && specspawn.is_active == false){
						std::cout << "you can't do that!" << std::endl;
						movcheck = false;
					}
					else if ((spycoord == ychecker && spxcoord == xchecker) && specspawn.is_active == true){
						ycord = ycord + 1;
						ychecker = ycord;
					}
					if (movcheck){
						mov(ycord, ychecker, tiles[level][ychecker][xchecker], false, false, tiles[level][ycord][xcord]);
					}
					else if (tiles[level][ychecker][xchecker] == UPBRDG){
						ycord = ycord + 1;
						ychecker = ycord;
					}
					if (bycoord == ychecker && bxcoord == xchecker){
						bycheck = bycoord + 1;
						tiles[level][bycoord][bxcoord] = 2;
						mov(bycoord, bycheck, tiles[level][bycheck][bxcheck], true, false, tiles[level][ycord][xcord]);
						tiles[level][bycheck][bxcheck] = 8;
						ycord = ycord + 1;
						ychecker = ycord;
					}

				}
			}
			else if (movementinput == 'a'){
				if (tiles[level][ycord][xcord] == UPBRDG){
					std::cout << "you can't do that!" << std::endl;
				}
				else{
					if (tiles[level][ycord][xcord] == BUPBRD){
						xchecker = xchecker - 1;
						if ((spycoord == ychecker && spxcoord == xchecker) && specspawn.is_active == false){
							std::cout << "you can't do that!" << std::endl;
							movcheck = false;
						}
						else if ((spycoord == ychecker && spxcoord == xchecker) && specspawn.is_active == true){
							tiles[level][ycord][xcord] = UPBRDG;
							xcord = xcord - 1;
							xchecker = xcord;
						}
						if (movcheck){
							tiles[level][ycord][xcord] = UPBRDG;
							mov(xcord, xchecker, tiles[level][ychecker][xchecker], false, true, tiles[level][ycord][xcord]);
						}
						else if (tiles[level][ychecker][xchecker] == UPBRDG){
							xcord = xcord - 1;
							tiles[level][ychecker][xchecker] = BUPBRD;
							xchecker = xcord;
						}
						if (bycoord == ychecker && bxcoord == xchecker){
							bxcheck = bxcoord - 1;
							tiles[level][bycoord][bxcoord] = 2;
							mov(bxcoord, bxcheck, tiles[level][bycheck][bxcheck], true, true, tiles[level][bycoord][bxcoord]);
							tiles[level][bycheck][bxcheck] = 8;
							xcord = xcord - 1;
							xchecker = xcord;
						}
					}
					else{
						xchecker = xchecker - 1;
						if ((spycoord == ychecker && spxcoord == xchecker) && specspawn.is_active == false){
							std::cout << "you can't do that!" << std::endl;
							movcheck = false;
						}
						else if ((spycoord == ychecker && spxcoord == xchecker) && specspawn.is_active == true){
							xcord = xcord - 1;
							xchecker = xcord;
						}
						if (movcheck){
							mov(xcord, xchecker, tiles[level][ychecker][xchecker], false, false, tiles[level][ycord][xcord]);
						}
						else if (tiles[level][ychecker][xchecker] == UPBRDG){
							xcord = xcord - 1;
							tiles[level][ychecker][xchecker] = BUPBRD;
							xchecker = xcord;
						}
						if (bycoord == ychecker && bxcoord == xchecker){
							bxcheck = bxcoord - 1;
							tiles[level][bycoord][bxcoord] = 2;
							mov(bxcoord, bxcheck, tiles[level][bycheck][bxcheck], true, false, tiles[level][bycoord][bxcoord]);
							tiles[level][bycheck][bxcheck] = 8;
							xcord = xcord - 1;
							xchecker = xcord;
						}
					}
				}
			}
		}
	}
end:;
}