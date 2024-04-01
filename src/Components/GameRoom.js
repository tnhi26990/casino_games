import React from "react";
import { useNavigate } from "react-router-dom";

function GameRoom() {
    const navigate = useNavigate();
    function coinFlipClick() {
        navigate("/coinflip");
    }
    function minesClick() {
        navigate("/mines");
    }

    return (
        <>
            <div className="page-room">
                <h1 className="user-credits">Credits: </h1>
                <div className = "game-btn-container">
                    <button onClick={minesClick} id = "mines-btn" className="game-btn" >Mines</button>
                    <button onClick={coinFlipClick} id = "coin-btn" className="game-btn" >Coin Flip</button>
                    <button id = "roulette-btn" className="game-btn" >Roulette</button>
                </div>
            </div>
        </>
    );
}

export default GameRoom