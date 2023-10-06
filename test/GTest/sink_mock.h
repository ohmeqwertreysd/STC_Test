#pragma once
#include <string>
#include "inout.h"
#include "gmock/gmock.h"

/*
* @brief ��������� ������ ��� mock ������.
*/
class SinkMock : public ISink
{
public:
	/*
	* @brief Mock ����� ��� ������ ���������� ������� � ����� ������.
	* @param byte ����������, ������� ������ ��������� ������.
	*/
	MOCK_METHOD(void, put, (const std::string& ch), (override));
};