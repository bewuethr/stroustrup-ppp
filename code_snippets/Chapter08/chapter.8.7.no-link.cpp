
//
// This is example code from Chapter 8.7 "Namespaces" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

namespace Graph_lib {
    struct Color { /* ... */ };
    struct Shape { /* ... */ };
    struct Line : Shape { /* ... */ };
    struct Function : Shape { /* ... */ }; 
    struct Text : Shape { /* ... */ };
    // ...
    int gui_main() { /* ... */ return 0; }
}

//------------------------------------------------------------------------------

namespace TextLib {
    class Text { /* ... */ };
    class Glyph {  /* ... */ };
    class Line {  /* ... */ };
    // ...
}

//------------------------------------------------------------------------------
