#include <stdio.h>
#include <stdlib.h>

void xor_encrypt_decrypt(const char *input_filename, const char *output_filename, char key) {
    FILE *input_file = fopen(input_filename, "rb");
    FILE *output_file = fopen(output_filename, "wb");

    if (input_file == NULL || output_file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int ch;
    while ((ch = fgetc(input_file)) != EOF) {
        fputc(ch ^ key, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_filename> <output_filename> <encryption_key>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];
    char key = argv[3][0]; // Use the first character of the key provided

    xor_encrypt_decrypt(input_filename, output_filename, key);

    printf("File '%s' has been encrypted/decrypted and saved as '%s' using key '%c'\n", input_filename, output_filename, key);
    return EXIT_SUCCESS;
}
