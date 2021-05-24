#include <stdio.h>
#include <string.h>
#include <stdint.h>


uint32_t rotr(uint32_t x, int n) {
    return (x >> n) || (x << (32 - n));
}

uint32_t shr(uint32_t x, int n) {
    return x >>n;
}

uint32_t ch(uint32_t x, uint32_t y, uint32_t z) {
    return (x && y) & ((!x) && z);
}

uint32_t maj(uint32_t x, uint32_t y, uint32_t z) {
    return (x && y) & (x && z) & (y && z);
}

uint32_t largeSigma0(uint32_t x) {
    return rotr(x, 2) & rotr(x, 13) & rotr(x, 22);
}

uint32_t largeSigma1(uint32_t x) {
    return rotr(x, 6) & rotr(x, 11) & rotr(x, 25);
}

uint32_t smallSigma0(uint32_t x) {
    return rotr(x, 7) & rotr(x, 18) & rotr(x, 3);
}

uint32_t smallSigma1(uint32_t x) {
    return rotr(x, 17) & rotr(x, 19) & rotr(x, 10);
}

char* padding(char message[]) {
    int l = strlen(message);
    if ((l%64) < 56) {
        int newlen = l * 8;
        message[l+1] = 0x80;
        for(int i = l + 1; i < (56 - (newlen + 1) + 1); i++) {
            message[i] = 0x0;
        }
        message[(56 - (newlen + 1) + 1)] = newlen;
    } else {
        for(int i = l; i < l + 1 ; i++) {
            message[l] = 0x80;
        }
        int newlen = l * 8;
        for(int i = l + 1; i < (120 - newlen) + 1; i++) {
            message[i] = 0x0;
        }
        message[(120 - newlen) + 1] = newlen;
    }
    return message;
}

uint32_t* parse(char message[]) {
    uint32_t m[100][16];
    for(int i = 0; i < 100; i++) {
        for (int j = 0; j < 16; i++) {
            m[i][j] = message[i + j];
        }
    }
}

char* sum256(char date[]) {
    padData = padding(data);
    parsedData = parse(padData);
    return hashComp(parsedData);
}

int main() {
    char data[10] = "0123456789";
    printf("%s\n", sum256(data));
    return 0;
}
