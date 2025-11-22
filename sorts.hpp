#ifndef SORTS_HPP
#define SORTS_HPP

#include <vector>
#include <iostream>

void printArray(const std::vector<int>& arr);
void swap(int& a, int& b);

void bubbleSort(std::vector<int>& arr);
void selectionSort(std::vector<int>& arr);
void insertionSort(std::vector<int>& arr);

void mergeSort(std::vector<int>& arr);
void heapSort(std::vector<int>& arr);
void quickSort(std::vector<int>& arr);

#endif // SORTS_HPP
