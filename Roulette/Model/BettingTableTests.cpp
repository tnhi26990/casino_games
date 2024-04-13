//#include <gtest/gtest.h>
//#include <string>
//#include "BettingTable.h"
//
//BettingTable* testTable = new BettingTable();
//
//TEST(evenTest, correctMod) {
//    int expectedRes;
//    for(int num = 1; num <= 36; ++num) {
//        if(num % 2 == 0) {
//            expectedRes = 0;
//        }
//        else{
//            expectedRes = 1;
//        }
//        EXPECT_EQ(testTable->isEven(num), expectedRes);
//    }
//}
//
//TEST(halfTest, correctHalf) {
//    int expectedHalf;
//    for(int num = 1; num <= 36; ++num) {
//        if(num <= 18) {
//            expectedHalf = 0;
//        }
//        else{
//            expectedHalf = 1;
//        }
//        EXPECT_EQ(testTable->firstHalf(num), expectedHalf);
//    }
//}
//
//TEST(blockTest, correctBlock) {
//    for (int num = 1; num <= 36; ++num) {
//        int expectedBlock = 0;
//        if (num <= 12) {
//            expectedBlock = 1;
//        } else if (num <= 24) {
//            expectedBlock = 2;
//        } else {
//            expectedBlock = 3;
//        }
//        EXPECT_EQ(testTable->checkBlock(num), expectedBlock);
//    }
//}
//
//TEST(rowTest, correctRow) {
//    for (int num = 1; num <= 36; ++num) {
//        int rowNum = (num % 3);
//        int expectedRow = 0;
//
//        if (rowNum > 0 && rowNum % 2 == 1) {
//            expectedRow = 2;
//        } else if (rowNum > 0 && rowNum % 2 == 0) {
//            expectedRow = 1;
//        }
//        else{
//            expectedRow = 0;
//        }
//        EXPECT_EQ(testTable->checkRow(num), expectedRow);
//    }
//}
//
//TEST(colTest, correctCol) {
//    int expectedCol;
//    for(int num = 1; num <= 36; ++num) {
//        if(num <= 3) {
//            expectedCol = 0;
//        }
//        else if(num <= 6) {
//            expectedCol = 1;
//        }
//        else if(num <= 9) {
//            expectedCol = 2;
//        }
//        else if(num <= 12) {
//            expectedCol = 3;
//        }
//        else if(num <= 15) {
//            expectedCol = 4;
//        }
//        else if(num <= 18) {
//            expectedCol = 5;
//        }
//        else if(num <= 21) {
//            expectedCol = 6;
//        }
//        else if(num <= 24) {
//            expectedCol = 7;
//        }
//        else if(num <= 27) {
//            expectedCol = 8;
//        }
//        else if(num <= 30) {
//            expectedCol = 9;
//        }
//        else if(num <= 33) {
//            expectedCol = 10;
//        }
//        else {
//            expectedCol = 11;
//        }
//
//        EXPECT_EQ(testTable->checkCol(num), expectedCol);
//    }
//}
//