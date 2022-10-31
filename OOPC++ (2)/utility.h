#pragma once
#include <windows.h>
#include <vector>
#include <string>

#define NO_WCHAR__

#ifdef WCHAR__
#define STRING std::wstring
#define COUT std::wcout
#define CHAR_T wchar_t
#define CP CP_UTF8
#else
#define STRING std::string
#define COUT std::cout
#define CHAR_T char
#define CP 866
#endif

enum ConsoleCodes {
	none,
	quit,
	pause,
	mouseClick,
};

std::string consoleCodeToString(const ConsoleCodes&);

typedef struct PlAction_S{

	ConsoleCodes code;
	COORD mouseClick;

}PlAction;

constexpr auto EMPTY_CELL = '\xb0';//'\xb0';
constexpr auto OCCUPIED_CELL = '\xdb';

constexpr CHAR_T BORDERCORNER = '\xce';
constexpr CHAR_T BORDERVERTICAL = '\xba';
constexpr CHAR_T BORDERHORIZONTAL = '\xcd';

constexpr SHORT WIDTHDEFAULT = 25;
constexpr SHORT HEIGHTDEFAULT = 25;

constexpr SHORT FILED_BASE_SIZE = 15;

enum Cell_T {
	empty, cell
};

typedef std::vector<STRING> FrameData;
typedef std::vector<std::vector<Cell_T>> FieldData;

class Field
{
public:
	Field();
	Field(const SHORT&, const SHORT&);
	~Field() = default;

	Cell_T& at(SHORT, SHORT);

	bool placeCell(const SHORT&, const SHORT&);
	bool clearCell(const SHORT& x, const SHORT& y);

	SHORT width;
	SHORT height;
	FieldData data;
};

class Frame
{
public:
	Frame();
	Frame(const Field&);
	Frame(const SHORT&, const SHORT&, const FrameData&);
	Frame(const SHORT&, const SHORT&);
	CHAR_T& at(SHORT, SHORT);
	~Frame() = default;

	SHORT width;
	SHORT height;
	FrameData data;
};