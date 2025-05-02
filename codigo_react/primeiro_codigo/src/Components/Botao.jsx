import React from 'react';

const Botao = ({ label, onClick }) => {
  return (
    <button onClick={onClick} className="btn">
      {label}
    </button>
  );
};

export default Botao;
