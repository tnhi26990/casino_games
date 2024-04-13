const { createProxyMiddleware } = require('http-proxy-middleware');

module.exports = function(app) {
    app.use(
        '/minesButton', // the endpoint you want to proxy
        createProxyMiddleware({
            target: 'http://localhost:18080', // the backend server address
            changeOrigin: true,
        })
    );
};
