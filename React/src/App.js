import './App.css';
import {Routes, Route, Link} from "react-router-dom";
import Homepage from "./Homepage";
import AboutMe from "./AboutMe";

function Header(){
    let title = "alo alo alo"
    return <h1>{title}</h1>
}


function App() {
    return(

       <div className="App">
           <nav className="nav">
               <Link to="/" className="nav-item">Homepage</Link>
               <Link to="/live-feed" className="nav-item">live feed</Link>
           </nav>
           <container className="container">
               <Routes>
                <Route path="/" element={<Homepage />} />
                <Route path="/live-feed" element={ <AboutMe/>} />
               </Routes>
           </container>
       </div>);
}

export default App;
