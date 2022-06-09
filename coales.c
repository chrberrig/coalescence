#include <stdio.h>
#include <stdlib.h>
#include "coales.h"

# define SEQLEN 128	// should be multiples of 32

struct seq_tmpl {
	unsigned int bitstr[SEQLEN>>5];	// uint array representation of bitmask seq. (SEQLEN/32 is number of cells necessary.)
};

// need function to return resp int divisor and modulo part of the bit entry of seq. 
// unsigned int cellnum, ibitnum;

struct agent_tmpl {
	int id;		// identifier
	int decendent;	// individual from previous population begatting this agent
	int offspring;	// number of offspring for this agent, accounted for in sim
	int mutation;	// nutation id
};

unsigned int nbits(unsigned int n) {
	return sizeof(n)*8;
}

void prbin(unsigned int n) {
	unsigned int i;
	for (i=(1 << (nbits(n)-1)); i>0; i>>=1){
		(n & i) ? printf("1") : printf("0");
	}
	printf(" : %d\n", n);
}

unsigned int d_hamming(unsigned int n1, unsigned int n2) {
	unsigned int v;	// count bits set in this (32-bit value)
	unsigned int c;	// store the total here
	
	// Running single-bit mask implementation.
	c = 0;
	v = (n1^n2);
	for (unsigned int i=(1 << (nbits(v)-1)); i>0; i>>=1){
        	if (v & i){
			c++;
		}
	}

	// Bit-operation implementation
	//
	// c = v - ((v >> 1) & 0x55555555);
	// c = ((c >> 2) & 0x33333333) + (c & 0x33333333);
	// c = ((c >> 4) + c) & 0x0F0F0F0F;
	// c = ((c >> 8) + c) & 0x00FF00FF;
	// c = ((c >> 16) + c) & 0x0000FFFF;
	// 
	// Edit: Admittedly it's a bit optimized which makes it harder to read. It's easier to read as:
	// 
	// c = (v & 0x55555555) + ((v >> 1) & 0x55555555);
	// c = (c & 0x33333333) + ((c >> 2) & 0x33333333);
	// c = (c & 0x0F0F0F0F) + ((c >> 4) & 0x0F0F0F0F);
	// c = (c & 0x00FF00FF) + ((c >> 8) & 0x00FF00FF);
	// c = (c & 0x0000FFFF) + ((c >> 16)& 0x0000FFFF);

	return c;
}

// unsigned int d_seq(int *a, )

/*
pop backpropagate(*population_state) {
	
} 

story gen_story
	int g_end = 20; 
	for (int g=0; g<g_end; g++){
	}		
}

struct coalTreeNode {
	
};
*/
