#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

namespace {

long getFileSize(FILE *file)
{
    fseek(file, 0, SEEK_END);
    auto size = ftell(file);
    rewind(file);
    return size;
}

}

int main(int argc, char *argv[])
{
    string filename;

    if (argc > 1)
        filename = argv[1];
    else
        filename = "roms/marioland.gb";

    FILE *file = fopen(filename.c_str(), "rb");

    if (file == nullptr) {
        printf("Error opening \"%s\" for reading.\n"
               "Reason: %s\n", filename.c_str(), strerror(errno));
        exit(1);
    }

    auto fSize = getFileSize(file);
    char *buffer = new char[fSize];
    fread(buffer, 1, fSize, file);
    fclose(file);
    delete[] buffer;
    return 0;
}
