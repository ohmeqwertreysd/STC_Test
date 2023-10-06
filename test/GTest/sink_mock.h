#pragma once
#include <string>
#include "inout.h"
#include "gmock/gmock.h"

/*
* @brief Интерфейс вывода для mock тестов.
*/
class SinkMock : public ISink
{
public:
	/*
	* @brief Mock метод для записи строкового символа в поток вывода.
	* @param byte Переменная, которая хранит строковый символ.
	*/
	MOCK_METHOD(void, put, (const std::string& ch), (override));
};
