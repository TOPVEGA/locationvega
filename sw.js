// ==========================================
// Service Worker - Python Zone App
// ==========================================

const CACHE_NAME = 'python-zone-v2.0';
const OFFLINE_URL = '/offline.html';

const urlsToCache = [
  '/',
  '/index.html',
  '/manifest.json',
  'https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.5.0/css/all.min.css',
  'https://unpkg.com/aos@2.3.1/dist/aos.css',
  'https://unpkg.com/aos@2.3.1/dist/aos.js',
  'https://fonts.googleapis.com/css2?family=Inter:wght@300;400;500;600;700;800&display=swap'
];

self.addEventListener('install', event => {
  event.waitUntil(
    caches.open(CACHE_NAME)
      .then(cache => cache.addAll(urlsToCache))
      .then(() => self.skipWaiting())
  );
});

self.addEventListener('activate', event => {
  event.waitUntil(
    caches.keys().then(cacheNames => {
      return Promise.all(
        cacheNames.map(cacheName => {
          if (cacheName !== CACHE_NAME) {
            return caches.delete(cacheName);
          }
        })
      );
    })
    .then(() => self.clients.claim())
  );
});

self.addEventListener('fetch', event => {
  if (event.request.url.includes('google-analytics') || 
      event.request.url.includes('doubleclick')) {
    return;
  }

  event.respondWith(
    caches.match(event.request)
      .then(response => {
        if (response) return response;
        const fetchRequest = event.request.clone();
        return fetch(fetchRequest)
          .then(response => {
            if (!response || response.status !== 200 || response.type !== 'basic') {
              return response;
            }
            const responseToCache = response.clone();
            caches.open(CACHE_NAME).then(cache => {
              cache.put(event.request, responseToCache);
            });
            return response;
          })
          .catch(() => {
            if (event.request.mode === 'navigate') {
              return caches.match('/index.html');
            }
          });
      })
  );
});

self.addEventListener('message', event => {
  if (event.data && event.data.type === 'SKIP_WAITING') {
    self.skipWaiting();
  }
});

// ===== إشعارات Push =====
self.addEventListener('push', event => {
  const data = event.data ? event.data.json() : { title: 'Python Zone', body: 'لديك تحديث جديد' };
  event.waitUntil(
    self.registration.showNotification(data.title || 'Python Zone', {
      body: data.body || 'لديك تحديث جديد',
      icon: '/icon-192.png',
      vibrate: [200, 100, 200],
      badge: '/icon-192.png',
      data: { url: data.url || '/' }
    })
  );
});

self.addEventListener('notificationclick', event => {
  event.notification.close();
  event.waitUntil(
    clients.openWindow(event.notification.data.url || '/')
  );
});

console.log('✅ Service Worker جاهز - Python Zone v2.0');