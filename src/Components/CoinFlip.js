import React, { Component } from 'react';
import Button from '@mui/material/Button';
import Stack from '@mui/material/Stack';
import { createTheme, ThemeProvider } from '@mui/material/styles';
import { yellow, green } from '@mui/material/colors';
import AttachMoneyIcon from '@mui/icons-material/AttachMoney';
import FlipCameraAndroidIcon from '@mui/icons-material/FlipCameraAndroid';
import LooksOneIcon from '@mui/icons-material/LooksOne';
import LooksTwoIcon from '@mui/icons-material/LooksTwo';
import ReturnButton from './ReturnButton';
import "../Coin.css";

const theme = createTheme({
    palette: {
        primary: yellow,
        secondary: green,
    },
});

class CoinFlip extends Component {
    constructor(props) {
        super(props);
        this.state = {
            flip: "heads",
            choice: "",
            amount: "",
            animation: false,
            credits: "",
            tempCreds: "",
            dest: "gameroom",
            result: 1,
            buttonDisabled: false, // State to manage button disablement
        };
        this.socket = new WebSocket('ws://localhost:9001');

        this.socket.onopen = () => {
            console.log('Connected to the WebSocket backend: Coin Flip Game.');
            this.socket.send("starting creds");
        };

        this.socket.onmessage = (event) => {
            console.log('Received message from server:', event.data);

            if (event.data === "1" || event.data === "0") {
                this.setState({ result: parseInt(event.data) });
            }
            if (event.data.endsWith("starting")) {
                const regex = /^\d+/;
                const match = event.data.match(regex);
                if (match) {
                    const credits = parseInt(match[0]);
                    this.setState({ credits });
                }
            } else {
                this.setState({ tempCreds: event.data });
            }
        };
    }

    componentWillUnmount() {
        this.socket.close();
    }

    onClickFlip = () => {
        const { choice, amount, credits } = this.state;
        const audio = new Audio('/coin-drop.mp3');

        if (isNaN(amount) || parseFloat(amount) <= 0 || parseFloat(amount) > parseFloat(credits)) {
            alert('Invalid bet amount or not enough credits');
            return;
        }
        if (choice !== 'H' && choice !== 'T') {
            alert('Please select either Head (H) or Tail (T)');
            return;
        }

        audio.play();
        if (this.state.animation) return;

        this.socket.send(choice + " " + amount);

        this.setState({ animation: true, buttonDisabled: true }); // Disable button on flip
        setTimeout(() => {
            if (this.state.result === 0) {
                this.setState({ flip: 'heads' });
            } else {
                this.setState({ flip: 'tails' });
            }

            this.setState({ animation: false, buttonDisabled: false, credits: this.state.tempCreds });

        }, 2000);
    }

    onClickChoice = (value) => {
        console.log(value);
        this.setState({ choice: value });
    };

    onClickAmount = (value) => {
        this.setState({ amount: value });
    };

    handleInputChange = (e) => {
        this.setState({ amount: e.target.value });
    };

    render() {
        const { flip, choice, amount, credits, buttonDisabled } = this.state;
        const headsImage = 'https://assets.ccbp.in/frontend/react-js/heads-img.png';
        const tailsImage = 'https://assets.ccbp.in/frontend/react-js/tails-img.png';

        return (
            <div className="bg-container">
                <div className="app-container">
                    <div className="heading">
                        <h1>COIN FLIP GAME</h1>
                    </div>
                    <div className="credit-content">
                        <Stack direction="row" spacing={2} className="play-button">
                            <div className="return-button"><ReturnButton dest={this.state.dest} /></div>
                            <label className="credit">Credit: </label>
                            <input type="text" className="credit-amount" value={credits} />
                        </Stack>
                    </div>
                    <div className="img">
                        <img
                            src={flip === 'heads' ? headsImage : tailsImage}
                            className={`image ${this.state.animation ? 'flipping' : ''}`}
                            alt="coin"
                        />
                    </div>
                    <Stack direction="row" spacing={4} className="bet-button">
                        <ThemeProvider theme={theme}>
                            <p>You bet: </p>
                            <Button variant="contained" startIcon={<LooksOneIcon />} color="primary" size="large"
                                    onClick={() => this.onClickChoice('H')}>
                                Head
                            </Button>
                            <Button variant="contained" startIcon={<LooksTwoIcon />} color="primary" size="large"
                                    onClick={() => this.onClickChoice('T')}>
                                Tail
                            </Button>
                            <input type="text" className="choice" value={choice} placeholder="H or T" size="5" disabled />
                        </ThemeProvider>
                    </Stack>
                    <p>For</p>
                    <Stack direction="row" spacing={4} className="amount-button">
                        <ThemeProvider theme={theme}>
                            <Button variant="contained" color="primary" size="medium" onClick={() => this.onClickAmount('10.00')}>
                                <AttachMoneyIcon />10.00
                            </Button>
                            <Button variant="contained" color="primary" size="medium" onClick={() => this.onClickAmount('20.00')}>
                                <AttachMoneyIcon />20.00
                            </Button>
                            <Button variant="contained" color="primary" size="medium" onClick={() => this.onClickAmount('50.00')}>
                                <AttachMoneyIcon />50.00
                            </Button>
                            <Button variant="contained" color="primary" size="medium" onClick={() => this.onClickAmount('100.00')}>
                                <AttachMoneyIcon />100.00
                            </Button>
                        </ThemeProvider>
                    </Stack>
                    <Stack direction="row" spacing={4} className="play-button">
                        <label>Bet Amount:</label>
                        <input type="text" className="amount" value={amount} placeholder="0.00" onChange={this.handleInputChange} />
                        <Button variant="contained" startIcon={<FlipCameraAndroidIcon />} color="success" size="large"
                                onClick={this.onClickFlip} disabled={buttonDisabled} style={{ opacity: buttonDisabled ? 0.5 : 1 }}>
                            Bet
                        </Button>
                    </Stack>
                </div>
            </div>
        );
    }
}

export default CoinFlip;
