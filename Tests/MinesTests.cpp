#include <gtest/gtest.h>
#include "../Mines/Model/MinesModel.h"

// Fixture for MinesModel tests
class MinesModelTest : public ::testing::Test {
protected:
    MinesModel* model;

    void SetUp() override {
        // Setup 
        model = new MinesModel();
        
        // Predefine bombGrid
        // Alternatively, access model's internal bombGrid directly if accessible
        int presetBombGrid[5][5] = {
            {1, 0, 0, 0, 0},
            {0, 1, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 1, 0},
            {0, 0, 0, 0, 1}
        };
        memcpy(model->bombGrid, presetBombGrid, sizeof(presetBombGrid)); // Assuming bombGrid is accessible
    }

    void TearDown() override {
        delete model;
    }
};

TEST_F(MinesModelTest, CheckBombTrue) {
    // Check that bombs are where you expect
    EXPECT_TRUE(model->checkForBomb(0, 0));
}

TEST_F(MinesModelTest, NoBombTest) {
    // Check that bombs are not in this spot
    EXPECT_FALSE(model->checkForBomb(0, 1));
}

TEST_F(MinesModelTest, MultiplierTest3){
    model->setTotalMines(3);
    model->flipSquare(0,1);
    model->flipSquare(0,2);

    double mul = model->returnMultiplier();
    ASSERT_EQ(mul, 1.02);

}

TEST_F(MinesModelTest, MultiplierTest5){
    model->reset();
    model->setTotalMines(5);
    model->flipSquare(0,1);
    model->flipSquare(0,2);
    model->flipSquare(0,2);
    model->flipSquare(0,3);

    double mul = model->returnMultiplier();
    ASSERT_EQ(mul, 1.32);

}

TEST_F(MinesModelTest, MultiplierTest10){
    model->reset();
    model->setTotalMines(10);
    model->flipSquare(0,1);
    model->flipSquare(0,2);

    double mul = model->returnMultiplier();
    ASSERT_EQ(mul, 1.36);

}

TEST_F(MinesModelTest, MultiplierTest15){
    model->reset();
    model->setTotalMines(15);
    model->flipSquare(0,1);
    model->flipSquare(0,2);

    double mul = model->returnMultiplier();
    ASSERT_EQ(mul, 1.6);

}

TEST_F(MinesModelTest, MultiplierTest24){
    model->reset();
    model->setTotalMines(24);
    model->flipSquare(0,1);

    double mul = model->returnMultiplier();
    ASSERT_EQ(mul, 10.1);

}

TEST_F(MinesModelTest, resetMultiplier){
    model->flipSquare(0,0);
    model->flipSquare(1,0);

    model->reset();

    float mul = model->returnMultiplier();
    ASSERT_EQ(mul, 1);
}

// Test to ensure correct number of bombs are placed on grid
TEST_F(MinesModelTest, numBombsOnGrid){
    int totalBombs = 0;
    for (int i=0; i<5; i++) {
        for (int j = 0; j < 5; j++) {
            if (model->bombGrid[i][j] == 1){
                totalBombs += 1;
            }
        }
    }

    ASSERT_EQ(totalBombs, 5);
}