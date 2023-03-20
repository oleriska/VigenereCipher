#include <iostream>
#include <string>

using namespace std;


int mod(int a, int b)
{
    return (b + (a % b)) % b;
}

string vigenereEncrypt(string plainText, string key) {
    string cipherText = "";
    int keyIndex = 0;
    for (char c : plainText) {
        if (isalpha(c)) {
            int offset = isupper(c) ? 'A' : 'a';
            char encryptedChar = ((c - offset + tolower(key[keyIndex]) - 'a') % 26) + offset;
            cipherText += encryptedChar;
            keyIndex = (keyIndex + 1) % key.length();
        }
        else {
            cipherText += c;
        }
    }
    return cipherText;
}

string vigenereDecrypt(string cipherText, string key) {
    string plainText = "";
    int keyIndex = 0;
    for (char c : cipherText) {
        if (isalpha(c)) {
            int offset = isupper(c) ? 'A' : 'a';
           // char decryptedChar = ((c - offset) - ((tolower(key[keyIndex]) - 'a')) % 26) + offset;
            char decryptedChar = mod((c - offset) - (tolower(key[keyIndex]) - 'a'), 26) + offset;
            plainText += decryptedChar;
            keyIndex = (keyIndex + 1) % key.length();
        }
        else {
            plainText += c;
        }
    }
    return plainText;
}



int main() {
    string plainText, key, cipherText;

    // encryption
    cout << "Enter plain text: ";
    getline(cin, plainText);
    cout << "Enter key: ";
    cin >> key;
    cipherText = vigenereEncrypt(plainText, key);
    cout << "Encrypted text: " << cipherText << endl;

    // decryption
    cout << "Enter cipher text: ";
    cin.ignore();  // clear the newline character from the input buffer
    getline(cin, cipherText);
    cout << "Enter key: ";
    cin >> key;
    plainText = vigenereDecrypt(cipherText, key);
    cout << "Decrypted text: " << plainText << endl;


    return 0;
}