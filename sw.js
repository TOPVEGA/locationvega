// ==========================================
// Service Worker - Python Zone v3.0
// ==========================================

const CACHE_NAME = 'python-zone-v3.0';
const OFFLINE_URL = '/offline.html';

const urlsToCache = [
  '/',
  '/index.html',
  '/manifest.json',
  '/offline.html',
  'https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.5.0/css/all.min.css',
  'https://unpkg.com/aos@2.3.1/dist/aos.css',
  'https://unpkg.com/aos@2.3.1/dist/aos.js',
  'https://fonts.googleapis.com/css2?family=Inter:wght@300;400;500;600;700;800&display=swap',
  'https://cdn.jsdelivr.net/npm/qrcodejs@1.0.0/qrcode.min.js'
];

// ===== التثبيت =====
self.addEventListener('install', event => {
  event.waitUntil(
    caches.open(CACHE_NAME)
      .then(cache => {
        console.log('📦 Caching assets...');
        return cache.addAll(urlsToCache);
      })
      .then(() => {
        console.log('✅ Cache ready!');
        return self.skipWaiting();
      })
      .catch(err => console.error('❌ Cache failed:', err))
  );
});

// ===== التفعيل =====
self.addEventListener('activate', event => {
  event.waitUntil(
    caches.keys().then(cacheNames => {
      return Promise.all(
        cacheNames.map(cacheName => {
          if (cacheName !== CACHE_NAME) {
            console.log('🗑️ Deleting old cache:', cacheName);
            return caches.delete(cacheName);
          }
        })
      );
    })
    .then(() => {
      console.log('✅ Service Worker activated!');
      return self.clients.claim();
    })
  );
});

// ===== التعامل مع الطلبات =====
self.addEventListener('fetch', event => {
  // تجاهل تحليلات Google
  if (event.request.url.includes('google-analytics') || 
      event.request.url.includes('doubleclick') ||
      event.request.url.includes('googletagmanager')) {
    return;
  }

  event.respondWith(
    caches.match(event.request)
      .then(response => {
        if (response) {
          return response;
        }
        
        const fetchRequest = event.request.clone();
        return fetch(fetchRequest)
          .then(response => {
            if (!response || response.status !== 200 || response.type !== 'basic') {
              return response;
            }
            
            const responseToCache = response.clone();
            caches.open(CACHE_NAME).then(cache => {
              try {
                cache.put(event.request, responseToCache);
              } catch (e) {
                console.warn('⚠️ Could not cache:', event.request.url);
              }
            });
            return response;
          })
          .catch(() => {
            // عرض صفحة غير متصل للملاحة
            if (event.request.mode === 'navigate') {
              return caches.match('/index.html').then(cached => {
                return cached || caches.match(OFFLINE_URL);
              });
            }
            // إرجاع استجابة فارغة للموارد الأخرى
            return new Response('Offline', {
              status: 503,
              statusText: 'Service Unavailable'
            });
          });
      })
  );
});

// ===== تحديث التطبيق =====
self.addEventListener('message', event => {
  if (event.data && event.data.type === 'SKIP_WAITING') {
    self.skipWaiting();
  }
  
  // تحديث ذاكرة التخزين المؤقت
  if (event.data && event.data.type === 'REFRESH_CACHE') {
    caches.open(CACHE_NAME).then(cache => {
      urlsToCache.forEach(url => {
        fetch(url).then(response => {
          if (response && response.status === 200) {
            cache.put(url, response);
          }
        }).catch(() => {});
      });
    });
  }
});

// ===== إشعارات Push =====
self.addEventListener('push', event => {
  let data = { title: 'Python Zone', body: 'لديك تحديث جديد', url: '/' };
  
  try {
    if (event.data) {
      const parsed = event.data.json();
      data = { ...data, ...parsed };
    }
  } catch (e) {
    data.body = event.data ? event.data.text() : data.body;
  }
  
  const options = {
    body: data.body || 'لديك تحديث جديد',
    icon: '/icon-192.png',
    badge: '/icon-192.png',
    vibrate: [200, 100, 200, 100, 200],
    data: { url: data.url || '/' },
    actions: [
      { action: 'open', title: '📱 فتح التطبيق' },
      { action: 'dismiss', title: '❌ إغلاق' }
    ],
    tag: 'python-zone-notification',
    requireInteraction: true
  };
  
  event.waitUntil(
    self.registration.showNotification(data.title || 'Python Zone', options)
  );
});

// ===== التعامل مع نقر الإشعار =====
self.addEventListener('notificationclick', event => {
  event.notification.close();
  
  if (event.action === 'dismiss') {
    return;
  }
  
  const url = event.notification.data?.url || '/';
  
  event.waitUntil(
    clients.matchAll({ type: 'window' }).then(windowClients => {
      for (let client of windowClients) {
        if (client.url === url && 'focus' in client) {
          return client.focus();
        }
      }
      if (clients.openWindow) {
        return clients.openWindow(url);
      }
    })
  );
});

console.log('✅ Service Worker v3.0 ready - Python Zone');
console.log('📌 @TopVeGa | @Cybervega');