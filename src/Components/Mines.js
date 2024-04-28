import React, { useRef, useEffect, useState } from "react";

import "../minesRoom.css"
import ReturnButton from './ReturnButton';

function Mines() {
    const [betAmount, setBetAmount] = useState("");
    const [totalBombs, setTotalBombs] = useState(3); // State to track the total number of bombs
    const [grid, setGrid] = useState(Array(5).fill(null).map(() => Array(5).fill({ clicked: false, safe: true })));
    const [credits, setCredits] = useState(5000);
    const [payout, setPayout] = useState(0);


    const [playing, setPlaying] = useState(false);

    let dest = "gameroom";


    const ws = useRef(null);
    
    useEffect(() => {
        const savedPay = localStorage.getItem('currentPay');
        if (savedPay) {
            //setPayout(savedPay);
        }
        // Initialize WebSocket connection
        ws.current = new WebSocket('ws://localhost:9001');
        ws.current.onopen = () => {
            console.log("connected to ws server");
            // Optionally request initial credit balance from server
            ws.current.send("starting creds");
            //ws.current.send("request grid");
        };
        ws.current.onmessage = (e) => {
            const message = e.data;
            console.log("Message from server ", message);
            if (message.includes("starting")) {
                setCredits(parseInt(message.split(" ")[0])); // Assuming message is "5000 starting"
            } else if (message.includes("Grid ")) {
                let gridString = message.split(" ")[1]; // Assuming message is "Grid 101110010..."
                handleGridChange(gridString);
            }else if (message.includes("Player Wins")) {
                setPayout(parseInt(message.split(" ")[2]));
                let coordinates = message.split(" ")[3].split(",");
                setGrid(currentGrid => currentGrid.map((row, i) => row.map((cell, j) => {
                    if (i === parseInt(coordinates[0]) && j === parseInt(coordinates[1])) {
                        return { ...cell, clicked: true, safe: true };
                    }
                    return cell;
                })));
            } else if (message.includes("Player Lost")) {
                let coordinates = message.split(" ")[2].split(",");
                setGrid(currentGrid => currentGrid.map((row, i) => row.map((cell, j) => {
                    if (i === parseInt(coordinates[0]) && j === parseInt(coordinates[1])) {
                        return { ...cell, clicked: true, safe: false };
                    }
                    return cell;
                })));
                setPayout(0);
                setPlaying(false);
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

    const getInitialGrid = () => Array(5).fill(null).map(() => Array(5).fill({ clicked: false, safe: true }));


    const handleGridChange = (gridString) => {
        let index = 0;
        let tempGrid = [];

        for (let i = 0; i < 5; i++) {
            let newRow = [];
            for (let j = 0; j < 5; j++) {
                // Assuming backend sends '1' for clicked and safe, '2' for clicked and bomb, '0' for unclicked
                const cellValue = gridString.charAt(index);
                newRow.push({
                    clicked: cellValue !== '0',
                    safe: cellValue !== '2'
                });
                index++;
            }
            tempGrid.push(newRow);
        }

        setGrid(tempGrid);
    };



    const handleBetAmountChange = (event) => {
        if(!(playing)){
            setBetAmount(event.target.value);
        }
    };

    const isValidBet = () => {
        if(isNaN(betAmount)){
            alert("Only numbers");
            return false;
        }else if(betAmount <= 0){
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
        setPlaying(false);
        setGrid(getInitialGrid());
    }

    const cellClick = (row, col) => {
        console.log("Clicked row: ", row, " Col: ", col);
        if (!grid[row][col].clicked) {
            ws.current.send(`Clicked ${row} ${col}`);
        }
    };

    const handleTotalBombsChange = (event) => {
        if (!playing) {
            setTotalBombs(parseInt(event.target.value));
        }
    };

    const placeBet = () => {
        if(isValidBet() && !(playing)){
            //logic to send bet amount to backend
            console.log("User bet" + betAmount);
            ws.current.send("Bet " + betAmount +" " +totalBombs);
            ws.current.send("request grid");
            setPayout(betAmount);
            localStorage.setItem('currentPay', betAmount);
            setPlaying(true);
            setGrid(getInitialGrid());

        }
        setBetAmount("");
    }

    const renderGrid = () => {
        return (
            <div className="grid">
                {grid.map((row, i) => (
                    <div key={i} className="grid-row">
                        {row.map((cell, j) => (
                            <div
                                key={`${i}-${j}`}
                                className={`cell ${cell.clicked ? (cell.safe ? "safe" : "bomb") : ""}`}
                                onClick={() => cellClick(i, j)}
                            />
                        ))}
                    </div>
                ))}
            </div>
        );
    };



    return (
        <>
            <div className="mines-container">
                <div className="left-side">
                    <div className="left-container">
                        <div className="mines-credits">


                        <div className="return-button"><ReturnButton dest={dest} /></div>
                          <h1 >Credits: {credits}</h1>
                        </div>
                        <div className="bombs-dropdown" style={{ marginLeft: '20px' }}> {/* Added marginLeft */}
                            <select
                                style={{
                                    padding: '8px',
                                    fontSize: '16px',
                                    border: '2px solid #ccc',
                                    borderRadius: '24px',
                                    backgroundColor: '#f9f9f9',
                                    cursor: 'pointer',
                                    outline: 'none',
                                }}
                                value={totalBombs}
                                onChange={handleTotalBombsChange}
                            >
                                <option value={3}>Total Bombs: 3</option>
                                <option value={5}>Total Bombs: 5</option>
                                <option value={10}>Total Bombs: 10</option>
                                <option value={15}>Total Bombs: 15</option>
                                <option value={24}>Total Bombs: 24</option>
                            </select>
                        </div>
                        <div className="payout-amt">
                            <h1>Payout: {payout}</h1>
                        </div>
                        <div className="bet-field">
                            <input
                                className="bet-amount"
                                placeholder="Enter Bet Amount"
                                value={betAmount}
                                onChange={handleBetAmountChange}
                            />
                        </div>
                        <div className="cash-bet">
                            <button className="place-bet-btn" onClick={placeBet}>Place Bet</button>
                            <button className="cashout-btn" onClick={cashOut}>Cash Out</button>
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
export default Mines;
