
namespace lasd {

/* ************************************************************************** */

// Costruttore NodoLnk
template<typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const Data& val){
  element = val;
}

// Distruttore NodoLnk
template<typename Data>
BinaryTreeLnk<Data>::NodeLnk::~NodeLnk(){
  if(left != nullptr){
    delete left;
  }
  if(right != nullptr){
    delete right;
  }
}

// Element
template <typename Data>
Data& BinaryTreeLnk<Data>::NodeLnk::Element() noexcept{
  return element;
}

// Element (const)
template <typename Data>
const Data& BinaryTreeLnk<Data>::NodeLnk::Element() const noexcept{
  return element;
}

// HasLeftChild
template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept{
  if(left!=nullptr){
    return true;
  }else{
    return false;
  }
}

// HasRightChild
template<typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept{
  if(right!=nullptr){
    return true;
  }else{
    return false;
  }
}

// IsLeaf
template<typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::IsLeaf() const noexcept{
  if(right==nullptr && left==nullptr){
    return true;
  }else{
    return false;
  }
}

// LeftChild
template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::LeftChild() const{
   if(HasLeftChild()){
     return *left;
   }else{
     throw std::out_of_range("il nodo corrente non ha figlio sinistro!");
   }
}

// RightChild
template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::RightChild() const{
  if(HasRightChild()){
    return *right;
  }else{
    throw std::out_of_range("il nodo corrente non ha figlio destro!");
  }
}

// Costruttore da un'altra struttura LinearContainer<Data> (vector, list, etc...)
template<typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const LinearContainer<Data>& lcon){
  size = lcon.Size();
  root = Insert(lcon,0,root);
}

// Copy constructor
template<typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk& tree){
  if(tree.size > 0){
    root = Insert(&tree.Root());
    size = tree.size;
  }
}

// Move constructor
template<typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk&& tree) noexcept{
  std::swap(root, tree.root);
  std::swap(size, tree.size);
}

// Destructor
template<typename Data>
BinaryTreeLnk<Data>::~BinaryTreeLnk(){
  Clear();
}

// Copy assignment
template<typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk<Data>& tree){
  Clear();
  if(!tree.Empty()){
    root = Insert(&tree.Root());
    size = tree.size;
  }
  return *this;
}

// Move assignment
template<typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(BinaryTreeLnk<Data>&& tree) noexcept{
  std::swap(root, tree.root);
  std::swap(size, tree.size);
  return *this;
}

// Operator ==
template<typename Data>
bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk<Data>& tree) const noexcept{
  if(size == tree.size){
    return (Root() == tree.Root());
  }
  else{
    return false;
  }
}

// Operator !=
template<typename Data>
bool BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk<Data>& tree) const noexcept{
  return !(Root() == tree.Root());
}

// Root
template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::Root() const{
  if(size > 0){
    return *root;
  }else{
    throw std::length_error("L'albero e' vuoto!");
  }
}

// Clear
template<typename Data>
void BinaryTreeLnk<Data>::Clear(){
  if(size != 0){
    delete root;
    root = nullptr;
    size=0;
  }
}

// Funzione Insert
template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::Insert(NodeLnk* radice){
    NodeLnk* tmp = new NodeLnk();
    tmp->element = radice->Element();
    if(radice->HasLeftChild()){
      tmp -> left = Insert(radice -> left);
    }
    if(radice->HasRightChild()){
      tmp -> right = Insert(radice -> right);
    }
    return tmp;
}

// Funzione Insert (LinearContainer)
template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::Insert(const LinearContainer<Data>& lcon, unsigned int i, NodeLnk* root){
  if(i < lcon.Size()){
    root = new NodeLnk(lcon[i]);
    root->left = Insert(lcon,(i*2)+1,root->left);
    root->right = Insert(lcon,(i*2)+2,root->right);
   }
  return root;
}

/* ************************************************************************** */

}
