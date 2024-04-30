const { createProxyMiddleware } = require('http-proxy-middleware');

module.exports = function(app) {
    app.use(
        '/minesButton', // The endpoint you want to proxy
        createProxyMiddleware({
            target: 'http://localhost:18080', // The backend server address
            changeOrigin: true,
        })
    );
};
