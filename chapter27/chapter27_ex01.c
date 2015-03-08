/* Chapter 27, exercise 1: implement versions of strlen(), strcmp() and strcpy()
*/

#include<stddef.h>
#include<stdio.h>

size_t strlen(const char* s)
{
    size_t len = 0;
    while (*s++) ++len;
    return len;
}

int strcmp(const char* s1, const char* s2)
{
    const char* p1 = s1;
    const char* p2 = s2;
    while (*p1 && *p2 && *p1==*p2) {
        ++p1;
        ++p2;
    }
    if (*p1 > *p2)
        return 1;
    else if (*p1 < *p2)
        return -1;
    else    /* *p1 == *p2 */
        return 0;
}

char* strcpy(char* s1, const char* s2)
{
    char* p = s1;
    while (*s1++ = *s2++);
    return p;
}

void test_strcmp(const char* s1, const char* s2)
{
    int res = strcmp(s1,s2);
    if (res == 0)
        printf("'%s' and '%s' are equal\n",s1,s2);
    else if (res < 0)
        printf("'%s' is before '%s'\n",s1,s2);
    else    /* res > 0 */
        printf("'%s' is after '%s'\n",s1,s2);
}

void test_strcpy(char* s1, const char* s2)
{
    printf("Copy '%s' into '%s': ",s2,s1);
    strcpy(s1,s2);
    printf("%s\n",s1);
}

int main()
{
    char* s1 = "This is a string";
    char* s2_1 = "abc";
    char* s2_2 = "abcd";
    char* s2_3 = "abd";
    char s3_1[] = "ABC";
    char s3_2[] = "abc";
    char s3_3[] = "ABCD";
    char s3_4[] = "";
        
    size_t l1 = strlen(s1);
    printf("Length of '%s': %i\n",s1,l1);
    printf("Length of '': %i\n",strlen(""));

    printf("\n");
    test_strcmp(s2_1,s2_1);
    test_strcmp(s2_1,"");
    test_strcmp("",s2_1);
    test_strcmp("","");

    test_strcmp(s2_1,s2_2);
    test_strcmp(s2_2,s2_1);

    test_strcmp(s2_2,s2_3);
    test_strcmp(s2_1,s2_3);

    printf("\n");
    test_strcpy(s3_1,s3_2);
    test_strcpy(s3_3,s3_2);
    test_strcpy(s3_1,s3_4);
    test_strcpy(s3_4,s3_4);
}
