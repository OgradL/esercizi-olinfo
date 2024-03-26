#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

#define ll long long


string bits_n(ll N){
	string a = "";
	for (int b = 34; b >= 0; b--){
		if ((N ^ (1LL << b)) >= N) a += "0";
		else a += "1";
	}
	return a;
}

ll sumxor(ll A){
	int v = A % 4;
	if (v == 0)
		return A;
	if (v == 1)
		return 1;
	if (v == 2)
		return A ^ 1;
	if (v == 3)
		return 0;
}

ll maxxor(ll A){
	ll N = sumxor(A);
	ll ris = 0;
	
    if ((N ^ (17179869184)) >= N){
		if ((ris + (17179869184)) <= A){
			ris += (17179869184);
		}
	}


    if ((N ^ (8589934592)) >= N){
		if ((ris + (8589934592)) <= A){
			ris += (8589934592);
		}
	}


    if ((N ^ (4294967296)) >= N){
		if ((ris + (4294967296)) <= A){
			ris += (4294967296);
		}
	}


    if ((N ^ (2147483648)) >= N){
		if ((ris + (2147483648)) <= A){
			ris += (2147483648);
		}
	}


    if ((N ^ (1073741824)) >= N){
		if ((ris + (1073741824)) <= A){
			ris += (1073741824);
		}
	}


    if ((N ^ (536870912)) >= N){
		if ((ris + (536870912)) <= A){
			ris += (536870912);
		}
	}


    if ((N ^ (268435456)) >= N){
		if ((ris + (268435456)) <= A){
			ris += (268435456);
		}
	}


    if ((N ^ (134217728)) >= N){
		if ((ris + (134217728)) <= A){
			ris += (134217728);
		}
	}


    if ((N ^ (67108864)) >= N){
		if ((ris + (67108864)) <= A){
			ris += (67108864);
		}
	}


    if ((N ^ (33554432)) >= N){
		if ((ris + (33554432)) <= A){
			ris += (33554432);
		}
	}


    if ((N ^ (16777216)) >= N){
		if ((ris + (16777216)) <= A){
			ris += (16777216);
		}
	}


    if ((N ^ (8388608)) >= N){
		if ((ris + (8388608)) <= A){
			ris += (8388608);
		}
	}


    if ((N ^ (4194304)) >= N){
		if ((ris + (4194304)) <= A){
			ris += (4194304);
		}
	}


    if ((N ^ (2097152)) >= N){
		if ((ris + (2097152)) <= A){
			ris += (2097152);
		}
	}


    if ((N ^ (1048576)) >= N){
		if ((ris + (1048576)) <= A){
			ris += (1048576);
		}
	}


    if ((N ^ (524288)) >= N){
		if ((ris + (524288)) <= A){
			ris += (524288);
		}
	}


    if ((N ^ (262144)) >= N){
		if ((ris + (262144)) <= A){
			ris += (262144);
		}
	}


    if ((N ^ (131072)) >= N){
		if ((ris + (131072)) <= A){
			ris += (131072);
		}
	}


    if ((N ^ (65536)) >= N){
		if ((ris + (65536)) <= A){
			ris += (65536);
		}
	}


    if ((N ^ (32768)) >= N){
		if ((ris + (32768)) <= A){
			ris += (32768);
		}
	}


    if ((N ^ (16384)) >= N){
		if ((ris + (16384)) <= A){
			ris += (16384);
		}
	}


    if ((N ^ (8192)) >= N){
		if ((ris + (8192)) <= A){
			ris += (8192);
		}
	}


    if ((N ^ (4096)) >= N){
		if ((ris + (4096)) <= A){
			ris += (4096);
		}
	}


    if ((N ^ (2048)) >= N){
		if ((ris + (2048)) <= A){
			ris += (2048);
		}
	}


    if ((N ^ (1024)) >= N){
		if ((ris + (1024)) <= A){
			ris += (1024);
		}
	}


    if ((N ^ (512)) >= N){
		if ((ris + (512)) <= A){
			ris += (512);
		}
	}


    if ((N ^ (256)) >= N){
		if ((ris + (256)) <= A){
			ris += (256);
		}
	}


    if ((N ^ (128)) >= N){
		if ((ris + (128)) <= A){
			ris += (128);
		}
	}


    if ((N ^ (64)) >= N){
		if ((ris + (64)) <= A){
			ris += (64);
		}
	}


    if ((N ^ (32)) >= N){
		if ((ris + (32)) <= A){
			ris += (32);
		}
	}


    if ((N ^ (16)) >= N){
		if ((ris + (16)) <= A){
			ris += (16);
		}
	}


    if ((N ^ (8)) >= N){
		if ((ris + (8)) <= A){
			ris += (8);
		}
	}


    if ((N ^ (4)) >= N){
		if ((ris + (4)) <= A){
			ris += (4);
		}
	}


    if ((N ^ (2)) >= N){
		if ((ris + (2)) <= A){
			ris += (2);
		}
	}


    if ((N ^ (1)) >= N){
		if ((ris + (1)) <= A){
			ris += (1);
		}
	}



	return ris ^ N;
}


int main() {
	

    int Q;
    cin >> Q;
    
    for (int i = 0; i < Q; i++) {
        int A;
        cin >> A;

        cout << sumxor(A) << " " << maxxor(A) << endl;
    }


    return 0;
}
