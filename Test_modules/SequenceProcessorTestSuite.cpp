#include "gtest/gtest.h"
#include "SequenceProcessor.hpp"

using namespace std;

TEST(SequenceProcessorTestSuite, anUnsortedSequenceShouldBeSorted)
{
    vector<int> l_seq = { 1, 8, 7, 99, 94, 76, 22, 42 };
    vector<int> l_seqExpect = { 1, 7, 8, 22, 42, 76, 94, 99 };
    SequenceProcessor::ProcessSequence(l_seq);
    ASSERT_EQ(l_seq, l_seqExpect);
}

TEST(SequenceProcessorTestSuite, duplicatedNumbersShouldBeRemoved)
{
    vector<int> l_seq = { 1, 8, 1, 99, 94, 8, 42, 42 };
    vector<int> l_seqExpect = { 1, 8, 42, 94, 99 };
    SequenceProcessor::ProcessSequence(l_seq);
    ASSERT_EQ(l_seq, l_seqExpect);
}

TEST(SequenceProcessorTestSuite, allNumbersCannotBeDevidedBy5ShouldBePlacedBack)
{
    vector<int> l_seq = { 5, 8, 0, 100, 95, 8, 42, 42 };
    vector<int> l_seqExpect = { 0, 5, 95, 100, 8, 42 };
    SequenceProcessor::ProcessSequence(l_seq);
    ASSERT_EQ(l_seq, l_seqExpect);
}

