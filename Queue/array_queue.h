#ifndef QUEUE_H_
#define QUEUE_H_
#include<iostream>
#include<vector>

template<class T> 
class ArrayQueue
{
  public:
    ArrayQueue();
    T pop();
    void push(const T& value);
    T front() const;
    T back() const;

    int count() const;
    bool is_empty() const;

    void clear();

    template<class U>
    friend std::ostream& operator<<(std::ostream& stream, const ArrayQueue<U>& other);

  private:
    std::vector<T> queue_;
    int count_;
    int front_;
    int back_;

    void resize();

};

template<class T>
ArrayQueue<T>::ArrayQueue() : queue_(10), front_(0), back_(-1), count_(0)
{

}

template<class T>
T ArrayQueue<T>::pop()
{
  if(is_empty())
  {
    throw std::runtime_error("Queue is empty");
  }
  else
  {
    T temp = queue_[front_];
    front_ = (front_ + 1) % queue_.size();
    count_--;
    return temp;
  }
}

template<class T>
void ArrayQueue<T>::push(const T& value)
{
  if(count_ == queue_.size())
  {
    resize();
  }
  back_ = (back_ + 1) % queue_.size();
  queue_[back_] = value;
  count_++;
}

template<class T>
T ArrayQueue<T>::front() const
{
  if(is_empty())
  {
    throw std::runtime_error("Queue is empty");
  }
    return queue_[front_];
}

template<class T>
T ArrayQueue<T>::back() const
{
  if(is_empty())
  {
    throw std::runtime_error("Queue is emtpy");
  }
  return queue_[back_];
}

template<class T>
int ArrayQueue<T>::count() const
{
  return count_;
}

template<class T>
bool ArrayQueue<T>::is_empty() const
{
  if(count_ <= 0)
  {
    return true;
  }
  else
  {
    return false;
  }

}

template<class T>
void ArrayQueue<T>::clear()
{
  while(count_ != 0)
  {
    pop();
  }
}


template<class T>
std::ostream& operator<<(std::ostream& stream, const ArrayQueue<T>& other)
{
  for(int i = other.front_; i < other.back_ + 1; i++)
  {
    stream << other.queue_[i];
  }
  return stream;
}

template<class T>
void ArrayQueue<T>::resize()
{
  int old_size = queue_.size();
  int new_size = old_size * 2;
  
  T* temp = new T[old_size];

  for(int i = 0; i < old_size; i++)
  {
    *(temp + i) = pop();
  }

  clear();
  queue_.resize(new_size);

  for(int i = 0; i < old_size; i++)
  {
    push(*(temp + i));
  }

  delete[] temp;
  temp = nullptr;
}

#endif