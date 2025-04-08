import React from 'react';


const Card = () => {
  return (
    <div className="card-container">
      <div className="card-item">
        <div className="card">
          <div className="card-body">
            <a href="#"><p className="card-text">Clique aqui para emissão de relatórios.</p></a>
          </div>
        </div>
      </div>

      <div className="card-item">
        <div className="card">
          <div className="card-body">
            <a href="#"><p className="card-text">Clique aqui para monitorar a temperatura.</p></a>
          </div>
        </div>
      </div>

      <div className="card-item">
        <div className="card">
          <div className="card-body">
            <a href="#"><p className="card-text">Clique aqui para monitorar a umidade.</p></a>
          </div>
        </div>
      </div>
    </div>
  );
};

export default Card;
