
bool accesa();
void accendi();
void soffia();
void gira_sinistra();
void gira_destra();

const int maxn = 10000000;

int conta(){
	for (int i = 0; i <= 2*maxn+10; i++){
		soffia();
		gira_destra();
	}
	
	accendi();
	gira_destra();
	int ans = 1;
	while (!accesa())
		ans++, gira_destra();

	return ans;
}