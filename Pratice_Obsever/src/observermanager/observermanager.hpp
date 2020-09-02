#pragma once

#ifndef OBSERVERMANAGER_H
#define OBSERVERMANAGER_H

#include <datasource.hpp>
#include <nonbufferingcapturesource.hpp>
#include <pollingthread.hpp>
#include <iostream>

class ObserverManager {
public:
    template<typename T> static void StopSensor(std::function<void()> stopFn,
                                                DataSource<T> *dataSource,
                                                bool *started)
    {
        if (*started)
        {
            stopFn();
        }
        dataSource->NotifyTermination();
        *started = false;
    }

    template<typename T> static bool PollSensor(DataSource<T> *dataSource,
                    bool *paused,
                    bool *started,
                    bool *abortInProgress,
                    std::function<bool( T *, std::chrono::milliseconds)> pollFn,
                    std::function<void()> stopFn,
                    std::chrono::milliseconds timeout)
    {
        std::string errorMessage;

        try
        {
            T data;
            const bool succeeded = pollFn(&data, timeout);
            if (succeeded)
            {
                if (!*paused)
                {
                    dataSource->NotifyObservers(data);
                }
                return true;
            }

            errorMessage = "timed out!";
        }
        catch (...)
        {
            std::cout<<errorMessage<<std::endl;
        }

        StopSensor(stopFn, dataSource, started);

        if (!*abortInProgress)
        {
            std::cout << " failed: " << errorMessage<<std::endl;
        }

        return false;
    }

    template<typename T> static void StopPollingThread(std::unique_ptr<PollingThread> *pollingThread,
                           std::function<void()> stopFn,
                           DataSource<T> *dataSource,
                           bool *started,
                           bool *abortInProgress)
    {
        *abortInProgress = true;
        if (*pollingThread)
        {
            (*pollingThread)->StopAsync();

            // Attempt graceful shutdown of the polling thread to reduce noise.
            // If this doesn't work out, we'll stop the device manually, which will
            // make the polling thread's blocking call to get the next data sample abort.
            //
            auto startTime = std::chrono::high_resolution_clock::now();
            while (*started)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                auto now = std::chrono::high_resolution_clock::now();
                if (now - startTime > PollingThreadCleanShutdownTimeout)
                {
                    break;
                }
            }
        }

        StopSensor(stopFn, dataSource, started);
        pollingThread->reset();
        *abortInProgress = false;
    }

    static constexpr std::chrono::milliseconds CameraPollingTimeout= std::chrono::milliseconds(3000);
    static constexpr std::chrono::minutes SubordinateModeStartupTimeout= std::chrono::minutes(5);
    static constexpr std::chrono::milliseconds PollingThreadCleanShutdownTimeout = std::chrono::milliseconds(1000 / 5);
};

#endif
