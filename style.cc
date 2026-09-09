* {
    margin: 0;
    padding: 0;
    box-sizing: border-box;
    font-family: 'Inter', sans-serif;
}
body {
    min-height: 100vh;
    background: #f0f4f8;
    padding: 1rem;
    transition: background 0.5s ease;
}
body.dark-mode {
    background: #0a0510;
}
.container {
    max-width: 1200px;
    margin: 0 auto;
}
.glass {
    background: rgba(255, 255, 255, 0.6);
    backdrop-filter: blur(20px);
    -webkit-backdrop-filter: blur(20px);
    border: 1px solid rgba(255, 255, 255, 0.3);
    border-radius: 40px;
    padding: 2rem;
    box-shadow: 0 8px 32px rgba(0, 0, 0, 0.04);
}
body.dark-mode .glass {
    background: rgba(20, 10, 30, 0.7);
    backdrop-filter: blur(24px);
    -webkit-backdrop-filter: blur(24px);
    border: 1px solid rgba(180, 100, 255, 0.15);
    box-shadow: 0 8px 32px rgba(120, 40, 200, 0.15);
}
/* ===== HEADER ===== */
.header {
    display: flex;
    flex-wrap: wrap;
    justify-content: space-between;
    align-items: center;
    padding-bottom: 1rem;
    border-bottom: 1px solid rgba(0, 0, 0, 0.05);
    gap: 0.5rem;
}
body.dark-mode .header {
    border-color: rgba(255, 255, 255, 0.05);
}
.brand h1 {
    font-size: 1.5rem;
    font-weight: 900;
    background: linear-gradient(135deg, #1e293b, #7c3aed);
    -webkit-background-clip: text;
    -webkit-text-fill-color: transparent;
}
body.dark-mode .brand h1 {
    background: linear-gradient(135deg, #f1f5f9, #a78bfa);
    -webkit-background-clip: text;
    -webkit-text-fill-color: transparent;
}
.brand small {
    font-size: 0.7rem;
    color: #64748b;
    display: block;
}
body.dark-mode .brand small {
    color: #94a3b8;
}
.header-actions {
    display: flex;
    align-items: center;
    gap: 8px;
    flex-wrap: wrap;
}
.btn-icon {
    background: rgba(255, 255, 255, 0.6);
    backdrop-filter: blur(10px);
    border: none;
    padding: 0.4rem 0.9rem;
    border-radius: 60px;
    color: #1e293b;
    font-size: 0.8rem;
    cursor: pointer;
    transition: all 0.3s ease;
    display: flex;
    align-items: center;
    gap: 6px;
}
body.dark-mode .btn-icon {
    background: rgba(255, 255, 255, 0.04);
    color: #e2e8f0;
}
.btn-icon i {
    color: #7c3aed;
}
body.dark-mode .btn-icon i {
    color: #a78bfa;
}
.btn-icon:hover {
    transform: translateY(-2px);
    background: rgba(124, 58, 237, 0.06);
}
/* ===== NAV ===== */
.nav-links {
    display: flex;
    flex-wrap: wrap;
    justify-content: center;
    gap: 0.4rem;
    margin: 1.2rem 0;
}
.nav-btn {
    background: rgba(255, 255, 255, 0.5);
    backdrop-filter: blur(10px);
    border: 1px solid rgba(0, 0, 0, 0.03);
    padding: 0.4rem 1.4rem;
    border-radius: 60px;
    color: #1e293b;
    font-weight: 500;
    font-size: 0.85rem;
    cursor: pointer;
    transition: all 0.3s ease;
    display: inline-flex;
    align-items: center;
    gap: 8px;
}
body.dark-mode .nav-btn {
    background: rgba(255, 255, 255, 0.03);
    color: #e2e8f0;
}
.nav-btn i {
    color: #7c3aed;
}
body.dark-mode .nav-btn i {
    color: #a78bfa;
}
.nav-btn:hover {
    transform: translateY(-3px);
    background: rgba(241, 245, 249, 0.7);
}
body.dark-mode .nav-btn:hover {
    background: rgba(255, 255, 255, 0.05);
}
.nav-btn.active {
    background: linear-gradient(135deg, #7c3aed, #a78bfa);
    color: #fff;
}
body.dark-mode .nav-btn.active {
    background: linear-gradient(135deg, #a78bfa, #c4b5fd);
    color: #0a0510;
}
.nav-btn.active i {
    color: #fff;
}
body.dark-mode .nav-btn.active i {
    color: #0a0510;
}
/* ===== CATEGORIES ===== */
.categories {
    display: flex;
    flex-wrap: wrap;
    gap: 0.5rem;
    margin: 1rem 0;
    padding: 0.8rem 1.2rem;
    border-radius: 28px;
}
.category-tag {
    padding: 0.2rem 1rem;
    border-radius: 60px;
    font-size: 0.75rem;
    background: rgba(241, 245, 249, 0.5);
    color: #1e293b;
    cursor: pointer;
    transition: all 0.3s ease;
    border: 1px solid rgba(0, 0, 0, 0.02);
}
body.dark-mode .category-tag {
    background: rgba(255, 255, 255, 0.02);
    color: #e2e8f0;
}
.category-tag:hover,
.category-tag.active {
    background: linear-gradient(135deg, #7c3aed, #a78bfa);
    color: #fff;
    transform: translateY(-2px);
}
body.dark-mode .category-tag:hover,
body.dark-mode .category-tag.active {
    background: linear-gradient(135deg, #a78bfa, #c4b5fd);
    color: #0a0510;
}
/* ===== CONTENT ===== */
.content-grid {
    display: grid;
    grid-template-columns: repeat(auto-fit, minmax(280px, 1fr));
    gap: 1rem;
    margin: 1.2rem 0;
}
.content-card {
    border-radius: 24px;
    padding: 1.2rem;
    border: 1px solid rgba(0, 0, 0, 0.02);
    transition: all 0.3s ease;
    box-shadow: 0 2px 8px rgba(0, 0, 0, 0.02);
    position: relative;
}
.content-card:hover {
    transform: translateY(-6px);
    border-color: rgba(124, 58, 237, 0.05);
}
.content-card .card-icon {
    font-size: 2rem;
    color: #7c3aed;
    margin-bottom: 0.5rem;
}
body.dark-mode .content-card .card-icon {
    color: #a78bfa;
}
.content-card .card-title {
    font-weight: 700;
    color: #0f172a;
    font-size: 1rem;
}
body.dark-mode .content-card .card-title {
    color: #f1f5f9;
}
.content-card .card-desc {
    color: #64748b;
    font-size: 0.8rem;
    margin: 0.3rem 0;
}
body.dark-mode .content-card .card-desc {
    color: #94a3b8;
}
.content-card .card-actions {
    display: flex;
    gap: 0.5rem;
    margin-top: 0.8rem;
    flex-wrap: wrap;
}
.content-card .card-actions button {
    padding: 0.2rem 1rem;
    border-radius: 40px;
    border: 1px solid rgba(0, 0, 0, 0.02);
    background: rgba(248, 250, 252, 0.5);
    color: #1e293b;
    font-size: 0.7rem;
    cursor: pointer;
    transition: all 0.3s ease;
}
body.dark-mode .content-card .card-actions button {
    background: rgba(255, 255, 255, 0.02);
    color: #e2e8f0;
}
.content-card .card-actions button:hover {
    background: linear-gradient(135deg, #7c3aed, #a78bfa);
    color: #fff;
    transform: translateY(-2px);
}
/* ===== PRICING ===== */
.pricing-grid {
    display: grid;
    grid-template-columns: repeat(auto-fit, minmax(180px, 1fr));
    gap: 1rem;
    margin-top: 0.5rem;
}
.pricing-card {
    border-radius: 20px;
    padding: 1.2rem 1rem;
    text-align: center;
    border: 2px solid transparent;
    transition: all 0.3s ease;
    cursor: pointer;
}
.pricing-card:hover {
    transform: translateY(-6px);
    border-color: rgba(124, 58, 237, 0.05);
}
.pricing-card.popular {
    border-color: #7c3aed;
    background: rgba(124, 58, 237, 0.02);
}
body.dark-mode .pricing-card.popular {
    border-color: #a78bfa;
    background: rgba(167, 139, 250, 0.02);
}
.pricing-card .pricing-name {
    font-weight: 700;
    color: #0f172a;
}
body.dark-mode .pricing-card .pricing-name {
    color: #f1f5f9;
}
.pricing-card .pricing-price {
    font-size: 1.6rem;
    font-weight: 900;
    color: #7c3aed;
    margin: 0.3rem 0;
}
body.dark-mode .pricing-card .pricing-price {
    color: #a78bfa;
}
.pricing-card .pricing-btn {
    background: linear-gradient(135deg, #7c3aed, #a78bfa);
    border: none;
    padding: 0.4rem 1.5rem;
    border-radius: 60px;
    color: #fff;
    font-size: 0.75rem;
    font-weight: 600;
    cursor: pointer;
    transition: all 0.3s ease;
    margin-top: 0.4rem;
}
.pricing-card .pricing-btn:hover {
    transform: scale(1.04);
}
body.dark-mode .pricing-card .pricing-btn {
    background: linear-gradient(135deg, #a78bfa, #c4b5fd);
    color: #0a0510;
}
/* ===== API ===== */
.api-grid {
    display: grid;
    grid-template-columns: repeat(auto-fit, minmax(180px, 1fr));
    gap: 0.8rem;
    margin-top: 0.8rem;
}
.api-card {
    background: rgba(248, 250, 252, 0.4);
    backdrop-filter: blur(6px);
    border-radius: 20px;
    padding: 1rem 0.8rem;
    text-align: center;
    border: 1px solid rgba(0, 0, 0, 0.02);
    transition: all 0.3s ease;
    cursor: pointer;
}
body.dark-mode .api-card {
    background: rgba(255, 255, 255, 0.02);
}
.api-card:hover {
    transform: translateY(-4px);
    box-shadow: 0 8px 30px rgba(124, 58, 237, 0.08);
}
.api-card i {
    font-size: 1.6rem;
    color: #7c3aed;
    display: block;
    margin-bottom: 0.3rem;
}
body.dark-mode .api-card i {
    color: #a78bfa;
}
.api-card .api-name {
    font-weight: 600;
    color: #0f172a;
}
body.dark-mode .api-card .api-name {
    color: #f1f5f9;
}
.api-card .api-desc {
    font-size: 0.7rem;
    color: #64748b;
}
body.dark-mode .api-card .api-desc {
    color: #94a3b8;
}
/* ===== FOOTER ===== */
.footer {
    display: flex;
    flex-wrap: wrap;
    justify-content: space-between;
    align-items: center;
    margin-top: 1.8rem;
    padding-top: 1rem;
    border-top: 1px solid rgba(0, 0, 0, 0.02);
    color: #64748b;
    font-size: 0.8rem;
}
body.dark-mode .footer {
    border-color: rgba(255, 255, 255, 0.02);
    color: #94a3b8;
}
/* ===== MODAL ===== */
.modal-overlay {
    display: none;
    position: fixed;
    top: 0;
    left: 0;
    width: 100%;
    height: 100%;
    background: rgba(0, 0, 0, 0.3);
    backdrop-filter: blur(8px);
    z-index: 2000;
    justify-content: center;
    align-items: center;
    padding: 1.5rem;
}
.modal-overlay.show {
    display: flex;
}
.modal {
    max-width: 600px;
    width: 100%;
    background: rgba(255, 255, 255, 0.9);
    backdrop-filter: blur(24px);
    border-radius: 32px;
    padding: 2rem;
    border: 1px solid rgba(255, 255, 255, 0.3);
    max-height: 90vh;
    overflow-y: auto;
}
body.dark-mode .modal {
    background: rgba(20, 10, 30, 0.9);
    border-color: rgba(180, 100, 255, 0.1);
}
.modal .close-modal {
    float: left;
    background: transparent;
    border: none;
    font-size: 1.2rem;
    cursor: pointer;
    color: #64748b;
}
.modal h2 {
    font-size: 1.3rem;
    margin-bottom: 1rem;
    color: #0f172a;
}
body.dark-mode .modal h2 {
    color: #f1f5f9;
}
.modal h2 i {
    color: #7c3aed;
}
body.dark-mode .modal h2 i {
    color: #a78bfa;
}
.toast {
    position: fixed;
    bottom: 80px;
    right: 20px;
    background: rgba(30, 41, 59, 0.9);
    backdrop-filter: blur(16px);
    color: #fff;
    padding: 0.8rem 1.5rem;
    border-radius: 16px;
    font-size: 0.9rem;
    z-index: 9999;
    animation: slideUp 0.3s ease;
    direction: rtl;
    max-width: 90%;
}
body.dark-mode .toast {
    background: rgba(20, 10, 30, 0.95);
}
.toast.hide {
    opacity: 0;
    transition: opacity 0.3s ease;
}
@keyframes slideUp {
    from {
        transform: translateY(30px);
        opacity: 0;
    }
    to {
        transform: translateY(0);
        opacity: 1;
    }
}
/* ===== RESPONSIVE ===== */
@media (max-width: 768px) {
    .glass {
        padding: 1rem;
        border-radius: 28px;
    }
    .brand h1 {
        font-size: 1.2rem;
    }
    .header-actions {
        width: 100%;
        justify-content: center;
    }
    .btn-icon {
        font-size: 0.7rem;
        padding: 0.2rem 0.6rem;
    }
    .content-grid {
        grid-template-columns: 1fr;
    }
    .pricing-grid {
        grid-template-columns: repeat(auto-fit, minmax(150px, 1fr));
    }
    .api-grid {
        grid-template-columns: repeat(auto-fit, minmax(140px, 1fr));
    }
}
@media (max-width: 480px) {
    .brand h1 {
        font-size: 1rem;
    }
    .nav-btn {
        font-size: 0.7rem;
        padding: 0.2rem 0.8rem;
    }
    .category-tag {
        font-size: 0.65rem;
        padding: 0.1rem 0.7rem;
    }
}