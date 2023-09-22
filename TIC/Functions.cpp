#include <iostream>
void cleanCmd() {
    #if _WIN32 || _WIN64
        system("cls");
    #else
        system("clear");
    #endif
}
