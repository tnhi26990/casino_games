import React from 'react';
import RouletteTable from '../Components/table/BettingTable';
import Chip from '../Components/chips/Chips'
import './Roulette.css';
import { Container, Row, Col, Image } from 'react-bootstrap';



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


const prizes = [
    {
      image: 'images/number-1.png',
    },
    {
      image: 'images/number-2.png',
    },
    {
      image: 'images/number-3.png',
    },
    {
      image: 'images/number-4.png',
    },
    {
      image: 'images/number-5.png',
    },
    {
      image: 'images/number-6.png',
    },
    {
      image: 'images/number-7.png',
    },
    {
      image: 'images/number-8.png',
    },
    {
      image: 'images/number-9.png',
    },
    {
      image: 'images/number-10.png',
    },
    {
      image: 'images/number-11.png',
    },
    {
      image: 'images/number-12.png',
    },
    {
      image: 'images/number-13.png',
    },
    {
      image: 'images/number-14.png',
    },
    {
      image: 'images/number-15.png',
    },
    {
      image: 'images/number-16.png',
    },
    {
      image: 'images/number-17.png',
    },
    {
      image: 'images/number-18.png',
    },
    {
      image: 'images/number-19.png',
    },
    {
      image: 'images/number-20.png',
    },
    {
      image: 'images/number-21.png',
    },
    {
      image: 'images/number-22.png',
    },
    {
      image: 'images/number-23.png',
    },
    {
      image: 'images/number-24.png',
    },
    {
      image: 'images/number-25.png',
    },
    {
      image: 'images/number-26.png',
    },
    {
      image: 'images/number-27.png',
    },
    {
      image: 'images/number-28.png',
    },
    {
      image: 'images/number-29.png',
    },
    {
      image: 'images/number-30.png',
    },
    {
      image: 'images/number-31.png',
    },
    {
      image: 'images/number-32.png',
    },
    {
      image: 'images/number-33.png',
    },
    {
      image: 'images/number-34.png',
    },
    {
      image: 'images/number-35.png',
    },
    {
      image: 'images/number-36.png',
    },
    {
      image: 'images/number-0.png',
    },
    {
      image: 'images/number-00.png',
    },
  ];
  
  const winPrizeIndex = 37;
  
  const reproductionArray = (array = [], length = 0) => [
    ...Array(length)
      .fill('_')
      .map(() => array[Math.floor(Math.random() * array.length)]),
  ];
  
  const reproducedPrizeList = [
    ...prizes,
    ...reproductionArray(prizes, prizes.length * 3),
    ...prizes,
    ...reproductionArray(prizes, prizes.length),
  ];
  
  const generateId = () =>
    `${Date.now().toString(36)}-${Math.random().toString(36).substring(2)}`;
  
  const prizeList = reproducedPrizeList.map((prize) => ({
    ...prize,
    id: typeof crypto.randomUUID === 'function' ? crypto.randomUUID() : generateId(),
  }));
  
  let socket = new WebSocket('ws://localhost:9001');

  socket.onopen = () => {
    socket.send("hello from roulette");

  };   

class Roulette extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
          start: false,
          firstRow, firstBorder, secondRow, secondBorder, thirdRow, thirdBorder, fourthRow, fifthRow, columnLeft, columnRight,
          stopInCenter: {
            value: true,
          },
          arr: [],
        };
      }

      handleStart = () => {
        this.setState((prevState) => ({ start: !prevState.start }));
        socket.send("Spin was hit");
        socket.send(this.state.arr);
      };
    
      handlePrizeDefined = () => {
        console.log('Prize defined!');
        setTimeout(() => {
          this.setState({start: false});
        }, 2000);
        
      };

      updateArr = (arr) => {
        this.setState({ arr })
      }

      updateRow = (row, val) => {
        this.setState({ [row]: val })
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
          })
        });
      }
 
    render() {
        const { start, stopInCenter } = this.state;
        const prizeIndex = prizes.length * 4 + winPrizeIndex;
        return (
            <Container className="roulette-container">
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
                                />
                            </Col>
                            <Col>
                             <div>
                              <label className="credit">Credit: </label>
                              <input type="text" className="credit-amount" value="5000.00" />
                             </div>
                            </Col>

                        </Row>
                        <Row className="chip-row">
                          <Chip />
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
                        onClick={(event) => {
                            this.resetGame();
                            this.handleStart(event);
                        }} 
                        className="spin-button" 
                        type="button">
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