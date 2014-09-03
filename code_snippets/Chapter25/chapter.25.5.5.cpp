
//
// This is example code from Chapter 25.5.5 "Bitfields" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

struct PPN { // R6000 Physical Page Number
    unsigned int PFN : 22 ;    // Page Frame Number
    int : 3 ;                  // unused
    unsigned int CCA : 3 ;     // Cache Coherency Algorithm
    bool nonreachable : 1 ;
    bool dirty : 1 ;
    bool valid : 1 ;
    bool global : 1 ;
};

//------------------------------------------------------------------------------

void part_of_VM_system(PPN * p )
{
    // ...
    if (p->dirty) { // contents changed
                    // copy to disc
        p->dirty = 0 ;
    }
    // ...
}

//------------------------------------------------------------------------------

int main()
{
    // Automatic extraction
    {
        PPN pn = {0};
        unsigned int x = pn.CCA;         // extract CCA
    }

    // Manual extraction
    {
        unsigned int pn = 0;
        unsigned int y = (pn>>3)&0x7;    // extract CCA
    }
}

//------------------------------------------------------------------------------
