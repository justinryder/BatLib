// BatLib_Sample.cpp : main project file.

#include <iostream>

using namespace BatLib;
using namespace System;

int main(array<System::String ^> ^args)
{
	Console::Write("Creating new batch file, Enter name: ");
	String^ fileName = Console::ReadLine();
	BL_File::CreateNew(fileName)->Close();
	Console::WriteLine(fileName + ".bat created!");

	Console::WriteLine("Edit and save " + fileName + ".bat, then press Enter");
	Console::Read();

	BL_File::Run();
	
    return 0;
}
