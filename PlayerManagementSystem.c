// Player Management System

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Player
{
	int JersyNumber;
	char name[50];
	int runs;
	int wicket;
	int MatchPlayed;
}Player;

int count = 0;
int capacity = 5;

void choice(Player*); // Taking choice
void AddPlayer(Player*);  // Add player
void displayPlayer(Player*);  // Display All Players
int searchPlayer(Player*);   // Search Player
void displayPlr(Player*);   // Display player after found in database (in search function)
void searchupdatedata(Player*);  // Update player Data
void removeplayer(Player*);   // Remove Player
void topthree(Player*);  // Leading Three Run Scorer OR Wicket Taker

void main()
{
	
	Player*plyarr = (Player*)malloc(sizeof(Player)*capacity);  // Creating array of size from user
	
	choice(plyarr);		// Taking Choice
	
}

void choice(Player* plyarr)
{
	while(1)
	{
		int choice;
		printf("******************************************************************************************************************\n");
		printf("\nEnter choice (1 - 7) \n1.Store Player \n2.Display Player \n3.Search Player \n4.Update Data \n5.Remove Player \n6.Top Three \n7.Exit: \n");
		scanf("%d",&choice);
		printf("******************************************************************************************************************\n");
		switch (choice)
		{
			case 1:
				{
					AddPlayer(plyarr);		
					break;
				}
			case 2:
				{
					displayPlayer(plyarr);	
					break;	
				}
			case 3:
				{
					int i = searchPlayer(plyarr);   
					if(i == 0)
						{
							printf("******************************************************************************************************************\n");
							printf("Player found at %d index\n",i);
							displayPlr(&plyarr[i]);
							printf("******************************************************************************************************************\n");
						}
					else if(i)
						{
							printf("******************************************************************************************************************\n");
							printf("Player found at %d index\n",i);
							displayPlr(&plyarr[i]);
							printf("******************************************************************************************************************\n");
						}
					else
						{
							printf("******************************************************************************************************************\n");
							printf("Player not found\n");
							printf("******************************************************************************************************************\n");
						}
						break;
				}
			case 4:
				{
					searchupdatedata(plyarr);	
					break;				
				}
			case 5:
				{
					removeplayer(plyarr);
					break;			
				}
			case 6:
				{
					topthree(plyarr);
					break;			
				}	
			case 7:
				{
					printf("Good Bye!!!....\n");
					return;
				}
			default:
				{
					printf("Invalid Choice!! \n");
					printf("Enter valid Choice \n");
					break;
				}			
		}
	}
}

void AddPlayer(Player*plyarr)
{
				int n;     // How many player want to add
				printf("How many players want to add: ");
				scanf("%d",&n);
	
				if((capacity - count) < n)   // If capacity full reallocation
				{
					plyarr = (Player*) realloc (plyarr, capacity + (n - (capacity - count)));
				}
				
				capacity = capacity + (n - (capacity - count));  // Capacity after reallocation
				
				for(int i = 0; i < n; i++)
					{
						printf("\nEnter Jersy Number: ");
						scanf("%d",&plyarr[count].JersyNumber);
						
						fflush(stdin);
					    printf("Enter Player Name: ");                                           
						gets(plyarr[count].name);
						
						printf("Enter Runs: ");	
						scanf("%d",&plyarr[count].runs);
						
						printf("Enter Wicket: ");	
						scanf("%d",&plyarr[count].wicket);
						
						printf("Enter Match Played: ");	
						scanf("%d",&plyarr[count].MatchPlayed);
						
						count = count + 1;
					}
}


void displayPlayer(Player*p1)
{	
	for(int i = 0; i < count; i++)
	{
		printf("******************************************************************************************************************\n");
		printf("Jersy Number: %d\t",p1[i].JersyNumber);
		printf("Name: %s\t",p1[i].name);
		printf("Runs: %d\t",p1[i].runs);
		printf("Wickets: %d\t",p1[i].wicket);
		printf("Match Played: %d\n",p1[i].MatchPlayed);
		printf("******************************************************************************************************************\n");
	}
}

int searchPlayer(Player* plyarr)
{
	int choice;
	printf("By which attribute you want to search player: \n");
	printf("By Player name Press 1 OR By Jersy Number Press 2: \n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			{
				char ch[30];
				fflush(stdin);
			    printf("Enter Player Name: ");                                           
				gets(ch);
				
							for(int i = 0; i < capacity; i++)
							{
								if((strcmp(ch,plyarr[i].name)) == 0)
								{
									return i;
								}
							}
							return -1;
			}
		case 2:
			{
				int ch;
			    printf("Enter Jersy Number: ");                                           
				scanf("%d",&ch);
				for(int i = 0; i < capacity; i++)
				{
					if(plyarr[i].JersyNumber == ch)
					{
						return i;
					}
				}
				return -1;
			}
	}
}

void displayPlr(Player*p1)
{
		printf("******************************************************************************************************************\n");
		printf("Jersy Number: %d\t",p1->JersyNumber);
		printf("Name: %s\t",p1->name);
		printf("Runs: %d\t",p1->runs);
		printf("Wickets: %d\t",p1->wicket);
		printf("Match Played: %d\n",p1->MatchPlayed);
		printf("******************************************************************************************************************\n");
}

void searchupdatedata(Player* p1)
{
	int ch;
	printf("Enter Jersy Number: \n");                                           
	scanf("%d",&ch);
	for(int i = 0; i < capacity; i++)
	{
		if(p1[i].JersyNumber == ch)
			{
				printf("Updating details for %s: \n",p1[i].name);
				printf("Enter new Runs: ");	
				scanf("%d",&p1[i].runs);
							
				printf("Enter New Wicket: ");	
				scanf("%d",&p1[i].wicket);
									
				printf("Enter New Match Played: ");	
				scanf("%d",&p1[i].MatchPlayed);
				
				printf("Updated details for %s: \n",p1[i].name);
				displayPlr(&p1[i]);
			}
	}
}

void removeplayer(Player*p1)
{
	int ch;
	printf("Enter Jersy Number: ");                                           
	scanf("%d",&ch);
	for(int i = 0; i < count; i++)
	{
		if(p1[i].JersyNumber == ch)
		{
			for(int j = i; j < count - 1; j++)
			{
				p1[j] = p1[j + 1];
			}
			count--;
			printf("Player removed from database\n");
		}
	}
}

void topthree(Player* p1)
{
	int choice;
	printf("By which attribute you want to find Top Three: \n");
	printf("By Runs Press 1 OR By Wickets Press 2: \n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			{
				printf("Top Three Run Scorer:\n");
				Player temp;
				for(int i = 0; i < count-1; i++)
				{
					for(int j = 0; j < count-1; j++)
					{
						if(p1[j].runs < p1[j + 1].runs)
						{
							temp = p1[j];
							p1[j] = p1[j + 1];
							p1[j + 1] = temp;
						}
					}
				}
				for(int i = 0; i < 3; i++)
				{
					printf("Jersy Number: %d\t\t",p1[i].JersyNumber);
					printf("Name: %s\t",p1[i].name);
					printf("Runs: %d\t",p1[i].runs);
					printf("Wickets: %d\t",p1[i].wicket);
					printf("Match Played: %d\n",p1[i].MatchPlayed);
				}
				break;
			}
		case 2:
			{
				printf("Top Three Wicket Taker:\n");
				Player temp;
				for(int i = 0; i < count-1; i++)
				{
					for(int j = 0; j < count-1; j++)
					{
						if(p1[j].wicket < p1[j + 1].wicket)
						{
							temp = p1[j];
							p1[j] = p1[j + 1];
							p1[j + 1] = temp;
						}
					}
				}
				for(int i = 0; i < 3; i++)
				{
					printf("Jersy Number: %d\t\t",p1[i].JersyNumber);
					printf("Name: %s\t",p1[i].name);
					printf("Runs: %d\t",p1[i].runs);
					printf("Wickets: %d\t",p1[i].wicket);
					printf("Match Played: %d\n",p1[i].MatchPlayed);
				}
				break;
			}
	}
}	