import GameRoom from "./pages/Gameroom";
import HomePage from "./pages/Homepage";
import CoinFlip from "./pages/Coinflip";
import Mines from "./pages/MinesPage";
import Roulette from "./pages/Roulette";
import { BrowserRouter as Router, Routes, Route } from "react-router-dom";

function App() {
  return (
    <Router>
      <Routes>
        <Route path="/" element={<HomePage />} />
        <Route path="/gameroom" element={<GameRoom />} />
        <Route path="/coinflip" element={<CoinFlip />} />
        <Route path="/mines" element={<Mines />} />
        <Route path="/roulette" element={<Roulette />} />
      </Routes>
    </Router>
  );
}

export default App;
