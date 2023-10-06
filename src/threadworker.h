#pragma once

#include <thread>
#include <string>
#include <memory>
#include "inout.h"

/*
* @brief ����� ��� ������ � ��������� ������. 
* ������ ����� � ������������ �� � ��������� �������.
*/
class ThreadWorker
{
public:
	/*
	* @brief �����������.
	* @param source ������ �� ����� ������ �����.
	* @param sink ������ �� ����� ������ ������.
	*/
	ThreadWorker(ISource& source, ISink& sink);

	/*
	* @brief ����� ����������� ������ ������.
	*/
	void start();

	/*
	* @brief ����� ��������������� ������ ������.
	*/
	void stop();

	/*
	* @brief ����������.
	*/
	~ThreadWorker();
private:
	/*
	* @brief ��������� ����� ���������� ������ ������ ������.
	*/
	void run();
	/*
	* @brief ��������� �����, �������������� ���� � ��������� ������.
	* @param byte ����������, ������� ������ ����.
	* @return ���������� ��������� ������, ������� ��� �������.
	* ��� ��������� ����������� - ������������ ������� ������.
	*/
	std::string convert(uint8_t byte);
private:
	std::thread m_pThread; ///< ��������� ������.
	ISource& m_pSource; ///< ��������� ������ �����.
	ISink& m_pSink; ///< ��������� ������ ������.
	bool m_pIsRunning; ///< ��������� ������ ������.
};