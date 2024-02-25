import GameRoom from "./pages/Gameroom";
import HomePage from "./pages/Homepage";
import { BrowserRouter as Router, Routes, Route } from "react-router-dom";

function App() {
  return (
    <Router>
      <Routes>
        <Route path="/" element={<HomePage />} />
        <Route path="/gameroom" element={<GameRoom />} />
      </Routes>
    </Router>
  );
}

export default App;
