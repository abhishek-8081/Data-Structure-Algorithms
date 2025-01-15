class Solution {
    private:
    bool isSet(int &x,int &bitpos){
        if(((1<<bitpos)&x)==0){
            return false;
        }
        else{
            return true;
        }
    }

// Function return type is bool since any non-zero is always true .
//eventually being bool type it modifies and return an integer 
    bool setBit(int &x,int &bitpos){
        return x|=(1<<bitpos);
    }

    bool unset(int &x,int &bitpos){
        return x&= ~(1<<bitpos);
    }



public:
    int minimizeXor(int num1, int num2) {
        int x=num1;
        int required = __builtin_popcount(num2);
        int current = __builtin_popcount(x);

        int bitpos=0;

        if(current<required){
            while(current<required){
                if(!isSet(x,bitpos)){
                    setBit(x,bitpos);
                    current++;
                }
                bitpos++;

            }


        }
        else if(required<current){
            while(current>required){
                if(isSet(x,bitpos)){
                    unset(x,bitpos);
                    current--;

                }
                bitpos++;
            }

        }
        

        return x;
        
    }
};