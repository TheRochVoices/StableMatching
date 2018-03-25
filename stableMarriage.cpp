#include<iostream>
using namespace std;
const int N = 4;
const int M = N+1;

int ladyNotHappy(int pref[2*N][M], int woman, int man)
{
	int i = 0;
	while(pref[woman][i] != pref[woman][M-1])
	{
		if(pref[woman][i] == man)
		{
			return true;
		}
		i++;
	}
	return false;
}

void stableMarriage(int pref[2*N][M])
{
	int freeMen = N;
	int man, manPref;
	int woman;
	
	while(freeMen > 0)
	{
	
		for(int i = 0;i<N;i++)
		{
			if(pref[i][M-1] == -1)
			{
				man = i;
				break;								//finding the unengaged sad guy who is not able to get his life in order	
			}
		}
		
		for(int i = 0;i<M-1;i++)
		{											//iterating over our sad guy's prefernces 
			woman = pref[man][i];
			
			if(pref[woman][M-1] == -1)				//if the lady is sad too
			{
				pref[man][M-1] = woman;
				pref[woman][M-1] = man;
				freeMen--;								//engage them
				break;
			}
			else
			{
				if(ladyNotHappy(pref, woman, man))
				{
					pref[pref[woman][M-1]][M-1] = -1;
					pref[woman][M-1] = man;
					pref[man][M-1] = woman;
				}
			}
			
		}
	}
	cout<<"Man\tWoman"<<endl;
	for(int i=0;i<N;i++)
	{
		cout<<i<<"\t"<<pref[i][M-1];
		cout<<endl;
	}
}

int main()
{
	int pref[2*N][M] = {{5, 6, 4, 7, -1}, {7, 6, 5, 4, -1},{6, 5, 7, 4, -1},{5, 6, 7, 4, -1},
							{0, 1, 2, 3, -1},{0, 1, 2, 3, -1},{0, 1, 2, 3, -1},{0, 1, 2, 3, -1}}; 
	stableMarriage(pref);
							
/*	for(int i=0;i<2*N;i++)
	{
		for(int j=0;j<M;j++)
		{
			cout<<pref[i][j]<<"\t";
		}
		cout<<endl;
	}*/
}
