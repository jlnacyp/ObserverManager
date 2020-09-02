#ifndef POLLINGTHREAD_H
#define POLLINGTHREAD_H

// System headers
//
#include <functional>
#include <thread>


// Project headers
//
#include <viewerutil.hpp>
#include <iostream>
#include <unistd.h>

class PollingThread
{
public:
    PollingThread(std::function<bool(bool)> &&pollFn) : m_pollFn(std::move(pollFn))
    {
        m_thread = std::thread(&PollingThread::Run, this);
    }

    void Stop()
    {
        StopAsync();
        if (m_thread.joinable())
        {
            m_thread.join();
        }
    }

    void StopAsync()
    {
        m_shouldExit = true;
    }

    bool IsRunning() const
    {
        return m_isRunning;
    }

    ~PollingThread()
    {
        Stop();
    }

private:
    static void Run(PollingThread *instance)
    {
        instance->m_isRunning = true;
        CleanupGuard runGuard([instance]() { instance->m_isRunning = false; });
        bool firstRun = true;
        while (!instance->m_shouldExit)
        {
            usleep(8000);
            if (!instance->m_pollFn(firstRun))
            {
                instance->m_shouldExit = true;
            }
            firstRun = false;
        }
    }

    std::thread m_thread;
    volatile bool m_shouldExit = false;
    volatile bool m_isRunning = false;

    std::function<bool(bool)> m_pollFn;
};

#endif
