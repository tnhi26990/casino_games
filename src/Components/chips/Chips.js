import React from 'react';
import './Chips.css';
import { useEffect, useState } from 'react';

function Chip(props) {
  const [chip, setChip] = useState(null);

  useEffect(() => {
    if (props.active && props.id && (!chip || !props.chip)) {
      switch (props.chip) {
        case 10:
          setChip(<div className="chip d-inline-block red">{props.chip}</div>);
          break;
        case 25:
          setChip(<div className="chip d-inline-block blue">{props.chip}</div>);
          break;
        case 50:
          setChip(<div className="chip d-inline-block green">{props.chip}</div>);
          break;
        case 100:
          setChip(<div className="chip d-inline-block purple">{props.chip}</div>);
          break;
        case 500:
          setChip(<div className="chip d-inline-block yellow">{props.chip}</div>);
          break;
        default:
          setChip(props.id);
          break;
      }
    }
  }, [props.active, props.chip, props.id, chip]);

  useEffect(() => {
    if (props.reset) {
      setChip(null);
    }
  }, [props.reset]);

  return chip || props.id;
  
}

export default Chip;