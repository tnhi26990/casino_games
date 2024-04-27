import React, { useRef, useEffect, useState } from "react";

import "../minesRoom.css"

function Mines() {
    const [betAmount, setBetAmount] = useState("");

    const [credits, setCredits] = useState(5000);
    const [payout, setPayout] = useState(0);
    const ws = useRef(null);

    useEffect(() => {
        // Initialize WebSocket connection
        ws.current = new WebSocket('ws://localhost:9001');
        ws.current.onopen = () => {
            console.log("connected to ws server");
            // Optionally request initial credit balance from server
            ws.current.send("starting creds");
        };
        ws.current.onmessage = (e) => {
            const message = e.data;
            console.log("Message from server ", message);
            if (message.includes("starting")) {
              setCredits(parseInt(message.split(" ")[0])); // Assuming message is "5000 starting"
            } else if (message.includes("Player Lost")){
              setPayout(0)

            }else if (message.startsWith("Player Wins")) {
              //message from backend is "Player Wins xxxx"
              setPayout(parseInt(message.split(" ")[2]));
            }else if (!isNaN(message)) {
              setCredits(parseInt(message));  // Update credits directly with message if it's a number
            }
        };
        ws.current.onerror = (error) => {
            console.log("WebSocket error: ", error);
        };
        ws.current.onclose = () => {
            console.log("WebSocket is closed now.");
        };

        return () => {
            ws.current.close();
        };
    }, []);


    const handleBetAmountChange = (event) => {
      setBetAmount(event.target.value);
    };

    const isValidBet = () => {
      if(isNaN(betAmount)){
        alert("Only numbers");
        return false;
      }else if(betAmount > credits){
        alert("not enough credits");
        return false;
      } else if(!betAmount){
        return false;
      }
      return true;
    }

    const cashOut = () => {
      console.log("User cashed out");
      ws.current.send("cashed ");
      setPayout(0);
    }

    const cellClick = (row, col) => {
    
      console.log("Clicked row: " + row + " Col: " + col);
      ws.current.send("Clicked "+row + ","+ col);
    

    }
    
    const placeBet = () => {
      if(isValidBet()){
        //logic to send bet amount to backend
        console.log("User bet" + betAmount);
        ws.current.send("Bet " + betAmount);
        setPayout(betAmount);
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
                            <h1>Payout: {payout}</h1>
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