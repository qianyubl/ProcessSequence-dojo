#include "SequenceProcessor.hpp"
#include <algorithm>

int SequenceProcessor::ProcessSequence(vector<int>& p_seq)
{
    sort(p_seq.begin(), p_seq.end());
    auto l_last = unique(p_seq.begin(), p_seq.end());
    p_seq.erase(l_last, p_seq.end());

    return 0;
}
