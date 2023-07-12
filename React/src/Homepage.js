import {useEffect, useState} from 'react';
import React from "react";
import firebaseConfig from "./firebaseConfig";
import {ref,onValue} from "firebase/database";


function Homepage() {
    useEffect(() => {

        const nrwRef = ref(firebaseConfig, 'nrw');

        onValue(nrwRef, (snapshot) => { const data = snapshot.val();setPredictions(data["prediction"].array); setNumberOfCars(data["aaa"].n);setNumberOfCars1(data["aaaa"].n1) }

    );}, []);
    const [float, setFloat] = useState(0);

    const [updated, setUpdated] = useState(float);
    const [numberOfCars, setNumberOfCars] = useState(0);
    const [numberOfCars1, setNumberOfCars1] = useState(0);
    const [predictions, setPredictions] = useState(new Array(24).fill(0));
    console.log(predictions);
    const handleChange = (event) => {
        setFloat(event.target.value);
    };

    const handleClick = () => {
        // 👇 "message" stores input field value
        setUpdated(float);
    };
    const [isVisible, setIsVisible] = React.useState(false);
    const toggleVisibility = () => setIsVisible(!isVisible);
  return (
    <div >
        <div>
            <div>
                <h1>Number of cars in this view is {numberOfCars}</h1>
                {(numberOfCars>12)&&(<h1 className="alert">there is traffic jam</h1>)}
                {(numberOfCars<=12)&&(<h1 className="good">there is  no traffic jam </h1>)}
            </div>
            <div>
                <h1>Number of cars in this opposite view is {numberOfCars1}</h1>
                {(numberOfCars1>12)&&(<h1 className="alert">there is traffic jam</h1>)}
                {(numberOfCars1<=12)&&(<h1 className="good">there is  no traffic jam </h1>)}
            </div>

            <div>
                <Toggle predictions={predictions} isVisible={isVisible} toggleVisibility={toggleVisibility} />
            </div>
            <h1>Select the right time for the traffic light</h1>
            <input
                type="text"
                id="float"
                name="float"
                onChange={handleChange}
                value={float}
            />

            <h2>time: {float}</h2>

            <h2 >Updated: {updated}</h2>

            <button className="button" onClick={handleClick}>Update</button>
        </div>

    </div>
  );
}
class Toggle extends React.Component {

    render() {
        return (
            <div>
                <button onClick={this.props.toggleVisibility}>
                    {this.props.isVisible ? "Hide details" : "Show details"}
                </button>
                {this.props.isVisible &&
                <table className="preds">
                    <tr>
                        <th>Hour</th>
                        <th>Average Number of cars</th>
                    </tr>
                    {/*Array.from({ length: 24 }, (_, i) => (*/
                        this.props.predictions.map((item, i) => (
                        <tr key={i}>
                            <td>{i}</td>
                            <td>{item}</td>
                        </tr>
                    ))}
                </table>}

            </div>
        );
    }}
export default Homepage;