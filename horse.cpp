#include "msoftcon.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int CPF = 5;
const int maxHorses = 7;

class Track;

class Horse {
    const Track* ptrTrack;
    const int horse_number;
    float finish_time;
    float distance_run;
public:
    Horse(const int n, const Track* ptrT) : horse_number(n), ptrTrack(ptrT), distance_run(0.0) {}
    ~Horse() {}
    void display_horse(const float elapsed_time);
};

class Track {
    Horse* hArray[maxHorses];
    int total_horses;
    int horse_count;
    const float track_length;
    float elapsed_time;
public:
    Track(float lenT, int mH);
    ~Track();
    void display_track();
    void run();
    float get_track_len() const;
};

void Horse::display_horse(float elapsed_time) {
    set_cursor_pos(1 + int(distance_run * CPF), 2 + horse_number * 2);
    set_color(static_cast<color>(cBLUE + horse_number));
    char horse_char = '0' + static_cast<char>(horse_number);
    putch(' ');
    putch('\xDB');
    putch(horse_char);
    putch('\xDB');
    if(distance_run < ptrTrack->get_track_len() + 1.0 / CPF) {
        if(rand() % 3) {
            distance_run += 0.2F;
            finish_time = elapsed_time;
        }
        else {
            int mins = int(finish_time) / 60;
            int secs = int(finish_time) - mins * 60;
            cout << "Time = " << mins << ':' << secs;
        }
    }
}

Track::Track(float lenT, int nH) : track_length(lenT), total_horses(nH), horse_count(0), elapsed_time(0.0) {
    init_graphics();
    total_horses = (total_horses > maxHorses) ? maxHorses : total_horses;
    for(int i =  0; i < total_horses; i++) {
        hArray[i] = new Horse(horse_count++, this);
    }
    time_t aTime;
    srand(static_cast<unsigned>(time(&aTime)));
    display_track();
}

Track::~Track() {
    for(int i = 0; i < total_horses; i++) {
        delete hArray[i];
    }
}

void Track::display_track() {
    clear_screen();
    for(int i = 0; i <= track_length; i++) {
        for(int j = 1; j <= total_horses * 2 + 1; j++) {
            set_cursor_pos(i * CPF + 5, j);
            if(i == 0 || i == track_length) {
                cout << '\xDE';
            }
            else {
                cout << '\xB3';
            }
        }
    }
}

void Track::run() {
    while(!kbhit()) {
        elapsed_time += 1.75;
        for(int i = 0; i < total_horses; i++) {
            hArray[i]->display_horse(elapsed_time);
        }
        wait(500);
    }
    getch();
    cout << '\n';
}

float Track::get_track_len() const {
    return track_length;
}

int main() {
    float length;
    int total;

    cout << "Enter distance: ";
    cin >> length;
    cout << "Enter number of horses: ";
    cin >> total;
    Track theTrack(length, total);
    theTrack.run();

    return 0;
}