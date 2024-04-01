import GameRoom from "./pages/Gameroom";
import HomePage from "./pages/Homepage";
import CoinFlip from "./pages/Coinflip";
import Mines from "./pages/MinesPage";
import { BrowserRouter as Router, Routes, Route } from "react-router-dom";

function App() {
  return (
    <Router>
      <Routes>
        <Route path="/" element={<HomePage />} />
        <Route path="/gameroom" element={<GameRoom />} />
        <Route path="/coinflip" element={<CoinFlip />} />
        <Route path="/mines" element={<Mines />} />
      </Routes>
    </Router>
  );
}

export default App;
