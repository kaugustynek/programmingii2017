#include "Punkt.h"
#include "Figura.h"
#include "Prostokat.h"
#include "Kolo.h"

int main()
{
    Figura* (figury[]) = { new Prostokat(2, 10), new Kolo(5) };

    for each (auto figura in figury)
    {
        cout << "Obwod: " << figura->Obwod() << endl;
        cout << "Pole: " << figura->Pole() << endl;
    }

    return 0;
}