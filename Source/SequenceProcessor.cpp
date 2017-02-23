#include "SequenceProcessor.hpp"
#include <algorithm>

int SequenceProcessor::ProcessSequence(vector<int>& p_seq)
{
    sort(p_seq.begin(), p_seq.end());

    auto l_last = unique(p_seq.begin(), p_seq.end());
    p_seq.erase(l_last, p_seq.end());

    auto l_result = stable_partition(p_seq.begin(), p_seq.end(),
                               [](auto p_val){return p_val % 5 == 0;});

    if(prev(l_result, 2) >= p_seq.begin() and next(l_result, 2) <= p_seq.end())
        reverse(prev(l_result, 2), next(l_result, 2));

    #if 0
    if(i-2 >= p_seq.begin() and i+2 <= p_seq.end())
    {
        int l_tmp = 0;
        l_tmp = p_seq[it-1], p_seq[it-1] = p_seq[it], p_seq[it] = l_tmp;
        l_tmp = p_seq[it-1], p_seq[it-1] = p_seq[it], p_seq[it] = l_tmp;
    }
    #endif
    return 0;
}
