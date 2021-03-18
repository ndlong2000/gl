#include <iostream>
using namespace std;
class Door
{
  class State *current;
  public:
    Door();
    void setCurrent(State *s)
    {
        current = s;
    }
    void unlock();
    void open();
    void close();
    void lock();
};

class State
{
  public:
    virtual void unlock(Door *m)
    {
        cout << "   already unlocked\n";
    }
    virtual void close(Door *m)
    {
        cout << "   already Closed\n";
    }
    virtual void open(Door *m)
    {
        cout << "   already Opened\n";
    }
    virtual void lock(Door *m)
    {
        cout << "   already Locked\n";
    }
};

void Door::unlock()
{
  current->unlock(this);
}

void Door::open()
{
  current->open(this);
}

void Door::close()
{
  current->close(this);
}

void Door::lock()
{
  current->lock(this);
}

class Locked: public State
{
  public:
    Locked()
    {
        cout << "   Locked-ctor ";
    };
    ~Locked()
    {
        cout << "   dtor-Locked\n";
    };
    void unlocked(Door* m);
};

class Closed: public State
{
  public:
    Closed()
    {
        cout << "   Closed-ctor ";
    };
    ~Closed()
    {
        cout << "   dtor-Closed\n";
    };
    void lock(Door *m);
    void open(Door *m);
};
class Opened: public State
{
  public:
    Opened()
    {
        cout << "   Opened-ctor ";
    };
    ~Opened()
    {
        cout << "   dtor-Opened\n";
    };
    void close(Door *m);
};
void Locked::unlocked(Door *m)
{
  cout << "   unlocked Door";
  m->setCurrent(new Closed());
  delete this;
}

void Closed::lock(Door *m)
{
    cout << "   lock Door";
    m->setCurrent(new Locked());
    delete this;
}
void Closed::open(Door *m)
{
    cout << "   open Door";
    m->setCurrent(new Opened());
    delete this;
}
void Opened::close(Door *m)
{
    cout << "   close Door";
    m->setCurrent(new Closed());
    delete this;
}

Door::Door()
{
  current = new Locked();
  cout << '\n';
}

int main()
{
  void(Door:: *ptrs[])() =
  {
    Door::unlock, Door::open, Door::close, Door::lock
  };
  Door d;
  int num;
  while (1)
  {
    cout << "Enter 0/1/2/3: ";
    cin >> num;
    (d. *ptrs[num])();
  }
}
