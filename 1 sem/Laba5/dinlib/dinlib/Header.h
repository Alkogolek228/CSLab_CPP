#pragma once

#ifdef DINLIB_EXPORTS
#define DINLIB_API __declspec(dllexport)
#else
#define DINLIB_API __declspec(dllimport)
#endif

extern "C" DINLIB_API void Reference2();

extern "C" DINLIB_API double* Create_din_array(int size);

extern "C" DINLIB_API void Print_din_array(double mas[], int size);

extern "C" DINLIB_API double Rec(double* arr, int first, int last);

extern "C" DINLIB_API int NonStop();

extern "C"  DINLIB_API int Enter();



