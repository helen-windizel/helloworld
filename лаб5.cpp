#include <iostream>
#include <fstream>
#include <cmath>


using namespace std;


class MyVector
{
    int _size, _capacity;
int *_data;


public:
    int size()
    {
        return _size;
    }
    int capacity()
    {
        return _capacity;
    }
    int& operator [](int i) const
    {
        return _data[i];
    }


    void Insert(int i, int x)
    {
        if(abs(i) >= _size)
            cout << "индекс вышел за границы вектора" << endl;
            return;
        _data[i] = x;  
       
    }
    MyVector()
    {
        _size = 0;
        _capacity = 8;
        _data = new int[8];
    }
    MyVector(MyVector& v)
    {
        _size = v.size();
        _capacity = v.capacity();
        _data = new int[_capacity];
        for(int i = 0; i < _size; i++)
            _data[i] = v[i];
    }
    MyVector(int size)
    {
        _size = size;
        _capacity = size * 2;
        _data = new int[_capacity];
    }
    MyVector(int n,int initialValue)
    {
        _capacity = 2 * n;
        _size = n;
        _data = new int[2 * n];
        for(int i = 0; i < n; i++)
            _data[i] = initialValue;
    }


    void Print()
    {
        for(int i = 0; i < _size; i++)
            cout <<_data[i] << " ";
        cout << endl;
    }


   MyVector& operator= (const MyVector& v) {
    if (this != &v) { 
        delete[] _data;                
        _size = v._size;                
        _capacity = v._capacity;
        _data = new int[v._capacity];   
        for (int i = 0; i < _size; i++) {
            _data[i] = v._data[i];      
        }
    }
    return *this;                      
}
    ~MyVector()
    {
        delete[] _data;
    }
    int Front()
    {
        return _data[0];
    }
    int Back()
    {
        return _data[_size - 1];
    }
    void PushBack(int x) {
        if(_size == _capacity) {
            int *new_data = new int[_capacity * 2];
            for(int i = 0; i < _size; i++)
                new_data[i] = _data[i];
            delete[] _data;
            _data = new_data;
            _capacity *= 2;
        }
        _data[_size++] = x;
    };
       
    
    void Resize(int NewSize)
    {
        if(NewSize < 0)
            cout << "недопустимый размер вектора" << endl;
            return;
        if(NewSize < _capacity)
            _size = NewSize;
        if(NewSize > _capacity)
        {
            int * new_data = new int [NewSize + 10];
            for(int i = 0; i < _capacity; i++)
                new_data[i] = _data[i];
            delete [] _data;
            _data = new_data;
            _capacity = NewSize + 10;
            _size = NewSize;
        }
    }
    void Reverse()
    {
        for(int i = 0; i < _size; i++)
            swap(_data[i], _data[_size - i - 1]);
    }
    void ShrinkToFit()
    {
        if (_size == _capacity)
            return;
        int *tmp = new int[_size];
        for(int i = 0; i < _size; i++)
            tmp[i] = _data[i];
        delete [] _data;
        _data = tmp;
        _capacity = _size;
    }
    bool Empty()
    {
        return (_size == 0) ? true : false;
    }
    void Erase(int i)
    {
        if(i >= _size || i < 0)
            cout << "индекс вышел за границы вектора" << endl;
            return;
        for(int j = i; j < _size; j++)
            _data[j] = _data[j + 1];
        _data[_size - 1] = 0;
        _size--;
    }
    MyVector operator + (const MyVector& other)
    {
        MyVector a(_size);
        if(_size != other._size){
            cout << "векторы должны быть одного размера" << endl;
            return a;
        }
        for(int i = 0; i < _size; i++)
            a.PushBack(_data[i] + other._data[i]);
        return a;
    }
    MyVector operator - (const MyVector& other)
    {
        MyVector a(_size);
        if(_size != other._size)
            cout << "векторы должны быть одного размера" << endl;
            return a;
        for(int i = 0; i < _size; i++)
            a.PushBack(_data[i] - other._data[i]);
        return a;
    }
    MyVector operator *(int x)
    {
        MyVector a(_size);
        for(int i = 0; i < _size; i++)
            a.PushBack(_data[i] *  x);
        return a;
    }


    double DotProduct(const MyVector& other) const
    {
        if(_size != other._size)
            cout << "векторы должны быть одного размера" << endl;
            return -100;
        double product = 0;
        for(int i = 0; i < _size; i++)
            product += _data[i] * other._data[i];
        return product;
    }


    MyVector VecProduct(const MyVector& other)
    {
        if(_size != 3 || _size != other._size)
            cout << "только для трехмерного пространства" << endl;
            return *this;
        MyVector a(3);
        a.PushBack(_data[1] * other._data[2] - _data[2] * other._data[1]);
        a.PushBack(-(_data[0] * other._data[2] - _data[2] * other._data[0]));
        a.PushBack(_data[0] * other._data[1] - _data[1] * other._data[0]);
        return a;
    }


};


int main()
{
    MyVector a;
    cout << a.Empty() << endl;
    a.PushBack(4);
    a.PushBack(7);
    


    MyVector b;
    b = a;
    b.PushBack(10);
    a.Print();
    b.Print();




    MyVector c = b;
    c.Erase(1);
    c.ShrinkToFit();
    cout << c.capacity() << endl;
    cout << endl;


    MyVector d = c;
    d.Resize(d.size() + 10);
    cout << d.capacity() << endl;
    cout <<"Front: " << d.Front() << "  Back:  " << d.Back() << endl;


    MyVector e = d;
    e.Insert(1, 5);
    e.Print();
    cout << endl;


    MyVector f(2,4);
    f.Print();
    f = f + a;
    f.Print();
    f = f - a;
    f.Print();
    f = f * 5;
    f.Print();
    cout << endl;


    MyVector g(2,4);
    g.PushBack(1);
    g.PushBack(1);
    g.PushBack(1);

    MyVector h(1,1);
    h.PushBack(1);
    h.PushBack(1);
    h.PushBack(1);

    MyVector j(2,4);
    MyVector r(2,4);
    double k;
    k = j.DotProduct(r);
    cout << k;
    return 0;
}
