import React, { useRef, useEffect, useState } from "react";
import "../minesRoom.css"
import ReturnButton from './ReturnButton';

function Mines() {
    const [betAmount, setBetAmount] = useState(""); // State to track bet amount
    const [totalBombs, setTotalBombs] = useState(3); // State to track the total number of bombs
    const [grid, setGrid] = useState(Array(5).fill(null).map(() => Array(5).fill({ clicked: false, safe: true })));
    const [credits, setCredits] = useState(5000); // State to track user credits
    const [payout, setPayout] = useState(0); // State to track payout
    const [playing, setPlaying] = useState(false); //State to track playing status
    const ws = useRef(null); // Websocket

    let dest = "gameroom";
    
    useEffect(() => {
        
        // Initialize WebSocket connection
        ws.current = new WebSocket('ws://localhost:9001');
        ws.current.onopen = () => {
            console.log("connected to ws server");
            // Request initial credit balance from server
            ws.current.send("starting creds");
            setTimeout(2500);
            // Request grid state
            ws.current.send("request grid");
            setTimeout(2500);
            // Request playing status
            ws.current.send("request playing");

        };
        ws.current.onmessage = (e) => {
            const message = e.data;
            console.log("Message from server ", message);
            if (message.includes("starting")) { // Intial load up from backend
                setCredits(parseInt(message.split(" ")[0])); // Assuming message is "5000 starting"

            } else if (message.includes("Grid ")) { // Grid state sent from backend
                let gridString = message.split(" ")[1]; // Assuming message is "Grid 101110010..."
                handleGridChange(gridString);

            }else if (message.includes("status: ")){ // Assuming message is "status: $$$ T/F"
                let parsedMessage = message.split(" ");
                setPayout(parseInt(parsedMessage[1]));
                let status = parsedMessage[2];
                
                if (status === "T"){
                    setPlaying(true);
                }else{
                    setPlaying(false);
                    setPayout(0);
                }

            }else if (message.includes("Player Wins")) { // Player winning flip message from backend
                setPayout(parseInt(message.split(" ")[2])); // Update payout for visual purposes
                let coordinates = message.split(" ")[3].split(","); 
                setGrid(currentGrid => currentGrid.map((row, i) => row.map((cell, j) => {
                    if (i === parseInt(coordinates[0]) && j === parseInt(coordinates[1])) {
                        return { ...cell, clicked: true, safe: true }; // Updates cell as clicked and safe on win
                    }
                    return cell;
                })));

            } else if (message.includes("Player Lost")) { // Player losing flip message from backend
                let coordinates = message.split(" ")[2].split(",");
                setGrid(currentGrid => currentGrid.map((row, i) => row.map((cell, j) => {
                    if (i === parseInt(coordinates[0]) && j === parseInt(coordinates[1])) {
                        return { ...cell, clicked: true, safe: false }; // Update cell as clicked and unsafe/bomb on loss
                    }
                    return cell;
                })));
                setPayout(0);
                setPlaying(false);

            } else if (message.includes("User Finished:")){ // Assuming message is "User Finished: $$$$"
                //This executes when the player has clicked all open cells
                setPlaying(false);
                setPayout(0);
                setCredits(parseInt(message.split(" ")[2]));

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

    // Function to reset grid state to all cells unclicked and safe
    const getInitialGrid = () => Array(5).fill(null).map(() => Array(5).fill({ clicked: false, safe: true }));

    // Handles changes to grid based on string from backend: ex: "10100110..."
    const handleGridChange = (gridString) => {
        let index = 0;
        let tempGrid = [];
        console.log(gridString); // debugging

        //Processes each charaveter in gridString to update grid state
        for (let i = 0; i < 5; i++) {
            let newRow = [];
            for (let j = 0; j < 5; j++) {
                // Assuming backend sends '1' for clicked and safe, '2' for clicked and bomb, '0' for unclicked
                const cellValue = gridString.charAt(index);
                newRow.push({
                    clicked: cellValue !== '0', // Mark as clicked
                    safe: cellValue !== '2' // Mark as safe unless character is '2' (indicate user clicked a bomb)
                });
                index++;
            }
            tempGrid.push(newRow);
        }

        setGrid(tempGrid); // Updates state of grid with new values
    };

    // Event handler for changes in bet amount input field
    const handleBetAmountChange = (event) => {
        if(!(playing)){ // Only allows bet amount change if the game in not currently active
            setBetAmount(event.target.value);
        }
    };

    // Error checks user input for bet amount
    const isValidBet = () => {
        const number = Number(betAmount);
        if(isNaN(betAmount)){  // If the bet amount is not a number
            alert("Only numbers");
            return false;
        }else if (!(Number.isInteger(number))){
            alert("Must be integer numbers");
            return false
        }else if(betAmount <= 0){ // Disallow zero or negative values
            return false;
        }else if(betAmount > credits){ // Must have enough credits
            alert("not enough credits");
            return false;
        } else if(!betAmount){ // Make sure it is a non empty bet
            return false;
        }
        return true;
    }

    // Function to handle cash out
    const cashOut = () => { 
        console.log("User cashed out");
        ws.current.send("cashed ");

        // Resets game state in front end
        setPayout(0);
        setPlaying(false);
        setGrid(getInitialGrid());
    }

    // Function to handle cell clicks
    const cellClick = (row, col) => { 
        console.log("Clicked row: ", row, " Col: ", col);
        if (!grid[row][col].clicked) { // Only executes this event if the cell hasn't been clicked
            ws.current.send(`Clicked ${row} ${col}`); // Sends "clicked {row} {col}" to backend via websocket
        }
    };

    // Event handler for changing number of bombs
    const handleTotalBombsChange = (event) => {
        if (!playing) { // Can only change bomb amount when game is not active
            setTotalBombs(parseInt(event.target.value));
        }
    };

    // Function to handle bet place
    const placeBet = () => { 
        if(isValidBet() && !(playing)){ // Check if the bet is valid and the user is not playing
            console.log("User bet" + betAmount);
            ws.current.send("Bet " + betAmount +" " +totalBombs);
            ws.current.send("request grid"); // Request grid state 
            setPayout(betAmount); // Sets payout to bet amount
            setPlaying(true);
            setGrid(getInitialGrid());

        }
        setBetAmount("");
    }

    // Function to render game grid
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


    // Website/page
    return (
        <>
            <div className="mines-container">
                <div className="left-side">
                    <div className="left-container">
                        <div className="mines-credits">
                            <div className="return-button"><ReturnButton dest={dest} /></div>
                            <h1>Credits: {credits}</h1>
                        </div>
                        <div className="bombs-dropdown" style={{ marginLeft: '20px' }}>
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
                            <button
                                className={`place-bet-btn ${playing ? 'opaque' : ''}`}
                                onClick={placeBet}
                                disabled={playing}
                                style={{ opacity: playing ? '0.5' : '1' }} /* Inline style for opacity */
                            >
                                Place Bet
                            </button>
                            {playing && (
                                <button
                                    className={`cashout-btn ${!playing ? 'opaque' : ''}`}
                                    onClick={cashOut}
                                    style={{ opacity: playing ? '1' : '0.5' }} /* Inline style for opacity */
                                >
                                    Cash Out
                                </button>
                            )}
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
