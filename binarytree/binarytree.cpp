
#include "../stack/stack.hpp"

namespace lasd
{

// ************************************************************************** NODE

// Opertator == (Node)
template<typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& newNode) const noexcept
{
  bool val = true;
  // if(Element() != newNode.Element())
  //   val = false;
  // if(Element() == newNode.Element())
  // {
  //   if(HasLeftChild() && newNode.HasLeftChild())
  //   {
  //     val = (LeftChild() == newNode.LeftChild());
  //   }
  //   else if (HasLeftChild() || newNode.HasLeftChild())
  //   {
  //     return false;
  //   }
  //   if(val)
  //   {
  //     if(HasRightChild() && newNode.HasLeftChild())
  //     {
  //       val = RightChild() == newNode.RightChild;
  //     }
  //     else if(HasRightChild() || newNode.HasRightChild())
  //     {
  //       return false;
  //     }
  //   }
  // }
    return val;
}

// Opertator != (Node)
template<typename Data>
bool BinaryTree<Data>::Node::operator!=(const Node& newNode) const noexcept
{
  // return !(*this == newNode);
  return false;
}

// Opertator ==
template<typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree& albero) const noexcept{
  // return Root() == albero.Root();
  return false;
}

// Opertator !=
template<typename Data>
bool BinaryTree<Data>::operator!=(const BinaryTree& albero) const noexcept{
  // return Root() != albero.Root();
  return false;
}

template <typename Data>
bool BinaryTree<Data>::Node::IsLeaf() noexcept
{
  return !(HasLeftChild() || HasRightChild());
}

template <typename Data>
bool BTBreadthIterator<Data>::Terminated() const noexcept
{
  return (curr == nullptr && coda.Empty());
}
//****************************************************************************** PRE ORDER

// Specific constructors
template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& pre)
{
  // if(!pre.Empty())
  // {
  //   curr = pre.Root();
  // }

}

// Copy constructor
template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator<Data>& pre){
  stack = pre.stack;
  curr = pre.curr;
}

// Move constructor
template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator<Data>&& pre) noexcept{
  stack = std::move(pre.stack);
  curr = std::move(pre.curr);
}

// Copy assignment
template<typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator<Data>& pre){
  stack = pre.stack;
  curr = pre.curr;
  return *this;
}

// Move assignment
template<typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(BTPreOrderIterator<Data>&& pre) noexcept{
  stack = std::move(pre.stack);
  curr = std::move(pre.curr);
  return *this;
}

// Opertator ==
template<typename Data>
bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator<Data>& pre) const noexcept{
  if(stack == pre.stack && curr == pre.curr)
  {
    return true;
  }
  else
  {
    return false;
  }
}

// Operator !=
template<typename Data>
bool BTPreOrderIterator<Data>::operator!=(const BTPreOrderIterator<Data>& pre) const noexcept
{
  return !(*this == pre);
}

// Operator *
template<typename Data>
Data& BTPreOrderIterator<Data>::operator*() const
{
  // if (Terminated())
  // {
  //   throw std::out_of_range("Iteratore terminato!");
  // }
  // else
  // {
  // return curr->Element();
  // }
  return curr->Element();

}

// Terminated
template<typename Data>
bool BTPreOrderIterator<Data>::Terminated() const noexcept
{
  return curr == nullptr && stack.Empty();
}

// Operator ++
template<typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator++()
{
  // if(Terminated())
  //   throw std::out_of_range("Iteratore in PreOrder, non è possibile andare avanti");
  // else
  // {
  //   if (curr->HasLeftChild())
  //   {
  //     stack.Push(curr.RightChild());
  //     curr = curr->LeftChild();
  //   }
  //   else
  //   {
  //     if(curr->HasRightChild())
  //     {
  //       curr = curr->RightChild();
  //     }
  //     else
  //     {
  //       if(stack.Empty())
  //       {
  //         curr = nullptr;
  //       }
  //       else
  //       {
  //         stack.TopNPop();
  //       }
  //     }
  //   }
  // }
  return *this;
}

//****************************************************************************** POST ORDER

// Specific constructors
template<typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& post)
{
  // typename BinaryTree<Data>::Node tmp = post.Root();
  // while(tmp.HasLeftChild() || tmp.HasRightChild())
  // {
  //   stack.Push(tmp);
  //   if(tmp.HasLeftChild())
  //   {
  //     tmp = tmp->LeftChild();
  //   }
  //   else
  //   {
  //     tmp = tmp->RightChild();
  //   }
  //   curr = tmp;
  // }
}

// Copy constructor
template<typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator& post)
{
  curr = post.curr;
  stack = post.stack;
}

// Move constructor
template<typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator&& post) noexcept{
  curr = std::move(post.curr);
  stack = std::move(post.stack);
}

// Copy assignment
template<typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator<Data>& post)
{
  curr = post.curr;
  stack = post.stack;
  return *this;
}

// Move assignment
template<typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(BTPostOrderIterator<Data>&& post) noexcept
{
  curr = std::move(post.curr);
  stack = std::move(post.stack);
  return *this;
}

// Operator ==
template<typename Data>
bool BTPostOrderIterator<Data>::operator==(const BTPostOrderIterator<Data>& post) const noexcept
{
  if(curr == post.curr && stack == post.stack)
  {
    return true;
  }
  else
  {
    return false;
  }
}

// Operator !=
template<typename Data>
bool BTPostOrderIterator<Data>::operator!=(const BTPostOrderIterator<Data>& post) const noexcept
{
  return !(*this == post);
}

// Operator *
template<typename Data>
Data& BTPostOrderIterator<Data>::operator*() const
{
  // if(Terminated())
  // {
  //   throw std::out_of_range("Iteratore in PostOrder terminato!");
  // }
  // else
  // {
  //   return curr.Element();
  // }
  return curr->Element();
}

// Terminated
template<typename Data>
bool BTPostOrderIterator<Data>::Terminated() const noexcept
{
  return false;
}

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator++()
{
  // if(Terminated())
  //   throw std::out_of_range("Iteratore in PostOrder, non è possibile andare avanti");
  // else
  // {
  //   if (!stack.Empty())
  //   {
  //     if (stack.Top().RightChild() != curr)
  //     {
  //       curr = stack.Top().RightChild();
  //       while (curr->HasLeftChild() || curr->HasRightChild())
  //       {
  //         if (curr->HasLeftChild())
  //         {
  //           stack.push(curr);
  //           curr = curr->LeftChild();
  //         }
  //         else
  //         {
  //           stack.push(curr);
  //           curr = curr->RightChild();
  //         }
  //       }
  //     }
  //     else
  //     {
  //       curr = stack.TopNPop();
  //     }
  //   }
  //   else
  //   {
  //     curr = nullptr;
  //   }
  // }
  return *this;
}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>& albero)
{
  // typename BinaryTree<Data>::Node *tmp = albero.Root();
  //
  // while(tmp->HasLeftChild())
  // {
  //   stack.Push(tmp);
  //   tmp = tmp->LeftChild();
  // }
  // curr = tmp;
}

//Copy assignment
template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator<Data>& iterator)
{
  curr = iterator.curr;
  stack = iterator.stack;
}
//Move assignment
template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator<Data>&& iterator) noexcept
{
  curr =  std::move(iterator.curr);
  stack = std::move(iterator.stack);
}


template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(const BTInOrderIterator<Data>& iterator)
{
  curr = iterator.curr;
  stack = iterator.stack;
  return *this;
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(BTInOrderIterator<Data>&& iterator) noexcept
{
  curr =  std::move(iterator.curr);
  stack = std::move(iterator.stack);
  return *this;
}

template <typename Data>
bool BTInOrderIterator<Data>::operator==(BTInOrderIterator<Data>&& iterator) const noexcept
{
  bool x;
  x = (curr == iterator.curr) && (stack == iterator.stack);
  return x;
}
template <typename Data>
bool BTInOrderIterator<Data>::operator!=(BTInOrderIterator<Data>&& iterator) const noexcept
{
  return !(*this == iterator);
}

// Operator *
template<typename Data>
Data& BTInOrderIterator<Data>::operator*() const
{
  // if(Terminated())
  // {
  //   throw std::out_of_range("Iteratore in PostOrder terminato!");
  // }
  // else
  // {
  //
  // }
   return curr->Element();
}
template<typename Data>
bool BTInOrderIterator<Data>::Terminated() const noexcept
{
  return curr == nullptr && stack.Empty();
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator++()
{
  // if(Terminated())
  //   throw std::out_of_range("L'iteratore e' terminato, impossibile andare avanti");
  // else
  // {
  //   if(curr->IsLeaf()){
  //     if(stack.Empty()) curr = nullptr;
  //     else curr = stack.TopNPop();
  // }
  // else
  // {
  //     if(curr->HasRightChild()){
  //       curr = curr->RightChild();
  //       while(curr->HasLeftChild()){
  //         stack.Push(curr);
  //         curr = curr->LeftChild();
  //       }
  //     }
  //   }
  // }
  return *this;
}


template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& albero)
{
  // curr = albero.Root();
}


//Copy
template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator<Data>& iterator)
{
  // curr = iterator.curr;
  // coda = iterator.coda;
}
//Move
template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator<Data>&& iterator) noexcept
{
  // curr = std::move(iterator.curr);
  // coda = std::move(iterator.coda);
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(const BTBreadthIterator<Data>& iterator)
{
  curr = iterator.curr;
  coda = iterator.coda;
  return *this;
}
template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(BTBreadthIterator<Data>&& iterator) noexcept
{
  curr = std::move(iterator.curr);
  coda = std::move(iterator.coda);
  return *this;
}

template <typename Data>
bool BTBreadthIterator<Data>::operator==(const BTBreadthIterator<Data>& iterator) const noexcept
{
  return (curr == iterator.curr) && (coda == iterator.coda);
}
template <typename Data>
bool BTBreadthIterator<Data>::operator!=(const BTBreadthIterator<Data>& iterator) const noexcept
{
  return !(*this ==iterator);
}

template <typename Data>
Data& BTBreadthIterator<Data>::operator*() const
{
  // if(Terminated())
  //   throw std::out_of_range("Iteratore in BTBreadthIterator è terminato");
  // else
    return curr->Element();
}



template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator++()
{
  // if(curr->HasLeftChild())
  //   coda.Enqueue(&curr->LeftChild());
  // if(curr->HasRightChild())
  //   coda.Enqueue(&curr->RightChild());
  // if(coda.Empty()) //abbiamo finito
  // {
  //   curr == nullptr;
  // }
  // else
  //   curr = coda.Dequeue();

  return *this;
}


template <typename Data>
void BinaryTree<Data>::MapPreOrder(const MapFunctor fun, void* support, Node& nodo)
{
  fun(nodo, support); //Radice
  if(nodo.HasLeftChild())
    MapPreOrder(fun, support, nodo.LeftChild());
  if(nodo.HasRightChild())
    MapPreOrder(fun, support, nodo.RightChild());
}
template <typename Data>
void BinaryTree<Data>::MapPreOrder(const MapFunctor fun, void* support)
{

}
template <typename Data>
void BinaryTree<Data>::FoldPreOrder(const FoldFunctor fun, const void* acc, void* support, Node& nodo) const
{
  fun(nodo,acc,support); //Radice
  if(nodo.HasLeftChild())
    FoldPreOrder(fun, acc, support, nodo.LeftChild());
  if(nodo.HasRightChild())
    FoldPreOrder(fun, acc, support, nodo.RightChild());
}
template <typename Data>
void BinaryTree<Data>::FoldPreOrder(const FoldFunctor fun, const void* acc, void* support) const
{


}

template <typename Data>
void BinaryTree<Data>::MapPostOrder(const MapFunctor fun, void* support, Node& nodo)
{
  //Stack di attivazione
  if(nodo.HasLeftChild())
    MapPostOrder(fun, support, nodo.LeftChild());
  if(nodo.HasRightChild())
    MapPostOrder(fun, support, nodo.RightChild());

  fun(nodo, support); //Radice, ultimo controllo.
}
template <typename Data>
void BinaryTree<Data>::MapPostOrder(const MapFunctor fun, void* support)
{

}
template <typename Data>
void BinaryTree<Data>::FoldPostOrder(const FoldFunctor fun, const void* acc, void* support, Node& nodo) const
{

  if(nodo.HasLeftChild())
    FoldPostOrder(fun, acc, support, nodo.LeftChild());
  if(nodo.HasRightChild())
    FoldPostOrder(fun, acc, support, nodo.RightChild());

  fun(nodo, acc, support); //Radice, ultimo controllo.
}
template <typename Data>
void BinaryTree<Data>::FoldPostOrder(const FoldFunctor fun, const void* acc, void* support) const
{

}
template <typename Data>
void BinaryTree<Data>::MapInOrder(const MapFunctor fun, void* support, Node& nodo)
{
  //Sotto albero sinitro, radice e poi sottoalbero destro.
  if(nodo.HasLeftChild())
    MapPostOrder(fun, support, nodo.LeftChild());

  fun(nodo, support);

  if(nodo.HasRightChild())
    FoldPostOrder(fun, support, nodo.RightChild());
}
template <typename Data>
void BinaryTree<Data>::MapInOrder(const MapFunctor fun, void* support)
{

}

template <typename Data>
void BinaryTree<Data>::FoldInOrder(const FoldFunctor fun, const void* acc, void* support, Node& nodo) const
{
  if(nodo.HasLeftChild())
    FoldInOrder(fun, acc, support, nodo.LeftChild());

  fun(nodo,acc,support); //Radice

  if(nodo.HasRightChild())
    FoldInOrder(fun, acc, support, nodo.RightChild());
}

template <typename Data>
void BinaryTree<Data>::FoldInOrder(const FoldFunctor fun, const void* acc, void* support) const
{

}

template <typename Data>
void BinaryTree<Data>::MapBreadth(const MapFunctor fun, void* support, Node& nodo)
{
  QueueLst<Node> coda;
  typename BinaryTree<Data>::Node tmp = nodo;
  fun(tmp, support);
  if(tmp.HasLeftChild())
    coda.Enqueue(tmp.LeftChild());
  if(tmp.HasRightChild())
    coda.Enqueue(tmp.RightChild());
  while(coda.Empty())
  {
    tmp = coda.HeadNDequeue();
    fun(tmp, support);
    if(tmp.HasLeftChild())
      coda.Enqueue(tmp.LeftChild());
    if(tmp.HasRightChild())
      coda.Enqueue(tmp.RightChild());
  }
}
template <typename Data>
void BinaryTree<Data>::MapBreadth(const MapFunctor fun, void* support)
{

}
template <typename Data>
void BinaryTree<Data>::FoldBreadth(const FoldFunctor fun, const void* acc, void* support, Node& nodo) const
{
  //Radice sinistra, radice destra
  QueueLst<Node> coda;
  typename BinaryTree<Data>::Node tmp = nodo;
  fun(tmp, acc,support);
  if(tmp.HasLeftChild())
    coda.Enqueue(tmp.LeftChild());
  if(tmp.HasRightChild())
    coda.Enqueue(tmp.RightChild());
  while(coda.Empty())
  {
    tmp = coda.HeadNDequeue();
    fun(tmp, acc,support);
    if(tmp.HasLeftChild())
      coda.Enqueue(tmp.LeftChild());
    if(tmp.HasRightChild())
      coda.Enqueue(tmp.RightChild());
  }

}
template <typename Data>
void BinaryTree<Data>::FoldBreadth(const FoldFunctor fun, const void* acc, void* supporto) const
{


}
/* ************************************************************************** */

}
