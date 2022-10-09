#include <iostream>
using namespace std;
int n = 0;
// deklarasi fungsi
void foo1(void);
void foo2(void);
// mendefinisikan fungsi rekursi
void foo1() {
 if (n <= 20) {
 cout << n << " "; // mencetak n
 n++; // increments n by 1
 foo2(); // memanggil foo2()
 } else
 return;
}

void foo2() {
 if (n <= 20) {
 cout << n << " "; // mencetak n
 n++; // increments n by 1
 foo1(); // memanggil foo1()
 } else
 return;
}

// Driver Program
int main(void) {
 foo1();
 return 0;
}
