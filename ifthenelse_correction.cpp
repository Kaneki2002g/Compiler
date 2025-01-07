void ifthenelse(Component* comm){ //ifthen(else)
	Component* condition = comm->children;
	Component* then = condition->next;
	Component* elsse = then->next;
	//BOTH NUMBERS NO JUMPS NEEDED
	int help = compareA(condition);
	int help2 = 0;
	if(help==1){
	buildCommands(then);
	}else if(help==-1){
		if (elsse!=nullptr){
			buildCommands(elsse);
		}
	}else{
		long long j1,j2;
		switch(condition->type){//NUM COMP ID
			case 51:{//==
				compareB(condition);
				JZERO(2);
				j1 = getVPOS();
				uJUMP(j1);
				}
			break;
			case 52:{//!=
				compareB(condition);
				j1 = getVPOS();
				uJZERO(j1);
				}
			break;
			case 53:{//>
				compareB(condition);
				JPOS(2);
				j1 = getVPOS();
				uJUMP(j1);
				}
			break;
			case 54:{//<
				compareB(condition);
				JNEG(2);
				j1 = getVPOS();
				uJPOS(j1);
				}
			break;
			case 55:{//>=
				compareB(condition);
				JPOS(2);
				j1 = getVPOS();
				uJNEG(j1);
				}
			break;
			case 56:{//<=
				compareB(condition);
				JNEG(2);
				j1 = getVPOS();
				uJPOS(j1);
				}
			break;
		}
		buildCommands(then);
			if(elsse!=nullptr){
				j2 = getVPOS();
				uJUMP(j2);
				help2++;
			}
			setVPOS(j1,helpCounter+1+help2);
			if(elsse!=nullptr){
				buildCommands(elsse);
				setVPOS(j2,helpCounter+1);
			}
	}
}