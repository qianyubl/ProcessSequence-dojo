#include <vector>
using namespace std;

class SequenceProcessor
{
public:
    static void process(vector<int>& p_seq);
    
    static void handleInvalidSeq(vector<int>& p_seq);
    static void sortSeq(vector<int>& p_seq);
    static void removeDuplicateNums(vector<int>& p_seq);
    static void putNumsCannotBeDevidedBy5Back(vector<int>& p_seq, vector<int>::iterator &p_result);
    static void twoLastNumbersDivededBy5ShouldbeExchangedWithNext2Numbers(vector<int>& p_seq, vector<int>::iterator &p_result);
    static void putBackAllNumbersBeforeThe1stNumberBiggerThanThe1OnTheFront(vector<int>& p_seq, vector<int>::iterator &p_result); 
};

