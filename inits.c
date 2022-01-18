#include "cubedefs.h"

CubieCube symCube[NSYM_Oh];
CubieCube moveCube[NMOVE];
int invSymIdx[NSYM_Oh];
int symIdxMultiply[NSYM_Oh][NSYM_Oh];
int moveConjugate[NMOVE][NSYM_Oh];
int twistConjugate[NTWIST][NSYM_D4h];
int rawFlipSliceRep[NFLIPSLICE];
char nextMove[NMBITS][NMOVE+1];
unsigned short int optimal_twistMove[NTWIST][NMOVE];
unsigned short int corn6PosMove[NCORN6POS][NMOVE];
unsigned short int edge4PosMove[NEDGE4POS][NMOVE];
int edge6PosMove[NEDGE6POS][NMOVE];
int symFlipSliceClassMove[NFLIPSLICE][NMOVE];
short *movesCloserToTarget[NTWIST];
short moveBitsConjugate[4096][NSYM_Oh];
unsigned long long ESymmetries[NMOVE],GESymmetries[NMOVE];


char *coset;

char *visitedA;
char *visitedB;
