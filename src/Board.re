
open Types
let component = ReasonReact.statelessComponent("Board");

let items = Belt.Array.range(0, 9);

let make = (~activeMole, _children) => {
  ...component,
  render: _self =>
    <div className="board">
      {items->Belt.Array.map(item => 
      <div key={string_of_int(item)} className="board-item">
        { switch (activeMole) {
        | Active(chosen) when(chosen == item) => <div className="mole visible"></div>
        | _ => <div className="mole"></div>
        }}
        <div className="ground"></div>
    </div>)->ReasonReact.array}
  </div>
}

