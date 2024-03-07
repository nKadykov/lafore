#include "elev_app.h"
#include "msoftcon.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cstdlib>
#include <process.h>

enum direction {UP, DN, STOP};
const int LOAD_TIME = 3;
const int SPACING = 7;
const int BUF_LENGTH = 80;

class Building;

class Elevator {
    Building* ptrBuilding;
    const int car_number;
    int current_floor;
    int old_floor;
    direction current_dir;
    bool destination[NUM_FLOORS];
    int loading_timer;
    int unloading_timer;
public:
    Elevator(Building*, int);
    void car_tick1();
    void car_tick2();
    void car_display();
    void dests_display() const;
    void decide();
    void move();
    void get_destinations();
    int get_floor() const;
    direction get_direction() const;
};

class Building {
    Elevator* car_list[NUM_CARS];
    int num_cars;
    bool floor_request[2][NUM_FLOORS];
public:
    Building();
    ~Building();
    void master_tick();
    int get_cars_floor(const int) const;
    direction get_cars_dir(const int) const;
    bool get_floor_req(const int, const int) const;
    void set_floor_req(const int, const int, const bool);
    void record_floor_reqs();
    void show_floor_reqs() const;
};