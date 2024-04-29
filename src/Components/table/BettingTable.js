import React from 'react';
import './BettingTable.css';
import Chip from '../chips/Chips';


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


    //we need to check if user can afford bets here.
    numsSelectionHandler = (num, whichRow, index) => {
        let chipVal = this.props.chip;
        let nums = this.props.arr.length === 0 ? [] : [...this.props.arr];
        let row = [...this.state[whichRow]];
        if (nums.indexOf(num) === -1 && chipVal <= this.props.credits) {
            nums.push([num,chipVal]);
            let updatedRow = row.map(chip => {
                if (chip.n === num) {
                    chip.visible = true;
                }
                return chip;
            });
            this.setState({ [whichRow]: updatedRow });
            this.props.socket.send("Button was clicked " + chipVal); //how do I send what chip value was present?
            // socket.send("Grid spot is " + index + ", " + whichRow);
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
                                    onClick={() => this.numsSelectionHandler(num.n, "columnLeft", index)}
                                >
                                    <Chip
                                        id={num.n}
                                        active={num.visible}
                                        chip={this.props.chip}
                                    />
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
                                        onClick={() => this.numsSelectionHandler(num.n, "firstRow", index)}>
                                        <Chip
                                            id={num.n}
                                            active={num.visible}
                                            chip={this.props.chip}
                                        />
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
                                        onClick={() => this.numsSelectionHandler(num.n, "secondRow", index)}>
                                        <Chip
                                            id={num.n}
                                            active={num.visible}
                                            chip={this.props.chip} />
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
                                        onClick={() => this.numsSelectionHandler(num.n, "thirdRow", index)}>
                                        <Chip
                                            id={num.n}
                                            active={num.visible}
                                            chip={this.props.chip} />
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
                                        onClick={() => this.numsSelectionHandler(num.n, "fourthRow", index)}>
                                        <Chip
                                            id={num.n}
                                            active={num.visible}
                                            chip={this.props.chip} />
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
                                        onClick={() => this.numsSelectionHandler(num.n, "fifthRow", index)}>
                                        <Chip
                                            id={num.n}
                                            active={num.visible}
                                            chip={this.props.chip} />
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
                                        onClick={() => this.numsSelectionHandler(num.n, "columnRight", index)}>
                                        <Chip
                                            id={num.n}
                                            active={num.visible}
                                            chip={this.props.chip} />
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