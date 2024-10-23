
template<typename type>
class Posled_arr
{
public:
    int size_;
    int capacity;
    type *arr;
    Posled_arr() : arr(new type[0]),size_(0),capacity(0){}
    Posled_arr(int size) : arr(new type[size]),size_(size),capacity(size){}
    Posled_arr(std::initializer_list<type> list) : size_(list.size())
    {
        arr=new type[size_];
        int i = 0;
        for (auto &elem : list)
        {
            arr[i++] = elem;  
        }
        capacity=size_;
    }
    Posled_arr(Posled_arr &&temp) noexcept : size_(temp.size_),capacity(temp.capacity),arr(temp.arr)
    {
        temp.arr=nullptr;
        temp.size_=0;
        temp.capacity=0;
    }

    Posled_arr& operator=(Posled_arr&& temp) noexcept
    {
        delete[] arr;
        size_=temp.size_;
        capacity=temp.capacity;
        arr=temp.arr;

        temp.arr=nullptr;
        temp.size_=0;
        temp.capacity=0;

        return *this;
    }

    Posled_arr& operator=(const Posled_arr& other)
    {
        delete[] arr;
        size_=other.size;
        capacity=other.capacity;
        arr=other.arr;
        return *this;
    }

    ~Posled_arr()
    {
        delete[] arr;
    }

    type& operator[](int index)
    {
        if(index<0 || index>=size_)
        {
            throw std::out_of_range("Index out of bounds");
        }
        return arr[index];
    }

    type& operator*()
    {
        return *arr;
    }

    type* operator+(int index)
    {
        if(index>size_-1)
        {
            throw std::out_of_range("Index out of bounds");
        }
        return (arr+index);
    }

    int size()
    {
        return size_;
    }

    void pushback(type val)
    {
        if(size_==capacity)
        {
            capacity=static_cast<int>(size_*1.5);
            type *new_arr=new type[capacity];
            for(size_t i=0;i<size_;i++)
            {
                new_arr[i]=arr[i];
            }
            new_arr[size_]=val;
            delete [] arr; 
            arr=new_arr;
            size_++;
        }
        else
        {
            arr[size_]=val;
            size_++;
        }

    }

    void insert(int index,type val)
    {
        if(index<0||index>size_+1)
        {
            throw std::out_of_range("Index out of bounds");
        }
        type *new_arr=new type[size_+1];
        int pos=0;
        for(;pos<index;pos++)
        {
            new_arr[pos]=arr[pos];
        }
        new_arr[index]=val;
        for(;pos<size_;pos++)
        {
            new_arr[pos+1]=arr[pos];
        }
        delete [] arr; 
        arr=new_arr;
        size_++;
        capacity=size_;
    }

    void erase(int index)
    {
        if(index<0||index>size_-1)
        {
            throw std::out_of_range("Index out of bounds");
        }
        type *new_arr=new type[size_-1];
        for(int i=0;i<size_;i++)
        {
            if(i<index)
            {
                new_arr[i]=arr[i];
            }
            else if(i>=index)
            {
                new_arr[i]=arr[i+1];
            }
        }
        delete [] arr; 
        arr=new_arr;
        size_--;
        capacity=size_;
    }

    void erase(int first,int last)
    {
        if(first<0||last>size_-1)
        {
            throw std::out_of_range("Index out of bounds");
        }
        int deleted=last-first+1;
        type *new_arr=new type[size_ - deleted];
        int pos=0;
        for (int i=0;i<size_;i++)
        {
            if(i<first)
            {
                new_arr[pos]=arr[i];
                pos++;
            }
            else if(i>=first && i<=last)
            {
                //ничего не делаем :) :) :) 
            }
            else
            {
                new_arr[pos]=arr[i];
                pos++;
            }
        }
        delete [] arr; 
        arr=new_arr;
        size_-=deleted;
        capacity=size_;
    }

    void clear()
    {
        delete[] arr;
        size_=0;
        capacity=0;
    }
};