let component = ReasonReact.statelessComponent("Score");


let make = (~score, _children) => {
  ...component,
  render: _self =>
  <div className="score">
  {ReasonReact.string(text)}
  </div>
}