---
title: Home
layout: default
---

Scheme interpreter in c++
=========================
* this a simple RSR5 Scheme implementation done in c++  
* project is called sexp_cpp (it morphed out of a s-expressions interpreter)  
* this is **work in progress** project! Scheme implementation is not complete yet!
* it's developed and tested on mac so it might not work strait out of the box on
  Linux (but it will in a future)

Requirements:
------------
- compilers: [clang](http://clang.llvm.org/) or [g++](http://gcc.gnu.org/) (any modern will do)
- [boost](http://www.boost.org/) (any modern will do)
- [ruby](http://www.ruby-lang.org/) and rake (for Rakefile, learn about it
  [here](http://martinfowler.com/articles/rake.html))
- [googletest](http://code.google.com/p/googletest/) for functional and unit tests
- Project is tested on MacOs 10.6  
- Rakefile expects BOOST_INC env variable to be set
- Rakefile expects googletest to be installed in /opt/local/lib

Random installation / rake tips:
-------------------------------
1. Clone git repo from github  
`git clone git://github.com/nazgob/sexp_cpp.git`  
2. Change directory to sex_cpp  
`cd sex_cpp`  
3. Use rake lib to build lib  
`rake lib`
4. Use rake exec to build interpreter itself  
`rake exec`  
5. Use rake test to build tests (if you have googletest installed)  
`rake test`  
6. Use rake run to run tests  
`rake run`  
7. Use rake (default task) to build lib, tests and run tests with one command  
`rake`  
8. Run interpreter and play with Scheme  
`bin/sexp`  
9. Stop interpreter session with CTRL-C  
`^C`  
10. Have fun! :)

Live sexp_cpp session preview:
------------------------------------
    [sexp_cpp (master)]$ bin/sexp 
    sexp> 123
    123
    sexp> -456
    -456
    sexp> #t
    #t
    sexp> #f
    #f
    sexp> "foobar"
    eval crashed => trying to eval NULL!
    NULL
    sexp> (quote (1 2 3))
    (1 2 3)
    sexp> '(1 2 3)
    (1 2 3)
    sexp> (define foo 55)
    ok
    sexp> foo
    55
    sexp> (set! foo 42)
    ok
    sexp> foo
    42
    sexp> (if #t 1 2)
    1
    sexp> (if #t (quote 1) 42))
    1
    sexp> (+ 1 2 3 4 5)
    15
    sexp> (null? (+ 1 2))
    #f
    sexp> (null? ())
    #t
    sexp> (boolean? #f)
    #t
    sexp> (define bazz 5)
    ok
    sexp> (define bar 7)
    ok
    sexp> (+ bazz bar)
    12
    sexp> ((lambda (x) (+ x 2)) 42)
    44


Problems:
---------
1. Check if you have Rake, its bundled with Ruby 1.9 but if you're on 1.8 you
   might need to install it:  
   Mac: `sudo port install rake`  
   Ubuntu: `sudo apt-get install rake`  

Author:
------
Copyright (c) 2011 [Przemek Owczarek](http://twitter.com/powczarek), released under the MIT license

