import React, { useRef, useEffect, useState } from "react";
import { useNavigate } from "react-router-dom";
import ReturnButton from './ReturnButton';

function GameRoom() {
    const navigate = useNavigate();
    const [credits, setCredits] = useState(5000);
    let dest = "home";
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
                setCredits(parseInt(message.split(" ")[0]));
            } else if (!isNaN(message)) {
                setCredits(parseInt(message));
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

    function coinFlipClick() {
        setTimeout(() => {
        ws.current.send("Change coin");
    }, 5000);
        navigate("/coinflip");
    }
    function minesClick() {
        setTimeout(() => {
        ws.current.send("Change mines");
    }, 5000);
        navigate("/mines");
    }

    function rouletteClick () {
        setTimeout(() => {
        ws.current.send("Change roulette");
    }, 5000);
        navigate("/roulette");
    }

    return (
        <>
            <div className="page-room">
                <div><ReturnButton dest={dest} /></div>
                <h1 className="user-credits">Credits: {credits} </h1>
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