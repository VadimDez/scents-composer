/**
 * Created by Vadym Yatsyuk on 08.09.17
 */

const blynk = require('blynk-client');
const Router = require('express').Router;

const blynkClient = blynk.connect();

let router = new Router();
router.get('/', (req, res) => {
  res.status(200).json('ok').end();
});

module.exports = router;