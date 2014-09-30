// Chapter 20, Try This 6: rewrite advance() so that it will "go backward" when
// you give it a negative argument

template<class Iter> void advance(Iter& p, int n)
{
    if (n>0) {
        while (n>0) { ++p; --n; }
    }
    else if (n<0) {
        while (n<0) { --p; ++n; }
    }
}

// That's right. Untested.
