#include <gtest/gtest.h>
#include <string>
#include "../Roulette/Model/BettingTable.h"
#include "../Roulette/Model/RouletteWheel.h"

RouletteWheel *testWheel = new RouletteWheel();
BettingTable* testTable = new BettingTable(*testWheel);

TEST(numPayoutTest, correctVal) {
    std::string input = "1";
    int betVal = 10;
    EXPECT_EQ(testTable->frontendPayout(input, betVal), 360);
}

TEST(numPayoutTest2, correctVal) {
    std::string input = "2";
    int betVal = 10;
    EXPECT_EQ(testTable->frontendPayout(input, betVal), 360);
}

TEST(numPayoutTest3, correctVal) {
    std::string input = "15";
    int betVal = 10;
    EXPECT_EQ(testTable->frontendPayout(input, betVal), 360);
}

TEST(numPayoutTest4, correctVal) {
    std::string input = "14";
    int betVal = 10;
    EXPECT_EQ(testTable->frontendPayout(input, betVal), 360);
}

TEST(oddPayout, correctVal) {
    std::string input = "Odd";
    int betVal = 10;
    EXPECT_EQ(testTable->frontendPayout(input, betVal), 20);
}

TEST(evenPayout, correctVal) {
    std::string input = "Even";
    int betVal = 10;
    EXPECT_EQ(testTable->frontendPayout(input, betVal), 20);
}

TEST(blackPayout, correctVal) {
    std::string input = "Black";
    int betVal = 10;
    EXPECT_EQ(testTable->frontendPayout(input, betVal), 20);
}

TEST(redPayout, correctVal) {
    std::string input = "Red";
    int betVal = 10;
    EXPECT_EQ(testTable->frontendPayout(input, betVal), 20);
}

TEST(elseCasePayout, correctVal) {
    std::string input = "2:1:1";
    int betVal = 10;
    EXPECT_EQ(testTable->frontendPayout(input, betVal), 30);
}

TEST(elseCasePayout2, correctVal) {
    std::string input = "1 to 18";
    int betVal = 10;
    EXPECT_EQ(testTable->frontendPayout(input, betVal), 20);
}
