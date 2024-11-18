#ifndef WATCHY_MOLIZABETH_H
#define WATCHY_MOLIZABETH_H

#ifdef WATCHY_SIM
#include "..\..\Watchy.h"
#else // WATCHY_SIM
#include <Watchy.h>
#endif // WATCHY_SIM

#define INDEX_SIZE 5

class WatchyMolizabeth : public Watchy{
    public:
        using Watchy::Watchy;

        void drawWatchFace();

        void drawBack(const int& film_index);
        void drawOneMember(const int& target, const int& film_index);

        void drawSeg(const int& num, int index_x, int index_y);
        void drawMic();
        void drawQoo();
};

#endif