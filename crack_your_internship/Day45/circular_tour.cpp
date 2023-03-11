// https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
        int start=0,cal=0,rem=0;
        
        for(int i=0;i<n;i++)
        {
            cal += p[i].petrol - p[i].distance;
            
            if(cal <0)
            {
                start =i+1;
                rem += cal;
                cal = 0;
            }
            
        }
        
        return (cal+rem >0) ? start : -1;
    }
};