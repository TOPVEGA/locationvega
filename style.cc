// ============================================================
// ===== DATA =====
// ============================================================
const contentData = [
    { id: 1, title: 'سكربت استخراج جلسات تليجرام', desc: 'استخراج جلسات بايروجرام بسهولة وسرعة', icon: 'fa-key', category: 'telegram', type: 'scripts', downloads: 1247, views: 5231, rating: 4.8, favorite: false, downloadLink: 'https://t.me/python2015' },
    { id: 2, title: 'بوت موسيقى متكامل', desc: 'بوت تليجرام لتشغيل وتحميل الأغاني من يوتيوب', icon: 'fa-music', category: 'music', type: 'bots', downloads: 892, views: 3412, rating: 4.9, favorite: false, downloadLink: 'https://t.me/Bi1ieBot' },
    { id: 3, title: 'أداة حماية سيرفرات', desc: 'حماية متقدمة للسيرفرات من الاختراقات', icon: 'fa-shield-alt', category: 'security', type: 'tools', downloads: 534, views: 2156, rating: 4.6, favorite: false, downloadLink: 'https://t.me/ToolsTermex' },
    { id: 4, title: 'مكتبة بايثون للـ API', desc: 'مكتبة متكاملة للتعامل مع واجهات API', icon: 'fa-plug', category: 'python', type: 'codes', downloads: 723, views: 2894, rating: 4.7, favorite: false, downloadLink: 'https://t.me/python2015' },
    { id: 5, title: 'سكربت نقل أعضاء تليجرام', desc: 'نقل أعضاء بين المجموعات مخفي أو ظهار', icon: 'fa-user-friends', category: 'telegram', type: 'scripts', downloads: 456, views: 1876, rating: 4.5, favorite: false, downloadLink: 'https://t.me/vegaone' },
    { id: 6, title: 'ملف حماية lua & php', desc: 'حماية متقدمة لمواقع الويب وسيرفرات اللعبة', icon: 'fa-file-code', category: 'security', type: 'tools', downloads: 678, views: 2567, rating: 4.8, favorite: false, downloadLink: 'https://t.me/ToolsTermex' }
];

const pricingData = [
    { name: 'أساسي', price: '1.5', desc: 'للمبتدئين', features: ['100 طلب/يوم', 'API أساسية', 'دعم أساسي'], popular: false },
    { name: 'قياسي', price: '5', desc: 'للمطورين', features: ['500 طلب/يوم', 'جميع الـ APIs', 'دعم سريع'], popular: false },
    { name: 'احترافي', price: '15', desc: 'الأكثر طلباً', features: ['2,000 طلب/يوم', 'جميع الـ APIs', 'دعم VIP 24/7', 'تخصيص مسبق'], popular: true },
    { name: 'أعمال', price: '35', desc: 'للشركات الصغيرة', features: ['5,000 طلب/يوم', 'جميع الـ APIs', 'دعم مخصص', 'تحليلات متقدمة'], popular: false },
    { name: 'مميز', price: '75', desc: 'للمشاريع الكبيرة', features: ['10,000 طلب/يوم', 'APIs مخصصة', 'دعم أولوية', 'تقارير مفصلة'], popular: false },
    { name: 'مؤسسي', price: '150', desc: 'للشركات الكبرى', features: ['غير محدود', 'APIs مخصصة بالكامل', 'دعم مخصص 24/7', 'SLA مضمون'], popular: false }
];

// API data with real pricing and specs
const apiData = [
    { 
        name: 'YouTube API', 
        desc: 'جلب البيانات، بحث، تشغيل', 
        icon: 'fab fa-youtube', 
        limit: '500 طلب/ساعة',
        badge: 'محدود',
        specs: 'معالج: AMD EPYC 32Core، ذاكرة: 16GB DDR4',
        pricing: [
            { name: 'ستارت', price: '2', features: ['50 طلب/ساعة', 'بحث فقط'] },
            { name: 'برو', price: '10', features: ['500 طلب/ساعة', 'بحث + تشغيل'] },
            { name: 'بريميوم', price: '25', features: ['غير محدود', 'جميع الميزات'] }
        ]
    },
    { 
        name: 'Spotify API', 
        desc: 'موسيقى، قوائم تشغيل، بحث', 
        icon: 'fab fa-spotify', 
        limit: '300 طلب/ساعة',
        badge: 'محدود',
        specs: 'معالج: AMD EPYC 16Core، ذاكرة: 8GB DDR4',
        pricing: [
            { name: 'ستارت', price: '1.5', features: ['30 طلب/ساعة', 'بحث فقط'] },
            { name: 'برو', price: '8', features: ['300 طلب/ساعة', 'بحث + قوائم'] },
            { name: 'بريميوم', price: '20', features: ['غير محدود', 'جميع الميزات'] }
        ]
    },
    { 
        name: 'Telegram API', 
        desc: 'بوتات، جلسات، تفاعلات', 
        icon: 'fab fa-telegram', 
        limit: '1000 طلب/ساعة',
        badge: 'مفتوح',
        specs: 'معالج: AMD EPYC 64Core، ذاكرة: 32GB DDR4',
        pricing: [
            { name: 'ستارت', price: '3', features: ['200 طلب/ساعة', 'بوتات أساسية'] },
            { name: 'برو', price: '15', features: ['1000 طلب/ساعة', 'بوتات + جلسات'] },
            { name: 'بريميوم', price: '40', features: ['غير محدود', 'جميع الميزات'] }
        ]
    },
    { 
        name: 'Media API', 
        desc: 'رفع ومعالجة الميديا', 
        icon: 'fas fa-cloud-upload-alt', 
        limit: '200 طلب/ساعة',
        badge: 'محدود',
        specs: 'معالج: AMD EPYC 16Core، ذاكرة: 8GB DDR4',
        pricing: [
            { name: 'ستارت', price: '2', features: ['50 طلب/ساعة', 'رفع فقط'] },
            { name: 'برو', price: '10', features: ['200 طلب/ساعة', 'رفع + معالجة'] },
            { name: 'بريميوم', price: '30', features: ['غير محدود', 'جميع الميزات'] }
        ]
    }
];

const servicesList = [
    'يوجد عمل اكواد برمجه بجميع اللغات',
    'يوجد ملفات و مصانع ميوزك',
    'يوجد ملفات و مصانع حمايه',
    'يوجد ملفات و مصانع تليثون',
    'يوجد ملفات نقل أعضاء مخفي و ظهار',
    'يوجد ملفات شد',
    'يوجد ملفات نشر تلقائي بمميزات',
    'يوجد ملفات مزاد للسوبرات',
    'يوجد ملف lua & php حمايه',
    'يوجد حل جميع الأخطاء',
    'يوجد بوت تسجيل دخول طلبات',
    'يوجد بوت فحص روابط و مواقع',
    'يوجد بوت رفع علي الاستضافة',
    'يوجد بوت فك و حظر حسابات تواصل الاجتماعي',
    'يوجد بوت انشاء بريد الكتروني مزيف',
    'يوجد بوت اشتراكات اجباري',
    'يوجد بوت حماية قنوات',
    'يوجد بوت حماية من رشق الاعضاء',
    'يوجد بوت تخصيص ازرار منشورات للقنوات',
    'يوجد بوت تحميل من المنصات'
];

let favorites = [];
let currentUser = 'زائر';
let currentFilter = 'all';
let currentCategory = 'all';
let cricketPlaying = false;
let currentLang = 'ar';
let selectedPricing = null;
let comments = [
    { id: 1, user: 'أحمد محمد', text: 'منصة رائعة، خدمات متكاملة وسريعة!', likes: 12, time: Date.now() - 3600000, replies: [] },
    { id: 2, user: 'سارة خالد', text: '❤️ أفضل موقع برمجي تعاملت معه، دعم فني ممتاز جداً', likes: 8, time: Date.now() - 7200000, replies: [] },
    { id: 3, user: 'علي حسن', text: '🔥 أكواد احترافية وسعر رمزي، أنصح الجميع بالتجربة', likes: 15, time: Date.now() - 10800000, replies: [] },
    { id: 4, user: 'نورا يوسف', text: 'موقع موثوق ومحتواه قيم، شكراً لفريق العمل', likes: 6, time: Date.now() - 14400000, replies: [] },
    { id: 5, user: 'محمد طارق', text: 'خدمات ممتازة وسرعة في التنفيذ، 👍', likes: 20, time: Date.now() - 18000000, replies: [] }
];
let nextCommentId = 6;
let vc = 12847;

// ============================================================
// ===== RENDER FUNCTIONS =====
// ============================================================
function renderContent() {
    const grid = document.getElementById('contentGrid');
    let filtered = contentData;
    if (currentFilter !== 'all') filtered = filtered.filter(item => item.type === currentFilter);
    if (currentCategory !== 'all') filtered = filtered.filter(item => item.category === currentCategory);
    if (filtered.length === 0) {
        grid.innerHTML = `<div style="grid-column:1/-1;text-align:center;padding:2rem;color:#64748b;"><i class="fas fa-search" style="font-size:2rem;display:block;margin-bottom:0.5rem;"></i>لا يوجد محتوى مطابق للبحث</div>`;
        return;
    }
    grid.innerHTML = filtered.map(item => `
        <div class="content-card glass" data-id="${item.id}">
            <span class="card-badge">${item.category}</span>
            <div class="card-icon"><i class="fas ${item.icon}"></i></div>
            <div class="card-title">${item.title}</div>
            <div class="card-desc">${item.desc}</div>
            <div class="rating">${generateStars(item.rating)}</div>
            <div class="card-stats">
                <span><i class="fas fa-download"></i> ${item.downloads}</span>
                <span><i class="fas fa-eye"></i> ${item.views}</span>
            </div>
            <div class="card-actions">
                <button onclick="downloadContent(${item.id})"><i class="fas fa-download"></i> تحميل</button>
                <button onclick="copyContent(${item.id})"><i class="fas fa-copy"></i> نسخ</button>
                <button class="favorite-btn ${favorites.includes(item.id) ? 'active' : ''}" onclick="toggleFavorite(${item.id})"><i class="fas fa-star"></i></button>
            </div>
        </div>
    `).join('');
}

function generateStars(rating) {
    const full = Math.floor(rating);
    const half = rating % 1 >= 0.5 ? 1 : 0;
    const empty = 5 - full - half;
    let html = '';
    for (let i = 0; i < full; i++) html += '<i class="fas fa-star"></i>';
    if (half) html += '<i class="fas fa-star-half-alt"></i>';
    for (let i = 0; i < empty; i++) html += '<i class="fas fa-star empty"></i>';
    return html;
}

function renderPricing() {
    const grid = document.getElementById('pricingGrid');
    grid.innerHTML = pricingData.map((p, idx) => `
        <div class="pricing-card glass ${p.popular ? 'popular' : ''}" onclick="openPricingDetail(${idx})">
            <div class="pricing-name">${p.name}</div>
            <div class="pricing-price">${p.price}$ <small>/شهر</small></div>
            <div class="pricing-desc">${p.desc}</div>
            <ul class="pricing-features">${p.features.map(f => `<li><i class="fas fa-check"></i> ${f}</li>`).join('')}</ul>
            <button class="pricing-btn" onclick="event.stopPropagation();openPricingDetail(${idx})">${currentLang === 'ar' ? 'ابدأ' : 'Start'}</button>
        </div>
    `).join('');
}

function renderAPIs() {
    const grid = document.getElementById('apiGrid');
    grid.innerHTML = apiData.map((api, idx) => `
        <div class="api-card glass" onclick="openApiDetail(${idx})">
            <span class="api-badge ${api.badge === 'محدود' ? 'limited' : ''}">${api.badge}</span>
            <i class="${api.icon}"></i>
            <div class="api-name">${api.name}</div>
            <div class="api-desc">${api.desc}</div>
            <div class="api-limits"><i class="fas fa-tachometer-alt"></i> ${api.limit}</div>
        </div>
    `).join('');
}

function renderServices() {
    const list = document.getElementById('servicesList');
    list.innerHTML = servicesList.map(s => `<li><i class="fas fa-check-circle"></i> ${s}</li>`).join('');
}

function renderAboutServices() {
    const list = document.getElementById('aboutServicesList');
    list.innerHTML = servicesList.map(s => `<li><i class="fas fa-check-circle"></i> ${s}</li>`).join('');
}

// ============================================================
// ===== PRICING DETAIL =====
// ============================================================
function openPricingDetail(index) {
    selectedPricing = pricingData[index];
    document.getElementById('pricingDetailTitle').textContent = selectedPricing.name;
    const grid = document.getElementById('pricingDetailGrid');
    grid.innerHTML = `
        <div class="pricing-detail-item"><span>السعر</span><span>${selectedPricing.price}$ / شهر</span></div>
        <div class="pricing-detail-item"><span>الوصف</span><span>${selectedPricing.desc}</span></div>
        ${selectedPricing.features.map(f => `<div class="pricing-detail-item"><span>الميزة</span><span>${f}</span></div>`).join('')}
        <div class="pricing-detail-item"><span>المعالج</span><span>AMD EPYC 64Core</span></div>
        <div class="pricing-detail-item"><span>الذاكرة</span><span>${index === 0 ? '4GB' : index === 1 ? '8GB' : index === 2 ? '16GB' : index === 3 ? '32GB' : index === 4 ? '64GB' : '128GB'} DDR4</span></div>
        <div class="pricing-detail-item"><span>التخزين</span><span>${index === 0 ? '50GB' : index === 1 ? '100GB' : index === 2 ? '200GB' : index === 3 ? '400GB' : index === 4 ? '800GB' : '1.6TB'} NVMe</span></div>
    `;
    document.getElementById('pricingDetailOverlay').classList.add('show');
}

function closePricingDetail() { document.getElementById('pricingDetailOverlay').classList.remove('show'); }

function openSubscribe() {
    document.getElementById('pricingDetailOverlay').classList.remove('show');
    document.getElementById('subscribeOverlay').classList.add('show');
}

function closeSubscribe() { document.getElementById('subscribeOverlay').classList.remove('show'); }

function processBinancePayment() {
    showToast('✅ تم الدفع بنجاح عبر Binance Pay!');
    closeSubscribe();
}

// ============================================================
// ===== API DETAIL =====
// ============================================================
function openApiDetail(index) {
    const api = apiData[index];
    document.getElementById('apiDetailTitle').textContent = api.name;
    document.getElementById('apiDetailContent').innerHTML = `
        <p><strong>الوصف:</strong> ${api.desc}</p>
        <p><strong>الحد:</strong> ${api.limit}</p>
        <p><strong>المواصفات:</strong> ${api.specs}</p>
    `;
    const grid = document.getElementById('apiPricingGrid');
    grid.innerHTML = api.pricing.map(p => `
        <div class="pricing-card glass" onclick="selectApiPlan('${api.name}', '${p.name}', '${p.price}')">
            <div class="pricing-name">${p.name}</div>
            <div class="pricing-price">${p.price}$ <small>/شهر</small></div>
            <ul class="pricing-features">${p.features.map(f => `<li><i class="fas fa-check"></i> ${f}</li>`).join('')}</ul>
        </div>
    `).join('');
    document.getElementById('apiDetailOverlay').classList.add('show');
}

function closeApiDetail() { document.getElementById('apiDetailOverlay').classList.remove('show'); }

function selectApiPlan(apiName, planName, price) {
    showToast(`✅ تم اختيار ${planName} لـ ${apiName} بسعر ${price}$`);
    document.getElementById('apiDetailOverlay').classList.remove('show');
}

// ============================================================
// ===== CONTENT FUNCTIONS =====
// ============================================================
function downloadContent(id) {
    const item = contentData.find(c => c.id === id);
    if (item) {
        item.downloads++;
        showToast(`⬇️ جاري التحميل: ${item.title}`);
        window.open(item.downloadLink || 'https://t.me/python2015', '_blank');
        renderContent();
        saveData();
    }
}

function copyContent(id) {
    const item = contentData.find(c => c.id === id);
    if (item) {
        navigator.clipboard.writeText(`${item.title}\n${item.desc}\nرابط التحميل: ${item.downloadLink || 'https://t.me/python2015'}`)
            .then(() => showToast(`📋 تم نسخ: ${item.title}`))
            .catch(() => showToast(`📋 ${item.title}`));
    }
}

function toggleFavorite(id) {
    const index = favorites.indexOf(id);
    if (index > -1) { favorites.splice(index, 1); showToast('⭐ تمت إزالة من المفضلة'); } 
    else { favorites.push(id); showToast('⭐ تمت الإضافة إلى المفضلة'); }
    renderContent();
    saveData();
}

function openFavorites() {
    const list = document.getElementById('favoritesList');
    if (favorites.length === 0) {
        list.innerHTML = `<p style="color:#64748b;text-align:center;padding:1rem;">لا توجد مفضلات حتى الآن</p>`;
    } else {
        list.innerHTML = favorites.map(id => {
            const item = contentData.find(c => c.id === id);
            return item ? `
                <div style="background:rgba(248,250,252,0.4);padding:0.8rem 1rem;border-radius:16px;display:flex;justify-content:space-between;align-items:center;">
                    <div><strong>${item.title}</strong><span style="font-size:0.7rem;color:#64748b;display:block;">${item.desc}</span></div>
                    <button onclick="toggleFavorite(${item.id});openFavorites();" style="background:transparent;border:none;color:#dc2626;cursor:pointer;font-size:1.2rem;"><i class="fas fa-times"></i></button>
                </div>
            ` : '';
        }).join('');
    }
    document.getElementById('favoritesOverlay').classList.add('show');
    document.getElementById('dropdownMenu').style.display = 'none';
    document.getElementById('userMenu').style.display = 'none';
}

function closeFavorites() { document.getElementById('favoritesOverlay').classList.remove('show'); }

// ============================================================
// ===== FILTERS & SEARCH =====
// ============================================================
function filterContent(type) {
    currentFilter = type;
    document.querySelectorAll('.nav-btn').forEach(b => b.classList.remove('active'));
    document.querySelectorAll('.nav-btn').forEach(b => {
        const key = b.querySelector('[data-key]')?.dataset?.key || '';
        if ((type === 'all' && key === 'navAll') || (type === 'codes' && key === 'navCodes') ||
            (type === 'tools' && key === 'navTools') || (type === 'scripts' && key === 'navScripts') ||
            (type === 'bots' && key === 'navBots')) b.classList.add('active');
    });
    renderContent();
}

function filterCategory(category) {
    currentCategory = category;
    document.querySelectorAll('.category-tag').forEach(t => t.classList.remove('active'));
    document.querySelectorAll('.category-tag').forEach(t => {
        const text = t.textContent.trim();
        if ((category === 'all' && text.includes('الكل')) || (category === 'python' && text.includes('بايثون')) ||
            (category === 'telegram' && text.includes('تليجرام')) || (category === 'security' && text.includes('أمن')) ||
            (category === 'music' && text.includes('موسيقى')) || (category === 'api' && text.includes('API')))
            t.classList.add('active');
    });
    renderContent();
}

function searchContent(query) {
    const grid = document.getElementById('contentGrid');
    if (!query.trim()) { renderContent(); return; }
    const filtered = contentData.filter(item => item.title.includes(query) || item.desc.includes(query) || item.category.includes(query));
    if (filtered.length === 0) {
        grid.innerHTML = `<div style="grid-column:1/-1;text-align:center;padding:2rem;color:#64748b;"><i class="fas fa-search" style="font-size:2rem;display:block;margin-bottom:0.5rem;"></i>لا توجد نتائج لـ "${query}"</div>`;
        return;
    }
    grid.innerHTML = filtered.map(item => `
        <div class="content-card glass" data-id="${item.id}">
            <span class="card-badge">${item.category}</span>
            <div class="card-icon"><i class="fas ${item.icon}"></i></div>
            <div class="card-title">${item.title}</div>
            <div class="card-desc">${item.desc}</div>
            <div class="rating">${generateStars(item.rating)}</div>
            <div class="card-stats">
                <span><i class="fas fa-download"></i> ${item.downloads}</span>
                <span><i class="fas fa-eye"></i> ${item.views}</span>
            </div>
            <div class="card-actions">
                <button onclick="downloadContent(${item.id})"><i class="fas fa-download"></i> تحميل</button>
                <button onclick="copyContent(${item.id})"><i class="fas fa-copy"></i> نسخ</button>
                <button class="favorite-btn ${favorites.includes(item.id) ? 'active' : ''}" onclick="toggleFavorite(${item.id})"><i class="fas fa-star"></i></button>
            </div>
        </div>
    `).join('');
}

function toggleSearchBar() {
    const bar = document.getElementById('searchBar');
    bar.classList.toggle('active');
    if (bar.classList.contains('active')) document.getElementById('searchInput').focus();
}

// ============================================================
// ===== USER =====
// ============================================================
function openUserSettings() {
    document.getElementById('settingsUsername').value = currentUser;
    document.getElementById('settingsLanguage').value = currentLang;
    document.getElementById('settingsOverlay').classList.add('show');
    document.getElementById('dropdownMenu').style.display = 'none';
    document.getElementById('userMenu').style.display = 'none';
}

function closeSettings() { document.getElementById('settingsOverlay').classList.remove('show'); }

function saveSettings() {
    const name = document.getElementById('settingsUsername').value.trim() || 'زائر';
    const lang = document.getElementById('settingsLanguage').value;
    currentUser = name;
    updateUserUI(name);
    changeLanguage(lang);
    showToast('✅ تم حفظ الإعدادات');
    closeSettings();
    saveData();
}

function updateUserUI(name) {
    document.getElementById('userName').innerHTML = `${name} <i class="fas fa-chevron-down"></i>`;
    document.getElementById('userMenuName').textContent = name;
    document.getElementById('userAvatar').textContent = name.charAt(0);
}

function loginUser() {
    const name = prompt('👤 أدخل اسم المستخدم:', currentUser);
    if (name && name.trim()) {
        currentUser = name.trim();
        updateUserUI(currentUser);
        document.getElementById('loginBtn').innerHTML = `<i class="fas fa-user"></i> ${currentUser}`;
        showToast(`👋 مرحباً ${currentUser}`);
        saveData();
    }
    document.getElementById('userMenu').style.display = 'none';
}

function toggleDropdown() {
    const menu = document.getElementById('dropdownMenu');
    const userMenu = document.getElementById('userMenu');
    menu.style.display = menu.style.display === 'block' ? 'none' : 'block';
    userMenu.style.display = 'none';
}

function toggleUserMenu() {
    const menu = document.getElementById('userMenu');
    const dropdown = document.getElementById('dropdownMenu');
    menu.style.display = menu.style.display === 'block' ? 'none' : 'block';
    dropdown.style.display = 'none';
}

document.addEventListener('click', function(e) {
    const d = document.querySelector('.header-actions');
    if (!d?.contains(e.target)) {
        document.getElementById('dropdownMenu').style.display = 'none';
        document.getElementById('userMenu').style.display = 'none';
    }
});

function toggleFullscreen() {
    if (!document.fullscreenElement) document.documentElement.requestFullscreen().catch(e => {});
    else document.exitFullscreen().catch(e => {});
    document.getElementById('dropdownMenu').style.display = 'none';
}

// ============================================================
// ===== LANGUAGE =====
// ============================================================
const translations = {
    ar: {
        brandTitle: 'python zone', brandSub: 'منصة البرمجيات والتطوير',
        navAll: 'الكل', navCodes: 'الأكواد', navTools: 'الأدوات', navScripts: 'سكربتات', navBots: 'بوتات',
        channel1Title: 'قناة بايثون', channel1Desc: 'محتوى برمجي، أكواد، ومشاريع بايثون متطورة.',
        channel2Title: 'سورس ميوزك فيجا', channel2Desc: 'مستوحى من بوتات الموسيقى • مفتوحة المصدر',
        channel3Title: 'قناة ترمكس', channel3Desc: 'أدوات و اختراق و أمن سيبراني .',
        supportTitle: 'جروب الدعم', supportDesc: 'الدعم الفني والمساعدة في جميع الاستفسارات.',
        join: 'انضم', joinSupport: 'انضم للدعم', active: 'نشطة', activeSupport: 'متاح 24', protection: 'حماية',
        s1: 'أكواد بجميع اللغات', s2: 'مصانع ميوزك', s3: 'مصانع حماية', s4: 'مصانع تليثون',
        s5: 'نقل أعضاء (مخفي او ظهار)', s6: 'ملفات شد', s7: 'نشر تلقائي بمميزات', s8: 'مزاد للسوبرات',
        s9: 'lua & php حماية', s10: 'حل جميع الأخطاء',
        botsTitle: 'بوتاتنا', bot1Desc: 'بوت استماع وتحميل الأغاني', bot2Desc: 'استخراج جلسات بايروجرام', openBot: 'افتح البوت',
        payTitle: 'دفع', payStarsSub: '⭐ نجوم تليجرام', founder: 'المؤسس', youtube: 'يوتيوب',
        comments: 'التعليقات', commentsTitle: 'آراء المستخدمين', addComment: 'إضافة تعليق', autoComments: 'تتغير التعليقات تلقائياً',
        footerRights: 'جميع الحقوق محفوظة', notice: 'تنويه هام: الرجاء جديه في تعامل حتي لا تضيع وقتي و وقتك',
        support: 'جروب الدعم', apiTitle: 'خدمات API للتطبيقات', apiDesc: 'نقدم واجهات برمجة تطبيقات (API) جاهزة للتكامل مع تطبيقاتك.',
        apiNote: 'ملاحظة: جميع واجهات API قابلة للتعديل والتخصيص حسب طلبك.',
        visionTitle: 'رؤيتنا وخدمتنا', visionText: 'نؤمن بأن البرمجيات هي لغة المستقبل، ونسعى لتقديم منصة متكاملة.',
        aboutTitle: 'خدماتنا', aboutGreeting: 'السلام علي من اتبع الهدى',
        aboutPricing: 'يوجد عمل اي كود او تعديل اي ملف كل هذا و #بأسعار رمزيه بدون تكلفة',
        aboutContact: 'للتواصل:', aboutNotice: '#تنويه_هام: الرجاء جديه في تعامل حتي لا تضيع وقتي و وقتك',
        popularTitle: '📌 الأكثر طلباً', channelsTitle: '📡 قنواتنا', pricingTitle: '💰 خطط التسعير',
        privacyTitle: '🔒 سياسة الخصوصية', privacyIntro: 'نحن في python zone نلتزم بحماية خصوصية بياناتك.',
        privacy1: 'لا نقوم بتخزين أي بيانات شخصية.', privacy2: 'طلبات الـ API تعالج بشكل مؤقت.',
        privacy3: 'البيانات مشفرة بالكامل (TLS 1.3).', privacy4: 'لا نشارك بياناتك مع أي طرف ثالث.',
        privacy5: 'يمكنك طلب حذف بياناتك في أي وقت.'
    },
    en: {
        brandTitle: 'python zone', brandSub: 'Software & Development Platform',
        navAll: 'All', navCodes: 'Codes', navTools: 'Tools', navScripts: 'Scripts', navBots: 'Bots',
        channel1Title: 'Python Channel', channel1Desc: 'Programming content, codes, and advanced Python projects.',
        channel2Title: 'Vega Music Source', channel2Desc: 'Inspired by music bots • Open source',
        channel3Title: 'Termex Channel', channel3Desc: 'Tools & hacking & cyber security.',
        supportTitle: 'Support Group', supportDesc: 'Technical support and help for all inquiries.',
        join: 'Join', joinSupport: 'Join Support', active: 'Active', activeSupport: 'Available 24', protection: 'Protection',
        s1: 'Codes in all languages', s2: 'Music factories', s3: 'Protection factories', s4: 'Telethon factories',
        s5: 'Member transfer (hidden & show)', s6: 'Crash files', s7: 'Auto-posting with features', s8: 'Supergroup auctions',
        s9: 'lua & php protection', s10: 'Fix all errors',
        botsTitle: 'Our Bots', bot1Desc: 'Music listening and downloading bot', bot2Desc: 'Pyrogram session extraction', openBot: 'Open Bot',
        payTitle: 'Pay', payStarsSub: '⭐ Telegram Stars', founder: 'Founder', youtube: 'YouTube',
        comments: 'Comments', commentsTitle: 'User Reviews', addComment: 'Add Comment', autoComments: 'Comments refresh automatically',
        footerRights: 'All rights reserved', notice: 'Important: Please be serious so we don\'t waste time',
        support: 'Support Group', apiTitle: 'API Services for Applications', apiDesc: 'We provide ready-to-use APIs for integration.',
        apiNote: 'Note: All APIs are customizable upon request.',
        visionTitle: 'Our Vision & Service', visionText: 'We believe that software is the language of the future.',
        aboutTitle: 'Our Services', aboutGreeting: 'Peace be upon those who follow the guidance',
        aboutPricing: 'We can create any code or modify any file at #symbolic prices without cost',
        aboutContact: 'Contact:', aboutNotice: '#Important: Please be serious so we don\'t waste time',
        popularTitle: '📌 Most Popular', channelsTitle: '📡 Our Channels', pricingTitle: '💰 Pricing Plans',
        privacyTitle: '🔒 Privacy Policy', privacyIntro: 'At python zone, we are committed to protecting your data privacy.',
        privacy1: 'We do not store any personal user data.', privacy2: 'All API requests are processed temporarily.',
        privacy3: 'Data passing through our servers is fully encrypted (TLS 1.3).',
        privacy4: 'We do not share your data with any third party.',
        privacy5: 'You can request deletion of any data related to you at any time.'
    }
};

function changeLanguage(lang) {
    currentLang = lang;
    const t = translations[lang];
    if (!t) return;
    document.body.dir = lang === 'en' ? 'ltr' : 'rtl';
    document.querySelectorAll('[data-key]').forEach(el => {
        const key = el.dataset.key;
        if (t[key]) el.textContent = t[key];
    });
    document.getElementById('settingsLanguage').value = lang;
    document.getElementById('dropdownMenu').style.display = 'none';
    renderPricing();
    renderAPIs();
    updateLanguageIndicators(lang);
    saveData();
}

function updateLanguageIndicators(selected) {
    document.getElementById('langIndicatorAr').innerHTML = selected === 'ar' ? '<span class="lang-indicator"></span>' : '';
    document.getElementById('langIndicatorEn').innerHTML = selected === 'en' ? '<span class="lang-indicator"></span>' : '';
}

// ============================================================
// ===== MODALS =====
// ============================================================
function openPrivacyPolicy() {
    document.getElementById('privacyOverlay').classList.add('show');
    document.getElementById('dropdownMenu').style.display = 'none';
}
function closePrivacyPolicy() { document.getElementById('privacyOverlay').classList.remove('show'); }

function openAboutModal() {
    document.getElementById('aboutOverlay').classList.add('show');
    document.getElementById('dropdownMenu').style.display = 'none';
}
function closeAboutModal() { document.getElementById('aboutOverlay').classList.remove('show'); }

// ============================================================
// ===== COMMENTS =====
// ============================================================
function getTimeAgo(timestamp) {
    const diff = Date.now() - timestamp;
    const minutes = Math.floor(diff / 60000);
    const hours = Math.floor(diff / 3600000);
    const days = Math.floor(diff / 86400000);
    if (minutes < 1) return 'الآن';
    if (minutes < 60) return `منذ ${minutes} دقيقة`;
    if (hours < 24) return `منذ ${hours} ساعة`;
    return `منذ ${days} يوم`;
}

function renderComments() {
    const list = document.getElementById('commentsList');
    list.innerHTML = '';
    comments.forEach(c => {
        const repliesHtml = c.replies.map(r => `
            <div class="comment-item" style="margin-bottom:0.5rem;padding:0.5rem 0.8rem;">
                <div class="comment-header"><div class="comment-user"><i class="fas fa-user-circle"></i> ${r.user}</div><div class="comment-time">${getTimeAgo(r.time)}</div></div>
                <div class="comment-text">${r.text}</div>
            </div>
        `).join('');
        list.innerHTML += `
            <div class="comment-item">
                <div class="comment-header"><div class="comment-user"><i class="fas fa-user-circle"></i> ${c.user}</div><div class="comment-time">${getTimeAgo(c.time)}</div></div>
                <div class="comment-text">${c.text}</div>
                <div class="comment-actions-bottom">
                    <button class="${c.liked ? 'liked' : ''}" onclick="toggleLike(${c.id})"><i class="fas fa-heart"></i> <span>${c.likes}</span></button>
                    <button class="reply-btn" onclick="toggleReplyInput(${c.id})"><i class="fas fa-reply"></i> رد</button>
                </div>
                <div class="replies">
                    ${repliesHtml}
                    <div class="reply-input" id="replyInput_${c.id}" style="display:none;">
                        <input type="text" id="replyText_${c.id}" placeholder="اكتب ردك...">
                        <button onclick="addReply(${c.id})">إرسال</button>
                    </div>
                </div>
            </div>
        `;
    });
}

function toggleReplyInput(commentId) {
    const input = document.getElementById(`replyInput_${commentId}`);
    if (input) {
        input.style.display = input.style.display === 'none' ? 'flex' : 'none';
        if (input.style.display === 'flex') document.getElementById(`replyText_${commentId}`).focus();
    }
}

function addReply(commentId) {
    const input = document.getElementById(`replyText_${commentId}`);
    if (!input || !input.value.trim()) return;
    const comment = comments.find(c => c.id === commentId);
    if (comment) {
        comment.replies.push({ user: currentUser || 'مستخدم', text: input.value.trim(), time: Date.now() });
        input.value = '';
        document.getElementById(`replyInput_${commentId}`).style.display = 'none';
        renderComments();
        saveData();
        showToast('✅ تم إضافة الرد');
    }
}

function toggleLike(commentId) {
    const comment = comments.find(c => c.id === commentId);
    if (comment) {
        comment.liked = !comment.liked;
        comment.likes += comment.liked ? 1 : -1;
        renderComments();
        saveData();
    }
}

function addComment() {
    const textInput = document.getElementById('newCommentText');
    const userInput = document.getElementById('newCommentUser');
    if (!textInput.value.trim()) { showToast('⚠️ الرجاء كتابة تعليق!'); return; }
    comments.unshift({
        id: nextCommentId++,
        user: userInput.value.trim() || currentUser || 'مستخدم',
        text: textInput.value.trim(),
        likes: 0,
        time: Date.now(),
        replies: [],
        liked: false
    });
    textInput.value = '';
    renderComments();
    saveData();
    showToast('✅ تم إضافة تعليقك بنجاح!');
}

function openComments() {
    document.getElementById('commentsOverlay').classList.add('show');
    document.getElementById('dropdownMenu').style.display = 'none';
    document.getElementById('userMenu').style.display = 'none';
    renderComments();
}
function closeComments() { document.getElementById('commentsOverlay').classList.remove('show'); }
function openMyComments() { openComments(); document.getElementById('userMenu').style.display = 'none'; }

// ============================================================
// ===== CALENDAR =====
// ============================================================
function toggleCalendar() {
    document.getElementById('calendarOverlay').classList.toggle('show');
    document.getElementById('dropdownMenu').style.display = 'none';
    updateDateTime();
}

function buildCalendar(date) {
    const grid = document.getElementById('calendarGrid');
    const year = date.getFullYear();
    const month = date.getMonth();
    const today = date.getDate();
    const firstDay = new Date(year, month, 1).getDay();
    const daysInMonth = new Date(year, month + 1, 0).getDate();
    const daysInPrevMonth = new Date(year, month, 0).getDate();
    const weekdays = ['ح', 'ن', 'ث', 'ر', 'خ', 'ج', 'س'];
    let html = '';
    weekdays.forEach(d => { html += `<div class="weekday">${d}</div>`; });
    const startOffset = (firstDay + 1) % 7;
    for (let i = startOffset - 1; i >= 0; i--) html += `<div class="day other-month">${daysInPrevMonth - i}</div>`;
    for (let i = 1; i <= daysInMonth; i++) {
        const isToday = i === today ? 'today' : '';
        html += `<div class="day ${isToday}">${i}</div>`;
    }
    const totalDays = startOffset + daysInMonth;
    const remaining = (7 - (totalDays % 7)) % 7;
    for (let i = 1; i <= remaining; i++) html += `<div class="day other-month">${i}</div>`;
    grid.innerHTML = html;
}

function updateDateTime() {
    const now = new Date();
    const cairoTime = new Date(now.toLocaleString('en-US', { timeZone: 'Africa/Cairo' }));
    let hours = cairoTime.getHours();
    const minutes = String(cairoTime.getMinutes()).padStart(2, '0');
    const seconds = String(cairoTime.getSeconds()).padStart(2, '0');
    const ampm = hours >= 12 ? 'م' : 'ص';
    hours = hours % 12 || 12;
    document.getElementById('headerDateTime').textContent = `${String(hours).padStart(2,'0')}:${minutes}:${seconds}`;
    document.getElementById('calClock').textContent = `${String(hours).padStart(2,'0')}:${minutes}:${seconds} ${ampm}`;
    const day = String(cairoTime.getDate()).padStart(2, '0');
    const monthNames = ['يناير', 'فبراير', 'مارس', 'أبريل', 'مايو', 'يونيو', 'يوليو', 'أغسطس', 'سبتمبر', 'أكتوبر', 'نوفمبر', 'ديسمبر'];
    document.getElementById('calFullDate').textContent = `${day} ${monthNames[cairoTime.getMonth()]} ${cairoTime.getFullYear()}`;
    document.getElementById('calMonthYear').textContent = `${monthNames[cairoTime.getMonth()]} ${cairoTime.getFullYear()}`;
    buildCalendar(cairoTime);
    document.getElementById('lastUpdate').textContent = `${day}/${String(cairoTime.getMonth()+1).padStart(2,'0')}/${cairoTime.getFullYear()}`;
}
updateDateTime();
setInterval(updateDateTime, 1000);

// ============================================================
// ===== CRICKET SOUND =====
// ============================================================
function initCricketSound() {
    try {
        const audioContext = new(window.AudioContext || window.webkitAudioContext)();
        function playCricket() {
            if (!cricketPlaying) return;
            try {
                const oscillator = audioContext.createOscillator();
                const gainNode = audioContext.createGain();
                oscillator.connect(gainNode);
                gainNode.connect(audioContext.destination);
                oscillator.frequency.value = 4000 + Math.random() * 1000;
                oscillator.type = 'sawtooth';
                gainNode.gain.value = 0.035;
                oscillator.start();
                oscillator.stop(audioContext.currentTime + 0.08);
                setTimeout(() => {
                    if (cricketPlaying) {
                        const o2 = audioContext.createOscillator();
                        const g2 = audioContext.createGain();
                        o2.connect(g2);
                        g2.connect(audioContext.destination);
                        o2.frequency.value = 4500 + Math.random() * 1500;
                        o2.type = 'square';
                        g2.gain.value = 0.025;
                        o2.start();
                        o2.stop(audioContext.currentTime + 0.05);
                    }
                }, 100 + Math.random() * 200);
                setTimeout(playCricket, 500 + Math.random() * 3000);
            } catch (e) { if (cricketPlaying) setTimeout(playCricket, 1000 + Math.random() * 3000); }
        }
        if (cricketPlaying) playCricket();
    } catch (e) {
        function fallbackChirp() {
            if (!cricketPlaying) return;
            try {
                const ctx = new(window.AudioContext || window.webkitAudioContext)();
                const osc = ctx.createOscillator();
                const gain = ctx.createGain();
                osc.connect(gain);
                gain.connect(ctx.destination);
                osc.frequency.value = 3500 + Math.random() * 1500;
                osc.type = 'sawtooth';
                gain.gain.value = 0.025;
                osc.start();
                osc.stop(ctx.currentTime + 0.06);
            } catch (e) {}
            if (cricketPlaying) setTimeout(fallbackChirp, 500 + Math.random() * 3000);
        }
        if (cricketPlaying) fallbackChirp();
    }
}

function toggleCricketSound() {
    cricketPlaying = !cricketPlaying;
    const toggle = document.getElementById('cricketToggle');
    const label = document.getElementById('cricketLabel');
    if (cricketPlaying) {
        toggle.classList.add('active');
        label.textContent = '🔇 كتم الليل';
        initCricketSound();
        showToast('🦗 تم تشغيل ظنين الليل');
    } else {
        toggle.classList.remove('active');
        label.textContent = '🔊 ظنين الليل';
        showToast('🔇 تم إيقاف ظنين الليل');
    }
}

// ============================================================
// ===== THEME =====
// ============================================================
function toggleTheme() {
    document.body.classList.toggle('dark-mode');
    const icon = document.getElementById('themeIcon');
    icon.className = document.body.classList.contains('dark-mode') ? 'fas fa-sun' : 'fas fa-moon';
    const cricketToggle = document.getElementById('cricketToggle');
    if (document.body.classList.contains('dark-mode')) {
        cricketToggle.style.display = 'flex';
        if (!cricketPlaying) toggleCricketSound();
    } else {
        cricketToggle.style.display = 'none';
        if (cricketPlaying) toggleCricketSound();
    }
    saveData();
}

// ============================================================
// ===== DARK MODE BACKGROUND =====
// ============================================================
function createBugs() {
    const container = document.getElementById('darkBgContainer');
    if (!container) return;
    container.innerHTML = '';
    const bugIcons = ['fa-bug', 'fa-spider', 'fa-mosquito', 'fa-dragonfly'];
    const numBugs = 30;
    for (let i = 0; i < numBugs; i++) {
        const bug = document.createElement('div');
        bug.className = 'bug';
        const isFirefly = Math.random() < 0.35;
        if (isFirefly) {
            bug.classList.add('bug-firefly');
            bug.innerHTML = '<i class="fas fa-circle"></i>';
        } else {
            const icon = bugIcons[Math.floor(Math.random() * bugIcons.length)];
            bug.innerHTML = `<i class="fas ${icon}"></i>`;
        }
        const startX = Math.random() * 100;
        const startY = Math.random() * 100;
        const tx = (Math.random() - 0.5) * 250;
        const ty = (Math.random() - 0.5) * 250;
        const duration = 18 + Math.random() * 30;
        const delay = Math.random() * 20;
        bug.style.setProperty('--tx', tx + 'vw');
        bug.style.setProperty('--ty', ty + 'vh');
        bug.style.left = startX + '%';
        bug.style.top = startY + '%';
        bug.style.animationDuration = duration + 's';
        bug.style.animationDelay = delay + 's';
        bug.style.fontSize = (4 + Math.random() * 12) + 'px';
        container.appendChild(bug);
    }
}

// ============================================================
// ===== TELEGRAM STARS =====
// ============================================================
function openTelegramStars() {
    const modalHtml = `
        <div style="position:fixed;top:0;left:0;width:100%;height:100%;background:rgba(0,0,0,0.5);backdrop-filter:blur(12px);-webkit-backdrop-filter:blur(12px);z-index:9999;display:flex;justify-content:center;align-items:center;padding:1.5rem;animation:fadeIn 0.4s ease;">
            <div style="background:rgba(255,255,255,0.85);backdrop-filter:blur(24px);-webkit-backdrop-filter:blur(24px);border-radius:32px;padding:2rem;max-width:400px;width:100%;text-align:center;position:relative;animation:slideUp 0.4s cubic-bezier(0.34, 1.56, 0.64, 1);border:1px solid rgba(255,255,255,0.3);">
                <button onclick="this.parentElement.parentElement.remove()" style="position:absolute;top:0.8rem;left:0.8rem;background:transparent;border:none;font-size:1.2rem;cursor:pointer;color:#64748b;transition:all 0.3s ease;">✕</button>
                <div style="font-size:3rem;margin-bottom:0.5rem;">⭐</div>
                <h3 style="color:#0f172a;margin-bottom:0.5rem;" data-key="donateTitle">تبرع بـ نجوم تليجرام</h3>
                <p style="color:#64748b;font-size:0.9rem;margin-bottom:1rem;" data-key="donateDesc">تبرعك بـ 1 نجمة يساعدنا على الاستمرار وتطوير المنصة نحو الأفضل ❤️</p>
                <div style="display:flex;flex-direction:column;gap:0.5rem;">
                    <button onclick="window.open('https://t.me/topvega?start=donate','_blank')" style="background:linear-gradient(135deg,#eab308,#f59e0b);border:none;padding:0.8rem;border-radius:60px;color:#fff;font-weight:600;cursor:pointer;display:flex;align-items:center;justify-content:center;gap:8px;transition:all 0.3s cubic-bezier(0.34, 1.56, 0.64, 1);">
                        <i class="fas fa-star"></i> <span data-key="donate1">تبرع بـ 1 ⭐</span>
                    </button>
                    <button onclick="window.open('https://t.me/topvega?start=donate_5','_blank')" style="background:linear-gradient(135deg,#f59e0b,#d97706);border:none;padding:0.8rem;border-radius:60px;color:#fff;font-weight:600;cursor:pointer;display:flex;align-items:center;justify-content:center;gap:8px;transition:all 0.3s cubic-bezier(0.34, 1.56, 0.64, 1);">
                        <i class="fas fa-star"></i> <span data-key="donate5">تبرع بـ 5 ⭐</span>
                    </button>
                    <button onclick="window.open('https://t.me/topvega?start=donate_10','_blank')" style="background:linear-gradient(135deg,#d97706,#b45309);border:none;padding:0.8rem;border-radius:60px;color:#fff;font-weight:600;cursor:pointer;display:flex;align-items:center;justify-content:center;gap:8px;transition:all 0.3s cubic-bezier(0.34, 1.56, 0.64, 1);">
                        <i class="fas fa-star"></i> <span data-key="donate10">تبرع بـ 10 ⭐</span>
                    </button>
                </div>
                <p style="color:#94a3b8;font-size:0.65rem;margin-top:1rem;"><i class="fas fa-lock"></i> <span data-key="donateSecure">الدفع مباشرة لحساب @TopVeGa</span></p>
            </div>
        </div>
    `;
    document.body.insertAdjacentHTML('beforeend', modalHtml);
    const t = translations[currentLang];
    if (t) document.querySelectorAll('[data-key]').forEach(el => { const key = el.dataset.key; if (t[key]) el.textContent = t[key]; });
}

// ============================================================
// ===== TOAST =====
// ============================================================
function showToast(message) {
    const toast = document.createElement('div');
    toast.className = 'toast';
    toast.textContent = message;
    document.body.appendChild(toast);
    setTimeout(() => { toast.classList.add('hide'); setTimeout(() => toast.remove(), 300); }, 3000);
}

// ============================================================
// ===== SAVE/LOAD =====
// ============================================================
function saveData() {
    try {
        const data = { favorites, comments, nextCommentId, currentUser, vc, darkMode: document.body.classList.contains('dark-mode'), language: currentLang };
        localStorage.setItem('siteData', JSON.stringify(data));
    } catch (e) {}
}

function loadData() {
    try {
        const saved = localStorage.getItem('siteData');
        if (saved) {
            const data = JSON.parse(saved);
            if (data.favorites) favorites = data.favorites;
            if (data.comments) comments = data.comments;
            if (data.nextCommentId) nextCommentId = data.nextCommentId;
            if (data.currentUser) { currentUser = data.currentUser; updateUserUI(currentUser); }
            if (data.vc) vc = data.vc;
            if (data.darkMode) {
                document.body.classList.add('dark-mode');
                document.getElementById('themeIcon').className = 'fas fa-sun';
                document.getElementById('cricketToggle').style.display = 'flex';
                if (!cricketPlaying) toggleCricketSound();
            }
            if (data.language) changeLanguage(data.language);
        }
    } catch (e) {}
}

// ============================================================
// ===== INIT =====
// ============================================================
loadData();
renderContent();
renderPricing();
renderAPIs();
renderServices();
renderAboutServices();
renderComments();
createBugs();
updateLanguageIndicators(currentLang);

if (document.body.classList.contains('dark-mode')) {
    document.getElementById('cricketToggle').style.display = 'flex';
}

document.querySelectorAll('.modal-overlay').forEach(el => {
    el.addEventListener('click', function(e) { if (e.target === this) this.classList.remove('show'); });
});

console.log('🚀 Py Zone | منصة خدمات فيجا المطورة');
console.log('📌 @TopVeGa | @Cybervega');
console.log('⭐ جميع الحقوق محفوظة © 2015-2026');