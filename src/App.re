
open Types

type status = 
  | Started 
  | Stopped

type action = 
  | Start
  | Stop
  | ChangeActiveMole(int)
  | DisableMole


type state = {
  score: int,
  status: status,
  activeMole: moleStatus
}


let initialState = {
  score: 0,
  status: Stopped,
  activeMole: Inactive
}

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => initialState,
  reducer: (action, state) =>
    switch action {
    | Start => ReasonReact.UpdateWithSideEffects({ ...state, status: Started}, (self) => {
      let _ = Js.Global.setInterval(() => {
        let randomInt = Js.Math.random_int(0, 9);
        self.send(ChangeActiveMole(randomInt))
      }, 1000)
    })
    | Stop => ReasonReact.Update({...state, status: Stopped, activeMole: Inactive})
    | ChangeActiveMole(idx) => ReasonReact.Update({...state, activeMole: Active(idx)}) 
    | DisableMole => ReasonReact.Update({...state, activeMole: Inactive})
    },
  render: self =>
    <div className="app">
      <div className="game"> {ReasonReact.string("hello reason")} </div>
      {
        switch (self.state.status) {
          | Started => <Board activeMole={self.state.activeMole} />
          | Stopped => <Button onClick={(_click) => self.send(Start)} text="Start game !" />
        }
      }
      
      
    </div>
}