#ifndef COALES_H
#define COALES_H

typedef struct seq_tmpl seq;
typedef struct agent_tmpl agent;

unsigned int nbits(unsigned int n);
void prbin(unsigned int n);
unsigned int d_hamming(unsigned int n1, unsigned int n2);

int d_seq(seq *s1, seq *s); 


#endif 
