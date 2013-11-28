#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    char *buffer;
    int fSize;
    FILE *file = fopen("roms/marioland.gb", "rb");
    if(file == nullptr){printf("Error loading %s\n", "shit.gb");exit(1);};

    fseek(file, 0, SEEK_END);
    fSize = ftell(file);
    rewind(file);
    buffer = new char[fSize];
    fread(buffer, 1, fSize, file);



    fclose(file);
    delete[] buffer;
    return 0;
}
