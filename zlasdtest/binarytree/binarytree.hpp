
#ifndef BINARYTREETEST_HPP
#define BINARYTREETEST_HPP

#include "../../binarytree/binarytree.hpp"

/* ************************************************************************** */

template <typename Data>
void GetElement(int& testnum, int& testerr, const typename lasd::BinaryTree<Data>::Node& nod, bool chk, const Data& val) {
  bool tst;
  testnum++;
  std::cout << " " << testnum << " The data of the node is \"" << nod.Element() << "\": ";
  std::cout << ((tst = ((nod.Element() == val) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  testerr += (1 - (int) tst);
}

template <typename Data>
void SetElement(int& testnum, int& testerr, const typename lasd::BinaryTree<Data>::Node& nod, bool chk, const Data& val) {
  bool tst;
  testnum++;
  std::cout << " " << testnum << " Setting the front of the linear container to \"" << val << "\": ";
  nod.Element() = val;
  std::cout << ((tst = ((nod.Element() == val) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  testerr += (1 - (int) tst);
}

template <typename Data>
void IsLeaf(int& testnum, int& testerr, const typename lasd::BinaryTree<Data>::Node& nod, bool chk) {
  bool tst;
  testnum++;
  std::cout << " " << testnum << " The node is " << ((tst = nod.IsLeaf()) ? "" : "not ") << "a leaf: ";
  std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!" << std::endl;
  testerr += (1 - (int) tst);
}

template <typename Data>
void HasLeftChild(int& testnum, int& testerr, const typename lasd::BinaryTree<Data>::Node& nod, bool chk) {
  bool tst;
  testnum++;
  std::cout << " " << testnum << " The node does " << ((tst = nod.HasLeftChild()) ? "" : "not ") << "have a left child: ";
  std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!" << std::endl;
  testerr += (1 - (int) tst);
}

template <typename Data>
void HasRightChild(int& testnum, int& testerr, const typename lasd::BinaryTree<Data>::Node& nod, bool chk) {
  bool tst;
  testnum++;
  std::cout << " " << testnum << " The node does " << ((tst = nod.HasRightChild()) ? "" : "not ") << "have a right child: ";
  std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!" << std::endl;
  testerr += (1 - (int) tst);
}

template <typename Data>
void Root(int& testnum, int& testerr, lasd::BinaryTree<Data>& bt, bool chk, const Data& val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " Root of the tree with value \"" << bt.Root().Element() << "\": ";
    std::cout << ((tst = (((bt.Root().Element() == val) && (bt.Root().Element() == val)) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::length_error exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (int) tst);
}

template <typename Data>
void EqualTrees(int& testnum, int& testerr, const lasd::BinaryTree<Data>& bt1, const lasd::BinaryTree<Data>& bt2, bool chk) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " The two trees are " << ((tst = (bt1 == bt2)) ? "" : "not ") << "equal: ";
    std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (int) tst);
}

/* ************************************************************************** */

#endif
