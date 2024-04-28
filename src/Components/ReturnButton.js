import React from 'react';
import Button from '@mui/material/Button';
import { useNavigate } from "react-router-dom";
import { createTheme, ThemeProvider } from '@mui/material/styles';
import { yellow, green } from '@mui/material/colors';


function ReturnButton(props) {
    const theme = createTheme({
        palette: {
            primary: yellow,
            secondary: green,
        },
    });
    const navigate = useNavigate();
    function goBackToGameRoom() {
        navigate("/gameroom");
    }
    function goBackToHome() {
        navigate("/");
    }

    if (props.dest === "gameroom") {
        return (
            <div>
                <ThemeProvider theme={theme}>
                    <Button variant="text" onClick={goBackToGameRoom}>Return</Button>  
                </ThemeProvider>
            </div>
        );
   } else if (props.dest === "home") {
        return (
            <div>
                <ThemeProvider theme={theme}>
                    <Button variant="text" onClick={goBackToHome}>Return</Button>  
                </ThemeProvider>
            </div>
    );
   } 
    
}


export default ReturnButton;

