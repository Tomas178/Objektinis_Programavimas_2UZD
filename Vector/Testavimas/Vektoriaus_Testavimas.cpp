#include "../Headers/Vector.h"
#include <gtest/gtest.h>

TEST(Vektoriaus_Member_Funkciju_Testavimas, konstruktorius) {
    Vector<int> v;
    EXPECT_EQ(v.size(), 0);
    EXPECT_EQ(v.capacity(), 1);
    EXPECT_EQ(v.empty(), true);
}

TEST(Vektoriaus_Member_Funkciju_Testavimas, Operatoriaus_Lygu){
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    Vector<int> v2;
    v2 = v;
    EXPECT_EQ(v2.size(), 2);
    EXPECT_EQ(v2.capacity(), 2);
    EXPECT_EQ(v2.empty(), false);
    EXPECT_EQ(v2[0], 1);
    EXPECT_EQ(v2[1], 2);
}

TEST(Vektoriaus_Element_Access_Funkciju_Testavimas, Operatorius_Kvadratiniu_Sklaustu){
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
}

TEST(Vektoriaus_Element_Access_Funkciju_Testavimas, At_Funkcija){
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    EXPECT_EQ(v.at(0), 1);
    EXPECT_EQ(v.at(1), 2);
    EXPECT_THROW(v.at(2), std::out_of_range);
}

TEST(Vektoriaus_Element_Access_Funkciju_Testavimas, Front_Funkcija){
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    EXPECT_EQ(v.front(), 1);
}

TEST(Vektoriaus_Element_Access_Funkciju_Testavimas, Back_Funkcija){
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    EXPECT_EQ(v.back(), 2);
}

TEST(Vektoriaus_Element_Access_Funkciju_Testavimas, Data_Funkcija){
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    EXPECT_EQ(v.data()[0], 1);
    EXPECT_EQ(v.data()[1], 2);
}

TEST(Vektoriaus_Iterator_Funkciju_Testavimas, Begin_Funkcija){
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    EXPECT_EQ(*v.begin(), 1);
}

TEST(Vektoriaus_Iterator_Funkciju_Testavimas, End_Funkcija){
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    EXPECT_EQ(*(v.end() - 1), 2);
}

TEST(Vektoriaus_Capacity_Funkciju_Testavimas, Capacity_Funkcija){
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    EXPECT_EQ(v.capacity(), 2);
}

TEST(Vektoriaus_Capacity_Funkciju_Testavimas, Size_Funkcija) {
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    EXPECT_EQ(v.size(), 2);
    v.push_back(3);
    EXPECT_EQ(v.size(), 3);
}

TEST(Vektoriaus_Capacity_Funkciju_Testavimas, Empty_Funkcija) {
    Vector<int> v;
    EXPECT_EQ(v.empty(), true);
    v.push_back(1);
    EXPECT_EQ(v.empty(), false);
}

TEST(Vektoriaus_Capacity_Funkciju_Testavimas, Reserve_Funkcija) {
    Vector<int> v;
    EXPECT_EQ(v.capacity(), 1);
    v.reserve(10);
    EXPECT_EQ(v.capacity(), 10);
}


int main(int argc, char** argv) {
    // Initialize Google Test framework
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}