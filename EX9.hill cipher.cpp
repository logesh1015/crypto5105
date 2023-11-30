#include <stdio.h>

#define ALPHABET_SIZE 26

int isValidCharacter(char c) {
    return (c >= 'A' && c <= 'Z');
}
void multiplyMatrices(int matrix1[2][2], int matrix2[2][2], int result[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void encryptHillCipher(char plaintext[], char ciphertext[], int key[2][2]) {
    int plaintextVector[2][1], ciphertextVector[2][1];

    for (int i = 0; i<plaintext,length(); i++) {
        if (isValidCharacter(plaintext[i])) {
            plaintextVector[0][0] = plaintext[i] - 'A';
            multiplyMatrices(key, plaintextVector, ciphertextVector);
            ciphertext[i] = (ciphertextVector[0][0] % ALPHABET_SIZE) + 'A';
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
}


void decryptHillCipher(char ciphertext[], char plaintext[], int key[2][2], int keyInverse[2][2]) {
    int ciphertextVector[2][1], plaintextVector[2][1];

    for (int i = 0; i < ciphertext.length(); i++) {
        if (isValidCharacter(ciphertext[i])) {
            ciphertextVector[0][0] = ciphertext[i] - 'A';
            multiplyMatrices(keyInverse, ciphertextVector, plaintextVector);
            plaintext[i] = (plaintextVector[0][0] % ALPHABET_SIZE) + 'A';
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
}

int main() {
    char plaintext[] = "meet me at the usual place at ten rather than eight oclock";
    char ciphertext[sizeof(plaintext)];
    char decryptedText[sizeof(plaintext)];

    int key[2][2] = {{9, 4}, {5, 7}};

    
    encryptHillCipher(plaintext, ciphertext, key);
    printf("Encrypted text: %s\n", ciphertext);

   
    decryptHillCipher(ciphertext, decryptedText, key, inverse(key));
    printf("Decrypted text: %s\n", decryptedText);

    return 0;
}
