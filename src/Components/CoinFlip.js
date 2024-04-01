import "../Coin.css";
import {Component} from 'react'
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
    state = {flip: 'heads', choice: '', amount: '', animation: false}
    
    onClickFlip = () => {
        const audio = new Audio('/coin-drop.mp3');
        audio.play();
        if (this.state.animation) return;
        const tossResult = Math.floor(Math.random() * 2)
        this.setState({ animation: true });
        setTimeout(() => {
            if (tossResult === 0) {
                this.setState({flip: 'heads'})
            } else {
                this.setState({flip: 'tails'})
            }
            this.setState({ animation: false });
        }, 2000);
    }

    onClickChoice = (value) => {
        this.setState({ choice: value });
    };

    onClickAmount = (value) => {
        this.setState({ amount: value });
    };

    handleInputChange = (e) => {
        this.setState({ amount: e.target.value });
      };

    render() {
        const {flip, choice, amount} = this.state;
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
                        <input type="text" className="credit-amount" value="5000.00" />
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
                        <input type="text" className="choice" value={choice} placeholder="H or T" size="5" disabled/>
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
                        <input type="text" className="amount" value={amount} placeholder="0.00" onChange={this.handleInputChange}/>
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