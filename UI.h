#pragma once
#include "Service.h"

class UI
{
private:
    Service service;
    void menu();
    void add();
    void add_current();
    void show();
    void show_pos();
    void update_description();
    void del_type();
    void del_day();
    void del_interval();
    void del_pos();
    void sold();
    void sum();
    void show_type();
    void show_maxim_sum();
    void show_equal_sum();
    void filtrer_type();
    void filtrer_type_sum();
    void valoros();
    void update_sum();


public:
    UI();
    UI(Service& service);
    void run();
};