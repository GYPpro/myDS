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

    template <typename TYPE_NAME>
    class vector
    {
    private:
        std::size_t _size = 0;
        std::size_t _max_cap = 1;
        TYPE_NAME *_begin = new TYPE_NAME[1];
        std::size_t _push_back_idx = 0;

        class _iterator
        {
        private:
            TYPE_NAME *_ptr;
            myDS::vector<TYPE_NAME> * _upper_pointer;
            size_t _upper_idx;

        public:
            enum __iter_dest_type
            {
                front,
                back
            };
            __iter_dest_type _iter_dest;
            
            _iterator(myDS::vector<TYPE_NAME> *_upper, size_t _n, __iter_dest_type _d)
            {
                _upper_idx = _n;
                _upper_pointer = _upper;
                _ptr = &(*_upper_pointer)[_n];        
                _iter_dest = _d;      
            }

            TYPE_NAME & operator*()
            {
                return (*_ptr);
            }

            TYPE_NAME *operator->()
            {
                return _ptr;
            }

            myDS::vector<TYPE_NAME>::_iterator operator++()
            {
                if (_iter_dest == front)
                    _upper_idx++;
                else
                    _upper_idx--;
                _ptr = &((*_upper_pointer)[_upper_idx]);
                return *this;
            }

            myDS::vector<TYPE_NAME>::_iterator operator+(size_t _n)
            {
                //_upper_idx += _n;
                if (_iter_dest == front)
                    _upper_idx += _n;
                else
                    _upper_idx -= _n;
                _ptr = &((*_upper_pointer)[_upper_idx]);
                return *this;
            }

            bool operator==(myDS::vector<TYPE_NAME>::_iterator _b)
            {
                if (&(*_b) == _ptr)
                    return 1;
                else
                    return 0;
            }

            bool operator!=(myDS::vector<TYPE_NAME>::_iterator _b)
            {
                if (&(*_b) == _ptr)
                    return 0;
                else
                    return 1;
            }
        };

    private:
        void _expension()
        {
            if (_size == 0)
            {
                _begin = new TYPE_NAME[_INITIAL_SIZE];
            }
            else
            {
                TYPE_NAME *_next_begin = new TYPE_NAME[_EXPENSION_RATIO * (std::size_t)_max_cap];
		_max_cap *= _EXPENSION_RATIO;
		for (std::size_t i = 0; i < _size; i++)
                    _next_begin[i] = _begin[i];
                delete[] _begin;
                _begin = _next_begin;
            }
        }

    public:
        vector() {}

        vector(std::size_t _n) //
        {
            _begin = new TYPE_NAME[_n];
            _size = _n;
            _max_cap = _n;
            _push_back_idx = _n;
        }

        vector(std::size_t _n, const TYPE_NAME &_init_value)
        {
            _begin = new TYPE_NAME[_n];
            _size = _n;
            _max_cap = _n;
            _push_back_idx = _n;
            for (std::size_t i = 0; i < _push_back_idx; i++)
                _begin[i] = _init_value;
        }

        vector(myDS::vector<TYPE_NAME> &_b)
        {
            for (auto x : _b)
                this->push_back(x);
        }

        void resize(size_t _n)
        {
	    if(_n > _size)
		for(int __i = 0;__i < _n;__i++)
		{
		    if(_push_back_idx >= _max_cap)
			_expension();
		    TYPE_NAME __tmp;
		    _begin[_push_back_idx] = __tmp;
		    _size ++;
		    _push_back_idx ++;
		}
	    _size = _n;
	    _push_back_idx = _n;
        }

        void push_back(const TYPE_NAME &_n)
        {
            if (_push_back_idx >= _max_cap)
                _expension();
            _begin[_push_back_idx] = _n;
            _push_back_idx++;
            _size++;
        }

        vector<TYPE_NAME>::_iterator begin()
        {
            enum myDS::vector<TYPE_NAME>::_iterator::__iter_dest_type s = myDS::vector<TYPE_NAME>::_iterator::__iter_dest_type::front;
            return myDS::vector<TYPE_NAME>::_iterator(this, 0,s);
        }

        myDS::vector<TYPE_NAME>::_iterator rbegin()
        {
            enum myDS::vector<TYPE_NAME>::_iterator::__iter_dest_type s = myDS::vector<TYPE_NAME>::_iterator::__iter_dest_type::back;
            return myDS::vector<TYPE_NAME>::_iterator(this, _size - 1,s);
        }

        myDS::vector<TYPE_NAME>::_iterator end()
        {
            enum myDS::vector<TYPE_NAME>::_iterator::__iter_dest_type s = myDS::vector<TYPE_NAME>::_iterator::__iter_dest_type::front;
            return myDS::vector<TYPE_NAME>::_iterator(this, _push_back_idx,s);
        }

        myDS::vector<TYPE_NAME>::_iterator rend()
        {
            enum myDS::vector<TYPE_NAME>::_iterator::__iter_dest_type s = myDS::vector<TYPE_NAME>::_iterator::__iter_dest_type::back;
            return myDS::vector<TYPE_NAME>::_iterator(this, 0, s);
        }

        TYPE_NAME at(std::size_t _n)
        {
            return _begin[_n];
        }

        std::size_t size()
        {
            return _size;
        }

        bool equal(myDS::vector<TYPE_NAME> _b)
        {
            for (int i = 0; i < _size; i++)
                if (_b[i] != _begin[i])
                    return false;
            return true;
        }

        TYPE_NAME &operator[](std::size_t _n)
        {
            return _begin[_n];
        }

        myDS::vector<TYPE_NAME> &operator=(myDS::vector<TYPE_NAME> _b)
        {
            this = new myDS::vector<TYPE_NAME>(_b);
        }

        myDS::vector<TYPE_NAME> &operator+(myDS::vector<TYPE_NAME> _b)
        {
            for (auto x : _b)
                this->push_back(x);
        }

        ~vector()
        {
            delete[] _begin;
        }
    };
} // namespace myDS

// #define std::vector myDS::vector
// #define vector myDS::vector

#endif
