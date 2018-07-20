//
// Created by ywl on 2017-12-3.
//

#include "WlQueue.h"

WlQueue::WlQueue() {
    pthread_mutex_init(&mutexPacket, NULL);
    pthread_cond_init(&condPacket, NULL);
}

WlQueue::~WlQueue() {
    pthread_mutex_destroy(&mutexPacket);
    pthread_cond_destroy(&condPacket);
}

void WlQueue::release() {
    noticeThread();
    clearPcmdata();
}

int WlQueue::putPcmdata(pcmdata *data){

    pthread_mutex_lock(&mutexPacket);
    queuePacket.push(data);
    pthread_cond_signal(&condPacket);
    pthread_mutex_unlock(&mutexPacket);

    return 0;
}

pcmdata* WlQueue::getPcmdata(){

    pthread_mutex_lock(&mutexPacket);
    pcmdata *pkt = NULL;
    if(queuePacket.size() > 0)
    {
        pkt = queuePacket.front();
        queuePacket.pop();
    } else{
        pthread_cond_wait(&condPacket, &mutexPacket);
    }
    pthread_mutex_unlock(&mutexPacket);
    return pkt;
}

int WlQueue::clearPcmdata() {

    pthread_cond_signal(&condPacket);
    pthread_mutex_lock(&mutexPacket);
    while (!queuePacket.empty())
    {
        pcmdata *pkt = queuePacket.front();
        queuePacket.pop();
        free(pkt->getData());
        pkt = NULL;
    }
    pthread_mutex_unlock(&mutexPacket);
    return 0;
}

int WlQueue::getPcmdataSize() {
    int size = 0;
    pthread_mutex_lock(&mutexPacket);
    size = queuePacket.size();
    pthread_mutex_unlock(&mutexPacket);
    return size;
}

int WlQueue::noticeThread() {
    pthread_cond_signal(&condPacket);
    return 0;
}

