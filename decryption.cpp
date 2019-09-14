//Quinton Negron
//Program takes a string input and int amount
//produces a new word that shifts each letter by that int amount
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int shiftdiff(char c)
{
    int diff;
    if ((int)c <= 90 && (int)c >= 65)
    {
        diff =(int)c - 64;
        return diff - 1;
    }
    else if ((int)c <= 122 && (int) c >= 97)
    {
        diff = (int)c - 96;
        return diff - 1;
    }
}

char shiftChar (char c, int rshift)
{
    //Checks to see if the letter ascii value of the word is within range
    //of the ascii values for lower case letters
    //This is donw to prevent the program from accidentally
    //producing a word that should exist
    //for example having "zzz" as your word and an int amount of 1
    //will case the program to spit out "[[[".
    //it's a fun experiment with ascii but means nothing for this assignment
    int newc;
    if (isalpha(c))
    {
        if((int)c <= 122 && (int)c >= 97)
        {
            newc = c - rshift;
            if(newc < 97)
            {
                newc = newc + 26;
                return newc;
            }
            else
            {
                return newc;
            }
        }
        //same as previous comments except this deals with upper case letters
        else if ((int)c <= 90 && (int)c >= 65)
        {
            newc = c - rshift;
            if (newc < 65)
            {
                newc = newc + 26;
                return newc;
            }
            else
            {
                return newc;
            }
        }
    }
    else
    {
        return c;
    }
}

//after breaking down the string to each character
//if goes through a loop that is dependent on the function above
//this part basically takes each letter, shift it by the requested amount
//and returns that shifted result
string encryptCaesar(string plaintext, int rshift)
{
    string changet;
    for (int i = 0; i < plaintext.length(); i++)
    {
        changet = changet + shiftChar(plaintext[i],rshift);
    }
    return changet;
}

string encryptVigenere(string plaintext, string keyword)
{
    string ciphertext;
    int k = 0;
    for (int i = 0; i < plaintext.length(); i++)
    {
        if (isalpha(plaintext[i]))
        {
            ciphertext = ciphertext + shiftChar(plaintext[i], shiftdiff(keyword[k%keyword.length()]));
            k++;
        }
        else
        {
            ciphertext = ciphertext + plaintext[i];
        }
    }
    return ciphertext;
}

string decryptCaesar(string ciphertext, int rshift)
{
    string plaintext;
    for (int i = 0; i < ciphertext.length(); i++)
    {
        plaintext = plaintext + shiftChar(ciphertext[i], rshift);
    }
    return plaintext;
}

string decryptVigenere(string ciphertext, string key)
{
    string plaintext;
    int k = 0;
    for (int i = 0; i < ciphertext.length(); i++)
    {
        if(isalpha(ciphertext[i]))
        {
            plaintext = plaintext + shiftChar(ciphertext[i], shiftdiff(key[k%key.length()]));
            k++;
        }
        else
        {
            plaintext = plaintext + ciphertext[i];
        }
    }
    return plaintext;
}

int main()
{
    string n,key;
    int rshift = 0;
    char c;
    cout << "Enter plaintext: ";
    //Because we are dealing with strings,
    //we don't have ot neceassrily have a cin statement
    //doing so would actually confuse the program and produce nothing
    //getline is used instead
    //so that each character in a string is read individually
    getline(cin,n);
    cout << " = Caesar = " << endl;
    cout << "Enter shift: ";
    cin >> rshift;
    cout << "Ciphertext: " << encryptCaesar(n,rshift) << endl;
    cout << "Decrypted: " << decryptCaesar ((encryptCaesar(n,rshift)),rshift) << endl;
    cout << "= Vigenere =" << endl;
    cout << "Enter keyword: ";
    cin >> key;
    cout << "Ciphertext: " << encryptVigenere(n,key) << endl;
    cout << "Decrypted: " << decryptVigenere((encryptVigenere(n,key)),key) << endl;
    //for (int i = 0; i < n.length(); i++)
    //{
    //a neat way to imagine an string is as an array
    //the string itself is comprised of individual characters
    //that the program can understand individually
    //doing so allows us to use array manipulation
    //to print out each character individually
    // same thing is done for ascii
    //but an int was added to print the ascii itself
    //  cout << n[i] << " " << (int)n[i] << endl;
    //}
    return 0;
}
