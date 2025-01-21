#pragma once
#include <iostream>
#include <cstring>

template <typename T>
class SeqCont
{
    private:
    size_t m_size;
    T* data;

    void freememory(){
        if (data){
            delete[] data;
            //для отладки
            std::cout << "clear mem of seq con" << std::endl;
        }
    }

    public:
    SeqCont();
    ~SeqCont();
    SeqCont(const SeqCont& copy);
    SeqCont& operator=(const SeqCont& copy);
    SeqCont(SeqCont&& moved) noexcept;
    SeqCont& operator=(SeqCont&& moved) noexcept;

    void push_back(T value);
    bool insert(T value, size_t n); //вставка со сдвигом всего остального
    bool erase(size_t n);
    bool update(T value, size_t n); //замена существующего на новое без сдвигов
    size_t size();
    T operator[](size_t n) const;
    void printall();
};

template <typename T>
class ListCont
{
    private:
    size_t m_size;
    struct Node { 
        Node* next; // указатель на следующий элемент Node 
        Node* prev; // указатель на предыдущий элемент Node 
        T data; // пользовательские данные (хранимый объект) 
    };
    Node* data;

    void freememory(){
        if (data){
            
            for(size_t i = m_size; i > 0; i--){
                Node* del_data = data;
                for (size_t j = 1; j < i; j++){
                    del_data = del_data->prev;
                }                
                delete del_data;
            }
            //delete data;
            //для отладки
            std::cout << "clear mem of list con" << std::endl;
        }
    }
    public:
    ListCont();
    ~ListCont();
    ListCont(const ListCont& copy);
    ListCont& operator=(const ListCont& copy);
    ListCont(ListCont&& moved) noexcept;
    ListCont& operator=(ListCont&& moved) noexcept;

    void push_back(T value);
    bool insert(T value, size_t n); //вставка со сдвигом всего остального
    bool erase(size_t n);
    bool update(T value, size_t n); //замена существующего на новое без сдвигов
    size_t size();
    T operator[](size_t n) const;
    void printallslow(); //постоянный пересчет с конца
    void printall(); //проход в начало, далее при помощи next должно работать быстрее


};

//BEGIN SEQ CONSTRUCORS
template <typename T>
inline SeqCont<T>::SeqCont() : m_size{0}, data{nullptr} {}

template <typename T>
inline SeqCont<T>::~SeqCont()
{
    freememory();
}

template <typename T>
inline SeqCont<T>::SeqCont(const SeqCont &copy) : 
    data(copy.data[m_size]),
    m_size(copy.m_size)
{
    data = copy.data;
}

template <typename T>
inline SeqCont<T> &SeqCont<T>::operator=(const SeqCont &copy)
{
    if (this != &copy){
        freememory();
        data = copy.data;
        m_size = copy.m_size;
    }
    return *this;
}

template <typename T>
inline SeqCont<T>::SeqCont(SeqCont &&moved) noexcept :
    data(std::move(moved.data)),
    m_size(moved.m_size)
{
    moved.data = nullptr;
    m_size = 0;
}

template <typename T>
inline SeqCont<T> &SeqCont<T>::operator=(SeqCont &&moved) noexcept
{
    if (this != &moved)
    {
        data = std::move(moved.data);
        m_size = moved.m_size;
    }

    return *this;
}
//END SEQ CONSTRUCTORS


//BEGIN SEQ Members
template <typename T>
inline void SeqCont<T>::push_back(T value)
{
    T* new_data = new T [m_size + 1];
    for (size_t i = 0; i < m_size; i++){
        new_data[i] = data[i];
    }

    new_data[m_size] = value;
    delete[] data;
    data = new_data;
    m_size++;
}

template <typename T>
inline void SeqCont<T>::printall()
{
    for (size_t i = 0; i < m_size; i++)
    {
        std::cout << data[i];
        if ((i+1)!= m_size){
            std::cout << ",";
        }
    }
        std::cout << std::endl;
}

template <typename T>
inline bool SeqCont<T>::insert(T value, size_t n)
{
    if ((n <= m_size)&&(n > 0)){
        T* new_data = new T [m_size + 1];
        size_t j = 0;
        for (size_t i = 0; i < m_size; i++){
            if (i == n - 1){
                new_data[j] = value;
                j++;
            }
            new_data[j] = data[i];
            j++;            
        }
            delete[] data;
            data = new_data;
            m_size++;
        return true;
    }
    if (n == 0){
        std::cout << "error: zero position" << std::endl;
        return false;
    }
    else{
        //наверно вставка в позицию не должна быть больше чем уже существующий список
        std::cout << "error: position to big" << std::endl;
        return false;
    }
}

template <typename T>
inline bool SeqCont<T>::erase(size_t n)
{
    if ((n <= m_size)&&(n > 0)){
        T* new_data = new T [m_size - 1];
        size_t j = 0;
        for (size_t i = 0; i < m_size; i++){
            if (i == n - 1){
                //new_data[j] = value;
                i++;
            }
            new_data[j] = data[i];
            j++;            
        }
            delete[] data;
            data = new_data;
            m_size--;
        return true;
    }
    if (n == 0){
        std::cout << "error: zero position" << std::endl;
        return false;
    }
    else{
        //наверно вставка в позицию не должна быть больше чем уже существующий список
        std::cout << "error: position to big" << std::endl;
        return false;
    }
}

template <typename T>
inline size_t SeqCont<T>::size()
{
    return m_size;
}

template <typename T>
inline bool SeqCont<T>::update(T value, size_t n)
{
    if ((n <= m_size)&&(n > 0)){
        data[n - 1] = value;
        return true;
    }
    if (n == 0){
        std::cout << "error: zero position" << std::endl;
        return false;
    }
    else{
        //наверно вставка в позицию не должна быть больше чем уже существующий список
        std::cout << "error: position to big" << std::endl;
        return false;
    }
}

template <typename T>
inline T SeqCont<T>::operator[](size_t n) const
{
    if ((n <= m_size)&&(n > 0)){
        return {data[n - 1]};
    }
    return {};
}
//END SEQ Members

//BEGIN LIST CONSTRUCORS
template <typename T>
inline ListCont<T>::ListCont() : m_size{0}, data{nullptr}{}

template <typename T>
inline ListCont<T>::~ListCont()
{
    freememory();
}

template <typename T>
inline ListCont<T>::ListCont(const ListCont &copy) : 
    data(copy.data),
    m_size(copy.m_size)
{
    data = copy.data;
}

template <typename T>
inline ListCont<T> &ListCont<T>::operator=(const ListCont &copy)
{
    if (this != &copy){
        freememory();
        data = copy.data;
        m_size = copy.m_size;
    }
    return *this;
}

template <typename T>
inline ListCont<T>::ListCont(ListCont &&moved) noexcept :
    data(std::move(moved.data)),
    m_size(moved.m_size)
{
    moved.data = nullptr;
    m_size = 0;
}

template <typename T>
inline ListCont<T> &ListCont<T>::operator=(ListCont &&moved) noexcept
{
    if (this != &moved)
    {
        data = std::move(moved.data);
        m_size = moved.m_size;

        moved.data = nullptr;
    }

    return *this;
}
//END LIST CONSTRUCORS

//BEGIN LIST Members
template <typename T>
inline void ListCont<T>::push_back(T value)
{
    Node* new_data = new Node{};
    new_data->prev = data;
    new_data->next = nullptr;
    new_data->data = value;
    if (m_size>0){
        data->next = new_data;
    }
    data = new_data;
    m_size++; 
}

template <typename T>
inline bool ListCont<T>::insert(T value, size_t n)
{
    if ((n <= m_size)&&(n > 0)){
        Node* new_data = new Node{};
        Node* temp_data = data;
        new_data->data = value;
        for (size_t i = m_size; i > 1; i--){
            temp_data = temp_data->prev;
        }
        for (size_t j = 1; j <= m_size; j++){
            
            if (j == n){
                new_data->next = temp_data;
                if(n > 1){
                    temp_data = temp_data->prev;
                    temp_data->next = new_data;
                    new_data->prev = temp_data;
                    temp_data = temp_data->next;
                    temp_data = temp_data->next;

                    temp_data->prev = new_data;
                }
                if (n == 1){
                    new_data->prev = nullptr;
                    temp_data->prev = new_data;
                }

                break;
            }
            temp_data = temp_data->next;
        }
        m_size++;
        return true;
    }
    if (n == 0){
        std::cout << "error: zero position" << std::endl;
        return false;
    }
    else{
        //наверно вставка в позицию не должна быть больше чем уже существующий список
        std::cout << "error: position to big" << std::endl;
        return false;
    }
}

template <typename T>
inline bool ListCont<T>::erase(size_t n)
{
    if ((n <= m_size)&&(n > 0)){
        Node* temp_data = data;
        for (size_t i = m_size; i > 1; i--){
            temp_data = temp_data->prev;
        }
        for (size_t j = 1; j <= m_size; j++){
            
            if (j == n){
                Node* prever = temp_data->prev;
                Node* nexter = temp_data->next;

                if(n > 1){
                    prever->next = nexter;
                    nexter->prev = prever;
                }
                if (n == 1){
                    nexter->prev = prever;
                }
                if (n==m_size){
                    prever->next = nexter;
                }
                delete temp_data;
                m_size--;
                break;
            }
            temp_data = temp_data->next;
        }
        return true;
    }
    if (n == 0){
        std::cout << "error: zero position" << std::endl;
        return false;
    }
    else{
        //наверно вставка в позицию не должна быть больше чем уже существующий список
        std::cout << "error: position to big" << std::endl;
        return false;
    }
}

template <typename T>
inline bool ListCont<T>::update(T value, size_t n)
{
    if ((n <= m_size)&&(n > 0)){
        Node* temp_data = data;
        for (size_t i = m_size; i > 1; i--){
            temp_data = temp_data->prev;
        }
        for (size_t j = 1; j <= m_size; j++){
            
            if (j == n){
                temp_data->data = value;
                break;
            }
            temp_data = temp_data->next;
        }
        return true;
    }
    if (n == 0){
        std::cout << "error: zero position" << std::endl;
        return false;
    }
    else{
        //наверно вставка в позицию не должна быть больше чем уже существующий список
        std::cout << "error: position to big" << std::endl;
        return false;
    }
}

template <typename T>
inline size_t ListCont<T>::size()
{
    return m_size;
}

template <typename T>
inline T ListCont<T>::operator[](size_t n) const
{
    if ((n <= m_size)&&(n > 0)){
        Node* temp_data = data;
        for (size_t i = m_size; i > 1; i--){
            temp_data = temp_data->prev;
        }
        for (size_t j = 1; j <= m_size; j++){
            
            if (j == n){
                return temp_data->data;
                break;
            }
            temp_data = temp_data->next;
        }
    }
    return {};
}

template <typename T>
inline void ListCont<T>::printallslow()
{
    
    for (size_t i = m_size; i > 0; i--)
    {
        Node* print_data = data;
        for (size_t j = 1; j < i; j++){
            print_data = print_data->prev;
        }
        std::cout << print_data->data;
        //print_data = print_data->prev;
        if ((i) != 1){
            std::cout << ",";
        }
    }
        std::cout << std::endl;
}

template <typename T>
inline void ListCont<T>::printall()
{
    Node* print_data = data;
    for (size_t i = m_size; i > 1; i--){
        print_data = print_data->prev;
    }
    for (size_t j = 0; j < m_size; j++){
        std::cout << print_data->data;
        print_data = print_data->next;
        if ((j) != m_size - 1){
            std::cout << ",";
        }
    }
    std::cout << std::endl;
    
}
//END LIST Members