import React, { useState } from 'react';


const Navbar = () => {
  const [username, setUsername] = useState('');
  const [password, setPassword] = useState('');

  const handleLogin = () => {
    if (username && password) {
      alert('Login bem-sucedido');
    } else {
      alert('Preencha todos os campos');
    }
  };

  return (
    <nav className="navbar">
      <div className="navbar-container">
        {/* Logo e Nome */}
        <a className="navbar-brand" href="#">
          <img src="./src/assets/IoT.jpg" alt="Logo" className="navbar-logo" />
          IoT - Projeto Integrador 3
        </a>

        {/* Container de Login */}
        <div className="login-container">
          <input
            type="text"
            placeholder="Usuário"
            value={username}
            onChange={(e) => setUsername(e.target.value)}
            className="login-input"
          />
          <input
            type="password"
            placeholder="Senha"
            value={password}
            onChange={(e) => setPassword(e.target.value)}
            className="login-input"
          />
          <button onClick={handleLogin} className="login-btn">Entrar</button>
        </div>
      </div>
    </nav>
  );
};

export default Navbar;
