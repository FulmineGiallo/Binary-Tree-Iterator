
//#include ".."

namespace lasd {

// ************************************************************************** NODE

//Opertator == (Node)
template<typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& node) const noexcept{
  bool val = true;

  if(Element() == node.Element())
  {
    if(HasLeftChild() && node.HasLeftChild())
    {
      val = (LeftChild() == node.LeftChild());
    }
    else if (HasLeftChild() || node.HasLeftChild())
    {
      val = false;
    }
    if(val)
    {
      if(HasRightChild() && node.HasRightChild())
      {
        val = RightChild() == node.RightChild();
      }
      else if(HasRightChild() || node.HasRightChild())
      {
        val = false;
      }
    }
  }
  else
    val = false;
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
bool BinaryTree<Data>::operator==(const BinaryTree<Data>& tree) const noexcept
{
  if(!(this->Empty()) && !(tree.Empty()))
    return Root() == tree.Root();

  if((this->Empty()) && tree.Empty())
    return true;
  else
    return false;
}

// Opertator !=
template<typename Data>
bool BinaryTree<Data>::operator!=(const BinaryTree<Data>& tree) const noexcept
{
  return !(Root() == tree.Root());
}

//****************************************************************************** MAP E FOLD (Interne)

// MapPreOrder
template<typename Data>
void BinaryTree<Data>::MapPreOrder(const MapFunctor fun, void* v, Node& node)
{
  fun(node.Element(), v);
  if (node.HasLeftChild())
    MapPreOrder(fun, v, node.LeftChild());

  if (node.HasRightChild())
    MapPreOrder(fun, v, node.RightChild());

}

// MapPostOrder
template<typename Data>
void BinaryTree<Data>::MapPostOrder(const MapFunctor fun, void* v, Node& node)
{
  if (node.HasLeftChild())
    MapPostOrder(fun, v, node.LeftChild());

  if (node.HasRightChild())
    MapPostOrder(fun, v, node.RightChild());

  fun(node.Element(), v);
}

// FoldPreOrder
template<typename Data>
void BinaryTree<Data>::FoldPreOrder(const FoldFunctor fun, const void* v, void* v2, const Node& node) const{
  fun(node.Element(), v, v2);
  if (node.HasLeftChild()){
    FoldPreOrder(fun, v, v2, node.LeftChild());
  }
  if (node.HasRightChild()){
    FoldPreOrder(fun, v, v2, node.RightChild());
  }
}

// FoldPostOrder
template<typename Data>
void BinaryTree<Data>::FoldPostOrder(const FoldFunctor fun, const void* v, void* v2, const Node& node) const{
  if (node.HasLeftChild()){
    FoldPostOrder(fun, v, v2, node.LeftChild());
  }
  if (node.HasRightChild()){
    FoldPostOrder(fun, v, v2, node.RightChild());
  }
  fun(node.Element(), v, v2);
}

// MapInOrder
template<typename Data>
void BinaryTree<Data>::MapInOrder(const MapFunctor fun, void* v, Node& node){
  if (node.HasLeftChild()){
    MapInOrder(fun, v, node.LeftChild());
  }
  fun(node.Element(), v);
  if (node.HasRightChild()){
    MapInOrder(fun, v, node.RightChild());
  }
}

// FoldInOrder
template<typename Data>
void BinaryTree<Data>::FoldInOrder(const FoldFunctor fun, const void* v, void* v2, const Node& node) const{
  if (node.HasLeftChild()){
    FoldInOrder(fun, v, v2, node.LeftChild());
  }
  fun(node.Element(), v, v2);
  if (node.HasRightChild()){
    FoldInOrder(fun, v, v2, node.RightChild());
  }
}

// MapBreadth
template<typename Data>
void BinaryTree<Data>::MapBreadth(const MapFunctor fun, void* v, Node& nodo){
  QueueLst<Node*> queue;
  queue.Enqueue(&nodo);
  while (!queue.Empty()){
    Node* currnode = queue.HeadNDequeue();
    fun(currnode->Element(), v);
    if(currnode->HasLeftChild()){
      queue.Enqueue(&(currnode->LeftChild()));
    }
    if(currnode->HasRightChild()){
      queue.Enqueue(&(currnode->RightChild()));
    }
  }
}

// FoldBreadth
template<typename Data>
void BinaryTree<Data>::FoldBreadth(const FoldFunctor fun, const void* v, void* v2, Node& nodo) const{
  QueueLst<Node*> queue;
  queue.Enqueue(&nodo);
  while (!queue.Empty()){
    Node* currnode = queue.HeadNDequeue();
    fun(currnode->Element(), v, v2);
    if(currnode->HasLeftChild()){
      queue.Enqueue(&(currnode->LeftChild()));
    }
    if(currnode->HasRightChild()){
      queue.Enqueue(&(currnode->RightChild()));
    }
  }
}

//****************************************************************************** MAP E FOLD

// MapPreOrder
template<typename Data>
void BinaryTree<Data>::MapPreOrder(const MapFunctor fun, void* v){
  if(!(this->Empty())){
    MapPreOrder(fun, v, Root());
  }
}

// MapPostOrder
template<typename Data>
void BinaryTree<Data>::MapPostOrder(const MapFunctor fun, void* v){
  if(!(this->Empty())){
    MapPostOrder(fun, v, Root());
  }
}

// FoldPreOrder
template<typename Data>
void BinaryTree<Data>::FoldPreOrder(const FoldFunctor fun, const void* v, void* v2) const{
  if(!(this->Empty())){
    FoldPreOrder(fun, v, v2, Root());
  }
}

// FoldPostOrder
template<typename Data>
void BinaryTree<Data>::FoldPostOrder(const FoldFunctor fun , const void* v, void* v2) const{
  if(!(this->Empty()))
  {
    FoldPostOrder(fun, v, v2, Root());
  }
}

// MapInOrder
template<typename Data>
void BinaryTree<Data>::MapInOrder(const MapFunctor fun, void* v){
  if(!(this->Empty()))
  {
    MapInOrder(fun, v, Root());
  }
}

// FoldInOrder
template<typename Data>
void BinaryTree<Data>::FoldInOrder(const FoldFunctor fun, const void* v, void* v2) const
{
  if(!(this->Empty())){
    FoldInOrder(fun, v, v2, Root());
  }
}

// MapBreadth
template<typename Data>
void BinaryTree<Data>::MapBreadth(const MapFunctor fun, void* v)
{
  if(!(this->Empty())){
    MapBreadth(fun, v, Root());
  }
}

// FoldBreadth
template<typename Data>
void BinaryTree<Data>::FoldBreadth(const FoldFunctor fun, const void* v, void* v2) const
{
  if(!(this->Empty()))
  {
    FoldBreadth(fun, v, v2, Root());
  }
}

/******************************************************************* PRE ORDER ***********************/

// Specific constructors
template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& pre)
{
  if(!pre.Empty()){
    node = &pre.Root();
  }
}

// Copy constructor
template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator<Data>& pre)
{
  stack = pre.stack;
  node = pre.node;
}

// Move constructor
template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator<Data>&& pre) noexcept
{
  std::swap(stack, pre.stack);
  std::swap(node, pre.node);
}

// Copy assignment
template<typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator<Data>& pre)
{
  stack = pre.stack;
  node = pre.node;
  return *this;
}

// Move assignment
template<typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(BTPreOrderIterator<Data>&& pre) noexcept
{
  std::swap(stack, pre.stack);
  std::swap(node, pre.node);
  return *this;
}

// Opertator ==
template<typename Data>
bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator<Data>& iterator) const noexcept
{
  if(stack == iterator.stack && node == iterator.node)
    return true;
  else
    return false;

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
  if (Terminated())
    throw std::out_of_range("Iteratore in PreOrder terminato!");
  else
     return node->Element();

}

// Terminated
template<typename Data>
bool BTPreOrderIterator<Data>::Terminated() const noexcept
{
  return node == nullptr && stack.Empty();
}

// Operator ++
template<typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator++(){
  if(!Terminated()){
    if (node->HasLeftChild()){
      if(node->HasRightChild()){
        stack.Push(&node->RightChild());
      }
      node = &node->LeftChild();
      }else{
        if(node->HasRightChild()){
          node = &node->RightChild();
        }else{
          if(stack.Empty()){
            node = nullptr;
          }else{
            node = stack.TopNPop();
          }
        }
      }
    }else{
      node = nullptr;
      throw std::out_of_range("Iteratore terminato!");
    }
  return *this;
}

//****************************************************************************** POST ORDER

// Specific constructors
template<typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& post)
{
  node = &post.Root();
  while(node->HasLeftChild() || node->HasRightChild())
  {
    stack.Push(node);

    if(node->HasLeftChild())
      node = &node->LeftChild();
    else
      node = &node->RightChild();

  }
}

// Copy constructor
template<typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator<Data>& post)
{
  node = post.node;
  stack = post.stack;
}

// Move constructor
template<typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator<Data>&& post) noexcept
{
  std::swap(node, post.node);
  std::swap(stack, post.stack);
}

// Copy assignment
template<typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator<Data>& post)
{
  node = post.node;
  stack = post.stack;
  return *this;
}

// Move assignment
template<typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(BTPostOrderIterator<Data>&& post) noexcept
{
  std::swap(node, post.node);
  std::swap(stack, post.stack);
  return *this;
}

// Opertator ==
template<typename Data>
bool BTPostOrderIterator<Data>::operator==(const BTPostOrderIterator<Data>& post) const noexcept
{
  if(stack == post.stack && node == post.node)
    return true;
  else
    return false;

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
  if (Terminated())
    throw std::out_of_range("Iteratore in PostOrder terminato!");
  else
     return node->Element();

}

// Terminated
template<typename Data>
bool BTPostOrderIterator<Data>::Terminated() const noexcept
{
  return node == nullptr && stack.Empty();
}

// Operator ++
template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator++(){
  if(!Terminated()){
    if (!stack.Empty()){
      if(stack.Top()->HasRightChild()){
        if (&stack.Top()->RightChild() != node){
          node = &stack.Top()->RightChild();
          while (node->HasLeftChild() || node->HasRightChild()){
            if (node->HasLeftChild()){
              stack.Push(node);
              node = &node->LeftChild();
            }else{
              stack.Push(node);
              node = &node->RightChild();
            }
          }
        }else{
          node = stack.TopNPop();
        }
      }
      else{
        node = stack.TopNPop();
      }
    }
    else{
      node = nullptr;
    }
  }else{
    throw std::out_of_range("Iteratore terminato!");
  }
  return *this;
}

/**************** IN ORDER *************************/

// Specific constructor
template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(BinaryTree<Data>& iterator)
{
  node = &iterator.Root();
  while(node->HasLeftChild())
  {
    stack.Push(node);
    node = &node->LeftChild();
  }
}

// Copy constructor
template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator<Data>& iterator)
{
  node = iterator.node;
  stack = iterator.stack;
}

// Move constructor
template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator<Data>&& iterator) noexcept
{
  std::swap(node, iterator.node);
  std::swap(stack, iterator.stack);
}

// Copy assignment
template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(const BTInOrderIterator<Data>& iterator)
{
  node = iterator.node;
  stack = iterator.stack;
  return *this;
}

// Move assignment
template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(BTInOrderIterator<Data>&& iterator) noexcept
{
  std::swap(node, iterator.node);
  std::swap(stack, iterator.stack);
  return *this;
}

// Operator ==
template <typename Data>
bool BTInOrderIterator<Data>::operator==(const BTInOrderIterator<Data>& iterator) const noexcept
{
  return node == iterator.node && stack == iterator.stack;
}

// Operator !=
template <typename Data>
bool BTInOrderIterator<Data>::operator!=(const BTInOrderIterator<Data>& iterator) const noexcept
{
  return !(*this == iterator);
}

// Operator *
template <typename Data>
Data& BTInOrderIterator<Data>::operator*() const
{
  if (Terminated())
    throw std::out_of_range("Iteratore in Order terminato!");
  else
    return node->Element();

}

// Terminated
template<typename Data>
bool BTInOrderIterator<Data>::Terminated() const noexcept
{
  return node == nullptr && stack.Empty();
}

// Operator ++
template<typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator++(){
  if(!Terminated()){
    if(node->IsLeaf()){
      if(stack.Empty()){
        node = nullptr;
      }else{
        node = stack.TopNPop();
      }
    }else{
      if(node->HasRightChild()){
        node = &node->RightChild();
        while(node->HasLeftChild()){
          stack.Push(node);
          node = &node->LeftChild();
        }
      }else{
        if(stack.Empty()){
          node = nullptr;
        }else{
          node = stack.TopNPop();
        }
      }
    }
  }else{
    throw std::out_of_range("Iteratore terminato!");
  }
  return *this;
}

/********************** BREADTH ***********************/

// Specific constructor
template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BinaryTree<Data>& tree)
{
  node = &tree.Root();
}

// Copy constructor
template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator<Data>& breadth)
{
  node = breadth.node;
  queue = breadth.queue;
}

// Move constructor
template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator<Data>&& breadth) noexcept
{
  std::swap(node, breadth.node);
  std::swap(queue, breadth.queue);
}

// Copy assignment
template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(const BTBreadthIterator<Data>& breadth)
{
  node = breadth.node;
  queue = breadth.queue;
  return *this;
}

// Move assignment
template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(BTBreadthIterator<Data>&& breadth) noexcept
{
  node =  std::move(breadth.node);
  queue = std::move(breadth.queue);
  return *this;
}

// Operator ==
template <typename Data>
bool BTBreadthIterator<Data>::operator==(const BTBreadthIterator<Data>& breadth) const noexcept
{
  return node == breadth.node && breadth == breadth.queue;
}


// Operator !=
template <typename Data>
bool BTBreadthIterator<Data>::operator!=(const BTBreadthIterator<Data>& breadth) const noexcept
{
  return !(*this == breadth);
}

// Operator *
template <typename Data>
Data& BTBreadthIterator<Data>::operator*() const{
  if (Terminated())
    throw std::out_of_range("Iteratore in Ampiezza terminato!");
  else
    return node->Element();

}

// Terminated
template <typename Data>
bool BTBreadthIterator<Data>::Terminated() const noexcept
{
  return node == nullptr && queue.Empty();
}

// Operator ++
template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator++()
{
  if(!Terminated())
  {
    if(node->HasLeftChild())
      queue.Enqueue(&node->LeftChild());

    if(node->HasRightChild())
      queue.Enqueue(&node->RightChild());

    if(queue.Empty())
      node = nullptr;
    else
      node = queue.HeadNDequeue();

  }
  else
    throw std::out_of_range("Iteratore terminato!");

  return *this;
}
/* ************************************************************************** */

}
