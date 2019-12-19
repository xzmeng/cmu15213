/* 
 * 
 */
#include "cachelab.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

void showHelpMessage();

struct cache_line {
    int s_num;
    int E_num;
};

int main(int argc, char *argv[])
{
    int hflag = 0, vflag = 0, sflag = 0, Eflag=0, bflag=0, tflag = 0;
    int s = 0, E = 0, b = 0;
    int opt; /* this is the opt character */
    char *tracename = NULL;

    /* parse command line arguments */
    while ((opt = getopt(argc, argv, "hvs:E:b:t:")) != -1) {
        switch (opt) {
            case 'h':
                hflag = 1;
                break;
            case 'v':
                vflag = 1;
                break;
            case 's':
                sflag = 1;
                s = atoi(optarg);
                break;
            case 'E':
                Eflag = 1;
                E = atoi(optarg);
                break;
            case 'b':
                bflag = 1;
                b = atoi(optarg);
                break;
            case 't':
                tflag = 1;
                tracename = optarg;
        }
    }
    
    /* show help message */
    if (optind == 1 || hflag) {
        showHelpMessage();
        exit(EXIT_SUCCESS);
    }
 
}

void showHelpMessage() {
    printf("Usage: ./csim [-hv] -s <num> -E <num> -b <num> -t <file>\n");
    printf("Options:\n");
    printf("  -h         Print this help message.\n");
    printf("  -v         Optional verbose flag.\n");
    printf("  -s <num>   Number of set index bits.\n");
    printf("  -E <num>   Number of lines per set.\n");
    printf("  -b <num>   Number of block offset bits.\n");
    printf("  -t <file>  Trace file.\n");
    printf("\n");
    printf("Examples:\n");
    printf("  linux>  ./csim -s 4 -E 1 -b 4 -t traces/yi.trace\n");
    printf("  linux>  ./csim -v -s 8 -E 2 -b 4 -t traces/yi.trace\n");
}

