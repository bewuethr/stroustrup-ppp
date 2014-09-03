
//
// This is example code from Chapter 27.5.3 "An example: strcpy()" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

char* strcpy(char* p, const char* q)
{
    while (*p++ = *q++);
    return p;
}

//------------------------------------------------------------------------------

int main()
{
    char buf[10];
    strcpy(buf, "Hello");
    return buf[0];
}

//------------------------------------------------------------------------------
