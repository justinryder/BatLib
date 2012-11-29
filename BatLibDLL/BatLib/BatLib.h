// BatLib.h

#pragma once

using namespace System;

namespace BatLib
{
	public ref class BL_File
	{
	public:
		static IO::StreamWriter^ CreateNew();
		static IO::StreamWriter^ CreateNew(String^ name);
		static IO::StreamWriter^ CreateNew(String^ name, String^ path);

		static bool Run();
		static bool Run(String^ name);
		static bool Run(String^ name, String^ path);
	};
}
