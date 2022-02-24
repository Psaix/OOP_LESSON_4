#pragma once
#ifndef ARRAYINT_H
#define ARRAYINT_H
#include <iostream>
#include <algorithm>
#include <cassert> 



//____________________________________________________________________________________________________________
//____________________________________________TASK1___________________________________________________________
//____________________________________________________________________________________________________________


class ArrayInt
{
private:
    int m_length;
    int* m_data;

public:
    ArrayInt() : m_length(0), m_data(nullptr) {}

    ArrayInt(int length) : m_length(length)
    {
        assert(length >= 0);

        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }

    void erase()
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    int getLength() { return m_length; }

    void resize(int newLength)
    {
        if (newLength == m_length)
            return;

        if (newLength <= 0)
        {
            erase();
            return;
        }

        int* data = new int[newLength];


        if (m_length > 0)
        {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;

            for (int index = 0; index < elementsToCopy; ++index)
                data[index] = m_data[index];
        }

        delete[] m_data;

        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index)
    {
        assert(index >= 0 && index <= m_length);

        int* data = new int[m_length + 1];

        for (int before = 0; before < index; ++before)
            data[before] = m_data[before];

        data[index] = value;

        for (int after = index; after < m_length; ++after)
            data[after + 1] = m_data[after];

        delete[] m_data;
        m_data = data;
        ++m_length;
    }

//_____________ EXTRACT LAST ELEMENT _________________
//_____________________ METHOD _______________________


    void extractLast()
    {
        if (m_length <= 0)
        {
            erase();
            return;
        }

        int* data = new int[m_length - 1];
        for (size_t index = 0; index < m_length - 1; index++)
            data[index] = m_data[index];

        delete[] m_data;
        m_data = data;
        --m_length;
    }


//_____________ EXTRACT FIRST ELEMENT ________________
//_____________________ METHOD _______________________


    void extractFirst()
    {
        if (m_length <= 0)
        {
            erase();
            return;
        }

        int* data = new int[m_length - 1];
        for (size_t index = 0; index < m_length - 1; index++)
            data[index] = m_data[index + 1];

        delete[] m_data;
        m_data = data;
        --m_length;
    }


//_____________ SORT ________________
//_____________ METHOD ______________


    void sort()
    {
        int temp;

        for (size_t i = 0; i < m_length - 1; i++)
        {
            for (size_t j = 0; j < m_length - 1; j++)
            {
                if (m_data[j] > m_data[j + 1])
                {
                    temp = m_data[j];
                    m_data[j] = m_data[j + 1];
                    m_data[j + 1] = temp;
                    temp = 0;
                }
            }
        }
    }


//_____________ PRINT ________________
//_____________ METHOD _______________


    void print()
    {
        for (size_t index = 0; index < m_length; index++)
        {
            std::cout << m_data[index] << " ";
        }
        std::cout << std::endl;
    }

    ~ArrayInt()
    {
        delete[] m_data;
    }
};

#endif