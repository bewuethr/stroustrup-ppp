# Exercises from "Programming &ndash; Principles and Practice using C++" by Stroustrup

Exercises from Stroustrup's ["Programming &ndash; Principles and Practice Using
C++" (First Edition)][1]. Some sample solutions by Stroustrup can be found
[here][2]. The directory `ppt_slides` contains the *old* version of the slides
on [Stroustrup's website][3], as the current ones are updated for the 2nd
edition of the book and C++11. In `code_snippets` are all the code examples in
the book, taken from [the book's website][4].

[1]: http://www.informit.com/store/programming-principles-and-practice-using-c-plus-plus-9780321543721
[2]: http://www.stroustrup.com/Programming/Solutions/exercise_solutions.html
[3]: http://www.stroustrup.com/Programming/lecture-slides.html
[4]: http://www.stroustrup.com/Programming/PPP1.html

I was working with Visual Studio 2013 Express for Chapters 1&ndash;18, then I
changed to [Code::Blocks][5]. Everything I've uploaded here was tested to
compile in Code::Blocks using [MinGW][6] GCC 4.8.1. From Chapter 21 on, I
switched to Visual Studio Community 2013.

[5]: http://www.codeblocks.org
[6]: http://www.mingw.org

Notice that some solutions require using an older C++ standard when compiling,
for example Chapter 17 exercise 4: use something like

```sh
g++ --std=c++03
```

to compile (under Linux).

Chapter 1 has no programming exercises, and for Chapter 2 I just went along and
changed the same file over and over, so these solutions are not here.

Chapters 12&ndash;16 deal with GUI/graphics and use [FLTK][7]. The actual work
there is not in the files containing `main`, but in `lib_files/Graph.cpp` and
`lib_files/Simple_window.cpp`. I've done a little write-up about setting up
FLTK under Visual Studio Community 2013 [here][8].

[7]: http://www.fltk.org/index.php
[8]: http://bewuethr.github.io/installing-fltk-133-under-visual-studio/
