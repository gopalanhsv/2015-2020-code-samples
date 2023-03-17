#ifndef _MEETING_ROOMS_H_
#define _MEETING_ROOMS_H_

// System headers
#include <vector>

// Statics, typedefs, globals

class Meeting {
public:
    Meeting(int s, int e) : _start(s), _end(e) {}
    inline int start() const { return _start; }
    inline int end() const { return _end; }

private:
    int _start;
    int _end;
};

class MeetingRooms {
public:
    static int
    findMinimumRequired(std::vector<Meeting>& meetings);

private:
};

#endif /* _MEETING_ROOMS_H_ */
