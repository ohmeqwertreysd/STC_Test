#include <iostream>
#include <chrono>
#include "source_mock.h"
#include "sink_mock.h"
#include "threadworker.h"
#include "gtest/gtest.h"

/*
* @test TestType
* @brief Тест для проверки считывания 6-7 битов, для определения type
*/
TEST(TestType, TestAll)
{
	SourceMock source;
	SinkMock sink;
	EXPECT_CALL(source, get(testing::_))
		.Times(4)
		.WillOnce(testing::DoAll(testing::SetArgReferee<0>(0b00000000), testing::Return(true)))
		.WillOnce(testing::DoAll(testing::SetArgReferee<0>(0b01000000), testing::Return(true)))
		.WillOnce(testing::DoAll(testing::SetArgReferee<0>(0b10000000), testing::Return(true)))
		.WillOnce(testing::Return(false));

	EXPECT_CALL(sink, put("0")).Times(2);
	EXPECT_CALL(sink, put("a")).Times(1);

	ThreadWorker worker(source, sink);

	worker.start();
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	worker.stop();
}

/*
* @test TestType
* @brief Тест для проверки определения беззнакового целого
*/
TEST(TestType, TestUnsigned)
{
	SourceMock source;
	SinkMock sink;

	EXPECT_CALL(source, get(testing::_))
		.Times(7)
		.WillOnce(testing::DoAll(testing::SetArgReferee<0>(0b00000000), testing::Return(true)))
		.WillOnce(testing::DoAll(testing::SetArgReferee<0>(0b00111010), testing::Return(true)))
		.WillOnce(testing::DoAll(testing::SetArgReferee<0>(0b00111111), testing::Return(true)))
		.WillOnce(testing::DoAll(testing::SetArgReferee<0>(0b00101011), testing::Return(true)))
		.WillOnce(testing::DoAll(testing::SetArgReferee<0>(0b00001011), testing::Return(true)))
		.WillOnce(testing::DoAll(testing::SetArgReferee<0>(0b00001111), testing::Return(true)))
		.WillOnce(testing::Return(false));
	
	EXPECT_CALL(sink, put("0")).Times(1);
	EXPECT_CALL(sink, put("58")).Times(1);
	EXPECT_CALL(sink, put("63")).Times(1);
	EXPECT_CALL(sink, put("43")).Times(1);
	EXPECT_CALL(sink, put("11")).Times(1);
	EXPECT_CALL(sink, put("15")).Times(1);

	ThreadWorker worker(source, sink);

	worker.start();
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	worker.stop();
}

/*
* @test TestType
* @brief Тест для проверки определения знакового целого
*/
TEST(TestType, TestSigned)
{
	SourceMock source;
	SinkMock sink;

	EXPECT_CALL(source, get(testing::_))
		.Times(9)
		.WillOnce(testing::DoAll(testing::SetArgReferee<0>(0b01000000), testing::Return(true)))
		.WillOnce(testing::DoAll(testing::SetArgReferee<0>(0b01000001), testing::Return(true)))
		.WillOnce(testing::DoAll(testing::SetArgReferee<0>(0b01000010), testing::Return(true)))
		.WillOnce(testing::DoAll(testing::SetArgReferee<0>(0b01000101), testing::Return(true)))
		.WillOnce(testing::DoAll(testing::SetArgReferee<0>(0b01001111), testing::Return(true)))
		.WillOnce(testing::DoAll(testing::SetArgReferee<0>(0b01011111), testing::Return(true)))
		.WillOnce(testing::DoAll(testing::SetArgReferee<0>(0b01111111), testing::Return(true)))
		.WillOnce(testing::DoAll(testing::SetArgReferee<0>(0b01100000), testing::Return(true)))
		.WillOnce(testing::Return(false));

	EXPECT_CALL(sink, put("0")).Times(1);
	EXPECT_CALL(sink, put("1")).Times(1);
	EXPECT_CALL(sink, put("2")).Times(1);
	EXPECT_CALL(sink, put("5")).Times(1);
	EXPECT_CALL(sink, put("15")).Times(1);
	EXPECT_CALL(sink, put("31")).Times(1);
	EXPECT_CALL(sink, put("-1")).Times(1);
	EXPECT_CALL(sink, put("-32")).Times(1);

	ThreadWorker worker(source, sink);

	worker.start();
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	worker.stop();
}

/*
* @test TestType
* @brief Тест для проверки определения буквы латинского алфавита
*/
TEST(TestType, TestChar)
{
	SourceMock source;
	SinkMock sink;

	EXPECT_CALL(source, get(testing::_))
		.Times(7)
		.WillOnce(testing::DoAll(testing::SetArgReferee<0>(0b10111111), testing::Return(true)))
		.WillOnce(testing::DoAll(testing::SetArgReferee<0>(0b10111010), testing::Return(true)))
		.WillOnce(testing::DoAll(testing::SetArgReferee<0>(0b10011001), testing::Return(true)))
		.WillOnce(testing::DoAll(testing::SetArgReferee<0>(0b10001101), testing::Return(true)))
		.WillOnce(testing::DoAll(testing::SetArgReferee<0>(0b10010101), testing::Return(true)))
		.WillOnce(testing::DoAll(testing::SetArgReferee<0>(0b10000000), testing::Return(true)))
		.WillOnce(testing::Return(false));

	EXPECT_CALL(sink, put("")).Times(2);
	EXPECT_CALL(sink, put("z")).Times(1);
	EXPECT_CALL(sink, put("n")).Times(1);
	EXPECT_CALL(sink, put("v")).Times(1);
	EXPECT_CALL(sink, put("a")).Times(1);

	ThreadWorker worker(source, sink);

	worker.start();
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	worker.stop();
}


int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	::testing::InitGoogleMock(&argc, argv);
	
	return RUN_ALL_TESTS();
}