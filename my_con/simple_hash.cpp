#include "head.h"

int addHash(string key) {
    long long hash = 0;
    const int Modulus = 1000000007;
    for (unsigned char c : key) {
        hash = (hash + (int)c) % Modulus;
    }
    return (int)hash;
}

int mulHash(string key) {
    long long hash = 0;
    const int Modulus = 1000000007;
    const int Prime = 31;
    for (unsigned char c : key) {
        hash = (hash * Prime + (int)c) % Modulus;
    }
    return (int)hash;
}

int xorHash(string key) {
    int hash = 0;
    const int Modulus = 1000000007;
    for (unsigned char c : key) {
        hash ^= (int)c;
    }
    return hash % Modulus;
}

int rotHash(string key) {
    long long hash = 0;
    const int Modulus = 1000000007;
    for (unsigned char c : key) {
        hash = ((hash << 4) ^ (hash >> 28) ^ (int)c) % Modulus;
    }
    return (int)hash;
}