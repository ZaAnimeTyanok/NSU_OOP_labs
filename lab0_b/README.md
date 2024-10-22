# Lab0_b aka Word counter
## Description
This program counts words from .txt file ant outputs frequency statistics to .csv file

## How to use
Just call .exe file and gives to him names of inpit and output files

**Example:**
```lab0_b.exe in.txt out.csv```

## Memory leaks check

**Valgrind's report:**
```
==4921== Memcheck, a memory error detector
==4921== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==4921== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==4921== HEAP SUMMARY:
==4921==     in use at exit: 0 bytes in 0 blocks
==4921==   total heap usage: 5,472 allocs, 5,472 frees, 468,734 bytes allocated
==4921==
==4921== All heap blocks were freed -- no leaks are possible
==4921==
==4921== For lists of detected and suppressed errors, rerun with: -s
==4921== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

Also i made a function for detecting memory leaks (memcheck.cpp and memcheck.h files) based on standart functions for Visual Studio, it output results of check in VS debug output window

**Memcheck function's report:**
```
Memory check:

Memory leaks are not detected!

Memory statistics:
0 bytes in 0 Free Blocks.
0 bytes in 0 Normal Blocks.
19941 bytes in 121 CRT Blocks.
0 bytes in 0 Ignore Blocks.
0 bytes in 0 Client Blocks.
Largest number used: 412956 bytes.
Total allocations: 1249119 bytes.
```

