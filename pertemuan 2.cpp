#include <iostream>
using namespace std;
main()
{
	int *p;
	
	int val[7] = { 11, 22, 33, 44, 55, 66, 77 } ;
	
	p = &val[0];
	
	for( int i = 0 ; i <= 6 ; i++ )
	{
		cout << "val ke [" << i << "] : memiliki nilai " << *p << " dengan alamat " << p << endl;
		p++;
	}
}
