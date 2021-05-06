
namespace lasd {

/* ************************************************************************** */

// Costruttore NodoLnk
template<typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const Data& val)
{
  element = val;
}

// Distruttore NodoLnk
template<typename Data>
BinaryTreeLnk<Data>::NodeLnk::~NodeLnk()
{
  if(left != nullptr)
    delete left;
  if(right != nullptr)
    delete right;

}

//Mutable Element
template <typename Data>
Data& BinaryTreeLnk<Data>::NodeLnk::Element() noexcept
{
  return element;
}

//Immutable Element
template <typename Data>
const Data& BinaryTreeLnk<Data>::NodeLnk::Element() const noexcept
{
  return element;
}

//Metodo HasLeftChild(), ritorna true se il figlio sinistro esiste, altrimenti false.
template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept
{
  if(left==nullptr)
    return false;
  else
    return true;
}

//Metodo HasRightChild(), ritorna true se il figlio sinistro esiste, altrimenti false.
template<typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept
{
  if(right==nullptr)
    return false;
  else
    return true;
}

// Metodo IsLeaf(), restuisce vero, se un nodo non ha il figlio sinistro, ne un nodo destro, altrimenti false.
template<typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::IsLeaf() const noexcept
{
  if(!HasLeftChild() && !HasRightChild())
    return true;
  else
    return false;
}

// LeftChild
template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::LeftChild() const{
   if(HasLeftChild())
     return *left;
   else
     throw std::out_of_range("Questo nodo non ha figlio sinistro!");

}

// RightChild
template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::RightChild() const{
  if(HasRightChild())
    return *right;
  else
    throw std::out_of_range("Questo nodo non ha figlio destro!");

}

// Costruttore da un'altra struttura LinearContainer, list o vector.
template<typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const LinearContainer<Data>& container)
{
  size = container.Size();
  root = BuildTree(container,0,root);
}

// Copy constructor
template<typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk& tree)
{
  if(tree.size > 0)
  {
    root = BuildTree(&tree.Root());
    size = tree.size;
  }

}

// Move constructor
template<typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk&& tree) noexcept
{
  std::swap(root, tree.root);
  std::swap(size, tree.size);
}

// Destructor
template<typename Data>
BinaryTreeLnk<Data>::~BinaryTreeLnk()
{
  Clear();
}

// Copy assignment
template<typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk<Data>& tree)
{
  Clear();
  if(!tree.Empty())
  {
    root = BuildTree(&tree.Root());
    size = tree.size;
  }
  return *this;
}

// Move assignment
template<typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(BinaryTreeLnk<Data>&& tree) noexcept
{
  std::swap(root, tree.root);
  std::swap(size, tree.size);
  return *this;
}

// Operator ==
template<typename Data>
bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk<Data>& tree) const noexcept
{
  if(size == tree.size)
    return (Root() == tree.Root());
  else
    return false;

}

// Operator !=
template<typename Data>
bool BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk<Data>& tree) const noexcept
{
  return !(Root() == tree.Root());
}

// Root
template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::Root() const
{
  if(size > 0)
    return *root;
  else
    throw std::length_error("L'albero e' vuoto!");
}

// Clear
template<typename Data>
void BinaryTreeLnk<Data>::Clear()
{
  if(size != 0)
  {
    delete root;
    root = nullptr;
    size = 0;
  }
}

// Funzione Insert
template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::BuildTree(NodeLnk* radice)
{
    NodeLnk* tmp = new NodeLnk();
    tmp->element = radice->Element();
    if(radice->HasLeftChild())
      tmp -> left = BuildTree (radice -> left);

    if(radice->HasRightChild())
      tmp -> right = BuildTree (radice -> right);

    return tmp;
}

// Funzione Insert (LinearContainer)
template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::BuildTree(const LinearContainer<Data>& container, unsigned int index, NodeLnk* root)
{
  if(index < container.Size())
  {
    root = new NodeLnk(container[index]);
    root->left =  BuildTree (container,  (index * 2) + 1, root->left);
    root->right = BuildTree (container, (index * 2) + 2, root->right);
  }
  return root;
}

/* ************************************************************************** */

}
