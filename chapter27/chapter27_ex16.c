/* Chapter 27, exercise 16: "improve" (obfuscate) exercise 15 by using macros */

#include<stdio.h>
#include<stdlib.h>

#define GET_PTR(type,var_name) type* var_name = (type*)malloc(sizeof(type))
#define SET_FCT_PTR(pshape,pfct,fct) pshape->shape.pvtable->pfct = &fct

typedef void (*Pfct0)(struct Shape*);
typedef void (*Pfct1int)(struct Shape*, int);

typedef struct {
    Pfct0 draw;
    Pfct1int rotate;
} Vtable;

typedef struct {
    Vtable* pvtable;
    int x;
    int y;
} Shape;

typedef struct {
    Shape shape;
    int radius;
} Circle;

void draw(Shape* this)
{
    (this->pvtable->draw)(this);
}

void rotate(Shape* this, int deg)
{
    (this->pvtable->rotate)(this,deg);
}

void draw_shape(Shape* this)
{
    printf("Drawing Shape at (%d,%d)\n",this->x,this->y);
}

void rotate_shape(Shape* this, int deg)
{
    printf("Rotating Shape at (%d,%d) by %d\n",this->x,this->y,deg);
}

void draw_circle(Shape* this)
{
    Circle* pcircle = (Circle*)this;
    printf("Drawing Circle at (%d,%d) with radius %d\n",
           this->x,this->y,pcircle->radius);
}

void rotate_circle(Shape* this, int deg)
{
    Circle* pcircle = (Circle*)this;
    printf("Rotating Circle at (%d,%d) with radius %d by %d\n",
           this->x,this->y,pcircle->radius,deg);
}

Shape* init_shape(int x, int y)
{
    GET_PTR(Shape,pshape);
    GET_PTR(Vtable,pvtable);
    pvtable->draw = &draw_shape;
    pvtable->rotate = &rotate_shape;
    pshape->pvtable = pvtable;
    pshape->x = x;
    pshape->y = y;
    return pshape;
}

Circle* init_circle(int x, int y, int radius)
{
    GET_PTR(Circle,pcircle);
    pcircle->shape = *init_shape(x,y);
    SET_FCT_PTR(pcircle,draw,draw_circle);
    SET_FCT_PTR(pcircle,rotate,rotate_circle);
    pcircle->radius = radius;
    return pcircle;
}

int main()
{
    Shape* myshape = init_shape(10,10);
    Circle* mycircle = init_circle(20,20,5);
    draw(myshape);
    draw(mycircle);
    rotate(myshape,10);
    rotate(mycircle,15);
}
