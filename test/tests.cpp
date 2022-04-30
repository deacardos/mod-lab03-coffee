// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "kofe.h"

TEST(task1, test1) {
    kofe machine = kofe();
    machine.on();
    States result = machine.getState();
    EXPECT_EQ(WAIT, result);
}

TEST(task2, test2) {
    kofe machine = kofe();
    machine.on();
    machine.coin(20);
    States result = machine.getState();
    EXPECT_EQ(ACCEPT, result);
}

TEST(task3, test3) {
    kofe machine = kofe();
    machine.on();
    machine.coin(50);
    machine.choice(1);
    States result = machine.getState();
    EXPECT_EQ(CHECK, result);
}

TEST(task4, test4) {
    kofe machine = kofe();
    machine.on();
    machine.coin(50);
    machine.choice(1);
    machine.cook();
    States result = machine.getState();
    EXPECT_EQ(COOK, result);
}

TEST(task5, test5) {
    kofe machine = kofe();
    machine.on();
    machine.coin(50);
    machine.choice(1);
    machine.cook();
    machine.finish();
    States result = machine.getState();
    EXPECT_EQ(WAIT, result);
}

TEST(task6, test6) {
    kofe machine = kofe();
    machine.on();
    machine.coin(50);
    machine.choice(1);
    machine.cook();
    machine.finish();
    machine.off();
    States result = machine.getState();
    EXPECT_EQ(OFF, result);
}
