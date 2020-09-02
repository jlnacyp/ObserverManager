#include <iostream>

#include <observermanager.hpp>
using namespace std;

int main()
{
    auto captureSource = std::make_shared<NonBufferingCaptureSource>();//Observer
    DataSource<int> m_cameraDataSource;
    m_cameraDataSource.RegisterObserver(captureSource);

    DataSource<int> *pCameraDataSource = &m_cameraDataSource;
    std::unique_ptr<PollingThread> m_cameraPollingThread;

    bool m_paused = false;
    bool isSubordinate = false;
    bool m_camerasStarted = false;
    bool m_camerasAbortInProgress = false;

    bool *pPaused = &m_paused;
    bool *pCamerasStarted = &m_camerasStarted;
    bool *pAbortInProgress = &m_camerasAbortInProgress;

    m_cameraPollingThread = std14::make_unique<PollingThread>([pCameraDataSource,
                                                                  pPaused, pCamerasStarted, pAbortInProgress,
                                                                  isSubordinate](bool firstRun)
    {
        std::chrono::milliseconds pollingTimeout = ObserverManager::CameraPollingTimeout;
        if (firstRun && isSubordinate) // first run
            pollingTimeout = ObserverManager::SubordinateModeStartupTimeout;

        return ObserverManager::PollSensor<int>(pCameraDataSource,
                               pPaused,
                               pCamerasStarted,
                               pAbortInProgress,
                               [](int *num, std::chrono::milliseconds timeout)
                               {
                                   std::this_thread::sleep_for(std::chrono::milliseconds(timeout));
                                   *num = rand()%11 + 1;
                                   return true;
                               },
                                []() {},
                               pollingTimeout);
    });

    int i = 0;
    while(true)
    {
        usleep(300); // < ObserverManager::CameraPollingTimeout

        if(captureSource->HasData())
        {
            std::cout << "++++++++++++++++++++++++++" << std::endl;
            const int &num = captureSource->GetLastCapture();

            std::cout<<"num="<<num<<endl;
            captureSource->ClearData();
        }

        if(i == 50000)
        {
            m_camerasStarted = true;

            ObserverManager::StopPollingThread(&m_cameraPollingThread,
                                               []() { std::cout<<"last run"<<std::endl;},
            &m_cameraDataSource,
            &m_camerasStarted,
            &m_camerasAbortInProgress);

            return 0;
        }

        i++;
    }

    return 0;
}
