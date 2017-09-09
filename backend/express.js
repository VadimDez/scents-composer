/**
 * Created by Vadym Yatsyuk on 08.09.17
 */


const bodyParser = require('body-parser');
const methodOverride = require('method-override');
const cookieParser = require('cookie-parser');
const session = require('express-session');
const cors = require('cors');

const config = require('./config');

module.exports = (app) => {


  app.use(cookieParser());
  app.use(bodyParser.urlencoded({ extended: false }));
  app.use(bodyParser.json());
  app.use(methodOverride());
  app.use(session({
    secret: config.secrets.session,
    resave: false,
    saveUninitialized: true,
    cookie: { secure: true }
  }));

  app.use(cors({
    origin: (origin, callback) => {
      callback(null, [config.domains].indexOf(origin) !== -1);
    },
    credentials: true
  }));
};