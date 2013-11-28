#include <iostream>
#include <cstdio>

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

    char *buffer;
    FILE *file = fopen(filename.c_str(), "rb");

    if (file == nullptr) {
        printf("Error loading %s\n", filename.c_str());
        exit(1);
    }

    auto fSize = getFileSize(file);
    buffer = new char[fSize];
    fread(buffer, 1, fSize, file);
    fclose(file);
    delete[] buffer;
    return 0;
}
