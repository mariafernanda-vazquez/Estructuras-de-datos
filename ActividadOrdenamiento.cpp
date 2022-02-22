#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
void imprimirV(const vector<T>& lista)
{
   cout << "N£meros ordenados ";
  for(int i=0; i < lista.size(); i++)
    cout << lista[i] << " ";
}

template <class T>
void selectionSort(vector<T>&lista, int total, int i, int j, int min, int ubi, int aux){
    for (i =0; i < total-1; i++)
        {
            min=lista[i];
            ubi=i;
            for(j=i+1;j<total;j++){
                if(min>lista[j]){
                    min=lista[j];
                    ubi=j;
                }
            }
            aux=lista[i];
            lista[i]=lista[ubi];
            lista[ubi]=aux;
            
        }
}

template <class T>
void insertionSort(vector<T>&lista, int totalArreglo){
    int i, orden, j;
    for(i=1; i<totalArreglo;i++){
        orden=lista[i];
        j=i-1;
        while (j >= 0 && lista[j] > orden)
        {
            lista[j + 1] = lista[j];
            j = j - 1;
        }
        lista[j + 1] = orden;
    }
}

template <class T>
void bubbleSort(vector<T>&lista, int aux, int fin){
  while (fin>0){
      for(int i=0;i<fin;i++){
          if (lista[i]>lista[i+1]){
              aux=lista[i];
              lista[i]=lista[i+1];
              lista[i+1]=aux;
          }
      }
    
      fin--;
  }
}

template <class T>
void merge(int tamIzq, int tamDer, vector<T> izq, vector<T> der, vector <T>&lista){
    int i=0, j=0, k=0;
    while (i<tamIzq && j<tamDer){
        if(izq[i]<der[j]){
            lista[k]=izq[i];
            i++;
        }
        else{
            lista[k]=der[j];
            j++;
        }
        k++;
    }
    if(i>tamIzq-1)
        for(int indice=j;indice<tamDer;indice++){
            lista[k]=der[indice];
            k++;
        }
        else{
            for(int indice=i;indice<tamIzq;indice++){
                lista[k]=izq[indice];
                k++;
            }
        }
}
template <class T>
void mergeSort(int totalArreglo, vector<T> &lista){
    if(totalArreglo>1){
        int tamIzq=totalArreglo/2;
        int tamDer= totalArreglo-tamIzq;
        vector <T> izq, der;
        for(int i=0;i<tamIzq;i++){
            izq.push_back(lista[i]);
        }
        for (int i=tamIzq;i<totalArreglo;i++){
            der.push_back(lista[i]);
        }
        mergeSort(tamIzq,izq);
        mergeSort(tamDer,der);
        merge(tamIzq, tamDer, izq,der,lista);
    }
}
template <class T>
int particion (vector<T>&lista, int inicio, int fin){
    int i=0, j=0, aux=0, indPivote=0;
    T pivote=lista[inicio];
    j=inicio;
    for(i=inicio+1;i<=fin;i++){
        if(lista[i]<pivote){
            j++;
            //intercambiar lists[i] y lists[j]
            aux=lista[i];
            lista[i]=lista[j];
            lista[j]=aux;
        }
    }
    //Intercambiar lista [inicio] y lista [indPivote]
    indPivote=j;
    aux=lista[inicio];
    lista[inicio]=lista[j];
    lista[j]=aux;
    return j;
}


template <class T>
void quicksort(int inicio, int fin, vector<T> &lista) {
    int indiceP;
    if(inicio<fin){
        indiceP=particion(lista,inicio,fin);
        quicksort(inicio,indiceP-1,lista);
        quicksort(indiceP+1, fin,lista);
    }
}

int main()
{
  int input, respuestaMetodo=0,control=0,i=0,j=0,ubi,min,aux,posMenor,orden, fin, inicio=0;
  vector<int> lista;
  cout << "Escribe el numero: " << endl;
    while ((cin >> input) && input != 9999)
    lista.push_back(input);
    int totalArreglo=lista.size();
    cout<<"el total de arreglo es: "<<totalArreglo;
    cout<<"\nQue deseas realizar\n1.Con Seleccion\n2.Con insertion\n3.Bubble";
    cin>>respuestaMetodo;

  switch(respuestaMetodo){
      //m‚todo de seleccion 
      case 1:
        selectionSort(lista, totalArreglo, i,j,min,ubi,aux);
        imprimirV(lista);
      break;

        //metodo de insertion
      case 2:
        insertionSort(lista, totalArreglo);
        imprimirV(lista);
      break;

      case 3:
        fin=lista.size()-1;
        bubbleSort(lista,aux,fin);
        imprimirV(lista);
        break;

      case 4:
        mergeSort(totalArreglo, lista);
        imprimirV(lista);
        break;
      case 5:
      int inicio=0;
      int fin=lista.size()-1;
      quicksort(inicio,fin,lista);
      imprimirV(lista);

  }
  return 0;
}
