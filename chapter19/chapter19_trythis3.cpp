// Chapter 19, Try This 3: modify reserve to use auto_ptr, compare to
// vector_base solution

template<class T, class A>
void vector<T,A>::reserve(int newalloc)
{
    if (newalloc<=space) return;                // never decrease allocation
    auto_ptr<T> p(alloc.allocate(newalloc));    // allocate new space

    for (int i = 0; i<sz; +i) alloc.construct(&p[i],elem[i]); // copy

    for (int i = 0; i<sz; ++i) alloc.destroy(&elem[i]);       // destroy

    alloc.deallocate(elem,space);   // deallocate old space
    elem = p.release();
    space = newalloc;
}
