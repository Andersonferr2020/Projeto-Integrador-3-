import React from 'react';


const Footer = () => {
  return (
    <footer className="footer">
      <div className="footer-container">
        {/* WhatsApp */}
        <div className="footer-item">
          <a href="https://wa.me/1234567890" target="_blank" rel="noopener noreferrer">
            <i className="fab fa-whatsapp footer-icon"></i> WhatsApp
          </a>
        </div>

        {/* Endereço */}
        <div className="footer-item">
          <a href="https://goo.gl/maps/xyz" target="_blank" rel="noopener noreferrer">
            <i className="fas fa-map-marker-alt footer-icon"></i> Endereço
          </a>
        </div>

        {/* Instagram */}
        <div className="footer-item">
          <a href="https://www.instagram.com/seu_usuario" target="_blank" rel="noopener noreferrer">
            <i className="fab fa-instagram footer-icon"></i> Instagram
          </a>
        </div>

        {/* Facebook */}
        <div className="footer-item">
          <a href="https://www.facebook.com/seu_usuario" target="_blank" rel="noopener noreferrer">
            <i className="fab fa-facebook footer-icon"></i> Facebook
          </a>
        </div>

        {/* Telefone */}
        <div className="footer-item">
          <a href="tel:+1234567890">
            <i className="fas fa-phone-alt footer-icon"></i> Telefone
          </a>
        </div>
      </div>
    </footer>
  );
};

export default Footer;
