/* Exercise 7.26 Solution */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DOWN 0             /* move down */
#define RIGHT 1            /* move right */
#define UP 2               /* move up */
#define LEFT 3             /* move left */
#define POSSIBLE_ZEROS 100 /* maximum possible zeroes */

/* function prototypes */
void mazeTraversal(char maze[12][12], const int xCoord, const int yCoord,
                   int row, int col, int direction);
void mazeGenerator(char maze[][12], int *xPtr, int *yPtr);
void printMaze(const char maze[][12]);
int validMove(const char maze[][12], int r, int c);
int coordsAreEdge(int x, int y);

int main() {
  char maze[12][12]; /* maze grid */
  int loop;          /* row counter */
  int loop2;         /* column counter */
  int xStart;        /* starting x coordinate */
  int yStart;        /* starting y coordinate */
  int x;             /* current x coordinate */
  int y;             /* current y coordinate */

  /* initialize maze grid to 1's */
  for (loop = 0; loop < 12; loop++) {

    for (loop2 = 0; loop2 < 12; loop2++) {
      maze[loop][loop2] = '1';
    } /* end for */

  } /* end for */

  /* generate the maze */
  mazeGenerator(maze, &xStart, &yStart);

  x = xStart; /* starting row */
  y = yStart; /* starting col */

  mazeTraversal(maze, xStart, yStart, x, y, RIGHT);

  return 0; /* indicate successful termination */

} /* end main */

/* Assume that there is exactly 1 entrance and
exactly 1 exit to the maze. */
void mazeTraversal(char maze[12][12], const int xCoord, const int yCoord,
                   int row, int col, int direction) {
  static int flag = 0; /* starting position flag */

  maze[row][col] = 'X'; /* insert X at current location */
  printMaze(maze);

  /* if maze completed */
  if (coordsAreEdge(row, col) && row != xCoord && col != yCoord) {
    printf("\nMaze successfully exited!\n\n");
    return;
  } /* end if */
  else if (row == xCoord && col == yCoord && flag == 1) {
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
        if (validMove(maze, row + 1, col)) {
          mazeTraversal(maze, xCoord, yCoord, row + 1, col, LEFT);
          return;
        } /* end if */

        break; /* exit switch */

      case RIGHT: /* move right */

        /* if move is valid, call mazeTraversal */
        if (validMove(maze, row, col + 1)) {
          mazeTraversal(maze, xCoord, yCoord, row, col + 1, DOWN);
          return;
        } /* end if */

        break; /* exit switch */

      case UP: /* move up */

        /* if move is valid, call mazeTraversal */
        if (validMove(maze, row - 1, col)) {
          mazeTraversal(maze, xCoord, yCoord, row - 1, col, RIGHT);
          return;
        } /* end if */

        break; /* exit switch */

      case LEFT: /* move left */
                 /* if move is valid, call mazeTraversal */
        if (validMove(maze, row, col - 1)) {
          mazeTraversal(maze, xCoord, yCoord, row, col - 1, UP);
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

/* check boundaries of coordinates */
int coordsAreEdge(int x, int y) {

  /* if coordinates not valid */
  if ((x == 0 || x == 11) && (y >= 0 && y <= 11)) {
    return 1;
  } /* end if */
  else if ((y == 0 || y == 11) && (x >= 0 && x <= 11)) {
    return 1;
  }      /* end else if */
  else { /* coordinates valid */
    return 0;
  } /* end else */

} /* end function coordsAreEdge */

/* print the maze */
void printMaze(const char maze[][12]) {
  int x; /* row counter */
  int y; /* column counter */

  /* loop through maze grid */
  for (x = 0; x < 12; x++) {

    for (y = 0; y < 12; y++) {
      printf("%c ", maze[x][y]);
    } /* end for */

    printf("\n");
  } /* end for */

  printf("\nHit return to see next move");
  getchar();
} /* end function printMaze */
  /* random maze generator */
void mazeGenerator(char maze[][12], int *xPtr, int *yPtr) {
  int a;     /* random number */
  int x;     /* random number */
  int y;     /* random number */
  int entry; /* random entry */
  int exit;  /* random exit */
  int loop;  /* loop counter */

  srand(time(NULL));

  /* generate random entry and exit positions */
  do {
    entry = rand() % 4;
    exit = rand() % 4;
  } while (entry == exit); /* end do...while */

  /* Determine entry position while avoiding corners */
  if (entry == 0) {
    *xPtr = 1 + rand() % 10;
    *yPtr = 0;
    maze[*xPtr][0] = '0';
  } /* end if */
  else if (entry == 1) {
    *xPtr = 0;
    *yPtr = 1 + rand() % 10;
    maze[0][*yPtr] = '0';
  } /* end else if */
  else if (entry == 2) {
    *xPtr = 1 + rand() % 10;
    *yPtr = 11;
    maze[*xPtr][11] = '0';
  } /* end else if */
  else {
    *xPtr = 11;
    *yPtr = 1 + rand() % 10;
    maze[11][*yPtr] = '0';
  } /* end else */

  /* Determine exit location */
  if (exit == 0) {
    a = 1 + rand() % 10;
    maze[a][0] = '0';
  } /* end if */
  else if (exit == 1) {
    a = 1 + rand() % 10;
    maze[0][a] = '0';
  } /* end else if */
  else if (exit == 2) {
    a = 1 + rand() % 10;
    maze[a][11] = '0';
  } /* end else if */
  else {
    a = 1 + rand() % 10;
    maze[11][a] = '0';
  } /* end else */

  /* randomly add zeroes to maze grid */
  for (loop = 1; loop < POSSIBLE_ZEROS; loop++) {
    x = 1 + rand() % 10;
    y = 1 + rand() % 10;
    maze[x][y] = '0';
  } /* end for */

} /* end function mazeGenerator */