#pragma once
#include <iostream>

/*
* @brief Интерфейс ввода.
*/
class ISource
{
public:
	/*
	* @brief Метод для чтения байта из потока ввода.
	* @param byte Переменная, в которую будет записан входной байт.
	* @return Возвращает true, если чтение успешно, иначе false.
	*/
	virtual bool get(uint8_t& byte) = 0;

	/*
	* @brief Виртуальный деструктор по умолчанию.
	*/
	virtual ~ISource() = default;
};

/*
* @brief Интерфейс вывода.
*/
class ISink
{
public:
	/*
	* @brief Метод для записи строкового символа в поток вывода.
	* @param byte Переменная, которая хранит строковый символ.
	*/
	virtual void put(const std::string& ch) = 0;

	/*
	* @brief Виртуальный деструктор по умолчанию
	*/
	virtual ~ISink() = default;
};

/*
* @brief Конкретная реализация интерфейса для считывания байт.
*/
class Source : public ISource
{
public:
	/*
	* @brief Конструктор.
	* @param is Поток ввода для считывания байтов.
	*/
	Source(std::istream& is);
	/*
	* @brief Перегруженный метод для чтения байта из потока ввода.
	* @param byte Переменная в которую будет записан байт.
	* @return Возвращает true, если чтение успешно, иначе false.
	*/
	virtual bool get(uint8_t& byte) override;
	/*
	* @brief Деструктор по умолчанию.
	*/
	~Source() = default;
private:
	std::istream& m_pIstream; ///< Агрегация потока ввода.
};

/*
* @brief Конкретная реализация интерфейса для вывода строкового символа.
*/
class Sink : public ISink
{
public:
	/*
	* @brief Конструктор.
	* @param os Поток вывода для строкового символа.
	*/
	Sink(std::ostream& os);
	/*
	* @brief Перегруженный метод для вывода строкового символа в поток.
	* @param ch Переменная, которая хранит строковый символ.
	*/
	virtual void put(const std::string& ch) override;
	/*
	* @brief Деструктор по умолчанию.
	*/
	~Sink() = default;
private:
	std::ostream& m_pOstream; ///< Агрегация потока вывода.
};