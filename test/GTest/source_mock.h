#pragma once
#include "inout.h"
#include "gmock/gmock.h"

/*
* @brief ��������� ����� ��� mock ������.
*/
class SourceMock : public ISource
{
public:
	/*
	* @brief Mock ����� ��� ������ ����� �� ������ �����.
	* @param byte ����������, � ������� ����� ������� ������� ����.
	* @return ���������� true, ���� ������ �������, ����� false.
	*/
	MOCK_METHOD(bool, get, (uint8_t& byte), (override));
};