#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "coales.h"

int main(){
	int i, j;
	i = 47;
	j = 247;
	prbin(47);
	prbin(247);
	prbin(i^j);
	printf("%d\n", d_hamming(i, j));

}
