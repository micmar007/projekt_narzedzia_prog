#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
#include <chrono>
#include <windows.h>
#include <winbase.h>


void rezerwacja();
void cennik();
void rozklad_sali();
void menu();
void open_file();
void open_file2();
void dane();
void bilet();
void wys_bilet();
void cena();
void data();

using namespace std;
int wybor,s,x,suma,a,b,miej,filmax=5,dzien,dzietyg,rok,mies,dzienmie,godzina,minuty;
string godziny[200],line[200], filename;
string tydzien[] ={"Poniedzialek", "Wtorek", "Sroda", "Czwartek", "Piatek", "Sobota", "Niedziela"};
string miesiac[] ={"Styczen", "Luty", "Marzec", "Kwiecien", "Maj", "Czerwiec", "Lipiec", "Sierpien", "Wrzesien", "Pazdziernik", "Listopad", "Grudzien"};
int liczbaDni[] ={0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
int dzienroku;
char ans,rzad,przyrostek[3];
bool flaga=false, flaga2=true;

class bilet{
public:
    char imie[20];
    char tel[11];
    char mail[30];
} t;






int main() {

    SYSTEMTIME st;
    GetSystemTime(&st);
    dzietyg=st.wDayOfWeek;
    rok=st.wYear;
    mies=st.wMonth;
    dzienmie=st.wDay;
    godzina =st.wHour;
    minuty=st.wMinute;
    dzienroku=dzienmie+liczbaDni[mies-1];


    cout<<dzienroku;
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
                wys_bilet();
                break;

            case 7:
                cout << "\n\t\t\tMamy nadzieje, ze wrocisz do nas wkrotce :)\n\n";
                system("PAUSE");
                return (0);

        }
    } while (ans == 't');

}
void rezerwacja() {

    cout << "\n\n\t\t\tAktualne seanse :\n";
    open_file();
    cout << "\n\t\t\tWybierz film (1-5) : " ;
    cin >> a;cout<< endl;
    data();
    cout << "\n\t\t\tWybierz date: " << "\t";
    cin >> s;
    cout << "\n\n\tGodziny seansow dla filmu " <<line[a-1]<<":\n";
    open_file2();
    dane();
    bilet();

}

void data(){
    cout << "\n\n\tDaty seansow dla filmu " <<line[a-1]<<":\n\n";
for (int i=0;i<7;i++){
if (dzienroku+i>liczbaDni[mies])
{
if(flaga2=true)
{
mies=mies+1;
flaga2=false;
}

dzienmie=1-i;}

if (dzietyg-1+i>6)
    cout<<i+1<<"."<< tydzien[dzietyg+i-8]<<" "<<dzienmie+i<<" "<<miesiac[mies-1]<<"\n";
else
cout<<i+1<<"."<< tydzien[dzietyg-1+i]<<" "<<dzienmie+i<<" "<<miesiac[mies-1]<<"\n";


}}

void wys_bilet(){
    cout << "\t _______________________________________________________________________\n";
     cout    << "\t\t\t\t\t           BILET\n";
       cout  << "\t    ________________________________________________________________________________\n";
    fstream file;
    file.open("bilet.txt", ios::in);
    if (!file.good()){
        cout <<"\n Brak dostepnych biletow"<<endl;
        system("pause");

    }

    int s=0;
    while(s<9)

    {

        getline(file, line[s]);
        cout << s + 1 << "." << line[s] << "\n";

        s++;
    }
    file.close();
    cout << "\n\n\t\tChcesz wrocic do MENU? (t/n)";
    cin >> ans;
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
    if(flaga){
        cout << "\n\n\t\tPodaj nazwe rzedu(A-B):";
        cin >> rzad;
        cout << "\n\n\t\tPodaj numer  miejsca(1-13):";
        cin >> miej;

    }
    if(!flaga) {
        cout << "\n\n\t\tChcesz wrocic do MENU? (t/n)";
        cin >> ans;
    }
}
void menu(){



    cout << "\n\t\t\t-------------------------------------";
    cout << "\n\t\t\t       System rezerwacji miejsc ";
    cout << "\n\t\t\t-------------------------------------";
    cout << "\n\t\t\t\tWitaj w naszym kinie! ";
    if (minuty<10){
        cout << "\n\t\tDzis mamy: "<<tydzien[dzietyg-1]<<" "<<dzienmie<<" "<<miesiac[mies-1]<<" "<<rok<<" godzina - "<<godzina+2<<":0"<<minuty;
    }
    else{
    cout << "\n\t\tDzis mamy: "<<tydzien[dzietyg-1]<<" "<<dzienmie<<" "<<miesiac[mies-1]<<" "<<rok<<" godzina - "<<godzina+2<<":"<<minuty;}
    cout << "\n\n\t\t<1> Zarezerwuj bilet";
    cout << "\n\t\t<2> Co jest grane?";
    cout << "\n\t\t<3> Cennik";
    cout << "\n\t\t<4> Promocje";
    cout << "\n\t\t<5> Rozklad sali kinowej";
    cout << "\n\t\t<6> Wyswietl zapisany bilet.";
    cout << "\n\t\t<7> Wyjscie \n";
    cout << "\n\t\tWybierz opcje 1-7:" << "\t";
}
void open_file(){  //odczyt seansow z pliku
    fstream file;
    file.open("seanse.csv", ios::in);
    if (!file.good()){
        cout <<"\n Brak dostepnych filmow"<<endl;
        system("pause");

    }

    int s=0;
    while(s<filmax)

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
    sprintf(przyrostek,"%d",a);
    filename=nazwy + przyrostek+".csv";

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
    while (z<filmax);
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
    cout << "\n\t\t\tPrzejdzmy do wyboru miejsca:\n\t";
    flaga=true;
    rozklad_sali();
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
    cout << "\n\t\t\tRzad:		" << rzad;
    cout << "\n\t\t\tMiejsce:	" << miej;
    if (dzienroku+s-1>liczbaDni[mies])
    {   mies=mies+1;
        dzienmie=1-s-1;}

    if (dzietyg-1+s-1>6)
        cout << "\n\t\t\tData:		"<< tydzien[dzietyg+s-1-8]<<" "<<dzienmie+s-1<<" "<<miesiac[mies-1]<<"\n";
    else
        cout << "\n\t\t\tData:		"<< tydzien[dzietyg-1+s-1]<<" "<<dzienmie+s-1<<" "<<miesiac[mies-1]<<"\n";

    cout << "\n\t\t\tGodzina seansu:	" <<godziny[b-1];
    cout << "\n\t\t\tSuma:   \t" << suma << " zl";
    cout << "\n\n\t\t\tChcesz zapisac bilet do pliku(t/n)";
    cin >> ans;
    if (ans=='t')
    {
        ofstream file;

        file.open("bilet.txt",ios::out);


        file<<"Nr. rezerwacji:"<<rez<<endl;
        file<<"Imie:"<<t.imie<<endl;
        file<<"Nr tel.:"<<t.tel<<endl;
        file<<"Mail:"<<t.mail<<endl;
        file<<"Rzad:"<<rzad<<endl;
        file<<"Miejsce:"<<miej<<endl;
        file<< "Godzina seansu:"<<godziny[b-1]<<endl;
        if (dzietyg-1+s-1>6)
            file<< "Data:" <<tydzien[dzietyg+s-1-8]<<" "<<dzienmie+s-1<<" "<<miesiac[mies-1] ;
        else
            file<< "Data:" <<tydzien[dzietyg-1+s-1]<<" "<<dzienmie+s-1<<" "<<miesiac[mies-1] ;
        file<<"Suma:"<<suma<<"zl"<<endl;
        file.close();
        cout << "\n\n\t\t\tZapisano!";
    }
    cout << "\n\n\t\t\tChcesz wybrac inna opcje?(t/n)";
    cin >> ans;
}
