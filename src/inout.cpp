#include "inout.h"

Source::Source(std::istream& is)
	: m_pIstream(is)
{ }

bool Source::get(uint8_t& ch)
{
	if (m_pIstream >> ch)
	{
		return true;
	}

	return false; 
}

Sink::Sink(std::ostream& os)
	: m_pOstream(os)
{ }

void Sink::put(const std::string& ch)
{
	m_pOstream << ch;
}