# High-Level Design Documentation

### Mines Class Diagram

```mermaid
classDiagram
    Mines <|-- MainDriver
    Player <|-- MainDriver
    Mines <|-- Player

    class MainDriver {
        -MinesModel* minesGame
        -Player* player
    }

    class Player {
        - int betAmount
        - int credits
        - bool playing
        + int getCredits()
        + int getBet()
        + int setBet(int bet)
        + void playRound(bool prediction)
        + void increaseBet(int bet)
        + void updateCredits(int money)
        + void printCredits()
        + bool isPlaying()
        + bool setPlaying(bool)
    }

    class Mines {
        - double multiplier
        - double adder
        - int payOut
        - int totalMines
        - int totalSquares
        - int bombGrid[5][5]
        - int grid[5][5]
        + int getPayOut()
        + void initPayout(int)
        + void executeWin(int, int)
        + void executeLoss()
        + void generateMineLocations()
        + bool gridClicked(int, int)
        + bool checkForBomb(int x, int y)
        + void flipSquare(int x, int y)
        + double returnMultiplier()
        + void reset()
        + int (*returnGrid())[5]
        + std::string returnGridString()
        + void setTotalMines(int mines)
        + void printGridWithBombs()
    }
```
    
 

### Roulette Class Diagram
```mermaid
classDiagram
    BettingTable <|-- MainDriver 
    RouletteWheel <|-- MainDriver
    Player <|-- MainDriver
    BettingTable <|-- Player
    RouletteWheel <|-- Player

    class MainDriver {
        - RouletteWheel* rouletteWheel
        - BettingTable* rouletteGame 
        - Player* player
    }

    class Player {
        - int betAmount
        - int credits
        - bool playing
        + int getCredits()
        + int getBet()
        + int setBet(int bet)
        + void playRound(bool prediction)
        + void increaseBet(int bet)
        + void updateCredits(int money)
        + void printCredits()
        + bool isPlaying()
        + bool setPlaying(bool)
    }

    class BettingTable {
        - std::unordered_map<int, std::list<std::pair<int,int>>> lookupTable
        - std::unordered_map<int, std::list<std::string>> frontendLookupTable
        - RouletteWheel wheel
        - int payoutGrid[3][17]
        - std::list<int> frontendPayoutGrid
        - std::vector<std::pair<std::pair<int, int>, int>> playerBets
        + void addPlayerBet(int rowNum, int colNum, int betAmount)
        + int handleInput(const std::string& input)
        + std::string toLowerCase(const std::string &str)
        + int isEven(int num)
        + int firstHalf(int num)
        + int checkBlock(int num)
        + int checkRow(int num)
        + bool isBlack(int num)
        + int checkCol(int num)
        + int checkResults()
        + int payout(std::pair<int, int> betSpot, int betAmount)
        + std::list<std::pair<int, int>> getValues(int key)
        + void assignMapValues()
        + int executeRound(std::string betString, int spinRes)
        + std::vector<std::string> split(const std::string& s, const std::string& delimiter)
        + void reactAssignMapValues()
        + std::list<std::string > getFrontendValues(int key)
        + int frontendPayout(std::string betSpot, int betAmount)
        + int getSpinNumber()
        + std::string removeLeadingSpaces(const std::string& str)
    }

    class RouletteWheel {
        + int generateNumber()
    }

```

### CoinFlip Class Diagram
```mermaid
classDiagram
    CoinFlip <|-- MainDriver 
    Player <|-- MainDriver
    CoinFlip <|-- Player

    class CoinFlip {
        + bool tossCoin()
        + bool checkWinner(bool prediction, bool outcome)
        + bool executeRound(bool prediction)      
    }

    class Player {
        - int betAmount
        - int credits
        - bool playing
        + int getCredits()
        + int getBet()
        + int setBet(int bet)
        + void playRound(bool prediction)
        + void increaseBet(int bet)
        + void updateCredits(int money)
        + void printCredits()
        + bool isPlaying()
        + bool setPlaying(bool)
    }

    class MainDriver {
        - CoinGame* coinGame
        - Player* player   
    }
```

## Description
MainDriver facilitates all communication from the frontend and backend. It's where the backend WebSocket lives so it knows what game is being played and tells the CPP models what to do.

We use CMake to run C++. To run the backend, use the following commands:
<br>
<code>mkdir build</code>
<br>
<code>cd build</code>
<br>
<code>cmake ..</code>
<br>
<code>make</code>
<br>
<code>./backend</code>

