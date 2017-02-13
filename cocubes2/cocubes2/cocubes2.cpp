#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

char *compressStr(char *str)
{
    int len, charCount, newStrIdx, i;
    char *newStr, *originalStr;
    char prevChar;
    char itoaBuffer[32];

    assert(str);
    len = strlen(str);
    newStr = (char *)malloc(len+1);
    assert(newStr);
    memset(newStr, '\0', sizeof(newStr));
    charCount = 0;
    newStrIdx = 0;
    prevChar = '\0';
    
    for (i=0; i <= len; ++i) {
        if (str[i] == prevChar) {
            ++charCount;
        }
        else
        {
            if (charCount > 1) {
                sprintf(itoaBuffer, "%d", charCount);
                strcpy(&newStr[newStrIdx], &itoaBuffer[0]);
                newStrIdx++;
            }
            newStr[newStrIdx] = str[i];
            ++newStrIdx;
            charCount = 1;
        }
        prevChar = str[i];
    }
    if (strlen(newStr) >= len)
    {   
        originalStr = (char *)malloc(len+1);
        assert(originalStr);
        strcpy(originalStr, str);
        return originalStr;
    }
    return newStr;
}
        
int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        fprintf(stderr, "Please specify a string to compress\n");
        return -1;
    }

    //char stringToCompress[] = "aabcccccaaad";
    char *stringToCompress = argv[1];
    char *compressedString;    

    printf("Original string is %s, len = %d\n", stringToCompress, strlen(stringToCompress));
    compressedString = compressStr(stringToCompress);
    printf("Compressed string is %s, len = %d\n", compressedString, strlen(compressedString));
    
    free(compressedString);
    
    return 0;
}