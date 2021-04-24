
namespace lasd
{

/* ************************************************************************** */
template<typename Data>
StackVec<Data>::StackVec() //costruttore senza parametri
{
  Vector<Data>::Resize(1);
}

template<typename Data>
StackVec<Data>::StackVec(const LinearContainer<Data>& con):Vector<Data>::Vector(con)
{
  indice = con.Size() - 1;
}

//Copy assignment
template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(const StackVec<Data>& newVec)
{
  Vector<Data>::operator=(newVec);
  indice = newVec.indice;
  return *this;
}
//move assignment
template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(StackVec<Data>&& newVec) noexcept
{
  Vector<Data>::operator=(std::move(newVec));
  std::swap(indice, newVec.indice);
  return *this;
}

//Copy constructor
template<typename Data>
StackVec<Data>::StackVec(const StackVec<Data>& newVec):Vector<Data>(newVec)
{
  indice = newVec.indice;
  //la size la fa nel costruttore di vector<int> v;
}

//move constructor
template <typename Data>
StackVec<Data>::StackVec(StackVec<Data>&& vec) noexcept
{
    std::swap(Elements, vec.Elements);
    std::swap(indice, vec.indice);
    std::swap(size, vec.size);
}


//Copy PUSH
template <typename Data>
void StackVec<Data>::Push(const Data& val)
{
  if((indice + 1) == (size - 1) )
    Expand();

  Elements[indice + 1] = val;
  indice++;
}

//move PUSH
template <typename Data>
void StackVec<Data>::Push(Data&& val) noexcept
{
  if((indice + 1) == (size - 1))
  {
    Expand();
  }
  Elements[indice + 1] = std::move(val);
  indice++;
}

template <typename Data>
void StackVec<Data>::Pop()
{
  if((indice + 1) == (size/2))
  {
    Reduce();
  }
  if(indice == -1)
      throw std::length_error("Impossibile accedere al primo elemento di uno stack vuoto!");
  else
    indice--;
}

//TopNPop
template <typename Data>
Data StackVec<Data>::TopNPop()
{
  Data valueRemoved = Top();
  Pop();
  return valueRemoved;
}

template <typename Data>
Data& StackVec<Data>::Top() const
{
  if(indice > -1)
    return Elements[indice];
  else
    throw std::length_error("Impossibile accedere al primo elemento di uno stack vuoto!");
}

template <typename Data>
void StackVec<Data>::Expand()
{
    Vector<Data>::Resize(size * 2);
}
template <typename Data>
void StackVec<Data>::Reduce()
{
    Vector<Data>::Resize(size - (size / 4));
}
//operator ==
template <typename Data>
bool StackVec<Data>::operator==(const StackVec<Data>& newVec) const noexcept
{
  if(Size() != newVec.Size())
    return false;
  else
  {
    bool buff = true;
    unsigned long i = 0;
    while(buff && i < Size())
    {
      if(Elements[i] != newVec.Elements[i])
        buff = false;
      i++;
    }
    return buff;
  }
  return true;
}
//operator !=
template <typename Data>
bool StackVec<Data>::operator!=(const StackVec<Data>& newVec) const noexcept
{
  return !(*this==newVec);
}

template <typename Data>
bool StackVec<Data>::Empty() const noexcept
{
  if(indice == -1)
    return true;
  else
    return false;
}

template <typename Data>
unsigned long StackVec<Data>::Size() const noexcept
{
  return indice + 1;
}

template <typename Data>
void StackVec<Data>::Clear()
{
  Vector<Data>::Clear();
  Vector<Data>::Resize(1);
  indice = -1;
}
/* ************************************************************************** */

}
