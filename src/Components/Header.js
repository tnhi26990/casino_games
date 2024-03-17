import React from "react";
import { Link, useNavigate } from "react-router-dom";

function Header() {
  const navigate = useNavigate();
    function coinFlipClick() {
        navigate("/gameroom");
    }
  return (
    <>
      <div className="Button-ctnr">
        <button onClick={coinFlipClick} className = "gameroom-btn">Enter Game Room</button>
      </div>
      
    </>
  );
}
export default Header;