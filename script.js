// ============================================================
// ===== DATA =====
// ============================================================
const contentData = [
    { id: 1, title: 'سكربت استخراج جلسات', desc: 'استخراج جلسات بايروجرام بسهولة', icon: 'fa-key', category: 'telegram',
        type: 'scripts' },
    { id: 2, title: 'بوت موسيقى متكامل', desc: 'تشغيل وتحميل الأغاني من يوتيوب', icon: 'fa-music', category: 'music',
        type: 'bots' },
    { id: 3, title: 'أداة حماية سيرفرات', desc: 'حماية متقدمة من الاختراقات', icon: 'fa-shield-alt',
        category: 'security', type: 'tools' },
    { id: 4, title: 'مكتبة بايثون للـ API', desc: 'مكتبة متكاملة للتعامل مع APIs', icon: 'fa-plug', category: 'python',
        type: 'codes' },
    { id: 5, title: 'سكربت نقل أعضاء', desc: 'نقل أعضاء بين المجموعات', icon: 'fa-user-friends', category: 'telegram',
        type: 'scripts' },
    { id: 6, title: 'ملف حماية lua & php', desc: 'حماية متقدمة لمواقع الويب', icon: 'fa-file-code',
        category: 'security', type: 'tools' }
];

const pricingData = [
    { name: 'أساسي', price: '1.5', desc: 'للمبتدئين', features: ['100 طلب/يوم', 'API أساسية'] },
    { name: 'قياسي', price: '5', desc: 'للمطورين', features: ['500 طلب/يوم', 'جميع APIs'] },
    { name: 'احترافي', price: '15', desc: 'الأكثر طلباً', features: ['2000 طلب/يوم', 'دعم VIP'] },
    { name: 'مؤسسي', price: '35', desc: 'للشركات', features: ['5000 طلب/يوم', 'دعم مخصص'] }
];

const apiData = [
    { name: 'YouTube API', desc: 'جلب البيانات، بحث، تشغيل', icon: 'fab fa-youtube' },
    { name: 'Spotify API', desc: 'موسيقى، قوائم تشغيل', icon: 'fab fa-spotify' },
    { name: 'Telegram API', desc: 'بوتات، جلسات، تفاعلات', icon: 'fab fa-telegram' },
    { name: 'Media API', desc: 'رفع ومعالجة الميديا', icon: 'fas fa-cloud-upload-alt' }
];

let currentFilter = 'all';
let currentCategory = 'all';

// ============================================================
// ===== RENDER FUNCTIONS =====
// ============================================================
function renderContent() {
    const grid = document.getElementById('contentGrid');
    let filtered = contentData;
    if (currentFilter !== 'all') filtered = filtered.filter(item => item.type === currentFilter);
    if (currentCategory !== 'all') filtered = filtered.filter(item => item.category === currentCategory);

    if (filtered.length === 0) {
        grid.innerHTML =
            `<div style="grid-column:1/-1;text-align:center;padding:2rem;color:#64748b;">لا يوجد محتوى مطابق</div>`;
        return;
    }

    grid.innerHTML = filtered.map(item => `
            <div class="content-card glass">
                <div class="card-icon"><i class="fas ${item.icon}"></i></div>
                <div class="card-title">${item.title}</div>
                <div class="card-desc">${item.desc}</div>
                <div class="card-actions">
                    <button onclick="showToast('⬇️ جاري تحميل: ${item.title}')"><i class="fas fa-download"></i> تحميل</button>
                    <button onclick="showToast('📋 تم نسخ: ${item.title}')"><i class="fas fa-copy"></i> نسخ</button>
                </div>
            </div>
        `).join('');
}

function renderPricing() {
    const grid = document.getElementById('pricingGrid');
    grid.innerHTML = pricingData.map((p, idx) => `
            <div class="pricing-card glass ${idx === 2 ? 'popular' : ''}" onclick="openPricingModal(${idx})">
                <div class="pricing-name">${p.name}</div>
                <div class="pricing-price">${p.price}$ <small>/شهر</small></div>
                <div class="pricing-desc" style="font-size:0.7rem;color:#64748b;">${p.desc}</div>
                <button class="pricing-btn" onclick="event.stopPropagation();openPricingModal(${idx})">اختيار</button>
            </div>
        `).join('');
}

function renderAPIs() {
    const grid = document.getElementById('apiGrid');
    grid.innerHTML = apiData.map((api, idx) => `
            <div class="api-card" onclick="openApiModal(${idx})">
                <i class="${api.icon}"></i>
                <div class="api-name">${api.name}</div>
                <div class="api-desc">${api.desc}</div>
            </div>
        `).join('');
}

// ============================================================
// ===== MODALS =====
// ============================================================
function openPricingModal(index) {
    const p = pricingData[index];
    document.getElementById('pricingModalTitle').textContent = p.name;
    document.getElementById('pricingModalBody').innerHTML = `
            <div style="display:grid;gap:0.5rem;">
                <div style="display:flex;justify-content:space-between;padding:0.4rem 0.8rem;background:rgba(248,250,252,0.4);border-radius:12px;">
                    <span>السعر</span><span style="font-weight:600;color:#7c3aed;">${p.price}$ / شهر</span>
                </div>
                <div style="display:flex;justify-content:space-between;padding:0.4rem 0.8rem;background:rgba(248,250,252,0.4);border-radius:12px;">
                    <span>الوصف</span><span>${p.desc}</span>
                </div>
                ${p.features.map(f => `
                    <div style="display:flex;justify-content:space-between;padding:0.4rem 0.8rem;background:rgba(248,250,252,0.4);border-radius:12px;">
                        <span>الميزة</span><span>${f}</span>
                    </div>
                `).join('')}
            </div>
        `;
    document.getElementById('pricingModal').classList.add('show');
}

function closePricingModal() {
    document.getElementById('pricingModal').classList.remove('show');
}

function openApiModal(index) {
    const api = apiData[index];
    document.getElementById('apiModalTitle').textContent = api.name;
    document.getElementById('apiModalBody').innerHTML = `
            <p><strong>الوصف:</strong> ${api.desc}</p>
            <p><strong>الحالة:</strong> <span style="color:#22c55e;">متاح</span></p>
        `;
    document.getElementById('apiPricingGrid').innerHTML = `
            <div class="pricing-card glass" onclick="showToast('✅ تم اختيار خطة ستارت لـ ${api.name}')">
                <div class="pricing-name">ستارت</div>
                <div class="pricing-price">2$ <small>/شهر</small></div>
            </div>
            <div class="pricing-card glass" onclick="showToast('✅ تم اختيار خطة برو لـ ${api.name}')">
                <div class="pricing-name">برو</div>
                <div class="pricing-price">8$ <small>/شهر</small></div>
            </div>
            <div class="pricing-card glass popular" onclick="showToast('✅ تم اختيار خطة بريميوم لـ ${api.name}')">
                <div class="pricing-name">بريميوم</div>
                <div class="pricing-price">20$ <small>/شهر</small></div>
            </div>
        `;
    document.getElementById('apiModal').classList.add('show');
}

function closeApiModal() {
    document.getElementById('apiModal').classList.remove('show');
}

// ============================================================
// ===== FILTERS =====
// ============================================================
function filterContent(type) {
    currentFilter = type;
    document.querySelectorAll('.nav-btn').forEach(b => b.classList.remove('active'));
    document.querySelectorAll('.nav-btn').forEach((b, i) => {
        if ((type === 'all' && i === 0) || (type === 'codes' && i === 1) ||
            (type === 'tools' && i === 2) || (type === 'bots' && i === 3)) {
            b.classList.add('active');
        }
    });
    renderContent();
}

function filterCategory(category) {
    currentCategory = category;
    document.querySelectorAll('.category-tag').forEach(t => t.classList.remove('active'));
    document.querySelectorAll('.category-tag').forEach(t => {
        const text = t.textContent.trim();
        if ((category === 'all' && text === 'الكل') ||
            (category === 'python' && text.includes('بايثون')) ||
            (category === 'telegram' && text.includes('تليجرام')) ||
            (category === 'security' && text.includes('أمن')) ||
            (category === 'music' && text.includes('موسيقى'))) {
            t.classList.add('active');
        }
    });
    renderContent();
}

// ============================================================
// ===== THEME =====
// ============================================================
function toggleTheme() {
    document.body.classList.toggle('dark-mode');
    const icon = document.getElementById('themeIcon');
    icon.className = document.body.classList.contains('dark-mode') ? 'fas fa-sun' : 'fas fa-moon';
}

// ============================================================
// ===== TOAST =====
// ============================================================
function showToast(message) {
    const toast = document.createElement('div');
    toast.className = 'toast';
    toast.textContent = message;
    document.body.appendChild(toast);
    setTimeout(() => {
        toast.classList.add('hide');
        setTimeout(() => toast.remove(), 300);
    }, 3000);
}

// ============================================================
// ===== CLOSE MODALS ON OVERLAY CLICK =====
// ============================================================
document.querySelectorAll('.modal-overlay').forEach(el => {
    el.addEventListener('click', function(e) {
        if (e.target === this) this.classList.remove('show');
    });
});

// ============================================================
// ===== INIT =====
// ============================================================
renderContent();
renderPricing();
renderAPIs();

// Check for saved theme
if (localStorage.getItem('darkMode') === 'true') {
    document.body.classList.add('dark-mode');
    document.getElementById('themeIcon').className = 'fas fa-sun';
}

// Save theme preference
document.addEventListener('DOMContentLoaded', function() {
    const observer = new MutationObserver(function() {
        localStorage.setItem('darkMode', document.body.classList.contains('dark-mode'));
    });
    observer.observe(document.body, { attributes: true, attributeFilter: ['class'] });
});

console.log('🚀 Py Zone | منصة خدمات فيجا');
console.log('📌 @TopVeGa');