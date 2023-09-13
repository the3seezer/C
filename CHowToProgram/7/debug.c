/* Exercise 7.25 Solution */
/* This solution assumes that there is only one */
/* entrance and one exit for a given maze, and */
/* these are the only two zeroes on the borders.*/
#include <stdio.h>
#include <stdlib.h>

#define DOWN 0 /* move down */
#define RIGHT 1 /* move right */
#define UP 2 /* move up */
#define LEFT 3 /* move left */

#define X_START 2 /* starting X and Y coordinate for maze */
#define Y_START 0

    /* function prototypes */
void mazeTraversal(char maze[12][12], int xCoord, int yCoord, int direction);
void printMaze(const char maze[][12]);
int validMove(const char maze[][12], int r, int c);
int coordsAreEdge(int x, int y);

int main() {

  /* maze grid */
  char maze[12][12] = {
      {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
      {'1', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '1'},
      {'0', '0', '1', '0', '1', '0', '1', '1', '1', '1', '0', '1'},
      {'1', '1', '1', '0', '1', '0', '0', '0', '0', '1', '0', '1'},
      {'1', '0', '0', '0', '0', '1', '1', '1', '0', '1', '0', '0'},
      {'1', '1', '1', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
      {'1', '0', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
      {'1', '1', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
      {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1'},
      {'1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1'},
      {'1', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1'},
      {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}};

  mazeTraversal(maze, X_START, Y_START, RIGHT);

  return 0; /* indicate successful termination */

} /* end main */

/* Assume that there is exactly 1 entrance and
exactly 1 exit to the maze. */
void mazeTraversal(char maze[12][12], int xCoord, int yCoord, int direction) {
  static int flag = 0; /* starting position flag */

  maze[xCoord][yCoord] = 'X'; /* mark current point */
  printMaze(maze);

  /* if maze completed */
  if (coordsAreEdge(xCoord, yCoord) && xCoord != X_START && yCoord != Y_START) {
    printf("\nMaze successfully exited!\n\n");
    return;
  } /* end if */
  else if (xCoord == X_START && yCoord == Y_START && flag == 1) {
    printf("\nArrived back at the starting location.\n\n");
    return;
  }            /* end else if */
  else {       /* make next move */
    int move;  /* next move */
    int count; /* counter */

    flag = 1;

    /* loop 4 times and find first valid move */
    for (move = direction, count = 0; count < 4; ++count, ++move, move %= 4) {

      /* choose valid move */
      switch (move) {

      case DOWN: /* move down */

        /* if move is valid, call mazeTraversal */
        if (validMove(maze, xCoord + 1, yCoord)) {
          mazeTraversal(maze, xCoord + 1, yCoord, LEFT);
          return;
        } /* end if */

        break; /* exit switch */

      case RIGHT: /* move right */
        /* if move is valid, call mazeTraversal */
        if (validMove(maze, xCoord, yCoord + 1)) {
          mazeTraversal(maze, xCoord, yCoord + 1, DOWN);
          return;
        } /* end if */

        break; /* exit switch */

      case UP: /* move up */

        /* if move is valid, call mazeTraversal */
        if (validMove(maze, xCoord - 1, yCoord)) {
          mazeTraversal(maze, xCoord - 1, yCoord, RIGHT);
          return;
        } /* end if */

        break; /* exit switch */

      case LEFT: /* move left */

        /* if move is valid, call mazeTraversal */
        if (validMove(maze, xCoord, yCoord - 1)) { /* move left */
          mazeTraversal(maze, xCoord, yCoord - 1, UP);
          return;
        } /* end if */

        break; /* exit switch */
      }        /* end switch */

    } /* end for */

  } /* end else */

} /* end function mazeTraversal */

/* validate move */
int validMove(const char maze[][12], int r, int c) {
  return (r >= 0 && r <= 11 && c >= 0 && c <= 11 && maze[r][c] != '1');

} /* end function validMove */

/* function to check coordinates */
int coordsAreEdge(int x, int y) {

  /* if coordinate is not valid */
  if ((x == 0 || x == 11) && (y >= 0 && y <= 11)) {
    return 1;
  } /* end if */
  else if ((y == 0 || y == 11) && (x >= 0 && x <= 11)) {
    return 1;
  }      /* end else if */
  else { /* coordinate is valid */
    return 0;
  } /* end else */

} /* end function coordsAreEdge */
/* print the current state of the maze */
void printMaze(const char maze[][12]) {
  int x; /* row counter */
  int y; /* column counter */

  /* iterate through the maze */
  for (x = 0; x < 12; x++) {

    for (y = 0; y < 12; y++) {
      printf("%c ", maze[x][y]);
    } /* end for */

    printf("\n");
  } /* end for */

  printf("\nHit return to see next move");
  getchar();
} /* end function printMaze */