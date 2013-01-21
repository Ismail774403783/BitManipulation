// BitManipulation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#define UISIZE ( 8*sizeof(unsigned int) )
#define BMLEN(n) ( 1+(n-1)/(int)UISIZE )

#define BITSET(bm, i)   bm[(i)/UISIZE] |=     1 << ((i)%UISIZE)
#define BITCLR(bm, i)   bm[(i)/UISIZE] &=   ~(1 << ((i)%UISIZE))
#define BITONQ(bm, i) ( bm[(i)/UISIZE] &     (1 << ((i)%UISIZE)) )


int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int bm[2] = {1,4};
	printf("size of unsigned %d \n", sizeof(unsigned int));
	printf("%d-%d--%d\n", 1, 1, BITONQ(bm,32));
	printf("%d-%d--%d\n", 1, 1, BITONQ(bm,1));
	printf("1<<0 %d\n", 1<<0);
	printf("1<<1 %d\n", 1<<1);
	printf("1<<2 %d\n", 1<<2);
	printf("1<<3 %d\n", 1<<3);

	// integer         bit
	// 0                 0
	// 1                 1
	// 2                10
	// 4               100
	// 8              1000
	// 16            10000
	// 24            11000
	// 20            10100
	unsigned int bm2[2] = {24, 0};
	// print 0
	printf("%d--%d\n", 2, BITONQ(bm2,2));
	// print 0
	bm2[0] = 20;
	printf("%d-%d--%d\n",bm2[0], 3, BITONQ(bm2,3));
	// print !=0
	bm2[0] = 24;
	printf("%d-%d--%d\n",bm2[0], 3, BITONQ(bm2,3));

	printf("24 & (1<<3) %d \n", (24 & (1<<3)) );

	return 0;
}

