#ifndef DATASOURCE_H
#define DATASOURCE_H

// System headers
//

// Library headers
//
#include <list>
#include <mutex>

// Project headers
//
#include <iobserver.hpp>

template<typename T> class DataSource
{
public:
    DataSource() = default;

    ~DataSource()
    {
        NotifyTermination();
    }

    DataSource(DataSource &) = delete;
    DataSource(DataSource &&) = delete;
    DataSource &operator=(DataSource &) = delete;
    DataSource &operator=(DataSource &&) = delete;

    void RegisterObserver(std::shared_ptr<IObserver<T>> &&observer)
    {
        std::lock_guard<std::mutex> lock(m_mutex);

        if (m_primed)
        {
            observer->NotifyData(m_mostRecentData);
        }
        m_observers.emplace_back(std::move(observer));
    }

    void NotifyObservers(const T &data)
    {
        std::lock_guard<std::mutex> lock(m_mutex);

        m_mostRecentData = data;
        m_primed = true;
        for (auto wpObserver = m_observers.begin(); wpObserver != m_observers.end();)
        {
            auto spObserver = wpObserver->lock();
            if (spObserver)
            {
                spObserver->NotifyData(data);
                ++wpObserver;
            }
            else
            {
                auto toDelete = wpObserver;
                ++wpObserver;
                m_observers.erase(toDelete);
            }
        }
    }

    void NotifyTermination()
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_primed = false;
        m_mostRecentData = T();
        for (const auto &wpObserver : m_observers)
        {
            if (auto spObserver = wpObserver.lock())
            {
                spObserver->NotifyTermination();
            }
        }

        m_observers.clear();
    }

    void ClearData()
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_primed = false;
        m_mostRecentData = T();
        for (auto wpObserver = m_observers.begin(); wpObserver != m_observers.end();)
        {
            auto spObserver = wpObserver->lock();
            if (spObserver)
            {
                spObserver->ClearData();
                ++wpObserver;
            }
            else
            {
                auto toDelete = wpObserver;
                ++wpObserver;
                m_observers.erase(toDelete);
            }
        }
    }

private:
    std::list<std::weak_ptr<IObserver<T>>> m_observers;

    bool m_primed = false;
    T m_mostRecentData;

    std::mutex m_mutex;
};

#endif
