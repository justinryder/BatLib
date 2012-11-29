// This is the main DLL file.

#include "BatLib.h"

#include <process.h>
#include <string>

using namespace std;
using Runtime::InteropServices::Marshal;

namespace BatLib
{
	IO::StreamWriter^ BL_File::CreateNew()
	{
		return CreateNew("NewBatchFile");
	}

	IO::StreamWriter^ BL_File::CreateNew(String^ name)
	{
		return name == "" ? CreateNew() : CreateNew(name, "");
	}

	IO::StreamWriter^ BL_File::CreateNew(String^ name, String^ path)
	{
		return IO::File::CreateText(path + name + ".bat");
	}


	bool BL_File::Run()
	{
		return Run("NewBatchFile");
	}

	bool BL_File::Run(String^ name)
	{
		return Run(name, "");
	}

	bool BL_File::Run(String^ name, String^ path)
	{
		char* args[4];

		args[0] = (char*)(const char*)(Marshal::StringToHGlobalAnsi(path + name + ".bat")).ToPointer();
		args[1] = "arg1";
		args[2] = "arg2";
		args[3] = NULL;

		puts("Spawning child with spawnv");
  
		spawnv( P_WAIT, (char*)(const char*)(Marshal::StringToHGlobalAnsi(path + name + ".bat")).ToPointer(), args);

		return true;
	}
}