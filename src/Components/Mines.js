import React, { useState } from "react";

import "../minesRoom.css"

function Mines() {
    const [betAmount, setBetAmount] = useState("");

    const [credits, setCredits] = useState(5000);

    const handleBetAmountChange = (event) => {
      setBetAmount(event.target.value);
    };

    const isValidBet = () => {
      if(!(isNaN(betAmount)) && betAmount<= credits && betAmount){
        return true;
      }
      return false;
    }

    const cashOut = () => {
      console.log("User cashed out");
    }

    const cellClick = (row, col) => {
      console.log("Clicked row: " + row + " Col: " + col);
    }
    
    const placeBet = () => {
      if(isValidBet()){
        //logic to send bet amount to backend
        setCredits(credits - betAmount);
        console.log("User bet" + betAmount);
      }
      setBetAmount("");
    }

    const getBalance = () => {
      // logic for getting balance from back end
    
    }

    const renderGrid = () => {
        const rows = 5;
        const cols = 5;
        const grid = [];
        for (let i = 0; i < rows; i++) {
          for (let j = 0; j < cols; j++) {
            grid.push(
              <div
                className="cell"
                key={`${i}-${j}`}
                onClick={() => cellClick(i, j)}
              ></div>
            );
          }
        }
        return grid;
      };
      
    
    return (
        <>
            <div className="mines-container">
                <div className="left-side">
                    <div className="left-container">
                        <div className="mines-credits">
                          <h1 >Credits: {credits}</h1>
                        </div>
                        <div className="bet-field">
                            <input 
                              className="bet-amount" 
                              placeholder="Enter Bet Amount" 
                              value={betAmount}
                              onChange={handleBetAmountChange}>
                              </input>
                        </div>
                        <div className="payout-amt">
                            <h1>Payout:</h1>
                        </div>
                        <div className="cash-bet">
                          <button class="place-bet-btn" onClick={placeBet} >Place Bet</button>
                          <button class="cashout-btn" onClick={cashOut}>Cash Out</button> 
                        </div>

                    </div>

                </div>
                <div className="right-side">
                    <div className="grid">{renderGrid()}</div>
                </div>                
            </div>
        
        </>
    );

}
export default Mines