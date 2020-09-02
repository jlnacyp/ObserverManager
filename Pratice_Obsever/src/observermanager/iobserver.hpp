#ifndef IOBSERVER_H
#define IOBSERVER_H

// System headers
//
#include <memory>

template<typename NotificationType> class IObserver
{
public:
    virtual void NotifyData(const NotificationType &data) = 0;
    virtual void NotifyTermination() = 0;
    virtual void ClearData() = 0;

    virtual ~IObserver() = default;

    IObserver() = default;
    IObserver(const IObserver &) = delete;
    IObserver(const IObserver &&) = delete;
    IObserver &operator=(const IObserver &) = delete;
    IObserver &operator=(const IObserver &&) = delete;
};

using ICaptureObserver = IObserver<int>;

#endif
