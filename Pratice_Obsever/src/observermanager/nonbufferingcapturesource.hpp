#ifndef NONBUFFERINGCAPTURESOURCE_H
#define NONBUFFERINGCAPTURESOURCE_H

// System headers
//
#include <array>
#include <memory>
#include <mutex>

// Project headers
//
#include <iobserver.hpp>

class NonBufferingCaptureSource : public ICaptureObserver
{
public:
    inline int GetLastCapture()
    {
        std::lock_guard<std::mutex> lock(m_mutex);

        return m_lastCapture;
    }

    bool IsFailed() const
    {
        return m_failed;
    }

    bool HasData() const
    {
        return m_lastCapture > 0;
    }

    void NotifyData(const int &num) override
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_lastCapture = num;
    }

    void ClearData() override
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_lastCapture = 0;
    }

    void NotifyTermination() override
    {
        m_failed = true;
    }

    ~NonBufferingCaptureSource() override = default;

    NonBufferingCaptureSource() = default;
    NonBufferingCaptureSource(NonBufferingCaptureSource &) = delete;
    NonBufferingCaptureSource(NonBufferingCaptureSource &&) = delete;
    NonBufferingCaptureSource &operator=(NonBufferingCaptureSource &) = delete;
    NonBufferingCaptureSource &operator=(NonBufferingCaptureSource &&) = delete;

private:
    int m_lastCapture;
    
    bool m_failed = false;

    std::mutex m_mutex;
};

#endif
