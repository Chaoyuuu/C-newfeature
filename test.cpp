#include <iostream>
#include <vector>

template <class T> class MyPtr
{
private:
    T* _ptr;
    static int iCount;
    
public:
    MyPtr(T* ptr_)
    {
        std::cout << "pointer constructed, ";
        iCount++;
        std::cout << "reference count " << iCount << std::endl;
        _ptr = ptr_;
    }

    // redefine the clone constructor  
    MyPtr(const MyPtr& self_)
    {
        std::cout << "pointer cloned, ";
        iCount++;
        std::cout << "reference count " << iCount << std::endl;
        _ptr = self_.get();
    }

    // redefine the assignment operator
    void operator = (const MyPtr& self_)
    {
        std::cout << "pointer assigned, ";
        iCount++;
        std::cout << "reference count " << iCount << std::endl;
        _ptr = self_.get();
    }

    ~MyPtr()
    {
        std::cout << "pointer destructed, ";
        iCount--;
        std::cout << "reference count " << iCount << std::endl;
        if(iCount==0)
            delete _ptr;
    }

    T* get() const {return _ptr;}
};

template <class T> int MyPtr<T>::iCount = 0;


class Test1
{
public:
    Test1(){std::cout<<"test 1 constructed"<<std::endl;}
    ~Test1(){std::cout<<"test 1 destructed"<<std::endl;}
    void print(){std::cout<<"print was called in the test 1"<<std::endl;}
};

class Test2
{
public:
    Test2(){std::cout<<"test 2 constructed"<<std::endl;}
    ~Test2(){std::cout<<"test 2 destructed"<<std::endl;}
    void print(){std::cout<<"print was called in the test 2"<<std::endl;}
};

typedef MyPtr<Test1> Test1_Ptr;
typedef MyPtr<Test2> Test2_Ptr;
typedef std::vector<Test2_Ptr> ArrTest2_Ptr;

ArrTest2_Ptr arrTest2_Ptr;

void Program2(Test1_Ptr test1_Ptr_)
{
    test1_Ptr_.get()->print();

    arrTest2_Ptr.at(0).get()->print();
    arrTest2_Ptr.erase(arrTest2_Ptr.begin());
}

void Program1()
{
    Test2_Ptr test2_Ptr(new Test2());
    Test1_Ptr test1_Ptr(new Test1());
    
    arrTest2_Ptr.push_back(test2_Ptr);

    Program2(test1_Ptr);
}

int main(int argc, char** argv)
{
    Program1();
    std::cout << "End" << std::endl;
}

