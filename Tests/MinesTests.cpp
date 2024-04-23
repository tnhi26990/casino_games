#include <gtest/gtest.h>
#include "../Mines/Model/MinesModel.h"
#include "../Mines/View/MinesView.h"  // Ensure you include the View if it's used in the Model constructor

// Mock View class to pass to MinesModel
class MockMinesView : public MinesView {
public:
    void showGrid(int[5][5]) override {}
};

// Fixture for MinesModel tests
class MinesModelTest : public ::testing::Test {
protected:
    MinesModel* model;

    void SetUp() override {
        // Setup with 5 mines
        model = new MinesModel(5);
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

TEST_F(MinesModelTest, MultiplierTest){
    model->flipSquare(0,0);
    model->flipSquare(1,0);

    float mul = model->returnMultiplier();
    ASSERT_EQ(mul, 1.2);

}

TEST_F(MinesModelTest, resetMultiplier){
    model->flipSquare(0,0);
    model->flipSquare(1,0);

    model->reset();

    float mul = model->returnMultiplier();
    ASSERT_EQ(mul, 1);
}

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