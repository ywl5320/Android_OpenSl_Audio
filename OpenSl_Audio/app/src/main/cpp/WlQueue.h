//
// Created by ywl on 2017-12-3.
//

#ifndef WLPLAYER_QUEUE_H
#define WLPLAYER_QUEUE_H

#include "queue"
#include "pcmdata.h"
#include "pthread.h"

class WlQueue {

public:
    std::queue<pcmdata*> queuePacket;
    pthread_mutex_t mutexPacket;
    pthread_cond_t condPacket;

public:
    WlQueue();
    ~WlQueue();
    int putPcmdata(pcmdata *data);
    pcmdata* getPcmdata();
    int clearPcmdata();

    void release();
    int getPcmdataSize();

    int noticeThread();
};


#endif //WLPLAYER_QUEUE_H
