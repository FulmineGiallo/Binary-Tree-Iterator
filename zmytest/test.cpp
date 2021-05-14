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

    lasd::Vector<int> vecint(dim);
    lasd::Vector<float> vecfloat(dim);
    lasd::Vector<string> vecstring(dim);

    typename BinaryTree<int>::Node* node_int;
    typename BinaryTree<float>::Node* node_float;
    typename BinaryTree<string>::Node* node_string;


    if(type == 1)
      riempi(vecint, dim);

    if(type == 2)
      riempi(vecfloat, dim);

    if(type == 3)
      riempiString(vecstring, dim);

    BinaryTreeVec<int> treeint(vecint);
    BinaryTreeVec<float> treefloat(vecfloat);
    BinaryTreeVec<string> treestring(vecstring);

    BTPostOrderIterator<int> postorder_int(treeint);
    BTPostOrderIterator<float> postorder_float(treefloat);
    BTPostOrderIterator<string> postorder_string(treestring);

    BTInOrderIterator<int> inorder_int(treeint);
    BTInOrderIterator<float> inorder_float(treefloat);
    BTInOrderIterator<string> inorder_string(treestring);

    BTBreadthIterator<int> breadth_int(treeint);
    BTBreadthIterator<float> breadth_float(treefloat);
    BTBreadthIterator<string> breadth_string(treestring);

    BTPreOrderIterator<int> preorder_int(treeint);
    BTPreOrderIterator<float> preorder_float(treefloat);
    BTPreOrderIterator<string> preorder_string(treestring);

    node_int = &treeint.Root();
    node_float = &treefloat.Root();
    node_string = &treestring.Root();

    while(scelta != 0)
    {
      cout << "Benevenuto nel menu del BinaryTreeVec" << endl;
      cout << "Cosa vorresti testare?" << endl;
      cout << "1. Navigazione Albero con i Nodi" << endl;
      cout << "2. Navigazione Albero con gli Iteratori" << endl;
      cout << "3. Visualizzazioni elementi {Ampiezza, Pre-ordine, ordine, post-ordine}" << endl;
      cout << "4. Controllo di esistenza di un valore" << endl;
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
        int options = -1;
        int elementoModificato = 0;

        while(options != 0)
        {
          cout << "Opzioni:" << endl;
          cout << "1: Vai verso Figlio SX se esiste" << endl;
          cout << "2: Vai verso Figlio DX se esiste" << endl;
          cout << "3: Visualizza l'elemento di questo nodo."<< endl;
          cout << "4: Modifica l'elemento di questo nodo." << endl;
          cout << "0: Per tornare al Menu Precedente" << endl;
          cin >> options;
          if(type == 1)
          {
            if(options == 1)
            {
              if(!treeint.Empty())
                  if(node_int->HasLeftChild())
                    node_int = &node_int->LeftChild();
                  else
                    cout << "Non puoi andare a sinistra, non ha figlio sx questo nodo" << endl;
            }
            if(options == 2)
            {
              if(!treeint.Empty())
                  if(node_int->HasRightChild())
                    node_int = &node_int->RightChild();
                  else
                    cout << "Non puoi andare a destra, non ha figlio dx questo nodo" << endl;
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
              if(!treeint.Empty())
                  if(node_float->HasLeftChild())
                    node_float = &node_float->LeftChild();
                  else
                    cout << "Non puoi andare a sinistra, non ha figlio sx questo nodo" << endl;
            }
            if(options == 2)
            {
              if(!treeint.Empty())
                  if(node_float->HasRightChild())
                    node_float = &node_float->RightChild();
                  else
                    cout << "Non puoi andare a destra, non ha figlio dx questo nodo" << endl;
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
              if(!treeint.Empty())
                  if(node_string->HasLeftChild())
                    node_string = &node_string->LeftChild();
                  else
                    cout << "Non puoi andare a sinistra, non ha figlio sx questo nodo" << endl;
            }
            if(options == 2)
            {
              if(!treeint.Empty())
                  if(node_string->HasRightChild())
                    node_string = &node_string->RightChild();
                  else
                    cout << "Non puoi andare a destra, non ha figlio dx questo nodo" << endl;
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
      }
      if(scelta == 2)
      {
        int choose = 0;
        int chooseOperator = 0;
        cout << "1. Ampiezza" << endl;
        cout << "2. Pre-Ordine" << endl;
        cout << "3. Ordine" << endl;
        cout << "4. Post-Ordine" << endl;
        cin  >> choose;
        if(choose == 1)
        {
          cout << "1: Visualizza l'elemento corrente (operator *)" << endl;
          cout << "2: Vai avanti con l'iterator (operator ++)" << endl;
          cin  >> chooseOperator;
          if(type == 1 && chooseOperator == 1)
          {
            if(!breadth_int.Terminated())
              cout << "Elemento corrente: " << *breadth_int << endl;
          }
          if(type == 1 && chooseOperator == 2)
          {
            if(!breadth_int.Terminated())
            {
              ++breadth_int;
              cout << "Operator ++ applicato" << endl;
            }
          }
          if(type == 2 && chooseOperator == 1)
          {
            if(!breadth_float.Terminated())
              cout << "Elemento corrente: " << *breadth_float << endl;
          }
          if(type == 2 && chooseOperator == 2)
          {
            if(!breadth_float.Terminated())
            {
              ++breadth_float;
              cout << "Operator ++ applicato" << endl;
            }
          }
          if(type == 3 && chooseOperator == 1)
          {
            if(!breadth_string.Terminated())
              cout << "Elemento corrente: " << *breadth_string << endl;
          }
          if(type == 3 && chooseOperator == 2)
          {
            if(!breadth_string.Terminated())
            {
              ++breadth_string;
              cout << "Operator ++ applicato" << endl;
            }
          }
        }
        if(choose == 2)
        {
          cout << "1: Visualizza l'elemento corrente (operator *)" << endl;
          cout << "2: Vai avanti con l'iterator (operator ++)" << endl;
          cin  >> chooseOperator;
          if(type == 1 && chooseOperator == 1)
          {
            if(!preorder_int.Terminated())
              cout << "Elemento corrente: " << *preorder_int << endl;
          }
          if(type == 1 && chooseOperator == 2)
          {
            if(!preorder_int.Terminated())
            {
              ++preorder_int;
              cout << "Operator ++ applicato" << endl;
            }
          }
          if(type == 2 && chooseOperator == 1)
          {
            if(!preorder_float.Terminated())
              cout << "Elemento corrente: " << *preorder_float << endl;
          }
          if(type == 2 && chooseOperator == 2)
          {
            if(!preorder_float.Terminated())
            {
              ++preorder_float;
              cout << "Operator ++ applicato" << endl;
            }
          }
          if(type == 3 && chooseOperator == 1)
          {
            if(!preorder_string.Terminated())
              cout << "Elemento corrente: " << *preorder_string << endl;
          }
          if(type == 3 && chooseOperator == 2)
          {
            if(!preorder_string.Terminated())
            {
              ++preorder_string;
              cout << "Operator ++ applicato" << endl;
            }
          }
        }
        if(choose == 3)
        {
          cout << "1: Visualizza l'elemento corrente (operator *)" << endl;
          cout << "2: Vai avanti con l'iterator (operator ++)" << endl;
          cin  >> chooseOperator;
          if(type == 1 && chooseOperator == 1)
          {
            if(!inorder_int.Terminated())
              cout << "Elemento corrente: " << *inorder_int << endl;
          }
          if(type == 1 && chooseOperator == 2)
          {
            if(!inorder_int.Terminated())
            {
              ++inorder_int;
              cout << "Operator ++ applicato" << endl;
            }
          }
          if(type == 2 && chooseOperator == 1)
          {
            if(!inorder_float.Terminated())
              cout << "Elemento corrente: " << *inorder_float << endl;
          }
          if(type == 2 && chooseOperator == 2)
          {
            if(!inorder_float.Terminated())
            {
              ++inorder_float;
              cout << "Operator ++ applicato" << endl;
            }
          }
          if(type == 3 && chooseOperator == 1)
          {
            if(!inorder_string.Terminated())
              cout << "Elemento corrente: " << *inorder_string << endl;
          }
          if(type == 3 && chooseOperator == 2)
          {
            if(!inorder_string.Terminated())
            {
              ++inorder_string;
              cout << "Operator ++ applicato" << endl;
            }
          }
        }
        if(choose == 4)
        {
          cout << "1: Visualizza l'elemento corrente (operator *)" << endl;
          cout << "2: Vai avanti con l'iterator (operator ++)" << endl;
          cin  >> chooseOperator;
          if(type == 1 && chooseOperator == 1)
          {
            if(!postorder_int.Terminated())
              cout << "Elemento corrente: " << *postorder_int << endl;
          }
          if(type == 1 && chooseOperator == 2)
          {
            if(!postorder_int.Terminated())
            {
              ++postorder_int;
              cout << "Operator ++ applicato" << endl;
            }
          }
          if(type == 2 && chooseOperator == 1)
          {
            if(!postorder_float.Terminated())
              cout << "Elemento corrente: " << *postorder_float << endl;
          }
          if(type == 2 && chooseOperator == 2)
          {
            if(!postorder_float.Terminated())
            {
              ++postorder_float;
              cout << "Operator ++ applicato" << endl;
            }
          }
          if(type == 3 && chooseOperator == 1)
          {
            if(!postorder_string.Terminated())
              cout << "Elemento corrente: " << *postorder_string << endl;
          }
          if(type == 3 && chooseOperator == 2)
          {
            if(!postorder_string.Terminated())
            {
              ++postorder_string;
              cout << "Operator ++ applicato" << endl;
            }
          }
        }
      }
      if(scelta == 3)
      {
        int choose = 0;
        cout << "1. Ampiezza" << endl;
        cout << "2. Pre-Ordine" << endl;
        cout << "3. Ordine" << endl;
        cout << "4. Post-Ordine" << endl;
        cin  >> choose;
        if(choose == 1)
        {
          if(type == 1)
          {
            cout << "Albero  In Ampiezza =  ";
            treeint.MapBreadth([](int & dat, void * ) {
              cout << dat << "  ";
            }, nullptr);
            cout << endl;
          }
          if(type == 2)
          {
            cout << "Albero  In Ampiezza =  ";
            treefloat.MapBreadth([](float & dat, void * ) {
              cout << dat << "  ";
            }, nullptr);
            cout << endl;
          }
          if(type == 3)
          {
              cout << "Albero In Ampiezza =  ";
            treestring.MapBreadth([](string & dat, void * ) {
              cout << dat << "  ";
            }, nullptr);
            cout << endl;
          }
        }
        if(choose == 2)
        {
          if(type == 1)
          {
            cout << "Albero  In Pre-Ordine =  ";
            treeint.MapPreOrder([](int & dat, void * ) {
              cout << dat << "  ";
            }, nullptr);
            cout << endl;
          }
          if(type == 2)
          {
              cout << "Albero  In Pre-Ordine =  ";
            treefloat.MapPreOrder([](float & dat, void * ) {
              cout << dat << "  ";
            }, nullptr);
            cout << endl;
          }
          if(type == 3)
          {
              cout << "Albero  In Pre-Ordine =  ";
            treestring.MapPreOrder([](string & dat, void * ) {
              cout << dat << "  ";
            }, nullptr);
            cout << endl;
          }
        }
        if(choose == 3)
        {
          if(type == 1)
          {
              cout << "Albero  InOrder =  ";
            treeint.MapInOrder([](int & dat, void * ) {
              cout << dat << "  ";
            }, nullptr);
            cout << endl;
          }
          if(type == 2)
          {
            cout << "Albero  InOrder =  ";
            treefloat.MapInOrder([](float & dat, void * ) {
              cout << dat << "  ";
            }, nullptr);
            cout << endl;
          }
          if(type == 3)
          {
            cout << "Albero  InOrder =  ";
            treestring.MapInOrder([](string & dat, void * ) {
              cout << dat << "  ";
            }, nullptr);
            cout << endl;
          }
        }
        if(choose == 4)
        {
          if(type == 1)
          {
            cout << "Albero  In PostOrder =  ";
            treeint.MapPostOrder([](int & dat, void * ) {
              cout << dat << "  ";
            }, nullptr);
            cout << endl;
          }
          if(type == 2)
          {
            cout << "Albero  In PostOrder =  ";
            treefloat.MapPostOrder([](float & dat, void * ) {
              cout << dat << "  ";
            }, nullptr);
            cout << endl;
          }
          if(type == 3)
          {
            cout << "Albero  In PostOrder =  ";
            treestring.MapPostOrder([](string & dat, void * ) {
              cout << dat << "  ";
            }, nullptr);
            cout << endl;
          }
        }

      }
      if(scelta == 4)
      {
        cout << "Che Elemento vuoi cercare nell'albero?" << endl;
        if(type == 1)
        {
          int search = 0;
          cin >> search;
          if(treeint.Exists(search))
            cout << "Elemento trovato" << endl;
          else
            cout << "Elemento non trovato" << endl;
        }
        if(type == 2)
        {
          float search = 0;
          cin >> search;
          if(treefloat.Exists(search))
            cout << "Elemento trovato" << endl;
          else
            cout << "Elemento non trovato" << endl;
        }
        if(type == 3)
        {
          string search;
          cin >> search;
          if(treestring.Exists(search))
            cout << "Elemento trovato" << endl;
          else
            cout << "Elemento non trovato" << endl;
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
