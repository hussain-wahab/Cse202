// Hussain Alabdrabalnabi
// HW-04& Lab-09

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

template<class T>
class Mlist
{
public:
   Mlist();
   T front();
   T end();
   bool in(T x);
   bool empty();
   void addfront(T entry);
   void addend(T entry);
   void addorder(T entry);
   void removefront();
   void removeend();
   void remove(T n);
private:
   vector<T> mlist;
   void remove(typename vector<T>::iterator ix, T n);
   void addorder(typename vector<T>::iterator ix, T n);
};

template<typename T>
Mlist<T>::Mlist()
{
}

template<typename T>
T Mlist<T>::front()
{
return *mlist.begin();
}

template<typename T>
T Mlist<T>::end()
{
return *(--mlist.end());
}

template<typename T>
bool Mlist<T>::in(T x)
{
typename vector <T>::iterator it;
    for (it = mlist.begin(); it != mlist.end(); it++)
      {
        if (*it ==x)
        {
          return true;
        }
      }
    return false;
}

template<typename T>
bool Mlist<T>::empty()
{
if (mlist.size() == 0)
    {
      return true;
    }
else
    {
      return false;
    }
}

template<typename T>
void Mlist<T>::addfront(T entry)
{
mlist.insert(mlist.end(), entry);
}

template<typename T>
void Mlist<T>:: addend(T entry)
{
mlist.insert(mlist.end(), entry);
}

template<typename T>
void Mlist<T>::addorder(T entry)
{
typename vector <T>:: iterator it;
    for (it = mlist.begin(); it != mlist.end(); it++)
      {
        if (entry < *it)
        {
          mlist.insert(it, entry);
          return;
        }
      }
}

template<typename T>
void Mlist<T>::removefront()
{
mlist.erase(mlist.begin());
}

template<typename T>
void Mlist<T>::removeend()
{
mlist.erase(--mlist.end());
}

template<typename T>
void Mlist<T>::remove(T n)
{
typename vector <T>::iterator it;
it = mlist.begin();
while (it != mlist.end())
{
    if(*it == n)
    {
      mlist.erase(it);
    }
    else
    {
      it++;
    }
}
return;
}

template<typename T>
void Mlist<T> :: remove(typename vector <T> :: iterator it, T n)
{
if (it = mlist.end())
{
    return;
}
else
{
    if (*it == n)
    {
      mlist.erase(it);
    }
    else
    {
      remove (++it, n);
    }
}
}

template<typename T>
void Mlist<T>::addorder(typename vector<T>::iterator ix, T n)
{
if (ix = mlist.end())
{
    mlist.insert(mlist.end(), n);
    return;
}
if (n < *ix)
{
    mlist.insert(ix, n);
    return;
}
addorder (++ ix, n);
return;
}

int main()
{
Mlist<int> test1=Mlist<int>() ;
test1.addfront(5);
test1.addfront(7);
test1.addfront(4);
test1.remove(7);
cout << test1.front()<< endl;
cout << test1.end()<< endl;
Mlist<string> test2= Mlist<string>() ;
test2.addfront("John");
test2.addfront("Paul");
test2.addfront("Mary");
test2.addfront("Kate");
test2.remove("Paul");
cout << test2.front()<< endl;
cout << test2.end()<< endl;
}
