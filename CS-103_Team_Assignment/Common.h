#pragma once

#ifndef _COMMON
#define _COMMON

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>

constexpr auto PROMPT = " > ";

constexpr auto RESET = "\x1b[39;40m";
constexpr auto RED = "\x1b[91;40m";
constexpr auto GREEN = "\x1b[92;40m";
constexpr auto BLUE = "\x1b[94;40m";
constexpr auto CYAN = "\x1b[96;40m";


void clear() {
    COORD topLeft = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}


namespace trim {
	/*
	 *
	 *   Borrowed from the internet
	 *
	 *   I hope this doesn't count as academic dishonesty as long
	 *   as I state the source:
	 *   https://stackoverflow.com/questions/216823/how-to-trim-an-stdstring
	 *
	 */

	 // trim from start (in place)
	static inline void l(std::string& s) {
		s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {return !std::isspace(ch); }));
	}

	// trim from end (in place)
	static inline void r(std::string& s) {
		s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {return !std::isspace(ch); }).base(), s.end());
	}

	// trim from both ends (in place)
	static inline void trim(std::string& s) {
		l(s); r(s);
	}
}

namespace utils {
	// this allows it to take different kinds of numbers
	//
	// including floats
	template<typename T>
	static inline T get_number(std::string query) {
		std::cout << BLUE << query << RESET << std::endl << PROMPT;
		T a{};

		std::cin.clear();
		std::cin >> a;

		return a;
	}

	// this is formatted weirdly because we need to handle blank line entering.
	//
	// this is significant for having default options for instances of [y/N] 
	// (where N is default) or [Y/n] (where Y is default).
	//
	// this concept of defaults is a convention of questioning in the linux community 
	// that many people are used to in TUIs.
	static inline char get_char(std::string prompt) {
		std::cout << BLUE << prompt << RESET << std::endl << PROMPT;
		std::string a{};

		std::cin.clear();
		std::getline(std::cin, a);

		if (a == "") return '\0';
		else return a[0];
	}

	static inline std::string get_word(std::string prompt) {
		std::cout << BLUE << prompt << RESET << std::endl << PROMPT;
		std::string a{};

		std::cin.clear();
		std::cin >> a;
		std::cin.clear();

		return a;
	}

	static inline std::string get_line(std::string prompt) {
		std::cout << BLUE << prompt << RESET << std::endl << PROMPT;
		std::string a{};

		std::cin.clear();
		std::getline(std::cin, a);
		std::cin.clear();

		return a;
	}

	static inline std::string paragraph(std::string prompt) {
		std::cout
			<< BLUE << prompt << RESET
			<< "[" << CYAN << "press Enter twice to finish" << RESET << "]"
			<< std::endl;

		std::string a{}, separator{}, last_input{};

		do {
			std::getline(std::cin, last_input);
			trim::trim(last_input);

			a.append(separator);
			separator = " ";
			a.append(last_input);
		} while (last_input != "");

		std::cout << "\033[Fend of paragraph" << RESET << std::endl;

		return a;
	}

	//
	// works by using ESC[2J to clear the terminal screen (typically works on windows)
	// then using ESC[1;1H to set the cursor to the top left, where we want it
	//
	static inline void clear_terminal() {
		std::cout << "\033[2J\033[1;1H";
	}

	// if a character is a lower case ascii letter
	static inline bool is_lower(char& c) {
		return c >= 'a' && c <= 'z';
	}

	// if a character is an upper case ascii letter
	static inline bool is_upper(char& c) {
		return c >= 'A' && c <= 'Z';
	}

	static inline void to_lower(char& c) {
		if (is_upper(c)) c += 32;
	}

	static inline void to_upper(char& c) {
		if (is_lower(c)) c -= 32;
	}

	static inline int gen_random_int(int min = 0, int max = INT32_MAX) {
		return (rand() % max) + min;
	}

	// src: https://stackoverflow.com/questions/236129/how-do-i-iterate-over-the-words-of-a-string
	static inline void split(const std::string& s, char delim, std::vector<std::string>* result) {
		std::istringstream iss(s);
		std::string item;
		while (std::getline(iss, item, delim)) {
			result->push_back(item);
		}
	}
}

#endif