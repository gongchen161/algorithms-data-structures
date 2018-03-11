#ifndef SYNCHRONIZINGQUEUE_HPP
#define SYNCHRONIZINGQUEUE_HPP

#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <atomic>

template<typename T>
class SynchronizingQueue
{
private:
	std::queue<T> m_queue;
	std::mutex m_mutex;
	std::condition_variable m_cv;
	int m_max;
	std::atomic<bool> m_closed;
public:

    void Enqueue(const T& item) {
        std::unique_lock<std::mutex> lock(m_mutex);
        
        if (m_queue.size() == m_max) {
            std::cout << "Queue full " << data << " left\n";
            return;
        }
        m_queue.emplace(data);
        m_cv.notify_one();
    }
    
    T Dequeue() {
        
        std::unique_lock<std::mutex> lock(m_mutex);
        if (m_queue.size() == 0) {
            //m_cv.wait_for(lock, std::chrono::milliseconds(1000));	//end if 1 sec passed to prevent deadlock!
            m_cv.wait(lock, [&]() { return m_closed.load(); });
        }
        if (m_queue.size() == 0)
            return T();
        
        T temp = m_queue.front();
        m_queue.pop();
        
        return temp;
        
    }

    void setMax(int i) {
        m_max = i;
    }
    
    void close() {
        {
            std::unique_lock<std::mutex> lock(m_mutex);
            m_closed.store(true);
        }
        m_cv.notify_all();
    }
    
    void open() {
        m_closed.store(false);
    }
    
    bool closed() {
        return m_closed.load();
    }
    
    std::size_t size() {
        return m_queue.size();
    }
};

#endif;
