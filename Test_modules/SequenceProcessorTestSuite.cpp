#include "gtest/gtest.h"
#include "SequenceProcessor.hpp"

using namespace std;

TEST(SequenceProcessorTestSuite, anUnsortedSequenceShouldBeSorted)
{
    vector<int> l_seq = { 5, 8, 0, 100, 95, 76, 25, 42 };
    vector<int> l_seqExpect = { 0, 5, 8, 25, 42, 76, 95, 100 };
    SequenceProcessor::ProcessSequence(l_seq);
    ASSERT_EQ(l_seq, l_seqExpect);
}



