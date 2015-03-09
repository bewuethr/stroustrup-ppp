/* Chapter 27, exercise 15: simulate single inheritance in C. Let each "base
   class" contain a pointer to an array of pointers to functions (to simulate
   virtual functions as freestanding functions taking a pointer to a "base
   class" object as their first argument); see 27.2.3. Implement "derivation" by
   making the "base class" the type of the first member of the derived class.
   
   For each class, initialize the array of "virtual functions" appropriately. To
   test the ideas, implement a version of "the old Shape example" with the base
   and derived draw() just printing out the name of their class. Use only
   language features and library facilities available in standard C. */

/* This solution uses a struct as the vtable and not an array. Also, Shape is
   not abstract and the vtables are not static, i.e., each instance of Shape
   and Circle has their own vtable, which is not optimal. A more complete
   implementation would provide destroy() functions to clean up. */

#include<stdio.h>
#include<stdlib.h>

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
    Shape* pshape = (Shape*)malloc(sizeof(Shape));
    Vtable* pvtable = (Vtable*)malloc(sizeof(Vtable));
    pvtable->draw = &draw_shape;
    pvtable->rotate = &rotate_shape;
    pshape->pvtable = pvtable;
    pshape->x = x;
    pshape->y = y;
    return pshape;
}

Circle* init_circle(int x, int y, int radius)
{
    Circle* pcircle = (Circle*)malloc(sizeof(Circle));
    pcircle->shape = *init_shape(x,y);
    pcircle->shape.pvtable->draw = &draw_circle;
    pcircle->shape.pvtable->rotate = &rotate_circle;
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
