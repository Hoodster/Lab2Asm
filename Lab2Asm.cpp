// Lab2Asm.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <windows.h>
#include "Solution.h"


int main()
{
	typedef int(_stdcall* addInt)(int, int);
	typedef int(_stdcall* subInt)(int, int);
	typedef int(_stdcall* mulInt)(int, int);
	typedef int(_stdcall* divInt)(int, int);
	typedef float(_stdcall* addFloat)(float, float);
	typedef float(_stdcall* subFloat)(float, float);
	typedef float(_stdcall* mulFloat)(float, float);
	typedef float(_stdcall* divFloat)(float, float);

	HINSTANCE dllHandle = LoadLibrary(TEXT("Lab2Assembly.dll"));
	addInt _addInt = (addInt)GetProcAddress(dllHandle, "addInt");
	subInt _subInt = (subInt)GetProcAddress(dllHandle, "subInt");
	mulInt _mulInt = (mulInt)GetProcAddress(dllHandle, "mulInt");
	divInt _divInt = (divInt)GetProcAddress(dllHandle, "divInt");
	addFloat _addFloat = (addFloat)GetProcAddress(dllHandle, "addFloat");
	subFloat _subFloat = (subFloat)GetProcAddress(dllHandle, "subFloat");
	mulFloat _mulFloat = (mulFloat)GetProcAddress(dllHandle, "mulFloat");
	divFloat _divFloat = (divFloat)GetProcAddress(dllHandle, "divFloat");

	std::cout << "(INT) 3 + 2 = " << _addInt(3, 2) << std::endl;
	std::cout << "(INT) 3 - 2 = " << _subInt(3, 2) << std::endl;
	std::cout << "(INT) 3 * 2 = " << _mulInt(3, 2) << std::endl;
	std::cout << "(INT) 3 / 2 = " << _divInt(3, 2) << std::endl;

	std::cout << "(FLOAT) 3.3 + 2.2 = " << _addFloat(3.3f, 2.2f) << std::endl;
	std::cout << "(FLOAT) 3.3 - 2.2 = " << _subFloat(3.3f, 2.2f) << std::endl;
	std::cout << "(FLOAT) 3.3 * 2.2 = " << _mulFloat(3.3f, 2.2f) << std::endl;
	std::cout << "(FLOAT) 3.3 / 2.2 = " << _divFloat(3.3f, 2.2f) << std::endl;

	std::getchar();
}
