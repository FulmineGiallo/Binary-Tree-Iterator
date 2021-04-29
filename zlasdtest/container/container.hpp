
#ifndef CONTAINERTEST_HPP
#define CONTAINERTEST_HPP

#include "../../container/container.hpp"

/* ************************************************************************** */

// Container member functions!

void Empty(int&, int&, const lasd::Container&, bool);

void Size(int&, int&, const lasd::Container&, bool, long);

/* ************************************************************************** */

// LinearContainer member functions!

template <typename Data>
void GetFront(int& testnum, int& testerr, const lasd::LinearContainer<Data>& con, bool chk, const Data& val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " The front of the linear container is \"" << con.Front() << "\": ";
    std::cout << ((tst = ((con.Front() == val) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::length_error exc) {
    std::cout << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << std::endl << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (int) tst);
}

template <typename Data>
void SetFront(int& testnum, int& testerr, const lasd::LinearContainer<Data>& con, bool chk, const Data& val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " Setting the front of the linear container to \"" << val << "\": ";
    con.Front() = val;
    std::cout << ((tst = ((con.Front() == val) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::length_error exc) {
    std::cout << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << std::endl << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (int) tst);
}

template <typename Data>
void GetBack(int& testnum, int& testerr, const lasd::LinearContainer<Data>& con, bool chk, const Data& val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " The back of the linear container is \"" << con.Back() << "\": ";
    std::cout << ((tst = ((con.Back() == val) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::length_error exc) {
    std::cout << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << std::endl << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (int) tst);
}

template <typename Data>
void SetBack(int& testnum, int& testerr, const lasd::LinearContainer<Data>& con, bool chk, const Data& val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " Setting the back of the linear container to \"" << val << "\": ";
    con.Back() = val;
    std::cout << ((tst = ((con.Back() == val) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::length_error exc) {
    std::cout << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << std::endl << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (int) tst);
}

template <typename Data>
void GetAt(int& testnum, int& testerr, lasd::LinearContainer<Data>& con, bool chk, const long& ind, const Data& val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " Get of the linear container at index \"" << ind << "\" with value \"" << con[ind] << "\": ";
    std::cout << ((tst = ((con[ind] == val) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::out_of_range exc) {
    std::cout << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << std::endl << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (int) tst);
}

template <typename Data>
void SetAt(int& testnum, int& testerr, lasd::LinearContainer<Data>& con, bool chk, const long& ind, const Data& val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " Set of the linear container at index \"" << ind << "\" with value \"" << val << "\": ";
    con[ind] = val;
    std::cout << ((tst = ((con[ind] == val) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::out_of_range exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << std::endl << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (int) tst);
}

/* ************************************************************************** */

// TestableContainer member functions!

template <typename Data>
void Exists(int& testnum, int& testerr, const lasd::TestableContainer<Data>& con, bool chk, const Data& val) {
  bool tst;
  testnum++;
  std::cout << " " << testnum << " Data \"" << val << "\" " << ((tst = con.Exists(val)) ? "does" : "does not") << " exist: ";
  std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!" << std::endl;
  testerr += (1 - (int) tst);
}

/* ************************************************************************** */

// MappableContainer member functions!

template <typename Data, typename Parameter>
void MapPreOrder(int& testnum, int& testerr, lasd::MappableContainer<Data>& con, bool chk, typename lasd::MappableContainer<Data>::MapFunctor fun, const Parameter& inipar) {
  bool tst = true;
  testnum++;
  Parameter par = {inipar};
  try {
    std::cout << " " << testnum << " Executing map in pre order - ";
    con.MapPreOrder(fun, &par);
    std::cout << ": " << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (int) tst);
}

template <typename Data, typename Parameter>
void MapPostOrder(int& testnum, int& testerr, lasd::MappableContainer<Data>& con, bool chk, typename lasd::MappableContainer<Data>::MapFunctor fun, const Parameter& inipar) {
  bool tst = true;
  testnum++;
  Parameter par = {inipar};
  try {
    std::cout << " " << testnum << " Executing map in post order - ";
    con.MapPostOrder(fun, &par);
    std::cout << ": " << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (int) tst);
}

template <typename Data>
void MapPrint(const Data& dat, void* _) {
  std::cout << dat << " ";
}

template <typename Data>
void MapIncrement(Data& dat, void* _) {
  dat++;
}

template <typename Data>
void MapDecrement(Data& dat, void* _) {
  dat--;
}

template <typename Data>
void MapIncrementNPrint(Data& dat, void* _) {
  std::cout << dat++ << "->" << dat << "; ";
}

template <typename Data>
void MapDouble(Data& dat, void* _) {
  dat *= 2;
}

template <typename Data>
void MapHalf(Data& dat, void* _) {
  dat /= 2;
}

template <typename Data>
void MapDoubleNPrint(Data& dat, void* _) {
  std::cout << dat << "->" << (dat *= 2) << "; ";
}

template <typename Data>
void MapInvert(Data& dat, void* _) {
  dat = -dat;
}

template <typename Data>
void MapInvertNPrint(Data& dat, void* _) {
  std::cout << dat << "->" << (dat = -dat) << "; ";
}

template <typename Data>
void MapParityInvert(Data& dat, void* _) {
  if (dat % 2 != 0) { dat = -dat; }
}

void MapStringAppend(std::string&, void*);

/* ************************************************************************** */

// FoldableContainer member functions!

template <typename Data, typename Parameter, typename Value>
void FoldPreOrder(int& testnum, int& testerr, const lasd::FoldableContainer<Data>& con, bool chk, typename lasd::FoldableContainer<Data>::FoldFunctor fun, const Parameter& inipar, const Value& inival, const Value& finval) {
  bool tst;
  testnum++;
  Parameter par = {inipar};
  Value val = inival;
  try {
    std::cout << " " << testnum << " Executing fold in pre order - ";
    con.FoldPreOrder(fun, &par, &val);
    std::cout << "obtained value is \"" << val << "\": ";
    std::cout << ((tst = ((val == finval) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (int) tst);
}

template <typename Data, typename Parameter, typename Value>
void FoldPostOrder(int& testnum, int& testerr, const lasd::FoldableContainer<Data>& con, bool chk, typename lasd::FoldableContainer<Data>::FoldFunctor fun, const Parameter& inipar, const Value& inival, const Value& finval) {
  bool tst;
  testnum++;
  Parameter par = {inipar};
  Value val = inival;
  try {
    std::cout << " " << testnum << " Executing fold in post order - ";
    con.FoldPostOrder(fun, &par, &val);
    std::cout << "obtained value is \"" << val << "\": ";
    std::cout << ((tst = ((val == finval) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (int) tst);
}

template <typename Data>
void FoldAdd(const Data& dat, const void* _, void* acc) {
  *((Data*) acc) += dat;
}

template <typename Data>
void FoldMultiply(const Data& dat, const void* _, void* acc) {
  *((Data*) acc) *= dat;
}

void FoldParity(const int&, const void*, void*);

void FoldStringConcatenate(const std::string&, const void*, void*);

/* ************************************************************************** */

// InOrderMappableContainer member functions!

template <typename Data, typename Parameter>
void MapInOrder(int& testnum, int& testerr, lasd::InOrderMappableContainer<Data>& con, bool chk, typename lasd::InOrderMappableContainer<Data>::MapFunctor fun, const Parameter& inipar) {
  bool tst = true;
  testnum++;
  Parameter par = {inipar};
  try {
    std::cout << " " << testnum << " Executing map in order - ";
    con.MapInOrder(fun, &par);
    std::cout << ": " << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (int) tst);
}

/* ************************************************************************** */

// InOrderFoldableContainer member functions!

template <typename Data, typename Parameter, typename Value>
void FoldInOrder(int& testnum, int& testerr, const lasd::InOrderFoldableContainer<Data>& con, bool chk, typename lasd::InOrderFoldableContainer<Data>::FoldFunctor fun, const Parameter& inipar, const Value& inival, const Value& finval) {
  bool tst;
  testnum++;
  Parameter par = {inipar};
  Value val = inival;
  try {
    std::cout << " " << testnum << " Executing fold in order - ";
    con.FoldInOrder(fun, &par, &val);
    std::cout << "obtained value is \"" << val << "\": ";
    std::cout << ((tst = ((val == finval) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (int) tst);
}

/* ************************************************************************** */

// BreadthMappableContainer member functions!

template <typename Data, typename Parameter>
void MapBreadth(int& testnum, int& testerr, lasd::BreadthMappableContainer<Data>& con, bool chk, typename lasd::BreadthMappableContainer<Data>::MapFunctor fun, const Parameter& inipar) {
  bool tst = true;
  testnum++;
  Parameter par = {inipar};
  try {
    std::cout << " " << testnum << " Executing map in breadth - ";
    con.MapBreadth(fun, &par);
    std::cout << ": " << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (int) tst);
}

/* ************************************************************************** */

// BreadthFoldableContainer member functions!

template <typename Data, typename Parameter, typename Value>
void FoldBreadth(int& testnum, int& testerr, const lasd::BreadthFoldableContainer<Data>& con, bool chk, typename lasd::BreadthFoldableContainer<Data>::FoldFunctor fun, const Parameter& inipar, const Value& inival, const Value& finval) {
  bool tst;
  testnum++;
  Parameter par = {inipar};
  Value val = inival;
  try {
    std::cout << " " << testnum << " Executing fold in breadth - ";
    con.FoldBreadth(fun, &par, &val);
    std::cout << "obtained value is \"" << val << "\": ";
    std::cout << ((tst = ((val == finval) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (int) tst);
}

/* ************************************************************************** */

#endif
