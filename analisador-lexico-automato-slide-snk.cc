#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define linha 14
#define coluna 40

void Leitura (int matriz [linha][coluna]);
int PosicaoIndice (char ch);
bool IsFinal (int is_final_);
void Token (int final_state_);

int main (){
	int matrix[linha][coluna] = {
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  // estado 0 (morto)
			{4,4,4,4,4,4,4,4,2,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7,7,7,5,9,13,12}, //estado 1
			{4,4,4,4,4,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,0,0,0},  //estado 2
			{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,0,0,0},  //estado 3
			{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,0,0,0},  //estado 4
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,6,6,6,6,6,0,0,0,0},  //estado 5
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,6,6,6,6,6,0,0,0,0},  //estado 6	
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,7,7,7,7,7,7,7,8,0,0,0},  //estado 7
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,8,8,8,8,8,8,8,0,0,0,0},  //estado 8		
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0},  //estado 9
			{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,0,0,0,0,0,0,0,0,0,0,0,0,11,0},  // estado 10
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  // estado 11
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12},  // estado 12	
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}  // estado 13
	};
	Leitura (matrix);
}

void Leitura (int matriz [linha][coluna]) {
  ifstream fin ("teste.txt");
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
    if (indice == -1 && current_state != 1) current_state = 0;
    if (indice == -1 && current_state == 1) current_state = 13;
    if (indice != -1) current_state = matriz [current_state][indice];

    if (IsFinal(current_state)) final_state = current_state;

    if (current_state != 0) {
      if (caracter [i] != '\n') cout << caracter [i];
      if (caracter [i] == '\n') cout << "\\n";
      i++; 
    } 
    if (current_state == 0) {
      Token (final_state);
      current_state = 1;
      final_state = 0;
    }
  }
}

int PosicaoIndice (char ch) {
	char indice [coluna] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','.','-','\n',' '};
	int i = 0;
	while (i < 40) {
		if (ch == indice[i]) return i;	
		i++;
	}
	return -1;
}

bool IsFinal (int is_final_) {
	if (is_final_ != 1 && is_final_ != 10 && is_final_ != 0) return true;
	else return false;
}

void Token (int final_state_) {
	switch (final_state_) {
		case 2  : cout << " ID\n"         ; break;
		case 3  : cout << " IF\n"         ; break;
		case 4  : cout << " ID\n"         ; break;
		case 5  : cout << " error\n"      ; break;
		case 6  : cout << " REAL\n"       ; break;
		case 7  : cout << " NUM\n"        ; break;
		case 8  : cout << " REAL\n"       ; break;
		case 9  : cout << " error\n"      ; break;
		case 11 : cout << " comment\n"    ; break;
		case 12 : cout << " white space\n"; break;
    case 13 : cout << " error\n"      ; break;
	}
}
