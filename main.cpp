
#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main()
{
  int scelta = -1;
  std::cout << "Libreria numero 4 - Guarracino Carmine - N86003420" << std::endl;
  while(scelta != 0)
  {
    std::cout << "1: Test Prof.Mogavero" << std::endl;
    std::cout << "2: Menu Utente" << std::endl;
    std::cout << "0: Per uscire dal programma" << std::endl;
    std::cin  >> scelta;
    if(scelta == 1)
      lasdtest();
    if(scelta == 2)
      lasd::MenuUtente();
  }

  return 0;
}
