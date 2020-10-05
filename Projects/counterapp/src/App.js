import React, { Component } from "react";
import "./App.css";

class App extends Component {
  constructor(props) {
    super(props);
    this.state = {
      count: 0,
    };
  }
  clickHandle() {
    this.setState({
      count: this.state.count + 1,
    });
  }
  decHandle() {
    this.setState({
      count: this.state.count - 1,
    });
  }
  resetHandle() {
    this.setState({
      count: 0,
    });
  }
  render() {
    return (
      <div className="App">
        <h1>Counter App</h1>
        <h2>{this.state.count}</h2>
        <button
          onClick={() => {
            this.clickHandle();
          }}
        >
          INCR
        </button>
        <button
          onClick={() => {
            this.resetHandle();
          }}
        >
          Reset
        </button>
        <button
          onClick={() => {
            this.decHandle();
          }}
        >
          DECR
        </button>
      </div>
    );
  }
}
export default App;
