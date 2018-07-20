//
// Created by hlwky001 on 2018/7/20.
//

#ifndef OPENSL_AUDIO_PCMDATA_H
#define OPENSL_AUDIO_PCMDATA_H


class pcmdata {

public:
    char *data;
    int size;

public:
    pcmdata(char* data, int size);
    ~pcmdata();

    int getSize();

    char* getData();


};


#endif //OPENSL_AUDIO_PCMDATA_H
