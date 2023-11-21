#include<iostream>
#include<cctype>
using namespace std;
void countVowelsConsonants(char myString[],int &vowels, int & consonants)
{
    for(int i=0;myString[i]!='\0';i++)
    {
        switch(tolower(myString[i]))
        {
            case 'a':

            case 'e':
            case 'i':
            case 'o':
            case 'u':
            vowels = vowels + 1;

            break;

            case ' ':
            break;
            default:

            consonants = consonants + 1;

        }
    }
}
int main()
{
    char myString[] = "hello to the world of c Hope YOU ARE DOING WELL";

    int vowels, consonants;
    vowels = consonants = 0;
    
    countVowelsConsonants(myString,vowels,consonants);
    
cout<<myString<<endl;
    cout<<"the number of vowels is "<<vowels<<
    " \n and the number of consonants is "<<consonants<<endl;

    return 0;
}




