#include <iostream>
#include <string>

using namespace std;

string cek_palindrom (const string& input) {
    string cleaned_str = "";

    for (char c : input) {
        if (isalnum(c)) {
            cleaned_str += tolower(c);
        }
    }

    int n = cleaned_str.length();
    
    for (int i = 0, j = n - 1; i < j; ++i, --j) {
        if (cleaned_str[i] != cleaned_str[j]) {
            return "False"; 
        }
    }

    return "True"; 
}

int main () {
    system("cls");
    string kalimat;

    cout << "Masukkan kalimat/kata: ";
    getline (cin, kalimat);

    string hasil = cek_palindrom(kalimat);

    cout<<"Hasil untuk " <<kalimat<<": "<<hasil<<endl;
}