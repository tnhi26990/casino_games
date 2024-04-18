import React from 'react';
import './Chips.css';

class Chip extends React.Component {

    render() {
      
        return (
        <>
          <div className="chip d-inline-block red" id={this.props.id} >10</div>
          <div className="chip d-inline-block blue" id={this.props.id} >25</div>
          <div className="chip d-inline-block green" id={this.props.id} >50</div>
          <div className="chip d-inline-block purple" id={this.props.id} >100</div>
          <div className="chip d-inline-block yellow" id={this.props.id} >500</div>
        </>
        )
    }
  }
  
  export default Chip;