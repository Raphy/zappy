
#include <stdexcept>
#include "SafeQueue.hh"
#include "Mutex.hh"
#include "CondVar.hh"
#include "ScopedLock.hh"
#include "Worker.hh"

template <typename T>
SafeQueue<T>::SafeQueue()
: _finished(false)
{
    _mutex = new Mutex();
    _cond = new CondVar();
}
template <typename T>
SafeQueue<T>::~SafeQueue()
{
    while (!_queue.empty())
	_queue.pop();
    delete _mutex;
    delete _cond;
}

template <typename T>
void SafeQueue<T>::push(const T& value)
{
    ScopedLock lock(_mutex);
    _cond->broadcast();//signal ?
    _queue.push(value);
}
template <typename T>
bool SafeQueue<T>::tryPop(T& value)
{
    ScopedLock lock(_mutex);
    if (_queue.empty()) return (false);
    value = _queue.front();
    _queue.pop();
    return (true);
}
template <typename T>
T	SafeQueue<T>::pop(void)
{
    ScopedLock lock(_mutex);
    
    if (_finished && _queue.empty())
	throw std::runtime_error("Pop on empty queue");
    if (_queue.empty())
	_cond->wait();
    T value = _queue.front();
    _queue.pop();
    return (value);
}
template <typename T>
bool SafeQueue<T>::isFinished(void)
{
    ScopedLock lock(_mutex);
    return (_finished && _queue.empty());
}
template <typename T>
bool SafeQueue<T>::isEmpty(void)
{
    ScopedLock lock(_mutex);
    return (_queue.empty());
}
template <typename T>
void SafeQueue<T>::setFinished(void)
{
    ScopedLock lock(_mutex);//?
    _finished = true;
}

template<typename T>
const T&	SafeQueue<T>::front(void) const
{
    ScopedLock	lock(this->_mutex);
    
    return this->_queue.front();
}

template<typename T>
const T&	SafeQueue<T>::back(void) const
{
    ScopedLock	lock(this->_mutex);
    
    return this->_queue.back();
}

template<typename T>
T&	SafeQueue<T>::front(void)
{
    ScopedLock	lock(this->_mutex);
    
    return this->_queue.front();
}

template<typename T>
T&	SafeQueue<T>::back(void)
{
    ScopedLock	lock(this->_mutex);
    
    return this->_queue.back();
}

template class	SafeQueue<t_data *>;
