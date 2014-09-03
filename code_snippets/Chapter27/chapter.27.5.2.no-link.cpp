
//
// This is example code from Chapter 27.5.2 "Byte operations" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <stddef.h> // required for size_t

//------------------------------------------------------------------------------

/* copy n bytes from s2 to s1 (like strcpy): */
void* memcpy(void* s1, const void* s2, size_t n); 

//------------------------------------------------------------------------------

/* copy n bytes from s2 to s1 */
void* memmove(void* s1, const void* s2, size_t n);

//------------------------------------------------------------------------------

/* compare n bytes from s2 to s1 (like strcmp): */
int memcmp(const void* s1, const void* s2, size_t n);

//------------------------------------------------------------------------------

/* find c (converted to an unsigned char) in the first n bytes of s */
void* memchr(const void* s, int c, size_t n);

//------------------------------------------------------------------------------

/* copy c (converted to an unsigned char)
into each of the first n bytes what s points to: */
void* memset(void* s, int c, size_t n);

//------------------------------------------------------------------------------
