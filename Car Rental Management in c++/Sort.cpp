void sort(string food[],int rs[])
{
    for(int i = 0; i <= MenuCount - 1; i++)
    {
         for(int j = 0; j <= MenuCount; j++)
         {
             if(rs[j] < rs[i])
             {
                 int temp = rs[j];
                 rs[j] = rs[i];
                 rs[i] = temp;

                 string temp1 = food[j];
                 food[j] = food[i];
                 food[i] = temp;
                 
             }
         }
    }
}