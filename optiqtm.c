//FILE OPTIQTM.C

// #define _LINUX_
//Comment this line out if you compile with MinGW under Windows.
//This disables the SIGNAL handling.

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include <assert.h>
#include <signal.h>
#include "cubedefs.h"

static char manString[256];
int subOptLev;
int symRed;

#ifdef _LINUX_
static sigjmp_buf jump_buf;
#endif

CubieCube cc_a;


#ifdef _LINUX_ 
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void  user_break(int  n)
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
{
printf("-- skipping cube --\n");
fflush(stdout);
siglongjmp(jump_buf, 1);
return;
}
#endif

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void  pp()
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
{
printf(".");
fflush(stdout);
return;
}

void init()
{
    int i,l;
    subOptLev=-1;
    symRed=1;

    printf("initializing memory.\n");
    visitedA = (char *)calloc(NGOAL/8+1,1);//initialized to 0 by default
    visitedB = (char *)calloc(NGOAL/8+1,1);
    for (l=0;l<NTWIST;l++)
    movesCloserToTarget[l] = (short *)calloc(NFLIPSLICE*2,2);

    printf("initializing tables");fflush(stdout);
    initSymCubes();
    initMoveCubes();
    initInvSymIdx();
    initSymIdxMultiply();
    initMoveConjugate();
    initMoveBitsConjugate();
    initGESymmetries();
    initTwistConjugate();pp();
    initRawFLipSliceRep();pp();
    initTwistMove();pp();
    initCorn6PosMove();pp();
    initEdge4PosMove();pp();
    initEdge6PosMove();pp();
    initSymFlipSliceClassMove();pp();
    initMovesCloserToTarget();pp();
    initNextMove();pp();
    printf("\r\n");
}

const char* solve_string(const char* cube_string)
{
    printf("\nsolving optimal: %s\n",cube_string);fflush(stdout);
    cc_a = stringToCubieCube((char*)cube_string);
    return solveOptimal(cc_a);
}
