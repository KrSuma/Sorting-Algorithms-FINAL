#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include <algorithm>
#include <utility>
#include <iostream>
#include <string>
#include <vector>

void heapify(int arr[], int n, int i);
void heapsort(int arr[], int input);

int partition(int arr[], int low, int high);
void quicksort(int arr[], int low, int high);
void TRquicksort(int arr[], int low, int high);

void bubblesort(int arr[], int input);
void insertionsort(int arr[], int input);
void selectionsort(int arr[], int input);
//void countingsort
void shellsort(int arr[], int input);
void print(int arr[], int input);

