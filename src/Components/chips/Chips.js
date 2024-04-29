import React from 'react';
import './Chips.css';
import { useEffect, useState } from 'react';

// renders different chips based on props
function Chip(props) {
  const [chipElement, setChipElement] = useState(null);
  
  // uses the useEffect hook to react to changes in props.active, props.chip, and props.id. 
  // When these props change, it updates the chip accordingly.
  useEffect(() => {
    if (props.active && props.id && (!chipElement || !props.chip)) {
      switch (props.chip) {
        case 10:
          setChipElement(<div className="chip d-inline-block red">{props.chip}</div>);
          break;
        case 25:
          setChipElement(<div className="chip d-inline-block blue">{props.chip}</div>);
          break;
        case 50:
          setChipElement(<div className="chip d-inline-block green">{props.chip}</div>);
          break;
        case 100:
          setChipElement(<div className="chip d-inline-block purple">{props.chip}</div>);
          break;
        case 500:
          setChipElement(<div className="chip d-inline-block yellow">{props.chip}</div>);
          break;
        default:
          setChipElement(props.id);
          break;
      }
    }
  }, [props.active, props.chip, props.id, chipElement]);
  
  return chipElement || props.id;

}

export default Chip;