
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

#include "../iterator/iterator.hpp"

// #include "..."

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTree : virtual public InOrderMappableContainer<Data>
                 : virtual public BreadthMappableContainer<Data>
                 : virtual public InOrderFoldableContainer<Data>
                 : virtual public BreadthFoldableContainer<Data>
{ // Must extend InOrder/BreadthMappableContainer<Data> and InOrder/BreadthFoldableContainer<Data> in ampiezza, in order, post order, tutto virtuale.

private:

  // ...

protected:

  using BreadthMappableContainer<Data>::size;
  using InOrderMappableContainer<Data>::size;
  // ...

public:

  struct Node { //Classe astratta

  private:

    // ...

  protected:

    /* ********************************************************************** */

    // Comparison operators devono andare in protected.
    bool operator==(const Nodo&) const noexcept; // Comparison of abstract types is possible, but should not be visible.
    bool operator!=(const Nodo&) const noexcept; // Comparison of abstract types is possible, but should not be visible.

  public:

    friend class BinaryTree<Data>;
    //Se implementiamo i confronti ==, !=, per valutare la dim dell'albero.
    // i nodi non sanno quanti nodi ci stanno, ma solo Albero sa quanti nodi ci sono.


    /* ********************************************************************** */

    // Destructor
    virtual ~Node() = default;

    /* ********************************************************************** */

    // Copy assignment
    bool operator=(const Nodo&) const noexcept = delete; // Copy assignment of abstract types should not be possible.

    // Move assignment
    bool operator=(Nodo&&) noexcept = delete;  // Move assignment of abstract types should not be possible.

    /* ********************************************************************** */

    // Specific member functions

    virtual Data& Element() noexcept = 0; // Mutable access to the element (concrete function should not throw exceptions)
    virtual Data& Element() const noexcept = 0; // Immutable access to the element (concrete function should not throw exceptions)

    virtual bool IsLeaf() noexcept = 0; // (concrete function should not throw exceptions)
    virtual bool HasLeftChild() noexcept = 0 ; // (concrete function should not throw exceptions)
    virtual bool HasRightChild() noexcept = 0; // (concrete function should not throw exceptions)

    virtual Nodo&  LeftChild() = 0; // (concrete function must throw std::out_of_range when not existent)
    virtual Nodo&  RightChild() = 0; // (concrete function must throw std::out_of_range when not existent)

  };

  /* ************************************************************************ */

  // Destructor
  virtual ~BinaryTree() = default;

  /* ************************************************************************ */

  // Copy assignment
  BinaryTree& operator=(const BinaryTree&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  BinaryTree&& operator=(BinaryTree&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BinaryTree&) const noexcept; // Comparison of abstract binary tree is possible.
  bool operator!=(const BinaryTree&) const noexcept; // Comparison of abstract binary tree is possible.
  // usare i metodi del nodo per gestire
  /* ************************************************************************ */

  // Specific member functions
  virtual Nodo& Root() = 0; // (concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)
  // usare i metodi del nodo per gestire
  // using typename MappableContainer<Data>::MapFunctor;

  // type MapPreOrder(arguments) specifiers; // Override MappableContainer member
  // type MapPostOrder(arguments) specifiers; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)
  // usare i metodi del nodo per gestire
  // using typename FoldableContainer<Data>::FoldFunctor;

  // type FoldPreOrder(arguments) specifiers; // Override FoldableContainer member
  // type FoldPostOrder(arguments) specifiers; // Override FoldableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from InOrderMappableContainer)

  // type MapInOrder(arguments) specifiers; // Override InOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from InOrderFoldableContainer)

  // type FoldInOrder(arguments) specifiers; // Override InOrderFoldableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthMappableContainer)

  // type MapBreadth(arguments) specifiers; // Override BreadthMappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthFoldableContainer)

  // type FoldBreadth(arguments) specifiers; // Override BreadthFoldableContainer member

protected:

  // Auxiliary member functions (for MappableContainer)

  // type MapPreOrder(arguments) specifiers; // Accessory function executing from one node of the tree
  // type MapPostOrder(arguments) specifiers; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member functions (for FoldableContainer)

  // type FoldPreOrder(arguments) specifiers; // Accessory function executing from one node of the tree
  // type FoldPostOrder(arguments) specifiers; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member functions (for InOrderMappableContainer)

  // type MapInOrder(arguments) specifiers; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member functions (for InOrderFoldableContainer)

  // type FoldInOrder(arguments) specifiers; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member functions (for BreadthMappableContainer)

  // type MapBreadth(arguments) specifiers; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member functions (for BreadthFoldableContainer)

  // type FoldBreadth(arguments) specifiers; // Accessory function executing from one node of the tree

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderIterator : virtual public ForwardIterator<Data>
{ // Must extend ForwardIterator<Data>


private:

  BinaryTree::Node::curr = nullptr;
  StackLst<Data> stack;

protected:

  // ...

public:

  // Specific constructors
  BTPreOrderIterator(const BinaryTree<Data>&); // An iterator over a given binary tree
  // Si pone nella radice per l'ampiezza e per il pre order

  /* ************************************************************************ */

  // Copy constructor
  BTPreOrderIterator(const BinaryTree<Data>&);

  // Move constructor
  BTPreOrderIterator(BinaryTree<Data>&&);

  /* ************************************************************************ */

  // Destructor
  ~BTPreOrderIterator = default;

  /* ************************************************************************ */

  // Copy assignment
  BTPreOrderIterator& operator=(const BTPreOrderIterator&);

  // Move assignment
  // type operator=(argument) specifiers;
  BTPreOrderIterator& operator=(BTPreOrderIterator&&) noexcept;
  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTPreOrderIterator&) const noexcept;
  bool operator!=(const BTPreOrderIterator&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  Data& operator*(); // (throw std::out_of_range when terminated)
  // if iteratore è terminato, alterimenti da accesso al Nodo
  virtual bool Terminated() noexcept = 0; // (should not throw exceptions)
  // confronto di curr = null;
  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)
  BTPreOrderIterator& operator++(); // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderIterator : ForwardIterator<Data>{ // Must extend ForwardIterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Specific constructors
  BTPostOrderIterator(const BinaryTree<Data>&); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTPostOrderIterator(const BinaryTree<Data>&);

  // Move constructor
  BTPostOrderIterator(BinaryTree<Data>&&);

  /* ************************************************************************ */

  // Destructor
  ~BTPostOrderIterator = default;

  /* ************************************************************************ */

  // Copy assignment
  BTPostOrderIterator& operator=(const BTPostOrderIterator&);

  // Move assignment
  // type operator=(argument) specifiers;
  BTPostOrderIterator& operator=(BTPostOrderIterator&&) noexcept;
  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTPostOrderIterator&) const noexcept;
  bool operator!=(const BTPostOrderIterator&) const noexcept;


  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)
  Data& operator*(); // (throw std::out_of_range when terminated)
  virtual bool Terminated() noexcept = 0; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)
  BTPostOrderIterator& operator++(); // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderIterator : virtual public ForwardIterator<Data>{ // Must extend ForwardIterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Specific constructors
  BTInOrderIterator(const BinaryTree<Data>&); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTInOrderIterator(const BinaryTree<Data>&);

  // Move constructor
  BTInOrderIterator(BinaryTree<Data>&&);

  /* ************************************************************************ */

  // Destructor
  ~BTInOrderIterator = default;

  /* ************************************************************************ */

  // Copy assignment
  BTInOrderIterator& operator=(const BTInOrderIterator&);

  // Move assignment
  // type operator=(argument) specifiers;
  BTInOrderIterator& operator=(BTInOrderIterator&&) noexcept;
  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTInOrderIterator&) const noexcept;
  bool operator!=(const BTInOrderIterator&) const noexcept;


  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)
  Data& operator*(); // (throw std::out_of_range when terminated)
  virtual bool Terminated() noexcept = 0; // (should not throw exceptions)
  /* ************************************************************************ */
  // Specific member functions (inherited from ForwardIterator)
  BTInOrderIterator& operator++(); // (throw std::out_of_range when terminated)
};

/* ************************************************************************** */

template <typename Data>
class BTBreadthIterator : virtual public ForwardIterator<Data> { // Must extend ForwardIterator<Data>

private:

  // ...

protected:

  // ...

public:


    // Specific constructors
    BTBreadthIterator(const BinaryTree<Data>&); // An iterator over a given binary tree

    /* ************************************************************************ */

    // Copy constructor
    BTBreadthIterator(const BinaryTree<Data>&);

    // Move constructor
    BTBreadthIterator(BinaryTree<Data>&&);

    /* ************************************************************************ */

    // Destructor
    ~BTBreadthIterator = default;

    /* ************************************************************************ */

    // Copy assignment
    BTBreadthIterator& operator=(const BTBreadthIterator&);

    // Move assignment
    // type operator=(argument) specifiers;
    BTBreadthIterator& operator=(BTBreadthIterator&&) noexcept;
    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const BTBreadthIterator&) const noexcept;
    bool operator!=(const BTBreadthIterator&) const noexcept;
    /* ************************************************************************ */
    // Specific member functions (inherited from Iterator)
    Data& operator*(); // (throw std::out_of_range when terminated)
    virtual bool Terminated() noexcept = 0; // (should not throw exceptions)
    /* ************************************************************************ */
    // Specific member functions (inherited from ForwardIterator)
    BTBreadthIterator& operator++(); // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

}

#include "binarytree.cpp"

#endif
