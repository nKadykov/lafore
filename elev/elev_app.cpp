#include "elev.h"

int main() {
    Building theBuilding;
    while(true) {
        theBuilding.master_tick();
        wait(1000);
        theBuilding.record_floor_reqs();
    }
    return 0;
}