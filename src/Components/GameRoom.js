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

    function rouletteClick () {
        navigate("/roulette");
        // Connect to the WebSocket backend
        const socket = new WebSocket('ws://localhost:9001');

        socket.onopen = () => {
            console.log('Connected to the WebSocket backend');
            // Send a message to the backend when the button is clicked
            socket.send('Hello from client!');
        };

        socket.onmessage = (event) => {
            console.log('Received message from server:', event.data);
            // Handle the received message from the server
            // For example, update the UI with the received message
            alert(event.data); // Display the received message in an alert
        };

        socket.onclose = () => {
            console.log('Disconnected from the WebSocket backend');
            // Handle the WebSocket connection being closed.
        };
    }

    return (
        <>
            <div className="page-room">
                <h1 className="user-credits">Credits: </h1>
                <div className = "game-btn-container">
                    <button onClick={minesClick} id = "mines-btn" className="game-btn" >Mines</button>
                    <button onClick={coinFlipClick} id = "coin-btn" className="game-btn" >Coin Flip</button>
                    <button onClick  = {rouletteClick} id = "roulette-btn" className="game-btn" >Roulette</button>
                </div>
            </div>
        </>
    );
}

export default GameRoom