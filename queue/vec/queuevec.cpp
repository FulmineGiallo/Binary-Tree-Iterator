
namespace lasd
{

/* ************************************************************************** */
template<typename Data>
QueueVec<Data>::QueueVec() //costruttore senza parametri
{
  Vector<Data>::Resize(2);
  testa = 0;
  sizeEffettiva = 0;
  coda = -1;
}

template<typename Data>
QueueVec<Data>::QueueVec(const LinearContainer<Data>& con)
{
  Vector<Data>::Resize(2);
  for(unsigned long i = 0; i < con.Size(); i++)
  {
      Enqueue(con[i]);
  }
}

//Copy assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec<Data>& newVec)
{
  Vector<Data>::operator=(newVec);
  testa = newVec.testa;
  coda = newVec.coda;
  sizeEffettiva = newVec.sizeEffettiva;
  return *this;
}
//move assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec<Data>&& newVec) noexcept
{
  Vector<Data>::operator=(std::move(newVec));
  testa = newVec.testa;
  coda = newVec.coda;
  sizeEffettiva = newVec.sizeEffettiva;
  return *this;
}

//Copy constructor
template<typename Data>
QueueVec<Data>::QueueVec(const QueueVec<Data>& newVec):Vector<Data>(newVec)
{
  testa = newVec.testa;
  coda  = newVec.coda;
  sizeEffettiva = newVec.sizeEffettiva;

}

//move constructor
template <typename Data>
QueueVec<Data>::QueueVec(QueueVec<Data>&& newVec) noexcept
{
  std::swap(Elements, newVec.Elements);
  std::swap(testa, newVec.testa);
  std::swap(coda, newVec.coda);
  std::swap(sizeEffettiva, newVec.sizeEffettiva);

}


//Copy PUSH
template <typename Data>
void QueueVec<Data>::Enqueue(const Data& val)
{
    if(testa == -1)
      testa = 0;
    if(sizeEffettiva == Vector<Data>::Size())
      Expand();

    coda++;
    coda = (coda % Vector<Data>::Size());
    Elements[coda] = val;
    sizeEffettiva++;
}

//move PUSH
template <typename Data>
void QueueVec<Data>::Enqueue(Data&& val) noexcept
{
    if(testa == -1)
      testa = 0;
    if(sizeEffettiva == Vector<Data>::Size())
      Expand();

    coda++;
    coda = (coda % Vector<Data>::Size());
    Elements[coda] = std::move(val);
    sizeEffettiva++;
}

template <typename Data>
void QueueVec<Data>::Dequeue()
{
  if(sizeEffettiva <= size / 2)
  {
    Reduce();
  }
  if(sizeEffettiva == 0)
    throw std::length_error("Impossibile accedere al primo elemento di uno Coda vuoto!");
  else
  {
    testa++;
    testa = (testa) % Vector<Data>::Size();
    sizeEffettiva--;
  }
}

//TopNPop
template <typename Data>
Data QueueVec<Data>::HeadNDequeue()
{
  Data valueRemoved = Head();
  Dequeue();
  return valueRemoved;
}

template <typename Data>
Data& QueueVec<Data>::Head() const
{
  if(sizeEffettiva > 0)
    return Elements[testa];
  else
    throw std::length_error("Impossibile accedere al primo elemento di una Coda vuoto!");
}


//operator ==
template <typename Data>
bool QueueVec<Data>::operator==(const QueueVec<Data>& newVec) const noexcept
{
    if(sizeEffettiva == newVec.sizeEffettiva)
    {
      int i = testa;
      int j = newVec.testa;
      while(i != coda)
      {
        if(Elements[i] != Elements[j])
          return false;
        else
        {
          i++;
          i = i % Vector<Data>::Size();
          j++;
          j = j % newVec.Vector<Data>::Size();
        }
      }
      return true;
    }
    else
      return false;
}
//operator !=
template <typename Data>
bool QueueVec<Data>::operator!=(const QueueVec<Data>& newVec) const noexcept
{
  return !(*this == newVec);
}

template <typename Data>
bool QueueVec<Data>::Empty() const noexcept
{
  if(sizeEffettiva == 0)
    return true;
  else
    return false;
}

template <typename Data>
unsigned long QueueVec<Data>::Size() const noexcept
{
  return sizeEffettiva;
}

template <typename Data>
void QueueVec<Data>::Clear()
{
  Vector<Data>::Clear();
  Vector<Data>::Resize(2);

  testa = -1;
  coda = -1;
  sizeEffettiva = 0;

}

template <typename Data>
void QueueVec<Data>::Expand()
{
  Vector<Data> v(size * 2);
  //Se testa parte da V[0]
  //Se coda + 1, = testa --> si deve Espandere il vettore con Expand()
  //Se testa == coda, vettore vuoto.
  //Se avessimo 0 1 2 3 --> vuoi inserire di nuovo in coda, quindi if(coda (mod) == Vectror<Data>::Size()) Exapand();
  //Quindi 0 1 2 3 4 5 6 7 --> 3 Dequeue() --> null null null 3 4 5 6 7
  int j = 0;
  if(coda > testa)
  {
    for(unsigned long i = testa; i <= coda; i++)
    {
      v[j] = Elements[i];
      j++;
    }
  }
  if(coda < testa)
  {
    for(unsigned long i = testa; i < Vector<Data>::Size(); i++)
    {
      v[j] = Elements[i];
      j++;
    }
    for(unsigned long i = 0; i <= coda; i++)
    {
      v[j] = Elements[i];
      j++;
    }
  }

  Vector<Data>::operator=(v);
  testa = 0;
  coda = sizeEffettiva - 1;
  size = v.Size();
  v.Clear();

}
template <typename Data>
void QueueVec<Data>::Reduce()
{
  Vector<Data> v(size - (size / 4));
  int j = 0;
  if(coda > testa)
  {
    for(unsigned long i = testa; i <= coda; i++)
    {
      v[j] = Elements[i];
      j++;
    }
  }
  if(coda < testa)
  {
    for(unsigned long i = testa; i < Vector<Data>::Size(); i++)
    {
      v[j] = Elements[i];
      j++;
    }
    for(unsigned long i = 0; i <= coda; i++)
    {
      v[j] = Elements[i];
      j++;
    }
  }
  Vector<Data>::operator=(v);
  testa = 0;
  coda = sizeEffettiva - 1;
  size = v.Size();
  v.Clear();
}
/* ************************************************************************** */

}
