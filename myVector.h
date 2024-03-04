/**
 * @file myVector.h
 * @brief A Memory-contiguous, variable-length array 
 * @details 
 * 不知道该写什么，反正就是vector，正常用就行了
 * @author github.com/GYPpro
 * @version 0.0.1
 */


#ifndef PRVLIBCPP_VECTOR_HPP
#define PRVLIBCPP_VECTOR_HPP

#include <cstddef>
namespace myDS
{

    const size_t _EXPENSION_RATIO = 2;
    const size_t _INITIAL_SIZE = 16;

    template<typename TYPE_NAME>
    class vector{
    private:
        std::size_t _size = 0;
        std::size_t _max_cap = 0;
        TYPE_NAME *_begin = nullptr;
        std::size_t _push_back_idx = 0;

        class _iterator{
        private:
            TYPE_NAME *_ptr;
            myDS::vector<TYPE_NAME> * _super_pointer;

        public:

            _iterator(myDS::vector<TYPE_NAME> *)

            TYPE_NAME & operator*()
            {

            }

            TYPE_NAME * operator->()
            {

            }

            TYPE_NAME operator++()
            {

            }
            
            TYPE_NAME operator+()
            {

            }

        };

    private:

        void _expension()
        {
            if(_size == 0){
                _begin = new TYPE_NAME[_INITIAL_SIZE];
            } else {
                TYPE_NAME * _next_begin = new TYPE_NAME [_EXPENSION_RATIO*(std::size_t)_max_cap];
                for(std::size_t i = 0;i < _size;i ++)
                    _next_begin[i] = _begin[i];
                delete [] _begin;
                _begin = _next_begin;
            }
        }
    
    public:
        vector() {  }

        vector(std::size_t _n)//
        {
            _begin = new TYPE_NAME[_n];
            _size = _n;
            _max_cap = _n;
            _push_back_idx = _n;
        }

        vector(std::size_t _n,const TYPE_NAME & _init_value)
        {
            _begin = new TYPE_NAME[_n];
            _size = _n;
            _max_cap = _n;
            _push_back_idx = _n;
            for(std::size_t i = 0;i < _push_back_idx;i ++)
                _begin[i] = _init_value;
        }

        vector(myDS::vector<TYPE_NAME> & _b)
        {
            for(auto x:_b) this->push_back(x);
        }

        void resize(size_t _n)
        {
            _size = _n;
        }

        void push_back(const TYPE_NAME & _n)
        {
            if(_push_back_idx >= _max_cap)
                _expension();
            _begin[_push_back_idx] = _n;
            _push_back_idx ++;
            _size ++;
        }

        vector<TYPE_NAME>::_iterator begin()
        {

        }

        myDS::vector<TYPE_NAME>::_iterator rbegin()
        {

        }

        myDS::vector<TYPE_NAME>::_iterator end()
        {

        }

        myDS::vector<TYPE_NAME>::_iterator rend()
        {

        }

        TYPE_NAME at(std::size_t _n)
        {

        }

        std::size_t size()
        {

        }

        bool equal(myDS::vector<TYPE_NAME> _b)
        {

        }

        TYPE_NAME & operator[](std::size_t _n)
        {

        }

        myDS::vector<TYPE_NAME> & operator= (myDS::vector<TYPE_NAME> _b)
        {

        }

        myDS::vector<TYPE_NAME> & operator+ (myDS::vector<TYPE_NAME> _b)
        {
            
        }
    
    };
} // namespace myDS

// #define std::vector myDS::vector
// #define vector myDS::vector

#endif