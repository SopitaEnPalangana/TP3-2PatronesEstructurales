#include <iostream>
#include <memory>
#include "hotel.hpp"
#include "decorators.hpp"

using namespace std;


int main(){

    //No hago con base de datos, cargo algunos para simular un registro previo
    unique_ptr<Rentable> hotel1 = make_unique<Hotel>();
    hotel1->setDescription("Hotel Mar del Plata");
    hotel1->setBudget(50);
    hotel1 = make_unique<Beachline>(move(hotel1));

    unique_ptr<Rentable> hotel2 = make_unique<Hotel>();
    hotel2->setDescription("NH Gran Hotel Provincial");
    hotel2->setBudget(150);
    hotel2 = make_unique<Beachline>(move(hotel2));
    hotel2 = make_unique<WholePension>(move(hotel2));
    hotel2 = make_unique<VIPDiscount>(move(hotel2));

    cout << "New Housing created: " <<endl;
    cout <<endl;
    cout << hotel1->getType() <<endl;
    cout << "***    " << hotel1->getDescription() << "  ***" <<endl;
    cout <<endl;
    cout << hotel2->getType() <<endl;
    cout << "***    " << hotel2->getDescription() << "  ***" <<endl;
    cout <<endl;

    int choice = -1;
    int aloja = -1;
    int noches;
    int price;
    int budget;

    do{
        cout << "-----------------------------------------------" <<endl;
        cout << "   1 - Consultar Presupuesto   |   0 - Salir   " <<endl;
        cout << "Seleccione: ";
        cin >> choice;
        switch (choice){
            case 1:
                cout << "----------------------------------------------" <<endl;
                cout << "   1 - " << hotel1->getDescription() <<endl;
                cout << "   2 - " << hotel2->getDescription() <<endl;
                cout << "Seleccione Alojamiento: ";
                cin >> aloja;
                cout << "Cantidad de noches: ";
                cin >> noches;
                    switch (aloja){
                        case 1:
                            price = hotel1->getBudget();
                            budget = price*noches;
                            cout << "************" <<endl;
                            cout << "Presupuesto:" <<endl;
                            cout << "Alojamiento: " << hotel1->getDescription() <<endl;
                            cout << "Presupuesto por " << noches << " noche/s: $" << budget <<endl;
                            cout << "************" <<endl;
                            break;
                        case 2:
                            price = hotel2->getBudget();
                            budget = price*noches;
                            cout << "************" <<endl;
                            cout << "Presupuesto:" <<endl;
                            cout << "Alojamiento: " << hotel2->getDescription() <<endl;
                            cout << "Presupuesto por " << noches << " noche/s: $" << budget <<endl;
                            cout << "************" <<endl;
                            break;
                        default:
                            cout << "   !!!   " <<endl;
                            cout << "Alojamiento no encontrado" <<endl;
                            break;
                        }
                break;

            case 0:
                cout << "Saliendo..." <<endl;
                break;
            default:
                cout << "   !!!   " <<endl;
                cout << "Opcion invalida, intente nuevamente" <<endl;    
                continue;
            }

    } while (choice != 0);

    return 0;
}