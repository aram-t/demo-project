#include "gtest/gtest.h"

#include "nearest-greater-number-array.h"


namespace
{

TEST(MyTest, InputFromKaren)
{
	std::vector<int> input =
		{12, 11, 10, 9, 12, 8, 7, 14};
	std::vector<int> expected_output =
		{7,  3,  2,  1, 3,  2, 1, 0};

	auto output = get_nearest_greater_values(input);

	ASSERT_EQ(output.size(), expected_output.size());
	for (unsigned i=0;i<input.size();++i)
	{
		EXPECT_EQ(output[i], expected_output[i]) << "issue on id number " << i;
	}
}

TEST(MyTest, RandomNumbers)
{
	std::vector<int> input =
		{10, 9, 8, 12, 16, 13, 8, 15};
	std::vector<int> expected_output =
		{3,  2, 1, 1,  0,  2,  1, 0};

	auto output = get_nearest_greater_values(input);

	ASSERT_EQ(output.size(), expected_output.size());
	for (unsigned i=0;i<input.size();++i)
	{
		EXPECT_EQ(output[i], expected_output[i]) << "issue on id number " << i;
	}
}

TEST(MyTest, Descending)
{
	std::vector<int> input =
		{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	std::vector<int> expected_output =
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	auto output = get_nearest_greater_values(input);

	ASSERT_EQ(output.size(), expected_output.size());
	for (unsigned i=0;i<input.size();++i)
	{
		EXPECT_EQ(output[i], expected_output[i]) << "issue on id number " << i;
	}
}

TEST(MyTest, Ascending)
{
	std::vector<int> input =
		{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::vector<int> expected_output =
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 0};

	auto output = get_nearest_greater_values(input);

	ASSERT_EQ(output.size(), expected_output.size());
	for (unsigned i=0;i<input.size();++i)
	{
		EXPECT_EQ(output[i], expected_output[i]) << "issue on id number " << i;
	}
}

TEST(MyTest, UpAndDown)
{
	std::vector<int> input =
		{1, 2, 1, 2, 1, 2, 1, 2, 1, 2};
	std::vector<int> expected_output =
		{1, 0, 1, 0, 1, 0, 1, 0, 1, 0};

	auto output = get_nearest_greater_values(input);

	ASSERT_EQ(output.size(), expected_output.size());
	for (unsigned i=0;i<input.size();++i)
	{
		EXPECT_EQ(output[i], expected_output[i]) << "issue on id number " << i;
	}
}


TEST(MyTest, Hmmm)
{
	std::vector<int> input =
		{20, 18, 15, 16, 19, 2, 1};
	std::vector<int> expected_output =
		{0,  3,  1,  1,  0,  0, 0};

	auto output = get_nearest_greater_values(input);

	ASSERT_EQ(output.size(), expected_output.size());
	for (unsigned i=0;i<input.size();++i)
	{
		EXPECT_EQ(output[i], expected_output[i]) << "issue on id number " << i;
	}
}


}
