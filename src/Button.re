let component = ReasonReact.statelessComponent("Button");


let make = (~text, ~onClick, _children) => {
  ...component,
  render: _self =>
  <button className="button" onClick={onClick}>
  {ReasonReact.string(string_of_int(item))}
  </button>
}