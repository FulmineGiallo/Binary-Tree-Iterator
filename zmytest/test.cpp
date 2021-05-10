#include <iostream>
using namespace std;
#include "test.hpp"
#include <string.h>
#include <string>
#include <typeinfo>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>    // std::shuffle
#include <iostream>
#include "../stack/vec/stackvec.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../vector/vector.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../binarytree/vec/binarytreevec.hpp"
namespace lasd
{
  std::string chars {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()`~-_=+[{]{|;:'\",<.>/?"};
  std::random_device rd;
  std::mt19937 generator(rd());
  std::string rand_str (int length)
  {
     std::string output (chars);
     std::shuffle(output.begin(), output.end(), generator);
     return output.substr(0, length);
  }
  void riempiString(Vector<string>& v, int dim)
  {
    for(unsigned int i=0; i < dim; i++)
    {
       v[i] = rand_str(5);
    }
  }

  template<typename Data>
  void riempi(Vector<Data>& v, int dim)
  {
      Data dataRandom;
      srand ((unsigned int)time(NULL));
      std::string type_name();

      for(unsigned int i = 0; i < dim; i++)
      {
         dataRandom = (Data)rand() / 100 + 1;
         v[i] = dataRandom;
      }
  }

  void MenuVec(int type, int dim)
  {
    int scelta;
    BinaryTreeVec<int> treeint;
    BinaryTreeVec<float> treefloat;
    BinaryTreeVec<string> treestring;

    lasd::Vector<int> vecint(dim);
    lasd::Vector<float> vecfloat(dim);
    lasd::Vector<string> vecstring(dim);

    typename BinaryTree<int>::Node* node_int;
    typename BinaryTree<float>::Node* node_float;
    typename BinaryTree<string>::Node* node_string;

    // BTPreOrderIterator<int> preorder_int;
    // BTPreOrderIterator<float> preorder_float;
    // BTPreOrderIterator<string> preorder_string;

    if(type == 1)
    {
      riempi(vecint, dim);
      treeint = BinaryTreeVec<int>(vecint);
      node_int = &treeint.Root();
    }
    if(type == 2)
    {
      riempi(vecfloat, dim);
      treefloat = BinaryTreeVec<float>(vecfloat);
      node_float = &treefloat.Root();
    }
    if(type == 3)
    {
      riempiString(vecstring, dim);
      treestring = BinaryTreeVec<string>(vecstring);
      node_string = &treestring.Root();
    }


    while(scelta != 0)
    {
      cout << "Benevenuto nel menu del BinaryTreeVec" << endl;
      cout << "Cosa vorresti testare?" << endl;
      cout << "1. Vuoi navigare nell'albero?" << endl;
      cout << "2. Visualizzazioni elementi {Ampiezza, Pre-ordine, ordine, post-ordine}" << endl;
      cout << "3. Controllo di esistenza di un valore" << endl;
      if(type == 1) //INT
      {
        cout << "4. Prodotto per gli interi minori di n (Funzione Fold)" << endl;
        cout << "5. 3n per gli interi" << endl;
      }
      if(type == 2) //Float
      {
        cout << "4. Somma per i float maggiori di n (Funzione Fold)" << endl;
        cout << "5. n^3 per i float " << endl;
      }
      if(type == 3) //String
      {
        cout << "4. Concatenazione per le stringhe con lunghezza minore o uguale a n (Funzione Fold)" << endl;
        cout << "5. Concatenazione in testa di una specifica stringa str data " << endl;
      }
      cout << "0. Per uscire dal programma" << endl;
      cin >> scelta;
      if(scelta == 1)
      {
        int options = 0;
        int elementoModificato = 0;

        cout << "Opzioni:" << endl;
        cout << "1: Vai verso Figlio SX se esiste" << endl;
        cout << "2: Vai verso Figlio DX se esiste" << endl;
        cout << "3: Visualizza l'elemento di questo nodo."<< endl;
        cout << "4: Modifica l'elemento di questo nodo." << endl;
        cin >> options;

        if(type == 1)
        {
          if(options == 1)
          {
            if(!treeint.Empty())
              if(node_int->HasLeftChild())
                node_int = &node_int->LeftChild();

          }
          if(options == 2)
          {
            if(!treeint.Empty())
              if(node_int->HasRightChild())
                node_int = &node_int->RightChild();
          }
          if(options == 3)
            cout << "Elemento del nodo corrente: " << node_int->Element() << endl;
          if(options  == 4)
          {
            cout << "Inserisci un elemento che vuoi inserire nel nodo corrente" << endl;
            cin  >> elementoModificato;
            node_int->Element() = elementoModificato;
            cout << "Elemento inserito" << endl;
          }
        }
        if(type == 2)
        {
          if(options == 1)
          {
            if(!treefloat.Empty())
              if(node_float->HasLeftChild())
                node_float = &node_float->LeftChild();

          }
          if(options == 2)
          {
            if(!treefloat.Empty())
              if(node_float->HasRightChild())
                node_float = &node_float->RightChild();
          }
          if(options == 3)
            cout << "Elemento del nodo corrente: " << node_float->Element() << endl;
          if(options  == 4)
          {
            cout << "Inserisci un elemento che vuoi inserire nel nodo corrente" << endl;
            cin  >> elementoModificato;
            node_float->Element() = elementoModificato;
            cout << "Elemento inserito" << endl;
          }
        }
        if(type == 3)
        {
          if(options == 1)
          {
            if(!treestring.Empty())
              if(node_string->HasLeftChild())
                node_string = &node_string->LeftChild();

          }
          if(options == 2)
          {
            if(!treestring.Empty())
              if(node_string->HasRightChild())
                node_string = &node_string->RightChild();
          }
          if(options == 3)
            cout << "Elemento del nodo corrente: " << node_string->Element() << endl;
          if(options  == 4)
          {
            cout << "Inserisci un elemento che vuoi inserire nel nodo corrente" << endl;
            cin  >> elementoModificato;
            node_string->Element() = elementoModificato;
            cout << "Elemento inserito" << endl;
          }
        }


      }
      if(scelta == 2)
      {
        int iterator = 0;
        cout << "1. Ampiezza" << endl;
        cout << "2. Pre-Ordine" << endl;
        cout << "3. Ordine" << endl;
        cout << "4. Post-Ordine" << endl;
        cin  >> iterator;

        if(iterator == 1)
        {
          if(type == 1)
          {

          }
          if(type == 2)
          {

          }
          if(type == 3)
          {

          }
        }
      }
    }
  }
  void MenuLnk(int type, int dim)
  {}
  void MenuUtente()
  {
    int chooseTree = 0;
    int chooseType = 0;
    int n = 0;
    cout << "___ MENU Esercizio 3 _____" << endl;
    cout << "Che albero vuoi utilizzare?"<< endl;
    cout << "1: BinaryTreeVec" << endl;
    cout << "2: BinaryTreeLnk" << endl;
    cin  >> chooseTree;
    cout << endl;
    cout << "Che tipo di dati vuoi utilizzare in questo albero?" << endl;
    cout << "1: int" << endl;
    cout << "2: float" << endl;
    cout << "3: String" << endl;
    cin  >> chooseType;
    cout << "Quanti elementi vuoi inserire all'interno dell'albero?" << endl;
    cin  >> n;

    if(chooseTree == 1)
      MenuVec(chooseType, n);
    if(chooseTree == 2)
      MenuLnk(chooseType, n);
  }

}
