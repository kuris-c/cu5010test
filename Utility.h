// Header Guard
#pragma once

// C++ Libraries
#include <assert.h>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <Windows.h>

class Utility
{
public:
	// Enum Classes
	enum class Severity
	{
		Failure = MB_ICONERROR,
		Warning = MB_ICONWARNING,
		Default = MB_ICONINFORMATION
	};
	enum class Destination
	{
		LogFile,
		OutputWindow,
		WindowsMessageBox
	};

	// Set Handle
	static void SetWindowHandle(HWND windowHandle);

	// String Control
	static void RemoveCharacter(std::string& string, char character);
	static void ParseString(std::string string, std::vector<std::string, std::string>& subStrings, char token);

	// Log Errors
	static void Log(Destination destination, float value, const std::string& label = "");
	static void Log(Destination destination, const std::string& message, Severity severity = Severity::Default);
	static void Log(Destination destination, float x, float y, const std::string& label = "");

private:
	static HWND windowHandle;
};