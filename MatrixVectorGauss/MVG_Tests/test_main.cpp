#include <algorithm>
#include <Matrix.h>
#include <Vector.h>
#include <gtest.h>

int main(int argc, char** argv) 
{
    setlocale(LC_ALL, "Russian");
    matrix M(5);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}
