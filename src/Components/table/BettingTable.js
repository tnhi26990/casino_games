import React from 'react';
import './BettingTable.css';
import Chip from '../chips/Chips';
import { Overlay, OverlayTrigger, Tooltip, Button } from 'react-bootstrap';


class RouletteTable extends React.Component {
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
                            >
                            
                            <span className="d-inline-block">
                                {num.n}
                            </span>
                            </li>)
                        }
                        </ul>
                        <div className="align-self-start">
                    <div className="table-divider"></div>
                    {/* First row */}
                    <ul className="d-flex list-unstyled">
                    { 
                        this.state.firstRow.map((num, index, arr) =>
                            <button
                                key={num.n + index + arr}
                                className={num.className}
                                value={num.n}
                                > {num.n}
                            </button>)
                    }
                    </ul>
                    {/* Between first and second rows borders */}
                    <ul className="d-flex list-unstyled">
                    {
                        this.state.firstBorder.map((num, index, arr) =>
                        <button
                            key={num.n + index + arr}
                            className={num.className}
                            value={num.n}
                            > {num.n}
                            </button>)
                    } 
                    </ul>
                    {/* Second row */}
                    <ul className="d-flex list-unstyled">
                    {
                        this.state.secondRow.map((num, index, arr) =>
                            <button
                                key={num.n + index + arr}
                                className={num.className}
                                value={num.n}> {num.n}
                            </button>)
                    }
                    </ul>
                    {/* Between second and thirs rows borders */}
                    <ul className="d-flex list-unstyled">
                        {
                            this.state.secondBorder.map((num, index, arr) =>
                                <button
                                    key={num.n + index + arr}
                                    className={num.className}
                                    value={num.n}> {num.n}
                                    </button>)
                        }
                    </ul>
                    {/* Third row */}
                    <ul className="d-flex list-unstyled">
                    {
                        this.state.thirdRow.map((num, index, arr) =>
                            <button
                            key={num.n + index + arr}
                            className={num.className}
                            value={num.n}> {num.n}
                            </button>)
                    }
                    </ul>
                    {/* Between second and thirs rows borders */}
                    <ul className="d-flex list-unstyled">
                    {
                        this.state.thirdBorder.map((num, index, arr) =>
                            <button
                                key={num.n + index + arr}
                                className={num.className}
                                value={num.n}> {num.n}
                            </button>)
                    }
                    </ul>
                    {/* Fourth row */}
                    <ul className="d-flex list-unstyled">
                    {
                        this.state.fourthRow.map((num, index, arr) =>
                            <button
                                key={num.n + index + arr}
                                className={num.className}
                                value={num.n}> {num.n}
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
                                value={num.n}> {num.n}
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
                                        value={num.n}> {num.n}
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