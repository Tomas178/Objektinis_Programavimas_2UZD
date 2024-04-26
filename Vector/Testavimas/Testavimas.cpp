#include "../Headers/funkcijos.h"
#include <gtest/gtest.h>

int programos_veikimas;

TEST(Studento_Testavimas, Studento_Default_Konstruktorius) {
    Studentas studentas;
    EXPECT_EQ(studentas.Get_Vardas(), "");
    EXPECT_EQ(studentas.Get_Pavarde(), "");
    EXPECT_EQ(studentas.Nd_empty(), true);
    EXPECT_EQ(studentas.Nd_dydis(), 0);
    EXPECT_EQ(studentas.Get_Egzaminas(), 0);
    EXPECT_EQ(studentas.Get_Vidurkis(), 0.0);
    EXPECT_EQ(studentas.Get_Mediana(), 0.0);

}

TEST(Studento_Testavimas, Studento_Parametirinis_Konstruktorius) {
    Studentas studentas("Tomas", "Petronis");
    EXPECT_EQ(studentas.Get_Vardas(), "Tomas");
    EXPECT_EQ(studentas.Get_Pavarde(), "Petronis");
    EXPECT_EQ(studentas.Nd_empty(), true);
    EXPECT_EQ(studentas.Nd_dydis(), 0);
    EXPECT_EQ(studentas.Get_Egzaminas(), 0);
    EXPECT_EQ(studentas.Get_Vidurkis(), 0.0);
    EXPECT_EQ(studentas.Get_Mediana(), 0.0);
}

TEST(Studento_Testavimas, Studento_Move_konstruktorius) {
    Studentas studentas("Tomas", "Petronis");
    studentas.SetMediana(8.0);
    Studentas studentas2(std::move(studentas));
    EXPECT_EQ(studentas.Get_Vardas(), "");
    EXPECT_EQ(studentas.Get_Pavarde(), "");
    EXPECT_EQ(studentas.Get_Mediana(), 0.0);
    EXPECT_EQ(studentas2.Get_Vardas(), "Tomas");
    EXPECT_EQ(studentas2.Get_Pavarde(), "Petronis");
    EXPECT_EQ(studentas2.Get_Mediana(), 8.0);
}

TEST(Studento_Testavimas, Studento_Copy_konstruktorius) {
    Studentas studentas("Tomas", "Petronis");
    studentas.SetMediana(8.0);
    Studentas studentas2(studentas);
    EXPECT_EQ(studentas.Get_Vardas(), "Tomas");
    EXPECT_EQ(studentas.Get_Pavarde(), "Petronis");
    EXPECT_EQ(studentas.Get_Mediana(), 8.0);
    EXPECT_EQ(studentas2.Get_Vardas(), "Tomas");
    EXPECT_EQ(studentas2.Get_Pavarde(), "Petronis");
    EXPECT_EQ(studentas2.Get_Mediana(), 8.0);
}

TEST(Studento_Testavimas, Studento_kopijavimo_operatorius) {
    Studentas studentas("Tomas", "Petronis");
    studentas.SetMediana(8.0);
    Studentas studentas2 = studentas;
    EXPECT_EQ(studentas.Get_Vardas(), "Tomas");
    EXPECT_EQ(studentas.Get_Pavarde(), "Petronis");
    EXPECT_EQ(studentas.Get_Mediana(), 8.0);
    EXPECT_EQ(studentas2.Get_Vardas(), "Tomas");
    EXPECT_EQ(studentas2.Get_Pavarde(), "Petronis");
    EXPECT_EQ(studentas2.Get_Mediana(), 8.0);
}

TEST(Studento_Testavimas, Studento_move_operatorius) {
    Studentas studentas("Tomas", "Petronis");
    studentas.SetMediana(8.0);
    Studentas studentas2 = std::move(studentas);
    EXPECT_EQ(studentas.Get_Vardas(), "");
    EXPECT_EQ(studentas.Get_Pavarde(), "");
    EXPECT_EQ(studentas.Get_Mediana(), 0.0);
    EXPECT_EQ(studentas2.Get_Vardas(), "Tomas");
    EXPECT_EQ(studentas2.Get_Pavarde(), "Petronis");
    EXPECT_EQ(studentas2.Get_Mediana(), 8.0);
}

TEST(Studento_Testavimas, Studento_Seteriai_ir_Geteriai) {
    Studentas studentas;
    studentas.SetVardas("Tomas");
    EXPECT_EQ(studentas.Get_Vardas(), "Tomas");
    studentas.SetPavarde("Petronis");
    EXPECT_EQ(studentas.Get_Pavarde(), "Petronis");
    studentas.setNd(10);
    studentas.setNd(5);
    EXPECT_EQ(studentas.Nd_empty(), false);
    EXPECT_EQ(studentas.Nd_dydis(), 2);
    EXPECT_EQ(studentas.Get_Last_Nd(), 5);
    studentas.setEgzaminas(10);
    EXPECT_EQ(studentas.Get_Egzaminas(), 10);
    studentas.setVidurkis(7.5);
    EXPECT_EQ(studentas.Get_Vidurkis(), 7.5);
    studentas.SetMediana(8.0);
    EXPECT_EQ(studentas.Get_Mediana(), 8.0);
    studentas.DeleteLastNd();
    EXPECT_EQ(studentas.Nd_empty(), false);
    EXPECT_EQ(studentas.Nd_dydis(), 1);
    EXPECT_EQ(studentas.Get_Last_Nd(), 10);
}

int main(int argc, char** argv) {
    // Initialize Google Test framework
    ::testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}
