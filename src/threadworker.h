#pragma once

#include <thread>
#include <string>
#include <memory>
#include "inout.h"

/*
* @brief Класс для работы в отдельном потоке. 
* Читает байты и конвертирует их в строковые символы.
*/
class ThreadWorker
{
public:
	/*
	* @brief Конструктор.
	* @param source Ссылка на класс потока ввода.
	* @param sink Ссылка на класс потока вывода.
	*/
	ThreadWorker(ISource& source, ISink& sink);

	/*
	* @brief Метод запускающий работу потока.
	*/
	void start();

	/*
	* @brief Метод останавливающий работу потока.
	*/
	void stop();

	/*
	* @brief Деструктор.
	*/
	~ThreadWorker();
private:
	/*
	* @brief Приватный метод содержащий логику работы потока.
	*/
	void run();
	/*
	* @brief Приватный метод, конвертирующий байт в строковый символ.
	* @param byte Переменная, которая хранит байт.
	* @return Возвращает строковый символ, который был получен.
	* При неудачной конвертации - возвращается пустная строка.
	*/
	std::string convert(uint8_t byte);
private:
	std::thread m_pThread; ///< Экземпляр потока.
	ISource& m_pSource; ///< Агрегация потока ввода.
	ISink& m_pSink; ///< Агрегация потока вывода.
	bool m_pIsRunning; ///< Состояние работы потока.
};