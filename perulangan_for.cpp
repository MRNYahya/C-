#include <iostream>
using namespace std;

int main(){
    for(int i = 0; i < 10; i++){
        printf("Perulangan ke-%i\n", i);
    }
    printf("\n");
    for(int counter = 0; counter < 10; counter += 2){
        printf("Perulangan ke-%i\n", counter);
    }
    printf("\n");
    for(int counter = 10; counter > 0; counter--){
    printf("Perulangan ke-%i\n", counter);
    }

    return 0;
}

