
template<typename type>
struct Node_array
{
    type value;
    Node_array *prev;
    Node_array *next;
    Node_array(type val) : value{val},prev(nullptr), next(nullptr) {}
};


template<typename type>
class Iter
{
public:
    Node_array<type> *link_;
    Iter(Node_array<type>* link):link_(link){}

    type& operator*()
    {
        return link_->value;
    }

    Iter& operator++()
    {
        if(link_->next)
        {
            link_ = link_->next;
        }
        return *this; 
    }

    Iter& operator--()
    {
        if (link_->prev)
        {
            link_=link_->prev;
        }
        return *this;
    }

    bool operator!=(const Iter& other) const
    {
        return link_ != other.link_;
    }
    
};



template<typename type>
class Spis2_array
{
public:
    Node_array<type> *first;
    Node_array<type> *last;
    int size_;
    Spis2_array() : first(nullptr),last(nullptr), size_(0) {}
    Spis2_array(std::initializer_list<type> list) : first(nullptr), last(nullptr), size_(0)
    {
        for (auto it = list.begin(); it != list.end(); ++it)
        {
            pushback(*it);  
        }
    }
    ~Spis2_array()
    {
        clear();
    }
    type& operator[](int index)
    {
        if(index<0 || index>=size_)
        {
            throw std::out_of_range("Index out of bounds");
        }
        Node_array<type> *current=first;
        for(int i=0;i<index;i++)
        {
            current=current->next;
        }
        return current->value;
    }
    int size()
    {
        return this->size_;
    }
    void pushback(type val)
    {
        Node_array<type> *newnode=new Node_array<type>(val);
        if(this->size_==0)
        {
            first=last=newnode;
        }
        else
        {
            last->next=newnode;
            newnode->prev=last;
            last=newnode;
        }
        size_++;
    }
    void insert(int index,type val)
    {
        Node_array<type> *newnode=new Node_array<type>(val);
        if(index==0)
        {
            if(size_==0)
            {
                pushback(val);
            }
            else
            {
                newnode->next=first;
                first->prev=newnode;
                first=newnode;
            }
        }
        else if(index==(size_+1))
        {
            pushback(val);
        }
        else if(index>(size_+1))
        {
            throw std::out_of_range("Index out of bounds");
        }
 
        else
        {
            Node_array<type> *current=first;
            for(int i=0;i<index-1;i++)
            {
                current=current->next;
            }
            newnode->next=current->next;
            current->next=newnode;
            newnode->prev=current;
        }
        size_++;
    };
    void erase(int index)
    {
        if(size_==0)
        {
            return;
        }
        else if(index<0 || index>size_)
        {
            throw std::out_of_range("Index out of bounds");
        }

        Node_array<type> *current=first;
        if(index==0)
        {
            if(size_==1)
            {
                delete current;
            }
            else
            {
                first=first->next;
                delete current;
            }
        }
        else if(index==(size_-1))
        {
            current=last;
            last=last->prev;
            delete current;
        }
        else
        {
            for(int i=0;i<index;i++)
            {
                current=current->next;
            }
            current->prev->next=current->next;
            current->next->prev=current->prev;
            delete current;
        }
        size_--;
    }
    void erase(int start,int last)
    {
        if(size_==0)
        {
            throw std::out_of_range("Index out of bounds");
        }
        else if(start<0 || last>size_)
        {
            throw std::out_of_range("Index out of bounds");
        }
        else if(start==last)
        {
            erase(start);
        }
        else
        {
            for(int k=start;k<=last;k++)
            {
                erase(start);
            }
        }
    }
    void clear()
    {
        Node_array<type> *current=first;
        while(current!=nullptr)
        {
            Node_array<type> *n=current->next;
            delete current;
            current=n;
        }
        first=nullptr;
        last=nullptr;
        size_=0;
    };

    Iter<type> begin()
    {
        return Iter<type>(first);
    }

    Iter<type> end()
    {
        return Iter<type>(last);
    }


};


template<typename type>
class Spis1_array
{
public:
    Node_array<type> *first;
    Node_array<type> *last;
    int size_;
    Spis1_array() : first(nullptr),last(nullptr), size_(0) {}
    Spis1_array(std::initializer_list<type> list) : first(nullptr), last(nullptr), size_(0)
    {
        for (auto it = list.begin(); it != list.end(); ++it)
        {
            pushback(*it);  
        }
    }
    ~Spis1_array()
    {
        clear();
    }
    type& operator[](int index)
    {
        if(index<0 || index>=size_)
        {
            throw std::out_of_range("Index out of bounds");
        }
        Node_array<type> *current=first;
        for(int i=0;i<index;i++)
        {
            current=current->next;
        }
        return current->value;
    }
    int size()
    {
        return size_;
    }
    void pushback(type val)
    {
        Node_array<type> *newnode=new Node_array<type>(val);
        if(this->size_==0)
        {
            first=last=newnode;
        }
        else
        {
            last->next=newnode;
            last=newnode;
        }
        size_++;
    }
    void insert(int index,type val)
    {
        Node_array<type> *newnode=new Node_array<type>(val);
        if(index==0)
        {
            if(size_==0)
            {
                pushback(val);
            }
            else
            {
                newnode->next=first;
                first=newnode;
            }
        }
        else if(index==(size_+1))
        {
            pushback(val);
        }
        else if(index>(size_+1)||index<0)
        {
            throw std::out_of_range("Index out of bounds");
        }
 
        else
        {
            Node_array<type> *current=first;
            for(int i=0;i<index-1;i++)
            {
                current=current->next;
            }
            newnode->next=current->next;
            current->next=newnode;
        }
        size_++;
    }
    void erase(int index)
    {
    if(size_==0)
        {
            return;
        }
        else if(index<0 || index>size_)
        {
            throw std::out_of_range("Index out of bounds");
        }

        Node_array<type> *current=first;
        if(index==0)
        {
            if(size_==1)
            {
                delete current;
            }
            else
            {
                first=first->next;
                delete current;
            }
        }
        else if(index==(size_-1))
        {
            for(int i=0;i<index-1;i++)
            {
                current=current->next;
            }
            last=current;
            current=last->next;
            delete current;
           
        }
        else
        {
            for(int i=0;i<index-1;i++)
            {
                current=current->next;
            }
            Node_array<type> *to_erase =current->next;
            current->next=current->next->next;
            delete to_erase;
        }
        size_--;        
    }
    void erase(int start,int last)
    {
        if(size_==0)
        {
            throw std::out_of_range("Index out of bounds");
        }
        else if(start<0 || last>size_)
        {
            throw std::out_of_range("Index out of bounds");
        }
        else if(start==last)
        {
            erase(start);
        }
        else
        {
            for(int k=start;k<=last;k++)
            {
                erase(start);
            }
        }
    }
    void clear()
    {
        Node_array<type> *current=first;
        while(current!=nullptr)
        {
            Node_array<type> *n=current->next;
            delete current;
            current=n;
        }
        first=nullptr;
        last=nullptr;
        size_=0;
    };


    Iter<type> begin()
    {
        return Iter<type>(first);
    }

    Iter<type> end()
    {
        return Iter<type>(last);
    }
};
