#include <iostream>
using namespace std;


// 스마트 포인터 
// 코드 안정성
// UE만 까봐도 대부분 스마트 포인터


class Knight
{
public:
    Knight()
    {
        cout << "Knight 생성" << endl;
    }
    ~Knight()
    {
        cout << "Knight 소멸" << endl;
    }

    void Attack()
    {
        if (_target.expired() == false)
        {
            shared_ptr<Knight> sptr = _target.lock();
            sptr->_hp -= _damage;
            cout << "HP: " << sptr->_hp << endl;
        }
    }

public:
    int _hp = 100;
    int _damage = 10;
    // shared_ptr<Knight> _target = nullptr;
    weak_ptr<Knight> _target;
};

class RefCountBlock
{
public:
    // 0이 되면 삭제해도 된다.
    int _refCount = 1;      // 객체를 참조하는 포인터가 몇개인지 체크
    int _weakCount = 1;     // 위크포인터 몇개가 객체를 참고하고 있는지 체크
};

// 포인터 자체를 몇명이나 참조를 하고 있는지 추적해서 멋대로 삭제하는게 아니라 이 객체를 아무도 기억하지 않을때 delete한다
// 절대로 delete를 함부로 하지 않고 모두가 잊었을 떄 삭제
template<typename T>
class SharedPtr
{
public:
    SharedPtr()
    {

    }
    SharedPtr(T* ptr) : _ptr(ptr)
    {
        if (_ptr != nullptr)
        {
            _block = new RefCountBlock();
            cout << "RefCount : " << _block->_refCount << endl;
        }
    }
    SharedPtr(const SharedPtr& sptr) : _ptr(sptr->_ptr), _block(sptr->_block)
    {
        if (_ptr != nullptr)
        {
            _block->_refCount++;
            cout << "RefCount : " << _block->_refCount << endl;
        }
    }

    void operator=(const SharedPtr& sptr)
    {
        _ptr = sptr._ptr;
        _block = sptr._block;
        if (_ptr != nullptr)
        {
            _block->_refCount++;
            cout << "RefCount : " << _block->_refCount << endl;
        }
    }

    ~SharedPtr()
    {
        if (_ptr != nullptr)
        {
            _block->_refCount--;
            cout << "RefCount : " << _block->_refCount << endl;

            if (_block->_refCount == 0)
            {
                delete _ptr;
                delete _block;
                cout << "Delete Data" << endl;
            }
        }
    }

public:
    T* _ptr = nullptr;
    RefCountBlock* _block = nullptr;
};

int main()
{
    //Knight* k1 = new Knight();
    //Knight* k2 = new Knight();

    //k1->_target = k2;

    //delete k2;

    //k1->Attack();
    
    // 스마트 포인터 : 포인터를 알맞는 정책에 따라 관리하는 객체 (포인터를 래핑해서 사용)
    // shared_ptr, weak_ptr, unique_ptr
    shared_ptr<Knight> k1 = make_shared<Knight>();

    // 이렇게 서로를 바라보고 있다면 shared_ptr로는 절대로 삭제할 수 없다.
    // k1 [   2]
    // k2 [   1]
    shared_ptr<Knight> k2 = make_shared<Knight>();
    k1->_target = k2;
    k2->_target = k1;
    k1->Attack();

    unique_ptr<Knight> uptr = make_unique<Knight>();
    unique_ptr<Knight> uptr2 = std::move(uptr);
    // unique_ptr<Knight> uptr2 = uptr; // 절대 못넘김 할거면 오른값
    


    return 0;
}
