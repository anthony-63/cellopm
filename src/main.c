#include <stdio.h>

#include <string.h>
#include <stdlib.h>

#define COMMAND "git clone https://github.com/anthony-63/cello-template "
#ifdef _WIN32
    #define RM_CMD "rmdir /s /q "
    #define SEP "\\"
#else
    #define RM_CMD "rm -rf "
    #define SEP "/"
#endif

void usage() {
    printf("HELP: cello --help\n");
    exit(0);
}

void help() {
    printf("cello <SUBCOMMAND>\n");
    printf("SUBCOMMANDS:\n");
    printf("\tnew <dir> -> creates folder <dir> with template project\n");
    printf("\tbuild -> build project\n");
    printf("\trun -> runs project\n");
    exit(0);
}

int main(int argc, char** argv) {
    if(argc < 2) {
        usage();
    }

    if(strcmp(argv[1], "--help") == 0) {
        help();
    }

    if(strcmp(argv[1], "new") == 0) {
        if(argc < 3) {
            printf("Invalid parameters to SUBCOMMAND 'new'\n");
            usage();
        }
        
        char* command = (char*)malloc(sizeof(char*) * strlen(COMMAND) + sizeof(char*) * strlen(argv[2]) + 1);
        sprintf(command, "%s%s", COMMAND, argv[2]);
        system(command);
        free(command);

        command = (char*)malloc(sizeof(char*) * strlen(RM_CMD) + sizeof(char*) * strlen(argv[2]) + sizeof(char*) * strlen("/.git") + 1);
        sprintf(command, "%s%s"SEP".git", RM_CMD, argv[2]);
        system(command);
        free(command);

        printf("Modify the output name in 'makefile' on line 1\n");
    } else if(strcmp(argv[1], "build") == 0) {
        system("make -B");
    } else if(strcmp(argv[1], "run") == 0) {
        system("make -B run");
    } else {
        printf("Invalid SUBCOMMAND: '%s'\n", argv[1]);
        usage();
    }
    
    return 0;
}