//
//  MuseListener.cpp
//  MuseSample
//
//  Created by Brian George on 6/8/15.
//
//

#include "MuseListener.h"

MuseListener::MuseListener()
{
    mListener.setup( 5000 );
    mPosition = 0.0f;
}

void MuseListener::listen()
{
    while ( mListener.hasWaitingMessages() ) {
        
        ci::osc::Message message;
        mListener.getNextMessage( &message );
        int numArgs = message.getNumArgs();
        if( message.getAddress() == "/muse/eeg" && numArgs == 4 )
        {

            std::vector<float> params;
            for(int i = 0; i < numArgs; i++)
            {

                params.push_back(message.getArgAsFloat(i));

            }
            mMessages.push(params);

        }

    }
}

bool MuseListener::hasNextMessage()
{
    return !mMessages.empty();
}

std::vector<float> MuseListener::getNextMessage()
{
    std::vector<float> message = mMessages.front();
    mMessages.pop();
    return message;
}