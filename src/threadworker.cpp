#include "threadworker.h"

ThreadWorker::ThreadWorker(ISource& source, ISink& sink)
	: m_pSource(source), m_pSink(sink), m_pIsRunning(false)
{ }

void ThreadWorker::start()
{
	m_pIsRunning = true;
	m_pThread = std::thread(&ThreadWorker::run, this);
}

void ThreadWorker::run()
{
	uint8_t byte;
	while (m_pSource.get(byte))
	{
		m_pSink.put(convert(byte));
	}
}

std::string ThreadWorker::convert(uint8_t byte)
{
	constexpr uint8_t mask_type_a = 0b00; // unsigned
	constexpr uint8_t mask_type_b = 0b01; // signed
	constexpr uint8_t mask_type_c = 0b10; // char

	uint8_t type = byte >> 6;
	uint8_t data = byte & 0b00111111;

	if (type == mask_type_a)
	{
		return std::to_string(data);
	}
	else if (type == mask_type_b)
	{
		return std::to_string(static_cast<int8_t>(data << 2) >> 2);
	}
	else if ((type == mask_type_c) && ('a' + data <= 'z'))
	{
		return std::string(1, 'a' + data);
	}

	return "";
}

void ThreadWorker::stop()
{
	m_pIsRunning = false;
	if (m_pThread.joinable())
	{
		m_pThread.join();
	}
}

ThreadWorker::~ThreadWorker()
{
	stop();
}
