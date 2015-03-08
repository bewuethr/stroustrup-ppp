/*  Chapter 27, drill
    1. Write a Hello World program
    2. Define two variables holding "Hello" and "World!", concatenate them with
       a space in between and output them as "Hello World!"
    3. Define a function taking a char* p and an int x, print their values in
       the format "p is 'foo' and x is 7". Call it with a few argument pairs. */

#include<stdlib.h>
#include<string.h>
#include<stdio.h>

void my_func(char* p, int x)
{
    printf("p is \"%s\" and x is %i\n",p,x);
}

int main()
{
    printf("Hello World!\n");
    {
        char* hello = "Hello";
        char* world = "World!";
        char* hello_world = (char*) malloc(strlen(hello)+strlen(world)+2);
        strcpy(hello_world,hello);
        hello_world[strlen(hello)] = ' ';
        strcpy(hello_world+strlen(hello)+1,world);
        printf("%s\n",hello_world);
    }
    my_func("foo",7);
    my_func("Scott Meyers",42);
    my_func("Bjarne Stroustrup",99);
}