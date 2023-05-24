// Header Files
#include "Utility.h"

// Set Handle
HWND Utility::windowHandle = nullptr;

void Utility::SetWindowHandle(HWND windowHandle)
{
	windowHandle = windowHandle;
}

void Utility::RemoveCharacter(std::string& string, char character)
{
	auto it = std::find(string.begin(), string.end(), character);

	if (it != string.end())
	{
		do
		{
			string.erase(it);
			it = std::find(string.begin(), string.end(), character);
		} while (it != string.end());
	}
}

void Utility::Log(Destination destination, float value, const std::string& label)
{
	if (!label.empty())
	{
		if (destination == Destination::WindowsMessageBox)
		{
			MessageBox(windowHandle,
				reinterpret_cast<LPCWSTR>(std::to_string(value).c_str()),
				reinterpret_cast<LPCWSTR>(label.c_str()),
				MB_ICONINFORMATION | MB_OK);
		}

		else if (destination == Destination::OutputWindow)
		{
			std::string message = "[" + label + "] " + std::to_string(value) + "\n";
			OutputDebugString(reinterpret_cast<LPCWSTR>(message.c_str()));
		}

		else if (destination == Destination::LogFile)
		{
			std::fstream file("Data/Output.log", std::ios_base::out | std::ios_base::app);
			std::string message = "[" + label + "] " + std::to_string(value) + "\n";
			file << message;
			file.close();
		}
	}
}

void Utility::Log(Destination destination, const std::string& message, Severity severity)
{
	if (!message.empty())
	{
		if (destination == Destination::WindowsMessageBox)
		{
			MessageBoxA(windowHandle, message.c_str(), "Log", static_cast<int>(severity) | MB_OK);
		}

		else if (destination == Destination::OutputWindow)
		{
			std::string finalMessage;

			if (severity == Severity::Failure)
			{
				finalMessage = "[FAILURE] " + message + "\n";
			}

			else if (severity == Severity::Warning)
			{
				finalMessage = "[WARNING] " + message + "\n";
			}

			else
			{
				finalMessage = message + "\n";
			}

			OutputDebugString(reinterpret_cast<LPCWSTR>(finalMessage.c_str()));
		}

		else if (destination == Destination::LogFile)
		{
			std::string finalMessage;
			std::fstream file("Data/Output.log", std::ios_base::out | std::ios_base::app);

			if (severity == Severity::Failure)
			{
				finalMessage = "[FAILURE] " + message + "\n";
			}

			else if (severity == Severity::Warning)
			{
				finalMessage = "[WARNING] " + message + "\n";
			}

			else
			{
				finalMessage = message + "\n";
			}

			file << finalMessage;
			file.close();
		}
	}
}

void Utility::Log(Destination destination, float x, float y, const std::string& label)
{
	if (!label.empty())
	{
		if (destination == Destination::WindowsMessageBox)
		{
			std::string message = "x = " + std::to_string(x) +
				", y = " + std::to_string(y);

			MessageBox(windowHandle,
				reinterpret_cast<LPCWSTR>(message.c_str()),
				reinterpret_cast<LPCWSTR>(message.c_str()),
				MB_ICONINFORMATION | MB_OK);
		}

		else if (destination == Destination::OutputWindow)
		{
			std::string message = "[" + label + "] " + "x = " + std::to_string(x) +
				", y = " + std::to_string(y) + "\n";
			OutputDebugString(reinterpret_cast<LPCWSTR>(message.c_str()));
		}

		else if (destination == Destination::LogFile)
		{
			std::fstream file("Data/Output.log", std::ios_base::out | std::ios_base::app);
			std::string message = "[" + label + "] " + "x = " + std::to_string(x) +
				", y = " + std::to_string(y) + "\n";
			file << message;
			file.close();
		}
	}
}