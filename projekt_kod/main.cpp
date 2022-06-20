#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
void rezerwacja();
void cennik();
void rozklad_sali();
void menu();
void open_file();
using namespace std;
int wybor,x,suma;
char ans;
class bilet{
public:
    char imie[20];
    char tel[11];
} t;

int main() {

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

    cout << "\n\n\t\t\tAktualne seanse :";
    open_file();
    cout << "\t\t\tWybierz 1-5 :" << "\t";
    int a;
    cin >> a;
    cout << "\n\n\t\t\tGodziny seansow dla wybranego przez ciebie filmu";
    switch (a) {
        case 1:
            cout << "\n\n\t\t\tWybierz godzine: ";
            cout << "\n\t\t\t1. 11:00";
            cout << "\n\t\t\t2. 13:00";
            cout << "\n\t\t\t3. 14:50";
            cout << "\n\t\t\t4. 18:00";
            cout << "\n\t\t\t5. 21:00";
            cout << "\n\t\t\t6. 01:00 \n";
            cout << "\n\n\t\tWybierz godzine: ";
            int b;
            cin >> b;
            cout << "\n\n\t\tWpisz swoje imie: ";
            cin >> t.imie;
            cout << "\n\n\t\tPodaj swoj nr telefonu: ";
            cin >> t.tel;
            cout << "\n\t\t\tNa jaki seans chcesz kupic bilety?";
            cout << "\n\t\t\t1. 2D";
            cout << "\n\t\t\t2. 3D\n";
            cin >> x;
            switch (x) {
                case 1:
                    int ulg_2d, norm_2d;
                    cout << "\n\t\t\tIle biletow ulgowych chcesz kupic?";
                    cin >> ulg_2d;
                    cout << "\n\t\t\tIle biletow normalnych chcesz kupic?";
                    cin >> norm_2d;
                    suma = (ulg_2d * 15) + (norm_2d * 20);
                    break;
                case 2:
                    int ulg_3d, norm_3d;
                    cout << "\n\t\t\tIle biletow ulgowych chcesz kupic?";
                    cin >> ulg_3d;
                    cout << "\n\t\t\tIle biletow normalnych chcesz kupic?";
                    cin >> norm_3d;
                    suma = (ulg_3d * 15) + (norm_3d * 20);
                    break;
            }
            cout << "\n\n\t\t\tTwoj bilet ";
            cout << "\n\t\t\tImie 		    :" << t.imie;
            cout << "\n\t\t\tNr tel.	  \t:" << t.tel;
            cout << "\n\t\t\tGodzina seansu	:";
            switch (b) {
                case 1:
                    cout << "08:00";
                    break;
                case 2:
                    cout << "13:00";
                    break;
                case 3:
                    cout << "14:50";
                    break;
                case 4:
                    cout << "18:00";
                    break;
                case 5:
                    cout << "21:00";
                    break;
                case 6:
                    cout << "01:00";
                    break;
            }
            cout << "\n\t\t\tSuma   	 \t:" << suma << " zl";

            cout << "\n\n\t\t\tChcesz wybrac inna opcje?(t/n)";
            cin >> ans;
            break;
        case 2:
            cout << "\n\n\t\t\tWybierz godzine:";
            cout << "\n\t\t\t1. 09:00";
            cout << "\n\t\t\t2. 11:00";
            cout << "\n\t\t\t3. 12:50";
            cout << "\n\t\t\t4. 15:00";
            cout << "\n\t\t\t5. 20:00";
            cout << "\n\t\t\t6. 22:00";
            cout << "\n\t\t\tWybierz godzine: ";
            cin >> b;
            cout << "\n\n\t\t\tWpisz imie: ";
            cin >> t.imie;
            cout << "\n\t\t\tPodaj nr telefonu: ";
            cin >> t.tel;
            cout << "\n\t\t\tNa jaki seans chcesz kupic bilety?";
            cout << "\n\t\t\t1. 2D";
            cout << "\n\t\t\t2. 3D\n";
            cin >> x;
            switch (x) {
                case 1:
                    int ulg_2d, norm_2d;
                    cout << "\n\t\t\tIle biletow ulgowych chcesz kupic?";
                    cin >> ulg_2d;
                    cout << "\n\t\t\tIle biletow normalnych chcesz kupic?";
                    cin >> norm_2d;
                    suma = (ulg_2d * 15) + (norm_2d * 20);
                    break;
                case 2:
                    int ulg_3d, norm_3d;
                    cout << "\n\t\t\tIle biletow ulgowych chcesz kupic?";
                    cin >> ulg_3d;
                    cout << "\n\t\t\tIle biletow normalnych chcesz kupic?";
                    cin >> norm_3d;
                    suma = (ulg_3d * 15) + (norm_3d * 20);
                    break;
            }
            cout << "\n\n\t\t\tTwoj bilet ";
            cout << "\n\t\t\tImie 		    :" << t.imie;
            cout << "\n\t\t\tNr tel.	    :" << t.tel;
            cout << "\n\t\t\tGodzina seansu	:";
            switch (b) {
                case 1:
                    cout << "08:00";
                    break;
                case 2:
                    cout << "13:00";
                    break;
                case 3:
                    cout << "14:50";
                    break;
                case 4:
                    cout << "18:00";
                    break;
                case 5:
                    cout << "21:00";
                    break;
                case 6:
                    cout << "01:00";
                    break;
            }
            cout << "\n\t\t\tSuma   	 \t:" << suma << " zl";
            cout << "\n\n\t\t\tChcesz wybrac inna opcje?(t/n)";
            cin >> ans;

            break;
        case 3:
            cout << "\n\n\t\t\tGodziny seansu";
            cout << "\n\t\t\t1. 08:00";
            cout << "\n\t\t\t2. 13:00";
            cout << "\n\t\t\t3. 14:50";
            cout << "\n\t\t\t4. 18:00";
            cout << "\n\t\t\t5. 21:00";
            cout << "\n\t\t\t6. 01:00";
            cout << "\n\t\t\tWybierz godzine seansu";
            cin >> b;
            cout << "\n\t\t\tWpisz swoje imie: ";
            cin >> t.imie;
            cout << "\n\t\t\tPodaj nr telefonu: ";
            cin >> t.tel;
            cout << "\n\t\t\tNa jaki seans chcesz kupic bilety?";
            cout << "\n\t\t\t1. 2D";
            cout << "\n\t\t\t2. 3D\n";
            cin >> x;
            switch (x) {
                case 1:
                    int ulg_2d, norm_2d;
                    cout << "\n\t\t\tIle biletow ulgowych chcesz kupic?";
                    cin >> ulg_2d;
                    cout << "\n\t\t\tIle biletow normalnych chcesz kupic?";
                    cin >> norm_2d;
                    suma = (ulg_2d * 15) + (norm_2d * 20);
                    break;
                case 2:
                    int ulg_3d, norm_3d;
                    cout << "\n\t\t\tIle biletow ulgowych chcesz kupic?";
                    cin >> ulg_3d;
                    cout << "\n\t\t\tIle biletow normalnych chcesz kupic?";
                    cin >> norm_3d;
                    suma = (ulg_3d * 15) + (norm_3d * 20);
                    break;
            }
            cout << "\n\n\t\t\tTwoj bilet ";
            cout << "\n\t\t\tImie 		    :" << t.imie;
            cout << "\n\t\t\tNr tel.	    :" << t.tel;
            cout << "\n\t\t\tGodzina seansu	:";
            switch (b) {
                case 1:
                    cout << "08:00";
                    break;
                case 2:
                    cout << "13:00";
                    break;
                case 3:
                    cout << "14:50";
                    break;
                case 4:
                    cout << "18:00";
                    break;
                case 5:
                    cout << "21:00";
                    break;
                case 6:
                    cout << "01:00";
                    break;
            }
            cout << "\n\t\t\tSuma   	 \t:" << suma << " zl";
            cout << "\n\n\t\t\tChcesz wybrac inna opcje?(t/n)";
            cin >> ans;
            break;
        case 4:

            cout << "\n\n\t\t\tGodziny seansu: ";
            cout << "\n\t\t\t1. 08:00";
            cout << "\n\t\t\t2. 13:00";
            cout << "\n\t\t\t3. 14:50";
            cout << "\n\t\t\t4. 18:00";
            cout << "\n\t\t\t5. 21:00";
            cout << "\n\t\t\t6. 01:00";
            cout << "\n\t\t\tWybierz godzine seansu: ";
            cin >> b;
            cout << "\n\t\t\tWpisz swoje imie: ";
            cin >> t.imie;
            cout << "\n\t\t\tPodaj nr telefonu: ";
            cin >> t.tel;
            cout << "\n\t\t\tNa jaki seans chcesz kupic bilety?";
            cout << "\n\t\t\t1. 2D";
            cout << "\n\t\t\t2. 3D";
            cin >> x;
            switch (x) {
                case 1:
                    int ulg_2d, norm_2d;
                    cout << "\n\t\t\tIle biletow ulgowych chcesz kupic?";
                    cin >> ulg_2d;
                    cout << "\n\t\t\tIle biletow normalnych chcesz kupic?";
                    cin >> norm_2d;
                    suma = (ulg_2d * 15) + (norm_2d * 20);
                case 2:
                    int ulg_3d, norm_3d;
                    cout << "\n\t\t\tIle biletow ulgowych chcesz kupic?";
                    cin >> ulg_3d;
                    cout << "\n\t\t\tIle biletow normalnych chcesz kupic?";
                    cin >> norm_3d;
                    suma = (ulg_3d * 15) + (norm_3d * 20);
            }
            cout << "\n\n\t\t\tTwoj bilet ";
            cout << "\n\t\t\tImie 		    :" << t.imie;
            cout << "\n\t\t\tNr tel.	    :" << t.tel;
            cout << "\n\t\t\tGodzina seansu	:";
            switch (b) {
                case 1:
                    cout << "08:00";
                    break;
                case 2:
                    cout << "13:00";
                    break;
                case 3:
                    cout << "14:50";
                    break;
                case 4:
                    cout << "18:00";
                    break;
                case 5:
                    cout << "21:00";
                    break;
                case 6:
                    cout << "01:00";
                    break;
            }
            cout << "\n\t\t\tSuma   	 \t:" << suma << " zl";
            cout << "\n\n\t\t\tBilet nalezy odebrac 20 minut przed seansem w kasie kina.";
            cout << "\n\n\t\t\tChcesz wybrac inna opcje(t/n)";
            cin >> ans;
            break;
        case 5:

            cout << "\n\n\t\t\tGodziny seansow:";
            cout << "\n\t\t\t1. 08:00";
            cout << "\n\t\t\t2. 13:00";
            cout << "\n\t\t\t3. 14:50";
            cout << "\n\t\t\t4. 18:00";
            cout << "\n\t\t\t5. 21:00";
            cout << "\n\t\t\t6. 01:00";
            cout << "\n\t\t\tWybierz godzine: ";
            cin >> b;
            cout << "\n\t\t\tWpisz swoje imie: ";
            cin >> t.imie;
            cout << "\n\t\t\tPodaj nr telefonu: ";
            cin >> t.tel;
            cout << "\n\t\t\tNa jaki seans chcesz kupic bilety?";
            cout << "\n\t\t\t1. 2D";
            cout << "\n\t\t\t2. 3D\n";
            cin >> x;
            switch (x) {
                case 1:
                    int ulg_2d, norm_2d;
                    cout << "\n\t\t\tIle biletow ulgowych chcesz kupic?";
                    cin >> ulg_2d;
                    cout << "\n\t\t\tIle biletow normalnych chcesz kupic?";
                    cin >> norm_2d;
                    suma = (ulg_2d * 15) + (norm_2d * 20);
                    break;
                case 2:
                    int ulg_3d, norm_3d;
                    cout << "\n\t\t\tIle biletow ulgowych chcesz kupic?";
                    cin >> ulg_3d;
                    cout << "\n\t\t\tIle biletow normalnych chcesz kupic?";
                    cin >> norm_3d;
                    suma = (ulg_3d * 15) + (norm_3d * 20);
                    break;

            }
            cout << "\n\n\t\t\tTwoj bilet ";
            cout << "\n\t\t\tImie 		    :" << t.imie;
            cout << "\n\t\t\tNr tel.	    :" << t.tel;
            cout << "\n\t\t\tGodzina seansu	:";
            switch (b) {
                case 1:
                    cout << "08:00";
                    break;
                case 2:
                    cout << "13:00";
                    break;
                case 3:
                    cout << "14:50";
                    break;
                case 4:
                    cout << "18:00";
                    break;
                case 5:
                    cout << "21:00";
                    break;
                case 6:
                    cout << "01:00";
                    break;
                default:
                    cout << "\n\t\t\tWybierz liczbe 1-6\n";
                    break;
            }
            cout << "\n\t\t\tSuma   	 \t:" << suma << " zl";
            cout << "\n\n\t\t\tBilet nalezy odebrac 20 minut przed seansem w kasie kina.";
            cout << "\n\n\t\t\tChcesz wybrac inna opcje?(t/n)";
            cin >> ans;
            system("cls");
            break;
    }
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
    time_t czas;
    struct tm * data;
    char godzina[ 80 ];
    time( & czas );
    data = localtime( & czas );
    strftime( godzina, 80, " %H:%M", data );

    cout << "\n\t\t\t-------------------------------------";
    cout << "\n\t\t\t       System rezerwacji miejsc ";
    cout << "\n\t\t\t-------------------------------------";
    cout << "\n\t\t\t\tWitaj w naszym kinie!";
    cout<< "\n\t\t\t\tJest godzina:"<<godzina;
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
        main();
    }
    string line;
    while(!file.eof())
    {
        getline(file,line);
        cout<<line<<"\n";
    }
file.close();

}