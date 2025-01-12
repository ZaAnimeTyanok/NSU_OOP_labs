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
==16920== Memcheck, a memory error detector
==16920== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==16920== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==16920== Command: ./lab0_b ./in.txt ./out.csv
==16920==
==16920==
==16920== HEAP SUMMARY:
==16920==     in use at exit: 0 bytes in 0 blocks
==16920==   total heap usage: 537 allocs, 537 frees, 193,048 bytes allocated
==16920==
==16920== All heap blocks were freed -- no leaks are possible
==16920==
==16920== For lists of detected and suppressed errors, rerun with: -s
==16920== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
