#include <conio.h>
#include <iostream>
int main()
{
    int A[20];
    int i, j, nilai,batas,baru,a,b,c,d,k;
    cout << "\t\tPROGRAM ARRAY\n";
   cout<<"\nMasukkan Jumlah Elemen : ";
   cin >> batas;
   cout<<"\n=========================================================================="<<endl;

//menampilkan nilai yang terdapat pada elemen array
    for(i=0;i<batas;i++)
    {
        cout<<"\nData Indeks ["<<i<<"]= ";cin>>A[i];
    }
    cout<<endl;
//memasukkan nilai yang akan dicari
    cout<<"\nMasukkan nilai yang akan dicari= ";
    cin>>nilai;

//melakukan pencarian data
    for(j=0;j<batas;j++)
    {
    if(A[j]==nilai)
    {
    cout<<"\nNilai yang dicari terdapat pada INDEKS ["<<j<<"]";
    }
   }
   cout<<"\n\n============================================================================";
//mengganti data
cout<<endl;
cout<<"\nMasukkan indeks yang ingin diganti : ";
cin>>c;
cout<<"\nMasukkan data pengganti : ";
cin>>baru;
a = c;
A[a] = baru;
cout<<"\nData yang baru  : \n";

for(b=0;b<batas;b++)
{
 cout<<"\nData["<<b<<"]="<<A[b]<<"\n";
}
//menghapus data
cout<<"\n============================================================================";
cout<<endl;
cout<<"\nMasukkan indeks yang ingin dihapus : ";
cin>>d;
i=d;
cout<<"\nNilai yang dihapus : ";
cout<<" "<<A[i]<<" pada INDEKS ["<<i<<"] \n";
cout<<"\nNilai akhir : \n";
for(j=d;j<batas;j++)
{
 A[j]=A[j+1];
}
for(k=0;k<batas-1;k++)
{
 cout<<"\nData["<<k<<"]="<<A[k];
}
getch();
}