#pragma once
#include "inout.h"
#include "gmock/gmock.h"

/*
* @brief Интерфейс ввода для mock тестов.
*/
class SourceMock : public ISource
{
public:
	/*
	* @brief Mock метод для чтения байта из потока ввода.
	* @param byte Переменная, в которую будет записан входной байт.
	* @return Возвращает true, если чтение успешно, иначе false.
	*/
	MOCK_METHOD(bool, get, (uint8_t& byte), (override));
};