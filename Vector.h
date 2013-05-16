#ifndef VECTOR_H
#define VECTOR_H

using namespace std;

    template <typename T>
    my::vector<T>::vector() :size(0), capacity(1) {			//кидает 1 в случае ошибки
    try {
        p_vector = static_cast <T*> (::operator new (sizeof(T) * capacity));
            new(p_vector)T();
    } catch(std::bad_alloc &ex) {
        std::cerr<<"Ошибка при выделении памяти"<<std::endl;
        throw (ex);
    }
    }

    template <typename T>
    int my::vector<T>::remove_top(){
        if (size > 0){
            p_vector[size-1].~T();
            --size;
            return 0;
        } else{
        return 1;
        }
    }

    template <typename T>
    my::vector<T>::vector (int _capacity): size(0), capacity(_capacity) {
        p_vector = static_cast <T*> (::operator new (sizeof(T) * _capacity));;
        for (int i = 0; i < _capacity; ++i) {
            new (p_vector + i) T();
        }
    }

    template <typename T>
    my::vector<T>::vector (my::vector<T> const &a) : size(a.size), capacity(a.capacity) {
        p_vector = static_cast <T*> (::operator new (sizeof(T) * capacity));
        for (int i = 0; i < a.size; ++i) {
            new (p_vector + i) T(a.p_vector[i]);
        }
    }

    template <typename T>
    my::vector<T>::~vector(){
        for (int i = 0; i < this->size; ++i){
            p_vector[i].~T();
        }
        delete[] (p_vector);
    }
    template <typename T>
    int my::vector<T>::push_back (T const & new_){ //0 -успешное завершение, 1- неуспешное
        if (size == capacity) {
            T* placementMemory;
            try{
                placementMemory = static_cast <T*> (::operator new (sizeof(T) * capacity * 2));
            } catch (std::bad_alloc& ba) {
                 std::cerr << "bad_alloc caught: " << ba.what() << '\n';
                 throw(ba);
            }
            for (int i = 0; i < capacity; ++i) {
                 new (placementMemory+i) T(p_vector[i]) ;
                 p_vector[i].~T();
            }
            delete[] (p_vector);
            p_vector = placementMemory;
            capacity *= 2;
        }
        new (p_vector + size) T(new_) ;
        ++size;
        return 0;
    }


    template <typename T>
    int my::vector<T>::put_on_bot (T const & new_){
        int _size =  this->size_of_vector() + 1;
        my::vector<T> buf(_size);
        buf.push_back(new_);
        for (int i = 1; i < _size; ++i) {
           buf.push_back(this->operator[](i-1));
        }
        *this = buf;
        return 0;
    }


    template <typename T>
    int my::vector<T>::size_of_vector() const{
        return size;
    }

    template <typename T>
    void my::vector<T>::output () const
    {
        for (int i=0; i < size; ++i) {
            std::cout<<p_vector[i]<<" ";
        }
        std::cout<<std::endl;
        return;
    }

    template <typename T>
    T& my::vector<T>::operator [] (int pos)  {
        if (pos >= size) {
            std::cerr<<"Не существует элемента с указанным номером!!!"<<pos<<std::endl;//Кидает строчку ,bad_index
            throw ("bad_index");
        }
        return p_vector[pos];
    }

    template <typename T>
    const T& my::vector<T>::operator [] (int pos) const {
        if (pos >= size) {
            std::cerr<<"Не существует элемента с указанным номером!!!"<<std::endl;//Кидает строчку ,bad_index
            throw ("bad_index");
        }
        return p_vector[pos];
    }

    template <typename T>
    my::vector<T>& my::vector<T>::operator = (const my::vector<T> & a) {
        size=a.size;
        capacity=a.capacity;
        delete[](p_vector);
        p_vector = static_cast <T*> (::operator new (sizeof(T) * capacity));
        for (int i = 0; i < a.size; ++i) {
            new (p_vector + i) T(a.p_vector[i]);
        }
        return *this;
    }

    template <typename T>
    bool my::vector<T>::operator == (my::vector<T> const&a) const{
        if (a.size == this -> size) {
            int i = 0;
            while (i < a.size) {
                if (a.p_vector [i] != this -> p_vector[i]) {
                    return false;
                }
                ++i;
            }
            return true;
        } else {
            return false;
        }
    }

    template <typename T>
    bool my::vector<T>::operator != (my::vector<T> const& a) const {
        return (!(*this == a));
    }


#endif // VECTOR_H

