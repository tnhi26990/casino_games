
class Player{
private:
    int credits = 5000;

public:
    int placeBet(int bet){
        if ( credits >= bet){
            return bet;
        }
        return 0;
    }



};