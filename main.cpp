#include <QCoreApplication>
#include <iostream>

using namespace std;

struct stringy
{
    char * str; // указывает на строку
    int ct; // длина строки (не считая символа '\0')
};

// Здесь размещаются прототипы функций set() и show()
void set(stringy& beany, const char testing[]);
void show(const stringy& beany, int n = 1);
void show(const char testing[], int n = 1);

void set(stringy& beany, const char testing[])
{
    beany.str = new char[strlen(testing) + 1];  // получение нового хранилища
    strcpy(beany.str, testing);  // копирование строки в новое хранилище
    beany.ct = strlen(testing);
}

void show(const stringy& beany, int n)
{
    for (int i = 0; i < n; ++i) {
        cout << "str = " << beany.str << endl;
    }
}

void show(const char testing[], int n)
{
    for (int i = 0; i < n; ++i) {
        cout << "str = " << testing << endl;
    }
}

int main(int argc, char *argv[])
{
    std::cout << "Start program.\n";
    QCoreApplication a(argc, argv);

    stringy beany;
    char testing[] = "Reality isn't what it used to be.";
    set (beany, testing) ; // первым аргументом является ссылка,
    // Выделяет пространство для хранения копии testing,
    // использует элемент типа str структуры beany как указатель
    // на новый блок, копирует testing в новый блок и
    // создает элемент ct структуры beany
    show(beany) ; // выводит строковый член структуры один раз
    show(beany, 2) ; // выводит строковый член структуры два раза

    testing[0] = 'D' ;
    testing[1] = 'u' ;
    show(testing);  // выводит сроку testing один раз
    show(testing, 3) ; // выводит сроку testing 3 раза
    show("Done!") ;

//    char * ps;
//    ps = new char[strlen(testing) + 1]; // получение нового хранилища
//    strcpy (ps, testing) ; // копирование строки в новое хранилище
//    cout << ps << endl;

    cout << "Bye.";
    return a.exec();
}


