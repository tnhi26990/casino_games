import React from "react";

function GameRoom() {
    return (
        <>
            <div className="page-room">
                <h1 className="user-credits">Credits: </h1>
                <div className = "game-btn-container">
                    <button id = "mines-btn" className="game-btn" >Mines</button>
                    <button id = "coin-btn" className="game-btn" >Coin Flip</button>
                    <button id = "roulette-btn" className="game-btn" >Roulette</button>
                </div>
            </div>

        </>
    )

}

export default GameRoom