//Buy and sell stock

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 int nod;
   void pt(int k,int dp[][nod],int pos[][nod],int pri[],int i,int j,int flag)
      {                                                                            // 1 for buying
           if(pos[i][j]==-1)                                                // 0 for selling  
              {
                  return ;
              }
             else
              {
                 if(pos[i][j]==j)
                   pt(k,dp,pos,pri,i,j-1,flag);
                 else
                   {
                     int x=flag;
                      pt(k,dp,pos,pri,i-1,pos[i][j],(x+1)%2);
                      if(x==0)
                         cout<<"Selling the item at price : "<<pri[j]<<"   on day  : "<<j<<endl;
                       else
                         cout<<"Buying the item at price : "<<pri[j]<<"   on day  : "<<j<<endl;
                     }   
               return ;                                                       
          }
    }
  void calcprofit1(int pri[],int nod,int k)
    {
         cout<<"Calculate profit by first method : "<<endl;
       int dp1[k+1][nod];             // Rows stand for transactions
       int i,j,x,f;                                   //Cols stand for days
       int pos1[k+1][nod];
       for(i=0;i<nod;i++)
         {
            dp1[0][i]=0;
            pos1[0][i]=-1;
         }
       for(i=0;i<=k;i++)
        {
           dp1[i][0]=0;
            pos1[i][0]=-1;
        }
        for(i=1;i<=k;i++)
         {
           for(j=1;j<nod;j++)
             {
                int mp=dp1[i][j-1];
                pos1[i][j]=j;
                int flag=0;
                for(x=0;x<j;x++)
                 {
                   int y=dp1[i-1][x]+pri[j]-pri[x];
                   if(y>mp)
                    {
                       mp=y;
                       f=x;
                       flag=1;
                     }
                 }
                 dp1[i][j]=mp;
                  if(flag==1)
                    pos1[i][j]=f;
            }
        }

        cout<<" Profit by first method is : "<<dp1[k][nod-1]<<endl;
        cout<<"Printing the transactions by first method information : "<<endl;
         
        pt(k,dp1,pos1,pri,k+1,nod,0);
        return ;

   } 

     void calcprofit2(int pri[],int nod,int k)
       {
          cout<<"Calculating profit by second method : "<<endl;
          int dp2[k+1][nod];
          int i,j,x,f;
          int pos2[k+1][nod];
          for(i=0;i<nod;i++)
           {
             dp2[0][i]=0;
             pos2[0][i]=-1;
          }
          for(i=0;i<=k;i++)
           {
             dp2[i][0]=0;
             pos2[i][0]=-1;
           }
           for(i=1;i<=k;i++)
             {
                int maxdiff=INT_MIN;
               for(j=1;j<nod;j++)
               {
                 int x=dp2[i-1][j-1]-pri[j-1];
                 if(x>maxdiff)
                   {
                      maxdiff=x;
                      f=j-1;
                   }
                 if(dp2[i][j-1]>maxdiff+pri[j])
                   {
                     dp2[i][j]=dp2[i][j-1];
                      pos2[i][j]=j;
                   }
                  else
                   {
                     dp2[i][j]=maxdiff+pri[j];
                     pos2[i][j]=f;
                   }
            }
        }
        cout<<"Profit by second method is : "<<dp2[k][nod-1]<<endl;
        cout<<"Printing the transactions by second method : "<<endl;

         pt(k,dp2,pos2,pri,k+1,nod,0);

         return  ;

      }
                    
           
  int main()
   {
      int k;
      cout<<"Enter the no. of days and transactions : "<<endl;
      cin>>nod>>k;
      int pri[nod];
      int i,j;
        cout<<"Enter the profits in each day : "<<endl;
      for(i=0;i<nod;i++)
         cin>>pri[i];
     calcprofit1(pri,nod,k);
     calcprofit2(pri,nod,k);

     return 0;
   }
// Successfully cloned the code

