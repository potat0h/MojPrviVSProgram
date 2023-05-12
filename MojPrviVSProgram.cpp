#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int n;
    string a;
    int brojac = 0;
    fstream datoteka;
    datoteka.open("imenik.txt", ios::in);
    while (getline(datoteka, a))
    {
        cout << a << endl;
        brojac++;
    }

    datoteka.close();
    datoteka.open("imenik.txt", ios::in);
    string* ucenici1 = new string[brojac];
    for(int i=0;i<brojac;i++)
    {
        getline(datoteka, ucenici1[i]);
    }
    datoteka.close();
    cout << "Upisi broj novih ucenika: ";
    cin >> n;
    string* ucenici2 = new string[n];
    cin.ignore();
    cout << "Upisi prezime i ime novih ucenika: " << endl;
    for (int i = 0; i < n; i++)
    {
        getline(cin, ucenici2[i]);
    }
    string* ucenici = new string[brojac + n];

    copy(ucenici1, ucenici1 + brojac, ucenici);
    copy(ucenici2, ucenici2 + n, ucenici + brojac);

    std::sort(ucenici, ucenici + (n+brojac));

    
    datoteka.open("imenik.txt", ios::out);
    for (int i=0;i<brojac+n;i++)
    {
        datoteka << ucenici[i] << endl;
    }

    datoteka.close();
    return 0;
}
