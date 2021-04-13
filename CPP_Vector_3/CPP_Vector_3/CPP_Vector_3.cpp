#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Iterator
{
public:
    Iterator() : _ptr(nullptr)
    {

    }
    Iterator(T* ptr) : _ptr(ptr)
    {

    }
    Iterator& operator+(const int count)
    {
        Iterator temp = *this;
        temp._ptr += count;
        return temp;
    }
    Iterator& operator-(const int count)
    {
        Iterator temp = *this;
        temp._ptr -= count;
        return temp;
    }
    Iterator& operator++()
    {
        _ptr++;

        return *this;
    }
    Iterator operator++(int)
    {
        Iterator temp = *this;
        _ptr++;

        return *this;
    }
    Iterator& operator--()
    {
        _ptr--;

        return *this;
    }
    Iterator operator--(int)
    {
        Iterator temp = *this;
        _ptr--;

        return *this;
    }
    bool operator==(const Iterator& right)
    {
        return _ptr == right._ptr;
    }
    bool operator!=(const Iterator& right)
    {
        return !(*this == right);
    }
    T& operator*()
    {
        return *_ptr;   // 실제 데이터를 복사하는 것 처럼 반환
    }


public:
    T* _ptr;

};


template<typename T>
class Vector
{
public:
    Vector() : _data(nullptr), _size(0), _capacity(0)
    {

    }
    ~Vector()
    {
        if (_data != nullptr)
            delete[] _data;     // 동적배열로 만들어 줄것이므로
    }
    int size()
    {
        return _size;
    }
    int capacity()
    {
        return _capacity;
    }
    void push_back(const T& val)
    {
        if (_size == _capacity)
        {
            // 증설
            int newCapacity = static_cast<int>(_capacity * 1.5);
            if (newCapacity == _capacity)
                newCapacity++;
            reserve(newCapacity);
        }
        // 데이터 저장
        _data[_size] = val;
        // 데이터 개수 증가
        _size++;
        
    }
    void reserve(int capacity)
    {
        _capacity = capacity;
        // 일단 만들기
        T* newData = new T[_capacity];
        // 복사
        for (int i = 0; i < _size; i++)
        {
            newData[i] = _data[i];
        }
        // 이전 데이터 날리기
        if (_data)
            delete _data;

        // 이제 가리키는 거 바꾸기
        _data = newData;
    }
    // 실제 값을 건드릴 수도 있기 떄문에 참조로 반환
    T& operator[](const int pos)
    {
        return _data[pos];
    }

public:
    typedef Iterator<T> iterator;
    
    void clear() { _size = 0; }
    iterator begin() 
    { 
        return iterator(&_data[0]); 
    }
    iterator end() 
    {
        return begin() + _size; 
    }


public:
    T* _data;
    int _size;
    int _capacity;

};

int main()
{
    Vector<int> v;

    v.reserve(100);

    for (int i = 0; i < 100; i++)
    {
        v.push_back(i);
        cout << v.size() << " " << v.capacity() << endl;
    }

    for (int i = 0; i < 100; i++)
    {
        cout << v[i] << endl;
    }

    cout << "----------------------------------" << endl;

    for (Vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << (*it) << endl;
    }

    v.clear();

    return 0;
}