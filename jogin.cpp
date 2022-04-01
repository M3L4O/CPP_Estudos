#include <cstdlib>
#include <iostream>
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

#define TAM 30

int pontos = 0;
int x = 0, y = 0;
using namespace std;

void update(char window[TAM][TAM], int col, int row) {
  printw("Pontos: %d\n", pontos);

  window[x][y] = 'o';
  window[col][row] = 'X';
  if (col == x && row == y) {
    pontos++;
    x = rand() % TAM - 1;
    y = rand() % TAM - 1;
  }

  for (int i = 0; i < TAM; i++) {
    for (int j = 0; j < TAM; j++) {
      printw("%c", window[i][j]);
    }
    printw("\n");
  }
  window[col][row] = ' ';
  window[x][y] = ' ';
}

int main(int argc, char **argv) {
  char dir;
  char window[TAM][TAM] = {};

  for (int i = 0; i < TAM; i++) {
    for (int j = 0; j < TAM; j++) {
      window[i][j] = ' ';
    }
  }

  initscr();
  srand(time(NULL));

  int j = 0, i = 0;
  char tecla;
  do {
    halfdelay(1);

    tecla = wgetch(stdscr);
    if (tecla != ERR) {
      switch (tecla) {
      case 'w':
        if (i == 0)
          cout << "Já está no topo\n";
        else
          i--;
        break;
      case 'a':
        if (j == 0)
          cout << "Já está no max da esquerda\n";
        else
          j--;
        break;
      case 's':
        if (i == TAM - 1)
          cout << "Já está no fundo.\n";
        else
          i++;
        break;
      case 'd':
        if (j == TAM - 1)
          cout << "Já está no max da direita.\n";
        else
          j++;
        break;
      }
    }
    clear();
    update(window, i, j);
  } while (tecla != 'q');
  endwin();

  return 0;
}
