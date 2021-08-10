#ifndef UPGRADETHREAD_H
#define UPGRADETHREAD_H

#include <QThread>
#include "libusb.h"
#include "workspace.h"

enum REPLY
{
    REPLY_WAIT,
    REPLY_OK,
    REPLY_FAIL
};

class firmwareUpgrade;
#include "firmwareUpgrade.h"

class WinUSBDriver;
#include "winusbdriver.h"


class UpgradeThread : public QThread
{
    Q_OBJECT
private:

    enum REPLY waitReply(int wait_delay);

    FirmwareUpgrade *firmwareUpgrade;
    bool is_loop;
    QString binPath;
public:
    UpgradeThread(FirmwareUpgrade *firmwareUpgrade);
    void run();
    void waitClose();
    void setBinPath(QString binPath);
signals:
    void recvSignals(unsigned char *buffer,int len);
    // void imuSignals(int index);   
    // void closeSignals(void);   
private slots:
    //void closeSlot(void);    
};

#endif // USBTHREAD_H