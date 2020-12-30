int trailingZeroes(int n) {
        
        int countOf5 = 0;
        long div = 5;
        
        while(n/div > 0)
        {
            countOf5 += n/div;
            div *= 5;
        }
        return countOf5;
    }