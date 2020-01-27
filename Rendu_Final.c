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
	int xp;
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
	
	int chooseYouMonster;
	printf("Enter a choice between 1 and 3\n"); 
	scanf("%d",&chooseYouMonster);
	
	if ( chooseYouMonster != 1 && chooseYouMonster != 2 && chooseYouMonster != 3 ){
		
		printf("Enter a choice between 1 and 3\n"); 
		scanf("%d",&chooseYouMonster);
		
	}
		
	generate m1 = {0,0,0,0,0,0,1,0,0};
	generate m2 = {0,0,0,0,0,0,1,0,0};
	generate m3 = {0,0,0,0,0,0,1,0,0};
	generate m4 = {0,0,0,0,0,0,1,0,0};
	
	if ( chooseYouMonster == 1 ){
		
		//monster v3
		m1.pv = 150;
		m1.mana = 40;
		m1.force = 2;
		
		m2.pv = 80;
		m2.mana = 60;
		m2.force = 1;
		
		m3.pv = 100;
		m3.mana = 0;
		m3.force = 4;
		
		m4.pv = 200;
		m4.mana = 0;
		m4.force = 3;
	
	}
	
	if ( chooseYouMonster == 2 ){
		
		//monster v2
		m1.pv = 75;
		m1.mana = 100;
		m1.force = 1;
		
		m2.pv = 250;
		m2.mana = 0;
		m2.force = 2;
		
		m3.pv = 500;
		m3.mana = 0;
		m3.force = 1;
		
		m4.pv = 40;
		m4.mana = 0;
		m4.force = 10;
	
	}
	
	if ( chooseYouMonster == 3 ){
		
		//monster v1
		m1.pv = 50;
		m1.mana = 100;
		m1.force = 1;
		
		m2.pv = 100;
		m2.mana = 0;
		m2.force = 3;
		
		m3.pv = 250;
		m3.mana = 0;
		m3.force = 2;
		
		m4.pv = 50;
		m4.mana = 0;
		m4.force = 10;
		
	}
	
	
	
		// caracteristique
		// normal
		
		generate p1 = {150,0,3,0,0,0,0,0,0};
		
		// mage 
		generate p2 = {75,100,1,0,0,0,0,0,0};
		
		// healer
		generate p3 = {100,75,1,0,0,0,0,0,0};
		
		// tank
		generate p4 = {250,0,2,0,0,0,0,0,0};
		
		
		
	
	printf("Pv Monster 1 : %d\n", m1.pv);
    printf("Mana Monster 1 : %d\n", m1.mana);
	printf("Pv Monster 2 : %d\n", m2.pv);
    printf("Mana Monster 2 : %d\n", m2.mana);
	printf("Pv Monster 3 : %d\n", m3.pv);
	printf("Pv Monster 4 : %d\n", m4.pv);
    printf("Pv Player 1 : %d\n", p1.pv);
	printf("Pv Player 2 : %d\n", p2.pv);
    printf("Mana Player 2 : %d\n", p2.mana);
	printf("Pv Player 3 : %d\n", p3.pv);
    printf("Mana Player 3 : %d\n", p3.mana);
	printf("Pv Player 4 : %d\n", p4.pv);
	
    
    while ( m1.pv > 0 || m2.pv > 0 || m3.pv > 0 || m4.pv > 0 && p1.pv > 0 || p2.pv > 0 || p3.pv > 0 || p4.pv > 0 ){
        
        // Player choice
		if ( p1.death == 0 ){
			
			// texte choix actions 
			
			printf("Player 1 action :\nAttack ( Enter 1 )\nDefend ( Enter 2 )\n");
			scanf("%d", &p1.choice);
			
			// calcul attaque
			// parametres de la fonction "force"
			p1.attack = attack( p1.force );
			
			if ( p1.choice != 2 ){
				
				printf("Choose target :\n");
				scanf("%d", &p1.target);
			
			}
			
		}
		
        if ( p2.death == 0 ){
			 
			printf("Player 2 action :\nAttack ( Enter 1 )\nDefend ( Enter 2 )\nPoison spell : mana cost 30 ( Enter 3 )\n");
			scanf("%d", &p2.choice);
			
			// Mana regeneration
			if ( p2.mana < p2.mana ){
				
				p2.mana = p2.mana++;
            
			}
			
			p2.attack = attack( p2.force );
			
			if ( p2.choice != 2 ){
				
				printf("Choose target :\n");
				scanf("%d", &p2.target);
			
			}
			
		}
		
		if ( p3.death == 0 ){
			
			printf("Player 3 action :\nAttack ( Enter 1 )\nDefend ( Enter 2 )\nAntidote : mana cost 25 ( Enter 3 )\n");
			scanf("%d", &p3.choice);
			
			if ( p3.mana < p3.mana ){
            
				p3.mana = p3.mana++;
            
			}
			
			p3.attack = attack( p3.force );
			
			if ( p3.choice != 2 ){
				
				printf("Choose target :\n");
				scanf("%d", &p3.target);
			
			}
			
		}
		
		if ( p4.death == 0 ){
			
			printf("Player 4 action :\nAttack ( Enter 1 )\nDefend ( Enter 2 )\n");
			scanf("%d", &p4.choice);
			
			p4.attack = attack( p4.force );
			
			if ( p4.choice != 2 ){
				
				printf("Choose target :\n");
				scanf("%d", &p4.target);
			
			}
			
		}
		
		if ( m1.death == 0 ){
		
			// Choice of the monster
			m1.choice = rand()%2+1;
        
			// If player is not poisoned the monster cast Poison
			if ( m1.mana >= 20 && p1.state == 0 && p1.death == 0 && m1.target == 1 ){
            
				m1.choice = 3;
            
			}
			
			if ( m1.mana >= 20 && p2.state == 0 && p2.death == 0 && m1.target == 2 ){
            
				m1.choice = 3;
            
			}
			
			if ( m1.mana >= 20 && p3.state == 0 && p3.death == 0 && m1.target == 3 ){
            
				m1.choice = 3;
            
			}
			
			if ( m1.mana >= 20 && p4.state == 0 && p4.death == 0 && m1.target == 4 ){
            
				m1.choice = 3;
            
			}
        
			m1.attack = attack( m1.force );
		
		}
		
		if ( m2.death == 0 ){
		
			// Choice of the monster
			m2.choice = rand()%2+1;
        
			// If player is not poisoned the monster cast Poison
			if ( m2.mana >= 20 && p1.state == 0 && p1.death == 0 && m2.target == 1 ){
            
				m2.choice = 3;
            
			}
			
			if ( m2.mana >= 20 && p2.state == 0 && p2.death == 0 && m2.target == 2 ){
            
				m2.choice = 3;
            
			}
			
			if ( m2.mana >= 20 && p3.state == 0 && p3.death == 0 && m2.target == 3 ){
            
				m2.choice = 3;
            
			}
			
			if ( m2.mana >= 20 && p4.state == 0 && p4.death == 0 && m2.target == 4 ){
            
				m2.choice = 3;
            
			}
        
			m2.attack = attack( m2.force );
		
		}
		
		if ( m3.death == 0 ){
		
			// Choice of the monster
			m3.choice = rand()%2+1;
			m3.attack = attack( m2.force );
		
		}
		
		if ( m4.death == 0 ){
		
			// Choice of the monster
			m4.choice = rand()%2+1;
        
			m4.attack = attack( m4.force );
		
		}
		
		// player turn
		//defense
		if ( p1.choice == 2 && m1.target == 1 ){
			
			m1.attack = defense ( m1.attack );
			
			p1.attack = 0;
			
		}
		
		if ( p1.choice == 2 && m2.target == 1 ){
			
			m2.attack = defense ( m2.attack );
			
			p1.attack = 0;
			
		}
		
		if ( p1.choice == 2 && m3.target == 1 ){
			
			m3.attack = defense ( m3.attack );
			
			p1.attack = 0;
			
		}
		
		if ( p1.choice == 2 && m4.target == 1 ){
			
			m4.attack = defense ( m4.attack );
			
			p1.attack = 0;
			
		}
		
		if ( p2.choice == 2 && m1.target == 2 ){
			
			m1.attack = defense ( m1.attack );
			
			p2.attack = 0;
			
		}
		
		if ( p2.choice == 2 && m2.target == 2 ){
			
			m2.attack = defense ( m2.attack );
			
			p2.attack = 0;
			
		}
		
		if ( p2.choice == 2 && m3.target == 2 ){
			
			m3.attack = defense ( m3.attack );
			
			p2.attack = 0;
			
		}
		
		if ( p2.choice == 2 && m4.target == 2 ){
			
			m4.attack = defense ( m4.attack );
			
			p2.attack = 0;
			
		}
		
		if ( p3.choice == 2 && m1.target == 3 ){
			
			m1.attack = defense ( m1.attack );
			
			p3.attack = 0;
			
		}
		
		if ( p3.choice == 2 && m2.target == 3 ){
			
			m2.attack = defense ( m2.attack );
			
			p3.attack = 0;
			
		}
		
		if ( p3.choice == 2 && m3.target == 3 ){
			
			m3.attack = defense ( m3.attack );
			
			p3.attack = 0;
			
		}
		
		if ( p3.choice == 2 && m4.target == 3 ){
			
			m4.attack = defense ( m4.attack );
			
			p3.attack = 0;
			
		}
		
		if ( p4.choice == 2 && m1.target == 4 ){
			
			m1.attack = defense ( m1.attack );
			
			p4.attack = 0;
			
		}
		
		if ( p4.choice == 2 && m2.target == 4 ){
			
			m2.attack = defense ( m2.attack );
			
			p4.attack = 0;
			
		}
		
		if ( p4.choice == 2 && m3.target == 4 ){
			
			m3.attack = defense ( m3.attack );
			
			p4.attack = 0;
			
		}
		
		if ( p4.choice == 2 && m4.target == 4 ){
			
			m4.attack = defense ( m4.attack );
			
			p4.attack = 0;
			
		}
		
		// poison 
		if ( p2.choice == 3 && p2.mana >= 30 ){
			
			if ( p2.target == 1 ){
				
				m1.state = poison ( m1.state );
				
			}
		
			if ( p2.target == 2 ){
				
				m2.state = poison ( m2.state );
				
			}
			
			if ( p2.target == 3 ){
				
				m3.state = poison ( m3.state );
				
			}
			
			if ( p2.target == 4 ){
				
				m4.state = poison ( m4.state );
				
			}
			
			p2.mana -= 30;
			
			p2.attack = 0;
			
		}
		
		// antidote 
		
		if ( p3.choice == 3 && p3.mana >= 25 ){
			
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
		
		if ( m1.choice == 2 && p1.target == 1 ){ 
			
			p1.attack = defense ( p1.attack );	
			
			m1.attack = 0;
			
		}
		
		if ( m1.choice == 2 && p2.target == 1 ){ 
			
			p2.attack = defense ( p2.attack );	
			
			m1.attack = 0;
			
		}
		
		if ( m1.choice == 2 && p3.target == 1 ){ 
			
			p3.attack = defense ( p3.attack );	
			
			m1.attack = 0;
			
		}
		
		if ( m1.choice == 2 && p4.target == 1 ){ 
			
			p4.attack = defense ( p4.attack );	
			
			m1.attack = 0;
			
		}
		
		if ( m2.choice == 2 && p1.target == 2 ){ 
			
			p1.attack = defense ( p1.attack );	
			
			m2.attack = 0;
			
		}
		
		if ( m2.choice == 2 && p2.target == 2 ){ 
			
			p2.attack = defense ( p2.attack );	
			
			m1.attack = 0;
			
		}
		
		if ( m2.choice == 2 && p3.target == 2 ){ 
			
			p3.attack = defense ( p3.attack );	
			
			m2.attack = 0;
			
		}
		
		if ( m2.choice == 2 && p4.target == 2 ){ 
			
			p4.attack = defense ( p4.attack );	
			
			m2.attack = 0;
			
		}
		
		if ( m3.choice == 2 && p1.target == 3 ){ 
			
			p1.attack = defense ( p1.attack );	
			
			m3.attack = 0;
			
		}
		
		if ( m3.choice == 2 && p2.target == 3 ){ 
			
			p2.attack = defense ( p2.attack );	
			
			m3.attack = 0;
			
		}
		
		if ( m3.choice == 2 && p3.target == 3 ){ 
			
			p3.attack = defense ( p3.attack );	
			
			m3.attack = 0;
			
		}
		
		if ( m3.choice == 2 && p4.target == 3 ){ 
			
			p4.attack = defense ( p4.attack );	
			
			m3.attack = 0;
			
		}
		
		if ( m4.choice == 2 && p1.target == 4 ){ 
			
			p1.attack = defense ( p1.attack );	
			
			m4.attack = 0;
			
		}
		
		if ( m4.choice == 2 && p2.target == 4 ){ 
			
			p2.attack = defense ( p2.attack );	
			
			m4.attack = 0;
			
		}
		
		if ( m4.choice == 2 && p3.target == 4 ){ 
			
			p3.attack = defense ( p3.attack );	
			
			m4.attack = 0;
			
		}
		
		if ( m4.choice == 2 && p4.target == 4 ){ 
			
			p4.attack = defense ( p4.attack );	
			
			m4.attack = 0;
			
		}
		// poison 
		if ( m1.choice == 3 && m1.mana >= 20 && m1.target == 1 ){
			
			p1.state = poison ( p1.state );
			m1.mana -= 20;
			
			m1.attack = 0;
		
		}
		
		if ( m1.choice == 3 && m1.mana >= 20 && m1.target == 2 ){
			
			p2.state = poison ( p2.state );
			m1.mana -= 20;
			
			m1.attack = 0;
		
		}
		
		if ( m1.choice == 3 && m1.mana >= 20 && m1.target == 3 ){
			
			p3.state = poison ( p3.state );
			m1.mana -= 20;
			
			m1.attack = 0;
		
		}
		
		if ( m1.choice == 3 && m1.mana >= 20 && m1.target == 4 ){
			
			p4.state = poison ( p4.state );
			m1.mana -= 20;
			
			m1.attack = 0;
		
		}
		
		if ( m2.choice == 3 && m2.mana >= 20 && m2.target == 1 ){
			
			p1.state = poison ( p1.state );
			m2.mana -= 20;
			
			m2.attack = 0;
		
		}
		
		if ( m2.choice == 3 && m2.mana >= 20 && m2.target == 2 ){
			
			p2.state = poison ( p2.state );
			m2.mana -= 20;
			
			m2.attack = 0;
		
		}
		
		if ( m2.choice == 3 && m2.mana >= 20 && m2.target == 3 ){
			
			p3.state = poison ( p3.state );
			m2.mana -= 20;
			
			m2.attack = 0;
		
		}
		
		if ( m2.choice == 3 && m2.mana >= 20 && m2.target == 4 ){
			
			p4.state = poison ( p4.state );
			m2.mana -= 20;
			
			m2.attack = 0;
		
		}
		

		
		//calcul des dommage
		
		// damage by player
		if ( p1.target == 1 ){
			
			printf("Player 1 attack : - %d pv\n", p1.attack);
			m1.pv = damage ( p1.attack , m1.state , m1.pv );
			printf("Pv Monster 1 : %d\n", m1.pv );
			
		}
		
		if ( p1.target == 2 ){
			
			printf("Player 1 attack : - %d pv\n", p1.attack);
			m2.pv = damage ( p1.attack , m2.state , m2.pv );
			printf("Pv Monster 2 : %d\n", m2.pv );
			
		}
		
		if ( p1.target == 3 ){
			
			printf("Player 1 attack : - %d pv\n", p1.attack);
			m3.pv = damage ( p1.attack , m3.state , m3.pv );
			printf("Pv Monster 3 : %d\n", m3.pv );
			
		}
		
		if ( p1.target == 4 ){
			
			printf("Player 1 attack : - %d pv\n", p1.attack);
			m4.pv = damage ( p1.attack , m4.state , m4.pv );
			printf("Pv Monster 4 : %d\n", m4.pv );
			
		}
		
		if ( p2.target == 1 ){
			
			printf("Player 2 attack : - %d pv\n", p2.attack);
			m1.pv = damage ( p2.attack , m1.state , m1.pv );
			printf("Pv Monster 1 : %d\n", m1.pv );
			
		}
		
		if ( p2.target == 2 ){
			
			printf("Player 2 attack : - %d pv\n", p2.attack);
			m2.pv = damage ( p2.attack , m2.state , m2.pv );
			printf("Pv Monster 2 : %d\n", m2.pv );
			
		}
		
		if ( p2.target == 3 ){
			
			printf("Player 2 attack : - %d pv\n", p2.attack);
			m3.pv = damage ( p2.attack , m3.state , m3.pv );
			printf("Pv Monster 3 : %d\n", m3.pv );
			
		}
		
		if ( p2.target == 4 ){
			
			printf("Player 2 attack : - %d pv\n", p2.attack);
			m4.pv = damage ( p2.attack , m4.state , m4.pv );
			printf("Pv Monster 4 : %d\n", m4.pv );
			
		}
		
		if ( p3.target == 1 ){
			
			printf("Player 3 attack : - %d pv\n", p3.attack);
			m1.pv = damage ( p3.attack , m1.state , m1.pv );
			printf("Pv Monster 1 : %d\n", m1.pv );
			
		}
		
		if ( p3.target == 2 ){
			
			printf("Player 3 attack : - %d pv\n", p3.attack);
			m2.pv = damage ( p3.attack , m2.state , m2.pv );
			printf("Pv Monster 2 : %d\n", m2.pv );
			
		}
		
		if ( p3.target == 3 ){
			
			printf("Player 3 attack : - %d pv\n", p3.attack);
			m3.pv = damage ( p3.attack , m3.state , m3.pv );
			printf("Pv Monster 3 : %d\n", m3.pv );
			
		}
		
		if ( p3.target == 4 ){
			
			printf("Player 3 attack : - %d pv\n", p3.attack);
			m4.pv = damage ( p3.attack , m4.state , m4.pv );
			printf("Pv Monster 4 : %d\n", m4.pv );
			
		}
		
		if ( p4.target == 1 ){
			
			printf("Player 4 attack : - %d pv\n", p4.attack);
			m1.pv = damage ( p4.attack , m1.state , m1.pv );
			printf("Pv Monster 1 : %d\n", m1.pv );
			
		}
		
		if ( p4.target == 2 ){
			
			printf("Player 4 attack : - %d pv\n", p4.attack);
			m2.pv = damage ( p4.attack , m2.state , m2.pv );
			printf("Pv Monster 2 : %d\n", m2.pv );
			
		}
		
		if ( p4.target == 3 ){
			
			printf("Player 4 attack : - %d pv\n", p4.attack);
			m3.pv = damage ( p4.attack , m3.state , m3.pv );
			printf("Pv Monster 3 : %d\n", m3.pv );
			
		}
		
		if ( p4.target == 4 ){
			
			printf("Player 4 attack : - %d pv\n", p4.attack);
			m4.pv = damage ( p4.attack , m4.state , m4.pv );
			printf("Pv Monster 4 : %d\n", m4.pv );
			
		}
		
		
		
		
		// damage by monster
		if ( m1.target == 1 ){
		
			printf("Monster 1 attack : - %d pv\n", m1.attack);
			p1.pv = damage ( m1.attack , p1.state , p1.pv );
			printf("Pv Player 1 : %d\n", p1.pv);
		
		}
		
		if ( m1.target == 2 ){
		
			printf("Monster 1 attack : - %d pv\n", m1.attack);
			p2.pv = damage ( m1.attack , p2.state , p2.pv );
			printf("Pv Player 2 : %d\n", p2.pv);
		
		}
		
		if ( m1.target == 3 ){
		
			printf("Monster 1 attack : - %d pv\n", m1.attack);
			p3.pv = damage ( m1.attack , p3.state , p3.pv );
			printf("Pv Player 3 : %d\n", p3.pv);
		
		}
		
		if ( m1.target == 4 ){
		
			printf("Monster 1 attack : - %d pv\n", m1.attack);
			p4.pv = damage ( m1.attack , p4.state , p4.pv );
			printf("Pv Player 4 : %d\n", p4.pv);
		
		}
		
		if ( m2.target == 1 ){
		
			printf("Monster 2 attack : - %d pv\n", m2.attack);
			p1.pv = damage ( m2.attack , p1.state , p1.pv );
			printf("Pv Player 1 : %d\n", p1.pv);
		
		}
		
		if ( m2.target == 2 ){
		
			printf("Monster 2 attack : - %d pv\n", m2.attack);
			p2.pv = damage ( m2.attack , p2.state , p2.pv );
			printf("Pv Player 2 : %d\n", p2.pv);
		
		}
		
		if ( m2.target == 3 ){
		
			printf("Monster 2 attack : - %d pv\n", m2.attack);
			p3.pv = damage ( m2.attack , p3.state , p3.pv );
			printf("Pv Player 3 : %d\n", p3.pv);
		
		}
		
		if ( m2.target == 4 ){
		
			printf("Monster 2 attack : - %d pv\n", m2.attack);
			p4.pv = damage ( m2.attack , p4.state , p4.pv );
			printf("Pv Player 4 : %d\n", p4.pv);
		
		}
		
		if ( m3.target == 1 ){
		
			printf("Monster 3 attack : - %d pv\n", m3.attack);
			p1.pv = damage ( m3.attack , p1.state , p1.pv );
			printf("Pv Player 1 : %d\n", p1.pv);
		
		}
		
		if ( m3.target == 2 ){
		
			printf("Monster 3 attack : - %d pv\n", m3.attack);
			p2.pv = damage ( m3.attack , p2.state , p2.pv );
			printf("Pv Player 2 : %d\n", p2.pv);
		
		}
		
		if ( m3.target == 3 ){
		
			printf("Monster 3 attack : - %d pv\n", m3.attack);
			p3.pv = damage ( m3.attack , p3.state , p3.pv );
			printf("Pv Player 3 : %d\n", p3.pv);
		
		}
		
		if ( m3.target == 4 ){
		
			printf("Monster 3 attack : - %d pv\n", m3.attack);
			p4.pv = damage ( m3.attack , p4.state , p4.pv );
			printf("Pv Player 4 : %d\n", p4.pv);
		
		}
		
		if ( m4.target == 1 ){
		
			printf("Monster 4 attack : - %d pv\n", m4.attack);
			p1.pv = damage ( m4.attack , p1.state , p1.pv );
			printf("Pv Player 1 : %d\n", p1.pv);
		
		}
		
		if ( m4.target == 2 ){
		
			printf("Monster 4 attack : - %d pv\n", m4.attack);
			p2.pv = damage ( m4.attack , p2.state , p2.pv );
			printf("Pv Player 2 : %d\n", p2.pv);
		
		}
		
		if ( m4.target == 3 ){
		
			printf("Monster attack 4 : - %d pv\n", m4.attack);
			p3.pv = damage ( m4.attack , p3.state , p3.pv );
			printf("Pv Player 3 : %d\n", p3.pv);
		
		}
		
		if ( m4.target == 4 ){
		
			printf("Monster 4 attack : - %d pv\n", m4.attack);
			p4.pv = damage ( m1.attack , p4.state , p4.pv );
			printf("Pv Player 4 : %d\n", p4.pv);
		
		}
		
		
		
		printf("Recap :\n");
		printf("Pv Monster 1 : %d\n", m1.pv);
		printf("Mana Monster 1 : %d\n", m1.mana);
		printf("Pv Monster 2 : %d\n", m2.pv);
		printf("Mana Monster 2 : %d\n", m2.mana);
		printf("Pv Monster 3 : %d\n", m3.pv);
		printf("Pv Monster 4 : %d\n", m4.pv);
		printf("Pv Player 1 : %d\n", p1.pv);
		printf("Pv Player 2 : %d\n", p2.pv);
		printf("Mana Player 2 : %d\n", p2.mana);
		printf("Pv Player 3 : %d\n", p3.pv);
		printf("Mana Player 3 : %d\n", p3.mana);
		printf("Pv Player 4 : %d\n", p4.pv);
		
		
		// Monster death + Upgrading stats when players gain a level
        if ( m1.pv <= 0 ){
            m1.attack = 0;
            printf("You have slain the Monster.\n");
			m1.death = 1;

        }
		
		if ( m2.pv <= 0 ){
            m2.attack = 0;
            printf("You have slain the Monster 2.\n");
			m2.death = 1;
            
        }
		
		if ( m3.pv <= 0 ){
            m3.attack = 0;
            printf("You have slain the Monster 3.\n");
			m3.death = 1;
            
        }
		
		if ( m4.pv <= 0 ){
            m4.attack = 0;
            printf("You have slain the Monster 4.\n");
			m4.death = 1;
            
        }

         if ( m1.pv <= 0 && m2.pv <= 0 && m3.pv <= 0 && m4.pv <= 0){
            m1.attack = 0;
            printf("You have slain the Monster.\n");
			m1.death = 1;
			printf("Vous gagnez 10 points d'xp\n\n");
			printf("Tous les joueurs montent d'un niveau !\n");

			p1.pv = 150;
			p1.pv=p1.pv+10;
			p1.force = 3;
			p1.force=p1.force+3;

			p2.pv = 75;
			p2.pv=p2.pv+10;
			p2.mana = 100;
			p2.mana=p2.mana+10;
			p2.force = 1;
			p2.force=p2.force+3;

			p3.pv = 100;
			p3.pv=p3.pv+10;
			p3.mana = 75;
			p3.mana=p3.mana+10;
			p3.force = 1;
			p3.force=p3.force+3;

			p4.pv = 250;
			p4.pv=p4.pv+10;
			p4.force = 2;
			p4.force=p4.force+3;

			printf("Les joueurs ont gagnés en puissance ! :\n\n");
			printf("Player 1 is now : %d of HP, %d OF MANA and attack with %d points\n",p1.pv,p1.mana,p1.force);
			printf("Player 2 is now : %d of HP, %d OF MANA and attack with %d points\n",p2.pv,p2.mana,p2.force);
			printf("Player 3 is now : %d of HP, %d OF MANA and attack with %d points\n",p3.pv,p3.mana,p3.force);
			printf("Player 4 is now : %d of HP, %d OF MANA and attack with %d points\n",p4.pv,p4.mana,p4.force);

            
        }
        
        // Player death
        if ( p1.pv <= 0 && p1.death == 0 ){
            p1.attack = 0;
            printf("Player 1 has been killed by the Monster.\n");
			p1.death = 1;
			m1.target += 1;
			m2.target += 1;
            m3.target += 1;
			m4.target += 1;
			
        }
		
		if ( p2.pv <= 0 && p2.death == 0 ){
            p2.attack = 0;
            printf("Player 2 has been killed by the Monster.\n");
			p2.death = 1;
			m1.target += 1;
			m2.target += 1;
            m3.target += 1;
			m4.target += 1;
            
        }
		
		if ( p3.pv <= 0 && p3.death == 0 ){
            p3.attack = 0;
            printf("Player 3 has been killed by the Monster.\n");
			p3.death = 1;
			m1.target += 1;
			m2.target += 1;
            m3.target += 1;
			m4.target += 1;
            
        }
		
		if ( p4.pv <= 0 && p4.death == 0 ){
            p4.attack = 0;
            printf("Player 4 has been killed by the Monster.\n");
			p4.death = 1;
			m1.target += 1;
			m2.target += 1;
            m3.target += 1;
			m4.target += 1;
            
        }
		
        
    }
  
  return 0;
}