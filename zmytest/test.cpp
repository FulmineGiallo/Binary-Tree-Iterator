#include <iostream>
using namespace std;
#include "test.hpp"
#include "../binarytree/vec/binarytreevec.hpp"
namespace lasd
{

  void MenuVec(int type, int dim)
  {
    int scelta;
    BinaryTreeVec<int> treeint;
    BinaryTreeVec<float> treefloat;
    BinaryTreeVec<string> treestring;

    Vector<int> vecint(dim);
    Vector<float> vecfloat(dim);
    Vector<string> vecstring(dim);

    if(type == 1)
    {
      //Riempire vettore
      treeint = BinaryTreeVec<int>(vecint);
    }
    if(type == 2)
    {
      //Riempire vettore
      treefloat = BinaryTreeVec<float>(vecfloat);
    }
    if(type == 3)
    {
      //Riempire vettore
      treestring = BinaryTreeVec<string>(vecstring);
    }


    cout << "Benevenuto nel menu del BinaryTreeVec" << endl;
    cout << "Cosa vorresti testare?" << endl;
    cout << "1. Visualizzazioni elementi {Ampiezza, Pre-ordine, ordine, post-ordine}" << endl;
    cout << "2. Controllo di esistenza di un valore" << endl;
    if(type == 1) //INT
    {
      cout << "3. Prodotto per gli interi minori di n (Funzione Fold)" << endl;
      cout << "4. 3n per gli interi" << endl;
    }
    if(type == 2) //Float
    {
      cout << "3. Somma per i float maggiori di n (Funzione Fold)" << endl;
      cout << "4. n^3 per i float " << endl;
    }
    if(type == 3) //String
    {
      cout << "3. Concatenazione per le stringhe con lunghezza minore o uguale a n (Funzione Fold)" << endl;
      cout << "4. Concatenazione in testa di una specifica stringa str data " << endl;
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
