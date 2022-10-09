#include <iostream>
using namespace std;

int main(){

    string password;

    cout << "========= Login =========" << endl;
    cout << "Masukan password: ";
    cin >> password;

    // percabangan if/else
    if (password == "kopi"){
        cout << "Selamat datang bos!" << endl;
    } else {
        cout << "Password salah, coba lagi!"  << endl;
    }

    cout << "Terimakasih sudah menggunakan aplikasi ini!" << endl;

    return 0;
}
