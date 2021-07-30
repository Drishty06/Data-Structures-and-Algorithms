// problem link: https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1#
 // hint: num   E	D	C	B	A
    //        0	   0	0	0	0	0
    //        1    0  0 0	0	1
    //        2    0	0	0	1	0
    //        3    0	0	0	1	1
    //        4    0	0	1	0	0
    //        5	   0	0	1	0	1
    //        6	   0	0	1	1	0
    //        7	   0	0	1	1	1
    // here a b c d e are like the bits in binary representation of number.
    // we can notice pattern here and that is: in the first bits of all numbers, 0 and 1 occur alternatively
    // in the second bits, 0 and 1 occur after 2 occurences
    // in the third bits, 0 and 1 occur after 4 occurences
    // the reason of this pattern is that nth bit has actually the value of 2^n-
    
    // my logic: (see the commented line numbers)
    // line 0: the expression (int)(log2(n)+1) = number of bits required to represent any number in binary like 6 binary = 110 therefore it can be said that it can be represented in 3 bits
    // since we just want the loop to run (int)(log2(n)+1) times.
    // line 1: since we noted the pattern as it was repeating after 2^n-1 occurences in the nth bit therfore
    // this temp gives us that how many groups of 2^n-1 elements are already covered before
    // line 2: now since after these groups, half groups will be of 0s and half groups will be 1s so we did temp/2
    // in this line two we are counting 1s in "whole" such groups
    // and as groups will be of 2^n-1 size so multiplied it wwith
    // line 3: in the above part we counted 1s in such whole groups but there can be groups which may have1s less than 2^n-1 times
    // so rest of the is for that purpose
    // only if the current bit is set, we need to count incomplete group, or else no worries, since it wwill be an incomplete group of 0s
    // line 4: this is used to include the ones in the incomplete groups as modulo will say as how much away it is from group size ka multiple
    // done
    
     
    int countSetBits(int n)
    {
        int count = 0;
        for(int i=1; i<=(int)(log2(n)+1); i++)    // line 0
        {
            int temp = n / (int)(pow(2, i-1));    // line 1
            
            count += (pow(2, i-1)) * (temp/2);    // line 2
            if((n & (1 << (i-1))) != 0)           // line 3
            {
                int add = n % (int)(pow(2, i-1)); // line 4
                count += add;
                count++;
            }
            
        }
        return count;
    }
