#pragma once
#include <iostream>

/*
* @brief ��������� �����.
*/
class ISource
{
public:
	/*
	* @brief ����� ��� ������ ����� �� ������ �����.
	* @param byte ����������, � ������� ����� ������� ������� ����.
	* @return ���������� true, ���� ������ �������, ����� false.
	*/
	virtual bool get(uint8_t& byte) = 0;

	/*
	* @brief ����������� ���������� �� ���������.
	*/
	virtual ~ISource() = default;
};

/*
* @brief ��������� ������.
*/
class ISink
{
public:
	/*
	* @brief ����� ��� ������ ���������� ������� � ����� ������.
	* @param byte ����������, ������� ������ ��������� ������.
	*/
	virtual void put(const std::string& ch) = 0;

	/*
	* @brief ����������� ���������� �� ���������
	*/
	virtual ~ISink() = default;
};

/*
* @brief ���������� ���������� ���������� ��� ���������� ����.
*/
class Source : public ISource
{
public:
	/*
	* @brief �����������.
	* @param is ����� ����� ��� ���������� ������.
	*/
	Source(std::istream& is);
	/*
	* @brief ������������� ����� ��� ������ ����� �� ������ �����.
	* @param byte ���������� � ������� ����� ������� ����.
	* @return ���������� true, ���� ������ �������, ����� false.
	*/
	virtual bool get(uint8_t& byte) override;
	/*
	* @brief ���������� �� ���������.
	*/
	~Source() = default;
private:
	std::istream& m_pIstream; ///< ��������� ������ �����.
};

/*
* @brief ���������� ���������� ���������� ��� ������ ���������� �������.
*/
class Sink : public ISink
{
public:
	/*
	* @brief �����������.
	* @param os ����� ������ ��� ���������� �������.
	*/
	Sink(std::ostream& os);
	/*
	* @brief ������������� ����� ��� ������ ���������� ������� � �����.
	* @param ch ����������, ������� ������ ��������� ������.
	*/
	virtual void put(const std::string& ch) override;
	/*
	* @brief ���������� �� ���������.
	*/
	~Sink() = default;
private:
	std::ostream& m_pOstream; ///< ��������� ������ ������.
};