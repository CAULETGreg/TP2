#include<stdio.h>

#include<stdlib.h>

#include<time.h>



int attack ( int a ){

	

	a = rand()% 20+10;

	

	return a;



}



int defense (int a){

	

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

// Healing Function <=========================================================================================================

int heal (int Pp){



	Pp = Pp+25;



	return Pp;

}

//Antidote Function <=========================================================================================================

int antidote (int PState){



	PState = 0;



	return PState;


}

//Fire Ball (Mage Skill) <=========================================================================================================

int fire (int fi){



	fi = fi + 10;



	return fi;

}





int main(void){

    

    srand(time(NULL));

    

    int attackMonster;

    int attackPlayer;

    int pvMonster = 100;

    int pvPlayer = 150;

    int choice;

    int monsterChoice;

    int manaPlayer = 50;

    int monsterState;

    int manaMonster = 40;

    int playerState = 0;

    int errorChoice;





    //Pour visibilité

    /*

    printf("Pv Monster : %d\n", pvMonster);

    printf("Mana Monster : %d\n\n", manaMonster);

    printf("Pv Player : %d\n", pvPlayer);

    printf("Mana Player : %d\n\n", manaPlayer);

    

    while ( pvMonster > 0 && pvPlayer > 0 ){

        

        printf("Choose your action :\nAttack ( Enter 1 )\nDefend ( Enter 2 )\nPoison spell : mana cost 30 ( Enter 3 )\nAntidote : mana cost 25 ( Enter 4 )\n");

        

        // Issue with the State if invalid command damage of poison still occured

        // SOLVED with this variable

        errorChoice = 0;

        

        // Player choice

        scanf("%d", &choice);

        

        // Choice of the monster

        monsterChoice = rand()%2+1;

        

        // Mana regeneration

        if ( manaPlayer < 50 ){

            

            manaPlayer = manaPlayer + 1;

            

        }

        

        // If player is not poisoned the monster cast Poison

        if ( manaMonster > 20 && playerState == 0 ){

            

            monsterChoice = 3;

            

        }

        

		// player turn

		

		// calcul des 2 attaques

		attackPlayer = attack ( attackPlayer );

		attackMonster = attack ( attackMonster );

		

		//defense

		if ( choice == 2 ){

			

			attackMonster = defense ( attackMonster );

			

			attackPlayer = 0;

			

		}

		

		// poison 

		if ( choice == 3 && manaPlayer >= 30 ){

			

			monsterState = poison ( monsterState );

			manaPlayer = manaPlayer - 30;

			

			attackPlayer = 0;

			

		}

		

		// antidote 

		

		if ( choice == 4 && manaPlayer >= 25 ){

			

			playerState = 0;

			manaPlayer = manaPlayer - 25;

			

			attackPlayer = 0;

			

		}

		

		

		// Monster turn

		

		if ( monsterChoice == 2 ){ 

			

			attackPlayer = defense ( attackMonster );	

			

			attackMonster = 0;

			

		}

		

		if ( monsterChoice == 3 && manaMonster >= 20 && playerState == 0 ){

			

			playerState = poison ( playerState );

			manaMonster = manaMonster - 20;

			

			attackMonster = 0;

		

		}

		

		//calcul des dommage

		printf("Player attack : - %d pv\n", attackPlayer);

		pvMonster = damage ( attackPlayer , monsterState , pvMonster );

		printf("Pv Monster : %d\n", pvMonster);

		

		printf("Monster attack : - %d pv\n", attackMonster);

		pvPlayer = damage ( attackMonster , playerState , pvPlayer );

		printf("Pv Player : %d\n", pvPlayer);

		

		printf("Recap :\n");

		printf("Pv Monster : %d\n", pvMonster);

        printf("Mana Monster : %d\n", manaMonster);

        printf("Pv Player : %d\n", pvPlayer);

        printf("Mana Player : %d\n", manaPlayer);

		

		

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

        // Monster death

        if ( pvMonster <= 0 ){

            attackMonster = 0;

            printf("You have slain the Monster.\n");

            

        }

        

        // Player death

        if ( pvPlayer <= 0 ){

            attackPlayer = 0;

            printf("You have been killed by the Monster.\n");

            

        }

        

    }

    

    return 0;

