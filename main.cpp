#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

static char* read_file(const char* path) {
    auto file = fopen(path, "rb");
    if (!file)  {
        printf("Unable to open '%s': %s\n", path, strerror(errno));
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    auto size = ftell(file);
    fseek(file, 0, SEEK_SET);

    auto text = static_cast<char*>(malloc(size + 1));
    assert(text);

    assert(fread(text, size, 1, file) == 1);
    text[size] = 0;

    fclose(file);

    return text;
}

int main(int argc, char** argv) {
    printf("Hello Davinci1204\n");

    auto text = read_file(argv[1]);
    printf("%s", text);
    free(text);
}
