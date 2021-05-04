
namespace lasd {

/* ************************************************************************** */
//Copy constructor
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data>& albero)
{
  vettore.Resize(albero.size);
  for(unsigned long i = 0; i < albero.size; i++)
  {
    vettore[i] = new NodeVec();
    vettore[i]->elemento = albero.vettore[i]->elemento;
    vettore[i]->indiceNodoCurr = albero.vettore[i]->indiceNodoCurr;

    vettore[i]->vec = &vettore;
  }
  size = albero.size;

}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const LinearContainer<Data>& con)
{
  vettore.Resize(con.Size());
  for(unsigned long i = 0; i < con.Size(); i++)
  {
    vettore[i] = new NodeVec();
    vettore[i]->elemento = con[i];
    vettore[i]->indiceNodoCurr = i;

    vettore[i]->vec = &vettore;
  }
  size = con.Size();
}

//Move constructor
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec&& albero) noexcept
{
  std::swap(vettore, albero.vettore);
  std::swap(size, albero.size);
}
//Copy Assigment
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(const BinaryTreeVec<Data>& albero)
{
  Clear();
  vettore.Resize(albero.size);
  for(unsigned i = 0; i < albero.size; i++)
  {
    vettore[i] = new NodeVec();
    vettore[i]->elemento = albero.vettore[i]->elemento;
    vettore[i]->indiceNodoCurr = albero.vettore[i]->indiceNodoCurr;

    vettore[i]->vec = &vettore;
  }
  size = albero.size;
  return *this;
}
//Move Assigment
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(BinaryTreeVec&& albero) noexcept
{
  std::swap(vettore, albero.vettore);
  std::swap(size, albero.size);
  return *this;
}

template <typename Data>
Data& BinaryTreeVec<Data>::NodeVec::Element() noexcept
{
  return elemento;
}
template <typename Data>
const Data& BinaryTreeVec<Data>::NodeVec::Element() const noexcept
{
  return elemento;
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept
{
  if(2*(indiceNodoCurr) + 1 < vec->Size())
    return true;
  else
    return false;

}
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept
{
  if(2*(indiceNodoCurr) + 2 < vec->Size())
    return true;
  else
    return false;
}

// LeftChild
template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::LeftChild() const
{
  if(HasLeftChild())
  {
    return *((*vec)[(2*indiceNodoCurr)+ 1]);
  }
  else
  {
    throw std::out_of_range("Il nodo corrente non ha figlio sinistro!");
  }

}

// RightChild
template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::RightChild() const
{
  if(HasRightChild())
  {
   return *((*vec)[(2*indiceNodoCurr)+ 2]);
  }
  else
  {
    throw std::out_of_range("Il nodo corrente non ha figlio destro!");
  }

}
//Metodo Root()
template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::Root() const
{
  if(size > 0)
    return *(vettore[0]);
  else
    throw std::length_error("Albero vuoto!");
}

//Metodo Clear()
template <typename Data>
void BinaryTreeVec<Data>::Clear()
{
  for(int i = 0; i < size; i++)
  {
    delete vettore[i];
  }
  vettore.Clear();
  size = 0;
}

template <typename Data>
BinaryTreeVec<Data>::~BinaryTreeVec()
{
  Clear();
}

// Opertator ==
template <typename Data>
bool BinaryTreeVec<Data>::operator==(const BinaryTreeVec& albero2) const noexcept
{
  // if(size == albero2)
  // {
  //   for(unsigned long i = 0; i < size; i++)
  //   {
  //     if(vettore[i]->elemento == albero2.vettore[i]->element || vettore[i]->indiceNodoCurr == albero2.vettore[i]->indiceNodoCurr)
  //     {
  //       continue;
  //     }
  //     else
  //       return false;
  //   }
  // }
  // else
    return false;
}
// Opertator !=
template <typename Data>
bool BinaryTreeVec<Data>::operator!=(const BinaryTreeVec& albero2) const noexcept
{
  // return  !(Root() == albero2.Root();
  return false;
}
/* ************************************************************************** */

}
