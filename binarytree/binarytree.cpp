
#include "../stack/stack.hpp"

namespace lasd
{

// ************************************************************************** NODE

// Opertator == (Node)
template<typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& newNode) const noexcept{
  bool val = true;

  if(Element() == newNode.Element()){
    if(HasLeftChild() && newNode.HasLeftChild()){
      val = (LeftChild() == newNode.LeftChild());
    }else if (HasLeftChild() || newNode.HasLeftChild()){
      val = false;
    }
    if(val){
      if(HasRightChild() && newNode.HasLeftChild()){
        val = RightChild() == newNode.RightChild();
      }else if(HasRightChild() || newNode.HasRightChild()){
      val = false;
      }
    }
  }
  return val;
}

// Opertator != (Node)
template<typename Data>
bool BinaryTree<Data>::Node::operator!=(const Node& newNode) const noexcept
{
  return !(*this == newNode);
}

// Opertator ==
template<typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree& albero) const noexcept
{
  if(!(this->Empty()) && !(albero.Empty()))
    return Root() == albero.Root();

  if((this->Empty()) && albero.Empty()) //sono vuoti
    return true;
  else
    return false;
}

// Opertator !=
template<typename Data>
bool BinaryTree<Data>::operator!=(const BinaryTree& albero) const noexcept
{
  return !(*this == albero);
}

template <typename Data>
bool BinaryTree<Data>::Node::IsLeaf() const noexcept
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
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& albero)
{
  if(!albero.Empty())
  {
    curr = &albero.Root();
  }
}

// Copy constructor
template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator<Data>& pre)
{
  stack = pre.stack;
  curr = pre.curr;
}

// Move constructor
template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator<Data>&& pre) noexcept{
  std::swap(curr, pre.curr);
  std::swap(stack,pre.stack);
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
  std::swap(curr, pre.curr);
  std::swap(stack,pre.stack);
  return *this;
}

// Opertator ==
template<typename Data>
bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator<Data>& pre) const noexcept
{
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
  if(Terminated())
  {
    throw std::out_of_range("Iteratore terminato!");
  }
  else
  {
    return curr->Element();
  }
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
  if(!Terminated()){
    if (curr->HasLeftChild()){
      if(curr->HasRightChild()){
        stack.Push(&curr->RightChild());
      }
      curr = &curr->LeftChild();
      }else{
        if(curr->HasRightChild()){
          curr = &curr->RightChild();
        }else{
          if(stack.Empty()){
            curr = nullptr;
          }else{
            curr = stack.TopNPop();
          }
        }
      }
    }else{
      curr = nullptr;
      throw std::out_of_range("Iteratore terminato!");
    }
  return *this;
  /*Parto dalla Root, stack vuoto.
  Se faccio ++, devo passare al figlio sinistro
  Se esiste sinistro, ed esiste destro, metto destro nello stack
  Se figlio sinistro è foglia, POP Stack
  Se la pila è vuota, se il nodo è foglia, --> curr nullptr*/
}


template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>& albero)
{
  //Nodo più a sinistra
  curr = &albero.Root();
  while(curr->HasLeftChild())
  {
    stack.Push(curr);
    curr = &curr->LeftChild();
  }
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
  std::swap(curr, iterator.curr);
  std::swap(stack,iterator.stack);
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
  std::swap(curr, iterator.curr);
  std::swap(stack,iterator.stack);
  return *this;
}

template <typename Data>
bool BTInOrderIterator<Data>::operator==(const BTInOrderIterator<Data>& iterator) const noexcept
{
  return (curr == iterator.curr) && (stack == iterator.stack);

}
template <typename Data>
bool BTInOrderIterator<Data>::operator!=(const BTInOrderIterator<Data>& iterator) const noexcept
{
  return !(*this == iterator);
}

// Operator *
template<typename Data>
Data& BTInOrderIterator<Data>::operator*() const
{
  if(Terminated())
  {
    throw std::out_of_range("Iteratore in PostOrder terminato!");
  }
  else
  {
   return curr->Element();
  }

}
template<typename Data>
bool BTInOrderIterator<Data>::Terminated() const noexcept
{
  return curr == nullptr && stack.Empty();
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator++()
{
  if(Terminated())
    throw std::out_of_range("L'iteratore In Pre Order e' terminato, impossibile andare avanti");
  else
  {
    if(curr->IsLeaf())
    {
      if(stack.Empty())
        curr = nullptr;
      else
        curr = stack.TopNPop();
      }
      else
      {
        if(curr->HasRightChild())
        {
          curr = &curr->RightChild();
          while(curr->HasLeftChild())
          {
            stack.Push(curr);
            curr = &curr->LeftChild();
          }
        }
        else
        {
          if(stack.Empty())
            curr = nullptr;
          else
            curr = stack.TopNPop();
        }
      }
  }
  return *this;

  //Visita solo quando scende
  //Metta in stack, tutti quelli che deve visitare dopo.
  //Il costruttore parte dal figlio più in sinistra.
  //Se il figlio è una foglia, poppa lo stack.
  //Visita il dx, se dx è foglia, poppa lo stack.
  //Ogni volta che un nodo non è Leaf, prende sempre il figlio più a sinistra, e Pusha il destro.
}


template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& albero)
{
  curr = &albero.Root();
}


//Copy
template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator<Data>& iterator)
{
  curr = iterator.curr;
  coda = iterator.coda;
}
//Move
template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator<Data>&& iterator) noexcept
{
  std::swap(curr, iterator.curr);
  std::swap(coda, iterator.coda);
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
  std::swap(curr, iterator.curr);
  std::swap(coda, iterator.coda);
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
  if(Terminated())
    throw std::out_of_range("Iteratore in BTBreadthIterator è terminato");
  else
    return curr->Element();
}



template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator++()
{
  if(!Terminated())
  {
    if(curr->HasLeftChild())
      coda.Enqueue(&curr->LeftChild());
    if(curr->HasRightChild())
      coda.Enqueue(&curr->RightChild());
    if(coda.Empty())
    {
      curr = nullptr;
    }
    else
    {
      curr = coda.HeadNDequeue();
    }
  }
  else
  {
    throw std::out_of_range("Iteratore in Ampiezza, terminato!");
  }

  return *this;
}


template <typename Data>
void BinaryTree<Data>::MapPreOrder(const MapFunctor fun, void* support)
{
  if(!this->Empty())
    MapPreOrder(fun,support, Root());
}
template <typename Data>
void BinaryTree<Data>::MapPreOrder(const MapFunctor fun, void* support, Node& nodo)
{
  fun(nodo.Element(), support); //Radice
  if(nodo.HasLeftChild())
    MapPreOrder(fun, support, nodo.LeftChild());
  if(nodo.HasRightChild())
    MapPreOrder(fun, support, nodo.RightChild());
}

template <typename Data>
void BinaryTree<Data>::FoldPreOrder(const FoldFunctor fun, const void* acc, void* support, Node& nodo) const
{
  fun(nodo.Element(),acc,support); //Radice
  if(nodo.HasLeftChild())
    FoldPreOrder(fun, acc, support, nodo.LeftChild());
  if(nodo.HasRightChild())
    FoldPreOrder(fun, acc, support, nodo.RightChild());
}
template <typename Data>
void BinaryTree<Data>::FoldPreOrder(const FoldFunctor fun, const void* acc, void* support) const
{
  if(!this->Empty())
    FoldPreOrder(fun,acc,support, Root());

}

template <typename Data>
void BinaryTree<Data>::MapPostOrder(const MapFunctor fun, void* support, Node& nodo)
{
  //Stack di attivazione
  if(nodo.HasLeftChild())
    MapPostOrder(fun, support, nodo.LeftChild());
  if(nodo.HasRightChild())
    MapPostOrder(fun, support, nodo.RightChild());

  fun(nodo.Element(), support); //Radice, ultimo controllo.
}
template <typename Data>
void BinaryTree<Data>::MapPostOrder(const MapFunctor fun, void* support)
{
  if(!(this->Empty()))
    MapPostOrder(fun, support, Root());
}
template <typename Data>
void BinaryTree<Data>::FoldPostOrder(const FoldFunctor fun, const void* acc, void* support, Node& nodo) const
{
  if(nodo.HasLeftChild())
    FoldPostOrder(fun, acc, support, nodo.LeftChild());
  if(nodo.HasRightChild())
    FoldPostOrder(fun, acc, support, nodo.RightChild());

  fun(nodo.Element(), acc, support); //Radice, ultimo controllo.
}
template <typename Data>
void BinaryTree<Data>::FoldPostOrder(const FoldFunctor fun, const void* acc, void* support) const
{
  if(!(this->Empty()))
    FoldPostOrder(fun, acc, support, Root());
}
template <typename Data>
void BinaryTree<Data>::MapInOrder(const MapFunctor fun, void* support, Node& nodo)
{
  //Sotto albero sinitro, radice e poi sottoalbero destro.
  if(nodo.HasLeftChild())
    MapInOrder(fun, support, nodo.LeftChild());

  fun(nodo.Element(), support);

  if(nodo.HasRightChild())
    MapInOrder(fun, support, nodo.RightChild());
}
template <typename Data>
void BinaryTree<Data>::MapInOrder(const MapFunctor fun, void* support)
{
  if(!(this->Empty()))
    MapInOrder(fun, support, Root());
}

template <typename Data>
void BinaryTree<Data>::FoldInOrder(const FoldFunctor fun, const void* acc, void* support, Node& nodo) const
{
  if(nodo.HasLeftChild())
    FoldInOrder(fun, acc, support, nodo.LeftChild());

  fun(nodo.Element(),acc,support); //Radice

  if(nodo.HasRightChild())
    FoldInOrder(fun, acc, support, nodo.RightChild());
}

template <typename Data>
void BinaryTree<Data>::FoldInOrder(const FoldFunctor fun, const void* acc, void* support) const
{
  if(!(this->Empty()))
      FoldInOrder(fun, acc, support, Root());
}

// MapBreadth
template<typename Data>
void BinaryTree<Data>::MapBreadth(const MapFunctor fun, void* v, Node& node)
{
  QueueLst<Node * > queue;
  queue.Enqueue(&node);
  while (!queue.Empty()){
    Node * currnode = queue.HeadNDequeue();
    fun(currnode->Element(), v);
    if(currnode->HasLeftChild()){
      queue.Enqueue(&(currnode->LeftChild()));
    }
    if(currnode->HasRightChild()){
      queue.Enqueue(&(currnode->RightChild()));
    }
  }
}
template <typename Data>
void BinaryTree<Data>::MapBreadth(const MapFunctor fun, void* support)
{
  if(!(this->Empty()))
    MapBreadth(fun, support, Root());
}
template <typename Data>
void BinaryTree<Data>::FoldBreadth(const FoldFunctor fun, const void* acc, void* support, Node& nodo) const
{
  QueueLst<Node*> queue;
  queue.Enqueue(&nodo);
  while (!queue.Empty()){
    Node * currnode = queue.HeadNDequeue();
    fun(currnode->Element(),acc, support);
    if(currnode->HasLeftChild()){
      queue.Enqueue(&(currnode->LeftChild()));
    }
    if(currnode->HasRightChild()){
      queue.Enqueue(&(currnode->RightChild()));
    }
  }

}
template <typename Data>
void BinaryTree<Data>::FoldBreadth(const FoldFunctor fun, const void* acc, void* support) const
{
  if(!(this->Empty()))
    FoldBreadth(fun, acc, support, Root());

}
/* **************************************************************************/
}
