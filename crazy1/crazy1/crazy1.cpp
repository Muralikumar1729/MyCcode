
//  i(#define Murali kumar).................... am lazy  ;) :)
#include "stdafx.h"
#include "iostream"
#include "cmath"
#include "conio.h"
#include "windows.h"

using namespace std;

int main()
{
    double x, y, size=10;
    char ch=3;
    string message(" i am lazy ");
    int print_line = 4;

    if (message.length() % 2 != 0) message += " ";

    for (x=0;x<size;x++)
    {
        for (y=0;y<=4*size;y++)
        {
            double dist1 = sqrt( pow(x-size,2) + pow(y-size,2) );
            double dist2 = sqrt( pow(x-size,2) + pow(y-3*size,2) );

            if (dist1 < size + 0.5 || dist2 < size + 0.5 ) {
                cout << ch;Sleep(100);
            }
			else {cout << " ";Sleep(100);}
        }
        cout<<"\n";Sleep(100);
    }

    for (x=1;x<2*size;x++)
    {
        for(y=0;y<x;y++) {cout << " ";Sleep(100);}

        for (y=0; y<4*size + 1 - 2*x; y++)
        {
            if (x >= print_line - 1 && x <= print_line + 1) {
                int idx = y - (4*size - 2*x - message.length()) / 2;
                if (idx < message.length() && idx >= 0) {
					if (x == print_line) {cout<<message[idx];Sleep(1000);}
					else {cout << " ";Sleep(100);}
                }
				else {cout << ch;Sleep(100);}
            }
			else {cout << ch;Sleep(100);}
        }
        cout<<endl;Sleep(100);
    }
}
