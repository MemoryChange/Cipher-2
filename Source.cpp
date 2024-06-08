#include <iostream>  
#include <string>    
#include <windows.h> 

using namespace std;

string encryptText(const string& text, const string& alphabet, const string& key1, const string& key2, const string& key3) 
{
    string encryptedText = text; 
    for (size_t i = 0; i < text.size(); i++) 
    {
        size_t pos = alphabet.find(text[i]); 
        if (pos != string::npos) 
        {
            if (i % 3 == 0) 
            { 
                encryptedText[i] = key1[pos];
            }
            else if (i % 3 == 1) 
            {
                encryptedText[i] = key2[pos];
            }
            else 
            {
                encryptedText[i] = key3[pos];
            }
        }
    }
    return encryptedText;
}


string decryptText(const string& text, const string& alphabet, const string& key1, const string& key2, const string& key3) 
{
    string decryptedText = text; 
    for (size_t i = 0; i < text.size(); i++) 
    {
        size_t pos = alphabet.find(text[i]); 
        if (pos != string::npos) 
        {
            if (i % 3 == 0) 
            { 
                decryptedText[i] = alphabet[key1.find(text[i])];
            }
            else if (i % 3 == 1) 
            {
                decryptedText[i] = alphabet[key2.find(text[i])];
            }
            else 
            {
                decryptedText[i] = alphabet[key3.find(text[i])];
            }
        }
    }
    return decryptedText;
}

int main() {
    SetConsoleCP(1251);      
    SetConsoleOutputCP(1251);

    string alphabet = "àáâãäå¸æçèéêëìíîïðñòóôõö÷øùúûüýþÿÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞß .,:;`|/()!?¹^-=_";
    string key1 = "æçèéêëìíîïðñòóôõö÷øùúûüýþÿàáâãäå¸ÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞß .,:;`|/()!?¹^-=_ÀÁÂÃÄÅ¨";
    string key2 = "îïðñòóôõö÷øùúàáâãäå¸æçèéêëìíûüýþÿÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞß .,:;`|/()!?¹^-=_ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍ";
    string key3 = "éöóêåíãøùçôûâàïðîëäæýúõÿ÷¸ñìèòüáþÝÆÄËÎÐÏÀÂÛÔß×ÑÌÈÒÜÁÞÚ¨ .,:;`|/()!?¹^-=_ÕÇÙØÃÍÅÊÓÖÉ";

    int choice;
    string inputText;
    string outputText;

    while (true)
    {
        cout << "Âûáåðèòå äåéñòâèå:" << endl;
        cout << "1. Çàøèôðîâàòü òåêñò" << endl;
        cout << "2. Ðàñøèôðîâàòü òåêñò" << endl;
        cout << "3. Âûéòè" << endl;
        cout << "Âàø âûáîð: " << endl << endl;
        cout << alphabet << endl;
        cout << key1 << endl;
        cout << key2 << endl;
        cout << key3 << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            
            cout << "Ââåäèòå òåêñò äëÿ øèôðîâàíèÿ: ";
            cin.ignore();  
            getline(cin, inputText); 
            outputText = encryptText(inputText, alphabet, key1, key2, key3); 
            cout << "Çàøèôðîâàííûé òåêñò: " << outputText << endl << endl; 
            break;

        case 2:
            
            cout << "Ââåäèòå òåêñò äëÿ ðàñøèôðîâêè: ";
            cin.ignore();
            getline(cin, inputText);
            outputText = decryptText(inputText, alphabet, key1, key2, key3); 
            cout << "Ðàñøèôðîâàííûé òåêñò: " << outputText << endl << endl; 
            break;

        case 3:
            
            cout << "Äî ñâèäàíèÿ!" << endl; 
            return 0; 

        default:
            
            cout << "Íåâåðíûé âûáîð. Ïîïðîáóéòå åùå ðàç." << endl << endl;
            break;
        }
        
    }
    return 0;
}