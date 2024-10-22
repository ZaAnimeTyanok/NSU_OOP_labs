#include "memchek.h"

void check_memory() {
    _CrtMemState mem_state;
    _CrtMemCheckpoint(&mem_state);
    
    OutputDebugString("\nMemory check:\n\n");

    if (!_CrtDumpMemoryLeaks()) {
        OutputDebugString("Memory leaks are not detected!\n");

    }

    OutputDebugString("\nMemory statistics:\n");
    _CrtMemDumpStatistics(&mem_state);

}
