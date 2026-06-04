#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMORY_SIZE 1024

void display_memory(long long *memory, int size, int pointer) {
    printf("\n=== EFFICIENCY MEMORY STATE ===\n");
    printf("pointer at: %d\n\n", pointer);
    for (int i = 0; i < size; i++) {
        if (memory[i] != 0 || i == pointer) {
            if (i == pointer) {
                printf("[%d]* %lld\n", i, memory[i]);
            } else {
                printf("[%d]  %lld\n", i, memory[i]);
            }
        }
    }
    printf("================================\n\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage: efficiency <file.mint8eff>\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("error: could not open %s\n", argv[1]);
        return 1;
    }

    long long program[65536];
    int program_size = 0;
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        // strip comments
        char *comment = strchr(line, '#');
        if (comment) *comment = '\0';

        char *token = strtok(line, " \t\n\r");
        while (token) {
            program[program_size++] = atoll(token);
            token = strtok(NULL, " \t\n\r");
        }
    }
    fclose(file);

    printf("efficiency interpreter\n");
    printf("loaded %d values from %s\n\n", program_size, argv[1]);

    long long memory[MEMORY_SIZE];
    memset(memory, 0, sizeof(memory));
    int pointer = 0;
    int ip = 0;

    while (ip < program_size) {
        long long instruction = program[ip];

        switch (instruction) {
            case 1: // pointer up one
                pointer++;
                if (pointer >= MEMORY_SIZE) { printf("error: pointer out of bounds\n"); return 1; }
                ip++;
                break;

            case 2: // pointer down one
                pointer--;
                if (pointer < 0) { printf("error: pointer out of bounds\n"); return 1; }
                ip++;
                break;

            case 3: // increase pointer value
                memory[pointer]++;
                ip++;
                break;

            case 4: // decrease pointer value
                memory[pointer]--;
                ip++;
                break;

            case 5: // start of loop
                if (memory[pointer] == 0) {
                    int depth = 1;
                    ip++;
                    while (depth > 0 && ip < program_size) {
                        if (program[ip] == 5) depth++;
                        if (program[ip] == 6) depth--;
                        ip++;
                    }
                } else {
                    ip++;
                }
                break;

            case 6: // end of loop
                if (memory[pointer] != 0) {
                    int depth = 1;
                    ip--;
                    while (depth > 0 && ip >= 0) {
                        if (program[ip] == 6) depth++;
                        if (program[ip] == 5) depth--;
                        ip--;
                    }
                    ip++;
                } else {
                    ip++;
                }
                break;

            case 7: // jump to (pointer read value)
                ip = (int)memory[pointer];
                break;

            case 8: // conditional branch
                if (ip + 3 >= program_size) { printf("error: instruction 8 needs 3 following values\n"); return 1; }
                if (memory[pointer] == program[ip + 1]) {
                    ip = (int)program[ip + 2];
                } else {
                    ip = (int)memory[pointer + (int)program[ip + 3]];
                }
                break;

            default: // raw value — load into memory at pointer
                memory[pointer] = instruction;
                ip++;
                break;
        }

        display_memory(memory, MEMORY_SIZE, pointer);
    }

    printf("execution complete.\n");
    display_memory(memory, MEMORY_SIZE, pointer);

    return 0;
}
