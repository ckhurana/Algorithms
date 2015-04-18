#include<iostream>
using namespace std;

int getMax(float A[][3], int n, bool &finished)
{
	finished = true;
	int pos = -1;
	float max_profit = 0;
	
	for(int i = 0; i < n; i++)
	{
		if(A[i][0] == 0)
			continue;
		else
		{
			finished = false;
			if(A[i][2] > max_profit || pos == -1)
			{
				max_profit = A[i][2];
				pos = i;
			}
		}
		
	}
	
	return pos;
}

int main()
{
	float max_weight, rem_weight, total_value = 0;
	bool items_finished = false;
	int n, step_no = 1;								// step_no used for showing steps for knapsack
	
	cout << "\n\tEnter number of items: ";
	cin >> n;
	
	cout << "\n\tEnter the maximum weight for the problem: ";	
	cin >> max_weight;
	
	rem_weight = max_weight;
	
	float items[n][3];
	
	
	cout << "\n======================================================================";
	cout << "\n----------------------Input data for each Item------------------------";
	cout << "\n======================================================================";
	
	for(int i = 0; i < n; i++)
	{
		cout << "\n\t----------------- Item No. " << i+1 << " ------------------";
		cout << "\n\tWeight: ";
		cin >> items[i][0];
		cout << "\n\tBenefit: ";
		cin >> items[i][1];
		items[i][2] = items[i][1] / items[i][0];
	}
	
	
	cout << "\n======================================================================";
	cout << "\n-----------------Knapsack Problem Solution Starts---------------------";
	cout << "\n======================================================================";
	while(rem_weight > 0)
	{
		int position = getMax(items, n, items_finished);
		float consumed = 0;
		if(items_finished == true)
			break;
		else
		{
			if(rem_weight >= items[position][0])
				consumed = items[position][0];
			else
				consumed = rem_weight;
			
			total_value += (consumed * items[position][2]);
			rem_weight -= consumed;
			items[position][0] -= consumed;
			
			
			cout << "\n\n\n\t----------------- Step No. " << step_no++ << " ------------------";
			cout << "\n\tItem No. " << position + 1;
			cout << "\n\tBenefit / Unit_weight: " << items[position][2];
			cout << "\n\tWeight: " << consumed;
			cout << "\n\tBenefit: " << consumed * items[position][2];
			
			/*
			if(rem_weight >= items[position][0])
			{
				rem_weight -= items[position][0];
				total_value += (items[position][0] * items[position][2]);
				items[position][0] = 0;
			}
			else
				if(rem_weight < items[position][0])
				{
					total_value += (rem_weight * items[position][2]);
					items[position][0] -= rem_weight;
					rem_weight = 0;
				}
			*/
		}
			
	}
	
	cout << "\n======================================================================";
	cout << "\n\tMaximum Value for the given Fractional Knapsack Problem : " << total_value;
	cout << "\n======================================================================";
	
	return 0;
}
