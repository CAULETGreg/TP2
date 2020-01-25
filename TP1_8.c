#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int attack ( int f ){
	
	int a;
	
	a = rand()% 15+5;
	a = a*f;
	
	return a;

}

int defense ( int a ){
	
	a = a / 4;
	
	return a;
	
}

int damage ( int a , int s , int pV ){
	
	if ( s == 1 ){
		
		pV = pV - a - 5;
	
	}
	
	else {
	
		pV = pV - a;
	
	} 
	
	return pV;
}

int poison ( int s ){
	
	s = 1;
	
	return s;
	
}


int main(void){
    
    srand(time(NULL));
    
    int attackMonster;
    int attackP1;
	int attackP2;
	int attackP3;
	int attackP4;
    int choiceP1;
	int choiceP2;
	int choiceP3;
	int choiceP4;
    int monsterChoice;
    int monsterState;
    int p1State = 0;
    int errorChoice;
	
		// caracteristique
		// normal
        int p1[2];
		// vie 
		p1[0] = 100;
		// mana
		p1[1] = 50;
		// force
		p1[2] = 3;
		
		// mage 
		int p2[2];
		p2[0] = 75; 
		p2[1] = 100;
		p2[2] = 1;
		
		// healer
		int p3[2];
		p3[0] = 100; 
		p3[1] = 75;
		p3[2] = 1;
		
		// tank
		int p4[2];
		p4[0] = 250; 
		p4[1] = 50;
		p4[2] = 2;
		
		int monster[2];
		monster[0] = 300;
		monster[1] = 80;
		monster[2] = 4;
		
	
	printf("Pv Monster : %d\n", monster[0]);
    printf("Mana Monster : %d\n", monster[1]);
    printf("Pv Player : %d\n", p1[0]);
    printf("Mana Player : %d\n", p1[1]);
	printf("Pv Player 2 : %d\n", p2[0]);
    printf("Mana Player 2 : %d\n", p2[1]);
	printf("Pv Player 3 : %d\n", p3[0]);
    printf("Mana Player 3 : %d\n", p3[1]);
	printf("Pv Player 4 : %d\n", p4[0]);
    printf("Mana Player 4 : %d\n", p4[1]);
	
    
    while ( monster[0] > 0 && ( p1[0] > 0 || p2[0] || p3[0] || p4[0] )){
		
	
		// texte choix actions 
        printf("Choose your action :\nAttack ( Enter 1 )\nDefend ( Enter 2 )\nPoison spell : mana cost 30 ( Enter 3 )\nAntidote : mana cost 25 ( Enter 4 )\n");
        
        // Issue with the State if invalid command damage of poison still occured
        // SOLVED with this variable
        errorChoice = 0;
        
        // Player choice
        scanf("%d", &choiceP1);
        scanf("%d", &choiceP2);
		scanf("%d", &choiceP3);
		scanf("%d", &choiceP4);
		
        // Choice of the monster
        monsterChoice = rand()%2+1;
        
        // Mana regeneration
        if ( p1[1] < p1[1] ){
            
            p1[1] = p1[1]++;
            
        }
        
        // If player is not poisoned the monster cast Poison
        if ( monster[1] >= 20 && p1State == 0 ){
            
            monsterChoice = 3;
            
        }
        
		// player turn
		
		// calcul des 2 attaques
		// parametres de la fonction "force"
		attackP1 = attack ( p1[2] );
		attackP2 = attack ( p2[2] );
		attackP3 = attack ( p3[2] );
		attackP4 = attack ( p4[2] );
		attackMonster = attack ( monster [2] );
		
		//defense
		if ( choiceP1 == 2 ){
			
			attackMonster = defense ( attackMonster );
			
			attackP1 = 0;
			
		}
		
		if ( choiceP2 == 2 ){
			
			attackMonster = defense ( attackMonster );
			
			attackP2 = 0;
			
		}
		
		if ( choiceP3 == 2 ){
			
			attackMonster = defense ( attackMonster );
			
			attackP3 = 0;
			
		}
		
		if ( choiceP4 == 2 ){
			
			attackMonster = defense ( attackMonster );
			
			attackP4 = 0;
			
		}
		
		// poison 
		if ( choiceP1 == 3 && p1[1] >= 30 ){
			
			monsterState = poison ( monsterState );
			p1[1] = p1[1] - 30;
			
			attackP1 = 0;
			
		}
		
		// antidote 
		
		if ( choiceP1 == 4 && p1[1] >= 25 ){
			
			p1State = 0;
			p1[1] = p1[1] - 25;
			
			attackP1 = 0;
			
		}
		
		
		// Monster turn
		
		if ( monsterChoice == 2 ){ 
			
			attackP1 = defense ( attackMonster );	
			attackP2 = defense ( attackMonster );
			attackP3 = defense ( attackMonster );
			attackP4 = defense ( attackMonster );
			
			attackMonster = 0;
			
		}
		
		if ( monsterChoice == 3 && monster[1] >= 20 && p1State == 0 ){
			
			p1State = poison ( p1State );
			monster[1] = monster[1] - 20;
			
			attackMonster = 0;
		
		}
		
		//calcul des dommage
		printf("Player 1 attack : - %d pv\n", attackP1);
		monster[0] = damage ( attackP1 , monsterState , monster[0] );
		printf("Pv Monster : %d\n", monster[0]);
		
		printf("Player 2 attack : - %d pv\n", attackP2);
		monster[0] = damage ( attackP2 , monsterState , monster[0] );
		printf("Pv Monster : %d\n", monster[0]);
		
		printf("Player 3 attack : - %d pv\n", attackP3);
		monster[0] = damage ( attackP3 , monsterState , monster[0] );
		printf("Pv Monster : %d\n", monster[0]);
		
		printf("Player 4 attack : - %d pv\n", attackP4);
		monster[0] = damage ( attackP4 , monsterState , monster[0] );
		printf("Pv Monster : %d\n", monster[0]);
		
		printf("Monster attack : - %d pv\n", attackMonster);
		p1[0] = damage ( attackMonster , p1State , p1[0] );
		printf("Pv Player : %d\n", p1[0]);
		
		printf("Recap :\n");
		printf("Pv Monster : %d\n", monster[0]);
        printf("Mana Monster : %d\n", monster[1]);
        printf("Pv Player 1 : %d\n", p1[0]);
        printf("Mana Player 1 : %d\n", p1[1]);
		printf("Pv Player 2 : %d\n", p2[0]);
        printf("Mana Player 2 : %d\n", p2[1]);
		printf("Pv Player 3 : %d\n", p3[0]);
        printf("Mana Player 3 : %d\n", p3[1]);
		printf("Pv Player 4 : %d\n", p4[0]);
        printf("Mana Player 4 : %d\n", p4[1]);
		
		// Monster death
        if ( monster[0] <= 0 ){
            attackMonster = 0;
            printf("You have slain the Monster.\n");
            
        }
        
        // Player death
        if ( p1[0] <= 0 ){
            attackP1 = 0;
            printf("Player 1 has been killed by the Monster.\n");
            
        }
		
        // PLAYER and MONSTER
                
        // Not enough mana Poison
        /*if ( choice == 3 && manaPlayer < 30 ){
            
            printf("Not enough mana.\n");
            errorChoice = 1;
        }
        
        // Not enough mana Antidote
        if ( choice == 4 && manaPlayer < 25 ){
            
            printf("Not enough mana.\n");
            errorChoice = 1;
        }
        
        // Poison and Poison 
        if ( choice == 3 && manaPlayer >= 30 && monsterChoice == 3 ){
            
            monsterState = 1;
            printf("Monster poisoned.\n");
            manaPlayer = manaPlayer - 30;
            
            playerState = 1;
            printf("Player poisoned.\n");
            manaMonster = manaMonster - 20;
            
        }
        
        // Attack and Poison 
        if ( choice == 1 && monsterChoice == 3 ){
            
            attackPlayer = rand()%20+5;
            printf("Player attack : - %d pv\n", attackPlayer);
            pvMonster = pvMonster - attackPlayer;
            
            playerState = 1;
            printf("Player poisoned.\n");
            manaMonster = manaMonster - 20;
            
        }
        
        // Defense and Poison
        if ( choice == 2 && monsterChoice == 3 ){
            
            playerState = 1;
            printf("Player poisoned.\n");
            manaMonster = manaMonster - 20;
            
        }
        
        // Antidote and Poison
        if ( choice == 4 && manaPlayer >= 25 && monsterChoice == 3 ){
            
            if ( playerState == 0 ){
                
                printf("You try to cure yourself but nothing happen.\n");
                manaPlayer = manaPlayer - 25;
            }
            
            if ( playerState == 1 ){
                
                playerState = 0;
                printf("You are cured.\n");
                manaPlayer = manaPlayer - 25;
                
            }
            
            playerState = 1;
            printf("Player poisoned.\n");
            manaMonster = manaMonster - 20;
            
        }
        
        // Antidote and Defense
        if ( choice == 4 && manaPlayer >= 25 && monsterChoice == 2 ){
            
            printf("Monster defend.\n");
            
            if ( playerState == 0 ){
                
                printf("You try to cure yourself but nothing happen.\n");
                manaPlayer = manaPlayer - 25;
            }
            
            if ( playerState == 1 ){
                
                playerState = 0;
                printf("You are cured.\n");
                manaPlayer = manaPlayer - 25;
                
            playerState = 1;
            printf("Player poisoned.\n");
            manaMonster = manaMonster - 20;
            
            }
        
        }
        
        // Antidote and Attack
        if ( choice == 4 && manaPlayer >= 25 && monsterChoice == 1 ){
            
            attackMonster = rand()%20+5;
            printf("Monster attack : - %d pv\n", attackMonster);
            pvPlayer = pvPlayer - attackMonster;
            
            if ( playerState == 0 ){
                
                printf("You try to cure yourself but nothing happen.\n");
                manaPlayer = manaPlayer - 25;
            }
            
            if ( playerState == 1 ){
                
                playerState = 0;
                printf("You are cured.\n");
                manaPlayer = manaPlayer - 25;
                
            }
        
        }
            
        // Poison and Attack
        if ( choice == 3 && manaPlayer >= 30 && monsterChoice == 1 ){
            
            attackMonster = rand()%20+5;
            printf("Monster attack : - %d pv\n", attackMonster);
            pvPlayer = pvPlayer - attackMonster;
            
            monsterState = 1;
            printf("Monster poisoned.\n");
            manaPlayer = manaPlayer - 30;
                
        }
        
        // Poison and Defense 
        if ( choice == 3 && manaPlayer >= 30 && monsterChoice == 2 ){
            
            printf("Monster defend.\n");
            
            monsterState = 1;
            printf("Monster poisoned.\n");
            manaPlayer = manaPlayer - 30;
            
        }
        
        // Attack and Attack 
        if ( choice == 1 && monsterChoice == 1 ){
        
            attackPlayer = rand()%20+5;
            printf("Player attack : - %d pv\n", attackPlayer);
            pvMonster = pvMonster - attackPlayer;

            attackMonster = rand()%20+5;
            printf("Monster attack : - %d pv\n", attackMonster);
            pvPlayer = pvPlayer - attackMonster;
            
        }
        
        // Defense and Attack 
        if ( choice == 2 && monsterChoice == 1 ){
            
            attackMonster = rand()%20+5;
            attackMonster = attackMonster / 4;
            printf("Reduced monster attack : - %d pv\n", attackMonster);
            pvPlayer = pvPlayer - attackMonster;
            
        }
        
        // Attack and Defense
        if ( choice == 1 && monsterChoice == 2 ){
            
            attackPlayer = rand()%20+5;
            attackPlayer = attackPlayer / 4;
            printf("Monster defend.\n");
            printf("Reduced player attack : - %d pv\n", attackPlayer);
            pvMonster = pvMonster - attackPlayer;
        
        }
        
        // Defense and Defense
        if ( choice == 2 && monsterChoice == 2 ){
            
            printf("Nothing happened.\n");
                
        }
        
        // Invalid choice
        if ( choice != 1 && choice != 2 && choice != 3 && choice != 4 ){
            
            printf("Invalid choice.\n");
            errorChoice = 0;
                
        }
        
        // Poison Damage on monster
        if ( monsterState == 1 && errorChoice == 0 ){
            
            pvMonster = pvMonster - 2;
            printf("Poison damage on monster : - 2 pv\n");
            
        }
        
        // Poison Damage on player
        if ( playerState == 1 && errorChoice == 0 ){
            
            pvPlayer = pvPlayer - 4;
            printf("Poison damage on player : - 4 pv\n");
            
        }
        
		
        // Recap of life and mana
        printf("Pv Monster : %d\n", pvMonster);
        printf("Mana Monster : %d\n", manaMonster);
        printf("Pv Player : %d\n", pvPlayer);
        printf("Mana Player : %d\n", manaPlayer);
        */
        
    }
    
    return 0;
}