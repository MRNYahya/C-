#include <iostream>
using namespace std;

// deklarasi fungsi
int sum(int n);

int main(){
    int number, result;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    result = sum(number);

    printf("sum = %d", result);

    return 0;
}

// definisi fungsi
int sum(int num){
    if (num!=0)
        return num + sum(num-1); // fungsi sum() memanggil dirinya sendiri
    else
        return num;
}
