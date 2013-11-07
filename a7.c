#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>

uint64_t* fib(int n) {
    uint64_t* sequence;

    if((sequence = malloc(sizeof(n) * n)) == NULL) {
        perror("malloc failed\n");
        exit(0);
    }
    
    sequence[0] = 0;
    sequence[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        sequence[i] = sequence[i-1] + sequence[i-2];
    }

    return sequence;
}

uint64_t* fibgen(int n, int g) {
    uint64_t* sequence;

    if((sequence = malloc(sizeof(n) * n)) == NULL) {
        perror("malloc failed\n");
        exit(0);
    }
    
    sequence[0] = 0;
    sequence[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        sequence[i] = sequence[i-1] + sequence[i-2] -
            (i > g ? sequence[i-g] : 0);
    }

    return sequence;
}

int main(void) {
    uint64_t* seq = fib(69);
    for(int i = 0; i <=69; i++ ) {
        printf("%" PRIu64 "\n", seq[i]);
    }
    
    uint64_t* seq2 = fibgen(69, 4);
    for(int i = 0; i <= 69; i++ ) {
        printf("%" PRIu64 "\n", seq2[i]);
    }
}

