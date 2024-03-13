import "../Coin.css";
import {Component} from 'react'

class CoinFlip extends Component {
    state = {flip: 'heads', heads: 0, tails: 0, animation: false}
    
    onClickFlip = () => {
        const audio = new Audio('/coin-drop.mp3');
        audio.play();
        if (this.state.animation) return;
        const tossResult = Math.floor(Math.random() * 2)
        this.setState({ animation: true });
        setTimeout(() => {
            if (tossResult === 0) {
                this.setState({flip: 'heads'})
                this.setState(prevState => ({
                    heads: prevState.heads + 1,
                }))
            } else {
                this.setState({flip: 'tails'})
                this.setState(prevState => ({
                    tails: prevState.tails + 1,
                }))
            }
            this.setState({ animation: false });
        }, 2000);
    }

    onClickReset = () => {
        this.setState({flip: 'heads'})
        this.setState({heads: 0})
        this.setState({tails: 0})
    }

    render() {
        const {flip, heads, tails} = this.state
        const total = heads + tails
        const headsImage = 'https://media.geeksforgeeks.org/wp-content/uploads/20200916123059/SHalfDollarObverse2016head-300x300.jpg';
        const tailsImage = 'https://media.geeksforgeeks.org/wp-content/uploads/20200916123125/tails-200x200.jpg';
        
        return (
            <div className="bg-container">
                <div className="heading">
                    <h1>Coin Flip Game</h1>
                </div>
                <div className="app-container">
                    <h1>Credit: </h1>
                    <div className="count-container">
                        <p className="count">{`Total: ${total}`}</p>
                        <p className="count">{`Heads: ${heads}`}</p>
                        <p className="count">{`Tails: ${tails}`}</p>
                    </div>
                    <button className="coin-button" type="button" onClick={this.onClickFlip}>
                        <img
                         src={flip === 'heads' ? headsImage : tailsImage}
                         className={`image ${this.state.animation ? 'flipping' : ''}`}
                            alt="coin"
                        />
                    </button>
                    <button className="reset-button" type="button" onClick={this.onClickReset}>
                        Reset
                    </button>
                </div>
            </div>
        );
    }
}

export default CoinFlip;