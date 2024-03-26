/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXL 100000

// input data
char identifier[MAXL + 1];

int main() {
	
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	bool is_identifier = false;
	bool can_be_identifier = true;
	bool start_comment = false;
	bool is_comment = false;
	bool is_multicomment = false;
	int i = 0;
	
	int ans = 0;
	
    assert(1 == scanf("%s", identifier));
    char c;
    while ((c = getchar()) != EOF) {
    	
    	if (c == '\n'){
    		is_comment = false;
    		can_be_identifier = true;
    		is_identifier = false;
    		start_comment = false;
		}
    	
    	if (!(is_comment || is_multicomment)){
	    	if (c == '/'){
	    		if (start_comment){
	    			is_comment = true;
	    			start_comment = false;
				} else {
					start_comment = true;
				}
			} else if (c == '*'){
    			if (start_comment){
    				is_multicomment = true;
    				start_comment = false;
				}
			} else if (c == ' '){
				i = 0;
				start_comment = false;
				can_be_identifier = true;
				is_identifier = false;
			} else if (c == '"'){
				is_string = true;
			} else {
				
			}
			
		} else if (is_multicomment){
			if (c == '*'){
				start_comment = true;
			}
			if (c == '/'){
				if (start_comment){
    				is_multicomment = false;
    				start_comment = false;
				} else {
					start_comment = true;
				}
			}
		} else if (is_string){
			if (c == '"'){
				is_string = false;
			}
		}
    	
    }
    
    printf("%d\n", ans);
    return 0;
}
