#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>
#include <limits>
#include <algorithm> // for std::swap

template <typename T>
class Vector {
    private:
        unsigned int dydis;
        unsigned int talpa;
        T* duomenys;
    public:
        //Member funkcijos
        int max_size() const { return std::numeric_limits<unsigned int>::max() / sizeof(T); }
        Vector() : dydis(0), talpa(1), duomenys(new T[talpa]) {}
        ~Vector() { delete[] duomenys; }
        Vector& operator=(const Vector& Kitas_Vektorius) {
            if (this == &Kitas_Vektorius) return *this;
            delete[] duomenys;
            dydis = Kitas_Vektorius.dydis;
            talpa = Kitas_Vektorius.talpa;
            duomenys = new T[talpa];
            for (unsigned int i = 0; i < dydis; i++) {
                duomenys[i] = Kitas_Vektorius.duomenys[i];
            }
            return *this;
        }
        
        //Element access funkcijos
        T& operator[](unsigned int indeksas) {return duomenys[indeksas];}
        const T& operator[](unsigned int indeksas) const {return duomenys[indeksas];}
        T& at(unsigned int indeksas) {
            if (indeksas >= dydis) {
                throw std::out_of_range("Indeksas už ribų");
            }
            return duomenys[indeksas];
        }
        const T& at(unsigned int indeksas) const {
            if (indeksas >= dydis) {
                throw std::out_of_range("Indeksas už ribų");
            }
            return duomenys[indeksas];
        }
        T& front() {return duomenys[0];}
        const T& front() const {return duomenys[0];}
        T& back() {return duomenys[dydis - 1];}
        const T& back() const {return duomenys[dydis - 1];}
        T* data() noexcept {return duomenys;}

        //Iterators funkcijos
        T* begin() noexcept {return duomenys;}
        const T* begin() const noexcept {return duomenys;}
        T* end() noexcept {return duomenys + dydis;}
        const T* end() const noexcept {return duomenys + dydis;}

        //Capacity funkcijos
        unsigned int capacity() const {return talpa;}
        unsigned int size() const {return dydis;}
        bool empty() const {return dydis == 0;}
        void reserve(unsigned int nauja_talpa) {
            if (nauja_talpa <= talpa) return;
            if(nauja_talpa > max_size()) throw std::length_error("Vector::reserve");
            T* nauji_duomenys = new T[nauja_talpa];
            for (unsigned int i = 0; i < dydis; i++) {
                nauji_duomenys[i] = duomenys[i];
            }
            delete[] duomenys;
            duomenys = nauji_duomenys;
            talpa = nauja_talpa;
        }
        void shrink_to_fit() {
            if (dydis == talpa) return;
            T* nauji_duomenys = new T[dydis];
            for (unsigned int i = 0; i < dydis; i++) {
                nauji_duomenys[i] = duomenys[i];
            }
            delete[] duomenys;
            duomenys = nauji_duomenys;
            talpa = dydis;
        }
        void assign(unsigned int n, const T& value) {
            if (n > talpa) reserve(n);
            for (unsigned int i = 0; i < n; i++) {
                duomenys[i] = value;
            }
            dydis = n;
        }

        //Modifiers funkcijos
        void clear() {dydis = 0;}
        void push_back(const T& value) {
            if (dydis == talpa) reserve(talpa == 0 ? 1 : talpa * 2);
            duomenys[dydis++] = value;
        }
        void insert(unsigned int indeksas, const T& value) {
            if (dydis == talpa) reserve(talpa == 0 ? 1 : talpa * 2);
            for (unsigned int i = dydis; i > indeksas; i--) {
                duomenys[i] = duomenys[i - 1];
            }
            duomenys[indeksas] = value;
            dydis++;
        }
        void insert_range(unsigned int indeksas, unsigned int n, const T& value) {
            if (dydis + n > talpa) reserve(dydis + n);
            for (unsigned int i = dydis + n - 1; i > indeksas + n - 1; i--) {
                duomenys[i] = duomenys[i - n];
            }
            for (unsigned int i = indeksas; i < indeksas + n; i++) {
                duomenys[i] = value;
            }
            dydis += n;
        }
        void emplace(unsigned int indeksas, T&& value) {
            if (dydis == talpa) reserve(talpa == 0 ? 1 : talpa * 2);
            for (unsigned int i = dydis; i > indeksas; i--) {
                duomenys[i] = duomenys[i - 1];
            }
            duomenys[indeksas] = std::move(value);
            dydis++;
        }
        void emplace_back(T&& value) {
            if (dydis == talpa) reserve(talpa * 2);
            duomenys[dydis++] = std::move(value);
        }
        void pop_back() {
            if (dydis > 0) {
                --dydis;
            }
        }
        void resize(unsigned int naujas_dydis) {
            if (naujas_dydis > talpa) reserve(naujas_dydis);
            for (unsigned int i = dydis; i < naujas_dydis; i++) {
                duomenys[i] = T();
            }
            dydis = naujas_dydis;
        }
        void swap(Vector& other) {
            std::swap(dydis, other.dydis);
            std::swap(talpa, other.talpa);
            std::swap(duomenys, other.duomenys);
        }
};

#endif