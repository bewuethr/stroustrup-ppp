
//
// This is example code from Chapter 25.5.4 "Bit manipulation" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

void f(short val)    // assume 16-bit, 2-byte sort integer
{
    unsigned char left = val&0xff;        // leftmost (least significant) byte
    unsigned char right = (val>>8)&0xff;  // rightmost (most significant) byte
    // ...
    bool negative = val&0x800;            // sign bit
    // ...
}

//------------------------------------------------------------------------------

// When we want to name bits, we often use enumerations. For example:
enum Printer_flags {
    acknowledge=1,
    paper_empty=1<<1,
    busy=1<<2,
    out_of_black=1<<3,
    out_of_color=1<<4, 
    // ...
};

//------------------------------------------------------------------------------

int main()
{
    unsigned char x = out_of_color | out_of_black; // x becomes 12 (8+4)
    x |= paper_empty;                              // x becomes 13 (8+4+1)

    if (x& out_of_color) {                         // is out_of_color set? (yes, it is)
        // ... 
    }

    // We can still use & to mask:

    unsigned char y = x &(out_of_color | out_of_black); // x becomes 12

    Printer_flags z = Printer_flags(out_of_color | out_of_black); // the cast is necessary 
}

//------------------------------------------------------------------------------
