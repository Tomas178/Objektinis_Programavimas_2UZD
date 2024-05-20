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

TEST(Vektoriaus_Capacity_Funkciju_Testavimas, Shrink_to_fit_Funkcija) {
    Vector<int> v;
    v.reserve(10);
    v.push_back(1);
    v.push_back(2);
    v.shrink_to_fit();
    EXPECT_EQ(v.capacity(), 2);
}

TEST(Vektoriaus_Capacity_Funkciju_Testavimas, Assign_Funkcija) {
    Vector<int> v;
    v.assign(10, 5);
    EXPECT_EQ(v.size(), 10);
    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(v[i], 5);
    }
}

TEST(Vektoriaus_Modifiers_Funkciju_Testavimas, Clear_Funkcija) {
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    EXPECT_EQ(v.size(), 2);
    v.clear();
    EXPECT_EQ(v.size(), 0);
}

TEST(Vektoriaus_Modifiers_Funkciju_Testavimas, Push_Back_Funkcija) {
    Vector<int> v;
    v.push_back(1);
    EXPECT_EQ(v.size(), 1);
    EXPECT_EQ(v.capacity(), 1);
    EXPECT_EQ(v[0], 1);
    v.push_back(2);
    EXPECT_EQ(v.size(), 2);
    EXPECT_EQ(v.capacity(), 2);
    EXPECT_EQ(v[1], 2);
    v.push_back(3);
    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v.capacity(), 4);
    EXPECT_EQ(v[2], 3);
}

TEST(Vektoriaus_Modifiers_Funkciju_Testavimas, Emplace_Back_Funkcija) {
    Vector<int> v;
    v.emplace_back(1);
    EXPECT_EQ(v.size(), 1);
    EXPECT_EQ(v.capacity(), 1);
    EXPECT_EQ(v[0], 1);
    v.emplace_back(2);
    EXPECT_EQ(v.size(), 2);
    EXPECT_EQ(v.capacity(), 2);
    EXPECT_EQ(v[1], 2);
    v.emplace_back(3);
    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v.capacity(), 4);
    EXPECT_EQ(v[2], 3);
}

TEST(Vektoriaus_Modifiers_Funkciju_Testavimas, Pop_Back_Funkcija) {
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    EXPECT_EQ(v.size(), 3);
    v.pop_back();
    EXPECT_EQ(v.size(), 2);
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
    EXPECT_THROW(v.at(2), std::out_of_range);
}

TEST(Vektoriaus_Modifiers_Funkciju_Testavimas, Resize_Funkcija) {
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    EXPECT_EQ(v.size(), 2);
    v.resize(4);
    EXPECT_EQ(v.size(), 4);
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
    EXPECT_EQ(v[2], 0);
    EXPECT_EQ(v[3], 0);
}

TEST(Vektoriaus_Modifiers_Funkciju_Testavimas, Swap_Funkcija) {
    Vector<int> v1;
    v1.reserve(10);
    v1.push_back(1);
    v1.push_back(2);
    Vector<int> v2;
    v2.push_back(3);
    v2.push_back(4);
    v1.swap(v2);
    EXPECT_EQ(v1.size(), 2);
    EXPECT_EQ(v1.capacity(), 2);
    EXPECT_EQ(v2.size(), 2);
    EXPECT_EQ(v2.capacity(), 10);
    EXPECT_EQ(v1[0], 3);
    EXPECT_EQ(v1[1], 4);
    EXPECT_EQ(v2[0], 1);
    EXPECT_EQ(v2[1], 2);
}


int main(int argc, char** argv) {
    // Initialize Google Test framework
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}