#include <iostream>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;


//scrivo la funzione per effettuare il cambio di intervallo
double mappaValori(double oldValue)
{
    //x1=1; x2=5; y1 =-1; y2 = 2;
    double newValue = ((oldValue-1)*(0.75))-1 ; //funzione che permette il passaggio: y = mx+q dove m=(y2-y1)/(x2-x1)=3/4  e q come intersezione dell'asse y con la retta data q= -7/4;
    return newValue;
}


int main()
{
    string nameFile = "data.csv";
    ifstream fstr(nameFile);             //effettuo l'apertura del file


    if (!fstr.is_open())                      //se il file non viene trovato
    { cerr<<"impossibile aprire il file"<<endl;
        return 1;                         //numero diverso da 0 = errore
    }


    else
    {
        //creo il file di output
        ofstream outputFile("result.csv");
        outputFile<<"#N mean"<<endl;


        //inizializzo i --> numero di valori letti nel file di lettura
        unsigned int i = 0;
        double sum = 0;
        double value;

        while ( fstr >> value ) //cicla fino alla fine del file
        {
            i++;
            value = mappaValori(value);   //passo il valore alla funzione per poterlo mappare
            sum += value; //aggiorno la somma per ogni ciclo
            double mean = sum/i;
            outputFile<< i << "       " << scientific << setprecision(15) << mean << endl;
        }
        outputFile.close();
    }
    fstr.close();
    return 0;
}
