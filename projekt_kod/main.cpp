#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>

void rezerwacja();
void cennik();
void rozklad_sali();
void menu();
void open_file();
void open_file2();
void dane();
void bilet();
void cena();
using namespace std;
int wybor,x,suma,a,b;
string godziny[200];
string line[200];
string filename;
char ans;

char przyrostek[3];
class bilet{
public:
    char imie[20];
    char tel[11];
    char mail[30];
} t;

int main() {
    srand( time( NULL ) );
        do {

        menu();

        cin >> wybor;
        switch (wybor) {
            case 1:rezerwacja();

            break;

            case 2:
                cout << "\n\n\t\t\tU nas obejrzysz:"<<endl;
                open_file();
                cout << "\n\n\t\tChcesz wrocic do MENU? (t/n)";
                cin >> ans;
                break;
            case 3:cennik();
            break;

            case 4:
                cout << "\t\t---------------";
                cout << "\t\tTanie czwartki";
                cout << "\t\t---------------";
                cout << "\n\n\t\t\t   kazdy seans w godzinach 14-20 polowe taniej";
                cout << "\n\n\t\tChcesz wrocic do MENU? (t/n)";
                cin >> ans;
                break;
            case 5:
                rozklad_sali();
                break;
            case 6:
                cout << "\n\t\t\tMamy nadzieje, ze wrocisz do nas wkrotce :)\n\n";
                system("PAUSE");
                return (0);

        }
    } while (ans == 't');

}
void rezerwacja() {

    cout << "\n\n\t\t\tAktualne seanse :\n";
    open_file();
    cout << "\t\t\tWybierz 1-5 : " << "\t";
    cin >> a;
    cout << "\n\n\tGodziny seansow dla filmu " <<line[a-1]<<":\n";
    open_file2();
    dane();
    bilet();

}

void cennik(){

        cout << "\t\t---------------";
        cout << "\t\tFilmy 2D";
        cout << "\t---------------";
        cout << "\n\n\t\t\tNormalny:20 zl \t\tUlgowy:15 zl";
        cout << "\n\n\t\t---------------";
        cout << "\t\tFilmy 3D";
        cout << "\t---------------";
        cout << "\n\n\t\t\tNormalny:25 zl \t\tUlgowy:20 zl";
        cout << "\n\n\t\tChcesz wrocic do MENU? (t/n)";
        cin >> ans;

};
void rozklad_sali(){
    cout << "\t _______________________________________________________________________\n"
         << "\t\t\t\t\t           SCREEN\n"
         << "\t    ________________________________________________________________________________\n"
         << "\n\t           [A,1][A,2][A,3][A,4]   [A,5][A,6][A,7][A,8]   [A,9][A,10][A,11][A,12]\n"
         << "\t           [B,1][B,2][B,3][B,4]   [B,5][B,6][B,7][B,8]   [B,9][B,10][B,11][A,12]\n"
         << "\t           [C,1][C,2][C,3][C,4]   [C,5][C,6][C,7][C,8]   [C,9][C,10][C,11][A,12]\n"
         << "\t           [D,1][D,2][D,3][D,4]   [D,5][D,6][D,7][D,8]   [D,9][D,10][D,11][A,12]\n"
         << "\t           [E,1][E,2][E,3][E,4]   [E,5][E,6][E,7][E,8]   [E,9][E,10][E,11][A,12]\n\n";
    cout << "\n\n\t\tChcesz wrocic do MENU? (t/n)";
    cin >> ans;
}
void menu(){
    auto now = std::chrono::system_clock::now();
    std::time_t c_time = std::chrono::system_clock::to_time_t(now);


    cout << "\n\t\t\t-------------------------------------";
    cout << "\n\t\t\t       System rezerwacji miejsc ";
    cout << "\n\t\t\t-------------------------------------";
    cout << "\n\t\t\t\tWitaj w naszym kinie! ";
    std::cout << "Dzis mamy: " << std::ctime(&c_time);
    cout << "\n\n\t\t<1> Zarezerwuj bilet";
    cout << "\n\t\t<2> Co jest grane?";
    cout << "\n\t\t<3> Cennik";
    cout << "\n\t\t<4> Promocje";
    cout << "\n\t\t<5> Rozklad sali kinowej";
    cout << "\n\t\t<6> Wyjscie \n";
    cout << "\n\t\tWybierz opcje 1-6:" << "\t";
}
void open_file(){  //odczyt seansow z pliku
    fstream file;
    file.open("seanse.csv", ios::in);
    if (!file.good()){
        cout <<"\n Brak dostepnych filmow"<<endl;
        system("pause");

    }

    int s=0;
    while(s<5)

    {

        getline(file, line[s]);
        cout << s + 1 << "." << line[s] << "\n";

        s++;
    }
file.close();

}
void open_file2() {

    fstream file;

    string nazwy={"godziny"};
    filename=nazwy + itoa(a, przyrostek,10)+".csv";

    file.open(filename, ios::in);
    if (!file.good()) {
        cout << "\n Brak dostepnych filmow" << endl;
        system("pause");

    }

    int z = 0;
   do {

       getline(file, godziny[z]);

       cout << z + 1 << "." << godziny[z] << "\n";
       z++;
   }
        while (z<5);
    file.close();

}

void dane(){cout << "\n\n\t\tWybierz godzine: ";
    cin >> b;
    cout << "\n\n\t\tWpisz swoje imie: ";
    cin >> t.imie;
    cout << "\n\n\t\tPodaj swoj nr telefonu: ";
    cin >> t.tel;
    cout << "\n\n\t\tPodaj swoj adres email: ";
    cin >> t.mail;
    cout << "\n\t\t\tNa jaki seans chcesz kupic bilety?";
    cout << "\n\t\t\t1. 2D";
    cout << "\n\t\t\t2. 3D";
    cout << "\n\t\t\t:";
    cin >> x;
    cena();
}

    void cena() {
        int ulg, norm;
        cout << "\n\t\t\tIle biletow ulgowych chcesz kupic?";
        cout << "\n\t\t\t:";
        cin >> ulg;
        cout << "\n\t\t\tIle biletow normalnych chcesz kupic?";
        cout << "\n\t\t\t:";
        cin >> norm;


        switch (x) {
            case 1:
                suma = (ulg * 15) + (norm * 20);
                break;
            case 2:
                suma = (ulg * 20) + (norm * 25);
        }
    }
    void bilet(){
           int rez=1000+rand()%9999;
            cout << "\n\n\t\t\tTwoj bilet:\n ";
            cout << "\n\t\t\tNr. rezerwacji: "<<rez	;
            cout << "\n\t\t\tImie: 		" << t.imie;
            cout << "\n\t\t\tNr tel.:	" << t.tel;
            cout << "\n\t\t\tMail:		" << t.mail;
            cout << "\n\t\t\tGodzina seansu:	" <<godziny[b-1];
            cout << "\n\t\t\tSuma:   \t" << suma << " zl";
            cout << "\n\n\t\t\tChcesz zapisac bilet do pliku(t/n)";// zapisywanie nie dziala xd
            cin >> ans;
            if (ans=='t')
            {
                ofstream file;

                file.open("bilet.txt",ios::out);


                file<<rez;
                file<<t.imie;
                file<<t.tel;
                file<<t.mail;
                file<< godziny[b-1];
                file<<suma;
                file.close();
                cout << "\n\n\t\t\tZapisano!";
            }
            cout << "\n\n\t\t\tChcesz wybrac inna opcje?(t/n)";
            cin >> ans;
    }