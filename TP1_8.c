#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct GenerateAll { 

	int pv;
	int mana;
	int force;
	
	int state;
	int death;
	
	int choice;
	int target;
	
	int attack;
};

typedef struct GenerateAll generate;

int attack ( int f ){
	
	int a = rand()%20+1;
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
	
	int chooseYouMonster;
	printf("Enter a choice between 1 and 3\n"); 
	scanf("%d",&chooseYouMonster);
	
	if ( chooseYouMonster != 1 && chooseYouMonster != 1 && chooseYouMonster != 3 ){
		
		printf("Enter a choice between 1 and 3\n"); 
		scanf("%d",&chooseYouMonster);
		
	}
		
	generate m1 = {0,0,0,0,0,0,1,0};
	
	if ( chooseYouMonster == 1 ){
		
		//monster v3
		m1.pv = 500;
		m1.mana = 40;
		m1.force = 4;
	
	}
	
	if ( chooseYouMonster == 2 ){
		
		//monster v2
		m1.pv = 400;
		m1.mana = 100;
		m1.force = 5;
	
	}
	
	if ( chooseYouMonster == 3 ){
		
		//monster v1
		m1.pv = 200;
		m1.mana = 0;
		m1.force = 10;
		
	}
	
	
	
		// caracteristique
		// normal
		
		generate p1 = {150,0,3,0,0,0,0,0};
		
		// mage 
		generate p2 = {75,100,1,0,0,0,0,0};
		
		// healer
		generate p3 = {100,75,1,0,0,0,0,0};
		
		// tank
		generate p4 = {250,0,2,0,0,0,0,0};
		
		
		
	
	printf("Pv Monster : %d\n", m1.pv);
    printf("Mana Monster : %d\n", m1.mana);
    printf("Pv Player 1 : %d\n", p1.pv);
	printf("Pv Player 2 : %d\n", p2.pv);
    printf("Mana Player 2 : %d\n", p2.mana);
	printf("Pv Player 3 : %d\n", p3.pv);
    printf("Mana Player 3 : %d\n", p3.mana);
	printf("Pv Player 4 : %d\n", p4.pv);
	
    
    while ( m1.pv > 0 && ( p1.pv > 0 || p2.pv > 0 || p3.pv > 0 || p4.pv > 0 )){
		
	
		// texte choix actions 
        printf("Choose your action :\nAttack ( Enter 1 )\nDefend ( Enter 2 )\nPoison spell : mana cost 30 ( Enter 3 )\nAntidote : mana cost 25 ( Enter 4 )\n");
        
        
        // Player choice
		if ( p1.death == 0 ){
			
			scanf("%d", &p1.choice);
			
			// calcul attaque
			// parametres de la fonction "force"
			p1.attack = attack( p1.force );
			
		}
		
        if ( p2.death == 0 ){
			
			scanf("%d", &p2.choice);
			
			// Mana regeneration
			if ( p2.mana < p2.mana ){
				
				p2.mana = p2.mana++;
            
			}
			
			p2.attack = attack( p2.force );
			
		}
		
		if ( p3.death == 0 ){
			
			scanf("%d", &p3.choice);
			
			if ( p3.mana < p3.mana ){
            
				p3.mana = p3.mana++;
            
			}
			
			p3.attack = attack( p3.force );
			
		}
		
		if ( p4.death == 0 ){
			
			scanf("%d", &p4.choice);
			
			p4.attack = attack( p4.force );
			
		}
		
		if ( m1.death == 0 ){
		
			// Choice of the monster
			m1.choice = rand()%2+1;
        
			// If player is not poisoned the monster cast Poison
			if ( m1.mana >= 20 && p1.state == 0 && p1.death == 0 ){
            
				m1.choice = 3;
            
			}
        
			m1.attack = attack( m1.force );
		
		}
		
		// player turn
		//defense
		if ( p1.choice == 2 ){
			
			m1.attack = defense ( m1.attack );
			
			p1.attack = 0;
			
		}
		
		if ( p2.choice == 2 ){
			
			m1.attack = defense ( m1.attack );
			
			p2.attack = 0;
			
		}
		
		if ( p3.choice == 2 ){
			
			m1.attack = defense ( m1.attack );
			
			p3.attack = 0;
			
		}
		
		if ( p3.choice == 2 ){
			
			m1.attack = defense ( m1.attack );
			
			p3.attack = 0;
			
		}
		
		// poison 
		if ( p2.choice == 3 && p2.mana >= 30 ){
			
			m1.state = poison ( m1.state );
			p2.mana -= 30;
			
			p2.attack = 0;
			
		}
		
		// antidote 
		
		if ( p3.choice == 4 && p3.mana >= 25 ){
			
			printf("Choose target :\n");
			scanf("%d", &p3.target);
			
			if ( p3.target == 1 ){
				
				p1.state = 0;
				
			}
			
			if ( p3.target == 2 ){
				
				p2.state = 0;
				
			}
			
			if ( p3.target == 3 ){
				
				p3.state = 0;
				
			}
			
			if ( p3.target == 4 ){
				
				p4.state = 0;
				
			}
			
			p3.mana = p3.mana - 25;
			
			p3.attack = 0;
			
		}
		
		
		// Monster turn
		
		if ( m1.choice == 2 ){ 
			
			p1.attack = defense ( p1.attack );	
			p2.attack = defense ( p2.attack );
			p3.attack = defense ( p3.attack );
			p4.attack = defense ( p4.attack );
			
			m1.attack = 0;
			
		}
		
		if ( m1.choice == 3 && m1.mana >= 20 ){
			
			p1.state = poison ( p1.state );
			m1.mana -= 20;
			
			m1.attack = 0;
		
		}
		
		//calcul des dommage
		
		// damage by player
		printf("Player 1 attack : - %d pv\n", p1.attack);
		m1.pv = damage ( p1.attack , m1.state , m1.pv );
		printf("Pv Monster : %d\n", m1.pv );
		
		printf("Player 2 attack : - %d pv\n", p2.attack);
		m1.pv = damage ( p2.attack , m1.state , m1.pv );
		printf("Pv Monster : %d\n", m1.pv );
		
		printf("Player 3 attack : - %d pv\n", p3.attack);
		m1.pv = damage ( p3.attack , m1.state , m1.pv );
		printf("Pv Monster : %d\n", m1.pv );
		
		printf("Player 4 attack : - %d pv\n", p4.attack);
		m1.pv = damage ( p4.attack , m1.state , m1.pv );
		printf("Pv Monster : %d\n", m1.pv );
		
		// damage by monster
		if ( m1.target == 1 ){
		
			printf("Monster attack : - %d pv\n", m1.attack);
			p1.pv = damage ( m1.attack , p1.state , p1.pv );
			printf("Pv Player 1 : %d\n", p1.pv);
		
		}
		
		if ( m1.target == 2 ){
		
			printf("Monster attack : - %d pv\n", m1.attack);
			p2.pv = damage ( m1.attack , p2.state , p2.pv );
			printf("Pv Player 1 : %d\n", p2.pv);
		
		}
		
		if ( m1.target == 3 ){
		
			printf("Monster attack : - %d pv\n", m1.attack);
			p3.pv = damage ( m1.attack , p3.state , p3.pv );
			printf("Pv Player 1 : %d\n", p3.pv);
		
		}
		
		if ( m1.target == 4 ){
		
			printf("Monster attack : - %d pv\n", m1.attack);
			p4.pv = damage ( m1.attack , p4.state , p4.pv );
			printf("Pv Player 1 : %d\n", p4.pv);
		
		}
		
		printf("Recap :\n");
		printf("Pv Monster : %d\n", m1.pv);
		printf("Mana Monster : %d\n", m1.mana);
		printf("Pv Player 1 : %d\n", p1.pv);
		printf("Pv Player 2 : %d\n", p2.pv);
		printf("Mana Player 2 : %d\n", p2.mana);
		printf("Pv Player 3 : %d\n", p3.pv);
		printf("Mana Player 3 : %d\n", p3.mana);
		printf("Pv Player 4 : %d\n", p4.pv);
		
		
		// Monster death
        if ( m1.pv <= 0 ){
            m1.attack = 0;
            printf("You have slain the Monster.\n");
			m1.death = 1;
            
        }
        
        // Player death
        if ( p1.pv <= 0 && p1.death == 0 ){
            p1.attack = 0;
            printf("Player 1 has been killed by the Monster.\n");
			p1.death = 1;
			m1.target += 1;
            
        }
		
		if ( p2.pv <= 0 && p2.death == 0 ){
            p2.attack = 0;
            printf("Player 2 has been killed by the Monster.\n");
			p2.death = 1;
			m1.target += 1;
            
        }
		
		if ( p3.pv <= 0 && p3.death == 0 ){
            p3.attack = 0;
            printf("Player 3 has been killed by the Monster.\n");
			p3.death = 1;
			m1.target += 1;
            
        }
		
		if ( p4.pv <= 0 && p4.death == 0 ){
            p4.attack = 0;
            printf("Player 4 has been killed by the Monster.\n");
			p4.death = 1;
			m1.target += 1;
            
        }
		
        
    }
  
  return 0;
}