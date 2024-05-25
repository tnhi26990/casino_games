import React from 'react';
import RouletteTable from '../Components/table/BettingTable';
import './Roulette.css';
import { Container, Row, Col } from 'react-bootstrap';
import '../Components/chips/Chips.css';
import firstRow from '../Components/table/rows/FirstRow.json';
import firstBorder from '../Components/table/rows/FirstBorder.json';
import secondRow from '../Components/table/rows/SecondRow.json';
import secondBorder from '../Components/table/rows/SecondBorder.json';
import thirdRow from '../Components/table/rows/ThirdRow.json';
import thirdBorder from '../Components/table/rows/ThirdBorder.json';
import fourthRow from '../Components/table/rows/FourthRow.json';
import fifthRow from '../Components/table/rows/FifthRow.json';
import columnLeft from '../Components/table/rows/ColumnLeft.json';
import columnRight from '../Components/table/rows/ColumnRight.json';
import RoulettePro from 'react-roulette-pro';
import 'react-roulette-pro/dist/index.css';
import ReturnButton from './ReturnButton';

const prizes = [
    {
        image: 'images/RedNumbers/1.png',
    },
    {
        image: 'images/BlackNumbers/2.png',
    },
    {
        image: 'images/RedNumbers/3.png',
    },
    {
        image: 'images/BlackNumbers/4.png',
    },
    {
        image: 'images/RedNumbers/5.png',
    },
    {
        image: 'images/BlackNumbers/6.png',
    },
    {
        image: 'images/RedNumbers/7.png',
    },
    {
        image: 'images/BlackNumbers/8.png',
    },
    {
        image: 'images/RedNumbers/9.png',
    },
    {
        image: 'images/BlackNumbers/10.png',
    },
    {
        image: 'images/BlackNumbers/11.png',
    },
    {
        image: 'images/RedNumbers/12.png',
    },
    {
        image: 'images/BlackNumbers/13.png',
    },
    {
        image: 'images/RedNumbers/14.png',
    },
    {
        image: 'images/BlackNumbers/15.png',
    },
    {
        image: 'images/RedNumbers/16.png',
    },
    {
        image: 'images/BlackNumbers/17.png',
    },
    {
        image: 'images/RedNumbers/18.png',
    },
    {
        image: 'images/RedNumbers/19.png',
    },
    {
        image: 'images/BlackNumbers/20.png',
    },
    {
        image: 'images/RedNumbers/21.png',
    },
    {
        image: 'images/BlackNumbers/22.png',
    },
    {
        image: 'images/RedNumbers/23.png',
    },
    {
        image: 'images/BlackNumbers/24.png',
    },
    {
        image: 'images/RedNumbers/25.png',
    },
    {
        image: 'images/BlackNumbers/26.png',
    },
    {
        image: 'images/RedNumbers/27.png',
    },
    {
        image: 'images/BlackNumbers/28.png',
    },
    {
        image: 'images/BlackNumbers/29.png',
    },
    {
        image: 'images/RedNumbers/30.png',
    },
    {
        image: 'images/BlackNumbers/31.png',
    },
    {
        image: 'images/RedNumbers/32.png',
    },
    {
        image: 'images/BlackNumbers/33.png',
    },
    {
        image: 'images/RedNumbers/34.png',
    },
    {
        image: 'images/BlackNumbers/35.png',
    },
    {
        image: 'images/RedNumbers/36.png',
    },
    {
        image: 'images/GreenNumbers/0.png',
    },
    {
        image: 'images/GreenNumbers/00.png',
    },
];

//  returns a new array filled with randomly selected elements from the input array
const reproductionArray = (array = [], length = 0) => [
    ...Array(length)
        .fill('_')
        .map(() => array[Math.floor(Math.random() * array.length)]),
];

// replicates elements from the prizes array multiple times
const reproducedPrizeList = [
    ...prizes,
    ...reproductionArray(prizes, prizes.length * 3),
    ...prizes,
    ...reproductionArray(prizes, prizes.length),
];

// generates a unique ID
const generateId = () =>
    `${Date.now().toString(36)}-${Math.random().toString(36).substring(2)}`;

// mapping over the reproducedPrizeList array. For each prize in the reproducedPrizeList, a new object is created
// and gets a new id property
const prizeList = reproducedPrizeList.map((prize) => ({
    ...prize,
    id: typeof crypto.randomUUID === 'function' ? crypto.randomUUID() : generateId(),
}));

class Roulette extends React.Component {

    constructor(props) {
        super(props);
        this.state = {
            start: false,
            firstRow, firstBorder, secondRow, secondBorder, thirdRow, thirdBorder, fourthRow, fifthRow, columnLeft, columnRight,
            stopInCenter: {
                value: true,
            },
            arr: [], // array of bets
            chip: 10, // chip value
            dest: "gameroom", // target page when the player clicks on Return
            winPrizeIndex : 1,// number index on the spinner
            credits: 5000,
            totalBet : 5000
        };

        this.socket = new WebSocket('ws://localhost:9001');
        this.socket.onopen = () => {
            this.socket.send("starting creds");
        }

        this.socket.onmessage = (event) => {
            let message = event.data;
            console.log("Received message from server:", message);

            // Check if the message ends with " slot"
            if (message.trim().endsWith(" slot")) {
                // Extract the win prize index from the message using regular expressions
                let winPrizeIndex = parseInt(message.trim().match(/^\d+/)[0]);
                this.setState({ winPrizeIndex });
            } else {
                this.setState({ credits: parseFloat(message) })
                this.setState({ tempCredits: this.state.credits })

            }
        };

    }
    componentWillUnmount() {
        console.log("here!");
        if (!this.state.spinning) {
            this.calculateTotalBet();
        }
        setTimeout(() => {
            this.resetGame();
            // Close the WebSocket connection when the component is unmounted
            this.socket.close();
        }, 2000); // Move resetting the game and closing the socket inside the setTimeout to ensure total bet is sent
    }


    // function to change the value of start to true
    handleStart = () => {
        this.setState((prevState) => ({ start: !prevState.start }));
        console.log("Spin was hit");
        // socket.send(this.state.arr);
    };

    calculateTotalBet() {
        const { arr, spinning } = this.state;

        // Check if the spinner is currently spinning
        if (spinning) {
            console.log("Cannot calculate total bet while spinning.");
            return;
        }

        // Check if there are any bets placed on the table
        if (arr.length === 0) {
            console.log("No bets placed on the table.");
            return 0;
        }
        // Initialize total bet
        let totalBet = 0;
        // Loop through the array
        for (let i = 0; i < arr.length; i++) {
            // Check if the current element is an array
            if (Array.isArray(arr[i]) && arr[i].length === 2 && Number.isInteger(arr[i][1])) {
                console.log("Adding chip value:", arr[i][1]);
                totalBet += arr[i][1]; // Add the chip value to the total bet
            }
        }
        console.log("Total bet:", totalBet);
        this.resetGame();
        this.socket.send("total bet " + totalBet);
        return totalBet;
    }

    arrayToString(arr) {
        return arr.join(", ");
    }

    // function to change the value of start to false after the spinner has stopped
    handlePrizeDefined = () => {
        console.log('Prize defined!');
        setTimeout(() => {
            this.setState({start: false});
        }, 2000);

    };

    // function to update the array
    updateArr = (arr) => {
        this.setState({ arr })
    }

    // function to update the row
    updateRow = (row, val) => {
        this.setState({ [row]: val })
    }

    // function to update the chip value
    onClickAmount = (value) => {
        this.setState({ chip: value });
    };

    setWinIndex = (spinVal) => {
        this.setState({ winPrizeIndex : spinVal });
    }

    resetGame = () => {
        this.setState({
            arr: [],
            firstRow: firstRow.map(num => {
                num.visible = false;
                return num;
            }),
            secondRow: secondRow.map(num => {
                num.visible = false;
                return num;
            }),
            thirdRow: thirdRow.map(num => {
                num.visible = false;
                return num;
            }),
            fourthRow: fourthRow.map(num => {
                num.visible = false;
                return num;
            }),
            fifthRow: fifthRow.map(num => {
                num.visible = false;
                return num;
            }),
            columnLeft: columnLeft.map(num => {
                num.visible = false;
                return num;
            }),
            columnRight: columnRight.map(num => {
                num.visible = false;
                return num;
            }),
        });
    }

    render() {
        const { start, winPrizeIndex } = this.state;
        const { spinning, credits } = this.state; // Destructure spinning and credits from state
        const displayCredits = spinning ? this.state.tempCredits.toFixed(2) : credits.toFixed(2); // Determine which credits to display
        const prizeIndex = prizes.length * 4 + winPrizeIndex;
        return (
            <Container className="roulette-container">
                <Row>
                    <ReturnButton dest={this.state.dest}  updateCredits={this.updateCredits} resetGame={this.resetGame} closeSocket={this.closeSocket}/>
                </Row>
                <Row className="justify-items-center pt-2">
                    <Container fluid className="table">
                        <Row>
                            <Col className="betting-choice">
                                Your bets: {this.state.arr.join(", ")}
                            </Col>
                            <Col className="betting-table">
                                <RouletteTable
                                    //ROWS//
                                    firstRow={this.state.firstRow}
                                    firstBorder={this.state.firstBorder}
                                    secondRow={this.state.secondRow}
                                    secondBorder={this.state.secondBorder}
                                    thirdRow={this.state.thirdRow}
                                    thirdBorder={this.state.thirdBorder}
                                    fourthRow={this.state.fourthRow}
                                    fifthRow={this.state.fifthRow}
                                    columnLeft={this.state.columnLeft}
                                    columnRight={this.state.columnRight}
                                    arr={this.state.arr}
                                    updateRow={this.updateRow}
                                    updateArr={this.updateArr}
                                    chip={this.state.chip}
                                    socket={this.socket} // Pass the socket instance
                                    credits={ this.state.credits}
                                />
                            </Col>
                            <Col>
                                <div>
                                    <label className="credit">Credit: </label>
                                    <input type="text" className="credit-amount" value={displayCredits} readOnly />
                                </div>
                            </Col>

                        </Row>
                        <Row className="chip-row">
                            <div className="chip d-inline-block red" id={this.props.id} onClick={() => this.onClickAmount(10)}>10</div>
                            <div className="chip d-inline-block blue" id={this.props.id} onClick={() => this.onClickAmount(25)}>25</div>
                            <div className="chip d-inline-block green" id={this.props.id} onClick={() => this.onClickAmount(50)}>50</div>
                            <div className="chip d-inline-block purple" id={this.props.id} onClick={() => this.onClickAmount(100)}>100</div>
                            <div className="chip d-inline-block yellow" id={this.props.id} onClick={() => this.onClickAmount(500)}>500</div>
                        </Row>
                        <Row className="horizontal-slider">
                            <RoulettePro
                                prizes={prizeList}
                                prizeIndex={prizeIndex}
                                start={start}
                                onPrizeDefined={this.handlePrizeDefined}
                                spinningTime={7}
                                options={{ stopInCenter: true, }}
                            />
                            <div className="gray-block">
                                <div className="button-wrapper">
                                    <button
                                        disabled={this.state.arr.length === 0 || spinning} // Disable the button when arr is empty or spinning is true
                                        onClick={(event) => {
                                            if (this.state.arr.length === 0) return; // Prevent spinning if arr is empty
                                            this.setState({ spinning: true }, () => {
                                                let bet = this.arrayToString(this.state.arr);
                                                this.socket.send(bet);
                                                this.resetGame();
                                                this.handleStart(event);
                                                setTimeout(() => {
                                                    this.setState({ spinning: false });
                                                    window.location.reload(true);
                                                }, 8000);
                                            });
                                        }}
                                        className="spin-button"
                                        type="button"
                                        style={{ opacity: spinning ? 0.5 : 1 }} // Apply inline styles based on spinning state
                                    >
                                        Spin
                                    </button>

                                </div>
                            </div>
                        </Row>
                    </Container>
                </Row>

            </Container>
        )
    }
}

export default Roulette;
