#include <iostream>
using namespace std;
double fungsix(double);
double diffungsix(double);

main(){
      double x[20]={0}, fx[20], gx[20], e=0.0001,abso[20]; //gx merupakan turunan fx
      int i =0, n=9;


      puts("\t\t>>>>>>>METODE NEWTON RAPSON<<<<<<<");
      puts("\t\t\t  f(x)=x+e^x");
      puts("=================================================================");
      printf("Masukan nilai x        : ");
      scanf("%lf", &x);
      printf("Masukan nilai error    : ");
      scanf("%lf", &e);
      printf("Masukan jumlah iterasi : ");
      scanf("%d", &n);

      puts("=================================================================");
      printf("| n |      x       |       fx     |     gx       |  absolut fx  |\n");
      puts("=================================================================");
     
      while(i<=n){
            fx[i] = fungsix(x[i]);
            gx[i] = diffungsix(x[i]);
            x[i+1]= x[i] - (fx[i]/gx[i]);
            abso[i] = fx[i];
            if(abso[i]<0 data-blogger-escaped-span="">
                  abso[i] *=-1;
            printf("|%2d | %12.9lf | %12.9lf | %12.9lf | %12.9lf |\n",i+1, x[i], fx[i],gx[i],abso[i]);
           
            if(abso[i] < e)
                  break;
           
            i++;
      }
      puts("=================================================================");
      printf("Akar terletak di x %9.9lf dengan nilai fx %9.9lf\n",x[i], fx[i]);
}
double fungsix (double a){
      double hasil;
      hasil = a - exp(-a); //bisa diganti sesuai yang dingingankan
      return hasil;
}
double diffungsix (double b){
      double hasil2;
      hasil2 = 1 + exp(-b); //merupakan turunan fungsi fx
      return hasil2;
}
