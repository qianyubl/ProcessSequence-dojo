#include "SequenceProcessor.hpp"
#include <algorithm>
#include <stdexcept>

void SequenceProcessor::process(vector<int>& p_seq)
{
    
    handleInvalidSeq(p_seq);
    sortSeq(p_seq);
    removeDuplicateNums(p_seq);
    vector<int>::iterator l_result;
    putNumsCannotBeDevidedBy5Back(p_seq,l_result);
    twoLastNumbersDivededBy5ShouldbeExchangedWithNext2Numbers(p_seq,l_result);
    putBackAllNumbersBeforeThe1stNumberBiggerThanThe1OnTheFront(p_seq,l_result);
    
}

void SequenceProcessor::handleInvalidSeq(vector<int>& p_seq)
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

}

void SequenceProcessor::sortSeq(vector<int>& p_seq)
{
    sort(p_seq.begin(), p_seq.end());
}

void SequenceProcessor::removeDuplicateNums(vector<int>& p_seq)
{
    p_seq.erase(unique(p_seq.begin(), p_seq.end()), p_seq.end());    
}

void SequenceProcessor::putNumsCannotBeDevidedBy5Back(vector<int>& p_seq, vector<int>::iterator &p_result)
{
    p_result = stable_partition(p_seq.begin(), p_seq.end(),
                                [](auto p_val){return p_val % 5 == 0;});
}

void SequenceProcessor::twoLastNumbersDivededBy5ShouldbeExchangedWithNext2Numbers(vector<int>& p_seq, vector<int>::iterator &p_result)
{
    if(2 <= distance(p_seq.begin(), p_result) and 2 <= distance(p_result, p_seq.end()))
    {
        reverse(prev(p_result, 2), next(p_result, 2));
    }
}

void SequenceProcessor::putBackAllNumbersBeforeThe1stNumberBiggerThanThe1OnTheFront(vector<int>& p_seq, vector<int>::iterator &p_result)
{
    p_result = find_if(p_seq.begin(), p_seq.end(), [&](int p_val){return p_val > p_seq[0];});
    rotate(p_seq.begin(), p_result, p_seq.end());

}


