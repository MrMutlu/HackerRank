#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);


int main()
{
    int n = parse_int(ltrim(rtrim(readline())));
    
    int binArr[32], remainder, i = 0, consecutive = 1, maxconsecutive = 1;
    
    // save binary values in binArr array
    for(i = 0; n > 0; i++)
    {
        binArr[i] = n % 2;
        n = n / 2;
    }
    
    // reverse the elements of the array
    for(i = i - 1; i >= 0; i--)
    {
        
        /* 
        * check consecutive elements for "1" or "0"
        * if it's "1", increment consecutive and 
        * if maxconsecutive is lesser than consecutive,
        * equal it so we have max number of consecutive.
        */
        
        if( binArr[i] == 1 && binArr[i-1] == 1)
        {
            consecutive++;
            if(maxconsecutive < consecutive)
            {
                maxconsecutive = consecutive;
            }
            
            /* 
            * here, we are checking there are zeroes 
            * for example  439 = 110110111    
            * 2 times there are 0 and 1's consecutive
            * so we reset consecutive counter
            */
            if((binArr[i-1] == 1 && binArr[i-2] == 0) || (binArr[i-1] == 0 && binArr[i-2] == 1))
            {
              consecutive = 1;
            }
        }
    }
    printf("%d",maxconsecutive);
    
    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}

