#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

//0: number of pieces
//1: pawn
//2: rook
//3: knight
//4: bishop
//5: queen
//6: king


void printPieces(int *p){
	cout << "Remaining pieces:";
	if (p[1] != 0)
		cout << " (p)awn";
	if (p[2] != 0)
		cout << " (r)ook";
	if (p[3] != 0)
		cout << " (b)ishop";
	if (p[4] != 0)
		cout << " (k)night";
	if (p[5] != 0)
		cout << " (q)ueen";
	
	char temp = 'y';
	cout << "\nEnter eliminated (y to continue): ";
	cin >> temp;
	if (temp == 'y')
		return;
	if (temp == 'p')
		p[1] = 0;
	else if (temp == 'r')
		p[2] = 0;	
	else if (temp == 'b')
		p[3] = 0;	
	else if (temp == 'k')
		p[4] = 0;
	else if (temp == 'q')
		p[5] = 0;

	return;
}

void move(int *p){
	//movable pieces; m[0] is number of pieces
	int m[7];
	m[0] = 1; m[6] = 1;
	for(int i=1; i<6; i++){
		if (p[i] >0){
			m[i] = 1;
			m[0]++;
		}
		else
			m[i]=0;
	}
	
	while (1){
		int r = (rand() % m[0])+1;
		int i=1;
		while (r > 0){
			if (m[i] != 0){
				r--;
			}
			i++;
		}
		int piece = i-1;
		
		if (piece == 1)
			cout << "Move a pawn: ";
		else if (piece == 2)
			cout << "Move a rook: ";
		else if (piece == 3)
			cout << "Move a knight: ";
		else if (piece == 4)
			cout << "Move a bishop: ";
		else if (piece == 5)
			cout << "Move your queen: ";
		else
			cout << "Move your king: ";
		
		char temp;
		cin >> temp; 
		if (temp == 'y'){
			cout << "\n";
			return;
		}
		else if (temp == 'n'){
			m[piece] = 0;
			m[0]--;			
		}
		else if (temp == 'e'){
			p[piece] = 0;
			m[piece] = 0;
			m[0]--;
		}
		else if (temp == 'u'){
			p[5]++;
			cout << "\n";
			return;
		}
		else if (temp == 'q'){
			cout << "\nWell Played!";
			exit(1);
		}
		else{
			cout << "\n";
			return;
		}
	}	
}

int main(){
	srand(time(NULL));
	
	cout << "Welcome to random chess\n\n";
	cout << "If you can move the piece, enter 'y'.\n";
	cout << "If the piece can't be moved, enter 'n'.\n";
	cout << "If there are no remaining of the piece, enter 'e'.\n";
	cout << "If a pawn becomes a queen, enter 'u'.\n";
	cout << "To quit, enter q.\n";
	cout << "Good luck!\n\n";
	
	int p1[7]; //white
	int p2[7]; //black
	p1[0] = 16; p2[0] = 16; //pieces
	p1[1] = 8; p2[1] = 8; //pawn
	p1[2] = 2; p2[2] = 2; //rook
	p1[3] = 2; p2[3] = 2; //knight
	p1[4] = 2; p2[4] = 2; //bishop
	p1[5] = 1; p2[5] = 1; //queen
	p1[6] = 1; p2[6] = 1; //king
	
	
	cout << "White's turn: \n";
	move(p1);
	cout << "Black's turn: \n";
	move(p2);
	
	while(1){
		cout << "White's turn: \n";
		//printPieces(p1);
		move(p1);
		cout << "Black's turn: \n";
		//printPieces(p2);
		move(p2);
	}
}