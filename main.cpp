#include <iostream>
#include <cstring>
#include <string.h>
#include <fstream>
#include <istream>
#include <sstream>
#include <stdlib.h>
#include <filesystem>
#include <cstdio>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>


#define TAMMAX 10

using namespace std;


class Credencial
{
private:
    int id;
    string dominio,usuario,contrasena;
public:
    void setDominio(string dominio)
    {
        this->dominio=dominio;
    }
    void setUsuario(string usuario)
    {
        this->usuario=usuario;
    }
    void setContrasena(string contrasena)
    {
        this->contrasena=contrasena;
    }
    void setID(int id)
    {
        this->id=id;
    }
    int getID()
    {
        return id;
    }
    string getDominio()
    {
        return dominio;
    }
    string getUsuario()
    {
        return usuario;
    }
    string getContrasena()
    {
        return contrasena;
    }
    void printCredP();
    void printCredF();
};


class Wallet
{
private:
    class Nodo
    {
    public:
        Credencial cren;
        Nodo(Credencial cren)
        {
            this->cren=cren;
        }
        Credencial getCredencial()
        {
            return cren;
        }
        void setCredencial(Credencial cren)
        {
            this->cren=cren;
        }
        Nodo *next;
        Nodo *prev;
    };

    Nodo *Head;
    Nodo *Tail;
public:
    void guardar_wallet();
    void cargar_wallet();
    int numCred;
    int numNodo;
    Wallet();
    ~Wallet();
    void inserta_Final(Credencial);
    void ordenar(int);
    bool vacia();
    void imprimir();//debe imprimir solo los sitios, no usuarios ni contrasenas
    int moverse();
    void eliminar(int );
    void buscar(string );
    void editar(string );
    void RandomC(int);
//generar contrasena random
};
void Wallet::RandomC(int tam)
{

}
void EntraAdmin()
{
    char a[15];
    int contador=0;
    bool ingresa=false;
    do
    {
        cout<<"Bienvenido"<<endl;
        cout<<"Ingresa Contrasena de administrador"<<endl;
        cin>>a;
        cin.ignore();
        if(strcmp(a,"Admin123")==0)
        {
            cout<<"Acceso Permitido"<<endl;
            system("pause");
            system("cls");
            ingresa=true;
        }
        else
        {
            printf("Acceso denegado usuario incorrecto\n");
            exit(-1);
        }
    }while(ingresa=false);
}
void Credencial::printCredP()
{
    cout<<"------------------------------------------"<<endl;
    cout<<"ID: "<<id<<endl;
    cout<<"Dominio: "<<dominio<<endl;
    cout<<"------------------------------------------"<<endl;
}
void Credencial::printCredF()
{
    cout<<"------------------------------------------"<<endl;
    cout<<"ID: "<<id<<endl;
    cout<<"Dominio: "<<dominio<<endl;
    cout<<"Usuario: "<<usuario<<endl;
    cout<<"Contrasena: "<<contrasena<<endl;
    cout<<"------------------------------------------"<<endl;
}
Wallet::Wallet()
{
    Head = NULL;
    Tail = NULL;
    numNodo = 0;
    numCred = 0;
}
Wallet::~Wallet()
{
    if (Head != NULL)
    {
        Nodo *temp = Head->next;
        Nodo *temp_Head;
        while (temp != Head)
        {
            temp_Head = temp;
            temp = temp->next;
            delete temp_Head;
        }
        delete Head;
    }
}
Credencial armarCredencial(string cadena)
{
    int id, contador = 0;
    string idaux,dominio,usuario,contrasena;
    for(int i = 0; i < cadena.length(); i++)
    {
        if(contador==0)
        {
            if(cadena[i]=='|')
            {
                contador++;
            }
            else
            {
                idaux+=cadena[i];
            }
        }
        else if(contador==1)
        {
            if(cadena[i]=='|')
            {
                contador++;
            }
            else
            {
                usuario+=cadena[i];
            }
        }
        else if(contador==2)
        {
            if(cadena[i]=='|')
            {
                contador++;
            }
            else
            {
                dominio+=cadena[i];
            }
        }
        else if(contador==3)
        {
            if(cadena[i]=='|')
            {
                contador++;
            }
            else
            {
                contrasena+=cadena[i];
            }
        }
    }
    istringstream(idaux) >> id;
    Credencial nueva;
    nueva.setID(id);
    nueva.setDominio(dominio);
    nueva.setUsuario(usuario);
    nueva.setContrasena(contrasena);
    return nueva;
}
string encriptar(string frase)
{
string res;
string Clave="E";
int a,b,c;
int i,j;
int longi;
res = frase;    //Recorro la cadena para obtener la frase encriptada
for(i = 0; i < frase.length() ; i++)
{a = int (frase[i]);   //Calculo el indice de la clave
j = i % Clave.length();
b = int (Clave[j]);
//Operación xor
c = a ^ b;
//Guardo el caracter encriptado
res[i] = char( c );
}
return res;
}

string generate(int length){
  string password;
  password ="laskdfhou83";
  return password;
}
void Wallet::cargar_wallet()
{
    ifstream cargaArchivo;
    Credencial arch;
    string Credencial,convert;
    cargaArchivo.open("Credenciales.txt", ios::in|ios::app);
    while(!cargaArchivo.eof())//mientras no sea el final del archivo
    {
        getline(cargaArchivo,Credencial);
        convert=encriptar(Credencial);
        if(convert.length()> 6)
        {

            inserta_Final(armarCredencial(convert));
        }
    }
    cargaArchivo.close();
}

void Wallet::guardar_wallet()
{
    Nodo* temp = Head;
    const char* archivo = "Credenciales.txt";
    string credencial = "";
    string result;
    stringstream convertir;
    remove(archivo);
    do
    {
        convertir <<temp->getCredencial().getID();
        convertir >>credencial;
        credencial+="|"+temp->getCredencial().getUsuario() + "|"+temp->getCredencial().getDominio() + "|"+temp->getCredencial().getContrasena();
        result=encriptar(credencial);
        ofstream guardaArchivo;
        guardaArchivo.open("Credenciales.txt",ios::out|ios::app);
        guardaArchivo<<result<<endl;
        guardaArchivo.close();
        credencial = "";
        convertir.clear();
        temp=temp->next;
    }
    while(temp!=Head);
}
void Wallet::inserta_Final(Credencial cren)
{
    cren.setID(numCred);
    Nodo *nuevo_nodo = new Nodo(cren);
    if (Head == NULL)
    {
        nuevo_nodo->next = nuevo_nodo;
        nuevo_nodo->prev = nuevo_nodo;
        Head = nuevo_nodo;
        Tail = nuevo_nodo;
    }
    else
    {
        Tail->next = nuevo_nodo;
        nuevo_nodo->prev = Tail;
        nuevo_nodo->next = Head;
        Tail = nuevo_nodo;
    }
    numNodo++;
    numCred++;
}
bool Wallet::vacia()
{
    if (Head == NULL)
        return true;
    else
        return false;
}
void Wallet::imprimir()
{
    if (!vacia())
    {
        Nodo *temp = Head;
        do
        {
            temp->getCredencial().printCredP();
            temp = temp->next;
        }
        while (temp != Head);
        cout << "\n";
    }
}
int Wallet::moverse()
{
    int count = 0;
    if (!vacia())
    {
        Nodo *temp = Head;
        do
        {
            count++;
            temp = temp->next;
        }
        while (temp != Head);
    }
    return count;
}

void Wallet::eliminar(int position)
{
    if (position <= moverse())
    {
        if (position == 1)
        {
            if (moverse() == 1)
            {
                delete Head;
                Head = NULL;
                numNodo--;
            }
            else
            {
                Nodo *temp_Head = Head;
                Nodo *Tail = Head->prev;
                Head = Head->next;
                Tail->next = Head;
                Head->prev = Tail;
                delete temp_Head;
                numNodo--;
            }
        }
        else
        {
            Nodo *temp = Head;
            for (int f = 1; f <= position- 1; f++)
                temp = temp->next;
            Nodo *temp_Head = temp;
            Nodo *prev = temp->prev;
            temp = temp->next;
            prev->next = temp;
            temp->prev = prev;
            delete temp_Head;
            numNodo--;
        }
    }
}
void Wallet::buscar(string aux)
{
    if(vacia())
    {
        cout<<"La lista esta vacia"<<endl;
    }
    else
    {
        Nodo *temp_Head=Head;
        do
        {
            if(temp_Head->getCredencial().getDominio() == aux)
            {
                temp_Head->getCredencial().printCredP();
                return;
            }
            temp_Head=temp_Head->next;
        }
        while(temp_Head != Head);
        cout<<"Credencial No Encontrada!!"<<endl;
    }
}
void Wallet::editar(string aux)
{
    if(!vacia())
    {
        Nodo* temp_Head=Head;
        Nodo* temp=NULL;
        int opc2;
        do
        {
            if(temp_Head->getCredencial().getDominio()== aux)
            {
                temp=temp_Head;
            }
            temp_Head=temp_Head->next;
        }
        while(temp_Head!=Head);
        if(!temp)
        {
            cout<<"ELEMENTO NO ENCONTRADO"<<endl;
            return;
        }
        do
        {
            system("cls");
            temp->getCredencial().printCredF();
            cout<<endl<<endl;
            cout<<"MENU"<<endl;
            cout<<"1.-Editar Usuario"<<endl;
            cout<<"2.-Editar Dominio"<<endl;
            cout<<"3.-Editar Contrasena"<<endl;
            cout<<"4.-Salir"<<endl;
            cout<<"Selecciona una Opcion: "<<endl;
            cin>>opc2;
            cin.ignore();
            switch(opc2)
            {
            case 1:
            {
                string usuario;
                cout<<"Ingresa El Nuevo Usuario: "<<endl;
                getline(cin,usuario);
                temp_Head->cren.setUsuario(usuario);
                cout<<"Dato Editado Correctamente!"<<endl;
                system("pause");
                system("cls");
            }
            break;
            case 2:
            {
                string dominio;
                cout<<"Ingresa El Nuevo Dominio: "<<endl;
                getline(cin,dominio);
                temp_Head->cren.setDominio(dominio);
                cout<<"Dato Editado Correctamente!"<<endl;
                system("pause");
                system("cls");
            }
            break;
            case 3:
            {
                string contra;
                cout<<"Ingresa La nueva Contrasena: "<<endl;
                getline(cin,contra);
                temp_Head->cren.setContrasena(contra);
                cout<<"Dato Editado Correctamente!"<<endl;
                system("pause");
                system("cls");
            }
            break;
            case 4:
            {
                cout<<"Saliendo.."<<endl;
                system("pause");
                system("cls");
            }
            break;
            default:
            {
                cout<<"Opcion Invalida!"<<endl;
                system("pause");
                system("cls");
            }
            break;
            }
        }
        while(opc2 != 4);
    }
    else
    {
        cout<<"\nError. Lista vacia!";
    }
}
void Wallet::ordenar(int tipo)
{
    if(!vacia())
    {
        if(tipo==0)
        {
            Nodo* actual = Head;
            Nodo* recorre = NULL;
            Credencial copia;
            do //i
            {
                recorre = actual->next;
                do //j
                {
                    if(actual->getCredencial().getUsuario().compare(recorre->getCredencial().getUsuario())<0)
                    {
                        copia = actual->getCredencial();
                        actual->setCredencial(recorre->getCredencial());
                        recorre->setCredencial(copia);
                    }
                    recorre=recorre->next;
                }
                while(recorre!=Tail);
                actual=actual->next;
            }
            while(actual!=Tail->next);
            return;
        }
        if(tipo==1)
        {
            Nodo* actual = Head;
            Nodo* recorre = NULL;
            Credencial copia;
            do //i
            {
                recorre = actual->next;
                do //j
                {
                    if(actual->getCredencial().getDominio() < recorre->getCredencial().getDominio())
                    {
                        copia = actual->getCredencial();
                        actual->setCredencial(recorre->getCredencial());
                        recorre->setCredencial(copia);
                    }
                    recorre=recorre->next;
                }
                while(recorre!=Tail);
                actual=actual->next;
            }
            while(actual!=Tail->next);
            return;
        }
    }
    else
    {
        cout<<"\nError. Lista vacia!";
    }
}
int main(int argc, char** argv)
{
    int opc;
    Wallet *cren = new Wallet();
    EntraAdmin();
    do
    {
        cout<<"MENU"<<endl;
        cout<<"1.-Registrar Nuevo Usuario"<<endl;
        cout<<"2.-Buscar Por Dominio"<<endl;
        cout<<"3.-Ordenar Alfabeticamente Por Usuario"<<endl;
        cout<<"4.-Ordenar Alfabeticamente Por Dominio"<<endl;
        cout<<"5.-Ver todo"<<endl;
        cout<<"6.-Editar Datos De Un Usuario"<<endl;
        cout<<"7.-Borrar Registro"<<endl;
        cout<<"8.-Generar Contraseña aleatoria para algun usuario"<<endl;
        cout<<"9.-Cargar Wallet Cargado"<<endl;
        cout<<"0.-Salir"<<endl;
        cout<<"INGRESE OPCION:"<<endl;
        cin>>opc;
        cin.ignore();
        switch(opc)
        {
        case 1:
        {
            Credencial nueva;
            string usuario,dominio,contrasena;
            cout<<"Ingresa El Nombre Del Nuevo Usuario: "<<endl;
            getline(cin,usuario);
            nueva.setUsuario(usuario);
            cout<<"Ingresa El Dominio Del Nuevo Usuario: "<<endl;
            getline(cin,dominio);
            nueva.setDominio(dominio);
            cout<<"Ingresa La Contrasena Del Nuevo Usuario: "<<endl;
            getline(cin,contrasena);
            nueva.setContrasena(contrasena);
            cren->inserta_Final(nueva);
            system("pause");
            system("cls");
        }
        break;
        case 2:
        {
            string dominio;
            cout<<"Ingresa El Dominio a Buscar: "<<endl;
            getline(cin, dominio);
            cren->buscar(dominio);
            system("pause");
            system("cls");
        }
        break;
        case 3:
        {
            cren->ordenar(0);
            cren->imprimir();
            system("pause");
            system("cls");
        }
        break;
        case 4:
        {
            cren->ordenar(1);
            cren->imprimir();
            system("pause");
            system("cls");
        }
        break;
        case 5:
        {
cren->imprimir();
system("pause");
            system("cls");
        }
        break;
        case 6:
        {
            string dominio;
            cout<<"Ingresa El Dominio a Editar: "<<endl;
            getline(cin,dominio);
            cren->editar(dominio);
            system("pause");
            system("cls");
        }
        break;
        case 7:
        {
            int position;
            cout<<"Ingresa la pocision a eliminar"<<endl;
            cin>>position;
            cin.ignore();
            cren->eliminar(position);
            cout<<"Posicion Eliminada"<<endl;
            system("pause");
            system("cls");
        }
        break;
        case 8:
        {

        }
        break;
        case 9:
        {
            EntraAdmin();
            cren->cargar_wallet();
            cout<<"Datos Cargados correctamente"<<endl;
            system("pause");
            system("cls");
        }
        break;
        case 0:
        {
            cren->guardar_wallet();
            cout<<"Hasta Pronto!.."<<endl;
            system("pause");
            system("cls");
        }
        break;
        default:
            cout<<"La Opcion que elegiste no existe,intentalo de nuevo"<<endl;
            system("pause");
            system("cls");
            break;
        }
    }
    while(opc!=0);
    return 0;
}
