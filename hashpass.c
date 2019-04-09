#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "md5.h"

/*int main()
{
    printf("Enter a String: ");
    char str[100];
    scanf("%s", str);
    char *hash = md5(str, strlen(str));
    printf("hash: %s\n", hash);
}*/



/*int main(int argc, char* argv[])
{
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Can't open %s for reading\n", argv[1]);
        exit(1);
    }
    
    char line [100];
    while(fgets(line, 100, f) != NULL)
    {
        char *hash = md5(argv[1], strlen(argv[1]));
        printf("hash: %s\n", hash);
        free(hash);
    }    
}*/

int main (int argc, char* argv[])
{
    // check how many filename user supplied.
    // if not enough, error message and exit.
    if (argc < 3)
    {
        printf("You need to supply two filenames\n");
        exit(1);
    }
    
    if (strcmp(argv[1], argv[2]) == 0)
    {
        printf("out file is same as input file\n");
        exit(1);
    }
    // open first file for reading
    FILE *in = fopen(argv[1], "r");
    if (!in)
    {
        printf("Can't open %s for reading\n", argv[1]);
        exit(1);
    }
    
    // open second file for reading
    FILE *out = fopen(argv[2], "w");
    if(!out)
    {
        printf("Can't open %s for writing\n", argv[2]);
        exit(1);
    }
    
    // Loop through the first line
    char line [100];
    while(fgets(line, 100, in) != NULL)
    {
        char *hash = md5(line, (strlen(line)-1));
        printf("hash: %s\n", hash);
        free(hash);
    }
    
    fclose(in);
    fclose(out);
}

