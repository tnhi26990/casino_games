import React from "react";
import { Link, useNavigate } from "react-router-dom";

function Header() {
  const navigate = useNavigate();
    function homeRoomClick() {
        navigate("/gameroom");
    }
  return (
    <>
      <div className="Home-ctnr">
        <div className="Button-ctnr">
          <button onClick={homeRoomClick} className = "gameroom-btn">Enter Game Room</button>
        </div>
      </div>
      
    </>
  );
}
export default Header;