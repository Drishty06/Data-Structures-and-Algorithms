int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currPetrol = 0, totalPetrol = 0;
        int startIndex = 0;
        int totalCities = gas.size();

        for(int i=0; i<totalCities; i++)
        {
            totalPetrol += gas[i] - cost[i];
            if(currPetrol < 0)
            {
		        startIndex = i;
                currPetrol = 0;
            }
            currPetrol += gas[i] - cost[i];
        } 
        if(totalPetrol < 0) 
        {
            return -1;
        }
        return startIndex;

    }
