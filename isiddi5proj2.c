//
//  main.cpp
//  isiddi5proj2
//
//  Created by Mohamed Imran Mohamed Siddique on 1/27/17.
//  Copyright © 2017 Imran Siddique. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>  /* for strlen() */

#define TRUE 1
#define FALSE 0

int DebugMode;

typedef char stackAnother;

typedef struct {
    stackAnother *contents;
    int top;
    int Size;
} stackMain;


/* Function to accurately pinpoint and make spaces to print the missing/expecting code right
 *  under the user input
 */
void space(int count){
    int i;
    for (i=1; i<count; i++){
        
        printf(" ");
        
    }
}
/* Checks to see if the stack is empty or not */
int IsEmpty(stackMain *stacked)
{
    if (stacked->top < 0){
        return 1;
    
    }else {
        return 0;
    }
}

/*
 Initializes the stack
 */

void StackInit(stackMain *stacked, int Size)
{
    stackAnother *newContents;
    
    /* Allocate a new array to hold the contents. */
    
    stacked->contents = newContents;
    stacked->Size = 2;
    stacked->top = -1;  /* I.e., empty */
    
    newContents = (stackAnother *)malloc(sizeof(stackAnother) * Size);
    
    
    
}

/*
 Empties the stack once the program has completed
 */

void Stackreset(stackMain *stacked)
{
    
    
    stacked->contents = NULL;
    stacked->Size = 0;
    stacked->top = -1;  /* I.e., empty */
    
    /* Get rid of array. */
    free(stacked->contents);
}

/*
 Checks to see if the stack is full
 */

int IsFull(stackMain *stacked)
{
    return stacked->top >= stacked->Size - 1;
}

/*
 A function to access the top of the stack
 */

int top (stackMain *stacked)
{
    return (  stacked->contents[stacked->top] );
}

/*
 Push each symbols with/without the debug mode
 */

void Push(stackMain *stacked, stackAnother element)
{
    if (IsFull(stacked)) {
        if (DebugMode==TRUE){
        printf("Can't push element on stack: stack is full. Adding 2 spaces\n");
            printf("Old size = %d\n", stacked->Size);
        stacked->Size=stacked->Size+2;
            printf("New size = %d\n", stacked->Size);
        }else {
            stacked->Size=stacked->Size+2;
        }
        
    }
    
    /* Put information in array; update top. */
    
    
    stacked->contents[++stacked->top] = element;
}

/*
 pop each symbols once the closing symbol is encountered with/wothout the debug option
 */

void StackPop(stackMain *stacked, stackAnother element, int count, int mode)
{
    /*
     Checks if the stack is empty in order to pop symbols
     */
    
    if (IsEmpty(stacked)) {
        printf("Stack is empty, exiting program\n");
        exit(1);  /* Exit, returning error code. */
    }
    
    /*
     If the opening symbols are encountered, it will pop the corresponding closing symbols
     */
    
    if (element == ')'){
        
        if (stacked->contents[stacked->top] == '(')
        {
            
            stacked->contents[stacked->top] = stacked->contents[--stacked->top];
            
            
        }
        else {
        /*
        If the opening symbols for parenthesis are not matching, it will display the expected closing symbol
        */
            if (stacked->contents[stacked->top] == '{'){
                if (DebugMode==TRUE){
                    
                    printf("Expecting } at position %d \n", (count-1)/2);
                    printf("Error encountered, no longer pusing or popping\n");
                    
                } else {
                    printf("\t\t");
                    space(count);
                    printf("^ Expecting }\n");
                }
            }
            if (stacked->contents[stacked->top] == '['){
                if (DebugMode==TRUE){
                    
                    printf("Expecting ] at position %d \n", (count-1)/2);
                    printf("Error encountered, no longer pusing or popping\n");
                    
                } else {
                    printf("\t\t");
                    space(count);
                    printf("^ Expecting ]\n");
                }
            }
            if (stacked->contents[stacked->top] == '<'){
                if (DebugMode==TRUE){
                    
                    printf("Expecting < at position %d \n", (count-1)/2);
                    printf("Error encountered, no longer pusing or popping\n");
                    
                } else {
                    printf("\t\t");
                    space(count);
                    printf("^ Expecting <\n");
                }
            }
            exit (0);
        }
        
        
    
    }
    
    /*
     If the opening symbols for the greater than sign are encountered, it will pop the corresponding closing symbols
     */
    
    if (element == '>'){
        
        if (stacked->contents[stacked->top] == '<')
        {
            
            stacked->contents[stacked->top] = stacked->contents[--stacked->top];
            
            
        }
        else {
        /*
        If the opening symbols for greater than sign are not mathcing, it will display the corresponding closing symbols
        */
            if (stacked->contents[stacked->top] == '{'){
                if (DebugMode==TRUE){
                    
                    printf("Expecting } at position %d \n", (count-1)/2);
                    printf("Error encountered, no longer pusing or popping\n");
                    
                } else {
                    printf("\t\t");
                    space(count);
                    printf("^ Expecting }\n");
                }
            }
            if (stacked->contents[stacked->top] == '('){
                if (DebugMode==TRUE){
                    
                    printf("Expecting ) at position %d \n", (count-1)/2);
                    printf("Error encountered, no longer pusing or popping\n");
                    
                } else {
                    printf("\t\t");
                    space(count);
                    printf("^ Expecting )\n");
                }
            }
            if (stacked->contents[stacked->top] == '['){
                if (DebugMode==TRUE){
                    
                    printf("Expecting ] at position %d \n", (count-1)/2);
                    printf("Error encountered, no longer pusing or popping\n");
                    
                } else {
                    printf("\t\t");
                    space(count);
                    printf("^ Expecting ]\n");
                }
            }
            exit (0);
        }
        
        
        
    }
    /*
     If the opening symbols for the brackets are encountered, it will pop the corresponding closing symbols
     */
     if (element == ']'){
        
        if (stacked->contents[stacked->top] == '[')
        {
            
            stacked->contents[stacked->top] = stacked->contents[--stacked->top];
        }
        else {
        /*
        If the opening symbols for the brackets are not matching, it will display the corresponding closing symbols
        */
            
            if (stacked->contents[stacked->top] == '{'){
                if (DebugMode==TRUE){
                    
                printf("Expecting } at position %d \n", (count-1)/2);
                    printf("Error encountered, no longer pusing or popping\n");
                
                } else {
                printf("\t\t");
                space(count);
                printf("^ Expecting }\n");
                }
            }
            if (stacked->contents[stacked->top] == '('){
                if (DebugMode==TRUE){
                    
                    printf("Expecting ) at position %d \n", (count-1)/2);
                    printf("Error encountered, no longer pusing or popping\n");
                    
                } else {
                    printf("\t\t");
                    space(count);
                    printf("^ Expecting )\n");
                }
            }
            if (stacked->contents[stacked->top] == '<'){
                if (DebugMode==TRUE){
                    
                    printf("Expecting < at position %d \n", (count-1)/2);
                    printf("Error encountered, no longer pusing or popping\n");
                    
                } else {
                    printf("\t\t");
                    space(count);
                    printf("^ Expecting <\n");
                }
            }
            exit (0);
        }
        
        
        
    }
    
    /*
     If the opening symbols for the curly brakcets are encountered, it will pop the corresponding closing symbols
     */
    if (element == '}'){
        
        if (stacked->contents[stacked->top] == '{')
        {
            
            stacked->contents[stacked->top] = stacked->contents[--stacked->top];
            
        }
        else {
        /*
        If the opening symbols for the curly brakcets are not matching, it will pop the corresponding closing symbols
        */
            if (stacked->contents[stacked->top] == '['){
                if (DebugMode==TRUE){
                    
                    printf("Expecting [ at position %d \n", (count-1)/2);
                    printf("Error encountered, no longer pusing or popping\n");
                    
                } else {
                    printf("\t\t");
                    space(count);
                    printf("^ Expecting [\n");
                }
            }
            if (stacked->contents[stacked->top] == '('){
                if (DebugMode==TRUE){
                    
                    printf("Expecting ) at position %d \n", (count-1)/2);
                    printf("Error encountered, no longer pusing or popping\n");
                    
                } else {
                    printf("\t\t");
                    space(count);
                    printf("^ Expecting )\n");
                }
            }
            if (stacked->contents[stacked->top] == '<'){
                if (DebugMode==TRUE){
                    
                    printf("Expecting < at position %d \n", (count-1)/2);
                    printf("Error encountered, no longer pusing or popping\n");
                    
                } else {
                    printf("\t\t");
                    space(count);
                    printf("^ Expecting <\n");
                }
            }
            exit (0);
        }
        
        
        
    }
    
}






int main(int argc, const char * argv[]) {



        stackMain stack;    /* A stack to hold characters. */
        char str[300];   /* String entered by user. */
        char *transfer;  /* Pointer used to go through each input during push/pop function the string. */
    int count =0;
    int i;

    
    /*
     prompt the user to input symbols
     */
        printf("Enter Symbols: ");
    
    /*
     Checks whether the user has input -d to turn on Debug mode
     */
    for (i = 0; i < argc; i++)
    {
        
        if ('-' == argv[i][0]){
            if ('d' == argv[i][1]){
                /*
                 Activates the degug mode
                 */
                DebugMode=TRUE;

            }
            
        }

        else {DebugMode=FALSE;}
        
    }
    
    
    
    /*
     reads in the users input
     */
        fgets(str,300,stdin);
        
        /*
         * Initialize the stack.
         */
        StackInit(&stack, strlen(str)-1);
        
        /*
         * transfer the user input into the pointer array
         */
        
    transfer = str;
    
    /*
     keeping looping until the newline is read in or until the loop breaks
     */
    
    while (*transfer != '\0'){
        
        
        /*
         If the user input is opening symbols, it will push it in to the stack
         */

            if ((*transfer == '(') || (*transfer == '[') || (*transfer == '<') ||( *transfer == '{')){
                if (DebugMode==TRUE){
                    
                    //starts printing information for debug mode
                    printf("pushing %c to the stack\n", *transfer);
                    Push(&stack, *transfer);
                } else {
                    //does not print any information
                    Push(&stack, *transfer);
                }
            
            
            }
        
        
        /*
         If the user input is closing symbols, it will access the top and pop the symbol
         */
            if((*transfer == ')') || (*transfer == ']') || (*transfer == '>') ||( *transfer == '}')) {
                
            
                
                if (IsEmpty(&stack)==1){
                
                    if(*transfer == ')'){
                        if (DebugMode==TRUE){
                        printf("missing ( in position %d \n", (count-1)/2);
                            printf("Error encountered, no longer pusing or popping");
                            break;

                        }
                        else {
                        printf("\t\t");
                        space(count);
                    printf("^missing (\n");
                        break;
                        }
                        
                    }
                    if(*transfer == '>'){
                        if (DebugMode==TRUE){
                            printf("missing < in position %d \n", (count-1)/2);
                            printf("Error encountered, no longer pusing or popping");
                            break;
                            
                        }
                        else {
                            printf("\t\t");
                            space(count);
                            printf("^missing <\n");
                            break;
                        }
                        
                    }
                    if(*transfer == ']'){
                        if (DebugMode==TRUE){
                            printf("missing [ in position %d \n", (count-1)/2);
                            printf("Error encountered, no longer pusing or popping");
                            break;
                            
                        }
                        else {
                            printf("\t\t");
                            space(count);
                            printf("^missing [\n");
                            break;
                        }
                        
                    }
                    if (*transfer == '}'){
                        if (DebugMode==TRUE){
                            printf("missing { in position %d \n", (count-1)/2);
                            printf("Error encountered, no longer pusing or popping");
                            break;
                            
                        }
                        else {
                            printf("\t\t");
                            space(count);
                            printf("^missing {\n");
                            break;
                        }
                        
                    }

                }
                if (DebugMode==TRUE){
                    printf("popping %c from the stack\n", *transfer);
                    StackPop(&stack, *transfer, count, DebugMode);
                } else {
                    StackPop(&stack, *transfer, count, DebugMode);
                }
                
                
            }
        
        transfer++;
        count++;
            
     

        }
    
    /*
     If the opening symbols is present but the closing isn't, it will print out the missing symbols.
     */
    
    if (IsEmpty(&stack)!=1){
        
        
        //printf("Extra %c", top(&stack));
        
        if(top(&stack) == '('){
            
            if (DebugMode==TRUE){
            printf("missing ) in position %d\n", (count-2)/2);
                printf("Error encountered, no longer pusing or popping");
            }
            else {
            printf("\t\t");
            space(count);
            printf("^missing )\n");
            }
            
            
        }
        if(top(&stack) == '<'){
            
            if (DebugMode==TRUE){
                printf("missing > in position %d\n", (count-2)/2);
                printf("Error encountered, no longer pusing or popping");
            }
            else {
                printf("\t\t");
                space(count);
                printf("^missing >\n");
            }
            
            
        }
        if(top(&stack) == '['){
            
            if (DebugMode==TRUE){
                printf("missing ] in position %d\n", (count-2)/2);
                printf("Error encountered, no longer pusing or popping");
            }
            else {
                printf("\t\t");
                space(count);
                printf("^missing ]\n");
            }
            
            
        }
        if (top(&stack) == '{'){
            
            if (DebugMode==TRUE){
                printf("missing } in position %d\n", (count-2)/2);
                printf("Error encountered, no longer pusing or popping");
            }
            else {
                printf("\t\t");
                space(count);
                printf("^missing }\n");
            }
            
            
        }

        
        
        
    }
    
    
    
    
        printf("\n");
    
    printf("\n");
    

    
    if (IsEmpty(&stack)==1){
        if (DebugMode==TRUE){
    
            printf("the stack is empty\n");
        }
        else {
            printf("Expressiong is balanced\n");
        }
    }
    else {
        {
        if (DebugMode==TRUE){
            
            printf("Stack is not empty\n");
        }
        else {
            printf("\n");
        }
    }
    }
    
    /*
     reset the stack once its done pusing/popping
     */
        Stackreset(&stack);
        
        return 0;
    
    
}
