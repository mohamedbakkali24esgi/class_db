#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/sha.h>

// Function to calculate SHA-256 hash
void calculate_sha256(const char *input, unsigned char output[SHA256_DIGEST_LENGTH]) {
    SHA256((unsigned char*)input, strlen(input), output);
}

// Function to convert hash to hex string
char *hash_to_hex_string(unsigned char hash[SHA256_DIGEST_LENGTH]) {
    char *hex_string = malloc(SHA256_DIGEST_LENGTH * 2 + 1); // 2 hex chars per byte + 1 for null terminator
    if (hex_string == NULL) {
        perror("Unable to allocate memory for hex string");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hex_string + (i * 2), "%02x", hash[i]);
    }
    hex_string[SHA256_DIGEST_LENGTH * 2] = '\0'; // Null terminate the string
    return hex_string;
}