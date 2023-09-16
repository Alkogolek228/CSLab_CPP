#pragma once


extern "C" __declspec(dllexport) void Reference2();

extern "C" __declspec(dllexport) double* Create_din_array(int size);

extern "C" __declspec(dllexport) void Print_din_array(double mas[], int size);

extern "C" __declspec(dllexport) double Rec(double* arr, int first, int last);

extern "C" __declspec(dllexport) int NonStop();

extern "C" __declspec(dllexport) int Enter();
