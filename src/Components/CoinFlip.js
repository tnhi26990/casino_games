import "../Coin.css";
import { Component } from 'react'
import Button from '@mui/material/Button';
import Stack from '@mui/material/Stack';
import { createTheme, ThemeProvider } from '@mui/material/styles';
import { yellow, green } from '@mui/material/colors';
import AttachMoneyIcon from '@mui/icons-material/AttachMoney';
import FlipCameraAndroidIcon from '@mui/icons-material/FlipCameraAndroid';
import LooksOneIcon from '@mui/icons-material/LooksOne';
import LooksTwoIcon from '@mui/icons-material/LooksTwo';

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
            credits: ""
        };
        this.socket = new WebSocket('ws://localhost:9001');

        this.socket.onopen = () => {
            console.log('Connected to the WebSocket backend: Coin Flip Game.');
            // Send a message to the backend when the component is mounted
            this.socket.send('credits');
        };

        this.socket.onmessage = (event) => {
            console.log('Received message from server:', event.data);
            // Update credits state with the received data from the server

            this.setState({ credits: event.data });
        };
    }

    componentWillUnmount() {
        // Close the WebSocket connection when the component is unmounted
        this.socket.close();
    }

    onClickFlip = () => {
        const { choice, amount, credits } = this.state;
        const audio = new Audio('/coin-drop.mp3');
        audio.play();
        if (this.state.animation) return;

        // Check if the bet amount is not a number or if credits are less than the bet amount
        if (isNaN(amount) || parseFloat(amount) <= 0 || parseFloat(amount) > parseFloat(credits)) {
            alert('Invalid bet amount or not enough credits');
            return;
        }
        if (choice !== 'H' && choice !== 'T') {
            alert('Please select either Head (H) or Tail (T)');
            return;
        }



        const tossResult = Math.floor(Math.random() * 2);
        this.setState({ animation: true });
        setTimeout(() => {
            if (tossResult === 0 ) {
                //this.socket.send(amount);
                //console.log(choice + " and the result is " + tossResult);
                this.setState({ flip: 'heads' });
            } else {
                //this.socket.send("-" + amount);
                this.setState({ flip: 'tails' });
            }

            if (tossResult === 0 && choice === 'H' || tossResult === 1 && choice === 'T'){
                this.socket.send(amount);
            }
            else{
                this.socket.send("-" + amount);
            }
            this.setState({ animation: false });

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
        const { flip, choice, amount, credits } = this.state;
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
                                onClick={this.onClickFlip}>
                            Bet
                        </Button>
                    </Stack>
                </div>
            </div>
        );
    }
}

export default CoinFlip;
