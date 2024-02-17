import Header from "../Components/Header";
import "../Buttons.css";

export default function() {
    return (
        <>
            <div className="page-room">
                <div className = "game-btn-container">
                    <button id = "mines-btn" className="game-btn" >Mines</button>
                    <button id = "coin-btn" className="game-btn" >Coin Flip</button>
                    <button id = "roulette-btn" className="game-btn" >Roulette</button>
                </div>
            </div>

        </>
    )
}