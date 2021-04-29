
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../iterator/iterator.hpp"
#include "../queue/lst/queuelst.hpp"
#include "../stack/lst/stacklst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTree: virtual public InOrderMappableContainer<Data>,
                  virtual public InOrderFoldableContainer<Data>,
                  virtual public BreadthMappableContainer<Data>,
                  virtual public BreadthFoldableContainer<Data>{ // Must extend InOrder/BreadthMappableContainer<Data> and InOrder/BreadthFoldableContainer<Data>

private:

  // ...

protected:

   using BreadthMappableContainer<Data>::size;
   using InOrderMappableContainer<Data>::size;

public:

  struct Node {

  private:

    // ...

  protected:

    // Comparison operators
    // type operator==(argument) specifiers;
    // Comparison of abstract types is possible, but should not be visible.
    bool operator==(const Node&) const noexcept;

    // type operator!=(argument) specifiers;
    // Comparison of abstract types is possible, but should not be visible.
    bool operator!=(const Node&) const noexcept;

  public:

     friend class BinaryTree<Data>;

    /* ********************************************************************** */

    // Destructor
    // ~Node() specifiers
    virtual ~Node() = default;

    /* ********************************************************************** */

    // Copy assignment
    // type operator=(argument);
    // Copy assignment of abstract types should not be possible.
    Node& operator=(const Node&) = delete;

    // Move assignment
    // type operator=(argument);
    // Move assignment of abstract types should not be possible.
    Node& operator=(Node&&) noexcept = delete;

    /* ********************************************************************** */

    // Specific member functions

    // type Element() specifiers;
    // Mutable access to the element (concrete function should not throw exceptions)
    virtual Data& Element() noexcept = 0;

    // type Element() specifiers;
    // Immutable access to the element (concrete function should not throw exceptions)
    virtual Data& Element() const noexcept = 0;

    // type IsLeaf() specifiers;
    // (concrete function should not throw exceptions)
    virtual bool IsLeaf() noexcept = 0;

    // type HasLeftChild() specifiers;
    // (concrete function should not throw exceptions)
    virtual bool HasLeftChild() noexcept = 0;


    // type HasRightChild() specifiers;
    // (concrete function should not throw exceptions)
    virtual bool HasRightChild() noexcept = 0;

    // type LeftChild() specifiers;
    // (concrete function must throw std::out_of_range when not existent)
    virtual Node& LeftChild() = 0;

    // type RightChild() specifiers;
    // (concrete function must throw std::out_of_range when not existent)
    virtual Node& RightChild() = 0;

  };

  /* ************************************************************************ */

  // Destructor
  // ~BinaryTree() specifiers
  virtual ~BinaryTree() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);
  // Copy assignment of abstract types should not be possible.
  BinaryTree& operator=(const BinaryTree&) = delete;

  // Move assignment
  // type operator=(argument);
  // Move assignment of abstract types should not be possible.
  BinaryTree& operator=(BinaryTree&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // Comparison of abstract binary tree is possible.
  bool operator==(const BinaryTree&) const noexcept;

  // type operator!=(argument) specifiers;
  // Comparison of abstract binary tree is possible.
  bool operator!=(const BinaryTree&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions
  // type Root() specifiers;
  // (concrete function must throw std::length_error when empty)
  virtual Node& Root() = 0;

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)
  // using typename MappableContainer<Data>::MapFunctor;
  typedef std::function<void(Data&, void*)> MapFunctor;

  // type MapPreOrder(arguments) specifiers;
  // Override MappableContainer member
  virtual void MapPreOrder(const MapFunctor, void*) override;

  // type MapPostOrder(arguments) specifiers;
  // Override MappableContainer member
  virtual void MapPostOrder(const MapFunctor, void*) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)
  // using typename FoldableContainer<Data>::FoldFunctor;
  typedef std::function<void(const Data&, const void*, void*) noexcept> FoldFunctor;

  // type FoldPreOrder(arguments) specifiers;
  // Override FoldableContainer member
  virtual void FoldPreOrder(const FoldFunctor, const void*, void*) const = 0;

  // type FoldPostOrder(arguments) specifiers;
  // Override FoldableContainer member
  virtual void FoldPostOrder(const FoldFunctor, const void*, void*) const = 0;

  /* ************************************************************************ */

  // Specific member functions (inherited from InOrderMappableContainer)
  // type MapInOrder(arguments) specifiers;
  // Override InOrderMappableContainer member


  /* ************************************************************************ */

  // Specific member functions (inherited from InOrderFoldableContainer)
  // type FoldInOrder(arguments) specifiers;
  // Override InOrderFoldableContainer member


  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthMappableContainer)
  // type MapBreadth(arguments) specifiers;
  // Override BreadthMappableContainer member


  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthFoldableContainer)
  // type FoldBreadth(arguments) specifiers;
  // Override BreadthFoldableContainer member


protected:

  // Auxiliary member functions (for MappableContainer)
  // type MapPreOrder(arguments) specifiers;
  // Accessory function executing from one node of the tree


  // type MapPostOrder(arguments) specifiers;
  // Accessory function executing from one node of the tree


  /* ************************************************************************ */

  // Auxiliary member functions (for FoldableContainer)
  // type FoldPreOrder(arguments) specifiers;
  // Accessory function executing from one node of the tree


  // type FoldPostOrder(arguments) specifiers;
  // Accessory function executing from one node of the tree


  /* ************************************************************************ */

  // Auxiliary member functions (for InOrderMappableContainer)
  // type MapInOrder(arguments) specifiers;
  // Accessory function executing from one node of the tree


  /* ************************************************************************ */

  // Auxiliary member functions (for InOrderFoldableContainer)
  // type FoldInOrder(arguments) specifiers;
  // Accessory function executing from one node of the tree


  /* ************************************************************************ */

  // Auxiliary member functions (for BreadthMappableContainer)
  // type MapBreadth(arguments) specifiers;
  // Accessory function executing from one node of the tree


  /* ************************************************************************ */

  // Auxiliary member functions (for BreadthFoldableContainer)
  // type FoldBreadth(arguments) specifiers;
  // Accessory function executing from one node of the tree


};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderIterator: virtual public ForwardIterator<Data> { // Must extend ForwardIterator<Data>

private:

  using typename BinaryTree<Data>::Node;
  Node node;
  StackLst<Node> stack;

protected:

  // ...

public:

  // Specific constructors
  // BTPreOrderIterator(argument) specifiers;
  // An iterator over a given binary tree
  BTPreOrderIterator(const BinaryTree<Data>&);

  /* ************************************************************************ */

  // Copy constructor
  // BTPreOrderIterator(argument) specifiers;
  BTPreOrderIterator(const BTPreOrderIterator<Data>&);

  // Move constructor
  // BTPreOrderIterator(argument) specifiers;
  BTPreOrderIterator(BTPreOrderIterator<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTPreOrderIterator() specifiers;
  ~BTPreOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTPreOrderIterator<Data>& operator=(const BTPreOrderIterator<Data>&);

  // Move assignment
  // type operator=(argument) specifiers;
  BTPreOrderIterator<Data>& operator=(BTPreOrderIterator<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const BTPreOrderIterator<Data>&) const noexcept;

  // type operator!=(argument) specifiers;
  bool operator!=(const BTPreOrderIterator<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)
  // type operator*() specifiers;
  // (throw std::out_of_range when terminated)
  Data& operator*() const;

  // type Terminated() specifiers;
  // (should not throw exceptions)
  bool Terminated() noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)
  // type operator++() specifiers;
  // (throw std::out_of_range when terminated)
  BTPreOrderIterator& operator++();

};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderIterator: virtual public ForwardIterator<Data> { // Must extend ForwardIterator<Data>

private:

  using typename BinaryTree<Data>::Node;
  Node node;
  StackLst<Node> stack;

protected:

  // ...

public:

  // Specific constructors
  // BTPostOrderIterator(argument) specifiers;
  // An iterator over a given binary tree
  BTPostOrderIterator(BinaryTree<Data>);

  /* ************************************************************************ */

  // Copy constructor
  // BTPostOrderIterator(argument) specifiers;
  BTPostOrderIterator(const BTPostOrderIterator&);

  // Move constructor
  // BTPostOrderIterator(argument) specifiers;
  BTPostOrderIterator(BTPostOrderIterator&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTPostOrderIterator() specifiers;
  ~BTPostOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTPostOrderIterator& operator=(const BTPostOrderIterator&);

  // Move assignment
  // type operator=(argument) specifiers;
  BTPostOrderIterator& operator=(BTPostOrderIterator&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const BTPostOrderIterator&) const noexcept;

  // type operator!=(argument) specifiers;
  bool operator!=(const BTPostOrderIterator&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)
  // type operator*() specifiers;
  // (throw std::out_of_range when terminated)
  Data& operator*();

  // type Terminated() specifiers;
  // (should not throw exceptions)
  bool Terminated() noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)
  // type operator++() specifiers;
  // (throw std::out_of_range when terminated)
  BTPostOrderIterator& operator++();

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderIterator: virtual public ForwardIterator<Data> { // Must extend ForwardIterator<Data>

private:

  typename BinaryTree<Data>::Node node;
  StackLst<typename BinaryTree<Data>::Node> stack;

protected:

  // ...

public:

  // Specific constructors
  // BTInOrderIterator(argument) specifiers;
  // An iterator over a given binary tree
  BTInOrderIterator(BinaryTree<Data>);

  /* ************************************************************************ */

  // Copy constructor
  // BTInOrderIterator(argument) specifiers;
  BTInOrderIterator(const BTInOrderIterator&);

  // Move constructor
  // BTInOrderIterator(argument) specifiers;
  BTInOrderIterator(BTInOrderIterator&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTInOrderIterator() specifiers;
  ~BTInOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTInOrderIterator& operator=(const BTInOrderIterator&);

  // Move assignment
  // type operator=(argument) specifiers;
  BTInOrderIterator& operator=(BTInOrderIterator&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(BTInOrderIterator&&) const noexcept;

  // type operator!=(argument) specifiers;
  bool operator!=(BTInOrderIterator&&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)
  // type operator*() specifiers;
  // (throw std::out_of_range when terminated)
  Data& operator*() const;

  // type Terminated() specifiers;
  // (should not throw exceptions)
  virtual bool Terminated() noexcept = 0;

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)
  // type operator++() specifiers;
  // (throw std::out_of_range when terminated)
  BTInOrderIterator& operator++();

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthIterator: virtual public ForwardIterator<Data> { // Must extend ForwardIterator<Data>

private:

  typename BinaryTree<Data>::Node node;
  QueueLst<typename BinaryTree<Data>::Node> queue;

protected:

  // ...

public:

  // Specific constructors
  // BTBreadthIterator(argument) specifiers;
  // An iterator over a given binary tree
  BTBreadthIterator(BinaryTree<Data>);

  /* ************************************************************************ */

  // Copy constructor
  // BTBreadthIterator(argument) specifiers;
  BTBreadthIterator (const BTBreadthIterator&);

  // Move constructor
  // BTBreadthIterator(argument) specifiers;
  BTBreadthIterator (BTBreadthIterator&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTBreadthIterator() specifiers;
  ~BTBreadthIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTBreadthIterator& operator=(const BTBreadthIterator&);

  // Move assignment
  // type operator=(argument) specifiers;
  BTBreadthIterator& operator=(BTBreadthIterator&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(BTBreadthIterator&&) const noexcept;

  // type operator!=(argument) specifiers;
  bool operator!=(BTBreadthIterator&&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)
  // type operator*() specifiers;
  // (throw std::out_of_range when terminated)
  Data& operator*() const;

  // type Terminated() specifiers;
  // (should not throw exceptions)
  virtual bool Terminated() noexcept = 0;


  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)
  // type operator++() specifiers;
  // (throw std::out_of_range when terminated)
  virtual BTBreadthIterator& operator++() = 0;

};

/* ************************************************************************** */

}

#include "binarytree.cpp"

#endif
