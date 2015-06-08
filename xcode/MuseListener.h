//
//  MuseListener.h
//  MuseSample
//
//  Created by Brian George on 6/8/15.
//
//

#ifndef MuseSample_MuseListener_h
#define MuseSample_MuseListener_h

#include "OscListener.h"
#include <queue>

class MuseListener {
public:
    MuseListener();
    void listen();
    bool hasNextMessage();
    std::vector<float> getNextMessage();

    ci::osc::Listener               mListener;
    float                           mPosition;
    std::queue<std::vector<float>>   mMessages;
};

#endif
