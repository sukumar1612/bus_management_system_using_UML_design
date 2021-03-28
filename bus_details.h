#ifndef bus_h
#define bus_h
#include "food.h"
#include "route.h"

class timings{
            public:
                int hours;
                int minutes;
                char am_pm[50];
                int date;
                int month;
                int year;
                void get_data();
                void display();
                void display_time();
                void display_date();
            };
class bus{
        public:
            timings t;
            route r;
            food f;
            char model[20];
            int price;
            int number_of_seats_left;
            void get_data();
            void display();
            int search_data();
};
#endif // bus
