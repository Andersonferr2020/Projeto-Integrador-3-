import React from 'react';
import Home from './Components/Home';
import Contato from './Components/Contato';
import "./App.css"
import Card from './Components/Card';
import Navbar from './Navbar';
import Footer from './Components/Footer';



function App() {
  return (
    <div className="App">
      <Navbar/>
      <br/>  <br/>
      <br /><br />
      <Card/>
      <br /><br /><br /><br /><br /><br />
      <Footer/>
      
    </div>
  );
}

export default App;
