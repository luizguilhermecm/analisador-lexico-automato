#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define linha 9 
#define coluna 38 

void Leitura (int matriz [linha][coluna], char * argumento);
int PosicaoIndice (char ch);
bool IsFinal (int is_final_);
void Token (int final_state_);

int main (int argc, char *argv[]){
  int matrix[linha][coluna] = {
//	{a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,0,1,2,3,4,5,6,7,8,9,+,-}
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  // estado 0 (morto)
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,5,5,5,5,5,5,5,5,5,5,3,4},  // estado 1
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0},  // estado 2
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  // estado 3
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  // estado 4
		{0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,5,5,5,0,0},  // estado 5
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,8,8,8,8,8,8,8,7,7},  // estado 6
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,8,8,8,8,8,8,8,0,0},  // estado 7
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,8,8,8,8,8,8,8,0,0},  // estado 8
  };
	Leitura (matrix, argv[1]);
}

void Leitura (int matriz [linha][coluna], char *argumento) {
  ifstream fin (argumento);
  vector<char> caracter;
  char ch;
  int i;
  while (fin.get(ch))caracter.push_back(ch); 
  for(i = 0; i <= caracter.size(); i++) cout << caracter[i]; 
  cout << "\n\nSaida\n\n";
  int current_state = 1;
  int final_state = 0;
  int indice;
  i = 0;
  
  while (i <= caracter.size()) {
    indice = PosicaoIndice(caracter[i]);
    if (indice != -1) current_state = matriz [current_state][indice];

    if (IsFinal(current_state)) final_state = current_state;

    if (current_state != 0) {
      cout << caracter[i];
      i++; 
    } 
    if (current_state == 0) {
      Token (final_state);
      current_state = 1;
      final_state = 0;
    }
  }
  Token(final_state);
}

int PosicaoIndice (char ch) {
	char indice [coluna] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','+','-'};
	int i = 0;
	while (i < coluna) {
		if (ch == indice[i]) return i;	
		i++;
	}
	return -1;
}

bool IsFinal (int is_final_) {
	if (is_final_ != 1 &&
      is_final_ != 6 &&
      is_final_ != 7 &&
      is_final_ != 0){ 
    return true;
  }else return false;
}

void Token (int final_state_) {
	switch (final_state_) {
		case 2: cout << " Estado 2\n"; break;
		case 3: cout << " Estado 3\n"; break;
		case 4: cout << " Estado 4\n"; break;
		case 5: cout << " Estado 5\n"; break;
		case 8: cout << " Estado 8\n"; break;
	}
}
