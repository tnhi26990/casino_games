import React from "react";


function GameRoom() {
    return (
        <div style={{ display: 'flex', flexDirection: 'row', width: '100vw', height: '100vh', justifyContent: 'space-between', alignItems: 'center' }}>
            <button style={{ flex: 1, height: '50px' }}>Coin Flip</button>
            <button style={{ flex: 1, height: '50px' }}>Roulette</button>
            <button style={{ flex: 1, height: '50px' }}>Mines</button>
        </div>

    )

}

export default GameRoom