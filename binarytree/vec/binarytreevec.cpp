
namespace lasd {

/* ************************************************************************** */

// Copy constructor
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data>& tree){
  vector.Resize(tree.size);
  for(unsigned int i = 0; i < tree.size; i++){
    vector[i] = new NodeVec();
    vector[i] -> element = tree.vector[i] -> element;
    vector[i] -> indexCurrNode = tree.vector[i] -> indexCurrNode;
    vector[i] -> v = &vector;
  }
  size = tree.size;
}

// Move constructor
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec<Data>&& tree) noexcept{
  std::swap(vector, tree.vector);
  std::swap(size, tree.size);
}

// Costruttore da un'altra struttura LinearContainer<Data> (vector, list, etc...)
template<typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const LinearContainer<Data>& lcon){
  vector.Resize(lcon.Size());
  for(unsigned int i = 0; i < lcon.Size(); i++){
  vector[i] = new NodeVec();
  vector[i] -> element = lcon[i];
  vector[i] -> indexCurrNode = i;
  vector[i] -> v = &vector;
  }
  size = lcon.Size();
}

// Distruttore
template<typename Data>
BinaryTreeVec<Data>::~BinaryTreeVec(){
  Clear();
}

// Copy assignment
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(const BinaryTreeVec<Data>& tree){
  Clear();
  vector.Resize(tree.vector.Size());
  for(unsigned int i = 0; i < tree.vector.Size(); i++){
  vector[i] = new NodeVec();
  vector[i] -> element = tree.vector[i] -> element;
  vector[i] -> indexCurrNode = i;
  vector[i] -> v = &vector;
  }
  size = tree.Size();
  return *this;
}

// Move assignment
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(BinaryTreeVec<Data>&& tree) noexcept{
  std::swap(vector, tree.vector);
  std::swap(size, tree.size);
  return *this;
}

// Element
template <typename Data>
Data& BinaryTreeVec<Data>::NodeVec::Element() noexcept{
  return element;
}

// Element (const)
template <typename Data>
const Data& BinaryTreeVec<Data>::NodeVec::Element() const noexcept{
  return element;
}

// HasLeftChild
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept{
  if(2*(indexCurrNode) + 1 < v->Size()){
    return true;
  }else{
    return false;
  }
}

// HasRightChild
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept{
  if(2*(indexCurrNode ) + 2 < v->Size()){
  return true;
  }else{
    return false;
  }
}

// IsLeaf
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::IsLeaf() const noexcept{
  if(!(HasLeftChild() || HasRightChild())){
    return true;
  }else{
    return false;
  }
}

// LeftChild
template <typename Data>
typename BinaryTreeVec<Data>::NodeVec&
BinaryTreeVec<Data>::NodeVec::LeftChild() const{
  if(HasLeftChild()){
    return *((*v)[2*(indexCurrNode) + 1]);
  }else{
    throw std::out_of_range("Il nodo corrente non ha figlio sinistro!");
  }
}

// RightChild
template <typename Data>
typename BinaryTreeVec<Data>::NodeVec&
BinaryTreeVec<Data>::NodeVec::RightChild() const{
  if(HasRightChild()){
    return *((*v)[2*(indexCurrNode) + 2]);
  }else{
    throw std::out_of_range("Il nodo corrente non ha figlio destro!");
  }
}

// Root
template <typename Data>
typename BinaryTreeVec<Data>::NodeVec&
BinaryTreeVec<Data>::Root() const{
   if(vector.Empty()){
     throw std::length_error("Albero vuoto!");
   }else{
     return *(vector[0]);
   }
}

// Clear
template <typename Data>
void BinaryTreeVec<Data>::Clear(){
  for(unsigned int i = 0; i < size; i++){
    delete vector[i];
  }
  vector.Clear();
  size = 0;
}

// Opertator ==
template <typename Data>
bool BinaryTreeVec<Data>::operator==(const BinaryTreeVec& tree) const noexcept{
  bool val = true;
  if(vector.Size() == tree.vector.Size()){
    for(unsigned int i = 0; i < vector.Size(); i++){
      if(val && tree.vector[i]->Element() != vector[i]->Element()){
        val = false;
      }else{
        val = true;
      }
    }
  }else{
    val = false;
  }
  return val;
}

// Opertator !=
template <typename Data>
bool BinaryTreeVec<Data>::operator!=(const BinaryTreeVec& tree) const noexcept{
  return !(*this == tree);
}

/* ************************************************************************** */

}
