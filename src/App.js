import GameRoom from "./pages/Gameroom";
import HomePage from "./pages/Homepage";
import CoinFlip from "./pages/Coinflip"
import { BrowserRouter as Router, Routes, Route } from "react-router-dom";

function App() {
  return (
    <Router>
      <Routes>
        <Route path="/" element={<HomePage />} />
        <Route path="/gameroom" element={<GameRoom />} />
        <Route path="/coinflip" element={<CoinFlip />} />
      </Routes>
    </Router>
  );
}

export default App;
