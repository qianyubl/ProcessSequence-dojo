#include "SequenceProcessor.hpp"
#include <algorithm>
#include <stdexcept>

void SequenceProcessor::process(vector<int>& p_seq)
{
    if(p_seq.size() != 8)
    {
        throw length_error("invalid size");
    }

    if(any_of(p_seq.begin(), p_seq.end(),
              [](int p_val){return 0 > p_val or p_val > 100;}))
    {
        throw out_of_range("Numbers out of range.");
    }

    sort(p_seq.begin(), p_seq.end());

    p_seq.erase(unique(p_seq.begin(), p_seq.end()), p_seq.end());

    auto l_result = stable_partition(p_seq.begin(), p_seq.end(),
                                     [](auto p_val){return p_val % 5 == 0;});

    auto l_first = prev(l_result, 2);
    auto l_last = next(l_result, 2);
    if(l_first >= p_seq.begin() and l_last <= p_seq.end())
    {
        reverse(l_first, l_last);
    }

    l_result = find_if(p_seq.begin(), p_seq.end(), [&](int p_val){return p_val > p_seq[0];});
    rotate(p_seq.begin(), l_result, p_seq.end());
}
