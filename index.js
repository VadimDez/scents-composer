/**
 * Created by Vadym Yatsyuk on 08.09.17
 */
const express = require('express');
const app = express();
const server = require('http').Server(app);
const chalk = require('chalk');

const config = require('./config');

require('./express')(app);

app.use('/', require('./api'));

server.listen(config.PORT, () => {
  console.log(chalk.green.underline(`Listening on port ${ config.PORT }...`));
});