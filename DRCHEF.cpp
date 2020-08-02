#include <iostream>
#include<bits/stdc++.h>
using namespace std;
/*
On every day choose a day that , 

*/
void printArray(vector<long long int> &vec){
    for(int a = 0;a < vec.size();a++){
        cout << vec[a] << " ";
    }
    cout << endl;
}

bool checkGreaterEle(vector<long long int> &vec, long long int cures){
    for(int a=0;a<vec.size();a++){
        if(vec[a] > cures) return false;
    }
    return true;
}

int main() {
	long long int i=0,t,x,input,N,j;
	vector<long long int> status;
	cin >> t;
	while(t--){
	    cin >> N >> x;
	    for(i=0;i<N;i++){
	        cin >> input;
	        status.push_back(input);
	    }
        printArray(status);
	    sort(status.begin(),status.end());
	    long long int next_day_cures = x,min_diff,country_picked,index,count=0;
	    bool flag = false;
        
        while(!flag){
            min_diff = INT_MAX;
            for(j=0;j<status.size();j++){   //pick the next day value
                if(status[j] == next_day_cures){
                    next_day_cures = 2*next_day_cures;
                    status[j] = 0;
                    break;
                }

                else if(status[j] > next_day_cures && abs(status[j] - next_day_cures) < min_diff){
                    min_diff = abs(status[j] - next_day_cures);
                    //min_diff = status[j];
                    country_picked = status[j];
                    index = j;
                }
                else if(checkGreaterEle(status,next_day_cures) && status[j] != 0){
                    cout << "*****************************\n";
                    country_picked = status[j];
                    index = j;
                    
                }
                cout << status[j] << endl;
            }
            cout << "country_picked with population : " << country_picked << endl;
            
            if(status[index] > next_day_cures) status[index] = status[index] - next_day_cures;
            else {
                status[index] = 0;
            }

            
            if(2*status[index] > country_picked){
                //next_day_cures = 2*(abs(status[index] - country_picked));
                next_day_cures = 2*status[index];
                status[index] = country_picked;
            }
            else if(status[index] != 0){
                next_day_cures = 2*next_day_cures;
                status[index] = 0;
            }

            
            cout  << "next_day_cures : " << next_day_cures << endl;
            printArray(status);
            
            for(int k=0;k<status.size();k++){
                if(status[k] > 0) break;
                else if ( k == status.size()-1)
                flag = true;
            }
            count++;
            if(flag == true) break;

        }
            
        cout << "count : " << count << endl;
        status.clear();
        
	}
	
	
}
