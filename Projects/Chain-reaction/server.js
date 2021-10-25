/* inbuilt modules */
const path = require('path');

/* npm modules */
const express = require('express');

/* express instance */
const app = express();
const port = process.env.PORT || 8000;

const server = app.listen(port, function() {
	console.log("Chain Reaction server active at port: " + port + ".");
});
app.use(express.json()); // allow receiving json data
app.use(express.urlencoded({ extended: true })); // allow receiving urlencoded data

app.use('/', express.static('./public'));

app.get('/', function(req, res) {
	res.sendFile(path.join(__dirname, 'public', 'index.html'));
});
app.get('/run', function(req, res) {
	res.sendFile(path.join(__dirname, 'public', 'run.html'));
});
