import React from "react";
import "../minesRoom.css"

function Mines() {
    const cellClick = (row, col) => {
        console.log("clicked" + row + col);
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
                        <h1 className="mines-credits">Credits: </h1>
                        <div className="bet-field">
                            <input className="bet-amount" placeholder="Enter Bet Amount"></input>
                        </div>
                        <button class="place-bet-btn">Place Bet</button>
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