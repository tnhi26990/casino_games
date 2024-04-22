import React from 'react';
import './BettingTable.css';
import Chip from '../chips/Chips';
import { Overlay, OverlayTrigger, Tooltip, Button } from 'react-bootstrap';

let socket = new WebSocket('ws://localhost:9001');

socket.onopen = () => {
  socket.send("hello from roulette table");

}; 


class RouletteTable extends React.Component {
    chipVal = 10;
    state = {
        firstRow: this.props.firstRow,
        firstBorder: this.props.firstBorder,
        secondRow: this.props.secondRow,
        secondBorder: this.props.secondBorder,
        thirdRow: this.props.thirdRow,
        thirdBorder: this.props.thirdBorder,
        fourthRow: this.props.fourthRow,
        fifthRow: this.props.fifthRow,
        columnLeft: this.props.columnLeft,
        columnRight: this.props.columnRight,
      }

      numsSelectionHandler = (num, whichRow, chipVal) => {
        let nums = this.props.arr.length === 0 ? [] : [...this.props.arr];
        let row = [...this.state[whichRow]];
        if (nums.indexOf(num) === -1) {
            nums.push([num, chipVal]);
            let updatedRow = row.map(chip => {
                if (chip.n === num) {
                  chip.visible = true;
                }
                return chip;
              });
              this.setState({ [whichRow]: updatedRow });
            socket.send("Button was clicked " + num);
        }
        this.props.updateArr(nums)
      };
    
      render() {
        
        return (
            <React.Fragment>
                <div className="d-flex flex-row align-items-start roulette-table">
                    
                        <ul className="list-unstyled pt-6">
                        {
                            this.state.columnLeft.map((num, index, arr) =>
                            <li
                                key={num.n + index + arr}
                                className={num.className}
                                value={num.n}
                                onClick={() => this.numsSelectionHandler(num.n, "columnLeft", this.chipVal)}
                            > 
                            <Chip
                                id={num.n}
                                active={num.visible} />
                            
                            </li>)
                        }
                        </ul>
                        <div className="align-self-start">
                    <div className="table-divider"></div>
                    {/* First row */}
                    <ul className="d-flex list-unstyled">
                    { 
                        this.state.firstRow.map((num, index, arr) =>
                        <li
                                key={num.n + index + arr}
                                className={num.className}
                                value={num.n}
                                onClick={() => this.numsSelectionHandler(num.n, "firstRow", this.chipVal)}>
                             <Chip
                                id={num.n}
                                active={num.visible} />
                        </li>
                        )
                    }
                    </ul>
                    {/* Between first and second rows borders*/}
                    <ul className="d-flex list-unstyled">
                    {
                        this.state.firstBorder.map((num, index, arr) =>
                        <li
                            key={num.n + index + arr}
                            className={num.className}
                            value={num.n}
                        >
                        </li>)
                    } 
                    </ul>
                    {/* Second row */}
                    <ul className="d-flex list-unstyled">
                    {
                        this.state.secondRow.map((num, index, arr) =>
                            <button
                                key={num.n + index + arr}
                                className={num.className}
                                value={num.n}
                                onClick={() => this.numsSelectionHandler(num.n, "secondRow", this.chipVal)}>
                                    <Chip
                                id={num.n}
                                active={num.visible} />
                            </button>)
                    }
                    </ul>
                    {/* Between second and third rows borders */}
                    <ul className="d-flex list-unstyled">
                        {
                            this.state.secondBorder.map((num, index, arr) =>
                                <li
                                    key={num.n + index + arr}
                                    className={num.className}
                                    value={num.n}
                                >
                                    </li>)
                        }
                    </ul>
                    {/* Third row */}
                    <ul className="d-flex list-unstyled">
                    {
                        this.state.thirdRow.map((num, index, arr) =>
                            <button
                            key={num.n + index + arr}
                            className={num.className}
                            value={num.n}
                            onClick={() => this.numsSelectionHandler(num.n, "thirdRow", this.chipVal)}>
                                <Chip
                                id={num.n}
                                active={num.visible} />
                            </button>)
                    }
                    </ul>
                    {/* Between second and thirs rows borders */}
                    <ul className="d-flex list-unstyled">
                    {
                        this.state.thirdBorder.map((num, index, arr) =>
                            <li
                                key={num.n + index + arr}
                                className={num.className}
                                value={num.n}
                                > 
                            </li>)
                    }
                    </ul>
                    {/* Fourth row */}
                    <ul className="d-flex list-unstyled">
                    {
                        this.state.fourthRow.map((num, index, arr) =>
                            <button
                                key={num.n + index + arr}
                                className={num.className}
                                value={num.n}
                                onClick={() => this.numsSelectionHandler(num.n, "fourthRow", this.chipVal)}> 
                                <Chip
                                id={num.n}
                                active={num.visible} />
                            </button>)
                    }
                    </ul>
                    <div className="table-divider"></div>
                    {/* Fifth row */}
                    <ul className="d-flex list-unstyled">
                    {
                        this.state.fifthRow.map((num, index, arr) =>
                            <button
                                key={num.n + index + arr}
                                className={num.className}
                                value={num.n}
                                onClick={() => this.numsSelectionHandler(num.n, "fifthRow", this.chipVal)}> 
                                <Chip
                                id={num.n}
                                active={num.visible} />
                            </button>)
                    }
                    </ul>
                    <div className="table-divider"></div>
                    </div>
                    
                        <ul className="list-unstyled pt-6">
                        {
                            this.state.columnRight.map((num, index, arr) =>
                                <li className={num.className}
                                    key={num.n + index + arr}>
                                    <button
                                        className="blues"
                                        value={num.n}
                                        onClick={() => this.numsSelectionHandler(num.n, "columnRight", this.chipVal)}> 
                                        <Chip
                                        id={num.n}
                                        active={num.visible} />
                                    </button>
                                </li>
                            )
                        }
                        </ul>
                        
                    
                </div>

            </React.Fragment>
       )
      }
      
}
export default RouletteTable;