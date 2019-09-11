#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>
#include <ctime>



using namespace std;

bool GameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score,tailN,tailX[100],tailY[100],tail2X,tail2Y,sleep=150;
enum eDirection {STOP = 0, LEFT, RIGHT, DOWN,UP};
eDirection  dir;


void start(){
	GameOver = false;
	dir = STOP;
	x = width / 2 - 1;
	y = height / 2 - 1;
	fruitX = rand () % 16 + 3;
	fruitY = rand () % 16 + 3;
	score = 0; 
}


void Draw (){
	system("cls");
	for (int i = 0; i < width+1; i++)
		cout << "_";
	cout << "  YIIPABJIEHUE : wasd" << endl << "                                             x - 3aKoH4uTb urpy";
    cout << endl;
	
	
	for (int i = 0; i < height; i++){
		for (int j=0; j < width; j++){
			if (j==0 || j == width - 1)
	            cout << "|";
		    if (i == y && j == x)
		        cout << "@";
	        else if (i == fruitY && j == fruitX )
	            cout << "F"; 
	        else {
	        	bool probel = false;
	        	for (int k = 0; k < tailN; k++){
	        		if (tailX[k] == j && tailY[k] == i){
	        			probel = true;
	        			cout << "o";
					} 
				}
				if (!probel)
	        	    cout <<" ";
			}
	    }
    cout << endl;
    }
	
	
	for (int i=0;i < width+1; i++)
	    cout <<"_";
    cout << endl << endl; 
	cout << "C4ET: "<<score;
}


void Input() {
	if (_kbhit()) {
		switch (_getch()){
		case 'a' :
			if(dir != RIGHT || tailN == 0)
		    dir = LEFT;
			break;
		case 'd' :
			if (dir != LEFT || tailN == 0)
		    dir = RIGHT;
		    break;
	    case 'w' :
	    	if (dir != DOWN || tailN == 0)
		    dir = UP;
		    break;
	    case 's' :
	    	if (dir != UP || tailN == 0)
	    	dir = DOWN;
	        break;
		case 'x':
			GameOver = true;
			break;
	    }
	}
}


void Logic(){
	int prevX = tailX [0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x; 
	tailY[0] = y;
	for (int i=1; i < tailN; i++){
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch(dir)
	{
	    case  LEFT:
		    x--;
			break;
		case RIGHT:
		    x++;
		    break;
	    case UP:
		    y--;
		    break;
	    case DOWN:
	    	y++;
	        break;	
	}
	
	if (x == width-1 || x < 0 || y == height || y< 0)
	    GameOver =true;
	if (x == fruitX && y == fruitY){	// увелич хвоста + sleep + рандом фрукта
	    score += 1;
	    fruitX = rand () % 16 + 3 ;
	    fruitY  = rand () % 16 + 3 ;         
	    tailN+=1;
	    if (sleep > 50)
	    sleep -= 7 ;
    }
    for (int i = 0; i < tailN; i++){
    	if (tailX[i] == x && tailY[i] == y)
    	    GameOver = true;
	}
}
int main(){
	srand(time(0));
	start();
	while (GameOver!=true){
		Draw();
		Input();
		Logic();
		Sleep(sleep);
	}
	cout << endl << "Bbl IIpourpaJIu" << endl;
	system("pause");
	return 0;
}

