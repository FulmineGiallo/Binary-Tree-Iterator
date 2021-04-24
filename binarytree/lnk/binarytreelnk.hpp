
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk { // Must extend BinaryTree<Data>

private:

  // ...

protected:

  // using BinaryTree<Data>::???;

  // ...

  struct NodeLnk { // Must extend Node

  private:

    // ...

  protected:

    // Nodo sx = nulltr
    // Nodo dx = nullptr;

  public:

    // ...

  };

public:

  // Default constructor
  // BinaryTreeLnk() specifiers ; Albero vuoto.
  /* ************************************************************************ */

  // Specific constructors
  // BinaryTreeLnk(const LinearContainer<Data>&) specifiers; // A binary tree obtained from a LinearContainer
  // Albero completo.

  /* ************************************************************************ */

  // Copy constructor
  // BinaryTreeLnk(argument) specifiers;

  // Move constructor
  // BinaryTreeLnk(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BinaryTreeLnk() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  // Nodo Root() specifiers; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  void  Clear() override; // Override Container member
  // Post order per la cancellazione
  // Delete sulla radice
  // Delete dx e Delete sx dei nodi a cascata.

  //Mettere nel nodo un distruttore di dx e sx
};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
