#include <stdio.h>
#include <string.h>
#include "parse.h"

char *read_line(void){
    char *line = NULL;
    size_t buffer_size = 0;
    getline(&line, &buffer_size, stdin);
    //printf("%s\n", line);
    return line;

}

Param_t split_line(char *line){
    Param_t params;
    params.inputRedirect = NULL;
    params.outputRedirect = NULL;
    params.background = 0;
    params.argumentCount = 0;
    char *token;
    char *tokens[1024];
    int position = 0;

    token = strtok(line, " \n\r");
    //params.argumentCount = 1;

    while(token != NULL){
        params.argumentVector[position] = token;
        position++;
        params.argumentCount++;

        if(strcmp(token, "<") == 0)
            printf("Input redirect");
        if(strcmp(token, ">") == 0)
            printf("Output redirect");
        if(strcmp(token, "&") == 0)
            printf("background process");

        token = strtok(NULL, " \n\r");

    }

    params.argumentVector[position] = NULL;
    //printParams(&params);
    return params;
}

void printParams(Param_t * param)
{

    int i;
    printf ("InputRedirect: [%s]\n",
        (param->inputRedirect != NULL) ? param->inputRedirect:"NULL");
    printf ("OutputRedirect: [%s]\n",
        (param->outputRedirect != NULL) ? param->outputRedirect:"NULL");
    printf ("Background: [%d]\n", param->background);
    printf ("ArgumentCount: [%d]\n", param->argumentCount);
    for (i = 0; i < param->argumentCount; i++)
        printf("ArgumentVector[%2d]: [%s]\n", i, param->argumentVector[i]);
}
